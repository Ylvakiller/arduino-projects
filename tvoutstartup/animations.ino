unsigned long time;

void startTime(){
  time = millis();
}

void cursorBlink(byte x, byte y){
  if (bitRead(millis()-time, 0)==1){
    clearCursor(x,y);
  }
  else{
    drawCursor(x,y);
  }
}

