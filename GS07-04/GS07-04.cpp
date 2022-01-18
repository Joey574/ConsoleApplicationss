/*
Author: Joey Soroka
File Name: GS07-04.cpp
Project Name: GS07-04 (distance between points)
Purpose: Create a program that lets the user input the x and y of 2 points and calculates the distance between them
Pseudocode: Asks user for x and y of 2 points, stores inputs in a struct, before passing them to a function that will calculate the distance between the points
Maintenance Log:
12/15/21:   Added struct for points as well as function to calculate distance
1/18/22:    Changed struct to be more efficient
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
    float x;
    float y;
};

float distance(struct points p[2]);

int main()
{
    struct points p[2];

    printf("Point One:\nX: ");
    cin >> p[0].x;
    printf("Y: ");
    cin >> p[0].y;
    printf("Point Two:\nX: ");
    cin >> p[1].x;
    printf("Y: ");
    cin >> p[1].y;
    float dist = distance(p);
    system("CLS");
    cout << "Distance: " << dist;
}

float distance(struct points p[2])
{
    float dist = ((p[0].x - p[1].x) * (p[0].x - p[1].x)) + ((p[0].y - p[1].y) * (p[0].y - p[1].y));
    dist = sqrt(dist);

    return dist;
}