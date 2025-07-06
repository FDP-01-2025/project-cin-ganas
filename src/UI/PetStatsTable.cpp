#include <iostream>
using namespace std;
#include "PetStatsTable.h"
#include "../util/IntValidation.h"
#include "../util/SavingSystem.h"
#include "./MainMenu.h"
#include "../pet/Pet.h"

/**
 * This script will show the pet stats in a table
 */
void ShowPetStatsTable(string pet, string name, int happiness, int energy, int hunger, int coins)
{

    int option;

    cout << R"(
        ________              __                      __  __              __      __                               
       /        |            /  |                    /  |/  |            /  |    /  |                              
       $$$$$$$$/   _______  _$$ |_     ______    ____$$ |$$/   _______  _$$ |_   $$/   _______   ______    _______ 
       $$ |__     /       |/ $$   |   /      \  /    $$ |/  | /       |/ $$   |  /  | /       | /      \  /       |
       $$    |   /$$$$$$$/ $$$$$$/    $$$$$$  |/$$$$$$$ |$$ |/$$$$$$$/ $$$$$$/   $$ |/$$$$$$$/  $$$$$$  |/$$$$$$$/ 
       $$$$$/    $$      \   $$ | __  /    $$ |$$ |  $$ |$$ |$$      \   $$ | __ $$ |$$ |       /    $$ |$$      \ 
       $$ |_____  $$$$$$  |  $$ |/  |/$$$$$$$ |$$ \__$$ |$$ | $$$$$$  |  $$ |/  |$$ |$$ \_____ /$$$$$$$ | $$$$$$  |
       $$       |/     $$/   $$  $$/ $$    $$ |$$    $$ |$$ |/     $$/   $$  $$/ $$ |$$       |$$    $$ |/     $$/ 
       $$$$$$$$/ $$$$$$$/     $$$$/   $$$$$$$/  $$$$$$$/ $$/ $$$$$$$/     $$$$/  $$/  $$$$$$$/  $$$$$$$/ $$$$$$$/                                                                                               
                   

)";
    cout << "                                            +-------------------------------+\n";
    cout << "                                              - Mascota: " << pet << "\n";
    cout << "                                              - Nombre: " << name << "\n";
    cout << "                                              - Felicidad: " << happiness << "\n";
    cout << "                                              - Energia: " << energy << "\n";
    cout << "                                              - Hambre: " << hunger << "\n";
    cout << "                                              - Monedas: " << coins << "\n";
    cout << "                                            +-------------------------------+\n";

    cout << "Presiona 0 para regresar:\n";
    option = validateInt();

    if (option == 0)
    {
        Pet p = Load();
        MainMenu(p);
    }
    else
    {
        cout << "Por Favor. Ingresa una opcion valida\n";
    }
}
