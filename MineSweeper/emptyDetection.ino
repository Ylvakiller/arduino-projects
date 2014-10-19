byte emptyArray[13][13] = {
  0};      //empty array

void CalculateEmptyArray(){
  byte x = 0;
  byte y = 0;
  int i = 1;
  while (x<13){
    while(y<13){
      if(grid[x][y]!=10){
        if(x==0&&y==0){
          emptyArray[x][y]=i;        //top left corner
          i++;
        }
        else if (x==0){        //left border
          if (checkTop(x,y)){
            emptyArray[x][y] = emptyArray[x][y-1];
          }
          else{
            emptyArray[x][y]=i;
            i++;
          }
        }
        else if (y==0){      //top border
          if (checkLeft(x,y)){
            emptyArray[x][y] = emptyArray[x-1][y];
          }
          else{
            emptyArray[x][y] = i;
          }
        }
        else{               //no borders on left or on top
          if(checkLeft(x,y)&&checkTop(x,y)){    //blobs both on the top and on the bottom
            emptyArray[x][y] = emptyArray[x][y-1];                //saves the position of the top blob on the place of the intersection
            transformBlob(emptyArray[x][y-1],emptyArray[x-1][y]); //changes all the values in the empty array that have the value of the left blob towards the value fo the top blob
          }
          else if(checkLeft(x,y)){              //blob on the left but not on the top
            emptyArray[x][y] = emptyArray[x-1][y];
          }
          else if (checkTop(x,y)){
            emptyArray[x][y] = emptyArray[x][y-1];        //blob on the top but not on the right
          }
          else{                                //No blob found
            emptyArray[x][y] = i;
            i++;
          }
        }
      }
    }
    y++;
  }
  y=0;
  x++;
}




boolean checkLeft(byte x, byte y){
  //checks at the numerical position 2
}

boolean checkTop(byte x, byte y){
  //checks at the numerical position 3
}

//Changes all the values in the empty array that have a value of second towards the value of first
void transformBlob(byte first,byte second){
}




