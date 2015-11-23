/**
 * This Sketch fades a set of LEDs in and out one at time.
 * The circuit used with this sketch has a Red, Green, and a Blue
 * LED.
 */
const int RED = 11;
const int GREEN = 10;
const int BLUE = 3;

/**
 * Determines how quickly to Fade an LED
 */
const int FADE_AMOUNT = 5;

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
    fade(led);
  }
}

void fade(int LED)
{
  int brightness = 0;

  while (brightness < 255)
  {
    brightness += FADE_AMOUNT;
    analogWrite(LED, brightness);
    delay(30);
  }

  while (brightness > 0)
  {
    brightness -= FADE_AMOUNT;
    analogWrite(LED, brightness);
    delay(30);
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

