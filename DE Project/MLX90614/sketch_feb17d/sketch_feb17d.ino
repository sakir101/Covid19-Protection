#include <Adafruit_MLX90614.h>
#include<Wire.h>
#include<Servo.h>
#include<LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd (0x27,16,2);
Servo servo1;

//== CHANGE THIS ============
double new_emissivity = 0.95;
//===========================

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
int pos =10;
void setup() {
  
  Serial.begin(9600);
  Serial.println("Adafruit MLX90614 Emissivity Setter.\n");
  mlx.begin();
  lcd.begin();
  servo1.attach(3);
  
 
  
  }
int p, i=0, q = 0.0, r= 0.0, j=0;

void loop() {
   if(pos==10){
    servo1.write(10);
  }
  delay(1000);
  ++i;
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF());
  Serial.print("Object = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");
  lcd.setCursor(2,0);
  lcd.print("Please wait...");
  p = mlx.readObjectTempF();
  q = q+p;
   if(p>=97 && j==0){
      q=0;
      r=0;
      i=0;
      j=1;
      delay(2000);
    }
  if(i==5)
  {
    r = q /5;
    
    servo1.write(10);
   
  }
  
  
  if(r <=99 && r>=97 && i==5)
  {
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("Temp: ");
    lcd.print(r);
    lcd.setCursor(3,1);
    lcd.print("Please Enter");
    servo1.write(10);
    servo1.write(110);
  delay(3000);
  servo1.write(10);
  delay(2000);
  lcd.clear();
    i=0;
    p=0;
    q=0;
    r=0;
    j=0;
  
  }
  else if(r>99 && i==5)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("May Covid Positive");
    lcd.setCursor(1,1);
    lcd.print("Please Return!");
    servo1.write(10);
    Serial.print("No Entry!\n");
    delay(5000);
    lcd.clear();
    i=0;
    p=0;
    q=0;
    r=0;
    j=0;
  }
  else if(i>5){
    i=0;
    p=0;
    q=0;
    r=0;
    
  }
}
