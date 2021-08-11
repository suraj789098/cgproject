#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<GL/glut.h>
#include <math.h>
typedef enum
{
true,false
}bool;
bool first=true;
int temps=0;

char s[30];
int temp=0;
bool firstSound=true;
bool isNight=false;
bool doorOpen=false;
bool midNight=false;
bool isMorning=true;
bool shchooldoorOpen=false;
bool inc=true;
bool dcrmnt=false;
float planePos=-4;
float peopleSpeed=.0002;
float schoolBoyScalVal=0;
float peoplePos2=.8;
float peoplePos=-1.48;
float boyPosX=-1.48;
float boyPosY=-.58;
float boyPosX2=0;
float boyPosY2=0;
float sunInc=-20;
float sunPosX=-1.6;
float sunPosY=-.1;
float sunSpeed=.03;
float carPosX1=-3.8;
float carPosX2=3.8;
float car2PosX1=-1.6;
float car2PosX2=1.6;
float carSpeed=.001;
float cloudScalVal=0;
int gLobal_R=0;
int gLobal_G=0;
int gLobal_B=0;
float leftL=20;
float rightL=-20;
float speed=3*6;
float Rsecond=0;
float Rminute=0;
float Rhour=0;
bool isDay=true;
GLfloat road_ambient[]={.5,.5,.5,.1};
GLfloat ground_ambient[]={.7,.7,.8,.1};
GLfloat path_ambient[]={3.5,3.5,3.5,.1};
GLfloat doorFront_ambient[]={4,4,4,.1};
GLfloat grass_ambient[]={.5,3,.5,.1};

GLfloat doorRot=0;
GLfloat doorRot2=0;
GLfloat schoolDoorRot=0;
void anim();
void dayDisp(int a);
void morning();
void streetLight();
void sun();
void Watch();
void shop();
void day();
void grass();
void FilledCircle(GLfloat cx,GLfloat cy, GLfloat r, int amount);
void init();
void Origin();
void building();
void commonBuiliding();
void commonBuilidingLarge();
void commercialBuilding();
void demoBuilding();
void window();
void windowBack();
void setColor(int r, int g, int b);
void getColor();
void school();
void schoolBoy();
void people();
void Clouds(float xdiff, float ydiff);
void plant(float xdiff);
void renderBitmapString(float x, float y, void *font,const char *string);
void car();
void carAnim(int val);
void cloudAnim(int val);
void clockAnim(int val);
void legAnim(int val);
void sunAnim(int val);
void doorAnim(int val);
void peopleAnim(int val);

void myinit()
{
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 600, 0, 500);
}
void init1()
{
glClearColor(0,0,0,1);
}

void peopleAnim(int val){
if(peoplePos>2){
      if(!isNight)
          peoplePos=-1.48;
}
if(peoplePos2>2){
   if(!isNight)
       peoplePos2=.8;
}
peoplePos+=peopleSpeed;
peoplePos2+=peopleSpeed;

glutPostRedisplay();
glutTimerFunc(1000,peopleAnim,0);
}
//Function for clock animation
void clockAnim(int val){
       Rsecond-=speed;
       Rminute-=speed/60.0;
       Rhour-=(speed*5)/3600.0;
       glutPostRedisplay();
       glutTimerFunc(10,clockAnim,0);
}
//Function to make car move
void carAnim(int val){
    if(carPosX1>2){
         if(!midNight)
           carPosX1=-3.8;
    }

    if(carPosX2<-2){
        if(!midNight)
            carPosX2=3.8;
    }

    if(car2PosX1>2){
        if(!midNight)
           car2PosX1=-3.8;
    }

    if(car2PosX2<-2){
        if(!midNight)
            car2PosX2=3.8;
    }
    carPosX1+=carSpeed;
    carPosX2-=carSpeed;
    car2PosX1+=carSpeed;
    car2PosX2-=carSpeed;

    glutPostRedisplay();
    glutTimerFunc(1000,carAnim,0);

}
//Function for leg animation of people
void legAnim(int val){
    if(leftL>0 && rightL<0){
        rightL+=1;
        leftL-=1;
    }
    else if(leftL<=0 && rightL>=0 && leftL>-20 && rightL<20){
        rightL+=1;
        leftL-=1;
    }
    else if(leftL==-20 && rightL==20){
        rightL=-20;
        leftL=20;
    }
leftL+=.1;
rightL-=.1;
glutPostRedisplay();
glutTimerFunc(100,legAnim,0);

}

//Function for cloud animation
void cloudAnim(int val){
if(cloudScalVal>=.4)
{
    cloudScalVal=0;
}
cloudScalVal+=.00005;
glutPostRedisplay();
glutTimerFunc(100,cloudAnim,0);
}
//Function to draw streetlight
void streetLight(){
   glColor3f(0,0,0);

   glLineWidth(6);
   glBegin(GL_LINES);
   glVertex2f(0,-.4);
   glVertex2f(0,-.7);
   glEnd();
   glLineWidth(7);

   glBegin(GL_LINE_STRIP);
   glPointSize(7);
   for(int i=0;i<361;i++){
        glBegin(GL_POINTS);
        glVertex2f(.03+.03*cos(i*3.14159265358979/360.0),-.4+.03*sin(i*3.14159265358979/360.0));
        glEnd();
}
  glEnd();

  glBegin(GL_LINE_STRIP);
  for(int i=0;i<361;i++){
    glBegin(GL_POINTS);
    glVertex2f(-.03+.03*cos(i*3.14159265358979/360.0),-.4+.03*sin(i*3.14159265358979/360.0));
    glEnd();
}
  glEnd();

  glColor3f(.8,.8,.8);
  FilledCircle(.06,-.41,.03,100);
  FilledCircle(-.06,-.41,.03,100);

}
//Function to draw plants which are in autumn season
void planta(float xdiff){
glColor3ub(255,140,0);
glBegin(GL_POLYGON);
glVertex2f(.105+xdiff,-.44);
glVertex2f(.1+xdiff,-.44);
glVertex2f(.095+xdiff,-.56);
glVertex2f(.11+xdiff,-.56);
glEnd();
glColor3ub(255,140,0);
FilledCircle(.105+xdiff,-.43,.04,100);
FilledCircle(.08+xdiff,-.46,.04,100);
FilledCircle(.12+xdiff,-.46,.04,100);
}
//Function to draw clouds which are in autumn season
void Cloudsa(float xdiff, float ydiff){
glColor3ub(255,190,0);
FilledCircle(0+xdiff,.08+ydiff,.07,360);

FilledCircle(-.06+xdiff,.08+ydiff,.07,360);
FilledCircle(.06+xdiff,.085+ydiff,.07,360);
FilledCircle(-.06*2+xdiff,.08+ydiff,.07,360);
FilledCircle(.05*2+xdiff,.08+ydiff,.07,360);
FilledCircle(-.04*2+xdiff,.06*2+ydiff,.07,360);
FilledCircle(.05*2+xdiff,.05*2+ydiff,.07,360);
FilledCircle(0.03+xdiff,.065*2+ydiff,.07,360);
FilledCircle(-0.05*3+xdiff,.04*2+ydiff,.07,360);
}

//Function to draw plants
void plant(float xdiff){
glColor3ub(107,68,25);
glBegin(GL_POLYGON);
glVertex2f(.105+xdiff,-.44);
glVertex2f(.1+xdiff,-.44);
glVertex2f(.095+xdiff,-.56);
glVertex2f(.11+xdiff,-.56);
glEnd();
glColor3ub(117,183,25);
FilledCircle(.105+xdiff,-.43,.04,100);
FilledCircle(.08+xdiff,-.46,.04,100);
FilledCircle(.12+xdiff,-.46,.04,100);
}
//Function to draw clouds
void Clouds(float xdiff, float ydiff){
glColor3ub(200,232,245);
FilledCircle(0+xdiff,.08+ydiff,.07,360);

FilledCircle(-.06+xdiff,.08+ydiff,.07,360);
FilledCircle(.06+xdiff,.085+ydiff,.07,360);
FilledCircle(-.06*2+xdiff,.08+ydiff,.07,360);
FilledCircle(.05*2+xdiff,.08+ydiff,.07,360);
FilledCircle(-.04*2+xdiff,.06*2+ydiff,.07,360);
FilledCircle(.05*2+xdiff,.05*2+ydiff,.07,360);
FilledCircle(0.03+xdiff,.065*2+ydiff,.07,360);
FilledCircle(-0.05*3+xdiff,.04*2+ydiff,.07,360);
}
//Function to draw grass
void grass(){
    glColor3ub(117,182,26);
    FilledCircle(.88,-.38,.05,360);
    FilledCircle(.92,-.42,.05,360);
    FilledCircle(.88,-.41,.05,360);
    FilledCircle(.83,-.34,.05,360);
    FilledCircle(.83,-.42,.05,360);
    FilledCircle(.72,-.42,.05,360);
    FilledCircle(.77,-.42,.05,360);
    FilledCircle(.77,-.38,.05,360);
    glBegin(GL_POLYGON);
    glVertex2f(.92,-.47);
    glVertex2f(.72,-.47);
    glVertex2f(.82,-.38);
    glEnd();
}
//Function to write the strings
void renderBitmapString(float x, float y, void *font,const char *string){
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void setColor(int r, int g, int b){
gLobal_R=r;
gLobal_G=g;
gLobal_B=b;
glColor3ub(r,g,b);
}
void getColor(){
     glColor3ub(gLobal_R,gLobal_G,gLobal_B);
}
//Function to initialize the window
void init(){
  glClearColor(1,1,1,1);
  glColor3f(1.0,0.0,0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,2200.0,0.0,1800.0);
  glFlush();

  }

void FilledCircle(GLfloat cx,GLfloat cy, GLfloat r, int amount);
//Function to draw circle
void Circle(GLfloat cx, GLfloat cy, GLfloat r, int line_amount)
{
	int i;
    GLfloat twicePi=2.0f*3.14159265358979;
    glBegin(GL_LINE_LOOP);
    for(i=0;i<=line_amount;i++){
        glVertex2f(
            cx+(r*cos(i*twicePi/line_amount)),
            cy+(r*sin(i*twicePi/line_amount))
        );


    }
    glEnd();

}
//Function to fill the circle
void FilledCircle(GLfloat cx,GLfloat cy, GLfloat r, int amount){
    int i;
    GLfloat twicePi=2.0f*3.14159265358979;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);
    for(i=0;i<=amount;i++){
        glVertex2f(
            cx+(r*cos(i*twicePi/amount)),
            cy+(r*sin(i*twicePi/amount))
        );
    }
    glEnd();
}

void windowBack(){
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.71-.02,-.35);
    glVertex2f(-1.71-.02,-.43);
    glVertex2f(-1.61-.02,-.43);
    glVertex2f(-1.61-.02,-.35);
    glEnd();
}
//Function to draw schoolboy
void schoolBoy(){

    glColor3ub(253,231,173);
    FilledCircle(0,.5,.1,100);
    glBegin(GL_TRIANGLES);
    glVertex2f(.12,.48);
    glVertex2f(.08,.55);
    glVertex2f(.0,.48);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(.05,.538);
    glVertex2f(.07,.55);
    glVertex2f(.09,.545);
    glEnd();

    FilledCircle(.0825,.53,.01,100);
    glBegin(GL_TRIANGLES);
    glVertex2f(.0455,.45);
    glVertex2f(.075,.438);
    glVertex2f(.085,.445);
    glEnd();
    glColor3ub(253,231,173);

    glBegin(GL_QUADS);
    glVertex2f(-.06,.43);
    glVertex2f(-.06,.35);
    glVertex2f(.03,.35);
    glVertex2f(.03,.43);
    glEnd();

    //leg
    glPushMatrix();
    glRotatef(leftL,0,0,1);
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-.05,-.5);
    glVertex2f(.1,-.5);
    glVertex2f(.09,-.45);
    glVertex2f(.05,-.45);
    glVertex2f(.08,0);
    glVertex2f(-.08,0);
    glEnd();
    glPopMatrix();

    glRotatef(0,0,0,1);
    glPushMatrix();
    glRotatef(rightL,0,0,1);
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-.05,-.5);
    glVertex2f(.1,-.5);
    glVertex2f(.09,-.45);
    glVertex2f(.05,-.45);
    glVertex2f(.08,0);
    glVertex2f(-.08,0);
    glEnd();

    glPopMatrix();

    glRotatef(0,0,0,1);
