This file will tell something about the different values of the arrays used:

input array:
0 means no input
1 means left
2 means right
3 means up
4 means down
5 means single pres
6 means double pres


grid array
this array meant to store all the data about the level

0 means that cell is not deffined
1-8 means that there is a number of bombs nearby (1-8) but the cell is covered
9 means there is a bomb here and that the cell is covered
10 means that there are no bombs near, with the cell covered
11-18 say how many bombs are near, with the cell exposed
19 means no bomb near, spot exposed
20-28 say how many bombs are near, with a flag on the cell  // in this case 20 means 0 bombs near, 21 means 1 bomb near etc
29 is a flagged bomb




