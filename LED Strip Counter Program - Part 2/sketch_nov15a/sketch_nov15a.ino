
#include <Adafruit_NeoPixel.h> 
#define PIN A4 
byte stripLength = 36;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(stripLength, PIN, NEO_GRB + NEO_KHZ800);

byte pinA = 2;       // Pin 11 on display 
byte pinB = 3;       // Pin 7 on display 
byte pinC = 4;       // Pin 4 on display 
byte pinD = 5;       // Pin 2 on display 
byte pinE = 6;       // Pin 1 on display 
byte pinF = 7;       // Pin 10 on display 
byte pinG = 8;       // Pin 5 on display
byte D1 = 9;         // Pin 12 on display 
byte D2 = 10;        // Pin 9 on display 
byte D3 = 11;        // Pin 8 on display 
byte D4 = 12;        // Pin 6 on display
byte buzzerPin = A5; // Buzzer output pin
byte speedParameter;
short soundLength; // How long a sound is played in milliseconds
short soundFrequency; // Frequency of sound in Hertz

// Some global variables used for counting functions
byte countButtonPress = 0;
byte count1 = 0;
byte count2 = 0;
byte count3 = 0;
byte count4 = 0;

void setup()// Put your setup code here, to run once:
{
  Serial.begin(9600);
  strip.begin();
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT); 
  pinMode(buzzerPin, OUTPUT);
  speedParameter = 26;
  soundLength = 100;
  soundFrequency = 500;
}

void loop()//Put your main code here, to run repeatedly:
{ 
  for (byte i = 0; i < stripLength - 11; ++i)
  { 
    DisplayCount();
    DisplayLedMovement(i);

    // Timing LED strip: each LED is lit up for a total time of "speedParameter" x 12 milliseconds (from delays)
    // So the movement of the LED speeds up as "speedParameter" is reduced.

    // This loop controls the 4 digit counter and the LED timing, due to the delays within "DisplayCount()" called repeatedly
    for (byte x = 0; x <= (speedParameter/10); ++x)
    {
      DisplayCount();
    }
  }

  CounterDisplay(); // Counting each "bounce" of the LEDs at the ends of the strip
  
  --speedParameter;

  tone(buzzerPin, soundFrequency, soundLength);// Buzz

  if (speedParameter < 3)
  {
    speedParameter = 3;
  }
  
  for (short i = stripLength - 11; i >= 0; --i)
  { 
    DisplayCount();
    DisplayLedMovement(i);
    
    // Loop condition check needs adjusting to speed up LEDs more smoothly, as speedParameter is an integer value
    for (byte x = 0; x <= (speedParameter/10); ++x)
    {
      DisplayCount();
    }
  }

  CounterDisplay();
  --speedParameter;

  tone(buzzerPin, soundFrequency, soundLength);
  
  if (speedParameter < 3)
  {
    speedParameter = 3;
  }
}

void CounterDisplay()
{
  ++count1;
    
  if(count1 > 9)
  {
    count1 = 0;
    ++count2;
  }

  if(count2 > 9)
  {
    count2 = 0;
    ++count3;
  }

  if (count3 > 9)
  {
    count3 = 0;
    ++count4;
  }

  if (count4 > 9)
  {
    count4 = 0;
  }
}

void DisplayCount()
{
  DigitSelect(1, count1);
  delay(3);
  DigitSelect(2, count2);
  delay(3);
  DigitSelect(3, count3);
  delay(3);
  DigitSelect(4, count4);
  delay(3);
}

void DisplayLedMovement(byte ledNumber)
{  
    DisplayCount();

    for(byte x = 0; x < stripLength; x++)
    {
      if ((x >= ledNumber) && (x < ledNumber + 4))
      {
        strip.setPixelColor(x, 150, 0, 0);
      } 
      
      else if ((x >= ledNumber + 4) && (x <= ledNumber + 6))
      {
        strip.setPixelColor(x, 0, 150, 0);
      }
      
      else if ((x > ledNumber + 6) && (x <= ledNumber + 10))
      {
        strip.setPixelColor(x, 150, 0, 0);
      }
      
      else
      {
        strip.setPixelColor(x, 0, 0, 0);
      }
    }
    strip.show();
}

void DigitSelect(int digit, int count)
{
   switch(digit)
   {
      case 1:
      FourthDigit();
      break;
      
      case 2:
      ThirdDigit();
      break;

      case 3:
      SecondDigit();
      break;

      case 4:
      FirstDigit();
      break;
   }
   
   switch(count)
   {
      case 0:
      DisplayZero();
      break;
      
      case 1:
      DisplayOne();
      break;

      case 2:
      DisplayTwo();
      break;

      case 3:
      DisplayThree();
      break;

      case 4:
      DisplayFour();
      break;

      case 5:
      DisplayFive();
      break;

      case 6:
      DisplaySix();
      break;

      case 7:
      DisplaySeven();
      break;

      case 8:
      DisplayEight();
      break;

      case 9:
      DisplayNine();
      break;
   }
}

void FirstDigit()// Select the 1st digit
{
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH); 
}

void SecondDigit()// Select the 2nd digit 
{
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH); 
}

void ThirdDigit()// Select the 3rd digit
{
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D4, HIGH); 
}

void FourthDigit()// Select the 4th digit
{
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW); 
}

void DisplayZero()
{
  //Output "0" 
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);   
}

void DisplayOne()
{
  //Output "1"
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
}

void DisplayTwo()
{
  //Output "2"
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);   
}

void DisplayThree()
{
  //Output "3"
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);      
}

void DisplayFour()
{
  //Output "4"
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);     
}

void DisplayFive()
{
  //Output "5"
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);    
}

void DisplaySix()
{
  //Output "6"
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);   
}

void DisplaySeven()
{
  //Output "7"
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);   
}

void DisplayEight()
{
  //Output "8"
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
}

void DisplayNine()
{
  //Output "9"
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);  
}
