/*
Author: Joey Soroka
File Name: GS07-05
Project Name: GS07-05 (slope of a line)
Purpose:
Pseudocode:
Maintenance Log:
12/15/21:   Added struct for points, and function to calculate slope between two points
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

float slope(struct points p[2]);

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

    while (1)
    {
        system("CLS");
        if (p[0].x == p[1].x && p[0].y == p[1].y)
        {
            printf("Error: Points are the same... Please reenter the second point...\n");
            printf("Point Two:\nX: ");
            cin >> p[1].x;
            printf("Y: ");
            cin >> p[1].y;
            continue;
        }
        else if (p[0].x == p[1].x)
        {
            printf("Error: X values are the same, slope is infinite... Please reenter the second point...\n");
            printf("Point Two:\nX: ");
            cin >> p[1].x;
            printf("Y: ");
            cin >> p[1].y;
            continue;
        }
        break;

    }

    float output = slope(p);
    system("CLS");
    cout << "Slope: " << output;

    return 0;
}

float slope(struct points p[2])
{
    float slope = (p[1].y - p[0].y) / (p[1].x - p[0].x);
    return slope;
}