#include <iostream>
#include <fstream>
#include <ctime>
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
    savefile << p.coins << "\n";
    savefile << (p.isAlive ? 1 : 0) << "\n";
    long long currentTime = time(nullptr);
    savefile << currentTime << "\n";
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
    savefile >> p.coins;
    savefile >> p.isAlive;
    savefile >> p.last_saved;

    savefile.close();

    long long now = time(nullptr);
    long long seconds_passed = now - p.last_saved;
    int hours_passed = seconds_passed / 3600;

    if (hours_passed > 0)
    {

        cout << "Han pasado " << hours_passed << " hora(s) desde la ultima vez que estuviste con " << p.name << "." << endl;

        p.hunger += 5 * hours_passed;
        p.energy -= 5 * hours_passed;
        p.happiness -= 5 * hours_passed;

        if (p.hunger > 100)
            p.hunger = 100;

        if (p.energy < 0)
            p.energy = 0;

        if (p.happiness < 0)
            p.happiness = 0;

        if (p.energy > 100)
            p.energy = 100;

        if (p.happiness > 100)
            p.happiness = 100;

        if (p.hunger < 0)
            p.hunger = 0;

        // Here we can see if the pet has died
        if (p.hunger >= 100 || p.energy <= 0 || p.happiness <= 0)
        {
            p.isAlive = false;
            cout << "\nTu mascota ha muerto por descuido...\n";
            remove("save.txt");
        }
    }

    return p;
}

// This function checks if the file exists
bool FileExist()
{
    ifstream file("save.txt"); // Checks if the file "save.txt" exist
    return file.good();        // Returns true if the file exists
}

// Add Coins and save them locally, increase the happiness and hunger, and dicrease the energy
void finishGame(int coins, int happiness, int hunger, int energy)
{
    Pet pet = Load();

    // Increase the happiness and hunger, and dicrease the energy
    pet.coins += coins;
    pet.happiness += happiness;
    pet.hunger += hunger;
    pet.energy -= energy;
    Save(pet);
    cout << "Has Ganado " << coins << " Monedas\n";
    cout << "Felicidad: +" << happiness << endl;
    cout << "Hambre: +" << hunger << endl;
    cout << "Energia: -" << energy << endl;
}
