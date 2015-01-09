// first idea
float delayTime;
float modifier;

void setup()
{
  delayTime = 2000;
  modifier = 0.5;
  pinMode( 10 , OUTPUT);
  pinMode( 9, OUTPUT );
}

void loop()
{
  digitalWrite( 10 , HIGH );
  digitalWrite( 9, LOW);
  digitalWrite( 6, LOW);
  delay( delayTime );
  digitalWrite( 10 , LOW );
  digitalWrite( 9, HIGH);
  digitalWrite( 6, LOW);
  delay( delayTime );
  digitalWrite( 10 , LOW );
  digitalWrite( 9, LOW);
  digitalWrite( 6, HIGH);
  delay( delayTime );
  
  if(delayTime <= 75) {
    modifier = 2;
  } else if(delayTime >= 500) {
    modifier = 0.5;
  }
  delayTime = delayTime * modifier;
}



