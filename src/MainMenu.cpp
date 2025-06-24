#include <iostream>
#include <cstdlib>
#include "Pet.h"
#include "SavingSystem.h"
#include "CreatePetScreen.h"
#include "PetsASCII.h"
#include "IntValidation.h"
#include "MiniGames.h"
#include "PetStatsTable.h"
#include "StartScreen.h"
using namespace std;

void MainMenu(Pet &p)
{
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
            // Food options
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