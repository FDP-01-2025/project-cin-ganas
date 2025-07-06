#include <iostream>
#include <cstdlib>
using namespace std;

#include "StartScreen.h"
#include "CreditsScreen.h"
#include "../util/IntValidation.h"
#include "../util/SavingSystem.h"
#include "Instructions.h"
#include "CreatePetScreen.h"
#include "MainMenu.h"

/**
 * This Script will show the Start Screen and it will serve as the handler for the Start Menu
 */
int ShowStartScreen()
{
    // Variables
    int userOption = 0;

    system("cls"); // Always clear the console at the start of the game
    cout << R"(
                     ________                                    __    __   ______    ______  
                    /        |                                  /  |  /  | /      \  /      \ 
                    $$$$$$$$/   ______   _____  ____    ______  $$ |  $$ |/$$$$$$  |/$$$$$$  |
                       $$ |    /      \ /     \/    \  /      \ $$ |  $$ |$$ |  $$/ $$ |__$$ |
                       $$ |    $$$$$$  |$$$$$$ $$$$  | $$$$$$  |$$ |  $$ |$$ |      $$    $$ |
                       $$ |    /    $$ |$$ | $$ | $$ | /    $$ |$$ |  $$ |$$ |   __ $$$$$$$$ |
                       $$ |   /$$$$$$$ |$$ | $$ | $$ |/$$$$$$$ |$$ \__$$ |$$ \__/  |$$ |  $$ |
                       $$ |   $$    $$ |$$ | $$ | $$ |$$    $$ |$$    $$/ $$    $$/ $$ |  $$ |
                       $$/     $$$$$$$/ $$/  $$/  $$/  $$$$$$$/  $$$$$$/   $$$$$$/  $$/   $$/                                                           
    

                                          +---------------------------+
                                          | 1. Jugar                  |
                                          | 2. Ver Instrucciones      |
                                          | 3. Ver Creditos           |
                                          | 4. Salir                  |
                                          +---------------------------+

Ingresa tu Opcion: 
)";

    do
    {
        userOption = validateInt(); // Ask the user for an option (must be an int)

        switch (userOption)
        {
        case 1:
            if (FileExist())
            {
                Pet savedPet = Load(); // Load saved pet
                MainMenu(savedPet);    // Go to main menu
            }
            else
            {
                ShowCreatePetScreen(); // Create a new pet
            }
            break;
        case 2:
            system("cls");
            ShowInstructions(); // Show instructions screen
            break;
        case 3:
            system("cls");
            ShowCreditsScreen(); // Show credits screen
            break;
        case 4:
            cout << "Saliendo del juego...\n";
            return 0; // Exit function with return
        default:
            cout << "Por Favor. Ingrese una Opcion Valida:\n";
            break;
        }

    } while (true);
}
