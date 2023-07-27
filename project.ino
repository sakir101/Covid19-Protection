#include <Adafruit_MLX90614.h>
#include<Wire.h>
#include<Servo.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x27, 16, 2);
Servo servo1;
Servo servo2;

int trigpin = A0;
int echopin = A1;
float distance;
float duration;

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
int pos = 10;

void setup() {

  Serial.begin(9600);
  Serial.println("Adafruit MLX90614 Emissivity Setter.\n");
  mlx.begin();
  lcd.begin();
  servo1.attach(3);
  servo2.attach(5);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  Serial.begin(9600);
}

int p, i = 0, q = 0.0, r = 0.0, j = 0, s = 0, t = 0, pass = 0, count2 = 0;

void loop() {
  if (pos == 10) {
    servo1.write(10);
  }
  servo2.write(110);
  delay(1000);
  ++i;
  Serial.print("Object = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");
  digitalWrite(trigpin, LOW);
  delay(2);

  lcd.setCursor(2, 0);
  lcd.print("Please wait...");
  p = mlx.readObjectTempF();
  q = q + p;
  if (p <= 95 && p >= 92)
  {
    count2++;
    if (count2 == 5)
    {
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("Please come");
      lcd.setCursor(5, 1);
      lcd.print("close");
      delay(5000);
      count2 = 0;
    }
    
    lcd.clear();
  }
  if (p >= 96 && j == 0) {
    q = 0;
    r = 0;
    i = 0;
    j = 1;
    delay(2000);
  }
  if (i == 5)
  {
    r = q / 5;

    servo1.write(10);

  }


  if (r <= 99 && r >= 96 && i == 5)
  {
    Serial.print("\n");
    s = 1;
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Temp: ");
    lcd.print(r);
    lcd.print((char)223);
    lcd.print("F");
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Wash Hand");
    lcd.setCursor(1, 1);
    lcd.print("In 5 Sec");
    servo1.write(10);
    servo2.write(110);
    delay(5000);
    digitalWrite(trigpin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigpin, LOW);
    duration = pulseIn(echopin, HIGH);
    distance = (duration * .034) / 2;

    if (distance <= 10)
    {
      
      t = 1;
      servo2.write(0);
      delay(500);
      servo2.write(110);
      delay(2000);
      if (s == 1 && t == 1)
      {
        Serial.print("Temperature in between: ");
        Serial.print(r);
        Serial.print("\n");
        ++pass;
        Serial.print("Pass: ");
        Serial.print(pass);
        Serial.print("\n");
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("Please Enter");
        servo1.write(110);
        delay(5000);
        servo1.write(10);

      }
    }

    else if (distance > 10)
    {
      Serial.print("Temperature in between: ");
      Serial.print(r);
      Serial.print("\n");
      Serial.print("Did not wash hand\n");
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Time Out!");
      lcd.setCursor(1, 1);
      lcd.print("Go Back");
      delay(5000);
    }
    lcd.clear();
    s = 0;
    t = 0;
    i = 0;
    p = 0;
    q = 0;
    r = 0;
    j = 0;

  }
  else if (r > 99 && i == 5)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("May Covid Positive");
    lcd.setCursor(1, 1);
    lcd.print("Please Return!");
    servo1.write(10);
    servo2.write(110);
    Serial.print("No Entry!\n");
    delay(6000);
    lcd.clear();
    i = 0;
    p = 0;
    q = 0;
    r = 0;
    j = 0;
  }
  else if (i > 5) {
    i = 0;
    p = 0;
    q = 0;
    r = 0;

  }
}
