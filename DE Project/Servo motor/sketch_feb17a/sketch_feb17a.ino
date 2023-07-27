#include<Servo.h>
Servo servo1;
void setup()
{
  servo1.attach(3);
}
void loop()
{
  servo1.write(10);
  delay(1000);
  
  
  
}
