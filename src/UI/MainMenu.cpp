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
#include "SleepOption.h"
#include "StatsBar.h"

using namespace std;

void CheckIfDead(Pet &p)
{
    if (!p.isAlive)
    {
        system("cls");
        cout << "\nTu mascota ha fallecido por descuido :(\n";
        cout << "Presiona cualquier tecla para regresar al menú principal.\n";
        remove("save.txt");
        system("pause");
        ShowStartScreen();
        return;
    }
}

void MainMenu(Pet &p)
{
    Save(p);

    CheckIfDead(p);

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

        cout << "-------------------------------" << endl;
        cout << "       " << p.name << endl;
        cout << "-------------------------------" << endl;

        PrintBarStat("Hambre    ", p.hunger, 100);
        PrintBarStat("Felicidad ", p.happiness, 100);
        PrintBarStat("Energia   ", p.energy, 100);

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
            CheckIfDead(p);
            system("pause");
            break;
        case 2:
            system("cls");
            SleepOption(p);
            Save(p);
            CheckIfDead(p);
            system("pause");
            break;
        case 3:
            system("cls");
            FoodMenu(p);
            Save(p);
            CheckIfDead(p);
            system("pause");
            break;
        case 4:
            system("cls");
            ShowPetStatsTable(p.pet, p.name, p.happiness, p.energy, p.hunger, p.coins);
            CheckIfDead(p);
            system("pause");
            break;
        case 5:
            cout << "Saliendo..." << endl;
            Save(p);
            CheckIfDead(p);
            system("pause");
            break;
        default:
            cout << "Ingresa una opcion valida." << endl;
            Save(p);
            CheckIfDead(p);
            system("pause");
            break;
        }

    } while (option != 5);

    system("cls");
    ShowStartScreen();
}