
#include <numbers.ino>
#include <drawing.ino>
#include <bombgen.ino>
#include <TVout.h>
TVout TV;

//#include <pollserial.h>
//pollserial pserial;
byte startBombs;
byte cursorX;
byte cursorY;
byte cposX;
byte cposY;
int oldBombsLeft;
byte amountCovered;
byte flags;
unsigned long timestamp;
boolean allowButton;

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
  amountCovered = 169;
  flags = 0;
  cursorY=1;
  cursorX=1;
  cposX=0;
  cposY=0;
  digitalWrite(A2,HIGH);
  //TV.set_hbi_hook(pserial.begin(57600));
  startBombs = 1;
  
}

void loop(){
  byte temp = 0;
  while(temp<startBombs){
    if(setBombs()){
      temp++; 
    }
  }
  TV.begin(PAL,128,96);
  screen();
  initialGrid();
  countBombs();
  boolean temp1,temp2,temp2old;
  while (1){  
    //drawGen();
    displayBombsLeft();
    temp2old=temp2;
    getCursorMovement();
    if(allowButton){                  //if this is true then the joystick is not on one of the sides, should stop false short presses
      if (button()){
        if(millis()-timestamp>300){    //long press
          temp1=true;                  //temp1 defines a long or a short press
          temp2=true;
        }
        else{  //short press, made to debounce when moving the cursor
          temp1=false;
          temp2=true;                //means button is pressed
        }
      }
      else{
        temp2=false;              //means button is not pressed
      }

      if(temp2old&&!temp2){        //means button is just released          
        if(temp1){
          longPress();
        }
        else{
          shortPress();
        }
      }
    }
  }
}

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
    allowButton=false;
  }
  else if (temp>400&&temp<600){
    cursorX=1;
    allowButton=true;
  }
  else if (temp>900){
    cursorX=2;
    allowButton=false;
  }

  temp = analogRead(A1);
  if(temp<200){
    cursorY = 0;
    allowButton=false;
  }
  else if (temp>400&&temp<600){
    cursorY=1;
    allowButton=true;
  }
  else if (temp>900){
    cursorY=2;
    allowButton=false;
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
    return true;
  }
  else if(temp>100){
    timestamp=millis();
    return false;
  }
}

//returns true if the current position of the cursor is on a flag
boolean flaggedPosition(){
  byte t=grid[cposX][cposY];
  if(t>=20&&t<=29){
    return true;
  }
  else{
    return false;
  }
}

boolean coveredPosition(){
  byte t=grid[cposX][cposY];
  if(t>=1&&t<=10){
    return true;
  }
  else{
    return false;
  }  
}

boolean unCoveredPosition(){
  byte t=grid[cposX][cposY];
  if(t>=11&&t<=19){
    return true;
  }
  else{
    return false;
  }
}


//Code that needs to be excecuted when a short button press is happening
void shortPress(){
  if(unCoveredPosition()){
    //do nothing, flags cannot be placed on covered positions
  }
  else if (flaggedPosition()){
    //remove flag
    removeFlag();
  }
  else{
    //place flag
    placeFlag();
  }
}

//code that needs to be executed in case of a long button press
void longPress(){
  if(unCoveredPosition()){
    // do nothing, position is already uncovered
  }
  else if (flaggedPosition()){
    //More nothing, you cannot clear a flagged area
  }
  else {
    removeCover();
  }
}


void removeCover(){
  switch (grid[cposX][cposY]){
  case 1:
    grid[cposX][cposY]=11;
    draw1(cposX,cposY);
    amountCovered--;
    break;
  case 2:
    grid[cposX][cposY]=12;
    draw2(cposX,cposY);
    amountCovered--;
    break;
  case 3:
    grid[cposX][cposY]=13;
    draw3(cposX,cposY);
    amountCovered--;
    break;
  case 4:
    grid[cposX][cposY]=14;
    draw4(cposX,cposY);
    amountCovered--;
    break;
  case 5:
    grid[cposX][cposY]=15;
    draw5(cposX,cposY);
    amountCovered--;
    break;
  case 6:
    grid[cposX][cposY]=16;
    draw6(cposX,cposY);
    amountCovered--;
    break;
  case 7:
    grid[cposX][cposY]=17;
    draw7(cposX,cposY);
    amountCovered--;
    break;
  case 8:
    grid[cposX][cposY]=18;
    draw8(cposX,cposY);
    amountCovered--;
    break;
  case 9:
    grid[cposX][cposY]=30;          //bomb
    bombExplosion();
    break;
  case 10:
    grid[cposX][cposY]=19;
    drawEmpty(cposX,cposY);
    amountCovered--;
    break;
  }
}

