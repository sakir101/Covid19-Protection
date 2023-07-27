#include<Servo.h>
#include<LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd (0x27,16,2);
Servo servo1;
void setup()
{
  servo1.attach(3);
  lcd.begin();
}
int i=1;
void servo()
{
  servo1.write(10);
  delay(1000);
  servo1.write(110);
  delay(3000);
}
void loop()
{
  if(i==1)
  {
    servo();
  }
  
  lcd.setCursor(3,0);
  lcd.print("No Entry");
  
  
  
}
