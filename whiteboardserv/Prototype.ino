#include <Arduino.h>
#include <Servo.h> 
#include <math.h> 

Servo servo1;
Servo servo2;
Servo servoz;
double store1=0;
double store2=0;
double lengthEach = 12; //inches
double const pi = 3.14159;
char val = ' ';
int pos = 0;
void setup() {
  // put your setup code here, to run once:
  servo1.attach(11);
  servo2.attach(10);
  servoz.attach(9);
  //Serial.begin(9600);  
}

void loop() {
  /*if( Serial.available() )       // if data is available to read
  {
    val = Serial.read();         // read it and store it in 'val'
  }
  if( val == 'q'||val=='r' )               // if 'H' was received
  {
    servo1.write(65);  // turn ON the LED
  }
  else if (val = 'w'||val=='t') { 
    servo1.write(23);   // otherwise turn it OFF
  }
  else if (val = 'e'||val=='y'){
    servo1.write(123);
  }*/
  /*delay(100); 
  servo1.write(180);
  servo2.write(180);*/
    // wait 100ms for next reading
  // put your main code here, to run repeatedly:
  /*int pos = 0;
  servo1.write(180);
  delay(360);
  servo1.write(0);
  delay(360);*/
  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    servo1.write(pos);    
    servo2.write(pos);    // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
  /*for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    servo2.write(pos);  
    servo1.write(pos);    // tell servo to go to position in variable 'pos' 
    delay(15); 
  }*/
  //linecreate(2,8,2,2,10);
  //ellipsecreate(2,2,2,8,10,10,5);
  //delay(5000);
  //ognrotations(2,0,10);
  //ognrotations(2,8,10);
  //drawellipse(7,7,5,5,10,0,360);
  //delay(5000);
  //servo1.write(180);
  //servo2.write(180);
}

void checkcoordinate(double x, double y,double L) {
  if (sqrt(x*x+y*y)<2L)
  {
  }
  else
  {
    movecoordinate(x);
  }
}

void ognrotations(double x, double y,double L) {
  //servoz.write(15);
  double theta1 = acos(sqrt(x*x+y*y)/2/L)*180/pi;
  double theta2 = atan(y/x)*180/pi;
  double final1 = 180 - 2*theta1;
  double final2= 180-theta1-theta2;
  //delay(25);
  //servo1.write(final1);
  //servo2.write(final2);
  servo1.write(final1);
  servo2.write(final2);
  if (abs(store1-final1)>abs(store2-final2))
  {
    delay(abs(store1-final1)*8);
  } 
  else
  {
    delay(abs(store2-final2)*8);
  }
  //servoz.write(0);
  store1 = final1;
  store2 = final2;
}

void linecreate(double x1, double y1, double x2, double y2, double L) {
  //servoz.write(5);
  //delay(15);
  ognrotations(x1,y1,L);
  //servoz.write(0);
  //delay(15);
  ognrotations(x2,y2,L);
}
/*
void ellipsecreate(double x1, double y1, double x2, double y2, double L, double pointx, double pointy)
{
  servoz.write(5);
  delay(15);
  double midx = (x1+x2)/2;
  double midy = (y1+y2)/2;
  double elength = sqrt((x1-midx)*(x1-midx)+(y1-midy)*(y1-midy));
  double ewidth = sqrt((pointx-midx)*(pointx-midx)+(pointy-midy)*(pointy-midy));
  double slope = (y1-midy)/(x1-midx);
  double angle = atan(slope);
  double cosang = cos(angle);
  double sinang = sin(angle);
  ognrotations(x1,y1,L);
  servoz.write(0);
  delay(15);
  for (double theta = 0; theta <= pi; theta+=pi/10)
  {
    double Xout=elength*cos(theta)*cosang-ewidth*sin(theta)*sinang+midx;
    double Yout=elength*cos(theta)*sinang-ewidth*sin(theta)*cosang+midy;
    ognrotations(Xout,Yout,L);
  }
  
}
*/
void movecoordinate(double x)
{
  //moveforward/backwards
}
void drawellipse(double centerx,double centery,double width,double height,double L,double degreestart,double degreeend)
{
  for (double i=degreestart;i<=degreeend;i=i+3)
  {
    double xout = centerx+.5*width*cos(i*pi/180);
    double yout = centery-.5*height*sin(i*pi/180);
    ognrotations(xout,yout,L);
  }
}

