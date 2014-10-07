//Reading
unsigned long lastInterrupt; //when was the last interrupt?
int bitCount = 0; //at what bit are we?
byte bits[100]; //buffer for bits
int lastValue = 0; //previous value on pin 2
int Value = HIGH; //current value on pin 2
boolean byteReady = false; //Is the next char ready?
String unprintedChars = ""; 
byte buttons[8];
boolean pulling = false;

//Writing
unsigned long lastSend; //when was the last byte send


void setup() {
  pinMode(A0,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(A0,HIGH);

  digitalWrite(2, HIGH);

  digitalWrite(3, HIGH);

  digitalWrite(4, HIGH);

  digitalWrite(5, HIGH);
  pinMode(A1,OUTPUT);
  digitalWrite(A1,LOW);
  buttons[0] = 1;
  buttons[1] = 1;
  buttons[2] = 1;
  buttons[3] = 1;
  buttons[4] = 1;
  buttons[5] = 1;
  buttons[6] = 1;
  buttons[7] = 1;
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
    if(bitCount==0 && digitalRead(8)==LOW) {
      digitalWrite(A1, HIGH);
      pulling = true;
    }
    if(bitCount==1 && digitalRead(9)==LOW) {
      digitalWrite(A1, HIGH);
      pulling = true;
    }
    if(bitCount==2 && digitalRead(10)==LOW) {
      digitalWrite(A1, HIGH);
      pulling = true;
    }
    if(bitCount==3 && digitalRead(11)==LOW) {
      digitalWrite(A1, HIGH);
      pulling = true;
    }
    
    lastInterrupt = Interrupt;
  } 
  else if(Value==HIGH && lastValue == LOW) { //rising edge
    if(Interrupt-lastInterrupt>=4 && Interrupt-lastInterrupt<=8) bits[bitCount] = 1;
    else bits[bitCount] = 0;
  }
  
  if(Interrupt - lastInterrupt >= 6 && pulling) {
    digitalWrite(A1, LOW);
    pulling = false; 
  }
}

void loop() {
  buttons[0] = digitalRead(8);
  buttons[1] = digitalRead(9);
  buttons[2] = digitalRead(10);
  buttons[3] = digitalRead(11);
  
  change();

  digitalWrite(4, bits[4]);
  digitalWrite(5, bits[5]);
  digitalWrite(6, bits[6]);
  digitalWrite(7, bits[7]);
  
}

