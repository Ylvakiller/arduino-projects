#include <input.in>
#include <numbers.ino>
#include <drawing.ino>
#include <bombgen.ino>
#include <animations.ino>
#include <TVout.h>
#include <pollserial.h>
TVout TV;
pollserial pserial;

byte bombsLeft;
byte oldcursorX;
byte oldcursorY;
byte cursorX;
byte cursorY;
unsigned long timeStampInput;
byte input[10] = {
  0};
byte grid[13][13] = {
  0};
//In this grid a 0 means not counted or bombb, a 9 means bomb, a 10 means no bombs are near, spot covered 
//numbers 1 till 8 say how many bombs are near with that spot still covered, 
//11 till 18 say how many bombs are near with that spot exposed
//19 says no bomb near, spot exposed
//20 says no bomb near, area flagged
//21 till 28 say how many bombs are near but area is flagged
//29 is bomb that is flagged
//30 is bomb

void setup(){
  randomSeed(analogRead(A5));
  //Serial.begin(9600);  Do not use serial with the tbout library
  TV.set_hbi_hook(pserial.begin(57600));
  timeStampInput=millis();

}

void loop(){
  byte temp = 0;
  while(temp<50){
    if(setBombs()){
      temp++;
    }

  }

  TV.begin(PAL,128,96);
  screen();
  initialGrid();
  countBombs();
  pserial.println(bombsLeft);
  drawDigit1(1);
  drawDigit2(1);
  while (1){
    drawGen();

  }
}


//Does the cursor moving
void cursorMove(){
  if(oldcursorX=!cursorX||oldcursorY!=cursorY){
    clearCursor(oldcursorX,oldcursorY);
    drawCursor(cursorX,cursorY);
  }
}

void readInput(){
  if(millis()-timeStampInput>200){

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

























