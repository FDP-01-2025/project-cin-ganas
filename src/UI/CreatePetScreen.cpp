#include <iostream>
using namespace std;
#include "../pet/Pet.h"
#include "../util/IntValidation.h"
#include "../util/SavingSystem.h"
#include "MainMenu.h"

// This script is in order to create a new pet
void ShowCreatePetScreen()
{

    // Variables
    int petOption;
    string petName;
    Pet createdPet; // Define a new Struct for the Pet

    system("cls"); // Clear the Screen
    cout << R"(
                  __       __                                            __                         
                 /  \     /  |                                          /  |                        
                 $$  \   /$$ |  ______    _______   _______   ______   _$$ |_     ______    _______ 
                 $$$  \ /$$$ | /      \  /       | /       | /      \ / $$   |   /      \  /       |
                 $$$$  /$$$$ | $$$$$$  |/$$$$$$$/ /$$$$$$$/ /$$$$$$  |$$$$$$/    $$$$$$  |/$$$$$$$/ 
                 $$ $$ $$/$$ | /    $$ |$$      \ $$ |      $$ |  $$ |  $$ | __  /    $$ |$$      \ 
                 $$ |$$$/ $$ |/$$$$$$$ | $$$$$$  |$$ \_____ $$ \__$$ |  $$ |/  |/$$$$$$$ | $$$$$$  |
                 $$ | $/  $$ |$$    $$ |/     $$/ $$       |$$    $$/   $$  $$/ $$    $$ |/     $$/ 
                 $$/      $$/  $$$$$$$/ $$$$$$$/   $$$$$$$/  $$$$$$/     $$$$/   $$$$$$$/ $$$$$$$/  

            
                                              +-------------------------+
                                              | Selecciona una Mascota: |
                                              | 1. Buho                 |
                                              | 2. Ardilla              |
                                              | 3. Perico               |
                                              +-------------------------+
        
              __              __                                                           .---.
              \ `-._......_.-` /                                                       .'  .-.'._
               `.  '.    .'  .'                                                     _/   (  0 / ',
                //  _`\/`_  \\                                                   .-' \   (   /--./
               ||  /\O||O/\  ||             (\__/)  .~ ~~ ~. ))                .'.  ' |'.__.'--'
               |\  \_/||\_/  /|             /O O  ./      .'                 / '-/_, |'  |
               \ '.   \/   .' /           {O__,   \    {                    / /_.   ;    ;
               / ^ `'~  ~'`   \             / .  . )    \                  /_.' , '/    / 
              /  _-^_~ -^_ ~-  |            |-| '-' \    }        ________/_`-'_-' _.-'_______
              | / ^_ -^_- ~_^\ |           .(   _(   )_.'         ______________\\\_\\\_______
              | |~_ ^- _-^_ -| |          '---.~_ _ _&                  |_/,/ .|``` ```    
              | \  ^-~_ ~-_^ / |                                        / \_/-/
              \_/;-.,____,.-;\_/                                        |`| ; |
        ==========(_(_(==)_)_)=========                                 \/' \ /
                                                                         |'.|`
                                                                          \_/

                    [1]                       [2]                           [3]
)";

    do
    {
        // Ask the user for the pet
        cout << "\nIngresa una opcion (1-3):\n";
        petOption = validateInt();

        // Check if the user's pet option is in range
        if (petOption >= 1 && petOption <= 3)
        {
            // If so, ask the user for a name
            // cin.ignore();
            do
            {
                cout << "\nIngresa un nombre para tu mascota:\n";
                getline(cin, petName); // getline cuz the name may contain spaces

                // If the petName is empty
                if (petName.empty())
                {
                    cout << "Por Favor. Ingresa un nombre para tu mascota\n";
                }
            } while (petName.empty());
        }
        else
        {
            cout << "Por Favor. Selecciona una opcion valida\n";
        }
    } while (petOption < 1 || petOption > 3);

    // If the data entered by the user is correct, then create the struct, save it in the .txt file and start the game

    // Create the Struct
    // Check the pet that the user chose
    switch (petOption)
    {
    case 1:
        createdPet.pet = "Owl";
        break;
    case 2:
        createdPet.pet = "Squirrel";
        break;
    case 3:
        createdPet.pet = "Parrot";
        break;
    default:
        cout << "La opcion de mascota ingresada esta fuera de rango\n";
        break;
    }

    createdPet.name = petName;
    createdPet.happiness = 100;
    createdPet.energy = 100;
    createdPet.hunger = 0;
    createdPet.isAlive = true;

    // Save the struct in the .txt file
    Save(createdPet);

    // Star the game (Go to the Main Menu)
    MainMenu(createdPet);
}
