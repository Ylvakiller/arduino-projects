//Reading
unsigned long lastInterrupt; //when was the last interrupt?
int bitCount = 0; //at what bit are we?
byte bits[100]; //buffer for bits
int lastValue = 0; //previous value on pin A0
int Value = HIGH; //current value on pin A0
boolean byteReady = false; //Is the pulse train ready?

unsigned long lastSend; //when was the last byte send
boolean pulling = false;
boolean functionSwitch = false;

void setup() {
  pinMode(A0,INPUT);
  digitalWrite(A0,HIGH);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(A0,HIGH);
  pinMode(2,INPUT);
  digitalWrite(2,HIGH);
  pinMode(A1,OUTPUT);
  digitalWrite(A1,LOW);
  lastInterrupt = millis();
}

void change() {
  lastValue = Value;                       //store the value of the last itteration, this will be used to detect for a falling or rising edge
  Value = digitalRead(A0);                 //get the current value, by comparing this value with the lastValue we can do edge detecting
  unsigned long Interrupt = millis();      //store the current time
  if(Value==LOW && lastValue == HIGH) { //falling edge
    if(Interrupt-lastInterrupt>=13) {      //Here we have to previously unmentioned variables, interrupt is current time, lastInterrupt is the last falling edge that was detected, this stems from the old program that we made for c where we used this same bus system to send characters
      bitCount=0;                          //Due to the above if statement we know that we just had the sync pulse, we therefore know we are at bit 0 (or the first bits, we decided to start counting with 0 due to the fact that array's also start with 0)
    } 
    else if (Interrupt-lastInterrupt<=12) bitCount++;  //If the difference was not an sync pulse then we increase the bitcount
    
    //This will set our bit (the first one) to 1 if the switch is connected, it'll pull the bus down and notify the next part of the program that we are pulling, this comes back in a future if statement, this is also documented
    if(bitCount==0 && digitalRead(9)==LOW) {
      digitalWrite(A1, HIGH);
      pulling = true;
    }
    
    //This part is to store the time of the last falling edge
    lastInterrupt = Interrupt;
  } 
  else if(Value==HIGH && lastValue == LOW) { //rising edge
    if(Interrupt-lastInterrupt>=4 && Interrupt-lastInterrupt<=8) bits[bitCount] = 1;   //this calculates the time between the falling edge and the rising edge, if this is more then 4 and lower then 8 then we see a 1, otherwise a 0
    else bits[bitCount] = 0;                                                           //we included the lower then 8 since otherwise we might have missed a bit, and to avoid a 1 where it shouldn't be we use a 0
    
    //Notify the loop that we have recieved a complete bus train and we cans tart processing it
    if(bitCount == 23) {
      byteReady = true;
    }
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
  * This first reads out the bus, this means we have an array of 24 bits, this is just the raw array, we use the status switch to switch between the clock and counter
  */
  change();
  functionSwitch = digitalRead(8);  //the function switch that switches between clock and counter
  if(byteReady) {                   //This iff statement is only true when we are not reading the array, meaning that we have stored 24 bits. this means we are now after the last bit but before the first one, most likely in the sync, however we dont have to be here, might be just before
    if(functionSwitch) {            //read out what we have to do, if this is true then we will show the clock, otherwise we will 
      for(int i = 0; i<4; i++) {
        digitalWrite(2+i, bits[20+i]);    //write the last 4 bits to the leds on pin 2 till 5 which are the leds
      }
    } else {
      int total = 0;
      for(int i = 0; i<16; i++) {        // count the amount of bits that are 1 in the first 16 bits
        total += bits[i];
      }
      for(int i = 0; i<4; i++) {        
        digitalWrite(2+i, bitRead(total,i));    // take the bits from the total and display them on the leds.
      }
    }

    byteReady = false;      //notify the rest that we have processed the values from 1 full pulse train.
  }
}

