#include <iostream>
using namespace std;
#include "src/StartScreen.h"

// Define the Struct of the Pet
struct Pet
{
    string pet = ""; // Owl, Squirrell, Parrot
    string name = "";
    int happiness = 0;
    int energy = 0;
    int hunger = 0;
};

main()
{
    // Show the StartScreen (the game title + the main menu)
    ShowStartScreen();

    return 0;
}
