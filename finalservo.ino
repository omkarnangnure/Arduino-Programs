#include<Servo.h>   

Servo sg90; 
int servo_pin = 11;
int angle=0;
void setup() 
{
  // put your setup code here, to run once
  sg90.attach ( servo_pin );
  pinMode(6,INPUT);
sg90.write(180);
Serial.begin(9600); 
}
void loop() 
{
  // put your main code here, to run repeatedly:
 
  for(digitalRead(6)==HIGH; ; )
  {
    Serial.print("1\n");
    sg90.write(0);
    delay(3000);
    sg90.write(180);
    delay(1000);
    break;   
     }
  }


