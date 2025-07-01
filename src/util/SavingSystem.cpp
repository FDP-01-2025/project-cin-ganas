#include <iostream>
#include <fstream>
#include "../pet/Pet.h"
using namespace std;

void Save(const Pet &p) // writes into a txt file the pet's variables
{
    ofstream savefile("save.txt");
    savefile << p.pet << "\n";
    savefile << p.name << "\n";
    savefile << p.happiness << "\n";
    savefile << p.energy << "\n";
    savefile << p.hunger << "\n";
    savefile << (p.isAlive ? 1 : 0) << "\n";
    savefile.close();
}

Pet Load() // reads from the txt file the pet's stats
{
    Pet p;
    ifstream savefile("save.txt");
    getline(savefile, p.pet);
    getline(savefile, p.name);
    savefile >> p.happiness;
    savefile >> p.energy;
    savefile >> p.hunger;
    savefile >> p.isAlive;

    savefile.close();
    return p;
}

// This function checks if the file exists
bool FileExist()
{
    ifstream file("save.txt"); // Checks if the file "save.txt" exist
    return file.good();        // Returns true if the file exists
}