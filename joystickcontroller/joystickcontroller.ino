boolean sw;
byte X, Y, Xold, Yold;

void setup(){
  Serial.begin(9600);
  pinMode(A2, INPUT);
  pinMode(A1, INPUT);
  X=0;
  Y=0;
  Xold = 0;
  Yold = 0;
}

void loop(){
  Xold = X;
  Yold = Y;
  if (analogRead(A2)>100&&sw){
    Serial.println("not pressed");
    Serial.println(analogRead(A2));
    sw = false;
  }
  else if (analogRead(A2)<2&&!sw){
    Serial.println("pressed");
    Serial.println(analogRead(A2));
    sw = true;
  }
  
  Serial.println(analogRead(A1));
  if(analogRead(A1)<400){
    Y = 0;
  }
  else if (analogRead(A1)>600){
    Y = 2;
    Serial.println("High");
  }
  else{
    Y = 1;
  }

  if (Yold==!Y){
    switch (Y){
    case 0:
      Serial.println("Down");
      break;
    case 1:
      Serial.println("Let go Y");
      break;
    case 2:
      Serial.println("Up");
      break;

    }
  }
  
  
  delay(5);

}