//body
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(-.065,.37);
    glVertex2f(-.1,.3);
    glVertex2f(-.08,0);
    glVertex2f(.08,0);
    glVertex2f(.083,.28);
    glVertex2f(.04,.35);
    glEnd();
    //bag
    glColor3f(0,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-.1,.3);
    glVertex2f(-.15,.08);
    glVertex2f(-.07,.02);
    glEnd();

    glColor3ub(253,231,173);
    glBegin(GL_POLYGON);

    glVertex2f(-.02,.14);
    glVertex2f(.04,.3);
    glVertex2f(-.07,.3);
    glVertex2f(-.1,.1);
    glVertex2f(.0,.05);
    glVertex2f(.02,.11);
    glEnd();
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(.04,.3);
    glVertex2f(-.07,.3);
    glVertex2f(-.084,.22);
    glVertex2f(.01,.2);

    glEnd();
}
//Function to draw people
void people(){
    glColor3ub(253,231,173);
    FilledCircle(0,.5,.1,100);
    glBegin(GL_TRIANGLES);
    glVertex2f(.12,.48);
    glVertex2f(.08,.55);
    glVertex2f(.0,.48);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(.05,.538);
    glVertex2f(.07,.55);
    glVertex2f(.09,.545);
    glEnd();

    FilledCircle(.0825,.53,.01,100);
    glBegin(GL_TRIANGLES);
    glVertex2f(.0455,.45);
    glVertex2f(.075,.438);
    glVertex2f(.085,.445);
    glEnd();
    glColor3ub(253,231,173);

    glBegin(GL_QUADS);
    glVertex2f(-.06,.43);
    glVertex2f(-.06,.35);
    glVertex2f(.03,.35);
    glVertex2f(.03,.43);
    glEnd();

    //leg
    glPushMatrix();
    glRotatef(leftL,0,0,1);
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-.05,-.5);
    glVertex2f(.1,-.5);
    glVertex2f(.09,-.45);
    glVertex2f(.05,-.45);
    glVertex2f(.08,0);
    glVertex2f(-.08,0);
    glEnd();
    glPopMatrix();

    glRotatef(0,0,0,1);
    glPushMatrix();
    glRotatef(rightL,0,0,1);
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-.05,-.5);
    glVertex2f(.1,-.5);
    glVertex2f(.09,-.45);
    glVertex2f(.05,-.45);
    glVertex2f(.08,0);
    glVertex2f(-.08,0);
    glEnd();

    glPopMatrix();

    glRotatef(0,0,0,1);


//body
    getColor();
    glBegin(GL_POLYGON);
    glVertex2f(-.065,.37);
    glVertex2f(-.1,.3);
    glVertex2f(-.08,0);
    glVertex2f(.08,0);
    glVertex2f(.083,.28);
    glVertex2f(.04,.35);
    glEnd();

    glColor3ub(253,231,173);
    glBegin(GL_POLYGON);

    glVertex2f(-.02,.14);
    glVertex2f(.04,.3);
    glVertex2f(-.07,.3);
    glVertex2f(-.1,.1);
    glVertex2f(.0,.05);
    glVertex2f(.02,.11);
    glEnd();
    getColor();
    glBegin(GL_POLYGON);
    glVertex2f(.04,.3);
    glVertex2f(-.07,.3);
    glVertex2f(-.084,.22);
    glVertex2f(.01,.2);

    glEnd();
}
//Function to draw window
void window(){

    glColor3ub(66,174,213);

    glBegin(GL_QUADS);
    glVertex2f(-1.615-.02,-.355);
    glVertex2f(-1.705-.02,-.355);
    glColor3ub(55,84,114);
    glVertex2f(-1.705-.02,-.425);
    glVertex2f(-1.615-.02,-.425);
    glEnd();
}
//Function to draw clock
void Watch(){

    glColor3f(1,1,1);
    FilledCircle(0,0, .5, 360);
    glColor3ub(134,66,33);
    FilledCircle(0,0, .49, 360);
    glColor3f(0,0,0);
    FilledCircle(0,0, .44, 360);
    glColor3ub(248,236,194);
    FilledCircle(0,0, .43, 360);
    glColor3f(0,0,0);
    FilledCircle(0,0, .4, 360);
    glColor3ub(248,236,194);
    FilledCircle(0,0, .39, 360);
    glColor3f(0,0,0);
    for(int i=1;i<=12;i++){
        glBegin(GL_QUADS);
        glVertex2f(-.01,.4);
        glVertex2f(-.01,.35);
        glVertex2f(.01,.35);
        glVertex2f(.01,.4);
        glEnd();
        glRotatef(-6,0,0,1);
        for(int j=1;j<=4;j++){
            glBegin(GL_QUADS);
            glVertex2f(-.005,.4);
            glVertex2f(-.005,.37);
            glVertex2f(.005,.37);
            glVertex2f(.005,.4);
            glEnd();
            glRotatef(-6,0,0,1);
        }
    }
    glRotatef(0,0,0,1);
    //hour
    glPushMatrix();

    glRotatef(Rhour-150,0,0,1);
    glBegin(GL_QUADS);
    glVertex2f(-.012,.25);
    glVertex2f(-.012,-.05);
    glVertex2f(.012,-.05);
    glVertex2f(.012,.25);
    glEnd();
    glPopMatrix();
    FilledCircle(0,0,.024,100);

    glRotatef(0,0,0,1);
    glPushMatrix();

    glRotatef(Rminute,0,0,1);
    glBegin(GL_QUADS);
    glVertex2f(-.008,.3);
    glVertex2f(-.008,-.07);
    glVertex2f(.008,-.07);
    glVertex2f(.008,.3);
    glEnd();
    glPopMatrix();
    FilledCircle(0,0,.016,100);

    //seconds
    glRotatef(0,0,0,1);
    glPushMatrix();
    glRotatef(Rsecond,0,0,1);
    glColor3ub(149,25,23);
    glBegin(GL_QUADS);
    glVertex2f(-.005,.35);
    glVertex2f(-.005,-.07);
    glVertex2f(.005,-.07);
    glVertex2f(.005,.35);
    glEnd();
    glRotatef(0,0,0,1);
    glPopMatrix();
    FilledCircle(0,0,.01,100);
}
//Function to draw building
void demoBuilding(){
    glBegin(GL_POLYGON);
    glVertex2f(-1.79,0+.3);
    glVertex2f(-1.79,-.62);
    glVertex2f(-1.4,-.62);
    glVertex2f(-1.4,0+.3);
    glVertex2f(-1.595,.05+.3);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(-1.595,.05+.3);
    glVertex2f(-1.39,-.01+.3);
    glVertex2f(-1.39,0+.3);
    glVertex2f(-1.595,.06+.3);
    glVertex2f(-1.80,0+.3);
    glVertex2f(-1.80,-.010+.3);
    glEnd();


    FilledCircle(-1.595,-.0+.3,.03,100);
    glColor3ub(48,87,102);
    FilledCircle(-1.595,-.0+.3,.025,100);

    glColor3ub(87,62, 58);
    glBegin(GL_QUADS);
    glVertex2f(-1.56,-.48);
    glVertex2f(-1.56,-.62);
    glVertex2f(-1.4,-.62);
    glVertex2f(-1.4,-.48);
    glEnd();
    //door
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.52,-.50);
    glVertex2f(-1.52,-.62);
    glVertex2f(-1.44,-.62);
    glVertex2f(-1.44,-.50);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-1.515,-.505);
    glVertex2f(-1.515,-.62);
    glVertex2f(-1.445,-.62);
    glVertex2f(-1.445,-.505);
    glEnd();

    glTranslatef(-1.515,0,0);
    glColor3ub(177,107,58);
    glBegin(GL_QUADS);
    glVertex2f(-1.515+1.515,-.505);
    glVertex2f(-1.515+1.515,-.62);
    glVertex2f(-1.445+1.515,-.62);
    glVertex2f(-1.445+1.515,-.505);
    glEnd();
    glColor3f(1,1,1);
    FilledCircle(-1.455+1.515,-.56,.005,100);

    glTranslatef(1.515,0,0);
    //garage door
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.75,-.5);
    glVertex2f(-1.75,-.62);
    glVertex2f(-1.59,-.62);
    glVertex2f(-1.59,-.5);
    glEnd();
    glColor3ub(87,62, 58);
    glBegin(GL_QUADS);
    glVertex2f(-1.74,-.51);
    glVertex2f(-1.74,-.62);
    glVertex2f(-1.6,-.62);
    glVertex2f(-1.6,-.51);
    glEnd();

    glColor3ub(87,62, 58);
    glBegin(GL_QUADS);
    glVertex2f(-1.76,-.45);
    glVertex2f(-1.76,-.46);
    glVertex2f(-1.42,-.46);
    glVertex2f(-1.42,-.45);
    glEnd();

    //window
    for(int i=1;i<=5;i++){
        for(int j=1;j<=2;j++){
             glColor3ub(87,62, 58);
             glBegin(GL_QUADS);
             glVertex2f(-1.72-.02,-.43);
             glVertex2f(-1.72-.02,-.44);
             glVertex2f(-1.60-.02,-.44);
             glVertex2f(-1.60-.02,-.43);
             glEnd();
             windowBack();
             window();

             glTranslatef(.17,0,0);
    }
    glTranslatef(-.17*2,.15,0);
    }
    Origin();

}
//Function to draw large building
void commonBuilidingLarge(){
    glBegin(GL_POLYGON);
    glVertex2f(-1.79,0+.3);
    glVertex2f(-1.79,-.62);
    glVertex2f(-1.4,-.62);
    glVertex2f(-1.4,0+.3);
    glVertex2f(-1.595,.05+.3);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(-1.595,.05+.3);
    glVertex2f(-1.39,-.01+.3);
    glVertex2f(-1.39,0+.3);
    glVertex2f(-1.595,.06+.3);
    glVertex2f(-1.80,0+.3);
    glVertex2f(-1.80,-.010+.3);
    glEnd();


    FilledCircle(-1.595,-.0+.3,.03,100);
    glColor3ub(48,87,102);
    FilledCircle(-1.595,-.0+.3,.025,100);

    glColor3ub(87,62, 58);
    glBegin(GL_QUADS);
    glVertex2f(-1.56,-.48);
    glVertex2f(-1.56,-.62);
    glVertex2f(-1.4,-.62);
    glVertex2f(-1.4,-.48);
    glEnd();

    //door
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.52,-.50);
    glVertex2f(-1.52,-.62);
    glVertex2f(-1.44,-.62);
    glVertex2f(-1.44,-.50);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-1.515,-.505);
    glVertex2f(-1.515,-.62);
    glVertex2f(-1.445,-.62);
    glVertex2f(-1.445,-.505);
    glEnd();

    glTranslatef(-1.515,0,0);
    glColor3ub(177,107,58);
    glBegin(GL_QUADS);
    glVertex2f(-1.515+1.515,-.505);
    glVertex2f(-1.515+1.515,-.62);
    glVertex2f(-1.445+1.515,-.62);
    glVertex2f(-1.445+1.515,-.505);
    glEnd();
    glColor3f(1,1,1);
    FilledCircle(-1.455+1.515,-.56,.005,100);

    glTranslatef(1.515,0,0);

    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,doorFront_ambient);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.52,-.62);
    glVertex2f(-1.55,-.64);
    glVertex2f(-1.41,-.64);
    glVertex2f(-1.44,-.62);
    glEnd();
    glDisable(GL_LIGHTING);

    //garage door
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.75,-.5);
    glVertex2f(-1.75,-.62);
    glVertex2f(-1.59,-.62);
    glVertex2f(-1.59,-.5);
    glEnd();
    glColor3ub(87,62, 58);
    glBegin(GL_QUADS);
    glVertex2f(-1.74,-.51);
    glVertex2f(-1.74,-.62);
    glVertex2f(-1.6,-.62);
    glVertex2f(-1.6,-.51);
    glEnd();
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,doorFront_ambient);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.75,-.62);
    glVertex2f(-1.78,-.64);
    glVertex2f(-1.56,-.64);
    glVertex2f(-1.59,-.62);
    glEnd();
    glDisable(GL_LIGHTING);

    glColor3ub(87,62, 58);
    glBegin(GL_QUADS);
    glVertex2f(-1.76,-.45);
    glVertex2f(-1.76,-.46);
    glVertex2f(-1.42,-.46);
    glVertex2f(-1.42,-.45);
    glEnd();

    //window
    for(int i=1;i<=5;i++){
        for(int j=1;j<=2;j++){
             glColor3ub(87,62, 58);
             glBegin(GL_QUADS);
             glVertex2f(-1.72-.02,-.43);
             glVertex2f(-1.72-.02,-.44);
             glVertex2f(-1.60-.02,-.44);
             glVertex2f(-1.60-.02,-.43);
             glEnd();
             windowBack();
             window();

             glTranslatef(.17,0,0);
    }
    glTranslatef(-.17*2,.15,0);
    }
    Origin();
}
//Function to draw shop
void shop(){
    glBegin(GL_POLYGON);
    glVertex2f(-1.79,0);
    glVertex2f(-1.79,-.62);
    glVertex2f(-1.4,-.62);
    glVertex2f(-1.4,0);
    glVertex2f(-1.595,.05);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(-1.595,.05);
    glVertex2f(-1.39,-.01);
    glVertex2f(-1.39,0);
    glVertex2f(-1.595,.06);
    glVertex2f(-1.80,0);
    glVertex2f(-1.80,-.010);
    glEnd();


    FilledCircle(-1.595,-.0,.03,100);
    glColor3ub(48,87,102);
    FilledCircle(-1.595,-.0,.025,100);

    glColor3ub(87,62, 58);
    glBegin(GL_QUADS);
    glVertex2f(-1.56,-.48);
    glVertex2f(-1.56,-.62);
    glVertex2f(-1.4,-.62);
    glVertex2f(-1.4,-.48);
    glEnd();

    //door
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.52,-.50);
    glVertex2f(-1.52,-.62);
    glVertex2f(-1.44,-.62);
    glVertex2f(-1.44,-.50);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-1.515,-.505);
    glVertex2f(-1.515,-.62);
    glVertex2f(-1.445,-.62);
    glVertex2f(-1.445,-.505);
    glEnd();

    glTranslatef(-1.515,0,0);
    glColor3ub(177,107,58);

    glBegin(GL_QUADS);
    glVertex2f(-1.515+1.515,-.505);
    glVertex2f(-1.515+1.515,-.62);
    glVertex2f(-1.445+1.515,-.62);
    glVertex2f(-1.445+1.515,-.505);
    glEnd();
    glColor3f(1,1,1);
    FilledCircle(-1.455+1.515,-.56,.005,100);

    glTranslatef(1.515,0,0);

    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,doorFront_ambient);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.52,-.62);
    glVertex2f(-1.55,-.64);
    glVertex2f(-1.41,-.64);
    glVertex2f(-1.44,-.62);
    glEnd();
    glDisable(GL_LIGHTING);
    //garage door
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.775,-.5);
    glVertex2f(-1.775,-.58);
    glVertex2f(-1.59,-.58);
    glVertex2f(-1.59,-.5);
    glEnd();
    glColor3ub(66,174,213);

    glBegin(GL_QUADS);
    glVertex2f(-1.6,-.51);
    glVertex2f(-1.765,-.51);
    glColor3ub(55,84,114);
    glVertex2f(-1.765,-.57);
    glVertex2f(-1.6,-.57);

    glEnd();
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,doorFront_ambient);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.75,-.62);
    glVertex2f(-1.78,-.64);
    glVertex2f(-1.56,-.64);
    glVertex2f(-1.59,-.62);
    glEnd();
    glDisable(GL_LIGHTING);

    glColor3ub(87,62, 58);
    glBegin(GL_QUADS);
    glVertex2f(-1.76,-.45);
    glVertex2f(-1.76,-.46);
    glVertex2f(-1.42,-.46);
    glVertex2f(-1.42,-.45);
    glEnd();

    //window
    for(int i=1;i<=3;i++){
        for(int j=1;j<=2;j++){
                glColor3ub(87,62, 58);
                glBegin(GL_QUADS);
                glVertex2f(-1.72-.02,-.43);
                glVertex2f(-1.72-.02,-.44);
                glVertex2f(-1.60-.02,-.44);
                glVertex2f(-1.60-.02,-.43);
                glEnd();
                windowBack();
                window();

                glTranslatef(.17,0,0);
    }
    glTranslatef(-.17*2,.15,0);
    }
    glTranslatef(0,-3*.15,0);
    Origin();

    for(int i=0;i<5;i++){
        bool red=false;
        glColor3ub(205,182,15);
        for(int j=0;j<2;j++){
            glBegin(GL_QUADS);
            glVertex2f(-1.78,-.46);
            glVertex2f(-1.78,-.51);
            glVertex2f(-1.76,-.51);
            glVertex2f(-1.76,-.46);
            glEnd();
            glColor3ub(126,103,6);
            if(red){
                glColor3ub(79,1,6);
            }
            FilledCircle(-1.77,-.51,.01,100);
            glColor3ub(175,6,27);
            red=true;
            glTranslatef(.02,0,0);
        }
    }
    Origin();
}
//Function to draw building
void commonBuiliding(){
    glColor3ub(204,126,64);
    glBegin(GL_POLYGON);
    glVertex2f(-1.79,0);
    glVertex2f(-1.79,-.62);
    glVertex2f(-1.4,-.62);
    glVertex2f(-1.4,0);
    glVertex2f(-1.595,.05);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(-1.595,.05);
    glVertex2f(-1.39,-.01);
    glVertex2f(-1.39,0);
    glVertex2f(-1.595,.06);
    glVertex2f(-1.80,0);
    glVertex2f(-1.80,-.010);
    glEnd();


    FilledCircle(-1.595,-.0,.03,100);
    glColor3ub(48,87,102);
    FilledCircle(-1.595,-.0,.025,100);

    glColor3ub(87,62, 58);
    glBegin(GL_QUADS);
    glVertex2f(-1.56,-.48);
    glVertex2f(-1.56,-.62);
    glVertex2f(-1.4,-.62);
    glVertex2f(-1.4,-.48);
    glEnd();

    //door
    glColor3f(1,1,1);

    glBegin(GL_QUADS);
    glVertex2f(-1.52,-.50);
    glVertex2f(-1.52,-.62);
    glVertex2f(-1.44,-.62);
    glVertex2f(-1.44,-.50);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-1.515,-.505);
    glVertex2f(-1.515,-.62);
    glVertex2f(-1.445,-.62);
    glVertex2f(-1.445,-.505);
    glEnd();

    glTranslatef(-1.515,0,0);
    glColor3ub(177,107,58);

    glBegin(GL_QUADS);
    glVertex2f(-1.515+1.515,-.505);
    glVertex2f(-1.515+1.515,-.62);
    glVertex2f(-1.445+1.515,-.62);
    glVertex2f(-1.445+1.515,-.505);
    glEnd();
    glColor3f(1,1,1);
    FilledCircle(-1.455+1.515,-.56,.005,100);

    glTranslatef(1.515,0,0);

    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,doorFront_ambient);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.52,-.62);
    glVertex2f(-1.55,-.64);
    glVertex2f(-1.41,-.64);
    glVertex2f(-1.44,-.62);
    glEnd();
    glDisable(GL_LIGHTING);

    //garage door
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.75,-.5);
    glVertex2f(-1.75,-.62);
    glVertex2f(-1.59,-.62);
    glVertex2f(-1.59,-.5);
    glEnd();
    glColor3ub(87,62, 58);
    glBegin(GL_QUADS);
    glVertex2f(-1.74,-.51);
    glVertex2f(-1.74,-.62);
    glVertex2f(-1.6,-.62);
    glVertex2f(-1.6,-.51);
    glEnd();
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,doorFront_ambient);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.75,-.62);
    glVertex2f(-1.78,-.64);
    glVertex2f(-1.56,-.64);
    glVertex2f(-1.59,-.62);
    glEnd();
    glDisable(GL_LIGHTING);

    glColor3ub(87,62, 58);
    glBegin(GL_QUADS);
    glVertex2f(-1.76,-.45);
    glVertex2f(-1.76,-.46);
    glVertex2f(-1.42,-.46);
    glVertex2f(-1.42,-.45);
    glEnd();

    //window
    for(int i=1;i<=3;i++){
        for(int j=1;j<=2;j++){
               glColor3ub(87,62, 58);
               glBegin(GL_QUADS);
               glVertex2f(-1.72-.02,-.43);
               glVertex2f(-1.72-.02,-.44);
               glVertex2f(-1.60-.02,-.44);
               glVertex2f(-1.60-.02,-.43);
               glEnd();
               windowBack();
               window();
               glTranslatef(.17,0,0);
    }
       glTranslatef(-.17*2,.15,0);
    }
    Origin();

}

