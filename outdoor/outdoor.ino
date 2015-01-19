/*
 Thomas Ring + Alexander Miller
*/

// Pin constants
const unsigned int LIGHT    = 2;
const unsigned int BUZZER   = 5;
const unsigned int LOW_LED  = 6;
const unsigned int MID_LED  = 9;
const unsigned int HIGH_LED = 10;
const unsigned int TOGGLE   = 11;

// Constant for light
const unsigned int darkThreshold = 50;

// Time variables
int millissecondsStartedOutside; // At what millis() did they go outside?
unsigned int secondsAllowedOutside = 60;
unsigned long lastChime;
const float chimeInterval = 60; // how long inbetween chimes, in seconds

void setup() {
  millissecondsStartedOutside = -1;
  lastChime = 0;
  
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
    // LED Check
    if(secondsAllowedOutside/2 <= secondsOutside()) {
      if(secondsAllowedOutside <= secondsOutside()) {
        displayHigh();
      } else {
        displayMid();
      }
    } else {
      displayLow();
    }
    // song check
    if(lastChime + chimeInterval < secondsOutside()) {
      int chimes = secondsOutside() / chimeInterval;
      int hours = 0;
      if (chimes > 4) { // over an hour, count hours
        while(chimes > 4) {
          chimes -= 4;
          hours++;
        }
      }
      lastChime = secondsOutside();
      playChime(chimes, hours);
    }
  } else {
    if(millissecondsStartedOutside != -1) {
      Serial.print("User was just outside for ");
      printTimeOutside();
      Serial.println();
      playInside();
      millissecondsStartedOutside = -1;
      lastChime = 0;
      
      displayLow();
    }
  }
}

boolean isOutside() {
  if(analogRead(2) > darkThreshold) {
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

/*
  === Chime function ===
  0 = first (15 mins)
  1 = second (30 mins)
  2 = third (45 mins)
  3 = full + hours (60/0 mins)
*/
const int quarter = 500;
void playChime(int interval, int hours) {
  Serial.print("Playing chimes: ");
  Serial.print(interval);
  Serial.print(" ");
  Serial.println(hours);
  if(interval > 0) {
    tone(BUZZER, 659, quarter);
    delay(quarter);
    tone(BUZZER, 523, quarter);
    delay(quarter);
    tone(BUZZER, 587, quarter);
    delay(quarter);
    tone(BUZZER, 392, quarter*2);
    delay(quarter*2);
  }
  if(interval > 1) {
    tone(BUZZER, 392, quarter);
    delay(quarter);
    tone(BUZZER, 587, quarter);
    delay(quarter);
    tone(BUZZER, 659, quarter);
    delay(quarter);
    tone(BUZZER, 523, quarter*2);
    delay(quarter*2);
  }
  if(interval > 2) {
    tone(BUZZER, 659, quarter);
    delay(quarter);
    tone(BUZZER, 587, quarter);
    delay(quarter);
    tone(BUZZER, 523, quarter);
    delay(quarter);
    tone(BUZZER, 392, quarter*2);
    delay(quarter*2);
  }
  if (interval > 3) {
    tone(BUZZER, 392, quarter);
    delay(quarter);
    tone(BUZZER, 587, quarter);
    delay(quarter);
    tone(BUZZER, 659, quarter);
    delay(quarter);
    tone(BUZZER, 523, quarter*2);
    delay(quarter*3);
    for(int count = 0; count < hours; count++){
      chimeHours(hours);
    }
  }
}

void chimeHours(int hours) {
  tone(BUZZER, 523, quarter/2);
  delay((quarter/2)+50);
}