void writeletter(char letter, double centerX, double centerY, double fontX, double fontY)
{
  if (letter=='A')
  {
    linecreate((centerX-.5*fontX),(centerY-.5*fontY),centerX,(centerY+.5*fontY),lengthEach);
    linecreate(centerX,(centerY+.5*fontY),(centerX+.5*fontX),(centerY-.5*fontY),lengthEach);
    linecreate((centerX-.25*fontX),centerY,(centerX+.25*fontX),centerY,lengthEach);
  }
  else if (letter=='B')
  {
    linecreate((centerX-.5*fontX),(centerY-.5*fontY),(centerX-.5*fontX),(centerY+.5*fontY),lengthEach);
    drawellipse((centerX-.5*fontX),(centerY+.25*fontY),(2*fontX),(.5*fontY),lengthEach,-90,90);
    drawellipse((centerX-.5*fontX),(centerY-.25*fontY),(2*fontX),(.5*fontY),lengthEach,-90,90);    
  }
  else if (letter=='C')
  {
    drawellipse((centerX+.5*fontX),centerY,(2*fontX),fontY,lengthEach,90,270);
  }
  else if (letter=='D')
  {
    linecreate((centerX-.5*fontX),(centerY-.5*fontY),(centerX-.5*fontX),(centerY+.5*fontY),lengthEach);
    drawellipse((centerX-.5*fontX),centerY,(2*fontX),fontY,lengthEach,-90,90);
  }
  else if (letter=='E')
  {
    linecreate((centerX-.5*fontX),(centerY-.5*fontY),(centerX-.5*fontX),(centerY+.5*fontY),lengthEach);
    linecreate((centerX-.5*fontX),(centerY-.5*fontY),(centerX+.5*fontX),(centerY-.5*fontY),lengthEach);
    linecreate((centerX-.5*fontX),centerY,(centerX+.5*fontX),centerY,lengthEach);
    linecreate((centerX-.5*fontX),(centerY+.5*fontY),(centerX+.5*fontX),(centerY+.5*fontY),lengthEach);
  }
  else if (letter=='F')
  {
    linecreate((centerX-.5*fontX),(centerY-.5*fontY),(centerX-.5*fontX),(centerY+.5*fontY),lengthEach);
    linecreate((centerX-.5*fontX),centerY,(centerX+.5*fontX),centerY,lengthEach);
    linecreate((centerX-.5*fontX),(centerY+.5*fontY),(centerX+.5*fontX),(centerY+.5*fontY),lengthEach);
  }
  else if (letter=='G')
  {
    drawellipse((centerX-.1*fontX),centerY,(.8*fontX),fontY,lengthEach,90,360);
    linecreate(centerX,centerY,(centerX+.5*fontX),centerY,lengthEach);
    linecreate((centerX-.3*fontX),(centerY-.5*fontY),(centerX-.3*fontX),centerY,lengthEach);
  }
  else if (letter=='H')
  {
    linecreate((centerX-.5*fontX),(centerY-.5*fontY),(centerX-.5*fontX),(centerY+.5*fontY),lengthEach);
    linecreate((centerX+.5*fontX),(centerY-.5*fontY),(centerX+.5*fontX),(centerY+.5*fontY),lengthEach);
    linecreate((centerX-.5*fontX),centerY,(centerX+.5*fontX),centerY,lengthEach);
  }
  else if (letter=='I')
  {
    linecreate(centerX,(centerY-.5*fontY),centerX,(centerY+.5*fontY),lengthEach);
    linecreate((centerX-.5*fontX),(centerY-.5*fontY),(centerX+.5*fontX),(centerY-.5*fontY),lengthEach);
    linecreate((centerX-.5*fontX),(centerY+.5*fontY),(centerX+.5*fontX),(centerY+.5*fontY),lengthEach);
  }
  else if (letter=='J')
  {
    linecreate(centerX,(centerY-.25*fontY),centerX,(centerY+.5*fontY),lengthEach);
    linecreate((centerX-.5*fontX),(centerY+.5*fontY),(centerX+.5*fontX),(centerY+.5*fontY),lengthEach);
    drawellipse((centerX-.25*fontX),(centerY+.25*fontY),(.5*fontX),(.5*fontY),lengthEach,180,360);
  }
  else if (letter=='K')
  {
    linecreate((centerX-.5*fontX),(centerY-.5*fontY),(centerX-.5*fontX),(centerY+.5*fontY),lengthEach);
    linecreate((centerX-.5*fontX),centerY,(centerX+.5*fontX),(centerY-.5*fontY),lengthEach);
    linecreate((centerX-.5*fontX),centerY,(centerX+.5*fontX),(centerY+.5*fontY),lengthEach);
  }
  else if (letter=='L')
  {   
    linecreate((centerX-.5*fontX),(centerY-.5*fontY),(centerX-.5*fontX),(centerY+.5*fontY),lengthEach);
    linecreate((centerX-.5*fontX),(centerY-.5*fontY),(centerX+.5*fontX),(centerY-.5*fontY),lengthEach);
  }
  else if (letter=='M')
  {
    linecreate((centerX-.5*fontX),(centerY-.5*fontY),(centerX-.5*fontX),(centerY+.5*fontY),lengthEach);
    linecreate((centerX-.5*fontX),(centerY+.5*fontY),centerX,centerY,lengthEach);
    linecreate(centerX,centerY,(centerX+.5*fontX),(centerY+.5*fontY),lengthEach);
    linecreate((centerX+.5*fontX),(centerY+.5*fontY),(centerX+.5*fontX),(centerY-.5*fontY),lengthEach);
  }
  else if (letter=='N')
  {
    linecreate((centerX-.5*fontX),(centerY-.5*fontY),(centerX-.5*fontX),(centerY+.5*fontY),lengthEach);
    linecreate((centerX-.5*fontX),(centerY+.5*fontY),(centerX+.5*fontX),(centerY-.5*fontY),lengthEach);
    linecreate((centerX+.5*fontX),(centerY-.5*fontY),(centerX+.5*fontX),(centerY+.5*fontY),lengthEach);
  }
  else if (letter=='O')
  {
    drawellipse(centerX,centerY,fontX,fontY,lengthEach,0,360);
  }
  else if (letter=='P')
  {
    linecreate((centerX-.5*fontX),(centerY-.5*fontY),(centerX-.5*fontX),(centerY+.5*fontY),lengthEach);
    drawellipse((centerX-.5*fontX),(centerY+.25*fontY),(2*fontX),(.5*fontY),lengthEach,-90,90);
  }
  else if (letter=='Q')
  {
    drawellipse(centerX,centerY,fontX,fontY,lengthEach,0,360);
    linecreate(centerX,(centerY-.1*fontY),(centerX+.5*fontX),(centerY-.5*fontY),lengthEach);
  }
  else if (letter=='R')
  {
    linecreate((centerX-.5*fontX),(centerY-.5*fontY),(centerX-.5*fontX),(centerY+.5*fontY),lengthEach);
    drawellipse((centerX-.5*fontX),(centerY+.25*fontY),(2*fontX),(.5*fontY),lengthEach,-90,90);
    linecreate(centerX,centerY,(centerX+.5*fontX),(centerY-.5*fontY),lengthEach);
  }
  else if (letter=='S')
  {
    drawellipse(centerX,(centerY+.25*fontY),fontX,(.5*fontY),lengthEach,70,270);
    drawellipse(centerX,(centerY-.25*fontY),fontX,(.5*fontY),lengthEach,-110,90);
  }
  else if (letter=='T')
  {
    linecreate(centerX,(centerY-.5*fontY),centerX,(centerY+.5*fontY),lengthEach);
    linecreate((centerX-.5*fontX),(centerY+.5*fontY),(centerX+.5*fontX),(centerY+.5*fontY),lengthEach);
  }
  else if (letter=='U')
  {
    linecreate((centerX-.5*fontX),(centerY+.5*fontY),(centerX-.5*fontX),centerY,lengthEach);
    drawellipse(centerX,centerY,fontX,fontY,lengthEach,180,360);
    linecreate((centerX+.5*fontX),centerY,(centerX+.5*fontX),(centerY+.5*fontY),lengthEach);
  }
  else if (letter=='V')
  {
    linecreate((centerX-.5*fontX),(centerY+.5*fontY),centerX,(centerY-.5*fontY),lengthEach);
    linecreate(centerX,(centerY-.5*fontY),(centerX+.5*fontX),(centerY+.5*fontY),lengthEach);
  }
  else if (letter=='W')
  {
    linecreate((centerX-.5*fontX),(centerY+.5*fontY),(centerX-.25*fontX),(centerY-.5*fontY),lengthEach);
    linecreate((centerX-.25*fontX),(centerY-.5*fontY),centerX,(centerY+.5*fontY),lengthEach);
    linecreate(centerX,(centerY+.5*fontY),(centerX+.25*fontX),(centerY-.5*fontY),lengthEach);
    linecreate((centerX+.25*fontX),(centerY-.5*fontY),(centerX+.5*fontX),(centerY+.5*fontY),lengthEach);
  }
  else if (letter=='X')
  {
    linecreate((centerX-.5*fontX),(centerY-.5*fontY),(centerX+.5*fontX),(centerY+.5*fontY),lengthEach);
    linecreate((centerX+.5*fontX),(centerY-.5*fontY),(centerX+.5*fontX),(centerY+.5*fontY),lengthEach);
  }
  else if (letter=='Y')
  {
    linecreate((centerX-.5*fontX),(centerY+.5*fontY),centerX,centerY,lengthEach);
    linecreate(centerX,centerY,(centerX+.5*fontX),(centerY+.5*fontY),lengthEach);
    linecreate(centerX,centerY,centerX,(centerY-.5*fontY),lengthEach);
  }
  else if (letter=='Z')
  {
    linecreate((centerX-.5*fontX),(centerY+.5*fontY),(centerX+.5*fontX),(centerY+.5*fontY),lengthEach);
    linecreate((centerX+.5*fontX),(centerY+.5*fontY),(centerX-.5*fontX),(centerY-.5*fontY),lengthEach);
    linecreate((centerX-.5*fontX),(centerY-.5*fontY),(centerX+.5*fontX),(centerY-.5*fontY),lengthEach);
  }
}

