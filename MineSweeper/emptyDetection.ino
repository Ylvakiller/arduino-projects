byte empty[13][13] = {0};      //empty array

void CalculateEmptyArray(){
  byte x = 0;
  byte y = 0;
  int i = 1;
  while (x<13){
    while(y<13){
      if(grid[x][y]!=10){
        if(x==0&&y==0){
          empty[x][y]=i;        //top left corner
          i++;
        }else if (x==0){        //left border
          if (check3[x][y]){
            empty[x][y] = empty[x][y-1];
          }else{
             
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

boolean check1(byte x, byte y){
  //checks at the numerical position 1
}

boolean check2(byte x, byte y){
  //checks at the numerical position 2
}

boolean check3(byte x, byte y){
  //checks at the numerical position 3
}

boolean check4(byte x, byte y){
  //checks at the numerical position 4
}

boolean check6(byte x, byte y){
  //checks at the numerical position 6
}

boolean check7(byte x, byte y){
  //checks at the numerical position 7
}

boolean check8(byte x, byte y){
  //checks at the numerical position 8
}

boolean check9(byte x, byte y){
  //checks at the numerical position 9
}


