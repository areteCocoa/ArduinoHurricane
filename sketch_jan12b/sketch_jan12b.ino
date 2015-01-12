/* This program takes 3 different lights and lights them in 
* ascending and descending order based on the time delay. 
* They strobe back and forth. Once the light "reaches" 
* a side, they will play a song
*
* Author: Alexander Miller and Thomas Ring
*/

// global variables
float delayTime;
float modifier;
boolean buttonState;
boolean hasDoneSomething;
/*
* Need to define:
* 1. Delay time - how much time each light will take to show each other.
* 2. The dynamic multiplier for the delay time.
* 3. Set the pins 10, 9, and 6 to LED. Set pin 11 to Buzzer. Set pin 5 to button.
* 4. Enable console printing.
*/
void setup()
{
  delayTime = 2000;
  modifier = 0.5;
  pinMode( 10 , OUTPUT);
  pinMode( 9, OUTPUT );
  pinMode( 6, OUTPUT);
  pinMode( 5, INPUT);
  digitalWrite(5, HIGH);
  Serial.begin(9600);
  buttonState = false;
}

// pin 6
void light1()
{
  //Serial.println("Light 1");
  digitalWrite( 10 , HIGH );
  digitalWrite( 9, LOW);
  digitalWrite( 6, LOW);
}

// pin 9
void light2()
{
  //Serial.println("Light 2");
  digitalWrite( 10 , LOW );
  digitalWrite( 9, HIGH);
  digitalWrite( 6, LOW);
}

// pin 10
void light3()
{
  //Serial.println("Light 3");
  digitalWrite( 10 , LOW );
  digitalWrite( 9, LOW);
  digitalWrite( 6, HIGH);
}

void adjust()
{
  if(delayTime <= 75) {
    modifier = 2;
  } else if(delayTime >= 500) {
    modifier = 0.5;
  }
  delayTime = delayTime * modifier;
}

// Simply meant to play the tune for a little bit.
// pin 11
void playSong()
{
  //Serial.println("Played tune");
  tone(11, 300, 175);
  delay(200);
}

// this function gets the analog input of the light
// sensor and returns the float value.
float getWaitTime() {
  float waitTime = (5000 / analogRead(2));
  Serial.print( waitTime );
  Serial.println();
  return waitTime;
}


// The main of the program. Plays lights
// 1,2,3 and buzzer tune when the light reaches
// 1 and 3.
void loop()
{
  wait();
  
  light1();
  wait();
  
  light2();
  wait();
  
  light3();
  wait();
  
  playSong();
 
  light3();
  wait();
  
  light2();
  wait();
  
  light1();
  wait(); 
  
  playSong(); 
}

void checkButtonState() {
  int input = digitalRead(5);
  if(input == HIGH && hasDoneSomething == false)
  {
    Serial.println("Was off, now on.");
    buttonState = !buttonState;
    hasDoneSomething = true;
  } else if(input == LOW && hasDoneSomething == true) {
    hasDoneSomething = false;
  }
  
  Serial.print("Button state: ");
  Serial.println(buttonState);
}

void wait() {
  checkButtonState();
  
  while(buttonState) {
    checkButtonState();
  }
  
  delay(getWaitTime());
}
