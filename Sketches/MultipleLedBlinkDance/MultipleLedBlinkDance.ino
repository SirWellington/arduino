/**
 * This Sketch blinks the Red, Green, and Blue LEDS
 * in a particular pattern.
 */
const int RED = 11;
const int GREEN = 10;
const int BLUE = 3;

const int TOTAL_LEDS = 3;
const int LEDs [TOTAL_LEDS] = {RED, GREEN, BLUE};

void setup() {

  for(int i = 0; i < TOTAL_LEDS; ++i)
  {
    int led = LEDs[i];
    pinMode(led, OUTPUT);
  }

}

void loop() 
{
  const int states = 6;
  const int leds [states] = { RED, GREEN, RED, BLUE, RED, GREEN };
  
  for (int i = 0; i < states; ++i)
  {
    int led = leds[i];
    blink(led, 2);
  }
}

void blink(int LED, int numberOfTimes)
{
  for (int i = 0; i < numberOfTimes; ++i)
  {
    turnOn(LED);
    sleep(0.15);
    turnOff(LED);
    sleep(0.15);
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

