void draw1(byte x, byte y){
  clearSquare(x,y);
  TV.draw_line(((x*7)+5),((y*7)+3), ((x*7)+5),((y*7)+8), WHITE);
  //TV.draw_line(((x*7)+6),((y*7)+3), ((x*7)+6),((y*7)+8), WHITE);
  TV.set_pixel(((x*7)+4),((y*7)+4), WHITE);
  TV.set_pixel(((x*7)+4),((y*7)+8),WHITE);
  TV.set_pixel(((x*7)+6),((y*7)+8),WHITE);
}

void draw2(byte x, byte y){
  clearSquare(x,y);
  TV.set_pixel(((x*7)+4),((y*7)+4), WHITE);
  TV.draw_line(((x*7)+5),((y*7)+3),((x*7)+7),((y*7)+3), WHITE);
  TV.draw_line(((x*7)+7),((y*7)+4),((x*7)+7),((y*7)+5), WHITE);
  TV.draw_line(((x*7)+5),((y*7)+6),((x*7)+7),((y*7)+6), WHITE);
  TV.set_pixel(((x*7)+4),((y*7)+7), WHITE);
  TV.draw_line(((x*7)+4),((y*7)+8),((x*7)+8),((y*7)+8), WHITE);
}

void draw3(byte x, byte y){
  clearSquare(x,y);
  TV.set_pixel(((x*7)+7),((y*7)+4), WHITE);
  TV.set_pixel(((x*7)+7),((y*7)+6), WHITE);
  TV.set_pixel(((x*7)+7),((y*7)+7), WHITE);
  TV.draw_line(((x*7)+4),((y*7)+3),((x*7)+7),((y*7)+3), WHITE);
  TV.draw_line(((x*7)+4),((y*7)+5),((x*7)+7),((y*7)+5), WHITE);
  TV.draw_line(((x*7)+4),((y*7)+8),((x*7)+7),((y*7)+8), WHITE);
}

void draw4(byte x, byte y){
  clearSquare(x,y);
  TV.draw_line(((x*7)+4),((y*7)+3),((x*7)+4),((y*7)+6), WHITE);
  TV.draw_line(((x*7)+7),((y*7)+3),((x*7)+7),((y*7)+8), WHITE);
  TV.set_pixel(((x*7)+5),((y*7)+6), WHITE);
  TV.set_pixel(((x*7)+6),((y*7)+6), WHITE);
}

void draw5(byte x, byte y){
  clearSquare(x,y);
  TV.draw_line(((x*7)+4),((y*7)+3),((x*7)+8),((y*7)+3), WHITE);
  TV.draw_line(((x*7)+4),((y*7)+4),((x*7)+4),((y*7)+6), WHITE);
  TV.draw_line(((x*7)+5),((y*7)+6),((x*7)+8),((y*7)+6), WHITE);
  TV.set_pixel(((x*7)+7),((y*7)+7), WHITE);
  TV.draw_line(((x*7)+4),((y*7)+8),((x*7)+8),((y*7)+8), WHITE);
}

void draw6(byte x, byte y){
  clearSquare(x,y);
  TV.draw_line(((x*7)+4),((y*7)+4),((x*7)+4),((y*7)+7), WHITE);
  
  TV.set_pixel(((x*7)+5),((y*7)+3),WHITE);
  TV.set_pixel(((x*7)+6),((y*7)+3),WHITE);
  
  TV.set_pixel(((x*7)+5),((y*7)+5),WHITE);
  TV.set_pixel(((x*7)+6),((y*7)+5),WHITE);
  
  TV.set_pixel(((x*7)+5),((y*7)+8),WHITE);
  TV.set_pixel(((x*7)+6),((y*7)+8),WHITE);
  
  TV.set_pixel(((x*7)+7),((y*7)+6),WHITE);
  TV.set_pixel(((x*7)+7),((y*7)+7),WHITE);  
}

void draw7(byte x, byte y){
  clearSquare(x,y);
  TV.draw_line(((x*7)+4),((y*7)+3),((x*7)+8),((y*7)+3), WHITE);
  TV.draw_line(((x*7)+5),((y*7)+6),((x*7)+5),((y*7)+8), WHITE);
  TV.set_pixel(((x*7)+6),((y*7)+5), WHITE);
  TV.set_pixel(((x*7)+7),((y*7)+4), WHITE);
}

void draw8(byte x, byte y){
  clearSquare(x,y);
  TV.draw_line(((x*7)+4),((y*7)+3), ((x*7)+7),((y*7)+3), WHITE);
  TV.draw_line(((x*7)+4),((y*7)+5), ((x*7)+7),((y*7)+5), WHITE);
  TV.draw_line(((x*7)+4),((y*7)+8), ((x*7)+7),((y*7)+8), WHITE);
  TV.set_pixel(((x*7)+3),((y*7)+4), WHITE);
  TV.set_pixel(((x*7)+7),((y*7)+4), WHITE);
  TV.set_pixel(((x*7)+3),((y*7)+6), WHITE);
  TV.set_pixel(((x*7)+7),((y*7)+6), WHITE);
  TV.set_pixel(((x*7)+3),((y*7)+7), WHITE);
  TV.set_pixel(((x*7)+7),((y*7)+7), WHITE);
}

