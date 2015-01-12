/*
 Thomas Ring + Alexander Miller
*/

// Pin constants
int LIGHT    = 2;
int BUZZER   = 5;
int LOW_LED  = 6;
int MID_LED  = 9;
int HIGH_LED = 10;
int TOGGLE   = 11;

// Time variables
float millissecondsStartedOutside; // At what millis() did they go outside?
float secondsAllowedOutside = 10;

void setup() {
  millissecondsStartedOutside = -1;
  
  pinMode(LOW_LED, OUTPUT );
  pinMode(MID_LED, OUTPUT );
  pinMode(HIGH_LED, OUTPUT);
  pinMode(TOGGLE, INPUT);
  
  digitalWrite(TOGGLE, HIGH);
  
  displayLow();
  
  Serial.begin(9600);
}

void loop() {
  if(isOutside()) {
    if(millissecondsStartedOutside < 0) {
      Serial.println("User entered outside.");
      playOutside();
      millissecondsStartedOutside = millis();
    }
    if(secondsAllowedOutside/2 <= secondsOutside()) {
      if(secondsAllowedOutside <= secondsOutside()) {
        displayHigh();
      } else {
        displayMid();
      }
    } else {
      displayLow();
    }
  } else {
    if(millissecondsStartedOutside != -1) {
      Serial.print("User was just outside for ");
      printTimeOutside();
      playInside();
      millissecondsStartedOutside = -1;
      
      displayLow();
    }
  }
}

boolean isOutside() {
  if(analogRead(2) > 200) {
    return true;
  }
  return false;
}

/*
  === Functions for calculating how long they've been outside
*/
float millisOutside() {
  if(millissecondsStartedOutside > 0) {
    return millis() - millissecondsStartedOutside;
  }
  return 0;
}

float secondsOutside() {
  return millisOutside()/1000;
}

float minutesOutside() {
  return secondsOutside()/60;
}

void printTimeOutside() {
  int seconds = millisOutside()/1000;
  Serial.print(seconds/60);
  Serial.print("minutes, ");
  Serial.print(seconds%60);
  Serial.print("seconds.");
}

/*
  === Display functions for low, medium, and high levels of skin damage.
*/
void displayLow() {
  digitalWrite(LOW_LED, HIGH);
  digitalWrite(MID_LED, LOW);
  digitalWrite(HIGH_LED, LOW);
}

void displayMid() {
  digitalWrite(LOW_LED, LOW);
  digitalWrite(MID_LED, HIGH);
  digitalWrite(HIGH_LED, LOW);
}

void displayHigh() {
  digitalWrite(LOW_LED, LOW);
  digitalWrite(MID_LED, LOW);
  digitalWrite(HIGH_LED, HIGH);
}

void flashPin(int pin) {
  
}
