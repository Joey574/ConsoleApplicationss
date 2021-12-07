/*
Author: Joey Soroka
Partner: Eric Pace
File Name: ASCII Art and animation
Project Name: ASCII Art
Purpose: To give the user a choice of what ASCII art they would like to be displayed to the screen also offers a choice of a short animation
Pseudocode: Asks what robot the user would like outputted before outputting the selected robot, all of which are from Jay Thaler, one of which is animated by me,
			also gives the user an option to exit after art is displayed and user gives input it will repeat the code
Maintenance Log:
11/10/21:	Added first design to code, and halfway done with my second one
11/12/21:	Finished my second robot, Slater showed me a much faster way of making the outputs, finished the project quick.
12/7/21:	Added animation for the first robot
*/

#include <stdio.h>
#include <iostream>
#include <string> // Needed for string
#include <stdlib.h> // Needed for srand
#include <time.h> // Needed for srand
#include <conio.h> 
#include <vector>
#include <windows.h>

using namespace std;

int main()
{
	string input;

	while (1)
	{
		system("CLS");
		printf("Select which ASCII art you would like to see\n1. Tall robot (animated)\n2. Not as tall robot\n3. Mediocre height robot\n4. Exit\n");

		cin >> input;
		system("CLS");

		if (input == "1")
		{
			
				printf("   _____             _____\n");
				printf("  |_____|___________|_____|\n");
				printf("  |_____| / _____ \\ |_____|\n");
				printf("  |_____|/ /\\___/\\ \\|_____|\n");
				printf(" /|====|__/_/___\\_\\__|====|\\\n");
				printf(" ||====|  _/_\\_/_\\_  |====||\n");
				printf(" \\|====| | \\ ... / | |====|/\n");
				printf("       |__\\ `---' /__|\n");
				printf("        |==\\_____/==|\n");
				printf("        |===|===|===|\n");
				printf("        |===|+-+|===|\n");
				printf("        >|||<   >|||<\n");
				printf("        |---|   |---|\n");
				printf("        || ||   || ||\n");
				printf("        || ||   || ||\n");
				printf("        >= =<   >= =<\n");
				printf("        |===|   |===|\n");
				printf("        >---/   \\---<\n");
				printf("        ||#|     |#||\n");
				printf("        ||-|\\   /|-||\n");
				printf("        ||+||   ||+||\n");
				printf("        ||-|/   \\|-||\n");
				printf("        ||_|\\   /|_||     -- Jay Thaler \n");
				printf("     ___|/-\\/   \\/-\\|___\n");
				printf("    /________\\ /________\\\n");
				Sleep(500);
				system("CLS");
				printf("   _____             _____\n");
				printf("  |ooooo|___________|_____|\n");
				printf("  |ooooo| / _____ \\ |_____|\n");
				printf("  |ooooo|/ /\\___/\\ \\|_____|\n");
				printf(" /|====|__/_/___\\_\\__|====|\\\n");
				printf(" ||====|  _/_\\_/_\\_  |====||\n");
				printf(" \\|====| | \\ ... / | |====|/\n");
				printf("       |__\\ `---' /__|\n");
				printf("        |==\\_____/==|\n");
				printf("        |===|===|===|\n");
				printf("        |===|+-+|===|\n");
				printf("        >|||<   >|||<\n");
				printf("        |---|   |---|\n");
				printf("        || ||   || ||\n");
				printf("        || ||   || ||\n");
				printf("        >= =<   >= =<\n");
				printf("        |===|   |===|\n");
				printf("        >---/   \\---<\n");
				printf("        ||#|     |#||\n");
				printf("        ||-|\\   /|-||\n");
				printf("        ||+||   ||+||\n");
				printf("        ||-|/   \\|-||\n");
				printf("        ||_|\\   /|_||     -- Jay Thaler \n");
				printf("     ___|/-\\/   \\/-\\|___\n");
				printf("    /________\\ /________\\\n");
				Sleep(500);
				system("CLS");
				printf("   _____             _____\n");
				printf("  |<><>|___________|ooooo|\n");
				printf("  |<><>| / _____ \\ |ooooo|\n");
				printf("  |<><>|/ /\\___/\\ \\|ooooo|\n");
				printf(" /|====|__/_/___\\_\\__|====|\\\n");
				printf(" ||====|  _/_\\_/_\\_  |====||\n");
				printf(" \\|====| | \\ ... / | |====|/\n");
				printf("       |__\\ `---' /__|\n");
				printf("        |==\\_____/==|\n");
				printf("        |===|===|===|\n");
				printf("        |===|+-+|===|\n");
				printf("        >|||<   >|||<\n");
				printf("        |---|   |---|\n");
				printf("        || ||   || ||\n");
				printf("        || ||   || ||\n");
				printf("        >= =<   >= =<\n");
				printf("        |===|   |===|\n");
				printf("        >---/   \\---<\n");
				printf("        ||#|     |#||\n");
				printf("        ||-|\\   /|-||\n");
				printf("        ||+||   ||+||\n");
				printf("        ||-|/   \\|-||\n");
				printf("        ||_|\\   /|_||     -- Jay Thaler \n");
				printf("     ___|/-\\/   \\/-\\|___\n");
				printf("    /________\\ /________\\\n");
				Sleep(500);
				system("CLS");
				printf("   _____             _____\n");
				printf("  |_____|___________|<><>|\n");
				printf("  |_____| / _____ \\ |<><>|\n");
				printf("  |_____|/ /\\___/\\ \\|<><>|\n");
				printf(" /|====|__/_/___\\_\\__|====|\\\n");
				printf(" ||====|  _/_\\_/_\\_  |====||\n");
				printf(" \\|====| | \\ ... / | |====|/\n");
				printf("       |__\\ `---' /__|\n");
				printf("        |==\\_____/==|\n");
				printf("        |===|===|===|\n");
				printf("        |===|+-+|===|\n");
				printf("        >|||<   >|||<\n");
				printf("        |---|   |---|\n");
				printf("        || ||   || ||\n");
				printf("        || ||   || ||\n");
				printf("        >= =<   >= =<\n");
				printf("        |===|   |===|\n");
				printf("        >---/   \\---<\n");
				printf("        ||#|     |#||\n");
				printf("        ||-|\\   /|-||\n");
				printf("        ||+||   ||+||\n");
				printf("        ||-|/   \\|-||\n");
				printf("        ||_|\\   /|_||     -- Jay Thaler \n");
				printf("     ___|/-\\/   \\/-\\|___\n");
				printf("    /________\\ /________\\\n");
				Sleep(500);
				system("CLS");
				printf("   _____             _____\n");
				printf("  |_____|___________|_____|\n");
				printf("  |_____| / _____ \\ |_____|\n");
				printf("  |_____|/ /\\___/\\ \\|_____|\n");
				printf(" /|====|__/_/___\\_\\__|====|\\\n");
				printf(" ||====|  _/_\\_/_\\_  |====||\n");
				printf(" \\|====| | \\ ... / | |====|/\n");
				printf("       |__\\ `---' /__|\n");
				printf("        |==\\_____/==|\n");
				printf("        |===|===|===|\n");
				printf("        |===|+-+|===|\n");
				printf("        >|||<   >|||<\n");
				printf("        |---|   |---|\n");
				printf("        || ||   || ||\n");
				printf("        || ||   || ||\n");
				printf("        >= =<   >= =<\n");
				printf("        |===|   |===|\n");
				printf("        >---/   \\---<\n");
				printf("        ||#|     |#||\n");
				printf("        ||-|\\   /|-||\n");
				printf("        ||+||   ||+||\n");
				printf("        ||-|/   \\|-||\n");
				printf("        ||_|\\   /|_||     -- Jay Thaler \n");
				printf("     ___|/-\\/   \\/-\\|___\n");
				printf("    /________\\ /________\\\n");

		}
		else if (input == "2")
		{
			printf("     ____          ____\n");
			printf("    |oooo|        |oooo|\n");
			printf("    |oooo| .----. |oooo|\n");
			printf("    |Oooo|/\\_||_/\\|oooO|\n");
			printf("    `----' / __ \\ `----'\n");
			printf("    ,/ |#|/\\/__\\/\\|#| \\,\n");
			printf("   /  \\|#|| |/\\| ||#|/  \\\n");
			printf("  / \\_/|_|| |/\\| ||_|\\_/ \\\n");
			printf(" |_\\/    o\\=----=/o    \\/_|\n");
			printf(" <_>      |=\\__/=|      <_>\n");
			printf(" <_>      |------|      <_>\n");
			printf(" | |   ___|======|___   | |\n");
			printf("//\\\\  / |O|======|O| \\  //\\\\\n");
			printf("|  |  | |O+------+O| |  |  |\n");
			printf("|\\/|  \\_+/        \\+_/  |\\/|\n");
			printf("\\__/  _|||        |||_  \\__/\n");
			printf("      | ||        || |\n");
			printf("     [==|]        [|==]\n");
			printf("     [===]        [===]\n");
			printf("      >_<          >_<\n");
			printf("     || ||        || ||\n");
			printf("     || ||        || ||\n");
			printf("     || ||        || ||    -- Jay Thaler\n");
			printf("   __|\\_/|__    __|\\_/|__\n");
			printf("  /___n_n___\\  /___n_n___\\\n");
		}
		else if (input == "3")
		{
			printf("      ______________\n");
			printf("     `--------------'\n");
			printf("  _.  .--./|  |\\.--.  ._\n");
			printf(" //|  |--||----||--|  |\\\\\n");
			printf("||__\\_|  ||____||  |_/__||\n");
			printf("||_-- |__|||==|||__| --_||\n");
			printf("||_() |___||--||___| ()_||\n");
			printf("|| --_|   ||__||   |_-- ||\n");
			printf("||||  |---||__||---|  ||||\n");
			printf(" \\|| /|___||__||___|\\_||/\n");
			printf(" |||_| \\.||||||||./ |_|||\n");
			printf(" \\ _ /   \\--==--/   \\ _ /\n");
			printf("  <_>  /----------\\  <_>\n");
			printf("  ||| _\\__ |  | __/_ |||\n");
			printf("  ||| \\  |\\|  |/|  / |||\n");
			printf("  ||| |  |_|__|_|  | |||\n");
			printf("  ||| [--+ \\  / +--] |||\n");
			printf("  ||| |--+-/  \\-+--| |||\n");
			printf("  ||| |  ||    ||  | |||\n");
			printf("  |=| |___|    |___| |=|\n");
			printf("  / \\ |---|    |---| / \\\n");
			printf("  |=| | | |    | | | |=|\n");
			printf("  \\ / |___|    |___| \\ /\n");
			printf("   = (| | ||  || | |) =\n");
			printf("      |--_||  ||_--| \n");
			printf("     _|_#__|  |__#_|_     -- Jay Thaler\n");
			printf("    /______\\  /______\\\n");
			printf("   |________||________|\n");
		}
		else if (input == "4")
		{
			break;
		}
		else
		{
			printf("Incorrect input detected\n");
		}
		_getch();
		continue;
		
	
	}
	return 0;
}

