int BUZZER_PIN = 5;
int LED_ONE = 6;
const int LED_TWO = 9;
int LED_THREE = 10;
int LED_FOUR = 11;

void setup() {
  pinMode(LED_ONE, OUTPUT);
  pinMode(LED_TWO, OUTPUT);
  pinMode(LED_THREE, OUTPUT);
  pinMode(LED_FOUR, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  allOff();
  digitalWrite(LED_ONE, HIGH);
  printNext(LED_ONE);
  delay(250);
  digitalWrite(LED_TWO, HIGH);
  printNext(LED_TWO);
  delay(250);
  digitalWrite(LED_THREE, HIGH);
  printNext(LED_THREE);
  delay(250);
  digitalWrite(LED_FOUR, HIGH);
  printNext(LED_FOUR);
  delay(250);
}

void printNext(int currentPin){
  char next;
  switch(currentPin) {
    case LED_ONE:
      next = '9';
      break;
    case LED_TWO:
      next = '10';
      break;
    case LED_THREE:
      next = '11';
      break;
    case LED_FOUR:
      next = '5';
      break;
  }
  
  
  Serial.print("The next pin is pin ");
  Serial.print();
  Serial.println(".");
}

void allOff() {
  digitalWrite(LED_ONE, LOW);
  digitalWrite(LED_TWO, LOW);
  digitalWrite(LED_THREE, LOW);
  digitalWrite(LED_FOUR, LOW);
}

void playSong() {
  float triplet = 150;
  float quarter = triplet * 3;
  float half = quarter * 2;
  int octave = 1;
  
  triplet -= 5;
  quarter -= 5;
  half -= 5;
  
  // pickup
  tone(16, 587*octave, 145);
  ;
  delay(triplet + 5);
  tone(16, 587*octave, 145);
  ;
  delay(triplet + 5);
  tone(16, 587*octave, 145);
  ;
  
  // measure 1
  delay(triplet + 5);
  tone(16, 783*octave, half);
  ;
  delay(half + 5);
  tone(16, 587*2*octave, half);
  ;
  delay(half + 5);
  
  // measure 2
  tone(16, 523*2*octave, triplet);
  delay(triplet + 5);
  tone(16, 987*octave, triplet);
  delay(triplet + 5);
  tone(16, 880*octave, triplet);
  delay(triplet + 5);
  
  tone(16, 783*2*octave, half);
  delay(half + 5);
  
  tone(16, 587*2*octave, quarter);
  delay(quarter + 5);
  
  // measure 4
  tone(16, 523*2*octave, triplet);
  delay(triplet + 5);
  tone(16, 987*octave, triplet);
  delay(triplet + 5);
  tone(16, 880*octave, triplet);
  delay(triplet + 5);
  
  tone(16, 783*2*octave, half);
  delay(half + 5);
  
  tone(16, 587*2*octave, quarter);
  delay(quarter + 5);
  
  // last measure
  tone(16, 523*2*octave, triplet);
  delay(triplet + 5);
  tone(16, 493*2*octave, triplet);
  delay(triplet + 5);
  tone(16, 523*2*octave, triplet);
  delay(triplet + 5);

  tone(16, 880*octave, half);
  delay(half + 5);  
}
