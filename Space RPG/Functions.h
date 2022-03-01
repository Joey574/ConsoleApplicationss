#pragma once

#include <string> // Needed for string
#include <stdlib.h> // Needed for srand
#include <time.h> // Needed for srand
#include <conio.h> 
#include <vector>
#include <windows.h> // Uses functions named after shapes beware for classes
#include <algorithm>


void gotoxy(int x, int y) // credit: Miyoshi
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void invalidInput()
{
	printf("Invalid input");
	Sleep(200);
	printf(".");
	Sleep(200);
	printf(".");
	Sleep(200);
	printf(".");
	Sleep(500);
}

void introArt()
{
	system("CLS");
	printf("                     `. ___\n");
	printf("                   __,' __`.                _..----....____\n");
	printf("       __...--.'``;.   ,.   ;``--..__     .'    ,-._    _.-'\n");
	printf("  _..-''-------'   `'   `'   `'     O ``-''._   (,;') _,'\n");
	printf(",'________________                          \\`-._`-','\n");
	printf(" `._              ```````````------...___   '-.._'-:\n");
	printf("    ```--.._      ,.                     ````--...__\\-.\n");
	printf("            `.--. `-`                       ____    |  |`\n");
	printf("              `. `.                       ,'`````.  ;  ;`\n");
	printf("                `._`.        __________   `.      \\'__/`\n");
	printf("                   `-:._____/______/___/____`.     \\  `\n");
	printf("                              |       `._    `.    \\\n");
	printf("                              `._________`-.   `.   `.___\n");
	printf("                                                 `------'`\n");
	printf("\n  _________  __           .__   .__                   \n");
	printf(" /   _____/_/  |_   ____  |  |  |  |  _____   _______ \n");
	printf(" \\_____  \\ \\   __\\_/ __ \\ |  |  |  |  \\__  \\  \\_  __ \\\n");
	printf(" /        \\ |  |  \\  ___/ |  |__|  |__ / __ \\_ |  | \\/\n");
	printf("/_______  / |__|   \\___  >|____/|____/(____  / |__|   \n");
	printf("        \\/             \\/                  \\/         \n");
	printf("__________                                            __           \n");
	printf("\\______   \\  ____    _____    ____  _____     ____  _/  |_   ______\n");
	printf(" |       _/_/ __ \\  /     \\  /    \\ \\__  \\   /    \\ \\   __\\ /  ___/\n");
	printf(" |    |   \\\\  ___/ |  Y Y  \\|   |  \\ / __ \\_|   |  \\ |  |   \\___ \\ \n");
	printf(" |____|_  / \\___  >|__|_|  /|___|  /(____  /|___|  / |__|  /____  >\n");
	printf("        \\/      \\/       \\/      \\/      \\/      \\/             \\/ \n");
	printf("\nBy: Joey Soroka\n");
	_getch();
}

