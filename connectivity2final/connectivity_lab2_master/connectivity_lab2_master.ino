
void setup() {
  pinMode(A1,OUTPUT);
  digitalWrite(A1,HIGH);
}


void loop() {
    
    //if(Serial.available()) {
      //make sure its synced
      delay(15);
      //send bits

      for(int i = 0; i < 8; i++) {
        digitalWrite(A1, HIGH); //Pull signal low
          delay(2);
          digitalWrite(A1,LOW);
          delay(6);
      }
    
}