void placeFlag(){
  switch (grid[cposX][cposY]){
  case 1:
    grid[cposX][cposY]=21;
    drawFlag(cposX,cposY);
    flags++;
    break;
  case 2:
    grid[cposX][cposY]=22;
    drawFlag(cposX,cposY);
    flags++;    
    break;
  case 3:
    grid[cposX][cposY]=23;
    drawFlag(cposX,cposY);
    flags++;    
    break;
  case 4:
    grid[cposX][cposY]=24;
    drawFlag(cposX,cposY);
    flags++;    
    break;
  case 5:
    grid[cposX][cposY]=25;
    drawFlag(cposX,cposY);
    flags++;    
    break;
  case 6:
    grid[cposX][cposY]=26;
    drawFlag(cposX,cposY);
    flags++;    
    break;
  case 7:
    grid[cposX][cposY]=27;
    drawFlag(cposX,cposY);
    flags++;    
    break;
  case 8:
    grid[cposX][cposY]=28;
    drawFlag(cposX,cposY);
    flags++;    
    break;
  case 9:
    grid[cposX][cposY]=29;          //bomb
    drawFlag(cposX,cposY);
    flags++;    
    break;
  case 10:
    grid[cposX][cposY]=20;
    drawFlag(cposX,cposY);
    flags++;    
    break;
  }
}

void removeFlag(){
  switch (grid[cposX][cposY]){
  case 21:
    grid[cposX][cposY]=1;
    drawSquare(cposX,cposY);
    flags--;
    break;
  case 22:
    grid[cposX][cposY]=2;
    drawSquare(cposX,cposY);
    flags--;
    break;
  case 23:
    grid[cposX][cposY]=3;
    drawSquare(cposX,cposY);
    flags--;
    break;
  case 24:
    grid[cposX][cposY]=4;
    drawSquare(cposX,cposY);
    flags--;
    break;
  case 25:
    grid[cposX][cposY]=5;
    drawSquare(cposX,cposY);
    flags--;
    break;
  case 26:
    grid[cposX][cposY]=6;
    drawSquare(cposX,cposY);
    flags--;
    break;
  case 27:
    grid[cposX][cposY]=7;
    drawSquare(cposX,cposY);
    flags--;
    break;
  case 28:
    grid[cposX][cposY]=8;
    drawSquare(cposX,cposY);
    flags--;
    break;
  case 29:
    grid[cposX][cposY]=9;          //bomb
    drawSquare(cposX,cposY);
    flags--;
    break;
  case 20:
    grid[cposX][cposY]=10;
    drawSquare(cposX,cposY);
    flags--;
    break;
  }
}


void bombExplosion(){
  //game over
}

//Counts the total amount of bombs left and returns an int type for that
int countBombsLeft(){
  return (startBombs-flags);
}

//Displays the amount of bombs left
void displayBombsLeft(){
  if (oldBombsLeft!=countBombsLeft()){
  
    if (countBombsLeft()<0){
      if (abs(countBombsLeft())<10){      //negative one digit number
        clearSpace(0);
        drawMinusSign(1);
        drawDigit2(abs(countBombsLeft()));
      }
      else if(abs(countBombsLeft())<100){    //negative two digit number 
        drawMinusSign(0);
        drawDigit1(abs(countBombsLeft()/10));
        drawDigit2(abs(countBombsLeft()%10));
      }
      else{                         //negative overflow number
        drawMinusSign(0);
        drawDigit1(9);
        drawDigit2(9);
      }
    }
    else{
      if (countBombsLeft()<10){      //positive one digit number
        clearSpace(0);
        clearSpace(1);
        drawDigit2(countBombsLeft());
      }
      else{                        //positive two digit number
        clearSpace(0);
        drawDigit1((countBombsLeft()/10));
        drawDigit2(countBombsLeft()%10);
      }
    }
    oldBombsLeft=countBombsLeft();
  }
}