void menuArt()
{
	int ascX = 25;
	int ascY = 5;

		system("CLS");
		gotoxy(ascX, ascY);
		printf("                                ....");
		gotoxy(ascX, ascY + 1);
		printf("                                /   `.");
		gotoxy(ascX, ascY + 2);
		printf("                               |      `,");
		gotoxy(ascX, ascY + 3);
		printf("		                 -.   ,'		  ");
		gotoxy(ascX, ascY + 4);
		printf("                                   `-/ \\				  ");
		gotoxy(ascX, ascY + 5);
		printf("                                  ,'    ;				  ");
		gotoxy(ascX, ascY + 6);
		printf("                                ,'     /      ____		  ");
		gotoxy(ascX, ascY + 7);
		printf("                        ______,i     __-  ,'''__  `._	  ");
		gotoxy(ascX, ascY + 8);
		printf("                       /        `-,-'  `-+ /''XX`-.. `.	  ");
		gotoxy(ascX, ascY + 9);
		printf("                      /    ,'-._    ``-.i,'XXXXXXXX`.  :  ");
		gotoxy(ascX, ascY + 10);
		printf("                     /  .--  ._ `-,_     \\XXXXXXXXXX/ |	  ");
		gotoxy(ascX, ascY + 11);
		printf("                     |   `.  `.  /XX`..   \\XXXXXXXX| .'	  ");
		gotoxy(ascX, ascY + 12);
		printf("                   ,'|  .i> `. .'XXXXXX/-. -._XXX_/ ,'	  ");
		gotoxy(ascX, ascY + 13);
		printf("                 ,'  ',.:>_.'','XXXXXX/  ,`-. `. _,'\\  _  ");
		gotoxy(ascX, ascY + 14);
		printf("               ,'    /   _ `./XXXXXX,'  / /  `. '.  ,+' `.");
		gotoxy(ascX, ascY + 15);
		printf("             ,'     /   -_` /XXXXXX/  ,',',- , `.<-'    ,'");
		gotoxy(ascX, ascY + 16);
		printf("           ,'      /   :- ;'XXXXXX/  /,',' ,',  ,-.   ,'  ");
		gotoxy(ascX, ascY + 17);
		printf("         ,'       :  ._ `,'XXXXXX/ ,'/,'_,',',-'XX,-,'	  ");
		gotoxy(ascX, ascY + 18);
		printf("       ,'        _ `-.  /XXXXXXX/ /,;',',-','XXX,:`		  ");
		gotoxy(ascX, ascY + 19);
		printf("      `    _,'-,- `-..i`.XXXXX,' /`/,',',-'XX_X'  `,	  ");
		gotoxy(ascX, ascY + 20);
		printf("       `.,'   ,'      \\  `=.X,',' ;',','XX,,'\\\\  ,:		  ");
		gotoxy(ascX, ascY + 21);
		printf("            ,'`.       |,;' `-.  - i,'XXX,'    -' |		  ");
		gotoxy(ascX, ascY + 22);
		printf("          ,'    `    ,' .i     `-,'XXXX,'`.    ,-'		  ");
		gotoxy(ascX, ascY + 23);
		printf("         /         ,' ,'  `-..    ;-,,;'   `,,'			  ");
		gotoxy(ascX, ascY + 24);
		printf("       ,'    `.  ,' ,-        \\ ,'  ,:    ,'			  ");
		gotoxy(ascX, ascY + 25);
		printf("      |        ,' ,'       .  ,'  ,'  `-<'				  ");
		gotoxy(ascX, ascY + 26);
		printf("    ,-._     ,' ,'     -.  ,-'  ,'						  ");
		gotoxy(ascX, ascY + 27);
		printf("  ,'       ,'_,'   _    ,`'    |						  ");
		gotoxy(ascX, ascY + 28);
		printf(" \\       ,','       `,-:    _,/							  ");
		gotoxy(ascX, ascY + 29);
		printf(" \\     ,' '       ,-'   --''							  ");
		gotoxy(ascX, ascY + 30);
		printf("  '`-<' ,'   \\ ,-'										  ");
		gotoxy(ascX, ascY + 31);
		printf("        |    ,'											  ");
		gotoxy(ascX, ascY + 32);
		printf("        \\  _'											  ");
		gotoxy(ascX, ascY + 33);
		printf("         '-												  ");
		gotoxy(0, 0);

}

