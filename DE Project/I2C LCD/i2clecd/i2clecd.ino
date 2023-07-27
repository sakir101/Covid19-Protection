#include<LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd (0x27,16,2);
int i=6;

void setup()
{
  lcd.begin();
}
void loop()
{
  lcd.setCursor(3,0);
  lcd.print("No Entry");
  lcd.setCursor(0,1);
  delay(1000);
  lcd.clear();
}
