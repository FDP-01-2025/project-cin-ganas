#include <iostream>
#include <map>
#include <windows.h>
#include <cstdlib>
#include "../pet/Pet.h"
#include "../util/SavingSystem.h"
#include "../util/IntValidation.h"
#include "./MainMenu.h"
using namespace std;

struct Food
{
    string name;
    int price;
};

map<int, Food> food_items = {
    {1, {"Agua", 3}},
    {2, {"Manzana", 5}},
    {3, {"Pastel", 15}},
    {4, {"Hamburguesa", 20}},
    {5, {"Leche", 30}}};

Pet p = Load();

void FoodMenu(Pet &p)
{
    int option = -1;

    while (option != 0)
    {
        system("cls"); // Clear screen

        // New centered ASCII title
        cout << R"(
                                   __        __                     
                                  /  |      /  |                    
  _______   ______   _____  ____  $$/   ____$$ |  ______    _______ 
 /       | /      \ /     \/    \ /  | /    $$ | /      \  /       |
/$$$$$$$/ /$$$$$$  |$$$$$$ $$$$  |$$ |/$$$$$$$ | $$$$$$  |/$$$$$$$/ 
$$ |      $$ |  $$ |$$ | $$ | $$ |$$ |$$ |  $$ | /    $$ |$$      \ 
$$ \_____ $$ \__$$ |$$ | $$ | $$ |$$ |$$ \__$$ |/$$$$$$$ | $$$$$$  |
$$       |$$    $$/ $$ | $$ | $$ |$$ |$$    $$ |$$    $$ |/     $$/ 
 $$$$$$$/  $$$$$$/  $$/  $$/  $$/ $$/  $$$$$$$/  $$$$$$$/ $$$$$$$/  
                                                                    
                                                                    
)" << endl;

        cout << R"(
        +--------+-------------+-----------------+--------+
        | Opcion |   Comida    |    Incremento   | Precio |
        +--------+-------------+-----------------+--------+
        |      1 | Agua        | +3 de Energia   |      3 |
        |      2 | Manzana     | -3 de Hambre    |      5 |
        |      3 | Pastel      | -10 de Hambre   |     15 |
        |      4 | Hamburguesa | +10 de Energia  |     20 |
        |      5 | Leche       | +20 de Energia  |     30 |
        |      0 | Salir       |                 |        |
        +--------+-------------+-----------------+--------+
)" << endl;

        cout << "Elige una opcion (0 para salir): ";
        option = validateInt();

        if (option == 0)
        {
            cout << "Saliendo del menu de comida.\n";
            Sleep(3000);
            Pet p = Load();
            MainMenu(p);
        }

        if (food_items.find(option) == food_items.end())
        {
            cout << "Opcion invalida.\n";
        }

        Food food = food_items[option];

        if (p.coins < food.price)
        {
            cout << "No tienes suficientes monedas para comprar " << food.name << ".\n";
            Sleep(3000);
            Pet p = Load();
            MainMenu(p);
            break;
        }

        p.coins -= food.price;

        // Apply food effects
        switch (option)
        {
        case 1: // Agua
            p.energy += 3;
            break;
        case 2: // Manzana
            p.hunger -= 3;
            break;
        case 3: // Pastel
            p.hunger -= 10;
            break;
        case 4: // Hamburguesa
            p.energy += 10;
            break;
        case 5: // Leche
            p.energy += 20;
            break;
        }

        // Keep variables within bounds
        if (p.energy > 100) p.energy = 100;
        if (p.energy < 0) p.energy = 0;
        if (p.hunger > 100) p.hunger = 100;
        if (p.hunger < 0) p.hunger = 0;

        cout << "Le diste a tu mascota " << food.name << " por " << food.price << " monedas.\n";
        cout << "Te quedan " << p.coins << " monedas.\n";

        Save(p);
        Sleep(5000);

        MainMenu(p);
    }
}
