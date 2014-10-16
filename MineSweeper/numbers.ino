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
  // TV.draw_line(((x*7)+4),((y*7)+4),((x*7)+4),((y*7)+6), WHITE);
  TV.draw_line(((x*7)+4),((y*7)+5),((x*7)+8),((y*7)+5), WHITE);
  TV.draw_line(((x*7)+7),((y*7)+6),((x*7)+7),((y*7)+8), WHITE);
  //TV.set_pixel(((x*7)+7),((y*7)+7), WHITE);
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

  }
  else{
  }
}
void drawSide5(byte place){
  if(place==1){

  }
  else{
  }
}
void drawSide6(byte place){
  if(place==1){

  }
  else{
  }
}
void drawSide7(byte place){
  if(place==1){

  }
  else{
  }
}
void drawSide8(byte place){
  if(place==1){

  }
  else{
  }
}
void drawSide9(byte place){
  if(place==1){

  }
  else{
  }
}
void drawSide0(byte place){
  if(place==1){

  }
  else{
  }
}



