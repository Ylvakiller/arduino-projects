

#include <TVout.h>

TVout TV;

byte oldcursorX;
byte oldcursorY;


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
    draw1(0,1);

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


void clearSquare(byte x, byte y){
  if (TV.get_pixel(((x*7)+3),((y*7)+3))==1){
    TV.draw_rect(((x*7)+3),((y*7)+3),5,5, 0, 0);
  }
}


void drawSquare(byte x, byte y){
  TV.draw_rect(((x*7)+3),((y*7)+3),5,5, 1, 1);
}

void drawEmpty(byte x, byte y){
  clearSquare(x,y);
  TV.set_pixel(((x*7)+5),((y*7)+5), WHITE);
  TV.set_pixel(((x*7)+6),((y*7)+5), WHITE);
  TV.set_pixel(((x*7)+5),((y*7)+6), WHITE);
  TV.set_pixel(((x*7)+6),((y*7)+6), WHITE);
}

void drawFlag(byte x, byte y){
  clearSquare(x,y);

  TV.draw_line(((x*7)+3), ((y*7)+8), ((x*7)+9), ((y*7)+8), WHITE);
  TV.draw_line(((x*7)+5), ((y*7)+3), ((x*7)+5), ((y*7)+8), WHITE);
  TV.draw_line(((x*7)+6), ((y*7)+4), ((x*7)+6), ((y*7)+5), WHITE);
  TV.set_pixel(((x*7)+7), ((y*7)+5), WHITE);
}


void drawCursor(byte x, byte y){
}


void clearCursor(byte x, byte y){
}

//((x*7)+3),((y*7)+3)
void draw1(byte x, byte y){
  clearSquare(x,y);
  TV.draw_line(((x*7)+5),((y*7)+3), ((x*7)+5),((y*7)+8), WHITE);
  TV.draw_line(((x*7)+6),((y*7)+3), ((x*7)+6),((y*7)+8), WHITE);
  TV.set_pixel(((x*7)+4),((y*7)+4), WHITE);
  TV.set_pixel(((x*7)+4),((y*7)+8),WHITE);
  TV.set_pixel(((x*7)+7),((y*7)+8),WHITE);
}

void draw2(byte x, byte y){
  clearSquare(x,y);
  TV.set_pixel(((x*7)+3),((y*7)+4), WHITE);
  TV.draw_line(((x*7)+4),((y*7)+3),((x*7)+6),((y*7)+3), WHITE);
  TV.draw_line(((x*7)+7),((y*7)+4),((x*7)+7),((y*7)+5), WHITE);
  TV.draw_line(((x*7)+5),((y*7)+6),((x*7)+6),((y*7)+6), WHITE);
  TV.set_pixel(((x*7)+4),((y*7)+7), WHITE);
  TV.draw_line(((x*7)+4),((y*7)+8),((x*7)+7),((y*7)+8), WHITE);
}

void draw3(byte x, byte y){
  clearSquare(x,y);
  TV.set_pixel(((x*7)+7),((y*7)+4), WHITE);
  TV.set_pixel(((x*7)+7),((y*7)+6), WHITE);
  TV.set_pixel(((x*7)+7),((y*7)+7), WHITE);
  TV.draw_line(((x*7)+4),((y*7)+3),((x*7)+6),((y*7)+3), WHITE);
  TV.draw_line(((x*7)+4),((y*7)+5),((x*7)+6),((y*7)+5), WHITE);
  TV.draw_line(((x*7)+4),((y*7)+8),((x*7)+6),((y*7)+8), WHITE);
}

void draw4(byte x, byte y){
  clearSquare(x,y);
  TV.draw_line(((x*7)+4),((y*7)+3),((x*7)+4),((y*7)+6), WHITE);
  TV.draw_line(((x*7)+7),((y*7)+3),((x*7)+7),((y*7)+8), WHITE);
  TV.set_pixel(((x*7)+5),((y*7)+6), WHITE);
  TV.set_pixel(((x*7)+5),((y*7)+6), WHITE);
}

void draw5(byte x, byte y){
  clearSquare(x,y);
}

void draw6(byte x, byte y){
  clearSquare(x,y);
}

void draw7(byte x, byte y){
  clearSquare(x,y);
}

void draw8(byte x, byte y){
  clearSquare(x,y);
}

void draw9(byte x, byte y){
  clearSquare(x,y);
}




void setBombs(){  
  byte x = random(0,13);    
  byte y = random(0,13);    
  if(grid[x][y]==0){      
    grid[x][y]==9; 
  }
}



