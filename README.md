# Maximum and Minimum Numbers
This program is fairly simple and runs by first checking if you are using a Windows or an Apple product (code taken from the example project.)
It starts in the C++ script main.ccp, and when that is ran it prompts you for command line input to start the game. Once you start the game it asks
you for a minimum and maximum number. The minimum number must be positive and the maximum must be greater than the minimum.
 Once you have selected your numbers, it passes them as arguments to the module info.py. If you are running this in CLion instead of via the Terminal, you must add ../info.py instead of info.py in main.cpp.
 The python script performs a few basic calculations on your range of numbers, then challenges you to a guessing game. First, 
 it calculates how many tries it estimates it will take for it to guess a number you think of within your range. Then it asks 
 you to think of a number in the range and attempts to guess it. After it has guessed your number, or you try to lie to it, 
 it will ask if you want to play again. Once you refuse, it will print out how many times you played.
 
 # Known bugs
 There is one known bug that I can't fix for the life of me, the function getInput somehow calls itself and skips the cout and getline, 
 then returns an empty string and ends up having to call itself again, and this time double prints the cout. I don't know how to fix this, in the debugger 
 I literally watched it completely skip the cout the first time through then double print it the second time.
 

