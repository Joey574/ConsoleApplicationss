// Common Commandsand what they do:
#include <stdio.h>
#include <iostream>
#include <string> // Needed for string
#include <stdlib.h> // Needed for srand
#include <time.h> // Needed for srand
#include <conio.h> 
#include <vector>

using namespace std;


void example()  // A void is a function, you can call a fucntion any time you want under main and the code in a void will be executed, helpful for saving space
{      			// the parameters of a void can be set to pass a local variable through by reference, to do this, when you call a void under main, type the name
				// of the variable you want to pass, then in the void parameters, define the variable and give it the name it will be called under that void
}

int main()
{

	int example2;

	bool example3;

	_getch(); // Kind of like a break, the code waits here until any key is pressed

	system("CLS"); // Clears the screen of any text that has been outputed, may not want to use this when clearing specific text
	
	cin >> example2; // This is an easy way to collect player input, however be careful, as the input is stored and if the game asks for another input it will automatically
					// use the one given previously unless another cin command is given
	while (example3 = true) // While is a type of loop that will continuesly execute the commands inside until the while statement is no longer true or a break; command is given
	{
		continue; // This command will cause a loop to go back to the beginnig

		break; // This command will cause a loop to "break" and stop repeating
	}
	srand(0);						// Both of these commands should only be executed once at the beginning of the code, as they are what gives the number for the
	srand((unsigned)time(NULL));	// srand randomizer, initilizing these more than once will cause an error

}