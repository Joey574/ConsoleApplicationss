/*
Author: Joey Soroka
File Name: GS07-02.cpp
Project Name: GS07-02 (personal data)
Purpose: Collect a users information and store it in a struct
Pseudocode: Asks user for personal information, which is stored in a struct, then uses while loops to ask users if the information is correct, and if not to 
            re-enter it
Maintenance Log:
12/15/21:   Started project, added struct, and loops for collecting user information
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

struct personalData
{
    int age;
    string phoneNumber;
    string firstName;
    string middleName;
    string lastName;
};

int main()
{
    struct personalData p;
    bool done = false;
    string input;

        printf("To confirm your purchase, please enter your personal information...\n");
        _getch();
        system("CLS");
        printf("First Name: ");
        cin >> p.firstName;
        printf("Middle Name: ");
        cin >> p.middleName;
        printf("Last Name: ");
        cin >> p.lastName;
        printf("Age: ");
        cin >> p.age;
        printf("Phone Number: ");
        cin >> p.phoneNumber;
       
        while (1)
        {
            system("CLS");
            printf("Confirm the information below (y/n):\n");
            cout << p.firstName << endl;
            cin >> input;
            if (input == "n")
            {
                printf("Please enter the correct information:\nFirst Name: ");
                cin >> p.firstName;
                continue;
            }
            break;
        }
        while (1)
        {
            system("CLS");
            printf("Confirm the information below (y/n):\n");
            cout << p.middleName << endl;
            cin >> input;
            if (input == "n")
            {
                printf("Please enter the correct information:\nMiddle Name: ");
                cin >> p.middleName;
                continue;
            }
            break;
        }
        while (1)
        {
            system("CLS");
            printf("Confirm the information below (y/n):\n");
            cout << p.lastName << endl;
            cin >> input;
            if (input == "n")
            {
                printf("Please enter the correct information:\nLast Name: ");
                cin >> p.lastName;
                continue;
            }
            break;
        }
        while (1)
        {
            system("CLS");
            printf("Confirm the information below (y/n):\n");
            cout << p.age << endl;
            cin >> input;
            if (input == "n")
            {
                printf("Please enter the correct information:\nAge: ");
                cin >> p.age;
                continue;
            }
            break;
        }
        while (1)
        {
            system("CLS");
            printf("Confirm the information below (y/n):\n");
            cout << p.phoneNumber << endl;
            cin >> input;
            if (input == "n")
            {
                printf("Please enter the correct information:\nPhone Number: ");
                cin >> p.phoneNumber;
                continue;
            }
            break;
        }
    system("CLS");
    printf("Your information will be handled with care, thank you for your cooperation!\n");

    return 0;
}
