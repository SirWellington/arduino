/**
 * This Sketch reads a Resistor Ladder to determine a pitch to send
 * to the Piezo unit. It's designed to be used like an Electronic
 * Keyboard =)
 * 
 */

const int NOTES[] =  { 262, 294, 330, 349 };

void setup() 
{
  Serial.begin(9600);

}

void loop() 
{
  int keyValue = analogRead(A0);

  makeSoundForKey(keyValue);

  Serial.println(keyValue);
  sleep(30);

}

void makeSoundForKey(int value)
{
  if (isC(value))
  {
    soundC();
  }
  else if (isD(value))
  {
    soundD();
  }
  else if (isE(value))
  {
    soundE();
  }
  else if (isF(value))
  {
    soundF();
  }
  else
  {
    makeNoSound();
  }
}


boolean isC(int value)
{
  return value == 1023;
}

boolean isD(int value)
{
  return value > 995 && value < 1005;
}

boolean isE(int value)
{
  return value > 495 && value < 510;
}

boolean isF(int value)
{
  return value > 5 && value < 15;
}

void soundC()
{
  tone(9, NOTES[0]);
}

void soundD()
{
  tone(9, NOTES[1]);
}

void soundE()
{
  tone(9, NOTES[2]);
}
void soundF()
{
  tone(9, NOTES[3]);
}

void makeNoSound()
{
  noTone(9);
}

void sleep(long amount)
{
  delay(amount);
}

