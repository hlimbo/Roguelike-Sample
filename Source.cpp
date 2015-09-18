#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <random>
#include <ctime>

#include "Map.h"
#include "GameManager.h"

#include "Console.h"

using namespace std;


int main()
{
	   console.SetTitle( "Article One Demo" );
    // Initialize the player's on-screen location
    int nPlayerX=40, nPlayerY=12;
    
    // Main program loop
    while( true )
    {
        // Wipe the console clean
        console.Clear();
        // Output phase - Draw the player to the screen
        console.Position( nPlayerX, nPlayerY );
        console << '@';
        // Input phase - Wait for the player to do something
        KEYPRESS    sKeyPress = console.WaitForKeypress();
        // Processing phase - Implement the player's command
        switch( sKeyPress.eCode )
        {
            // Move down
            case CONSOLE_KEY_DOWN:
                nPlayerY++;
                break;
            
            // Move left
            case CONSOLE_KEY_LEFT:
                nPlayerX--;
                break;
            // Move right
            case CONSOLE_KEY_RIGHT:
                nPlayerX++;
                break;
            
            // Move up
            case CONSOLE_KEY_UP:
                nPlayerY--;
                break;
            // Quit
            case CONSOLE_KEY_ESCAPE:
                return 0;
            // Ignore any other key
            default:
                break;
        }
    }
	return 0;
}

//goal rewrite using kathekonta tutorial.
/*int main()
{
	//using standard console.
/*	cout << "Welcome to the Roguey Game!" << endl;
	cout << "Press any key to begin..." << endl;
	_getch();
	GameManager game("TestMap.txt");
	game.start();
	*/
	
/*	mt19937 random((signed)time(0));
	uniform_int_distribution<char> roll(97,122);

	//using console lib made by someone else 3rd party library.
/*	console.Clear();
	console.Position(0,0);
	console << "hi";
	console.Position(10,5);
	console << (char)23;
	console.Position(10,10);
	console << roll(random);
	console.Position(20,30);
	system("PAUSE");
	return 0;
}*/

//mt19937 is a mersenne twister engine aka a pseudo random number generator.
	//example:
	/*
		NOTES

		mt19937 var(seed number);
		uniform_int_distribution<type> varname(x,y);

		-uniform int distribution offers a range between x and y both inclusive.
		
		-when calling a uniform-int_distribution<type> variable, one can use 
		the mt19937 variable as a parameter for selecting a random number 
		within the specified x-y range.

		-to make things more random, passing in the computer's internal time tracker
		as a seed makes each roll different per compile time.
		-if one decides to use the same seed in mt19937, the same random numbers will be selected per compile.

		if the type for uniform_int_distribution is char, it follows the ascii table values from 0 - 127 inclusive.
		to convert an int value into an ascii value, cast char on the int value.

	*/