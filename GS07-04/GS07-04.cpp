/*
Author: Joey Soroka
File Name: GS07-04.cpp
Project Name: GS07-04 (distance between points)
Purpose: Create a program that lets the user input the x and y of 2 points and calculates the distance between them
Pseudocode: Asks user for x and y of 2 points, stores inputs in a struct, before passing them to a function that will calculate the distance between the points
Maintenance Log:
12/15/21:   Added struct for points as well as function to calculate distance
*/

#include <stdio.h>
#include <iostream>
#include <string> // Needed for string
#include <stdlib.h> // Needed for srand
#include <time.h> // Needed for srand
#include <conio.h> 
#include <vector>
#include <windows.h>
#include <math.h>
using namespace std;

struct points
{
    float x1;
    float y1;
    float x2;
    float y2;
};

float distance(struct points p);

int main()
{
    struct points p;

    printf("Point One:\nX: ");
    cin >> p.x1;
    printf("Y: ");
    cin >> p.y1;
    printf("Point Two:\nX: ");
    cin >> p.x2;
    printf("Y: ");
    cin >> p.y2;
    float dist = distance(p);
    system("CLS");
    cout << "Distance: " << dist;
}

float distance(struct points p)
{
    float dist = ((p.x1 - p.x2) * (p.x1 - p.x2)) + ((p.y1 - p.y2) * (p.y1 - p.y2));
    dist = sqrt(dist);

    return dist;
}