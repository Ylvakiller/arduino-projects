byte old1,old2;

void screen(){
  TV.draw_line(0,0,95,0, WHITE);
  TV.draw_line(0,0,0,95, WHITE);
  TV.draw_line(0,95,95,95, WHITE);
  TV.draw_line(95,0,95,95, WHITE);
  TV.draw_line(96,0,127,0, WHITE);
  TV.draw_line(96,0,96,95, WHITE);
  TV.draw_line(96,95,127,95, WHITE);
  TV.draw_line(127,0,127,95, WHITE);
  drawSideBombs();
}

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
  TV.set_pixel(((x*7)+2), ((y*7)+2), WHITE);  //top left
  TV.set_pixel(((x*7)+2), ((y*7)+3), WHITE);
  TV.set_pixel(((x*7)+3), ((y*7)+2), WHITE);


  TV.set_pixel(((x*7)+9), ((y*7)+9), WHITE);  //bottom right
  TV.set_pixel(((x*7)+8), ((y*7)+9), WHITE);
  TV.set_pixel(((x*7)+9), ((y*7)+8), WHITE);

  TV.set_pixel(((x*7)+2), ((y*7)+9), WHITE);  //bottom left
  TV.set_pixel(((x*7)+3), ((y*7)+9), WHITE);
  TV.set_pixel(((x*7)+2), ((y*7)+8), WHITE);


  TV.set_pixel(((x*7)+9), ((y*7)+2), WHITE);  // top right
  TV.set_pixel(((x*7)+9), ((y*7)+3), WHITE);
  TV.set_pixel(((x*7)+8), ((y*7)+2), WHITE);


}


void clearCursor(byte x, byte y){
  TV.set_pixel(((x*7)+2), ((y*7)+2), BLACK);  //top left
  TV.set_pixel(((x*7)+2), ((y*7)+3), BLACK);
  TV.set_pixel(((x*7)+3), ((y*7)+2), BLACK);


  TV.set_pixel(((x*7)+9), ((y*7)+9), BLACK);  //bottom right
  TV.set_pixel(((x*7)+8), ((y*7)+9), BLACK);
  TV.set_pixel(((x*7)+9), ((y*7)+8), BLACK);

  TV.set_pixel(((x*7)+2), ((y*7)+9), BLACK);  //bottom left
  TV.set_pixel(((x*7)+3), ((y*7)+9), BLACK);
  TV.set_pixel(((x*7)+2), ((y*7)+8), BLACK);


  TV.set_pixel(((x*7)+9), ((y*7)+2), BLACK);  // top right
  TV.set_pixel(((x*7)+9), ((y*7)+3), BLACK);
  TV.set_pixel(((x*7)+8), ((y*7)+2), BLACK);
}


void drawGen(){
  byte x = 0;
  byte y = 0;
  while (x<13){
    while(y<13){
      switch (grid[x][y]){
      case 1:
        draw1(x,y);
        break;
      case 2:
        draw2(x,y);
        break;
      case 3:
        draw3(x,y);
        break;
      case 4:
        draw4(x,y);
        break;
      case 5:
        draw5(x,y);
        break;
      case 6:
        draw6(x,y);
        break;
      case 7:
        draw7(x,y);
        break;
      case 8:
        draw8(x,y);
        break;
      case 9:
        drawFlag(x,y);
        break;
      case 10:
        drawEmpty(x,y);
        break;
      default:
        drawEmpty(x,y);
        break;
      }
      y++;
    }
    x++;
    y=0;
  }
}

