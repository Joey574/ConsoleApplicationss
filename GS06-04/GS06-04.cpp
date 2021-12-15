/*
Author: Joey Soroka
File Name: GS06-04.cpp
Project Name: Problem GS06-04 (function maze)
Purpose: Create a maze that uses functions for each room
Pseudocode: Uses struct for input and room variables, then checks bools for what room user is in, sends struct info along as well where it can be updated inside the function based on user input
Maintenance Log:
12/14/21:   Started project, added struct, and 11 different voids for rooms
*/

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <windows.h>
using namespace std;

struct rooms
{
    bool room1 = true;
    bool room2 = false;
    bool room3 = false;
    bool room4 = false;
    bool room5 = false;
    bool room6 = false;
    bool room7 = false;
    bool room8 = false;
    bool room9 = false;
    bool room10 = false;
    bool room11 = false;
    bool room12 = false;
    string input;
};

void mazeRoom1(struct rooms &r);
void mazeRoom2(struct rooms &r);
void mazeRoom3(struct rooms &r);
void mazeRoom4(struct rooms &r);
void mazeRoom5(struct rooms &r);
void mazeRoom6(struct rooms &r);
void mazeRoom7(struct rooms &r);
void mazeRoom8(struct rooms &r);
void mazeRoom9(struct rooms &r);
void mazeRoom10(struct rooms &r);
void mazeRoom11(struct rooms &r);



int main()
{
    struct rooms r;

    printf("Welcome to my maze, there are 12 rooms, press any key to start\n");
    _getch();

    while (r.room12 == false)
    {
        system("CLS");
        if (r.room1 == true)
        {
            mazeRoom1(r);
        }
        else if (r.room2 == true)
        {
            mazeRoom2(r);
        }
        else if (r.room3 == true)
        {
            mazeRoom3(r);
        }
        else if (r.room4 == true)
        {
            mazeRoom4(r);
        }
        else if (r.room5 == true)
        {
            mazeRoom5(r);
        }
        else if (r.room6 == true)
        {
            mazeRoom6(r);
        }
        else if (r.room7 == true)
        {
            mazeRoom7(r);
        }
        else if (r.room8 == true)
        {
            mazeRoom8(r);
        }
        else if (r.room9 == true)
        {
            mazeRoom9(r);
        }
        else if (r.room10 == true)
        {
            mazeRoom10(r);
        }
        else if (r.room11 == true)
        {
            mazeRoom11(r);
        }
    }
    printf("Wow you did it!");

    return 0;
}

void mazeRoom1(struct rooms &r)
{
    printf("1. Go right\n2. Go down\n");
    cin >> r.input;
    if (r.input == "1")
    {
        r.room2 = true;
    }
    else if (r.input == "2")
    {
        r.room5 = true;
    }
    r.room1 = false;
}

void mazeRoom2(struct rooms &r)
{
    printf("1. Go left\n2. Go right\n3. Go down\n");
    cin >> r.input;
    if (r.input == "1")
    {
        r.room1 = true;
    }
    else if (r.input == "2")
    {
        r.room3 = true;
    }
    else if (r.input == "3")
    {
        r.room6 = true;
    }
    r.room2 = false;
}

void mazeRoom3(struct rooms &r)
{
    printf("1. Go left\n2. Go right\n3. Go down\n");
    cin >> r.input;
    if (r.input == "1")
    {
        r.room2 = true;
    }
    else if (r.input == "2")
    {
        r.room4 = true;
    }
    else if (r.input == "3")
    {
        r.room7 = true;
    }
    r.room3 = false;
}

void mazeRoom4(struct rooms &r)
{
    printf("1. Go left\n2. Go down\n");
    cin >> r.input;
    if (r.input == "1")
    {
        r.room3 = true;
    }
    else if (r.input == "2")
    {
        r.room8 = true;
    }
    r.room4 = false;
}

void mazeRoom5(struct rooms &r)
{
    printf("1. Go up\n2. Go right\n3. Go down\n");
    cin >> r.input;
    if (r.input == "1")
    {
        r.room1 = true;
    }
    else if (r.input == "2")
    {
        r.room6 = true;
    }
    else if (r.input == "3")
    {
        r.room9 = true;
    }
    r.room5 = false;
}

void mazeRoom6(struct rooms &r)
{
    printf("1.Go up\n2. Go left\n3. Go right\n4. Go down\n");
    cin >> r.input;
    if (r.input == "1")
    {
        r.room2 = true;
    }
    else if (r.input == "2")
    {
        r.room5 = true;
    }
    else if (r.input == "3")
    {
        r.room7 = true;
    }
    else if (r.input == "4")
    {
        r.room10 = true;
    }
    r.room6 = false;
}

void mazeRoom7(struct rooms &r)
{
    printf("1.Go up\n2. Go left\n3. Go right\n4. Go down\n");
    cin >> r.input;
    if (r.input == "1")
    {
        r.room3 = true;
    }
    else if (r.input == "2")
    {
        r.room6 = true;
    }
    else if (r.input == "3")
    {
        r.room8 = true;
    }
    else if (r.input == "4")
    {
        r.room11 = true;
    }
    r.room7 = false;
}

void mazeRoom8(struct rooms &r)
{
    printf("1. Go up\n2. Go left\n3. Go down\n");
    cin >> r.input;
    if (r.input == "1")
    {
        r.room4 = true;
    }
    else if (r.input == "2")
    {
        r.room7 = true;
    }
    else if (r.input == "3")
    {
        r.room12 = true;
    }
    r.room8 = false;
}

void mazeRoom9(struct rooms &r)
{
    printf("1. Go up\n2. Go right\n");
    cin >> r.input;
    if (r.input == "1")
    {
        r.room5 = true;
    }
    else if (r.input == "2")
    {
        r.room10 = true;
    }
    r.room9 = false;
}

void mazeRoom10(struct rooms &r)
{
    printf("1. Go up\n2. Go left\n3. Go right\n");
    cin >> r.input;
    if (r.input == "1")
    {
        r.room6 = true;
    }
    else if (r.input == "2")
    {
        r.room9 = true;
    }
    else if (r.input == "3")
    {
        r.room11 = true;
    }
    r.room10 = false;
}

void mazeRoom11(struct rooms &r)
{
    printf("1. Go up\n2. Go left\n3. Go right\n");
    cin >> r.input;
    if (r.input == "1")
    {
        r.room7 = true;
    }
    else if (r.input == "2")
    {
        r.room10 = true;
    }
    else if (r.input == "3")
    {
        r.room12 = true;
    }
    r.room11 = false;
}
