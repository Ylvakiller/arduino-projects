//Reading
unsigned long lastInterrupt; //when was the last interrupt?
int bitCount = 0; //at what bit are we?
byte bits[100]; //buffer for bits
int lastValue = 0; //previous value on pin 2
int Value = HIGH; //current value on pin 2
boolean byteReady = false; //Is the next char ready?
String unprintedChars = ""; 


//Writing
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
  //attachInterrupt(0,change,CHANGE);
  Serial.begin(9600);
}

void change() {
  lastValue = Value;
  Value = digitalRead(A0);
  unsigned long Interrupt = millis();
  if(Value==LOW && lastValue == HIGH) { //falling edge
    if(Interrupt-lastInterrupt>=13) {
      bitCount=0;
    } 
    else if (Interrupt-lastInterrupt<=12) bitCount++;
    if(bitCount==0 && digitalRead(9)==LOW) {
      digitalWrite(A1, HIGH);
      pulling = true;
    }
    lastInterrupt = Interrupt;
  } 
  else if(Value==HIGH && lastValue == LOW) { //rising edge
    if(Interrupt-lastInterrupt>=4 && Interrupt-lastInterrupt<=8) bits[bitCount] = 1;
    else bits[bitCount] = 0;
    unprintedChars += bits[bitCount];
    if(bitCount == 23) {
      byteReady = true;
    }
  }

  if(Interrupt - lastInterrupt >= 6 && pulling) {
    digitalWrite(A1, LOW);
    pulling = false; 
  }
}

void loop() {
  change();
  functionSwitch = digitalRead(8);
  if(byteReady) {
    if(functionSwitch) {
      for(int i = 0; i<4; i++) {
        digitalWrite(2+i, bits[20+i]);
      }
    } else {
      int total = 0;
      for(int i = 0; i<16; i++) {
        total += bits[i];
      }
      for(int i = 0; i<4; i++) {
        digitalWrite(2+i, bitRead(total,i));
      }
    }

    byteReady = false;
    Serial.println(digitalRead(9));
  }
}