void commercialBuilding(){
glBegin(GL_POLYGON);
glVertex2f(-1.72,-.64);
glVertex2f(-1.3,-.64);
glVertex2f(-1.32,-.62);
glVertex2f(-1.32,-.22);
glVertex2f(-1.34,-.2);
glVertex2f(-1.34,.2);
glVertex2f(-1.36,.22);
glVertex2f(-1.36,.5);
glVertex2f(-1.38,.52);
glVertex2f(-1.38,.8);
glVertex2f(-1.4,.82);
glVertex2f(-1.7,.82);
glVertex2f(-1.72,.8);
glVertex2f(-1.72,.52);
glVertex2f(-1.74,.5);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(-1.72,-.64);
glVertex2f(-1.72,.52);
glVertex2f(-1.74,.5);
glVertex2f(-1.74,.22);
glVertex2f(-1.76,.2);
glVertex2f(-1.76,-.2);
glVertex2f(-1.78,-.22);
glVertex2f(-1.78,-.62);
glVertex2f(-1.8,-.64);



glEnd();


glTranslatef(3.6575,2.125,0);
glScalef(3.1,3.75,0);
window();

glTranslatef(.25225,-.08,0);
glScalef(1.15,1,0);
window();

glTranslatef(0.16775,.0605,0);
glScalef(1.1,1.4,0);
window();

glTranslatef(.185,-.08,0);
glScalef(1.11,1,0);
window();
glScalef(1/(1.11*1.1*1.15*3.1),1/(3.75*1.4),1);
glTranslatef(-.1855-.16775-.25225-4.6575-.5,.08-.0605+.08-2.125+.394,0);

glColor3ub(gLobal_R,gLobal_G,gLobal_B);
glBegin(GL_POLYGON);
glVertex2f(-1.7,-.0);
glVertex2f(-1.7,-.64);
glVertex2f(-1.4,-.64);
glVertex2f(-1.4,-.0);
glVertex2f(-1.45,-.05);
glVertex2f(-1.65,-.05);
glVertex2f(-1.7,-.0);


glEnd();



glColor3ub(66,174,213);


glBegin(GL_POLYGON);
glVertex2f(-1.7,-.0);
glVertex2f(-1.65,-.48);
glVertex2f(-1.45,-.48);
glColor3ub(55,84,114);

glVertex2f(-1.45,-.1);
glVertex2f(-1.65,-.1);


glEnd();

glColor3f(.8,.8,.8);

glBegin(GL_POLYGON);
glVertex2f(-1.7,-.0);
glVertex2f(-1.65,-.64);
glVertex2f(-1.45,-.64);
glColor3ub(55,84,114);
glVertex2f(-1.45,-.5);
glVertex2f(-1.65,-.5);

glEnd();

glColor3ub(55,84,114);

glBegin(GL_POLYGON);
glVertex2f(-1.7,-.0);
glVertex2f(-1.63,-.64);
glVertex2f(-1.47,-.64);
glColor3ub(66,174,213);
glVertex2f(-1.47,-.52);
glVertex2f(-1.63,-.52);
glEnd();

glColor3f(.8,.8,.8);
for(int i=0;i<2;i++){
glBegin(GL_POLYGON);
glVertex2f(-1.7,-.0);
glVertex2f(-1.58,-.64);
glVertex2f(-1.575,-.64);
glColor3ub(55,84,114);
glVertex2f(-1.575,-.52);
glVertex2f(-1.58,-.52);

glEnd();
glTranslatef(.05,0,0);
}

}
//Function to draw building
void building(){

    glColor3ub(204,126,64);
    glBegin(GL_POLYGON);
    glVertex2f(-1.79,0);
    glVertex2f(-1.79,-.62);
    glVertex2f(-1.4,-.62);
    glVertex2f(-1.4,0);
    glVertex2f(-1.595,.05);
    glEnd();

    glColor3f(1,1,1);

    glBegin(GL_POLYGON);
    glVertex2f(-1.595,.05);
    glVertex2f(-1.39,-.01);
    glVertex2f(-1.39,0);
    glVertex2f(-1.595,.06);
    glVertex2f(-1.80,0);
    glVertex2f(-1.80,-.010);
    glEnd();


    FilledCircle(-1.595,-.0,.03,100);
    glColor3ub(48,87,102);
    FilledCircle(-1.595,-.0,.025,100);

    glColor3ub(87,62, 58);
    glBegin(GL_QUADS);
    glVertex2f(-1.56,-.48);
    glVertex2f(-1.56,-.62);
    glVertex2f(-1.4,-.62);
    glVertex2f(-1.4,-.48);
    glEnd();

    //door
    glColor3f(1,1,1);

    glBegin(GL_QUADS);
    glVertex2f(-1.52,-.50);
    glVertex2f(-1.52,-.62);
    glVertex2f(-1.44,-.62);
    glVertex2f(-1.44,-.50);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-1.515,-.505);
    glVertex2f(-1.515,-.62);
    glVertex2f(-1.445,-.62);
    glVertex2f(-1.445,-.505);
    glEnd();

    glTranslatef(-1.515,0,0);
    glRotatef(doorRot-doorRot2,0,1,0);
    glColor3ub(177,107,58);

    glBegin(GL_QUADS);
    glVertex2f(-1.515+1.515,-.505);
    glVertex2f(-1.515+1.515,-.62);
    glVertex2f(-1.445+1.515,-.62);
    glVertex2f(-1.445+1.515,-.505);
    glEnd();
    glColor3f(1,1,1);

    FilledCircle(-1.455+1.515,-.56,.005,100);
    Origin();

    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,doorFront_ambient);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.52,-.62);
    glVertex2f(-1.55,-.64);
    glVertex2f(-1.41,-.64);
    glVertex2f(-1.44,-.62);
    glEnd();
    glDisable(GL_LIGHTING);

    //garage door
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.75,-.5);
    glVertex2f(-1.75,-.62);
    glVertex2f(-1.59,-.5);
    glEnd();
    glColor3ub(87,62, 58);
    glBegin(GL_QUADS);
    glVertex2f(-1.74,-.51);
    glVertex2f(-1.74,-.62);
    glVertex2f(-1.6,-.62);
    glVertex2f(-1.6,-.51);
    glEnd();
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,doorFront_ambient);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.75,-.62);
    glVertex2f(-1.78,-.64);
    glVertex2f(-1.56,-.64);
    glVertex2f(-1.59,-.62);
    glEnd();
    glDisable(GL_LIGHTING);
    glColor3ub(87,62, 58);
    glBegin(GL_QUADS);
    glVertex2f(-1.76,-.45);
    glVertex2f(-1.76,-.46);
    glVertex2f(-1.42,-.46);
    glVertex2f(-1.42,-.45);
    glEnd();

    //window
    for(int i=1;i<=3;i++){
        for(int j=1;j<=2;j++){
    glColor3ub(87,62, 58);
    glBegin(GL_QUADS);
    glVertex2f(-1.72-.02,-.43);
    glVertex2f(-1.72-.02,-.44);
    glVertex2f(-1.60-.02,-.44);
    glVertex2f(-1.60-.02,-.43);
    glEnd();
    windowBack();
    window();

    glTranslatef(.17,0,0);
    }
    glTranslatef(-.17*2,.15,0);
    }
    Origin();
}

