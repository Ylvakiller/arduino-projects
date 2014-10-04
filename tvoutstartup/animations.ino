unsigned long time;

void startTime(){
  time = millis();
}

void cursorBlink(byte x, byte y){
  if (((millis()-time)/1000)>2){
    clearCursor(x,y);
  }
  else if (((millis()-time)/1000)>4){
    startTime();
  }else{
    drawCursor(x, y);
  }
}

