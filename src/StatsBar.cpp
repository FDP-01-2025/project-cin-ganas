#include <iostream>
#include "Pet.h"
using namespace std;

void PrintBarStat(const string &label, int value, int maxValue = 100) //generates a bar that represents the atributes of pet
{
    int barLength = 20;
    int filled = (value * barLength) / maxValue; 
    int empty = barLength - filled; //empty is the complement of filled

    cout << label << ": ["; //opens the bar
    for (int i = 0; i < filled; ++i) //filled bar
        cout << "#";
    for (int i = 0; i < empty; ++i) //"empty" bar
        cout << "-";
    cout << "] " << value << "/" << maxValue << endl;  //ends the bar
}