/*
Author: Joey Soroka
File Name: Non-looping Maze.cpp
Project Name: Non-looping Maze
Purpose: To create a maze in which you go through several different doors to try to find the end and every time to go to a new room the door will close behind you
Pseudocode: Asks user which way they would like to go, all directions are nested in if statements, provides a victory screen if you win and defeat if you reach a dead end
Maintenance Log:
11/10/21:   Added all the nexting for the maze, code is complete
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
    printf("Welcome to my maze, in this maze you will start in a room with several different doors you can go through, however when you go through a door it will lock behind you, so beware!\n");
    _getch();
    system("CLS");
    printf("1. Go right\n2. Go down\n");
    cin >> input;
    system("CLS");

    if (input == "1")
    {
        printf("1. Go right\n2. Go down\n");
        cin >> input;
        system("CLS");

        if (input == "1")
        {
            printf("Dead end! That sucks, good luck next time.\n");
            _getch();
        }
        else if (input == "2")
        {
            printf("1. Go right\n2. Go left\n");
            cin >> input;
            system("CLS");

            if (input == "1")
            {
                printf("Dead end! That sucks, good luck next time.\n");
                _getch();
            }
            else if (input == "2")
            {
                printf("1. Go up\n2. Go down\n");
                cin >> input;
                system("CLS");

                if (input == "1")
                {
                    printf("Dead end! That sucks, good luck next time.\n");
                    _getch();
                }
                else if (input == "2")
                {
                    printf("1. Go right\n");
                    cin >> input;
                    system("CLS");

                    if (input == "1")
                    {
                        printf("1. Go right\n");
                        cin >> input;
                        system("CLS");

                        if (input == "1")
                        {
                            printf("You win! Congratulations!\n");
                            _getch();
                            system("CLS");
                        }
                    }
                }
            }
        }
    }
    else if (input == "2")
    {
        printf("1. Go right\n2. Go down\n");
        cin >> input;
        system("CLS");

        if (input == "1")
        {
            printf("1. Go right\n2. Go up\n");
            cin >> input;
            system("CLS");

            if (input == "1")
            {
                printf("Dead end! That sucks, good luck next time.\n");
                _getch();
            }
            else if (input == "2")
            {
                printf("1. Go right\n2. Go left\n");
                cin >> input;
                system("CLS");

                if (input == "1")
                {
                    printf("Dead end! That sucks, good luck next time.\n");
                    _getch();
                }
                else if (input == "2")
                {
                    printf("Dead end! That sucks, good luck next time.\n");
                    _getch();
                }
            }
        }
        else if (input == "2")
        {
            printf("1. Go right\n");
            cin >> input;
            system("CLS");

            if (input == "1")
            {
                printf("1. Go right\n");
                cin >> input;
                system("CLS");

                if (input == "1")
                {
                    printf("You win! Congratulations!\n");
                    _getch();
                    system("CLS");
                }
            }
        }
    }

    return 0;
}

