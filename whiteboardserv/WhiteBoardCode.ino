#include <Arduino.h>
#include <Servo.h> 
#include <math.h> 

Servo servo1;
Servo servo2;
Servo servoz;
double store1=0;
double store2=0;
double lengthEach = 10.7; //inches
double const pi = 3.14159;
char val = ' ';
int pos = 0;
char hangWord[10];
void setup() {
  // put your setup code here, to run once:
  servo1.attach(9);
  servo2.attach(10);
  servoz.attach(11);
  servoz.write(90);
  servo1.write(0);
  servo2.write(0);
  delay(3000);

  
  Serial.begin(9600);  
}

void loop() {
    
  if (Serial.available() > 0) {
    // read the incoming byte:
    char incomingByte = Serial.read();
    if (incomingByte=='1')
    {
      drawUSC();
      delay(5000);
    }
    else if (incomingByte=='2')
    {
      drawUCLA();
      delay(5000);
    }
    else if (incomingByte=='3')
    {
      char randomFig=random(1,2);
      if (randomFig==2)
      {
        drawHouse();
        delay(5000);
      }
      else
      {
        drawMtns();
        delay(5000);
      }
    }
  }
}

void ognrotations(double x, double y,double L) {
  //servoz.write(60);
   double final1 = 9.0/8*(180 - (180.0/pi * 2*asin(pow(x*x + y*y,.5)/(2*10.5))));
   double final2 = (9.0/8*(180.0/pi * (atan(y/x)+acos(pow((x*x+y*y),.5) /2/10.5))));
  servo1.write(final2);
  servo2.write(final1);
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

void drawUSC() {
  //Draw "U"
   servoz.write(90);
   delay(300);
   ognrotations(10,7,10.5);
   delay(300);
   ognrotations(5,5,10.5);
   servoz.write(0);
   for(double i = 5; i >= 2; i-=0.5) {
    ognrotations(5, i, 10.5);
    delay(200);
  }
  delay(300);
  ognrotations(5,2, 10.5);
  
  for(double i = 5; i <= 8; i+=0.5) {
    ognrotations(i, 2-i/3, 10.5);
    delay(200);
  }
  
    
  delay(300);
  ognrotations(8,3,10.5);

  for(double i = 3;i <= 7; i+=0.5) {
      ognrotations(8,i,10.5);
      delay(200);
  }
  
  servoz.write(90);
  
  delay(500);
  ognrotations(13,5,10.5);
  servoz.write(0);
   
   //"S"
   for(double i = 13; i >= 9; i-=0.5) {
    ognrotations(i, 5+i/5, 10.5);
    delay(200);
  }
  
  delay(500);
  ognrotations(9,5,10.5);
  
  for(double i = 5; i >= 2; i-=0.5) {
    ognrotations(9, i, 10.5);
    delay(200);
  }
  
  delay(500);
  ognrotations(10,3,10.5);
  
  for(double i = 10; i <= 13; i+=0.5) {
    ognrotations(i, 4-i/4 , 10.5);
    delay(200);
  }
  
  delay(500);
  //ognrotations(13,4,10.5);
  
  
  for(double i = 5; i >= 1; i-=0.5) {
    ognrotations(13, i, 10.5);
    delay(200);
  }
  
  delay(500);
  
  double j = 2;
  for(double i = 5; i >= 1; i-=0.5) {
      ognrotations(13,j-=0.5,10.5);
      delay(200);
  }
  
  delay(500);
  ognrotations(14, 1, 10.5);
  
  for(double i = 14; i >= 9; i-=0.5) {
    ognrotations(i, 0, 10.5);
   delay(200);
  }
  
  //"C"
  servoz.write(90);
  delay(500);
  ognrotations(17,5,10.5);
  delay(200);
  servoz.write(0);
  delay(200);
  
  for(double i = 17; i >= 14; i-=0.5) {
    ognrotations(i, 5+i/3,10.5);
    delay(200);
  }
  
  delay(500);
  ognrotations(14,5,10.5);
  
  double k = 4;
  for(double i = 9; i >= 1; i -=0.5) {
    ognrotations(14,k-=0.5,10.5);
    delay(200);
  }
  
  delay(500);
  ognrotations(14,0,10.5);
  
  for(double i = 14; i <= 19; i +=0.5) {
    ognrotations(i, 0-i/4,10.5);
    delay(200);
  }
  
  
  
  delay(300);  
  servoz.write(90);
  
  
  delay(3000);
}

void drawUCLA() {
  
  delay(100);
  
  servoz.write(90);
  delay(600);
  ognrotations(4,6,10.5);
  servoz.write(0);
  delay(600);
  for(int i=0;i<6;i++)//U
  {
    ognrotations(3,5-.5*i,10.5);
    delay(100);
  }
  for(int i=0;i<6;i++)//U
  {
    ognrotations(3+.5*i,2,10.5);
    delay(100);
  }
  for(int i=0;i<6;i++)//U
  {
    ognrotations(6,2+.5*i,10.5);
    delay(100);
  }
  servoz.write(90);
  delay(600);
  ognrotations(9,4.5,10.5);
  servoz.write(0);
  delay(600);
  for(int i=3;i<6;i++)//C
  {
    ognrotations(9,3+.5*i,10.5);
    delay(100);
  }
  for(int i=0;i<6;i++)//C
  {
    ognrotations(3+1.2*i,6,10.5);
    delay(100);
  }

  servoz.write(90);
  delay(600);
  ognrotations(12,6,10.5);
  servoz.write(0);
  delay(600);
  for(int i=0;i<6;i++)//L
  {
    ognrotations(12,6-.5*i,10.5);
    delay(100);
  }
  for(int i=0;i<6;i++)//L
  {
    ognrotations(12+.5*i,3,10.5);
    delay(100);
  }
   servoz.write(90);
  delay(600);
  ognrotations(16,3,10.5);
  servoz.write(0);
  delay(600);
  for(int i=0;i<6;i++)//A
  {
    ognrotations(16+.25*i,3+.5*i,10.5);
    delay(100);
  }
  for(int i=0;i<6;i++)//A
  {
    ognrotations(17.5+.25*i,6-.5*i,10.5);
    delay(100);
  }
  for(int i=0;i<10;i++)//A
  {
    ognrotations(14.5+.25*i,6,10.5);
    delay(100);
  }
     servoz.write(90);
  delay(600);
  ognrotations(13,10,10.5);
  servoz.write(0);
  delay(600);
  for(int i=12;i>3;i--)//A
  {
    ognrotations(8,i,10.5);
    delay(100);
  }
  ognrotations(7,9.5,10.5);
  delay(100);
  ognrotations(15,5.5,10.5);
  delay(100);
  
  
}


void drawMtns() {
  
  servoz.write(90);
   delay(300);
   ognrotations(10,7,10.5);
   delay(300);
   ognrotations(4,5,10.5);
   servoz.write(0);
   
   for(double i = 4; i < 10; i+=0.5) {
       ognrotations(i,5,10.5);
       delay(200);
   }
   
   delay(500);
   ognrotations(10,7,10.5);
   
   for(double i = 7; i > 2; i-=0.5) {
     ognrotations(17-i,i,10.5);
     delay(200);
   }
   
   delay(500);
   ognrotations(13,7,10.5);
   
   
    for(double i = 13; i < 17; i+=0.5) {
       ognrotations(i,7,10.5);
       delay(200);
   }
   
   for(double i = 7; i > 2; i-=0.5) {
     ognrotations(24-i,i,10.5);
     delay(200);
   }
   
   servoz.write(90);
   delay(500);
   ognrotations(4,9,10.5);
   delay(300);
   servoz.write(0);
   delay(500);
   
   //Second Loop
   
   for(double i = 4; i < 10; i+=0.5) {
       ognrotations(i,9,10.5);
       delay(200);
   }
   
   delay(500);
   ognrotations(10,9,10.5);
   
   for(double i = 9; i > 5; i-=0.5) {
     ognrotations(17-i,i,10.5);
     delay(200);
   }
   
   delay(500);
   ognrotations(13,9,10.5);
   
   
    for(double i = 13; i < 17; i+=0.5) {
       ognrotations(i,9,10.5);
       delay(200);
   }
   
   delay(500);
   ognrotations(17,9,10.5);
   
   for(double i = 7; i > 2; i-=0.5) {
     ognrotations(24-i,i,10.5);
     delay(200);
   }
   
   
  delay(300);  
  servoz.write(90);
  
  
  delay(3000);
   
}

void drawHouse() {
  
  servoz.write(90);
   delay(300);
   ognrotations(10,7,10.5);
   delay(300);
   ognrotations(5,7,10.5);
   servoz.write(0);
   
  for(double i = 7; i >= 2; i-=0.5) {
    ognrotations(5, i, 10.5);
    delay(200);
  }
  
  delay(500);
  ognrotations(5,4,10.5);
  
  for(double i = 5; i <= 11; i+=0.5) {
    ognrotations(i, 4-i/3, 10.5);
    delay(200);
  }
  
    
  delay(300);
  ognrotations(11,4,10.5);

  for(double i = 4;i <= 10; i+=0.5) {
      ognrotations(11,i,10.5);
      delay(200);
  }
  
  delay(300);
  ognrotations(11,5,10.5);
  
  for(double i = 11; i >= 5; i-=0.5) {
    ognrotations(i, 5+i/3, 10.5);
    delay(200);
  }
  
  delay(300);
  ognrotations(5,9,10.5);
  
  for(double i = 5; i < 10; i+=0.5) {
       ognrotations(i,9,10.5);
       delay(200);
   }
   
   delay(500);
   ognrotations(10,9,10.5);
   
   for(double i = 9; i > 6; i-=0.5) {
     ognrotations(17-i,i,10.5);
     delay(200);
   }
   
   delay(500);
   ognrotations(13,7,10.5);
  
  for(double i = 7; i <= 13; i+=0.5) {
    ognrotations(13, i, 10.5);
    delay(200);
  }
  
  delay(500);
  ognrotations(13,13,10.5);
  for(double i =13; i < 16; i+= 0.5) {
    ognrotations(i, 13-i/4, 10.5);
    delay(200);
  }
  
  delay(500);
  ognrotations(13,13,10.5);
  
  for(double i = 13; i >= 4; i-=0.5) {
      ognrotations(13,i,10.5);
      delay(200);
  }
  
  delay(300);  
  servoz.write(90);
  
  
  delay(3000);
  
  
}

