/**
 * This Sketch powers the Spaceship launcher!
 * When you push the button, the blue light turns on, 
 * and then the other two LEDs blink fast!
 */

const int RED = 13;
const int GREEN = 12;
const int BLUE = 11;

const int TOTAL_LEDS = 3;
const int LEDs[TOTAL_LEDS] = { RED, GREEN, BLUE };

const int BUTTON = 3;
 
void setup() 
{
  for (int i = 0; i < TOTAL_LEDS; ++i)
  {
    int led = LEDs[i];
    pinMode(led, OUTPUT);
  }

  pinMode(BUTTON, INPUT);

  Serial.begin(9600);
}

void loop() 
{
  turnOn(GREEN);

  if (isButtonPushed())
  {
    Serial.println("Button ON");
    turnOff(GREEN);
    
    int buttonsToBlink[2] = { RED, BLUE };
    blinkSimultaneously(buttonsToBlink, 2, 5);
  }
  else
  {
    Serial.println("Button OFF");
  }
}

boolean isButtonPushed()
{
  int value = digitalRead(BUTTON);
  return value == HIGH;
}

void turnOn(int device)
{
  digitalWrite(device, HIGH);
}

void turnOff(int device)
{
  digitalWrite(device, LOW);
}

void blink(int LED, int numberOfTimes)
{
  for (int i = 0; i < numberOfTimes; ++i)
  {
    turnOn(LED);
    sleep(0.2);
    turnOff(LED);
    sleep(0.2);
  }
}

void blinkSimultaneously(int LED[], int numberOfLeds, int numberOfTimes)
{
//  int len = sizeof(LED) / sizeof(int);
int len = numberOfLeds;

  Serial.println("Length = " + String(len));
  
  for (int i = 0; i < numberOfTimes; ++i)
  {
    for(int i = 0; i < len; ++i)
    {
      int led = LED[i];
      turnOn(led);
    }
    sleep(0.2);
    
    for(int i = 0; i < len; ++i)
    {
      int led = LED[i];
      turnOff(led);
    }
    sleep(0.2);
  }
}

void sleep(double seconds)
{
  int milli = secondsToMillis(seconds);
  delay(milli);
}

long secondsToMillis(double seconds)
{
  return seconds * 1000;
}