//Function to draw school
void school(){
    glColor3ub(172,23,27);
    glBegin(GL_POLYGON);
    glVertex2f(.9125,-.2);
    glVertex2f(1.025,-.24);
    glVertex2f(1.755,-.24);
    glVertex2f(1.8675,-.2);
    glEnd();

    for(int i=0;i<2;i++){
    glColor3ub(225,225,192);
    glBegin(GL_POLYGON);
    glVertex2f(1.025,-.24);
    glVertex2f(1.025,-.58);
    glVertex2f(1.25,-.58);
    glVertex2f(1.25,-.24);

    glEnd();
    glTranslatef(2.77,.05,0);
    for(int i=0;i<2;i++){
        for(int j=0; j<2;j++){
            windowBack();
            window();

            glColor3f(1,1,1);
            glBegin(GL_QUADS);
            glVertex2f(-1.6575-.02,-.355);
            glVertex2f(-1.6625-.02,-.355);
            glColor3ub(55,84,114);
            glVertex2f(-1.6625-.02,-.425);
            glVertex2f(-1.6575-.02,-.425);
            glEnd();

            glBegin(GL_QUADS);
            glVertex2f(-1.615-.02,-.3875);
            glVertex2f(-1.705-.02,-.3875);
            glColor3ub(55,84,114);
            glVertex2f(-1.705-.02,-.3925);
            glVertex2f(-1.615-.02,-.3925);
            glEnd();
            glTranslatef(.1,0,0);
        }
        glTranslatef(-2*.1,-.1,0);

    }
    glTranslatef(-2.77,-.05+2*.1,0);

    glTranslatef(.505,0,0);
    }
    glTranslatef(2*-.505,0,0);

    glColor3ub(250,250,214);
    glBegin(GL_POLYGON);
    glVertex2f(1.25,-.13);
    glVertex2f(1.25,-.58);
    glVertex2f(1.53,-.58);
    glVertex2f(1.53,-.13);
    glVertex2f(1.39,-.08);

    glEnd();

    glColor3ub(192,26,30);
    glBegin(GL_POLYGON);

    glVertex2f(1.39,-.065);
    glVertex2f(1.22,-.13);
    glVertex2f(1.25,-.13);
    glVertex2f(1.39,-.08);
    glVertex2f(1.53,-.13);
    glVertex2f(1.56,-.13);

    glEnd();
    glColor3f(1,1,1);
    FilledCircle(1.39,-.145,.04,100);
    glColor3ub(44,56,126);
    FilledCircle(1.39,-.145,.03,100);


    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(1.275,-.195);
    glVertex2f(1.275,-.265);
    glVertex2f(1.505,-.265);
    glVertex2f(1.505,-.195);

    glEnd();

    //signboard
    glColor3ub(44,56,126);
    glBegin(GL_POLYGON);
    glVertex2f(1.28,-.2);
    glVertex2f(1.28,-.26);
    glVertex2f(1.5,-.26);
    glVertex2f(1.5,-.2);

    glEnd();

    glColor3f(1,1,0);
   renderBitmapString(1.295,-.2525,GLUT_BITMAP_TIMES_ROMAN_24,"School");
    glBegin(GL_POLYGON);
    glVertex2f(1.31,-.48);
    glVertex2f(1.31,-.58);
    glVertex2f(1.47,-.58);
    glVertex2f(1.47,-.48);

    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(1.32,-.49);
    glVertex2f(1.32,-.58);
    glVertex2f(1.46,-.58);
    glVertex2f(1.46,-.49);

    glEnd();
    glTranslatef(1.32,0,0);
    glPushMatrix();
    glRotatef(schoolDoorRot,0,1,0);
    glColor3ub(224,141,65);
    glBegin(GL_POLYGON);
    glVertex2f(1.32-1.32,-.49);
    glVertex2f(1.32-1.32,-.58);
    glVertex2f(1.46-1.32,-.58);
    glVertex2f(1.46-1.32,-.49);
    glEnd();
    glColor3f(1,1,1);
    FilledCircle(1.45-1.32,-.53,.005,100);

    glPopMatrix();
    glRotatef(0,0,1,0);
    glTranslatef(-1.32,0,0);

    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,doorFront_ambient);
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(1.25,-.58);
    glVertex2f(1.53,-.58);
    glVertex2f(1.59,-.64);
    glVertex2f(1.19,-.64);
    glEnd();
    glDisable(GL_LIGHTING);

    glTranslatef(2.77+.245,.07,0);
    for(int i=0;i<2;i++){
        for(int j=0; j<2;j++){
            windowBack();
            window();

            glColor3f(1,1,1);
            glBegin(GL_QUADS);
            glVertex2f(-1.6575-.02,-.355);
            glVertex2f(-1.6625-.02,-.355);
            glVertex2f(-1.6625-.02,-.425);
            glVertex2f(-1.6575-.02,-.425);
            glEnd();

            glBegin(GL_QUADS);
            glVertex2f(-1.615-.02,-.3875);
            glVertex2f(-1.705-.02,-.3875);
            glColor3ub(55,84,114);
            glVertex2f(-1.705-.02,-.3925);
            glVertex2f(-1.615-.02,-.3925);
            glEnd();
            glTranslatef(.1,0,0);
        }
        glTranslatef(-2*.1,-.1,0);

    }
    glTranslatef(-2.77-.245,-.07+2*.1,0);



    for(int i=0;i<2;i++){
    glColor3ub(250,250,214);
    glBegin(GL_POLYGON);
    glVertex2f(.8,-.24);
    glVertex2f(.8,-.58);
    glVertex2f(1.025,-.58);
    glVertex2f(1.025,-.24);
    glVertex2f(.9125,-.2);

    glEnd();
    glColor3ub(192,26,30);
    glBegin(GL_POLYGON);
    glVertex2f(.9125,-.185);
    glVertex2f(.77,-.24);
    glVertex2f(.8,-.24);
    glVertex2f(.9125,-.2);
    glVertex2f(1.025,-.24);
    glVertex2f(1.055,-.24);



    glEnd();

    glTranslatef(2.77-.225,.03,0);
    for(int i=0;i<2;i++){
        for(int j=0; j<2;j++){
            windowBack();
            window();

            glColor3f(1,1,1);
            glBegin(GL_QUADS);
            glVertex2f(-1.6575-.02,-.355);
            glVertex2f(-1.6625-.02,-.355);
            glColor3ub(55,84,114);
            glVertex2f(-1.6625-.02,-.425);
            glVertex2f(-1.6575-.02,-.425);
            glEnd();

            glBegin(GL_QUADS);
            glVertex2f(-1.615-.02,-.3875);
            glVertex2f(-1.705-.02,-.3875);
            glColor3ub(55,84,114);
            glVertex2f(-1.705-.02,-.3925);
            glVertex2f(-1.615-.02,-.3925);
            glEnd();
            glTranslatef(.1,0,0);
        }
        glTranslatef(-2*.1,-.1,0);

    }
    glTranslatef(-2.77+.225,-.03+2*.1,0);


    glTranslatef(.955,0,0);
    }
    glTranslatef(2*-.955,0,0);



}
//Function to draw car
void car(){
getColor();
glBegin(GL_POLYGON);

glVertex2f(-.22,.08);
glVertex2f(-.28,.08);
glVertex2f(-.3,0);
glVertex2f(.3,0);
glVertex2f(.28,.08);
glVertex2f(.2,.08);
glVertex2f(.16,.14);
glVertex2f(-.18,.14);
glEnd();
glColor3f(0,0,0);
glBegin(GL_POLYGON);

glVertex2f(-.17,.13);
glVertex2f(-.21,.07);
glColor3ub(113,113,113);
glVertex2f(.19,.07);
glVertex2f(.15,.13);
glEnd();
getColor();
glBegin(GL_POLYGON);

glVertex2f(-.01,.13);
glVertex2f(-.01,.07);
glVertex2f(.0,.07);
glVertex2f(.0,.13);
glEnd();

glTranslatef(-.15,0,0);
for(int i=0;i<2;i++){
    glColor3f(0,0,0);
    FilledCircle(0,0,.04,100);
    glColor3f(.6,.6,.6);
    FilledCircle(0,0,.02,100);
    glTranslatef(.15+.2,0,0);
}
glTranslatef(-.2-.35,0,0);
glColor3f(.8,.8,.8);
glBegin(GL_POLYGON);
glVertex2f(.28,.08);
glVertex2f(.26,.08);
glVertex2f(.27,.06);
glVertex2f(.282,.06);
glEnd();
}
//Function to draw sun
void sun()
{

FilledCircle(0,0.6,.1,100);
}
//Function for defining origin
void Origin(){
    glLoadIdentity();
	glOrtho(-1.8,2,-1,1,-1,1);

}

