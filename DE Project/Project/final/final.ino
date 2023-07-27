#include<Servo.h>
#include<LiquidCrystal.h>
#include <Adafruit_MLX90614.h>
#include<Wire.h>

LiquidCrystal_I2C lcd (0x27,16,2);
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
Servo servo;

void setup()
{
  servo.attach(10);
  
  Serial.begin(9600);
  Serial.println("Adafruit MLX90614 Emissivity Setter.\n");
  mlx.begin();
  
  lcd.begin(); 
}
int objTemp;
void loop()
{
  objTemp = mlx.readObjectTempF();
  if(objTemp<=99)
  {
    lcd.setCursor(0,0);
    lcd.print("Object Temp: ");
    lcd.print(objTemp);
    lcd.print(char(223));
    lcd.print("F");
    servo.write(0);
    delay(500);
    servo.write(90);
    delay(2000);
  }
  else if(objTemp>99)
  {
    lec.setCursor(5,0);
    lec.print("NO ENTRY!");
    servo.write(0);
  }
}
