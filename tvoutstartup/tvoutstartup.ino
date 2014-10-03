

#include <TVout.h>

TVout TV;

byte oldcursorX;
byte oldcursorY;


byte grid[13][13] = {10};
//In this grid a 10 means not initialised, a 9 means bomb, a 0 means no bombs are near, numbers 1 till 8 say how many bombs are near
//Any number other then 9 is not a bomb

void setup(){
  TV.begin(PAL,128,96);
  randomSeed(analogRead(A5));
  Serial.begin(9600);
}

void loop(){
  
  setBombs();
  
  while (1){
    
  screen();
    initialGrid();
  drawEmpty(3,10);
  drawFlag(2,10);
  }
}


//Does the cursor moving
void cp(){

}

//sets the default screen, leaving a large blank area where the bombs will be
void screen(){
  TV.draw_line(0,0,95,0, WHITE);
  TV.draw_line(0,0,0,95, WHITE);
  TV.draw_line(0,95,95,95, WHITE);
  TV.draw_line(95,0,95,95, WHITE);
  TV.draw_line(96,0,127,0, WHITE);
  TV.draw_line(96,0,96,95, WHITE);
  TV.draw_line(96,95,127,95, WHITE);
  TV.draw_line(127,0,127,95, WHITE);
}

//Draws the initial grid
void initialGrid(){
  byte x = 0;
  byte y = 0;
  while (x<13){
    while (y<13){
      drawSquare(x,y);
      y++;
    }
    x++;
    y = 0;
  }

}

// first square should be 0,0
void drawSquare(byte x, byte y){
  TV.draw_rect(((x*7)+3),((y*7)+3),5,5, 1, 1);
}

void drawEmpty(byte x, byte y){
  TV.draw_rect(((x*7)+3),((y*7)+3),5,5, 0, 0);
  TV.set_pixel(((x*7)+5),((y*7)+5), WHITE);
  TV.set_pixel(((x*7)+6),((y*7)+5), WHITE);
  TV.set_pixel(((x*7)+5),((y*7)+6), WHITE);
  TV.set_pixel(((x*7)+6),((y*7)+6), WHITE);
}

void drawFlag(byte x, byte y){
  TV.draw_rect(((x*7)+3),((y*7)+3),5,5, 0, 0);
  TV.draw_line(((x*7)+3), ((y*7)+8), ((x*7)+9), ((y*7)+8), WHITE);
  TV.draw_line(((x*7)+5), ((y*7)+3), ((x*7)+5), ((y*7)+8), WHITE);
  TV.draw_line(((x*7)+6), ((y*7)+4), ((x*7)+6), ((y*7)+5), WHITE);
  TV.set_pixel(((x*7)+7), ((y*7)+5), WHITE);
}


void drawCursor(byte x, byte y){
}


void clearCursor(byte x, byte y){
}


void setBombs(){
  byte x = random(0,13);
  byte y = random(0,13);
  if(grid[x][y]==10){
    grid[x][y]==9;
  }

}