void morningDisp(int a){
    firstSound=true;
    isMorning=true;
    sunSpeed=.03;
    speed=3*18;
    sunInc=-20;
    peopleSpeed=.002;
    peoplePos2=.8;
    peoplePos=-1.48;
    boyPosX=-1.48;
    boyPosY=-.58;
    boyPosX2=0;
    boyPosY2=0;
    sunInc=-20;
    sunPosX=-1.6;
    sunPosY=-.1;
    sunSpeed=.03;
    carPosX1=-3.8;
    carPosX2=3.8;
    car2PosX1=-1.6;
    car2PosX2=1.6;
    carSpeed=.01;
    cloudScalVal=0;
//    glutDisplayFunc(morning);
}
//Function for summer season
void summer()
{
init();
    glClear(GL_COLOR_BUFFER_BIT);
    Origin();

    //sky
    glColor3ub(44,56,126);
    glBegin(GL_QUADS);
    glVertex2f(2,1);
    glVertex2f(-1.8,1);
    glColor3ub(0,188,126);
    glVertex2f(-1.8,-.3);
    glVertex2f(2,-.3);
    glEnd();
    glColor3ub(255,250,250);
    glColor3ub(243,218,37);
    glPushMatrix();
    glTranslatef(sunPosX,sunPosY,0);
    sun();
    glPopMatrix();
    Origin();
    if(planePos>=-2){
        glRotatef(5,0,0,1);
    }
    if(planePos>=2.5){
        glRotatef(0,0,0,1);
    }
    glTranslatef(planePos,1,0);
    glScalef(.3,.3,1);
    Origin();
    glTranslatef(-.5,.5,0);
    glScalef(.6+cloudScalVal,.6+cloudScalVal,1);
    Clouds(0,0);
    glTranslatef(-1,.2,0);
    Clouds(0,0);
    glTranslatef(-1,.2,0);
    Clouds(.2,0);
    glTranslatef(2.7,0,0);
    Clouds(0,0);
    glTranslatef(1,-.1,0);
    Clouds(0,0);
    glTranslatef(1,-.1,0);
    Clouds(0,0);
    glTranslatef(.5,.3,0);
    Clouds(0,0);
    glTranslatef(.5,-.5,0);
    Clouds(0,0);
    glTranslatef(-.5,-.3,0);
    Clouds(0,0);
    glTranslatef(-4.5,-.1,0);
    Clouds(0,0);
    Origin();
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ground_ambient);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.8,-.3);
    glVertex2f(-1.8,-1);
    glVertex2f(2,-1);
    glVertex2f(2,-.3);
    glEnd();
    glDisable(GL_LIGHTING);
     //road
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,road_ambient);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.8,-.7);
    glVertex2f(-1.8,-1);
    glVertex2f(2,-1);
    glVertex2f(2,-.7);
    glEnd();
    glDisable(GL_LIGHTING);

    glColor3ub(255,255,255);
    for(int i=0;i<18;i++){
    glBegin(GL_QUADS);
    glVertex2f(-1.798,-.845);
    glVertex2f(-1.8,-.855);
    glVertex2f(-1.7,-.855);
    glVertex2f(-1.702,-.845);
    glEnd();
    glTranslatef(.25,0,0);
    }
    Origin();



    //footpath
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,path_ambient);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.8,-.64);
    glVertex2f(-1.8,-.7);
    glVertex2f(2,-.7);
    glVertex2f(2,-.64);
    glEnd();
    glDisable(GL_LIGHTING);

    glColor3f(.3,.3,.3);
    glBegin(GL_QUADS);
    glVertex2f(-1.8,-.7);
    glVertex2f(-1.8,-.715);
    glVertex2f(2,-.715);
    glVertex2f(2,-.7);
    glEnd();

    //grass
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,grass_ambient);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.8,-.54);
    glVertex2f(-1.8,-.64);
    glVertex2f(2,-.64);
    glVertex2f(2,-.54);
    glEnd();
    glDisable(GL_LIGHTING);

    glTranslatef(-.15,.08,0);
    glColor3ub(0,150,136);
    demoBuilding();
    glTranslatef(-.45,-.15,0);
    glScalef(.6,.6,1);
    setColor(255,255,255);
    commercialBuilding();
    Origin();
    glTranslatef(.7,.08,0);
    glColor3ub(204,126,64);
    demoBuilding();
    glTranslatef(.67,-.1,0);
    glScalef(.7,.7,1);
    setColor(248,153,203);
    commercialBuilding();
    Origin();

    glTranslatef(1.55,.08,0);
    glColor3ub(144,52,162);
    demoBuilding();

    glTranslatef(2,.08,0);
    glColor3ub(204,126,64);
    demoBuilding();

    glTranslatef(2.8,.08,0);
    glColor3ub(204,126,64);
    demoBuilding();
    glTranslatef(3.22,.08,0);
    glColor3ub(204,126,64);
    commonBuiliding();
    Origin();

    glTranslatef(2,-.1,0);
    glScalef(.7,.7,1);
    setColor(255,255,255);
    commercialBuilding();
    Origin();
    glTranslatef(3.1,-.1,0);
    glScalef(.7,.7,1);
    setColor(255,255,255);
    commercialBuilding();
    Origin();

    glTranslatef(-1.65,-.4,0);
    glScalef(.3,.3,1);
    grass();
    glTranslatef(1.5,0,0);
    grass();
    glTranslatef(1.5,-.1,0);
    grass();
    glTranslatef(1.4,0,0);
    grass();
    glTranslatef(1.4,0,0);
    grass();
    glTranslatef(1.4,0,0);
    grass();
    glTranslatef(4,0,0);
    grass();
    Origin();

 renderBitmapString(.2,0.89,GLUT_BITMAP_TIMES_ROMAN_24,"SUMMER SEASON");
 renderBitmapString(1.5,0.5,GLUT_BITMAP_TIMES_ROMAN_24,"w- winter season");
 renderBitmapString(1.5,0.4,GLUT_BITMAP_TIMES_ROMAN_24,"a- autumn season");
 renderBitmapString(1.5,0.3,GLUT_BITMAP_TIMES_ROMAN_24,"r- rainy season");
    //front
    building();
    glTranslatef(.42,0,0);
    glColor3ub(0,150,136);
    commonBuiliding();
    glTranslatef(2*.42,0,0);
    glColor3ub(144,52,162);
    commonBuilidingLarge();
    glTranslatef(3*.42,0,0);
    glColor3ub(0,150,136);
    shop();


    school();

    glTranslatef(-1.9,-.07,0);
    float plantX=0;
    plant(0);
    plantX+=.43;
    plant(plantX);
    plantX+=.43;
    plant(plantX);
    plantX+=.4;
    plant(plantX);
    plantX+=.4;
    plant(plantX);
    plantX+=.52;
    plant(plantX);
    plantX+=.42;
    plant(plantX);
    plantX+=.32;
    plant(plantX);
    plantX+=.52;
    plant(plantX);
    plantX+=.32;
    plant(plantX);
    Origin();

    glTranslatef(4*.42,0,0);
    setColor(255,255,255);
    commercialBuilding();
    Origin();
    glTranslatef(.129,.6625,0);
    glScalef(.25,.25,0);
    Watch();
    Origin();
    glScalef(.8,.8,0);
    glTranslatef(5*.455,-.16,0);
    setColor(251,255,171);
    commercialBuilding();
    Origin();
    if(doorOpen){
    glTranslatef(boyPosX+boyPosX2,boyPosY+boyPosY2,0);
    glScalef(.08+schoolBoyScalVal,.08+schoolBoyScalVal,1);
    schoolBoy();
    Origin();
    }
    glTranslatef(peoplePos,-.62,0);
    glScalef(.12,.12,1);
    setColor(88,9,153);
    people();
    glTranslatef(2,0,0);
    setColor(175,99,237);
    people();
    glTranslatef(6,0,0);
    setColor(146,7,9);
    people();

    Origin();
    glTranslatef(peoplePos2,-.62,0);
    glScalef(.12,.12,1);
    setColor(88,9,153);
    people();
    glTranslatef(2,0,0);
    setColor(175,99,237);
    people();
    glTranslatef(6,0,0);
    setColor(146,7,9);
    people();

    Origin();

    glRotatef(180,0,1,0);

    glTranslatef(peoplePos,-.61,0);
    glScalef(.12,.12,1);
    setColor(88,9,153);
    people();
    glTranslatef(2,0,0);
    setColor(175,99,237);
    people();
    glTranslatef(6,0,0);
    setColor(146,7,9);
    people();

    Origin();

    glRotatef(180,0,1,0);
    glTranslatef(peoplePos2,-.61,0);
    glScalef(.12,.12,1);
    setColor(88,9,153);
    people();
    glTranslatef(2,0,0);
    setColor(175,99,237);
    people();
    glTranslatef(6,0,0);
    setColor(146,7,9);
    people();

    Origin();

    glTranslatef(-1.6,0,0);
    for(int i=0;i<5;i++){
       streetLight();
       glTranslatef(.8,0,0);
    }
    Origin();

    glPushMatrix();
    glTranslatef(carPosX1,0,0);
    setColor(137,0,3);
    glTranslatef(0,-.8,0);
    glScalef(.6,.6,1);
    car();
    glTranslatef(.7,0,0);
    setColor(5,25,102);
    car();
    glTranslatef(1,0,0);
    setColor(255,255,255);
    car();
    glTranslatef(.9,0,0);
    setColor(148,148,148);
    car();
    glPopMatrix();
    Origin();

    setColor(5,25,102);
    glPushMatrix();
    glTranslatef(carPosX2,0,0);
    glRotatef(180,0,1,0);
    glTranslatef(0,-.95,0);
    glScalef(.6,.6,1);
    car();
    glTranslatef(.7,0,0);
    setColor(103,0,5);
    car();
    glTranslatef(1,0,0);
    setColor(225,199,99);
    car();
    glTranslatef(.9,0,0);
    setColor(55,255,0);
    car();
    glPopMatrix();
    Origin();


    glPushMatrix();
    glTranslatef(car2PosX1,0,0);
    setColor(137,0,3);
    glTranslatef(0,-.8,0);
    glScalef(.6,.6,1);
    car();
    glTranslatef(.7,0,0);
    setColor(103,0,5);
    car();
    glTranslatef(1,0,0);
    setColor(225,199,99);
    car();
    glTranslatef(.9,0,0);
    setColor(55,255,0);
    car();


    glPopMatrix();
    Origin();

    setColor(5,25,102);
    glPushMatrix();
    glTranslatef(car2PosX2,0,0);
    glRotatef(180,0,1,0);
    glTranslatef(0,-.95,0);
    glScalef(.6,.6,1);
    car();
    glTranslatef(.7,0,0);
    setColor(5,25,102);
    car();
    glTranslatef(1,0,0);
    setColor(255,255,255);
    car();
    glTranslatef(.9,0,0);
    setColor(148,148,148);
    car();
    glPopMatrix();
    Origin();
    anim();
    glFlush();

}
//Function for draw strings
void drawstring(float x,float y,float z,char *msg)
{

    glRasterPos3f(x,y,z);
    for(int i=0;i<strlen(msg);i++)
    {

        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg[i]);
    }
}//Function to display the names in introductory window
void welcomeDisplay()
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

   drawstring(900,500,0,"SUBMITTED TO");

   drawstring(880,450,0,"Mr. PRADEEP KANCHAN");

    drawstring(980,400,0,"Asst Prof Gd III, Dept of CSE, NMAMIT");

    drawstring(870,740,0,"TEJAS SUDHIR BHAT  (4NM18CS202)");

     drawstring(870,790,0,"SURAJ NAYAK  (4NM18CS197)");

     drawstring(980,840,0,"BY");

    drawstring(880,1000,0,"SEASON SIMULATION");

     drawstring(900,1050,0,"MINI PROJECT ON");

     drawstring(750,1300,0,"NMAM INSTITUTE OF TECHNOLOGY");

   drawstring(650,1200,0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");

    glutSwapBuffers();
}
//Function to draw line
void line()
{
    glBegin(GL_LINES);
    glColor3d(0,0.3,0.7);
    glVertex2d(0,598);
    glVertex2d(0,596);
    glEnd();
}

