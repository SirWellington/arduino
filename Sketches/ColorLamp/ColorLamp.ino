/**
 * This Device is a Color Lamp that matches its color
 * to the Ambient Color. It reads the RGB color of the
 * sorrounding environment and changes its color to match.
 * It's like a Chameleon.
 */
#include <stdarg.h>
#include <stdio.h>

long secondsToMillis(double);

const double DEVICE_VOLTAGE = 5.0;

const int RED_LIGHT_COMPONENT = 11;
const int GREEN_LIGHT_COMPONENT = 9;
const int BLUE_LIGHT_COMPONENT = 10;

const int RED_SENSOR = A0;
const int GREEN_SENSOR = A1;
const int BLUE_SENSOR = A2;

int redInput = 0;
int greenInput = 0;
int blueInput = 0;

int redOutput = 0;
int greenOutput = 0;
int blueOutput = 0;

int maxSensorValue = 0;
int minSensorValue = 1025;

long lastCalibrationTime = 0L;
long calibrationFrequency = secondsToMillis(60);
long calibrationTime = secondsToMillis(5);

void setup() 
{
  Serial.begin(9600);
  
  setOutput(3, 
            RED_LIGHT_COMPONENT, 
            BLUE_LIGHT_COMPONENT,
            GREEN_LIGHT_COMPONENT);
  
  turnOff(3, 
          RED_LIGHT_COMPONENT, 
          BLUE_LIGHT_COMPONENT,
          GREEN_LIGHT_COMPONENT);

  testLEDs();

  calibrate(calibrationTime);
}

void loop() 
{
  reactToLight();
  
  long delayTime = secondsToMillis(3);
  delay(delayTime);

  if (shouldCalibrate())
  {
    calibrate(calibrationTime);
  }
  
  printBreak();
}

void testLEDs()
{
  Serial.println("Testing the LEDs");
  
  long delays = secondsToMillis(1);
  
  digitalWrite(RED_LIGHT_COMPONENT, HIGH);
  delay(delays);
  digitalWrite(RED_LIGHT_COMPONENT, LOW);
  
  digitalWrite(GREEN_LIGHT_COMPONENT, HIGH);
  delay(delays);
  digitalWrite(GREEN_LIGHT_COMPONENT, LOW);
  
  digitalWrite(BLUE_LIGHT_COMPONENT, HIGH);
  delay(delays);
  digitalWrite(BLUE_LIGHT_COMPONENT, LOW);
}

void reactToLight()
{
  redInput = analogRead(RED_SENSOR);
  greenInput = analogRead(GREEN_SENSOR);
  blueInput = analogRead(BLUE_SENSOR);

  String message = "Red: " + String(redInput) + ", Green: " + String(greenInput) + ", Blue: " + String(blueInput);
  Serial.println(message);

  redOutput = map(redInput, minSensorValue, maxSensorValue, 0, 255);
  blueOutput = map(blueInput, minSensorValue, maxSensorValue, 0, 255);
  greenOutput = map(greenInput, minSensorValue, maxSensorValue, 0, 255);
 
  message = "Red Output: " + String(redOutput) + ", Green Output: " + String(greenOutput) + ", Blue Output: " + String(blueOutput);
  Serial.println(message);

  analogWrite(RED_LIGHT_COMPONENT, redOutput);
  analogWrite(GREEN_LIGHT_COMPONENT, greenOutput);
  analogWrite(BLUE_LIGHT_COMPONENT, blueOutput);
}

boolean shouldCalibrate()
{
  long currentTime = millis();

  long timeDifference = currentTime - lastCalibrationTime;

  return timeDifference >= calibrationFrequency;
}

void calibrate(long durationInMillis)
{ 
  long currentTime = millis();
  long endTime = currentTime + durationInMillis;

  Serial.println("Calibrating Device..."); 
  Serial.println("Current Time: " + String(currentTime) + ", End Time: " + String(endTime));


  minSensorValue = 1025;
  maxSensorValue = 0;
  
  while (currentTime <= endTime)
  {
    redInput = analogRead(RED_SENSOR);

    minSensorValue = min(minSensorValue, redInput);
    maxSensorValue = max(maxSensorValue, redInput);

    currentTime = millis();
  }

  Serial.println("Calibration Complete.");
  Serial.println("Min Sensor Value at : " + String(minSensorValue));
  Serial.println("Max Sensor Value at: " + String(maxSensorValue));
  
  lastCalibrationTime = millis();
  
  printBreak();
  
}

//=========================================================

long secondsToMillis(double seconds)
{
  return seconds * 1000;
}

void setOutput(int count, ...)
{
  va_list pins;
  va_start(pins, count);

  for (int i = 0; i < count; ++i)
  {
    int pin = va_arg(pins, int);
    pinMode(pin, OUTPUT);
  }
  
  va_end(pins);
}

void turnOn(int count, ...)
{
  va_list pins;
  va_start(pins, count);

  for (int i = 0; i < count; ++i)
  {
    int pin = va_arg(pins, int);
    digitalWrite(pin, HIGH);
  }
  
  va_end(pins);
}


void turnOff(int count, ...)
{
  va_list pins;
  va_start(pins, count);

  for (int i = 0; i < count; ++i)
  {
    int pin = va_arg(pins, int);
    digitalWrite(pin, LOW);
  }
  
  va_end(pins);
}

int _min(int count, ...)
{

  if (count == 0)
  {
    return 0;
  }
  
  va_list values;
  va_start(values, count);
  
  int min = va_arg(values, int);
  
  for (int i = 1; i < count; ++i)
  {
      int nextValue = va_arg(values, int);

      if (nextValue < min)
      {
        min = nextValue;
      }
  }

  va_end(values);
  
  return min;
}

void printBreak()
{
  Serial.println("\n=================================================\n");
}

