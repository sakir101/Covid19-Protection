#include<LiquidCrystal.h>
int i=6;
LiquidCrystal lcd(5,6,7,8,9,10);
void setup()
{
  lcd.begin(16,2);
}
void loop()
{
  lcd.setCursor(3,0);
  lcd.print("Sakir");
  lcd.setCursor(0,1);
  lcd.print("Chapter No - ");
  lcd.print(i);
  delay(2000);
  lcd.clear();
  delay(1000);
}
