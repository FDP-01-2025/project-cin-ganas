#ifndef PET_H
#define PET_H

#include <iostream>
using namespace std;

// Define the Struct of the Pet

struct Pet
{
    string pet; // Owl, Squirrell, Parrot
    string name;
    int happiness;
    int energy;
    int hunger;
    int coins;
    bool isAlive;
    long long last_saved;
};

#endif