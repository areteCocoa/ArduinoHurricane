/*
Created by Thomas Ring and Alexander Miller, 2015
*/

// Pin Constants
const int LED_ONE = 5;
const int LED_TWO = 6;
const int BUTTON = 9;
const int LIGHT = 2; // A2

// Other constants
const int DARK_THRESHOLD = 150; // what sensor reading is "dark"?

void setup() {
  pinMode(LED_ONE, OUTPUT);
  pinMode(LED_TWO, OUTPUT);
  pinMode(BUTTON,  INPUT);
  digitalWrite(BUTTON, HIGH);
  
}

void loop() {
  // Light LED
  if(analogRead(LIGHT) < DARK_THRESHOLD) {
    // It's dark
    digitalWrite(LED_ONE, HIGH);
  } else {
    // It's not dark
    digitalWrite(LED_TWO, LOW);
  }
  
  // Set to on if on, off if off.
  digitalWrite(LED_TWO, digitalRead(BUTTON));
}
