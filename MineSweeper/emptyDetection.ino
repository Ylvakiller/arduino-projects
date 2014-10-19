byte emptyArray[13][13] = {0};      //empty array

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



/**
Both checkLeft and checkTop assume that the algorithm where these functions will be used will run first from top to bottom and then from left to right
Meaning that the assumption is that if the position either to the left or to the top (depending on the functions) has already gotten a number.
They also both assume that the array cannot get out of bounds by the values given to them.
Meaning the you should not run checkLeft if you are on the left most collum, and you should not run checkTop if you are on the top row.
*/
boolean checkLeft(byte x, byte y){
  if (grid[x-1][y]==10){
    return true;
  }else{
    return false;
  }
}

boolean checkTop(byte x, byte y){
  if (grid[x][y-1]==10){
    return true;
  }else{
    return false;
  }
}

//Changes all the values in the empty array that have a value of second towards the value of first
void transformBlob(byte first,byte second){
  byte x = 0;
  byte y = 0;
  while (x<13){
    while (y<13){
      if (emptyArray[x][y]==second){
          emptyArray[x][y]=first;        //if the blob at the correct position is of the type we want to change then change it, otherwise do nothing
      }
      y++;
    }
    y=0;
    x++;
  }
}

void drawDetection(){
  byte x = 0;
  byte y = 0;
  while (x<13){
    while(y<13){
      switch (emptyArray[x][y]){
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





