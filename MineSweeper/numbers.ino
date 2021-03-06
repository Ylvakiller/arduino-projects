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
  TV.set_pixel(((x*7)+4),((y*7)+4), WHITE);
  TV.draw_line(((x*7)+4),((y*7)+5),((x*7)+8),((y*7)+5), WHITE);
  TV.draw_line(((x*7)+7),((y*7)+6),((x*7)+7),((y*7)+8), WHITE);
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





void drawSide1(byte place){
  if(place==1){
    TV.draw_line(106,18,106,23,WHITE);
    TV.set_pixel(105,19,WHITE);
    TV.set_pixel(105,23,WHITE);
    TV.set_pixel(107,23,WHITE);
  }
  else{
    TV.draw_line(112,18,112,23,WHITE);
    TV.set_pixel(111,19,WHITE);
    TV.set_pixel(111,23,WHITE);
    TV.set_pixel(113,23,WHITE);
  }
}
void drawSide2(byte place){
  if(place==1){
    TV.set_pixel(105,19,WHITE);
    TV.draw_line(106,18,108,18,WHITE);
    TV.draw_line(108,19,108,20,WHITE);
    TV.draw_line(106,21,108,21,WHITE);
    TV.set_pixel(105,22,WHITE);
    TV.draw_line(105,23,109,23,WHITE);
  }
  else{
    TV.set_pixel(111,19,WHITE);
    TV.draw_line(112,18,114,18,WHITE);
    TV.draw_line(114,19,114,20,WHITE);
    TV.draw_line(112,21,114,21,WHITE);
    TV.set_pixel(111,22,WHITE);
    TV.draw_line(111,23,115,23,WHITE);
  }
}
void drawSide3(byte place){
  if(place==1){
    TV.draw_line(105,18,108,18,WHITE);
    TV.set_pixel(108,19,WHITE);
    TV.draw_line(105,20,108,20,WHITE);
    TV.set_pixel(108,21,WHITE);
    TV.set_pixel(108,22,WHITE);
    TV.draw_line(105,23,108,23,WHITE);
  }
  else{
    TV.draw_line(111,18,114,18,WHITE);
    TV.set_pixel(114,19,WHITE);
    TV.draw_line(111,20,114,20,WHITE);
    TV.set_pixel(114,21,WHITE);
    TV.set_pixel(114,22,WHITE);
    TV.draw_line(111,23,114,23,WHITE);
  }
}
void drawSide4(byte place){
  if(place==1){
    TV.draw_line(105,18,105,21,WHITE);
    TV.set_pixel(106,21,WHITE);
    TV.set_pixel(107,21,WHITE);
    TV.draw_line(108,18,108,23,WHITE);
  }
  else{
    TV.draw_line(111,18,111,21,WHITE);
    TV.set_pixel(112,21,WHITE);
    TV.set_pixel(113,21,WHITE);
    TV.draw_line(114,18,114,23,WHITE);
  }
}
void drawSide5(byte place){
  if(place==1){
    TV.draw_line(105,18,109,18,WHITE);
    TV.set_pixel(105,19,WHITE);
    TV.draw_line(105,20,109,20,WHITE);
    TV.set_pixel(108,21,WHITE);
    TV.set_pixel(108,22,WHITE);
    TV.draw_line(105,23,109,23,WHITE);
  }
  else{
    TV.draw_line(111,18,115,18,WHITE);
    TV.set_pixel(111,19,WHITE);
    TV.draw_line(111,20,115,20,WHITE);
    TV.set_pixel(114,21,WHITE);
    TV.set_pixel(114,22,WHITE);
    TV.draw_line(111,23,115,23,WHITE);
  }
}
void drawSide6(byte place){
  if(place==1){
    TV.draw_line(105,19,105,22,WHITE);
    TV.draw_line(106,18,108,18,WHITE);
    TV.draw_line(106,20,108,20,WHITE);
    TV.draw_line(106,23,108,23,WHITE);
    TV.draw_line(108,21,108,22,WHITE);
  }
  else{
    TV.draw_line(111,19,111,22,WHITE);
    TV.draw_line(112,18,114,18,WHITE);
    TV.draw_line(112,20,114,20,WHITE);
    TV.draw_line(112,23,114,23,WHITE);
    TV.draw_line(114,21,114,22,WHITE);
  }
}
void drawSide7(byte place){
  if(place==1){
    TV.draw_line(105,18,109,18,WHITE);
    TV.draw_line(108,19,106,21,WHITE);
    TV.draw_line(106,21,106,23,WHITE);
  }
  else{
    TV.draw_line(111,18,115,18,WHITE);
    TV.draw_line(114,19,112,21,WHITE);
    TV.draw_line(112,21,112,23,WHITE);
  }
}
void drawSide8(byte place){
  if(place==1){
    TV.draw_line(105,18,108,18,WHITE);
    TV.set_pixel(104,19,WHITE);
    TV.set_pixel(108,19,WHITE);
    TV.draw_line(105,20,108,20,WHITE);
    TV.set_pixel(104,21,WHITE);
    TV.set_pixel(108,21,WHITE);
    TV.set_pixel(104,22,WHITE);
    TV.set_pixel(108,22,WHITE);
    TV.draw_line(105,23,108,23,WHITE);
  }
  else{
    TV.draw_line(111,18,114,18,WHITE);
    TV.set_pixel(110,19,WHITE);
    TV.set_pixel(114,19,WHITE);
    TV.draw_line(111,20,114,20,WHITE);
    TV.set_pixel(110,21,WHITE);
    TV.set_pixel(114,21,WHITE);
    TV.set_pixel(110,22,WHITE);
    TV.set_pixel(114,22,WHITE);
    TV.draw_line(111,23,114,23,WHITE);
  }
}
void drawSide9(byte place){
  if(place==1){
    TV.draw_rect(105,18,3,3,1,0);
    TV.set_pixel(108,22,WHITE);
    TV.draw_line(105,23,109,23,WHITE);
  }
  else{
    TV.draw_rect(111,18,3,3,1,0);
    TV.set_pixel(114,22,WHITE);
    TV.draw_line(111,23,115,23,WHITE);
  }
}
void drawSide0(byte place){
  if(place==1){
  clearSpace(1);
  }
  else{
    TV.draw_rect(111,18,3,5,1,0);
    
  }
}





