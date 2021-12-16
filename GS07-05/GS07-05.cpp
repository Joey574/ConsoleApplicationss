/*
Author: Joey Soroka
File Name: GS07-05
Project Name: GS07-05 (slope of a line)
Purpose:
Pseudocode:
Maintenance Log:
12/15/21:   Added struct for points, and function to calculate slope between two points
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

float slope(struct points p);

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

    while (1)
    {
        system("CLS");
        if (p.x1 == p.x2 && p.y1 == p.y2)
        {
            printf("Error: Points are the same... Please reenter the second point...\n");
            printf("Point Two:\nX: ");
            cin >> p.x2;
            printf("Y: ");
            cin >> p.y2;
            continue;
        }
        else if (p.x1 == p.x2)
        {
            printf("Error: X values are the same, slope is infinite... Please reenter the second point...\n");
            printf("Point Two:\nX: ");
            cin >> p.x2;
            printf("Y: ");
            cin >> p.y2;
            continue;
        }
        break;

    }

    float output = slope(p);
    system("CLS");
    cout << "Slope: " << output;
}

float slope(struct points p)
{
    float slope = (p.y2 - p.y1) / (p.x2 - p.x1);
    return slope;
}