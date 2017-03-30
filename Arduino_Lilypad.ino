#include<SoftwareSerial.h>
SoftwareSerial lilypad(10,11);
int flex[5];
int flexpin[5]={A0,A1,A2,A3,A4};
int servorange[5];
int i;
void setup()
{
  lilypad.begin(9600);
}
void loop()
{
 for(i=0;i<=4;i++)
 {
   flex[i]=analogRead(flexpin[i]);
//range of flex sensor to be caliberated
   servorange[i]=map(flex[i],_,_,0,180);
   constrain(servorange[i],0,180);
   lilypad.println(servorange[i]);
 }
} 
  
  
