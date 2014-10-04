
#include <numbers.ino>
#include <drawing.ino>
#include <bombgen.ino>
#include <animations.ino>
#include <TVout.h>

TVout TV;

byte oldcursorX;
byte oldcursorY;

byte input[10] = {0};
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
  TV.begin(PAL,128,96);
  randomSeed(analogRead(A5));
  Serial.begin(9600);
}

void loop(){
  //Serial.println(grid[5][5]);
  byte temp = 0;
  while(temp<10){
    setBombs();
    temp++;
  }
  screen();
  initialGrid();
  while (1){
    draw1(0,0);
    byte x = 0;
    //while (x<13){
    //}
    
    drawCursor(5,9);
  }
}


//Does the cursor moving
void cp(){

}

//sets the default screen, leaving a large blank area where the bombs will be
























