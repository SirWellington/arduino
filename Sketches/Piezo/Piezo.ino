/**
 * This Sketch makes the Piezo sound unit make a sound
 * on the press of a button.
 */

const int PIEZO = 9;
const int BUTTON = 4;

void setup() 
{
  Serial.begin(9600);
  
  pinMode(PIEZO, OUTPUT);
  pinMode(BUTTON, INPUT);

  Serial.println("Starting Program...");
}

void loop() 
{ 

  bool isButtonPressed = checkIfButtonPressed();

  if (isButtonPressed)
  {
    Serial.println("Button Pressed!");
    makeSound();
  }

  delay(100);
}

bool checkIfButtonPressed()
{
  return digitalRead(BUTTON) == HIGH;
}

void makeSound()
{
  Serial.println("MAKING NOISE!!");
  tone(PIEZO, 2000, 40);
}

