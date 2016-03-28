/**
 * This Circuit and Program use a Potentiometer
 * to spin a Servo Motor
 */
 #include <Servo.h>

const int potPin = A5;
int potVal;
int angle;

const int servoMotorPin = 9;

const int LED = 13;

Servo servo;

void setup() 
{
  Serial.begin(9600);
  servo.attach(servoMotorPin);
  
  pinMode(LED, OUTPUT);
}

void loop() 
{
  potVal = analogRead(potPin);

  Serial.println("Pot Value: " + String(potVal));

  int newAngle = map(potVal, 0, 1023, 0, 179);

  if (newAngle != angle)
  {
    turnOn(LED);
  }
  else
  {
    turnOff(LED);
  }
  angle = newAngle;
  Serial.println("Angle: " + String(angle));

  servo.write(angle);
  delay(50);
}

void turnOn(int pin)
{
  digitalWrite(pin, HIGH);
}

void turnOff(int pin)
{
  digitalWrite(pin, LOW);
}