void mainMenu(bool inGame)
{
	string input;
	string temp;

	int iTemp;

	while (1)
	{


		if (inGame == false) // check to see if game has already been started
		{
			printf("Menu:\n1: Start Game\n2: High Scores\n3: Help\n4: Credits\n5: Save/Load\n6: Exit\nInput: "); // not started
		}
		else
		{
			printf("Menu:\n1: Resume Game\n2: High Scores\n3: Help\n4: Credits\n5: Save/Load\n6: Exit\nInput: "); // has started
		}

		cin >> input;
		system("CLS");

		if (input == "1") // start or resume game
		{
			if (inGame == false) // check to see if game has already been started
			{
				gameStart(player, ship);
				inGame = true;
			}
			break;
		}

		else if (input == "2") // high scores, add possibility to see details about high scores in the future
		{
			printf("Top 10 High Scores:\n");

			ifstream highScores;

			highScores.open("highScores.txt");

			if (!highScores.is_open())
			{
				printf("File not found");
			}

			vectorScore.clear(); // clear vector from any information from earlier use

			while (getline(highScores, temp))
			{
				iTemp = stoi(temp); // turns temp line from highScores.txt into int temp
				vectorScore.push_back(iTemp);
			}
			sort(vectorScore.rbegin(), vectorScore.rend()); // sorts the scores in vector from highest to lowest

			for (int i = 1; i < 11; i++) // runs 10 times
			{
				cout << i << ") " << vectorScore[i - 1] << endl; // outputs top 10 high scores
			}

			highScores.close();
			_getch();
		}

		else if (input == "3") // help
		{
			printf("Menu:\n1: Account\n2: Difficulty\n3: Reset High Scores\n4: Back\nInput: "); // help menu
			cin >> input;
			system("CLS");

			if (input == "1") // account
			{
				printf("Menu:\n1: Change name\n2: Back\nInput: "); // account menu
				cin >> input;

				if (input == "1") // change name
				{
					printf("Please enter new name: ");
					cin >> player.name;
					continue;
				}

				else if (input == "2") // back
				{
					continue;
				}

				else
				{
					invalidInput();
					continue;
				}

			}

			else if (input == "2") // change difficulty
			{
				printf("Difficulty:\n1: Easy\n2: Medium\n3: Hard\n4: Back\nInput: "); // change difficulty menu
				cin >> input;


				while (input != "1" && input != "2" && input != "3" && input != "4")
				{
					printf("Invalid input try again\nInput: ");
					cin >> input;
				}

				if (input == "4") // back
				{
					continue;
				}

				player.difficulty = stoi(input);
				continue;
			}
			else if (input == "3") // reset high scores
			{
				printf("Are you sure you want to reset your high scores?\n1: Yes\n2: No\nInput: ");
				cin >> input;
				if (input == "1")
				{
					ofstream highScores;

					highScores.open("highScores.txt", ios::out | ios::trunc); // opens highscores.txt and resets data

					for (int i = 0; i < 9; i++) // runs 9 times
					{
						highScores << "0\n";
					}
					highScores << "0";

					highScores.close();
				}
				else if (input == "2") // back
				{
					continue;
				}
				else
				{
					invalidInput();
					continue;
				}

			}
			else if (input == "4") // back
			{
				continue;
			}
			else
			{
				invalidInput();
				continue;
			}
		}

		else if (input == "4") // credits
		{
		printf("Author:\nJoey Soroka\n\nProgramming Support:\nEric Pace\nKian Darrington\nSlater Swart\nIssac Morine\nTucker Norris\n\nCreative Support:\nIssac Morine\n");
		_getch();
		}

		else if (input == "5") // save / load
		{

		printf("Menu:\n1: Save\n2: Load\n3: Back\nInput: ");
		cin >> input;
		system("CLS");

		if (input == "1" || input == "2")
		{
			if (input == "1")
			{
				printf("Save slots:\n");
			}
			else
			{
				printf("Load save:\n");
			}

			for (int i = 1; i < 4; i++)
			{
				if (i == 1)
				{
					saveFile.open("save1.txt");
				}
				else if (i == 2)
				{
					saveFile.open("save2.txt");
				}
				if (i == 3)
				{
					saveFile.open("save3.txt");
				}
				if (!saveFile.is_open())
				{
					printf("File not found\n");
				}
				for (int p = 0; p < 1; p++)
				{
					getline(saveFile, temp);
					if (temp == "empty")
					{
						cout << i << ": Empty\n";
					}
					else
					{
						cout << i << "Save " << i;
					}
					saveFile.close();
				}

			}

			printf("4: Back\nInput: "); // no cin because branches were previously decided by input but shared first part of code and old input is still needed for if
			if (input == "1") // save
			{
				cin >> input;
				if (input == "1")
				{
					saveName = "save1.txt";
				}
				else if (input == "2")
				{
					saveName = "save2.txt";
				}
				else if (input == "3")
				{
					saveName = "save3.txt";
				}
				else if (input == "4")
				{
					continue;
				}
				else
				{
					invalidInput();
					continue;
				}

			}
			else // load
			{
				cin >> input;
				if (input == "1")
				{
					saveName = "save1.txt";
				}
				else if (input == "2")
				{
					saveName = "save2.txt";
				}
				else if (input == "3")
				{
					saveName = "save3.txt";
				}
				else if (input == "4")
				{
					continue;
				}
				else
				{
					invalidInput();
					continue;
				}

			}



		}
		else if (input == "3")
		{
			continue;
		}
		else
		{
			invalidInput();
			continue;
		}

		}
	}
}