boolean boolean_aan = false;
int degree = 15;
String input = "";

void setup()
{
 noInterrupts();
  //Timer1
  TCCR1A = 0;
  TCCR1B = 0;
  OCR1A = 0;
  OCR1B = 0;
  ICR1 = 0;
  TIMSK1 = 0;
  TIFR1 = 0;
  
  TCNT1 = 1;            // preload timer 65536-16MHz/256/2Hz
  TCCR1B |= (1 << CS11);    // 8 prescaler for Timer1
  TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
  interrupts();             // enable all interrupts
  
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  Serial.println("Current servo angle:");
}

ISR(TIMER1_OVF_vect) {
  TIFR1 = 0;
  if(boolean_aan) {
    TCNT1 = 2*(degree*9.51+503);
    digitalWrite(9,HIGH);
    boolean_aan = false;
  } else {
    TCNT1 = 2*(20000-degree*9.51+503);
    digitalWrite(9,LOW);
    boolean_aan = true;
  }
}

void loop()
{
  if(Serial.available()) {
    input += (char)Serial.read();
    if(input.indexOf('\n')!=-1) {
      degree = input.toInt();
      Serial.print(degree);
      Serial.println(" deg");
      input = "";
    }
  }
}

