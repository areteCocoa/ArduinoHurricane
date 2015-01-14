int BUTTON_PIN = 5;
boolean buttonState = false;
boolean hasDoneSomething = true;
int buttonLevel = 0;
boolean musicOn;
boolean lightsOn;

/*
  Starts/stops the program
*/
void checkSwitchState() {
  int input = digitalRead(BUTTON_PIN);
  if(input == HIGH && hasDoneSomething == false)
  {
    Serial.println("Was off, now on.");
    
    buttonLevel = changeButtonLevel();
    
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

int changeButtonLevel(){
    // how to make sure the button only activates the correct
    // functions throughout the entire program.
    // 0 = Both Lights and music on 
    // 1 = Lights only on
    // 2 = Music only off
    // 3 = Both off
    
    switch(buttonLevel) {
      case 0:
        musicOn = false;      // Lights only
        lightsOn = true;
        return 1;
      case 1:
        musicOn = true;       // Music only
        lightsOn = false;
        return 2;
      case 2:
        musicOn = false;      // Both off
        lightsOn = false;
        return 3;
      case 3:
        musicOn = true;       //Both on
        lightsOn = true;
         return 0;
  }
  return 0;
}

void checkButtonState() {
  
}
