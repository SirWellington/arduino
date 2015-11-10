/*
 * This Sketch reads the value of a Push-Button.
 */

const int BUTTON = 2;

void setup() 
{
  Serial.begin(9600);
  
  pinMode(BUTTON, INPUT);
}

void loop() 
{
  int buttonState = digitalRead(BUTTON);

  boolean isOn = buttonState == 1;
  
  if (isOn)
  {
    Serial.println("Button is ON!");
  }
  else
  {
    Serial.println("Button is OFF");
  }
  
  delay(100);
}
