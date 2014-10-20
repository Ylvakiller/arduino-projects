Readme:

The game utilises 2 arrays.
The first array is called the grid array
This array holds the playing field
It is initialised as 0.
Then a random generator will generate 2 numbers
both of these are between 0 and 13 (not including 13)
These give coordinates on the 13x13 grid (size of the playing field).
Then it checks if that place is 0 (ie. not initialised as something specific)
If it is 0 it places a bomb, if its not zero it does not attempt to place a bomb and also does not increase the counter for the bombs.

Now the playing field is created.
The program will then go into the function countBombs which is in the bombgen file.
This will count all the bombs around that specific place and will save that as a number in the grid array.
In this array a 10 means that there is a no bomb, however the place is covered (ie. not opened).
If the value in the grid array is between 1 and 8 then it is just that number of bombs with that place covered.
In the grid a 9 means that there is a bomb.

After it has done this the whole playing field is completely initialised and calculated and we can start drawing.

We begin drawing by making the edges, this is done in the screen method in the drawing  file.
This method then continues with writing the text on the side panel.
From there we go and draw the initial grid (starting grid is all positions covered).
Then we draw the cursor in the top position (We added this due to a bug that did not show the cursor until it moved).
Then we go into the game loop, that is the while(1) loop

We start here by displaying the amount of bombs left on the side panel, this is a bit buggy in the start which we do not really understand why it happens. When we place a flag the bombcounter on the side is updated, from that point on it works perfectely.

we calculate the amount of bombs by taking the starting amount (which has to be smaller then 99(expert mode is around 50 already)) and then substracting the amount of flags from it.
This means that this number can become negative. That is also the reason why we used an int type there.

Then we check for a winning condition.
A winning condition is a condition where the amount of flags is the same as the amount of bombs we started with and the amount of not uncovered places - the amount of flags ==0
When a winning condition occurs it runs the code in drawWinScreen which will tell the user it has won in the sade panel and will then go in an infinite loop to stop the user from doing anything.

When there is no winning condition it will start with the user input.
I will first discuss the getCursorMovement function.

What this method does is checking the value of the 2 analog axis, when a value gets below 400 then it stores that in the correct variable, the variables are called cursorX and cursorY.
If this variable has a value of 1 then that means that that axis is in the middle, 0 is to a side and 2 is to the oposite side.

This function then goes and check if the value of one of these has changed and if it has changed it will process that code, this makes sure that when moving the cursor it will not keep on going in one direction but you have to let the cursor go to the middle before you can move the cursor again.
It also blocks the button when the joystick is at a certain side, this because with the joystick used there is a high likelyhood that the button will be pressed when moving the joystick.

When it detects that is has to move the cursor then it will will go into the moveCursor methods. these get the current position of the cursor, remove the rendering of the cursor at that postion by the function called clearCursor and the render a cursor at the new postion.
All of these moveCursor functions have edge detecting and if it has an edge in the place where it wants to go it instead places the cursor at the other side of the screen.

After this it will see what the button does.
It first sees if the cursor is moving, if it is not then it will check what the current postion of the button is and save that, if there is a falling edge it will store the time at when it detected the falling edge.
When there is a rising edge then it will start calculating how long the button was down.
If this time is shorter then 300 ms then it will say that there is a short click and otherwise it will say that there is a long click

When a long click happens it goes into the method called shortPress in the mineSweeper file.
This is because we switched what we wanted to happen. During nearly all of the programming we had that a long press was opening a spot and a short press was placing a flag.
However it is more natural to open a place with a short press and place a flag with a long press. we did not rename the methods for the demo and therefore I feel like it is most honest to deliver the code that we showed in the lab. (It is just a matter of renaming the methods and then thats done)