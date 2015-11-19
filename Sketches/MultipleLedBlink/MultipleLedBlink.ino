/**
 * This Sketch blinks a set of LEDs one at time.
 * The circuit used with this sketch has a Red, Green, and a Blue
 * LED.
 */
const int RED = 12;
const int GREEN = 8;
const int BLUE = 1;

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
    sleep(0.2);
    turnOff(LED);
    sleep(0.2);
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

