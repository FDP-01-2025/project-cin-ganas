#include <iostream>
#include <windows.h>
#include "SleepOption.h"
#include "../util/SavingSystem.h"
#include "./MainMenu.h"

using namespace std;

void SleepOption(Pet &p)
{
    system("cls"); // Clear the screen

    cout << R"(
                                                  ________            ________ 
                                                 /        |          /        |
                                                 $$$$$$$$/  ________ $$$$$$$$/ 
                                                     /$$/  /        |    /$$/  
                                                    /$$/   $$$$$$$$/    /$$/   
                                                   /$$/      /  $$/    /$$/    
                                                  /$$/____  /$$$$/__  /$$/____ 
                                                 /$$      |/$$      |/$$      |
                                                 $$$$$$$$/ $$$$$$$$/ $$$$$$$$/ 

    )";

    cout << "\n                                                 Tu mascota ha dormido bien!" << endl;
    cout << endl;
    cout << R"(
                                    +----------------------+-------------------------+
                                    |   Atributo           |    Efecto               |
                                    +----------------------+-------------------------+
                                    |   Energia            |   +6                    |
                                    |   Hambre             |   +5                    |
                                    |   Diversion          |   -10                   |
                                    +----------------------+-------------------------+
    )" << endl;

    // Apply sleep effects
    p.energy += 6;
    p.hunger += 5;
    p.happiness -= 10;

    // Clamp values between 0 and 100
    if (p.energy > 100)
        p.energy = 100;
    if (p.energy < 0)
        p.energy = 0;

    if (p.hunger > 100)
        p.hunger = 100;
    if (p.hunger < 0)
        p.hunger = 0;

    if (p.happiness > 100)
        p.happiness = 100;
    if (p.happiness < 0)
        p.happiness = 0;

    Save(p);     // Save updated pet state
    Sleep(5000); // Wait 5 seconds before returning
    MainMenu(p);
}
