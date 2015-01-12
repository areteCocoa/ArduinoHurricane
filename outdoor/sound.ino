int SOUND_PIN = 5;

void playIntro() {
  tone(SOUND_PIN, 392, 100);
  delay(100);
  tone(SOUND_PIN, 494, 100);
  delay(100);
  tone(SOUND_PIN, 294*2, 100);
  delay(100);
  tone(SOUND_PIN, 392*2, 100);
  delay(100);
}

void playPause() {
  tone(SOUND_PIN, 392*2, 100);
  delay(100);
  tone(SOUND_PIN, 294*2, 100);
  delay(100);
}

void playStart() {
  tone(SOUND_PIN, 294*2, 100);
  delay(100);
  tone(SOUND_PIN, 392*2, 100);
  delay(100);
}

void playOutside() {
  tone(SOUND_PIN, 294*2, 100);
  delay(100);
  tone(SOUND_PIN, 392*2, 100);
  delay(100);
}

void playInside() {
  tone(SOUND_PIN, 392*2, 100);
  delay(100);
  tone(SOUND_PIN, 294*2, 100);
  delay(100);
}
