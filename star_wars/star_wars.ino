float octave;

void setup()
{
  octave = 1;
}

void loop()
{
  /*
  tone(16, 261, 1000);
  delay(200);
  tone(16, 293, 1000);
  delay(200);
  tone(16, 329, 1000);
  delay(200);
  tone(16, 349, 1000);
  delay(200);
  tone(16, 392, 1000);
  delay(200);
  tone(16, 440, 1000);
  delay(200);
  tone(16, 493, 1000);
  delay(200);
  */
  
  float triplet = 150;
  float quarter = triplet * 3;
  float half = quarter * 2;
  
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
  
  noTone(16);
  delay(600000);
  
  octave = octave*2;
  
  if(octave > 3) {
    octave = 0.125;
    delay(600000);
  }
}