//Function for winter season
void winter()
{
init();
    glClear(GL_COLOR_BUFFER_BIT);
    Origin();

   //sky
    glColor3ub(255,250,250);
    glBegin(GL_QUADS);
    glVertex2f(2,1);
    glVertex2f(-1.8,1);
    glColor3ub(196,196,196);
    glVertex2f(-1.8,-.3);
    glVertex2f(2,-.3);
    glEnd();
    glColor3ub(255,250,250);
    glColor3ub(255,250,250);
    glPushMatrix();
    glTranslatef(sunPosX,sunPosY,0);
    sun();
    glPopMatrix();
    Origin();
    if(planePos>=-2){
        glRotatef(5,0,0,1);
    }
    if(planePos>=2.5){
        glRotatef(0,0,0,1);
    }
    glTranslatef(planePos,1,0);
    glScalef(.3,.3,1);

    Origin();

    glColor3ub(255,250,250);
    glTranslatef(-.5,.5,0);
    glScalef(.6+cloudScalVal,.6+cloudScalVal,1);
    Clouds(0,0);
    glTranslatef(-1,.2,0);
    Clouds(0,0);
    glTranslatef(-1,.2,0);
    Clouds(.2,0);
    glTranslatef(2.7,0,0);
    Clouds(0,0);
    glTranslatef(1,-.1,0);
    Clouds(0,0);
    glTranslatef(1,-.1,0);
    Clouds(0,0);
    glTranslatef(.5,.3,0);
    Clouds(0,0);
    glTranslatef(.5,-.5,0);
    Clouds(0,0);
    glTranslatef(-.5,-.3,0);
    Clouds(0,0);
    glTranslatef(-4.5,-.1,0);
    Clouds(0,0);
    Origin();
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ground_ambient);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.8,-.3);
    glVertex2f(-1.8,-1);
    glVertex2f(2,-1);
    glVertex2f(2,-.3);
    glEnd();
    glDisable(GL_LIGHTING);
     //road
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,road_ambient);
    glColor3f(1,0.95,0.95);
    glBegin(GL_QUADS);
    glVertex2f(-1.8,-.7);
    glVertex2f(-1.8,-1);
    glVertex2f(2,-1);
    glVertex2f(2,-.7);
    glEnd();
    glDisable(GL_LIGHTING);

    glColor3ub(255,255,255);
    for(int i=0;i<18;i++){
    glBegin(GL_QUADS);
    glVertex2f(-1.798,-.845);
    glVertex2f(-1.8,-.855);
    glVertex2f(-1.7,-.855);
    glVertex2f(-1.702,-.845);
    glEnd();
    glTranslatef(.25,0,0);
    }
    Origin();
    //footpath
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,path_ambient);
    glColor3f(1,0.95,0.95);
    glBegin(GL_QUADS);
    glVertex2f(-1.8,-.64);
    glVertex2f(-1.8,-.7);
    glVertex2f(2,-.7);
    glVertex2f(2,-.64);
    glEnd();
    glDisable(GL_LIGHTING);

    glColor3f(.3,.3,.3);
    glBegin(GL_QUADS);
    glVertex2f(-1.8,-.7);
    glVertex2f(-1.8,-.715);
    glVertex2f(2,-.715);
    glVertex2f(2,-.7);
    glEnd();

    //grass
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,grass_ambient);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.8,-.54);
    glVertex2f(-1.8,-.64);
    glVertex2f(2,-.64);
    glVertex2f(2,-.54);
    glEnd();
    glDisable(GL_LIGHTING);

    glTranslatef(-.15,.08,0);
    glColor3ub(0,150,136);
    demoBuilding();
    glTranslatef(-.45,-.15,0);
    glScalef(.6,.6,1);
    setColor(255,250,250);
    commercialBuilding();
    Origin();
    glTranslatef(.7,.08,0);
    glColor3ub(204,126,64);
    demoBuilding();
    glTranslatef(.67,-.1,0);
    glScalef(.7,.7,1);
    setColor(248,153,203);
    commercialBuilding();
    Origin();

    glTranslatef(1.55,.08,0);
    glColor3ub(144,52,162);
    demoBuilding();

    glTranslatef(2,.08,0);
    glColor3ub(204,126,64);
    demoBuilding();

    glTranslatef(2.8,.08,0);
    glColor3ub(204,126,64);
    demoBuilding();
    glTranslatef(3.22,.08,0);
    glColor3ub(204,126,64);
    commonBuiliding();
    Origin();

    glTranslatef(2,-.1,0);
    glScalef(.7,.7,1);
    setColor(255,255,255);
    commercialBuilding();
    Origin();
    glTranslatef(3.1,-.1,0);
    glScalef(.7,.7,1);
    setColor(255,255,255);
    commercialBuilding();
    Origin();

    glTranslatef(-1.65,-.4,0);
    glScalef(.3,.3,1);
    grass();
    glTranslatef(1.5,0,0);
    grass();
    glTranslatef(1.5,-.1,0);
    grass();
    glTranslatef(1.4,0,0);
    grass();
    glTranslatef(1.4,0,0);
    grass();
    glTranslatef(1.4,0,0);
    grass();
    glTranslatef(4,0,0);
    grass();
    Origin();

    renderBitmapString(.2,0.89,GLUT_BITMAP_TIMES_ROMAN_24,"WINTER SEASON");
    renderBitmapString(1.5,0.5,GLUT_BITMAP_TIMES_ROMAN_24,"s- summer season");
 renderBitmapString(1.5,0.4,GLUT_BITMAP_TIMES_ROMAN_24,"a- autumn season");
 renderBitmapString(1.5,0.3,GLUT_BITMAP_TIMES_ROMAN_24,"r- rainy season");
   building();
    glTranslatef(.42,0,0);
    glColor3ub(0,150,136);
    commonBuiliding();
    glTranslatef(2*.42,0,0);
    glColor3ub(144,52,162);
    commonBuilidingLarge();
    glTranslatef(3*.42,0,0);
    glColor3ub(0,150,136);
    shop();


    school();

    glTranslatef(-1.9,-.07,0);
    float plantX=0;
    plant(0);
    plantX+=.43;
    plant(plantX);
    plantX+=.43;
    plant(plantX);
    plantX+=.4;
    plant(plantX);
    plantX+=.4;
    plant(plantX);
    plantX+=.52;
    plant(plantX);
    plantX+=.42;
    plant(plantX);
    plantX+=.32;
    plant(plantX);
    plantX+=.52;
    plant(plantX);
    plantX+=.32;
    plant(plantX);
    Origin();

    glTranslatef(4*.42,0,0);
    setColor(255,255,255);
    commercialBuilding();
    Origin();
    glTranslatef(.129,.6625,0);
    glScalef(.25,.25,0);
    Watch();
    Origin();
    glScalef(.8,.8,0);
    glTranslatef(5*.455,-.16,0);
    setColor(251,255,171);
    commercialBuilding();
    Origin();
    if(doorOpen){
    glTranslatef(boyPosX+boyPosX2,boyPosY+boyPosY2,0);
    glScalef(.08+schoolBoyScalVal,.08+schoolBoyScalVal,1);
    schoolBoy();
    Origin();
    }
    glTranslatef(peoplePos,-.62,0);
    glScalef(.12,.12,1);
    setColor(88,9,153);
    people();
    glTranslatef(2,0,0);
    setColor(175,99,237);
    people();
    glTranslatef(6,0,0);
    setColor(146,7,9);
    people();

    Origin();
    glTranslatef(peoplePos2,-.62,0);
    glScalef(.12,.12,1);
    setColor(88,9,153);
    people();
    glTranslatef(2,0,0);
    setColor(175,99,237);
    people();
    glTranslatef(6,0,0);
    setColor(146,7,9);
    people();

    Origin();

    glRotatef(180,0,1,0);

    glTranslatef(peoplePos,-.61,0);
    glScalef(.12,.12,1);
    setColor(88,9,153);
    people();
    glTranslatef(2,0,0);
    setColor(175,99,237);
    people();
    glTranslatef(6,0,0);
    setColor(146,7,9);
    people();

    Origin();

    glRotatef(180,0,1,0);
    glTranslatef(peoplePos2,-.61,0);
    glScalef(.12,.12,1);
    setColor(88,9,153);
    people();
    glTranslatef(2,0,0);
    setColor(175,99,237);
    people();
    glTranslatef(6,0,0);
    setColor(146,7,9);
    people();

    Origin();

    glTranslatef(-1.6,0,0);
    for(int i=0;i<5;i++){
       streetLight();
       glTranslatef(.8,0,0);
    }
    Origin();

    glPushMatrix();
    glTranslatef(carPosX1,0,0);
    setColor(137,0,3);
    glTranslatef(0,-.8,0);
    glScalef(.6,.6,1);
    car();
    glTranslatef(.7,0,0);
    setColor(5,25,102);
    car();
    glTranslatef(1,0,0);
    setColor(255,255,255);
    car();
    glTranslatef(.9,0,0);
    setColor(148,148,148);
    car();
    glPopMatrix();
    Origin();

    setColor(5,25,102);
    glPushMatrix();
    glTranslatef(carPosX2,0,0);
    glRotatef(180,0,1,0);
    glTranslatef(0,-.95,0);
    glScalef(.6,.6,1);
    car();
    glTranslatef(.7,0,0);
    setColor(103,0,5);
    car();
    glTranslatef(1,0,0);
    setColor(225,199,99);
    car();
    glTranslatef(.9,0,0);
    setColor(55,255,0);
    car();
    glPopMatrix();
    Origin();


    glPushMatrix();
    glTranslatef(car2PosX1,0,0);
    setColor(137,0,3);
    glTranslatef(0,-.8,0);
    glScalef(.6,.6,1);
    car();
    glTranslatef(.7,0,0);
    setColor(103,0,5);
    car();
    glTranslatef(1,0,0);
    setColor(225,199,99);
    car();
    glTranslatef(.9,0,0);
    setColor(55,255,0);
    car();


    glPopMatrix();
    Origin();

    setColor(5,25,102);
    glPushMatrix();
    glTranslatef(car2PosX2,0,0);
    glRotatef(180,0,1,0);
    glTranslatef(0,-.95,0);
    glScalef(.6,.6,1);
    car();
    glTranslatef(.7,0,0);
    setColor(5,25,102);
    car();
    glTranslatef(1,0,0);
    setColor(255,255,255);
    car();
    glTranslatef(.9,0,0);
    setColor(148,148,148);
    car();
    glPopMatrix();
    Origin();
     myinit();

    temps++;
    if(temps<3)
    {
        for(int i=0;i<2600;i+=15)
        {
            for(int j=0;j<2600;j+=15)
            {
                glPushMatrix();
                glTranslatef(i,-j,0);
                glBegin(GL_LINES);
                glColor3d(1,1,1);
                glVertex2d(0,598);
                glVertex2d(0,596);
                glEnd();
                glPopMatrix();
            }
        }
    }
    else if(temps>=3 && temps<6)
    {
        for(int i=0;i<2600;i+=15)
        {
            for(int j=5;j<2600;j+=15)
            {
                glPushMatrix();
                glTranslatef(i,-j,0);
                glBegin(GL_LINES);
                glColor3d(1,1,1);
                glVertex2d(0,598);
                glVertex2d(0,596);
                glEnd();
                glPopMatrix();
            }
        }
    }


    else if(temps>=6 && temps<9)
    {
        for(int i=5;i<2600;i+=15)
        {
            for(int j=10;j<2600;j+=15)
            {
                glPushMatrix();
                glTranslatef(i,-j,0);
                glBegin(GL_LINES);
              glColor3d(1,1,1);
                glVertex2d(0,598);
                glVertex2d(0,596);
                glEnd();
                glPopMatrix();
            }
        }
    }
    else
        temps=0;
    anim();
     glFlush();
}
//Function for clouds in rainy season
void Cloudsr(float xdiff, float ydiff){
glColor3ub(0,0,0);
FilledCircle(0+xdiff,.08+ydiff,.07,360);

FilledCircle(-.06+xdiff,.08+ydiff,.07,360);
FilledCircle(.06+xdiff,.085+ydiff,.07,360);
FilledCircle(-.06*2+xdiff,.08+ydiff,.07,360);
FilledCircle(.05*2+xdiff,.08+ydiff,.07,360);
FilledCircle(-.04*2+xdiff,.06*2+ydiff,.07,360);
FilledCircle(.05*2+xdiff,.05*2+ydiff,.07,360);
FilledCircle(0.03+xdiff,.065*2+ydiff,.07,360);
FilledCircle(-0.05*3+xdiff,.04*2+ydiff,.07,360);
}
//Function for rainy season
void rain()
{
init1();
    glClear(GL_COLOR_BUFFER_BIT);
    Origin();

    //sky
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(2,1);
    glVertex2f(-1.8,1);
    glColor3ub(0,188,212);
    glVertex2f(-1.8,-.3);
    glVertex2f(2,-.3);
    glEnd();
    glColor3ub(0,0,0);
    glColor3ub(0,0,0);
    glPushMatrix();
    glTranslatef(sunPosX,sunPosY,0);

    glPopMatrix();
    Origin();
    if(planePos>=-2){
        glRotatef(5,0,0,1);
    }
    if(planePos>=2.5){
        glRotatef(0,0,0,1);
    }
    glTranslatef(planePos,1,0);
    glScalef(.3,.3,1);

    Origin();


    glTranslatef(-.5,.5,0);
    glScalef(.6+cloudScalVal,.6+cloudScalVal,1);
    Cloudsr(0,0);
    glTranslatef(-1,.2,0);
    Cloudsr(0,0);
    glTranslatef(-1,.2,0);
    Cloudsr(.2,0);
    glTranslatef(2.7,0,0);
    Cloudsr(0,0);
    glTranslatef(1,-.1,0);
    Cloudsr(0,0);
    glTranslatef(1,-.1,0);
    Cloudsr(0,0);
    glTranslatef(.5,.3,0);
    Cloudsr(0,0);
    glTranslatef(.5,-.5,0);
    Cloudsr(0,0);
    glTranslatef(-.5,-.3,0);
    Cloudsr(0,0);
    glTranslatef(-4.5,-.1,0);
    Cloudsr(0,0);
    Origin();
    //plot
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ground_ambient);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.8,-.3);
    glVertex2f(-1.8,-1);
    glVertex2f(2,-1);
    glVertex2f(2,-.3);
    glEnd();
    glDisable(GL_LIGHTING);

    //road
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,road_ambient);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.8,-.7);
    glVertex2f(-1.8,-1);
    glVertex2f(2,-1);
    glVertex2f(2,-.7);
    glEnd();
    glDisable(GL_LIGHTING);

    glColor3ub(255,255,255);
    for(int i=0;i<18;i++){
    glBegin(GL_QUADS);
    glVertex2f(-1.798,-.845);
    glVertex2f(-1.8,-.855);
    glVertex2f(-1.7,-.855);
    glVertex2f(-1.702,-.845);
    glEnd();
    glTranslatef(.25,0,0);
    }

    Origin();


 renderBitmapString(.2,0.89,GLUT_BITMAP_TIMES_ROMAN_24,"RAINY SEASON");
 renderBitmapString(1.5,0.5,GLUT_BITMAP_TIMES_ROMAN_24,"w- winter season");
 renderBitmapString(1.5,0.4,GLUT_BITMAP_TIMES_ROMAN_24,"a- autumn season");
 renderBitmapString(1.5,0.3,GLUT_BITMAP_TIMES_ROMAN_24,"s- summer season");
    //footpath
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,path_ambient);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.8,-.64);
    glVertex2f(-1.8,-.7);
    glVertex2f(2,-.7);
    glVertex2f(2,-.64);
    glEnd();
    glDisable(GL_LIGHTING);

    glColor3f(.3,.3,.3);
    glBegin(GL_QUADS);
    glVertex2f(-1.8,-.7);
    glVertex2f(-1.8,-.715);
    glVertex2f(2,-.715);
    glVertex2f(2,-.7);
    glEnd();

    //grass
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,grass_ambient);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.8,-.54);
    glVertex2f(-1.8,-.64);
    glVertex2f(2,-.64);
    glVertex2f(2,-.54);
    glEnd();
    glDisable(GL_LIGHTING);

    glTranslatef(-.15,.08,0);
    glColor3ub(0,150,136);
    demoBuilding();
    glTranslatef(-.45,-.15,0);
    glScalef(.6,.6,1);
    setColor(255,255,255);
    commercialBuilding();
    Origin();
    glTranslatef(.7,.08,0);
    glColor3ub(204,126,64);
    demoBuilding();
    glTranslatef(.67,-.1,0);
    glScalef(.7,.7,1);
    setColor(248,153,203);
    commercialBuilding();
    Origin();

    glTranslatef(1.55,.08,0);
    glColor3ub(144,52,162);
    demoBuilding();

     glTranslatef(2,.08,0);
    glColor3ub(204,126,64);
    demoBuilding();

    glTranslatef(2.8,.08,0);
    glColor3ub(204,126,64);
    demoBuilding();
    glTranslatef(3.22,.08,0);
    glColor3ub(204,126,64);
    commonBuiliding();
    Origin();

    glTranslatef(2,-.1,0);
    glScalef(.7,.7,1);
    setColor(255,255,255);
    commercialBuilding();
    Origin();
    glTranslatef(3.1,-.1,0);
    glScalef(.7,.7,1);
    setColor(255,255,255);
    commercialBuilding();
    Origin();

    glTranslatef(-1.65,-.4,0);
    glScalef(.3,.3,1);
    grass();
    glTranslatef(1.5,0,0);
    grass();
    glTranslatef(1.5,-.1,0);
    grass();
    glTranslatef(1.4,0,0);
    grass();
    glTranslatef(1.4,0,0);
    grass();
    glTranslatef(1.4,0,0);
    grass();
    glTranslatef(4,0,0);
    grass();
    Origin();

    //front
    building();
    glTranslatef(.42,0,0);
    glColor3ub(0,150,136);
    commonBuiliding();
    glTranslatef(2*.42,0,0);
    glColor3ub(144,52,162);
    commonBuilidingLarge();
    glTranslatef(3*.42,0,0);
    glColor3ub(0,150,136);
    shop();


    school();

    glTranslatef(-1.9,-.07,0);
    float plantX=0;
    plant(0);
    plantX+=.43;
    plant(plantX);
    plantX+=.43;
    plant(plantX);
    plantX+=.4;
    plant(plantX);
    plantX+=.4;
    plant(plantX);
    plantX+=.52;
    plant(plantX);
    plantX+=.42;
    plant(plantX);
    plantX+=.32;
    plant(plantX);
    plantX+=.52;
    plant(plantX);
    plantX+=.32;
    plant(plantX);
    Origin();

    glTranslatef(4*.42,0,0);
    setColor(255,255,255);
    commercialBuilding();
    Origin();
    glTranslatef(.129,.6625,0);
    glScalef(.25,.25,0);
    Watch();
    Origin();
    glScalef(.8,.8,0);
    glTranslatef(5*.455,-.16,0);
    setColor(251,255,171);
    commercialBuilding();
    Origin();
    if(doorOpen){
       glTranslatef(boyPosX+boyPosX2,boyPosY+boyPosY2,0);
       glScalef(.08+schoolBoyScalVal,.08+schoolBoyScalVal,1);
    schoolBoy();
    Origin();
    }
    glTranslatef(peoplePos,-.62,0);
    glScalef(.12,.12,1);
    setColor(88,9,153);
    people();
    glTranslatef(2,0,0);
    setColor(175,99,237);
    people();
    glTranslatef(6,0,0);
    setColor(146,7,9);
    people();

    Origin();

    glTranslatef(peoplePos2,-.62,0);
    glScalef(.12,.12,1);
    setColor(88,9,153);
    people();
    glTranslatef(2,0,0);
    setColor(175,99,237);
    people();
    glTranslatef(6,0,0);
    setColor(146,7,9);
    people();

    Origin();

    glRotatef(180,0,1,0);

    glTranslatef(peoplePos,-.61,0);
    glScalef(.12,.12,1);
    setColor(88,9,153);
    people();
    glTranslatef(2,0,0);
    setColor(175,99,237);
    people();
    glTranslatef(6,0,0);
    setColor(146,7,9);
    people();

    Origin();

    glRotatef(180,0,1,0);
    glTranslatef(peoplePos2,-.61,0);
    glScalef(.12,.12,1);
    setColor(88,9,153);
    people();
    glTranslatef(2,0,0);
    setColor(175,99,237);
    people();
    glTranslatef(6,0,0);
    setColor(146,7,9);
    people();

    Origin();

    glTranslatef(-1.6,0,0);
    for(int i=0;i<5;i++){
    streetLight();
    glTranslatef(.8,0,0);
    }
    Origin();


    glPushMatrix();
    glTranslatef(carPosX1,0,0);
    setColor(137,0,3);
    glTranslatef(0,-.8,0);
    glScalef(.6,.6,1);
    car();
    glTranslatef(.7,0,0);
    setColor(5,25,102);
    car();
    glTranslatef(1,0,0);
    setColor(255,255,255);
    car();
    glTranslatef(.9,0,0);
    setColor(148,148,148);
    car();
    glPopMatrix();
    Origin();

    setColor(5,25,102);
    glPushMatrix();
    glTranslatef(carPosX2,0,0);
    glRotatef(180,0,1,0);
    glTranslatef(0,-.95,0);
    glScalef(.6,.6,1);
    car();
    glTranslatef(.7,0,0);
    setColor(103,0,5);
    car();
    glTranslatef(1,0,0);
    setColor(225,199,99);
    car();
    glTranslatef(.9,0,0);
    setColor(55,255,0);
    car();
    glPopMatrix();
    Origin();


    glPushMatrix();
    glTranslatef(car2PosX1,0,0);
    setColor(137,0,3);
    glTranslatef(0,-.8,0);
    glScalef(.6,.6,1);
    car();
    glTranslatef(.7,0,0);
    setColor(103,0,5);
    car();
    glTranslatef(1,0,0);
    setColor(225,199,99);
    car();
    glTranslatef(.9,0,0);
    setColor(55,255,0);
    car();


    glPopMatrix();
    Origin();

    setColor(5,25,102);
    glPushMatrix();
    glTranslatef(car2PosX2,0,0);
    glRotatef(180,0,1,0);
    glTranslatef(0,-.95,0);
    glScalef(.6,.6,1);
    car();
    glTranslatef(.7,0,0);
    setColor(5,25,102);
    car();
    glTranslatef(1,0,0);
    setColor(255,255,255);
    car();
    glTranslatef(.9,0,0);
    setColor(148,148,148);
    car();
    glPopMatrix();
   Origin();
    myinit();

    temps++;
    if(temps<3)
    {
        for(int i=0;i<2600;i+=15)
        {
            for(int j=0;j<2600;j+=15)
            {
                glPushMatrix();
                glTranslatef(i,-j,0);
                glBegin(GL_LINES);
                glColor3ub(61,98,188);
                glVertex2d(0,598);
                glVertex2d(0,596);
                glEnd();
                glPopMatrix();
            }
        }
    }
    else if(temps>=3 && temps<6)
    {
        for(int i=0;i<2600;i+=15)
        {
            for(int j=5;j<2600;j+=15)
            {
                glPushMatrix();
                glTranslatef(i,-j,0);
                glBegin(GL_LINES);
                glColor3ub(61,98,188);
                glVertex2d(0,598);
                glVertex2d(0,596);
                glEnd();
                glPopMatrix();
            }
        }
    }


    else if(temps>=6 && temps<9)
    {
        for(int i=5;i<2600;i+=15)
        {
            for(int j=10;j<2600;j+=15)
            {
                glPushMatrix();
                glTranslatef(i,-j,0);
                glBegin(GL_LINES);
              glColor3ub(61,98,188);
                glVertex2d(0,598);
                glVertex2d(0,596);
                glEnd();
                glPopMatrix();
            }
        }
    }
    else
        temps=0;

     anim();

     glFlush();
}
//Function for autumn season
void autumn()
{
init();
    glClear(GL_COLOR_BUFFER_BIT);
    Origin();

    glColor3f(1.0f,1.0f,0.5f);

    //sky
    glColor3ub(255,140,0);
    glBegin(GL_QUADS);
    glVertex2f(2,1);
    glVertex2f(-1.8,1);
    glColor3ub(196,196,196);
    glVertex2f(-1.8,-.3);
    glVertex2f(2,-.3);
    glEnd();
    glColor3ub(232,72,22);
    glColor3ub(255,170,100);
    glPushMatrix();
    glTranslatef(sunPosX,sunPosY,0);
    sun();
    glPopMatrix();
    Origin();
    if(planePos>=-2){
        glRotatef(5,0,0,1);
    }
    if(planePos>=2.5){
        glRotatef(0,0,0,1);
    }
    glTranslatef(planePos,1,0);
    glScalef(.3,.3,1);
    Origin();


    glTranslatef(-.5,.5,0);
    glScalef(.6+cloudScalVal,.6+cloudScalVal,1);
    Cloudsa(0,0);
    glTranslatef(-1,.2,0);
    Cloudsa(0,0);
    glTranslatef(-1,.2,0);
    Cloudsa(.2,0);
    glTranslatef(2.7,0,0);
    Cloudsa(0,0);
    glTranslatef(1,-.1,0);
    Cloudsa(0,0);
    glTranslatef(1,-.1,0);
    Cloudsa(0,0);
    glTranslatef(.5,.3,0);
    Cloudsa(0,0);
    glTranslatef(.5,-.5,0);
    Cloudsa(0,0);
    glTranslatef(-.5,-.3,0);
    Cloudsa(0,0);
    glTranslatef(-4.5,-.1,0);
    Cloudsa(0,0);
    Origin();
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ground_ambient);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.8,-.3);
    glVertex2f(-1.8,-1);
    glVertex2f(2,-1);
    glVertex2f(2,-.3);
    glEnd();
    glDisable(GL_LIGHTING);

    //road
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,road_ambient);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.8,-.7);
    glVertex2f(-1.8,-1);
    glVertex2f(2,-1);
    glVertex2f(2,-.7);
    glEnd();
    glDisable(GL_LIGHTING);

    glColor3ub(255,255,255);
    for(int i=0;i<18;i++){
    glBegin(GL_QUADS);
    glVertex2f(-1.798,-.845);
    glVertex2f(-1.8,-.855);
    glVertex2f(-1.7,-.855);
    glVertex2f(-1.702,-.845);
    glEnd();
    glTranslatef(.25,0,0);
    }
    Origin();



    //footpath
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,path_ambient);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.8,-.64);
    glVertex2f(-1.8,-.7);
    glVertex2f(2,-.7);
    glVertex2f(2,-.64);
    glEnd();
    glDisable(GL_LIGHTING);

    glColor3f(.3,.3,.3);
    glBegin(GL_QUADS);
    glVertex2f(-1.8,-.7);
    glVertex2f(-1.8,-.715);
    glVertex2f(2,-.715);
    glVertex2f(2,-.7);
    glEnd();

    //grass
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,grass_ambient);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-1.8,-.54);
    glVertex2f(-1.8,-.64);
    glVertex2f(2,-.64);
    glVertex2f(2,-.54);
    glEnd();
    glDisable(GL_LIGHTING);

    glTranslatef(-.15,.08,0);
    glColor3ub(0,150,136);
    demoBuilding();
    glTranslatef(-.45,-.15,0);
    glScalef(.6,.6,1);
    setColor(255,255,255);
    commercialBuilding();
    Origin();
    glTranslatef(.7,.08,0);
    glColor3ub(204,126,64);
    demoBuilding();
    glTranslatef(.67,-.1,0);
    glScalef(.7,.7,1);
    setColor(248,153,203);
    commercialBuilding();
    Origin();

    glTranslatef(1.55,.08,0);
    glColor3ub(144,52,162);
    demoBuilding();

    glTranslatef(2,.08,0);
    glColor3ub(204,126,64);
    demoBuilding();

    glTranslatef(2.8,.08,0);
    glColor3ub(204,126,64);
    demoBuilding();
    glTranslatef(3.22,.08,0);
    glColor3ub(204,126,64);
    commonBuiliding();
    Origin();

    glTranslatef(2,-.1,0);
    glScalef(.7,.7,1);
    setColor(255,255,255);
    commercialBuilding();
    Origin();
    glTranslatef(3.1,-.1,0);
    glScalef(.7,.7,1);
    setColor(255,255,255);
    commercialBuilding();
    Origin();

    glTranslatef(-1.65,-.4,0);
    glScalef(.3,.3,1);
    grass();
    glTranslatef(1.5,0,0);
    grass();
    glTranslatef(1.5,-.1,0);
    grass();
    glTranslatef(1.4,0,0);
    grass();
    glTranslatef(1.4,0,0);
    grass();
    glTranslatef(1.4,0,0);
    grass();
    glTranslatef(4,0,0);
    grass();
    Origin();

 renderBitmapString(.2,0.89,GLUT_BITMAP_TIMES_ROMAN_24,"AUTUMN SEASON");
 renderBitmapString(1.5,0.5,GLUT_BITMAP_TIMES_ROMAN_24,"w- winter season");
 renderBitmapString(1.5,0.4,GLUT_BITMAP_TIMES_ROMAN_24,"s- summer season");
 renderBitmapString(1.5,0.3,GLUT_BITMAP_TIMES_ROMAN_24,"r- rainy season");
    //front
    building();
    glTranslatef(.42,0,0);
    glColor3ub(0,150,136);
    commonBuiliding();
    glTranslatef(2*.42,0,0);
    glColor3ub(144,52,162);
    commonBuilidingLarge();
    glTranslatef(3*.42,0,0);
    glColor3ub(0,150,136);
    shop();


    school();

    glTranslatef(-1.9,-.07,0);
    float plantX=0;
    planta(0);
    plantX+=.43;
    planta(plantX);
    plantX+=.43;
    planta(plantX);
    plantX+=.4;
    planta(plantX);
    plantX+=.4;
    planta(plantX);
    plantX+=.52;
    planta(plantX);
    plantX+=.42;
    planta(plantX);
    plantX+=.32;
    planta(plantX);
    plantX+=.52;
    planta(plantX);
    plantX+=.32;
    planta(plantX);
    Origin();

    glTranslatef(4*.42,0,0);
    setColor(255,255,255);
    commercialBuilding();
    Origin();
    glTranslatef(.129,.6625,0);
    glScalef(.25,.25,0);
    Watch();
    Origin();
    glScalef(.8,.8,0);
    glTranslatef(5*.455,-.16,0);
    setColor(251,255,171);
    commercialBuilding();
    Origin();
    if(doorOpen){
    glTranslatef(boyPosX+boyPosX2,boyPosY+boyPosY2,0);
    glScalef(.08+schoolBoyScalVal,.08+schoolBoyScalVal,1);
    schoolBoy();
    Origin();
    }
    glTranslatef(peoplePos,-.62,0);
    glScalef(.12,.12,1);
    setColor(88,9,153);
    people();
    glTranslatef(2,0,0);
    setColor(175,99,237);
    people();
    glTranslatef(6,0,0);
    setColor(146,7,9);
    people();

    Origin();
    glTranslatef(peoplePos2,-.62,0);
    glScalef(.12,.12,1);
    setColor(88,9,153);
    people();
    glTranslatef(2,0,0);
    setColor(175,99,237);
    people();
    glTranslatef(6,0,0);
    setColor(146,7,9);
    people();

    Origin();

    glRotatef(180,0,1,0);

    glTranslatef(peoplePos,-.61,0);
    glScalef(.12,.12,1);
    setColor(88,9,153);
    people();
    glTranslatef(2,0,0);
    setColor(175,99,237);
    people();
    glTranslatef(6,0,0);
    setColor(146,7,9);
    people();

    Origin();

    glRotatef(180,0,1,0);
    glTranslatef(peoplePos2,-.61,0);
    glScalef(.12,.12,1);
    setColor(88,9,153);
    people();
    glTranslatef(2,0,0);
    setColor(175,99,237);
    people();
    glTranslatef(6,0,0);
    setColor(146,7,9);
    people();

    Origin();

    glTranslatef(-1.6,0,0);
    for(int i=0;i<5;i++){
       streetLight();
       glTranslatef(.8,0,0);
    }
    Origin();

    glPushMatrix();
    glTranslatef(carPosX1,0,0);
    setColor(137,0,3);
    glTranslatef(0,-.8,0);
    glScalef(.6,.6,1);
    car();
    glTranslatef(.7,0,0);
    setColor(5,25,102);
    car();
    glTranslatef(1,0,0);
    setColor(255,255,255);
    car();
    glTranslatef(.9,0,0);
    setColor(148,148,148);
    car();
    glPopMatrix();
    Origin();

    setColor(5,25,102);
    glPushMatrix();
    glTranslatef(carPosX2,0,0);
    glRotatef(180,0,1,0);
    glTranslatef(0,-.95,0);
    glScalef(.6,.6,1);
    car();
    glTranslatef(.7,0,0);
    setColor(103,0,5);
    car();
    glTranslatef(1,0,0);
    setColor(225,199,99);
    car();
    glTranslatef(.9,0,0);
    setColor(55,255,0);
    car();
    glPopMatrix();
    Origin();


    glPushMatrix();
    glTranslatef(car2PosX1,0,0);
    setColor(137,0,3);
    glTranslatef(0,-.8,0);
    glScalef(.6,.6,1);
    car();
    glTranslatef(.7,0,0);
    setColor(103,0,5);
    car();
    glTranslatef(1,0,0);
    setColor(225,199,99);
    car();
    glTranslatef(.9,0,0);
    setColor(55,255,0);
    car();


    glPopMatrix();
    Origin();

    setColor(5,25,102);
    glPushMatrix();
    glTranslatef(car2PosX2,0,0);
    glRotatef(180,0,1,0);
    glTranslatef(0,-.95,0);
    glScalef(.6,.6,1);
    car();
    glTranslatef(.7,0,0);
    setColor(5,25,102);
    car();
    glTranslatef(1,0,0);
    setColor(255,255,255);
    car();
    glTranslatef(.9,0,0);
    setColor(148,148,148);
    car();
    glPopMatrix();
    Origin();
	anim();
    glFlush();
}
void idle(int val){


glutPostRedisplay();
glutTimerFunc(100,idle,0);
}
//Function for key press
void keys(unsigned char key,int x,int y)
{
    if(key=='s')
    {
        glutDisplayFunc(summer);
    }
    glutPostRedisplay();

    if(key=='w')
    {
        glutDisplayFunc(winter);
    }
    glutPostRedisplay();

    if(key=='a')
    {
        glutDisplayFunc(autumn);
    }
    glutPostRedisplay();

    if(key=='r')
    {
        glutDisplayFunc(rain);
    }
    glutPostRedisplay();
}
//Function for animation
void anim()
{
           glutTimerFunc(10,clockAnim,0);
            glutTimerFunc(10,legAnim,0);
	        glutTimerFunc(10,cloudAnim,0);
	        glutTimerFunc(10,carAnim,0);
	        glutTimerFunc(10,peopleAnim,0);

}
int main(int argc,char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1920, 1080);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Season simulation");
	glutKeyboardFunc(keys);
	glutDisplayFunc(welcomeDisplay);
	init();
	glutTimerFunc(100,idle,0);
	glutMainLoop();
	return 0;
}

