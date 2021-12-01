// Competency Test stuff.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int i1 = 5;
    int i2 = -2;
    int i3 = 1;

    if (i1 >= 0 && i2 >= 0 && i3 >= 0)
    {
        printf("all numbers are positive");
    }
    else if (i1 <= 0 && i2 <= 0 && i3 <= 0)
    {
        printf("no numbers are positive");
    }
    else
    {
        printf("some numbers are positive");
    }
    // return 0;
    // 
    // --------------------------------

    int iAns;
    std::cin >> iAns;

    switch (iAns)
    {
    case 3:
        printf("correct you inputed 3!");
        break;
    case 5:
        printf("correct you inputed 5!");
        break;
    case 11:
        printf("correct you inputed 11!");
        break;
    case 13:
        printf("correct you inputed 13!");
        break;
    case 17:
        printf("correct you inputed 17!");
        break;
    default:
        printf("man some people are unteachable *dissapointed eye roll*");
        break;
    }
    return 0;
}
