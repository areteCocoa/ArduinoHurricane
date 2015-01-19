// This program takes 3 different lights and lights them in 
// ascending order based on the time delay. 
// They strobe back and forth. Once the light "reaches" 
// a side, they will play a song

// global variables
float delayTime;
float modifier;

/*
* Need to define:
* 1. Delay time - how much time each light will take to show each other.
* 2. The dynamic multiplier for the delay time.
* 3. Set the pins 10, 9, and 6 to LED. Set pin 11 to Buzzer.
*/
void setup()
{
  delayTime = 2000;
  modifier = 0.5;
  pinMode( 10 , OUTPUT);
  pinMode( 9, OUTPUT );
  pinMode( 6, OUTPUT);
  pinMode( 11, OUTPUT);
}

// pin 6
void light1()
{
  digitalWrite( 10 , HIGH );
  digitalWrite( 9, LOW);
  digitalWrite( 6, LOW);
}

// pin 9
void light2()
{
  digitalWrite( 10 , LOW );
  digitalWrite( 9, HIGH);
  digitalWrite( 6, LOW);
}

// pin 10
void light3()
{
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
  tone(11, 260, 175);
  delay(200);
}

// The main of the program. Plays lights
// 1,2,3 and buzzer tune when the light reaches
// 1 and 3.
void loop()
{
  
  light1();
  delay( delayTime );
  
  light2();
  delay( delayTime );
  
  light3();
  delay( delayTime );
  
  playSong();

  adjust(); 
 
  light3();
  delay( delayTime );
  
  light2();
  delay( delayTime );
  
  light1();
  delay( delayTime ); 
  
  playSong(); 
}
