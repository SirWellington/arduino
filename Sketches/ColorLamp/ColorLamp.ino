/**
 * This Device is a Color Lamp that matches its color
 * to the Ambient Color. It reads the RGB color of the
 * sorrounding environment and changes its color to match.
 * It's like a Chameleon.
 */
#include <stdarg.h>
#include <stdio.h>

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
}

void loop() 
{
  redInput = analogRead(RED_SENSOR);
  greenInput = analogRead(GREEN_SENSOR);
  blueInput = analogRead(BLUE_SENSOR);

  String message = "";
  message = message + "Red: " + redInput;
  message = message + ", Green: " + greenInput;
  message = message + ", Blue: " + blueInput;
  Serial.println(message);

  redOutput = map(redInput, 0, 1023, 0, 255);
  blueOutput = map(blueInput, 0, 1023, 0, 255);
  greenOutput = map(greenInput, 0, 1023, 0, 255);
 
  message = "";
  message = message + "Red Output: " + redOutput;
  message = message + " Green Output: " + greenOutput;
  message = message + " Blue Output: " + blueOutput;
  Serial.println(message);

  analogWrite(RED_LIGHT_COMPONENT, redOutput);
  analogWrite(GREEN_LIGHT_COMPONENT, greenOutput);
  analogWrite(BLUE_LIGHT_COMPONENT, blueOutput);
  
  delay(500);
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
