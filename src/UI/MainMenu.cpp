#include <iostream>
#include <cstdlib>
#include <iomanip>
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
#include "SleepOption.h"
#include "StatsBar.h"

using namespace std;

void MainMenu(Pet &p)
{
    Save(p);

    checkPetDeath(p);

    int option;

    do
    {
        system("cls");
        cout << R"(
            $$\      $$\                                     $$$$$$$\            $$\                     $$\                     $$\ 
            $$$\    $$$ |                                    $$  __$$\           \__|                    \__|                    $$ |
            $$$$\  $$$$ | $$$$$$\  $$$$$$$\  $$\   $$\       $$ |  $$ | $$$$$$\  $$\ $$$$$$$\   $$$$$$$\ $$\  $$$$$$\   $$$$$$\  $$ |
            $$\$$\$$ $$ |$$  __$$\ $$  __$$\ $$ |  $$ |      $$$$$$$  |$$  __$$\ $$ |$$  __$$\ $$  _____|$$ |$$  __$$\  \____$$\ $$ |
            $$ \$$$  $$ |$$$$$$$$ |$$ |  $$ |$$ |  $$ |      $$  ____/ $$ |  \__|$$ |$$ |  $$ |$$ /      $$ |$$ /  $$ | $$$$$$$ |$$ |
            $$ |\$  /$$ |$$   ____|$$ |  $$ |$$ |  $$ |      $$ |      $$ |      $$ |$$ |  $$ |$$ |      $$ |$$ |  $$ |$$  __$$ |$$ |
            $$ | \_/ $$ |\$$$$$$$\ $$ |  $$ |\$$$$$$  |      $$ |      $$ |      $$ |$$ |  $$ |\$$$$$$$\ $$ |$$$$$$$  |\$$$$$$$ |$$ |
            \__|     \__| \_______|\__|  \__| \______/       \__|      \__|      \__|\__|  \__| \_______|\__|$$  ____/  \_______|\__|
                                                                                                         $$ |                    
                                                                                                         $$ |                    
                                                                                                         \__|                    
)" << endl;

        if (p.pet == "Squirrel")
            ShowSquirrel();
        else if (p.pet == "Owl")
            ShowOwl();
        else
            ShowParrot();

        cout << "\n\n+-------------------------------+\n";
        cout << "| Nombre: " << setw(24) << left << p.name << "|\n";
        cout << "+-------------------------------+\n";

        PrintBarStat("Hambre    ", p.hunger, 100);
        cout << endl;
        PrintBarStat("Felicidad ", p.happiness, 100);
        cout << endl;
        PrintBarStat("Energia   ", p.energy, 100);
        cout << endl;

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

        option = validateInt();
        switch (option)
        {
        case 1:
            MiniGames();
            Save(p);
            checkPetDeath(p);
            system("pause");
            break;
        case 2:
            system("cls");
            SleepOption(p);
            Save(p);
            checkPetDeath(p);
            system("pause");
            break;
        case 3:
            system("cls");
            FoodMenu(p);
            Save(p);
            checkPetDeath(p);
            system("pause");
            break;
        case 4:
            system("cls");
            ShowPetStatsTable(p.pet, p.name, p.happiness, p.energy, p.hunger, p.coins);
            checkPetDeath(p);
            system("pause");
            break;
        case 5:
            cout << "Saliendo..." << endl;
            Save(p);
            checkPetDeath(p);
            system("pause");
            break;
        default:
            cout << "Ingresa una opcion valida." << endl;
            Save(p);
            checkPetDeath(p);
            system("pause");
            break;
        }

    } while (option != 5);

    system("cls");
    ShowStartScreen();
}