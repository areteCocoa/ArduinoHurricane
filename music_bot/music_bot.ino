void setup() {
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
}

void loop() {
  if(digitalRead(5) == LOW) {
    play(frequencyForPin(5));
  } else if(digitalRead(6) == LOW) {
    play(frequencyForPin(6));
  } else if(digitalRead(9) == LOW) {
    play(frequencyForPin(9));
  } else if(digitalRead(10) == LOW) {
    play(frequencyForPin(10));
  }
}

void play(float frequency) {
  tone(19, frequency, 3);
}

float frequencyForPin(int pin) {
  switch(pin) {
    case 5:
      return 392;
    case 6:
      return 494;
     case 9:
      return 294*2;
     case 10:
       return 392*2;
  }
  return 0;
}
