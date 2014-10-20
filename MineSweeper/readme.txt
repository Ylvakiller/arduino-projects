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
There is one more function which happens before the drawing and that function is discussed at a later point in this readme due to its size

We begin drawing by making the edges, this is done in the screen function in the drawing  file.
This function then continues with writing the text on the side panel.
From there we go and draw the initial grid (starting grid is all positions covered).
Then we draw the cursor in the top position (We added this due to a bug that did not show the cursor until it moved).
Then we go into the game loop, that is the while(1) loop

We start here by displaying the amount of bombs left on the side panel, this is a bit buggy in the start which we do not really understand why it happens. When we place a flag the bombcounter on the side is updated, from that point on it works perfectly.
That side screen can display number ranging from 99 till -99, it also has a special class for numbers lower then -99, here it will just display 99 to make sure we do not have an overflow happening.

we calculate the amount of bombs by taking the starting amount (which has to be smaller then 99(expert mode is around 50 already)) and then substracting the amount of flags from it.
This means that this number can become negative. That is also the reason why we used an int type there.

Then we check for a winning condition.
A winning condition is a condition where the amount of flags is the same as the amount of bombs we started with and the amount of not uncovered places - the amount of flags ==0
When a winning condition occurs it runs the code in drawWinScreen which will tell the user it has won in the sade panel and will then go in an infinite loop to stop the user from doing anything.

When there is no winning condition it will start with the user input.
I will first discuss the getCursorMovement function.

What this function does is checking the value of the 2 analog axis, when a value gets below 400 then it stores that in the correct variable, the variables are called cursorX and cursorY.
If this variable has a value of 1 then that means that that axis is in the middle, 0 is to a side and 2 is to the oposite side.

This function then goes and check if the value of one of these has changed and if it has changed it will process that code, this makes sure that when moving the cursor it will not keep on going in one direction but you have to let the cursor go to the middle before you can move the cursor again.
It also blocks the button when the joystick is at a certain side, this because with the joystick used there is a high likelyhood that the button will be pressed when moving the joystick.

When it detects that is has to move the cursor then it will will go into the moveCursor functions. these get the current position of the cursor, remove the rendering of the cursor at that postion by the function called clearCursor and the render a cursor at the new postion.
All of these moveCursor functions have edge detecting and if it has an edge in the place where it wants to go it instead places the cursor at the other side of the screen.

After this it will see what the button does.
It first sees if the cursor is moving, if it is not then it will check what the current postion of the button is and save that, if there is a falling edge it will store the time at when it detected the falling edge.
When there is a rising edge then it will start calculating how long the button was down.
If this time is shorter then 300 ms then it will say that there is a short click and otherwise it will say that there is a long click

When a long click happens it goes into the function called shortPress in the mineSweeper file.
This is because we switched what we wanted to happen. During nearly all of the programming we had that a long press was opening a spot and a short press was placing a flag.
However it is more natural to open a place with a short press and place a flag with a long press. we did not rename the functions for the demo and therefore I feel like it is most honest to deliver the code that we showed in the lab. (It is just a matter of renaming the functions but still).

When a short click is detected multiple things happen, these all happen in the function called longPress (I know it is confusing...).
The current position is checked, if that position is already uncovered or a flag then the code will not do anything with that short press.
If however these cases are both not true it will go into the removeCover function.
This function has a switch case, if the position has a 1-8 then it will draw that number, it will then also change the number stored in the grid array towards a number from 11-18, this will make sure you cannot place a flag here for example.
If there is a bomb (case 9) then it will draw a cross at that position and go into the drawGameOver function in the drawing file. This function will show the user that they have lost by displaying text on the right side.
The function will then go into an infinite empty loop to stop the user from being able to give any more input.

If there is no bomb near there is a special case, and here is where we will discuss the function mentioned at the beginning of this document.
If there is no bomb near it will empty the current coordinate and it will then go into the openEmpty function.
This openEmpty function utilises the emptyArray.

This array is created by the function calculateEmptyArray in the emptyDetection file.
This function holds an algorithm that will go over every single cell, starting at the top left and going down, when it has done a column it starts at the top once more.
If it detects an empty space at the current position then we know that that is part of an empty blob.
It will then check the positions to the left and to the top (taking into account the boundary conditions).
If only one of them is part of a blob it will use that number on the current position.
If both to the left and to the top are parts of blobs it will store the value of the left blob in the current position and will send the values of both the left blob and the top blob to the function called transformBlob.
This function will go through all cells and when it finds a cell with the value of the top blob then it will change that with the value of the left blob (this does not check if both of them are part of the same blob, however that is okay since it is quite a fast function and changing 1 to 1 will result in 1 anyway)
When this emptyArray is finished it can be used by the openEmpty function

The openEmpty function will go through the whole playing field, checking for spots that are part of the same blob as the one given to the function.
When it finds a spot that is part of the same blob it will open up that spot and all those around it using the openPos function.
This takes into account the boundary positions to avoid going outside of the array.
It also lowers the amount of covered positions by 1, which is used in the part of the program that detects a win.

This is basically what the program does, there are more functions that we do not go into in this read me, most of them are graphics.
We decided to make our own graphics since we noticed a lot of other groups having memory problems when storing strings or even arrays.
This also allowed us to fully customise all the graphics, and it allowed us to only have the graphic calculations in local methods, then the variables used would be gone again when that method would be done.
The tvout library keeps an array of hex codes in the memory to store the value of every single pixel anyway. Therefore there is no need for us to keep that in memory.


As we know there are some bugs, and we believe it is best to tell you about our bugs and what we think of them:
artifacting:
	When the program opens up a large blob there is some artifacting happening in the bottom of the screen. we are unsure about why this happens.
	What we do know is that it is not happening in our code (although undoubtedly because our code), this because the artifacting is smaller then the pixels we can set for the tvout library.
	What could happen is that we are running near the edge of our memory, however we would suspect that the program would completely crash if it where actually running out of memory.
	Another thing that could be happening is that the processing takes up to large a portion of the program and that therefore the tvout library is not correctly sending the signal towards the tv any more
start up bug:
	There is a startup bug where it sometimes detects a short or a long button press at the start, this happens both when starting after upload and when resetting, although it happens more often after an upload.
	This is due to the floating nature of the analog pin. However we were unable to get it out.
	We tried using a delay before starting the game loop (and before starting reading out the button) this did not work.
	We tried initialising it as pullup, pulldown and even as just an input and doing a digitalWrite in the beginning. none of these worked.
	We then looked at what this bug actually meant, most of the time it would detect a short click, meaning that it would place a flag.
	We decided that this was not a gameAffecting bug, this because you can just remove the flag and the problem is solved.

I hope this readme (though large in size) gives a good idea of what happens in the program and will help with reading the code.
There is a file in the program called arraydocs, this file is what we used to keep track of what different numbers in the grid array mean, this file might be  helpfull aswell.
Furthermore the code is commented where we felt it was not clear what happened.
	
	