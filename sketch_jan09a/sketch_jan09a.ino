// This program takes a light sensor and translates the 
// value received via analog input and translates it to 
// a buzzer. The switch cases at the bottom allow for more
// "auto-tunning"

void setup()
{
  pinMode( 5, OUTPUT);
  pinMode( 6, OUTPUT);
  pinMode( 9, OUTPUT);
  //pinMode( 10,OUTPUT); 
  Serial.begin(9600);
}

void loop()
{
  float frequency = frequencyForValue(analogRead(2));
  Serial.println(frequency);
  
  tone( 10, frequency, 195);
  delay(200);
  
  /*
  digitalWrite( 6, LOW);
  digitalWrite( 5, HIGH);
  delay(getWaitTime());
  digitalWrite( 5, LOW);
  digitalWrite( 6, HIGH);
  delay(getWaitTime());
  digitalWrite( 6, LOW);
  digitalWrite( 9, HIGH);
  delay(getWaitTime());
  digitalWrite( 9, LOW);
  digitalWrite( 6, HIGH);
  delay(getWaitTime());
  */
  
  /*
  float lightValue = analogRead(2);
  
  int secondsRunning = millis()/1000;
  int minutesRunning = secondsRunning / 60;
  secondsRunning = secondsRunning % 60;
  
  if (lightValue > 200) {
    digitalWrite( 5, HIGH );
  } else {
    digitalWrite( 5, LOW );
  }
  /*
  if ((int)timeRunning % 2 == 0) {
    digitalWrite(5, HIGH);
  } else {
    digitalWrite(5, LOW);
  }
  */
  
  /*
  Serial.print(timeRunning);
  
  
  Serial.print( ": Analog reading:" );
  Serial.print(" ");
  Serial.print( lightValue );
  Serial.print("\n");
  delay( 1000 );
  */
  
  
}

float getWaitTime() {
  float waitTime = (5000 / analogRead(2));
  Serial.print( waitTime );
  Serial.println();
  return waitTime;
}

float frequencyForValue(float value) {
  int fixedValue = value/100;
  float baseFreq;
  
  switch (fixedValue) {
    case 1:
      baseFreq = 32.7;
      break;
    case 2:
      baseFreq = 36.7;
      break;
    case 3:
      baseFreq = 41.2;
      break;
    case 4:
      baseFreq = 43.7;
      break;
    case 5:
      baseFreq = 49;
      break;
    case 6:
      baseFreq = 55;
      break;
    case 7:
      baseFreq = 61.7;
  }
  
  return baseFreq * 6;
}
