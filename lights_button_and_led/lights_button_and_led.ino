/*
Created by Thomas Ring and Alexander Miller, 2015
*/

// Pin Constants
const int LED_ONE = 5; // LIGHT
const int LED_TWO = 6; // BUTTON
const int BUTTON = 9;
const int LIGHT = 2; // A2

// Other constants
const int DARK_THRESHOLD = 35; // what sensor reading is "dark"?

void setup() {
  pinMode(LED_ONE, OUTPUT);
  pinMode(LED_TWO, OUTPUT);
  pinMode(BUTTON,  INPUT);
  digitalWrite(BUTTON, HIGH);
  Serial.begin(9600);
}

void loop() {
  // Light LED
  Serial.println(analogRead(LIGHT));
  if(analogRead(LIGHT) < DARK_THRESHOLD) {
    // It's dark
    digitalWrite(LED_ONE, HIGH);
  } else {
    // It's not dark
    digitalWrite(LED_ONE, LOW);
  }
  
  // Set to on if on, off if off.
  digitalWrite(LED_TWO, abs(1 -digitalRead(BUTTON)));
}
