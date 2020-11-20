// Output pins 2-12 are used to drive the display 
byte pinA = 2;       // Pin 11 on display 
byte pinB = 3;       // Pin 7 on display 
byte pinC = 4;       // Pin 4 on display 
byte pinD = 5;       // Pin 2 on display 
byte pinE = 6;       // Pin 1 on display 
byte pinF= 7;        // Pin 10 on display 
byte pinG = 8;       // Pin 5 on display
byte D1 = 9;         // Pin 12 on display 
byte D2 = 10;        // Pin 9 on display 
byte D3 = 11;        // Pin 8 on display 
byte D4 = 12;        // Pin 6 on display
byte buttonPin = 13; // Button to control timer
bool buttonPressed;

// Some global variables used for counting functions
unsigned int countStart;
byte countTenths = 0;
byte countSeconds = 0;
byte countTens = 0;
byte countMinutes = 0;
byte countButtonPress;

void setup()// Put setup code here, to run once:
{
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
  pinMode(buttonPin, INPUT);
  countStart = millis();
}

void loop() // Main method, put main code here to run repeatedly:
{
  unsigned int count = millis();
  int timeDifference = count - countStart;

  DisplayCount();

  if (digitalRead(buttonPin) == LOW)// If the button is pressed then run the following code
  { 
    buttonPressed = true;
    countButtonPress = 1;
  }

  if (countButtonPress == 1)
  {
    countButtonPress = 0;
    return;
  }
  // The above code pauses the timer while the button is held down, the timer resumes when the button is released 
  
  if (timeDifference > 90)// Time check adjusted, compensating for delays in the program (approximate)
  {
    countTenths++;
    countStart = count;
  }

  if(countTenths > 9)
  {
    countTenths = 0;
    countSeconds++;
  }

  if(countSeconds > 9)
  {
    countSeconds = 0;
    countTens++;
  }

  if (countTens > 5)
  {
    countTens = 0;
    countMinutes++;
  }

  if (countMinutes > 9)
  {
    countMinutes = 0;
  }
}
// End main method

void DisplayCount()
{
  DigitSelect(1, countTenths);
  delay(3);
  DigitSelect(2, countSeconds);
  delay(3);
  DigitSelect(3, countTens);
  delay(3);
  DigitSelect(4, countMinutes);
  delay(3);
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
      //DisplayDecimalPoint();
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
