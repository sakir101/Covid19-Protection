#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 2, 1, 0, 4, 5, 6, 7, 3);

void setup()
{
  lcd.begin(16,2);
  lcd.blacklight();
  lcd.print("Sakir");
}

void loop()
{
  
}
