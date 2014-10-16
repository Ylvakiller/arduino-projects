

void setBombs(){  
  byte x = random(0,13);    
  byte y = random(0,13);    
  if(grid[x][y]==0){      
    grid[x][y]=9; 
  }
}




void countBombs(){
  byte x = 0;
  byte y = 0;
  while (x<13){
    while(y<13){
      if(grid[x][y]!=9){
        if(x==0){                    //left border
          if (y==0){                 //top border
            int i = 0;
            if(count6(x, y)){
              i++;
            }
            if(count8(x, y)){
              i++;
            }
            if(count9(x, y)){
              i++;
            }
            if(i==0){
              grid[x][y] = 10;
            }
            else{
              grid[x][y] = i;
            }
          }
          else if(y==12){          //bottom border
            int i = 0;
            if(count2(x, y)){
              i++;
            }
            if(count3(x, y)){
              i++;
            }
            if(count6(x, y)){
              i++;
            }
            if(i==0){
              grid[x][y] = 10;
            }
            else{
              grid[x][y] = i;
            }
          }
          else{                    //no y border
            int i = 0;
            if(count2(x, y)){
              i++;
            }
            if(count3(x, y)){
              i++;
            }
            if(count6(x, y)){
              i++;
            }
            if(count8(x, y)){
              i++;
            }
            if(count9(x, y)){
              i++;
            }
            if(i==0){
              grid[x][y] = 10;
            }
            else{
              grid[x][y] = i;
            }
          }
        }
        else if(x==12){             //right border
          if (y==0){                //top border
            int i = 0;
            if(count4(x, y)){
              i++;
            }
            if(count7(x, y)){
              i++;
            }
            if(count8(x, y)){
              i++;
            }
            if(i==0){
              grid[x][y] = 10;
            }
            else{
              grid[x][y] = i;
            }
          }
          else if(y==12){          //bottom border
            int i = 0;
            if(count1(x, y)){
              i++;
            }
            if(count2(x, y)){
              i++;
            }
            if(count4(x, y)){
              i++;
            }
            if(i==0){
              grid[x][y] = 10;
            }
            else{
              grid[x][y] = i;
            }
          }
          else{                    //no y border
            int i = 0;
            if(count1(x, y)){
              i++;
            }
            if(count2(x, y)){
              i++;
            }
            if(count4(x, y)){
              i++;
            }
            if(count7(x, y)){
              i++;
            }
            if(count8(x, y)){
              i++;
            }
            if(i==0){
              grid[x][y] = 10;
            }
            else{
              grid[x][y] = i;
            }
          }
        }
        else{                  //no x border
          if (y==0){           //top border
            int i = 0;
            if(count1(x, y)){
              i++;
            }
            if(count2(x, y)){
              i++;
            }
            if(count3(x, y)){
              i++;
            }
            if(count4(x, y)){
              i++;
            }
            if(count6(x, y)){
              i++;
            }
            if(i==0){
              grid[x][y] = 10;
            }
            else{
              grid[x][y] = i;
            }
          }
          else if(y==12){            //bottom border
            int i = 0;
            if(count4(x, y)){
              i++;
            }
            if(count6(x, y)){
              i++;
            }
            if(count7(x, y)){
              i++;
            }
            if(count8(x, y)){
              i++;
            }
            if(count9(x, y)){
              i++;
            }
            if(i==0){
              grid[x][y] = 10;
            }
            else{
              grid[x][y] = i;
            }
          }
          else{                  //no y border
            int i = 0;
            if(count1(x, y)){
              i++;
            }
            if(count2(x, y)){
              i++;
            }
            if(count3(x, y)){
              i++;
            }
            if(count4(x, y)){
              i++;
            }
            if(count6(x, y)){
              i++;
            }
            if(count7(x, y)){
              i++;
            }
            if(count8(x, y)){
              i++;
            }
            if(count9(x, y)){
              i++;
            }
            if(i==0){
              grid[x][y] = 10;
            }
            else{
              grid[x][y] = i;
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






boolean count1(byte x, byte y){
  if(grid[x-1][y-1]==9){
    return true;
  }
  return false;
}

boolean count2(byte x, byte y){
  if(grid[x][y-1]==9){
    return true;
  }
  return false;
}

boolean count3(byte x, byte y){
  if(grid[x+1][y-1]==9){
    return true;
  }
  return false;
}

boolean count4(byte x, byte y){
  if(grid[x-1][y]==9){
    return true;
  }
  return false;
}


boolean count6(byte x, byte y){
  if(grid[x+1][y]==9){
    return true;
  }
  return false;
}

boolean count7(byte x, byte y){
  if(grid[x-1][y+1]==9){
    return true;
  }
  return false;
}


boolean count8(byte x, byte y){
  if(grid[x][y+1]==9){
    return true;
  }
  return false;
}

boolean count9(byte x, byte y){
  if(grid[x+1][y+1]==9){
    return true;
  }
  return false;
}

