int trigpin = A0;
int echopin = A1;
float distance;
float duration;

void setup()
{
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigpin,LOW);
  delay(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  duration = pulseIn(echopin,HIGH);
  distance = (duration*.034)/ 2;
  Serial.print("The Distance is = ");
  Serial.print(distance);
  Serial.print("cm");
  delay(500);
}
