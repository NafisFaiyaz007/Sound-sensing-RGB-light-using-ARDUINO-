/*
CSE323 Project
Section: 5
Group: 4
Summer 2022
Project Name: Music Controlled Lighting System
*/

#define redPin 11
#define greenPin 10
#define bluePin 9
#define ledDelay 3
#define micPin A0

float micValue = 0, signalFiltered = 0, signalFilteredValues[] = {3.4, 3.1, 2.7, 2.4, 2.1, 1.7, 1.3, 0.9, 0.4};

void setup()
{
  Serial.begin(9600); // This starts the arduinos communication
}

void loop()
{
  MainFunction();
}

void  
{
  micValue = (float)analogRead(micPin) * (5.0 / 1024.0); // micPin value is 0 to 1023 & then we convert the value to volts ranging 0 to 5.

  FilterSignal(micValue); // This function is used to change the value of the signalFiltered variable

  CompareSignalFiltered(signalFiltered); // This function compares the singal value in order to choose the colour of the light
}

void FilterSignal(float sensorSignal) // This function is used to change the value of the signalFiltered variable
{
  signalFiltered = (0.945 * signalFiltered) + (0.0549 * sensorSignal);
}

void CompareSignalFiltered(float signalFiltered) // This function defines the color of the LEDS by comparing
{

  if (signalFiltered > signalFilteredValues[0])
  {
    RGBColor(0, 0, 255); // Blue
  }

  else if (signalFiltered <= signalFilteredValues[0] && signalFiltered > signalFilteredValues[1])
  {
    RGBColor(0, 255, 255); // Azure
  }

  else if (signalFiltered <= signalFilteredValues[1] && signalFiltered > signalFilteredValues[2])
  {
    RGBColor(0, 127, 255); // Cyan
  }

  else if (signalFiltered <= signalFilteredValues[2] && signalFiltered > signalFilteredValues[3])
  {
    RGBColor(0, 255, 127); // Aqua Marine
  }

  else if (signalFiltered <= signalFilteredValues[3] && signalFiltered > signalFilteredValues[4])
  {
    RGBColor(0, 255, 0); // Green
  }

  else if (signalFiltered <= signalFilteredValues[4] && signalFiltered > signalFilteredValues[5])
  {
    RGBColor(255, 255, 0); // Yellow
  }

  else if (signalFiltered <= signalFilteredValues[5] && signalFiltered > signalFilteredValues[6])
  {
    RGBColor(255, 0, 255); // Magenta
  }

  else if (signalFiltered <= signalFilteredValues[6] && signalFiltered > signalFilteredValues[7])
  {
    RGBColor(255, 0, 127); // Rose
  }

  else if (signalFiltered <= signalFilteredValues[7] && signalFiltered > signalFilteredValues[8])
  {
    RGBColor(255, 127, 0); // Orange
  }

  else if (signalFiltered <= signalFilteredValues[8])
  {
    RGBColor(255, 0, 0); // Red
  }

  else
  {
    RGBColor(0, 0, 255); // Default:Blue
  }
}

void RGBColor(int redColor, int greenColor, int blueColor) // This is the function which is actually switching the color of the leds through arduino pin
{
  analogWrite(redPin, redColor);
  analogWrite(greenPin, greenColor);
  analogWrite(bluePin, blueColor);

  delay(ledDelay); // Delays the light
}
