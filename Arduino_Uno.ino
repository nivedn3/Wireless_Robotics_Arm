#include<SoftwareSerial.h>
#include<Servo.h>
SoftwareSerial uno(10,11);
Servo n[5];
int range[5];
int i;
void setup()
{
//pins for attaching the servos
  n[0].attach(3);
  n[1].attach(5);
  n[2].attach(6);
  n[3].attach(9);
  n[4].attach(10);
  uno.begin(9600);
}
void loop()
{
  if(uno.available()>0)
  {
    for(i=0;i<=4;i++)
    {
//reads the series data send by Arduino Lilypad and moves the servos accordingly.
      range[i]=uno.read();
      n[i].write(range[i]);
    }
  }
}

  
  
