#include<Servo.h>

Servo servo1;

int trigpin = A0;
int echopin = A1;
float distance;
float duration;

void setup()
{
  servo1.attach(3);

  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  servo1.write(110);

  digitalWrite(trigpin, LOW);
  delay(2);

  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance = (duration * .034) / 2;
  Serial.print(distance);
  Serial.print("\n");
  if(distance<=5)
  {
    servo1.write(0);
  }

  else
  {
    servo1.write(110);
  }
  delay(500);
}
