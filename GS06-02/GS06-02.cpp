/*
Author: Eric Pace
Co-Author: Joey Soroka
*Title: square root reducer
* File Name : GS06-02.cpp
* Purpose: yr i.y yd.o. xcyjd.o rgya d.p.
* Pseudocode:
* Maintenence log:
*/

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <windows.h>
using namespace std;

int RootReducer(int num);

int main()
{
	int num;
	int radical = 251;
	bool imaginary = false;
		while (1)
		{
			system("CLS");
			cout << "Enter a number above -65537 and under 65537.\n";
			cin >> num;
			system("CLS");
			if (num > 65536 || num < -65536)
			{
				printf("Read the instructions and try again.\n");
				Sleep(2000);
				continue;
			}

			if (num < 0)
			{
				num *= -1;
				imaginary = true;
			}

				int root = RootReducer(num);
				int radicand = num / (root * root);
				system("CLS");

				if (imaginary == true && root > 1)
				{
					cout << "Your square root is: " << root << "i" << (char)radical << radicand << endl;
				}
				else if (imaginary == true && radicand > 1)
				{
					cout << "Your square root is: " << "i" << (char)radical << radicand << endl;
				}
				else if (imaginary == true)
				{
					cout << "Your square root is: " << root << "i"<< endl;
				}
				else if (radicand > 1)
				{
					cout << "Your square root is: " << root << (char)radical << radicand << endl;
				}
				else
				{
					cout << "Your square root is: " << root << endl;
				}
			_getch();
		}
}

int RootReducer(int num)
{
	int root;
	for (int i = num - 1; 0 < i; i--)
	{
		if (num % (i * i) == 0)
		{
			root = i;
			break;
		}
	}
	return root;
}