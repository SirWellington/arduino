//Communicates with the led on pin 13

int LED = 10;
int SYSTEM_LED = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(SYSTEM_LED, OUTPUT);
  turnOff(SYSTEM_LED);
}

void loop() {
  blink(LED, 2);
  sleep(5);
}

void blink(int led, int numberOfTimes)
{
  for(int i = 0; i < numberOfTimes; ++i)
  {
    turnOn(led);
    sleep(0.1);
    turnOff(led);
    sleep(0.1);
  }
}

void sleep(double seconds)
{
  int milliseconds = secondsToMillis(seconds);
  delay(milliseconds);
}
int secondsToMillis(double seconds)
{
  return seconds * 1000;
}

void turnOn(int device)
{
  digitalWrite(device, HIGH);
}

void turnOff(int device)
{
  digitalWrite(device, LOW);
}

