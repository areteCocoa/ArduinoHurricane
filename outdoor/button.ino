int BUTTON_PIN = 5;
boolean buttonState = false;
boolean hasDoneSomething = true;

/*
  Starts/stops the program
*/
void checkSwitchState() {
  int input = digitalRead(BUTTON_PIN);
  if(input == HIGH && hasDoneSomething == false)
  {
    Serial.println("Was off, now on.");
    buttonState = !buttonState;
    hasDoneSomething = true;
    if(buttonState == true) {
      playPause();
    } else {
      playStart();
    }
  } else if(input == LOW && hasDoneSomething == true) {
    hasDoneSomething = false;
  }
  
  Serial.print("Button state: ");
  Serial.println(buttonState);
  if(buttonState == false) {
    checkSwitchState(); // if it's not on, it halts the program through recursion
  }
}

void checkButtonState() {
  
}