void drawSideBombs(){
  TV.draw_line(99,3,99,7,WHITE);
  TV.draw_line(100,3,102,3,WHITE);
  TV.set_pixel(102,4,WHITE);
  TV.draw_line(100,5,102,5,WHITE);
  TV.set_pixel(102,6,WHITE);
  TV.draw_line(100,7,102,7,WHITE);    //B
  TV.draw_line(105,3,107,3,WHITE);
  TV.draw_line(104,4,104,6,WHITE);
  TV.draw_line(105,7,107,7,WHITE);
  TV.draw_line(107,4,107,6,WHITE);    //O

  TV.draw_line(109,3,109,7,WHITE);
  TV.set_pixel(110,4,WHITE);
  TV.set_pixel(111,5,WHITE);
  TV.set_pixel(112,4,WHITE);
  TV.draw_line(113,3,113,7,WHITE);    //M


  TV.draw_line(115,3,115,7,WHITE);
  TV.draw_line(116,3,118,3,WHITE);
  TV.set_pixel(118,4,WHITE);
  TV.draw_line(116,5,118,5,WHITE);
  TV.set_pixel(118,6,WHITE);
  TV.draw_line(116,7,118,7,WHITE);    //B

  TV.draw_line(121,3,124,3,WHITE);
  TV.set_pixel(120,4,WHITE);
  TV.set_pixel(121,4,WHITE);
  TV.draw_line(121,5,124,5,WHITE);
  TV.set_pixel(123,6,WHITE);
  TV.set_pixel(124,6,WHITE);
  TV.draw_line(121,7,124,7,WHITE);    //S

  //Next row of text
  TV.draw_line(99,9,99,13,WHITE);
  TV.draw_line(100,13,102,13,WHITE);  //L

  TV.draw_line(103,9,106,9,WHITE);
  TV.set_pixel(103,10,WHITE);
  TV.draw_line(103,11,106,11,WHITE);
  TV.set_pixel(103,12,WHITE);
  TV.draw_line(103,13,106,13,WHITE);  //E

    TV.draw_line(107,9,110,9,WHITE);
  TV.set_pixel(107,10,WHITE);
  TV.draw_line(107,11,110,11,WHITE);
  TV.set_pixel(107,12,WHITE);
  TV.set_pixel(107,13,WHITE);        //F

  TV.draw_line(111,9,116,9,WHITE);
  TV.draw_line(113,9,113,13,WHITE);  //T

  TV.set_pixel(117,10,WHITE);
  TV.set_pixel(117,12,WHITE);        //:
  TV.draw_rect(99,16,17,9,1,0);      //Square for the actual numbers for the bombcount

}

void drawBombCount(){
  if (bombsLeft<0){
    if (bombsLeft<=-10){
      drawMinusSign(1);//draw - sign
      //draw first digit
      //draw second digit
    }
    else{
      clearSpace(0);//remove minus sign before first digit
      clearSpace(1);//remove first digit
      drawMinusSign(2);//draw - sign at place of first digit
      //draw second digit at
    }
  }
  else if (bombsLeft>=10){
    clearSpace(0);//remove - sign
    //draw first digit
    //draw second digit
  }
  else{
    clearSpace(0);//remove minus sign
    clearSpace(1);//remove first digit
    //draw second digit
  }
}

/**
 * Place is here the place in the sidepanel, place 1 is for 2 digits, place 2 is for 1 digit (it needs to move to the right to display 1 digit)
 */
void drawMinusSign(byte place){
  if(place==1){
    TV.draw_line(101,21,103,21,WHITE);
  }
  else{
    TV.draw_line(106,21,108,21,WHITE);
  }
}

//completely clears a place from any number or sign.
//place 0 is the - sign, place 1 is the first digit and place 2 is the second digit
void clearSpace(byte place){
  if(place==0){
    TV.draw_rect(101,17,1,7,0,0);
  }
  else if (place==1){
    TV.draw_rect(104,17,4,7,0,0);
  }
  else if(place ==2){
    TV.draw_rect(110,17,4,7,0,0);
  }
}

void drawDigit1(byte digit){
  if(old1!=digit){
    clearSpace(1);
    switch(digit){
    case 1:
      drawSide1(1);
      break;
    case 2:
      drawSide2(1);
      break;
    case 3:
      drawSide3(1);
      break;
    case 4:
      drawSide4(1);
      break;
    case 5:
      drawSide5(1);
      break;
    case 6:
      drawSide6(1);
      break;
    case 7:
      drawSide7(1);
      break;
    case 8:
      drawSide8(1);
      break;
    case 9:
      drawSide9(1);
      break;
    case 0:
      drawSide0(1);
      break;
    }
    old1=digit;
  }
}

void drawDigit2(byte digit){
  if(old2!=digit){
    clearSpace(2);
    switch(digit){
    case 1:
      drawSide1(2);
      break;
    case 2:
      drawSide2(2);
      break;
    case 3:
      drawSide3(2);
      break;
    case 4:
      drawSide4(2);
      break;
    case 5:
      drawSide5(2);
      break;
    case 6:
      drawSide6(2);
      break;
    case 7:
      drawSide7(2);
      break;
    case 8:
      drawSide8(2);
      break;
    case 9:
      drawSide9(2);
      break;
    case 0:
      drawSide0(2);
      break;
    }
    old2=digit;
  }

}










