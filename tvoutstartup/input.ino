byte Y, Yold, X, Xold
int i = 0;
void storeInput(){
  readX();
  if (X!=Xold&&X!=1){
    if (X=0){
      input
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


void storeNextBuffer(byte input){
  
}

void clearBuffer(){
  i = 0;
  while (i<10){
    input[i] = 0;
    i++;
  }
  i=0;
}
