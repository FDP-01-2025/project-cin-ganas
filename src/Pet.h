#ifndef PET_H
#define PET_H

#include <iostream>
using namespace std;

// Define the Struct of the Pet

struct Pet
{
    string pet = ""; // Owl, Squirrell, Parrot
    string name = "";
    int happiness = 0;
    int energy = 0;
    int hunger = 0;
    bool isAlive; 
};

#endif