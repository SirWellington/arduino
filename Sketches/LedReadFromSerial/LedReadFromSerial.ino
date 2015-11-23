/**
 * This Sketch blinks a set of LEDs one at time.
 * The circuit used with this sketch has a Red, Green, and a Blue
 * LED.
 * 
 * This Sketch allows reading of values from the Serial to 
 * customize the Blink Speed.
 */
const int RED = 11;
const int GREEN = 10;
const int BLUE = 3;

const int TOTAL_LEDS = 3;
const int LEDs [TOTAL_LEDS] = {RED, GREEN, BLUE};

double BLINK_SPEED_SECONDS = 0.2;

void setup() 
{

  for(int i = 0; i < TOTAL_LEDS; ++i)
  {
    int led = LEDs[i];
    pinMode(led, OUTPUT);
  }
  
  Serial.begin(9600);
  Serial.setTimeout(5);
}

void loop() 
{
  float serialValue = Serial.parseFloat();
  //Only set variable if it's > 0
  if (serialValue > 0.0)
  {
    BLINK_SPEED_SECONDS = serialValue;
  }
  
  for (int i = 0; i < TOTAL_LEDS; ++i)
  {
    int led = LEDs[i];
    blink(led, 2);
  }
}

void blink(int LED, int numberOfTimes)
{
  for (int i = 0; i < numberOfTimes; ++i)
  {
    turnOn(LED);
    sleep(BLINK_SPEED_SECONDS);
    turnOff(LED);
    sleep(BLINK_SPEED_SECONDS);
  }
}

void sleep(double seconds)
{
  int milli = secondsToMillis(seconds);
  delay(milli);
}

void turnOn(int LED) 
{
  digitalWrite(LED, HIGH);
}

void turnOff(int LED)
{
  digitalWrite(LED, LOW);
}

long secondsToMillis(double seconds)
{
  return seconds * 1000;
}

