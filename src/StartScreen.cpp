#include <iostream>
#include <cstdlib>
using namespace std;
#include "StartScreen.h"
#include "CreditsScreen.h"

/**
 * This Script will show the Start Screen and it will serve as the handler for the Start Menu
 */
void ShowStartScreen()
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
                                          | 2. Ver Creditos           |
                                          +---------------------------+

Ingresa tu Opcion: 
)";

    cin >> userOption;

    // Validate the user's option
    switch (userOption)
    {
    case 1:
        break;
    case 2:
        // Go to the Credits Screen
        system("cls");
        ShowCreditsScreen();
        break;
    default:
        cout << "Por Favor. Ingrese una Opcion Valida\n";
        break;
    }
}
