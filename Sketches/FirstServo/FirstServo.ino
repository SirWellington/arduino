/**
 * This Circuit and Program use a Potentiometer
 * to spin a Servo Motor
 */
 #include <Servo.h>

const int potPin = A0;
int potVal;
int angle;

const int servoMotorPin = 11;

Servo servo;

 
void setup() 
{
  Serial.begin(9600);
  servo.attach(servoMotorPin);
  
}

void loop() 
{
  potVal = analogRead(potPin);

  Serial.println("Pot Value: " + String(potVal));

  angle = map(potVal, 0, 1024, 0, 179);
  Serial.println("Angle: " + String(angle));

  servo.write(angle);
  delay(50);
}
