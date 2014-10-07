void setup() {
  pinMode(A1,OUTPUT);
  digitalWrite(A1,HIGH);
}


void loop() {
                                      
      delay(15);                      //Sync delay, due to the fact that the for loop will end with a high there is no need to write a high singnal here
                                      // Switch between high and low for an idle pulse train of 2 down 7 up
      for(int i = 0; i < 8; i++) {
        digitalWrite(A1, HIGH);      //Pull signal low
          delay(2);
          digitalWrite(A1,LOW);      //Set signal high again
          delay(7);
      }
    
}
