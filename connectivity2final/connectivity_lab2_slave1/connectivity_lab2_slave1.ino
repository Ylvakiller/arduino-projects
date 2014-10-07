unsigned long lastInterrupt; //when was the last interrupt?
int bitCount = 0; //at what bit are we?
byte bits[100]; //buffer for bits, made really large so that we can send for example 100 bits without needing to change this setup, this takes just over 100 bytes to store (100 data bytes and a couple of location pointers)
int lastValue = 0; //previous value on pin A0
int Value = HIGH; //current value on pin A0
boolean pulling = false;


void setup() {
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(12,INPUT);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(12,HIGH);
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  
  pinMode(A0,INPUT);
  digitalWrite(A0,HIGH);
  pinMode(A1,OUTPUT);
  digitalWrite(A1,LOW);
  
  lastInterrupt = millis();
}

void change() {
  
  /*
  * This is the version that uses the shield that was supplied
  */
  lastValue = Value;                    //store the value of the last itteration, this will be used to detect for a falling or rising edge
  Value = digitalRead(A0);              //get the current value, by comparing this value with the lastValue we can do edge detecting
  unsigned long Interrupt = millis();   //store the current time
  if(Value==HIGH && lastValue == LOW) {   //falling edge
    if(Interrupt-lastInterrupt>=13) {   //Here we have to previously unmentioned variables, interrupt is current time, lastInterrupt is the last falling edge that was detected, this stems from the old program that we made for c where we used this same bus system to send characters
      bitCount=0;                       //Due to the above if statement we know that we just had the sync pulse, we therefore know we are at bit 0 (or the first bits, we decided to start counting with 0 due to the fact that array's also start with 0)
    } 
    else if (Interrupt-lastInterrupt<=12) bitCount++;      //If the difference was not an sync pulse then we increase the bitcount
    
    /*
    * The next four if statements are meant to write bits if the switches are connected.
    * Each checks if its at the correct bit, for the first slave that is the first 4 bits, and checks the status of the switch
    * If the if statement is true, then the bus will be pulled down and a boolean willl become active, this is used to put the bus high again after 6 milliseconds
    */
    if(bitCount==0 && digitalRead(6)==LOW) {
      digitalWrite(A1, HIGH);
      pulling = true;
    }
    if(bitCount==1 && digitalRead(7)==LOW) {
      digitalWrite(A1, HIGH);
      pulling = true;
    }
    if(bitCount==2 && digitalRead(8)==LOW) {
      digitalWrite(A1, HIGH);
      pulling = true;
    }
    if(bitCount==3 && digitalRead(12)==LOW) {
      digitalWrite(A1, HIGH);
      pulling = true;
    }
    
    //This part is to store the time of the last falling edge
    lastInterrupt = Interrupt;
  } 
  else if(Value==LOW && lastValue == HIGH) { //rising edge
    if(Interrupt-lastInterrupt>=4 && Interrupt-lastInterrupt<=8) bits[bitCount] = 1;      //this calculates the time between the falling edge and the rising edge, if this is more then 4 and lower then 8 then we see a 1, otherwise a 0
    else bits[bitCount] = 0;                                                              //we included the lower then 8 since otherwise we might have missed a bit, and to avoid a 1 where it shouldn't be we use a 0
  }
  
  /*
  *This part will turn the bus up if the bus was pulled down for a 1 bit and 6 milliseconds have passed since the last falling edge
  *Also resets the boolean to make sure we do not send it twice
  */
  if(Interrupt - lastInterrupt >= 6 && pulling) {
    digitalWrite(A1, LOW);
    pulling = false; 
  }
}

void loop() {
  
  /*
  * The change method is what both writes bits and reads out all bits.
  */
  change();


/*
* This small part reads out the stored bits from the bus and displays them on the leds, 
* Due to the way the leds are connected we need to set the pin to low in order for an led to turn on (leds on the shield are all connected to a vcc)
*/
  digitalWrite(2, !bits[4]);
  digitalWrite(3, !bits[5]);
  digitalWrite(4, !bits[6]);
  digitalWrite(5, !bits[7]);
  
}

