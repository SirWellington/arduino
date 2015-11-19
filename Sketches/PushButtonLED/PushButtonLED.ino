const int LED = 1;
const int BUTTON = 2;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() 
{
  int buttonState = digitalRead(BUTTON);
  boolean isOn = buttonState == 1;

  if (isOn)
  {
    turnOn(LED);
  }
  else
  {
    turnOff(LED);
  }
}

void turnOff(int device) 
{
  digitalWrite(device, LOW);
}

void turnOn(int device)
{
  digitalWrite(device, HIGH);
}