void countBombs(){
  byte x = 0;
  byte y = 0;
  while (x<13){
    while(y<13){
      if(grid[x][y]!=9){
        if(x==0){                    //left border
          if (y==0){                 //top border
            int i = 0;
            if(count6(x, y)){
              i++;
            }
            if(count8(x, y)){
              i++;
            }
            if(count9(x, y)){
              i++;
            }
            if(i==0){
              grid[x][y] = 10;
            }
            else{
              grid[x][y] = i;
            }
          }
          else if(y==12){          //bottom border
            int i = 0;
            if(count2(x, y)){
              i++;
            }
            if(count3(x, y)){
              i++;
            }
            if(count6(x, y)){
              i++;
            }
            if(i==0){
              grid[x][y] = 10;
            }
            else{
              grid[x][y] = i;
            }
          }
          else{                    //no y border
            int i = 0;
            if(count2(x, y)){
              i++;
            }
            if(count3(x, y)){
              i++;
            }
            if(count6(x, y)){
              i++;
            }
            if(count8(x, y)){
              i++;
            }
            if(count9(x, y)){
              i++;
            }
            if(i==0){
              grid[x][y] = 10;
            }
            else{
              grid[x][y] = i;
            }
          }
        }
        else if(x==12){             //right border
          if (y==0){                //top border
            int i = 0;
            if(count4(x, y)){
              i++;
            }
            if(count7(x, y)){
              i++;
            }
            if(count8(x, y)){
              i++;
            }
            if(i==0){
              grid[x][y] = 10;
            }
            else{
              grid[x][y] = i;
            }
          }
          else if(y==12){          //bottom border
            int i = 0;
            if(count1(x, y)){
              i++;
            }
            if(count2(x, y)){
              i++;
            }
            if(count4(x, y)){
              i++;
            }
            if(i==0){
              grid[x][y] = 10;
            }
            else{
              grid[x][y] = i;
            }
          }
          else{                    //no y border
            int i = 0;
            if(count1(x, y)){
              i++;
            }
            if(count2(x, y)){
              i++;
            }
            if(count4(x, y)){
              i++;
            }
            if(count7(x, y)){
              i++;
            }
            if(count8(x, y)){
              i++;
            }
            if(i==0){
              grid[x][y] = 10;
            }
            else{
              grid[x][y] = i;
            }
          }
        }
        else{                  //no x border
          if (y==0){           //top border
            int i = 0;
            if(count1(x, y)){
              i++;
            }
            if(count2(x, y)){
              i++;
            }
            if(count3(x, y)){
              i++;
            }
            if(count4(x, y)){
              i++;
            }
            if(count6(x, y)){
              i++;
            }
            if(i==0){
              grid[x][y] = 10;
            }
            else{
              grid[x][y] = i;
            }
          }
          else if(y==12){            //bottom border
            int i = 0;
            if(count4(x, y)){
              i++;
            }
            if(count6(x, y)){
              i++;
            }
            if(count7(x, y)){
              i++;
            }
            if(count8(x, y)){
              i++;
            }
            if(count9(x, y)){
              i++;
            }
            if(i==0){
              grid[x][y] = 10;
            }
            else{
              grid[x][y] = i;
            }
          }
          else{                  //no y border
            int i = 0;
            if(count1(x, y)){
              i++;
            }
            if(count2(x, y)){
              i++;
            }
            if(count3(x, y)){
              i++;
            }
            if(count4(x, y)){
              i++;
            }
            if(count6(x, y)){
              i++;
            }
            if(count7(x, y)){
              i++;
            }
            if(count8(x, y)){
              i++;
            }
            if(count9(x, y)){
              i++;
            }
            if(i==0){
              grid[x][y] = 10;
            }
            else{
              grid[x][y] = i;
            }
          }
        }
      }
      y++;
    }
    y=0;
    x++;
  }

}






boolean count1(byte x, byte y){
  if(grid[x-1][y-1]==9){
    return true;
  }
  return false;
}

boolean count2(byte x, byte y){
  if(grid[x][y-1]==9){
    return true;
  }
  return false;
}

boolean count3(byte x, byte y){
  if(grid[x+1][y-1]==9){
    return true;
  }
  return false;
}

boolean count4(byte x, byte y){
  if(grid[x-1][y]==9){
    return true;
  }
  return false;
}


boolean count6(byte x, byte y){
  if(grid[x+1][y]==9){
    return true;
  }
  return false;
}

boolean count7(byte x, byte y){
  if(grid[x-1][y+1]==9){
    return true;
  }
  return false;
}


boolean count8(byte x, byte y){
  if(grid[x][y+1]==9){
    return true;
  }
  return false;
}

boolean count9(byte x, byte y){
  if(grid[x+1][y+1]==9){
    return true;
  }
  return false;
}























