
#include <numbers.ino>
#include <drawing.ino>
#include <bombgen.ino>
#include <animations.ino>
#include <TVout.h>
TVout TV;

#include <pollserial.h>
pollserial pserial;

byte cursorX;
byte cursorY;
byte cposX;
byte cposY;
byte bombsLeft;
unsigned long timestamp;

byte grid[13][13] = {
  0};
//In this grid a 0 means not counted or bombb, a 9 means bomb, a 10 means no bombs are near, spot covered 
//numbers 1 till 8 say how many bombs are near with that spot still covered, 
//11 till 18 say how many bombs are near with that spot exposed
//19 says no bomb near, spot exposed
//20 says no bomb near, area flagged
//21 till 28 say how many bombs are near but area is flagged
//29 is bomb that is flagged
//30 is bomb that is exposed

void setup(){
  randomSeed(analogRead(A5));
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  cursorY=1;
  cursorX=1;
  cposX=0;
  cposY=0;
  TV.set_hbi_hook(pserial.begin(57600));
}

void loop(){
  byte temp = 0;
  while(temp<10){
    if(setBombs()){
      temp++; 
    }
  }
  TV.begin(PAL,128,96);
  screen();
  initialGrid();
  countBombs();
  drawDigit2(0);
  boolean temp1=false;
  boolean temp2 = false;
  unsigned long oldTimeStamp;
  while (1){
    //drawGen();

    getCursorMovement();
    if (button()){
      if(millis()-oldTimeStamp<400){    //long press
      
      }else{                            //short press

      }
    }
  }
}


/*
int freeRam () {
 extern int __heap_start, *__brkval; 
 int v; 
 return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
 }
 */
//sets the default screen, leaving a large blank area where the bombs will be

void moveCursorLeft(){
  clearCursor(cposX,cposY);
  if(cposX==0){
    cposX=12;
  }
  else{
    cposX--;
  }
  drawCursor(cposX,cposY);
}

void moveCursorRight(){
  clearCursor(cposX,cposY);  
  if(cposX==12){
    cposX=0;
  }
  else{
    cposX++;
  }
  drawCursor(cposX,cposY);

}

void moveCursorUp(){
  clearCursor(cposX,cposY);  
  if(cposY==0){
    cposY=12;
  }
  else{
    cposY--;
  }
  drawCursor(cposX,cposY);
}

void moveCursorDown(){
  clearCursor(cposX,cposY);  
  if(cposY==12){
    cposY=0;
  }
  else{
    cposY++;
  }
  drawCursor(cposX,cposY);
}



void getCursorMovement(){
  byte oldCursorX = cursorX;
  byte oldCursorY = cursorY;
  int temp = analogRead(A0);
  if(temp<200){
    cursorX = 0;
  }
  else if (temp>400&&temp<600){
    cursorX=1;
  }
  else if (temp>900){
    cursorX=2;
  }

  temp = analogRead(A1);
  if(temp<200){
    cursorY = 0;
  }
  else if (temp>400&&temp<600){
    cursorY=1;
  }
  else if (temp>900){
    cursorY=2;
  }

  if(oldCursorX!=cursorX){
    if(cursorX==0){
      moveCursorLeft();
    }
    else if(cursorX==2){
      moveCursorRight();
    }
  }


  if(oldCursorY!=cursorY){
    if(cursorY==0){
      moveCursorUp();
    }
    else if(cursorY==2){
      moveCursorDown();
    }
  }
}

boolean button(){
  int temp = analogRead(A2);
  if(temp<10){
    drawDigit2(1);
    return true;
  }
  else if(temp>100){
    drawDigit2(0);
    timestamp=millis();
    return false;
  }
}

