

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
  TV.draw_line(99,4,99,8,WHITE);
  TV.draw_line(100,4,102,4,WHITE);
  TV.set_pixel(102,5,WHITE);
  TV.draw_line(100,6,102,6,WHITE);
  TV.set_pixel(102,7,WHITE);
  TV.draw_line(100,8,102,8,WHITE);    //B


}


