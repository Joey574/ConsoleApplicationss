/*

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
		printf("Select which ASCII art you would like to see\n1. Robot\n2.");

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
			_getch();
			continue;
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
			printf(" <_>      |------|      <_>");
			printf(" | |   ___|======|___   | |\n");
			printf("//\\\\  / |O|======|O| \\  //\\\\\n");
		}
	
	}
	return 0;
}

