// Competency Test stuff.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <iostream>
#include <string> // Needed for string
#include <stdlib.h> // Needed for srand
#include <time.h> // Needed for srand
#include <conio.h> 
#include <vector>
#include <windows.h> // Uses functions named after shapes beware for classes
#include <chrono> // needed for sleep for
#include <thread>
#include <math.h>
#include <sstream> // needed for files
#include <fstream> // needed for files
#include <cwchar>
#include <algorithm> // needed for vector sort
/*
enum size {each = 1, dozen = 12, gross = 144 };

int main()
{
    size boxes;
    size envelopes;

    envelopes = dozen;
    boxes = each;
}
*/

struct person
{
    string firstName;
    string lastName;

    char middleInitial;

    int age;

    float height;
};

int main()
{
    person p;

    printf("Please enter your first name: ");
    cin >> p.firstName;
    printf("Please enter your middle initial: ");
    cin >> p.middleInitial;
    printf("Please enter your last name: ");
    cin >> p.lastName;
    printf("Please enter your age: ");
    cin >> p.age;
    printf("Please enter your height (use a . to seperate feet and inches, ex. 5.11 for 5 feet 11 inches): ");
    cin >> p.height;
}