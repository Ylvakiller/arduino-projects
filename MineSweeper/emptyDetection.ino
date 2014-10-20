

void calculateEmptyArray(){
  byte xpos = 0;
  byte ypos = 0;
  int j = 1;
  while (xpos<13){
    while(ypos<13){
      if(grid[xpos][ypos]==10){
        if(xpos==0&&ypos==0){
          emptyArray[xpos][ypos]=j;        //top left corner
          j++;
        }
        else if (xpos==0){        //left border
          if (checkTop(xpos,ypos)){
            emptyArray[xpos][ypos] = emptyArray[xpos][ypos-1];
          }
          else{
            emptyArray[xpos][ypos]=j;
            j++;
          }
        }
        else if (ypos==0){      //top border
          if (checkLeft(xpos,ypos)){
            emptyArray[xpos][ypos] = emptyArray[xpos-1][ypos];
          }
          else{
            emptyArray[xpos][ypos] = j;
            j++;
          }
        }
        else{               //no borders on left or on top
          if(checkLeft(xpos,ypos)&&checkTop(xpos,ypos)){    //blobs both on the top and on the bottom
            emptyArray[xpos][ypos] = emptyArray[xpos][ypos-1];                //saves the position of the top blob on the place of the intersection
            transformBlob(emptyArray[xpos][ypos-1],emptyArray[xpos-1][ypos]); //changes all the values in the empty array that have the value of the left blob towards the value of the top blob
          }
          else if(checkLeft(xpos,ypos)){              //blob on the left but not on the top
            emptyArray[xpos][ypos] = emptyArray[xpos-1][ypos];
          }
          else if (checkTop(xpos,ypos)){
            emptyArray[xpos][ypos] = emptyArray[xpos][ypos-1];        //blob on the top but not on the right
          }
          else{                                //No blob found
            emptyArray[xpos][ypos] = j;
            j++;
          }
        }
      }
      ypos++;
    }
    ypos=0;
  xpos++;
  }
  
}



/**
Both checkLeft and checkTop assume that the algorithm where these functions will be used will run first from top to bottom and then from left to right
Meaning that the assumption is that if the position either to the left or to the top (depending on the functions) has already gotten a number.
They also both assume that the array cannot get out of bounds by the values given to them.
Meaning the you should not run checkLeft if you are on the left most collum, and you should not run checkTop if you are on the top row.
*/
boolean checkLeft(byte x2, byte y2){
  if (grid[x2-1][y2]==10){
    return true;
  }else{
    return false;
  }
}

boolean checkTop(byte x3, byte y3){
  if (grid[x3][y3-1]==10){
    return true;
  }else{
    return false;
  }
}

//Changes all the values in the empty array that have a value of second towards the value of first
void transformBlob(byte first,byte second){
  byte x4 = 0;
  byte y4 = 0;
  while (x4<13){
    while (y4<13){
      if (emptyArray[x4][y4]==second){
          emptyArray[x4][y4]=first;        //if the blob at the correct position is of the type we want to change then change it, otherwise do nothing
      }
      y4++;
    }
    y4=0;
    x4++;
  }
}

void drawDetection(){
  drawFlag(5,5);
  byte x5 = 0;
  byte y5 = 0;
  while (x5<13){
    while(y5<13){
      //pserial.print(emptyArray[x5][y5]);
      y5++;
    }
    //pserial.println();
    x5++;
    y5=0;
  }
}





