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
