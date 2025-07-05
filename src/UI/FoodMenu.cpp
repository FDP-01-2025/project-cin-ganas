#include <iostream>
#include <map>
#include <cstdlib>
#include "../pet/Pet.h"
#include "../util/SavingSystem.h"
#include "../util/IntValidation.h"
using namespace std;

struct Food{
    string name;
    int price;
};

map<int, Food> food_items ={
    {1, {"Agua", 2}},
    {2, {"Manzana", 5}},
    {3, {"Pastel", 8}},
    {4, {"Hamburguesa", 10}}
};

Pet p = Load();

void FoodMenu(Pet &p) {
    int option = -1;

    while (option != 0) {
        system("cls");  // Limpia la pantalla en cada iteración

        cout << R"(
        +--------+-------------+--------+
        | Opcion |   Comida    | Precio |
        +--------+-------------+--------+
        |      1 | Agua        |      2 |
        |      2 | Manzana     |      5 |
        |      3 | Pastel      |      8 |
        |      4 | Hamburguesa |     10 |
        |      0 | Salir       |        |
        +--------+-------------+--------+
)" << endl;

        cout << "Elige una opcion (0 para salir): ";
        option = validateInt();

        if (option == 0) {
            cout << "Saliendo del menú de comida.\n";
            system("pause");
            break;
        }

        if (food_items.find(option) == food_items.end()) {
            cout << "Opción inválida.\n";
            system("pause");
            continue;
        }

        Food food = food_items[option];

        if (p.coins < food.price) {
            cout << "No tienes suficientes monedas para comprar " << food.name << ".\n";
            system("pause");
            continue;
        }

        p.coins -= food.price;
        cout << "Le diste a tu mascota " << food.name << " por " << food.price << " monedas.\n";
        cout << "Te quedan " << p.coins << " monedas.\n";

        Save(p);
        system("pause");
    }
}