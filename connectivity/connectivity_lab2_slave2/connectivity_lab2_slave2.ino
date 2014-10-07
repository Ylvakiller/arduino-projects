//Reading
unsigned long lastInterrupt; //when was the last interrupt?
int bitCount = 0; //at what bit are we?
byte bits[100]; //buffer for bits
int lastValue = 0; //previous value on pin A0
int Value = HIGH; //current value on pin A0
boolean pulling = false;

//Writing
unsigned long lastSend; //when was the last byte send


void setup() {

  //We had our leds on parts 4 till 7 and our switches on port 8 till 11
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);

  //We had our leds on parts 4 till 7 and our switches on port 8 till 11
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);


  pinMode(A0,INPUT);
  digitalWrite(A0,HIGH);
  pinMode(A1,OUTPUT);
  digitalWrite(A1,LOW);

  lastInterrupt = millis();
}

void change() {
  /*
  * This slave uses our own hardware, for some reason writing is the same, however reading is different, we are directely reading out the bus,
   * This is odd since the shield given and the circuit diagrams are all inverting the bus.
   * We are unsure why this happens, however since it is just a matter of switching the variables in the rising edge and falling edge if statements its not much of a problem.
   * This means that in order to check for a falling edge we are looking at when the value goes from high to low, that is pin value.
   * in the shield we have to look for the change from low to high for a falling edge, this because the bus is inverted on that circuit
   */
  lastValue = Value;                    //store the value of the last itteration, this will be used to detect for a falling or rising edge
  Value = digitalRead(A0);              //get the current value, by comparing this value with the lastValue we can do edge detecting
  unsigned long Interrupt = millis();    //store the current time
  if(Value==LOW && lastValue == HIGH) {//falling edge
    if(Interrupt-lastInterrupt>=13) {    //Here we have to previously unmentioned variables, interrupt is current time, lastInterrupt is the last falling edge that was detected, this stems from the old program that we made for c where we used this same bus system to send characters
      bitCount=0;                        //Due to the above if statement we know that we just had the sync pulse, we therefore know we are at bit 0 (or the first bits, we decided to start counting with 0 due to the fact that array's also start with 0)
    } 
    else if (Interrupt-lastInterrupt<=12) bitCount++;  //If the difference was not an sync pulse then we increase the bitcount


    /*
    * The next four if statements are meant to write bits if the switches are connected.
     * Each checks if its at the correct bit, for the second slave that is the last 4 bits, and checks the status of the switch
     * If the if statement is true, then the bus will be pulled down and a boolean willl become active, this is used to put the bus high again after 6 milliseconds
     */
    if(bitCount==4 && digitalRead(8)==LOW) {
      digitalWrite(A1, HIGH);
      pulling = true;
    }
    if(bitCount==5 && digitalRead(9)==LOW) {
      digitalWrite(A1, HIGH);
      pulling = true;
    }
    if(bitCount==6 && digitalRead(10)==LOW) {
      digitalWrite(A1, HIGH);
      pulling = true;
    }
    if(bitCount==7 && digitalRead(11)==LOW) {
      digitalWrite(A1, HIGH);
      pulling = true;
    }

    //This part is to store the time of the last falling edge
    lastInterrupt = Interrupt;
  } 
  else if(Value==HIGH && lastValue == LOW) { //rising edge
    if(Interrupt-lastInterrupt>=4 && Interrupt-lastInterrupt<=8) bits[bitCount] = 1; //this calculates the time between the falling edge and the rising edge, if this is more then 4 and lower then 8 then we see a 1, otherwise a 0
    else bits[bitCount] = 0;                                                         //we included the lower then 8 since otherwise we might have missed a bit, and to avoid a 1 where it shouldn't be we use a 0
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
   * The leds that we connected without the shield were all connected to the same ground
   */
  digitalWrite(4, bits[0]);
  digitalWrite(5, bits[1]);
  digitalWrite(6, bits[2]);
  digitalWrite(7, bits[3]);

}


