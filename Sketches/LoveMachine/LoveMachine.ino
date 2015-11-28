/**
   This Sketch programs the Love Machine. It reads the value
   from the Temperature sensor to determine just how hot
   we are.
*/

const int BAUD_RATE = 9600;
const int LEDs[] = { 10, 11, 12 };
const int TEMPERATURE_SENSOR = A0; //Pin 14
const double VOLTAGE = 5.0;

const double lowTemp = 75.0;
const double midTemp = 78.0;
const double highTemp = 83.0;

void setup()
{
  Serial.begin(BAUD_RATE);

  int len = sizeof(LEDs) / sizeof(int);
  Serial.println("Array Length = " + String(len));

  Serial.println("Temperature Sensor at " + String(TEMPERATURE_SENSOR));

  for (int i = 0; i < len; ++i)
  {
    int led = LEDs[i];
    pinMode(led, OUTPUT);
    turnOff(led);
  }
}

void loop()
{
  int sensorValue = analogRead(TEMPERATURE_SENSOR);
  Serial.println("Sensor Value at " + String(sensorValue));

  double percentage = map(sensorValue, 0, 1023, 0, 1000) / 10.0;
  Serial.println("Percentage at " + String(percentage));

  double voltage = (percentage / 100.0) * VOLTAGE;
  Serial.println("Voltage at " + String(voltage));

  double celcius = voltageToCelcius(voltage);
  Serial.println("Celcius at " + String(celcius));

  double fahrenheit = celciusToFahrenheit(celcius);
  Serial.println("Temperature at " + String(fahrenheit) + " degress Fahrenheit");

  if (fahrenheit <= lowTemp)
  {
    turnOn(12);
    turnOff(11);
    turnOff(10);
  }
  else if (fahrenheit <= midTemp)
  {
    turnOn(12);
    turnOn(11);
    turnOff(10);
  }
  else if (fahrenheit <= highTemp)
  {
    turnOn(12);
    turnOn(11);
    turnOn(10);
  }
  else
  {
    //OFF THE CHARTS HOT
    blinkSimultaneously(LEDs, 3, 3);
  }

  delay(1000);

}

void turnOn(int led)
{
  digitalWrite(led, HIGH);
}


void turnOff(int led)
{
  digitalWrite(led, LOW);

}

double voltageToCelcius(double voltage)
{
  double answer = voltage  - 0.5;
  answer = answer * 100;
  return answer;
}

double celciusToFahrenheit(double celcius)
{
  double answer = celcius * 9;
  answer = answer / 5;
  answer += 32;
  return answer;
}

double fahrenheitToCelcius(double fahrenheit)
{
  double answer = fahrenheit - 32;
  answer = answer * 5;
  answer = answer / 9;
  return answer;
}

void blinkSimultaneously(const int LED[], int numberOfLeds, int numberOfTimes)
{

  int len = numberOfLeds;

  Serial.println("Length = " + String(len));

  for (int i = 0; i < numberOfTimes; ++i)
  {
    for (int i = 0; i < len; ++i)
    {
      int led = LED[i];
      turnOn(led);
    }
    sleep(0.2);

    for (int i = 0; i < len; ++i)
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

