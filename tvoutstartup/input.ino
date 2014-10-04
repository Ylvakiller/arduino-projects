byte Y, Yold, X, Xold
int i = 0;
void storeInput(){
  Xold = X;
  readX();
  if (X!=Xold&&X!=1){
    if (X=0){
      input[i]=1;
      i++;
    }
    else{
      input[i]=2;
      i++;
    }
  }
  
  
  Yold = Y;
  readY();
  if (Y!=Yold&&Y!=1){
    if (Y=0){
      input[i]=3;
      i++;
    }
    else{
      input[i]=4;
      i++;
    }
  }
}

void readX(){
  if(analogRead(A0)<400){
    X = 0;
  }
  else if (analogRead(A0)>600){
    X = 2;
  }
  else{
    X = 1;
  }
}


void readY(){
  if(analogRead(A1)<400){
    Y = 0;
  }
  else if (analogRead(A1)>600){
    Y = 2;
  }
  else{
    Y = 1;
  }
}

byte button(}{
  unsigned long timeStamp;
  boolean temp1 = false;
    boolean temp2 = false;
  while (analogRead(A2)<2){
    timeStamp = millis();
    temp1=true;
  }
  while(millis()-timeStamp<100&&temp&&!temp2){
    if(analogRead(A2)>100){
      temp2 = true;
      timeStamp = millis();
    }
  }
  
}

void clearBuffer(){
  i = 0;
  while (i<10){
    input[i] = 0;
    i++;
  }
  i=0;
}

