#include <iostream>
#include <cstdlib>
#include "../pet/Pet.h"
#include "../util/SavingSystem.h"
#include "CreatePetScreen.h"
#include "../pet/PetsASCII.h"
#include "../util/IntValidation.h"
#include "Minigames.h"
#include "PetStatsTable.h"
#include "StartScreen.h"
#include "../util/SavingSystem.h"
#include "FoodMenu.h"
using namespace std;

void MainMenu(Pet &p)
{
    Save(p);
    int option;
    system("cls");
    if (p.pet == "Squirrel")
    {
        ShowSquirrel();
    }
    else if (p.pet == "Owl")
    {
        ShowOwl();
    }
    else
    {
        ShowParrot();
    }

    cout << "         " << p.name << endl;

    cout << "Escribe lo que quieres hacer: " << endl;
    cout << R"(
        +---------------------+
        | 1. Jugar            |
        | 2. Dormir           |
        | 3. Comer            |
        | 4. Ver estadisticas |
        | 5. Salir            |
        +---------------------+)"
         << endl;

    do
    {
        option = validateInt();
        switch (option)
        {
        case 1:
        {
            MiniGames();
            break;
        }
        case 2:
        {
            system("cls");
            // Sleep options
            break;
        }
        case 3:
        {
            system("cls");
            FoodMenu(p);
            break;
        }
        case 4:
        {
            system("cls");
            ShowPetStatsTable(p.pet, p.name, p.happiness, p.energy, p.hunger);
            break;
        }
        case 5:
        {
            cout << "Saliendo..." << endl;
            system("cls");
            ShowStartScreen();
            break;
        }

        default:
        {
            cout << "Ingresa una opcion valida." << endl;
            break;
        }
        }
    } while (option != 5);
}