#include <iostream>
#include "../pet/Pet.h"
#include "../util/IntValidation.h"
#include "../UI/StartScreen.h"
using namespace std;

void showDeathScreen(const Pet &p)
{
    int option;
    system("cls");
    cout << R"(
    
                                __       __                                  __               
                               /  \     /  |                                /  |              
                               $$  \   /$$ | __    __   ______    ______   _$$ |_     ______  
                               $$$  \ /$$$ |/  |  /  | /      \  /      \ / $$   |   /      \ 
                               $$$$  /$$$$ |$$ |  $$ |/$$$$$$  |/$$$$$$  |$$$$$$/   /$$$$$$  |
                               $$ $$ $$/$$ |$$ |  $$ |$$    $$ |$$ |  $$/   $$ | __ $$ |  $$ |
                               $$ |$$$/ $$ |$$ \__$$ |$$$$$$$$/ $$ |        $$ |/  |$$ \__$$ |
                               $$ | $/  $$ |$$    $$/ $$       |$$ |        $$  $$/ $$    $$/ 
                               $$/      $$/  $$$$$$/   $$$$$$$/ $$/          $$$$/   $$$$$$/                                                         

)";

    cout << "                                       +-----------------------------------------+\n";
    cout << "                                        Tu mascota " << p.name << " ha muerto\n";
    cout << "                                       +-----------------------------------------+\n\n";

    cout << "                                            +-------------------------------+\n";
    cout << "                                              - Mascota: " << p.pet << "\n";
    cout << "                                              - Felicidad: " << p.happiness << "\n";
    cout << "                                              - Energia: " << p.energy << "\n";
    cout << "                                              - Hambre: " << p.hunger << "\n";
    cout << "                                              - Monedas: " << p.coins << "\n";
    cout << "                                            +-------------------------------+\n\n";

    cout << "Presiona 0 para Regresar:\n";

    do
    {
        option = validateInt();

        if (option != 0)
        {
            cout << "Por Favor. Ingresa una Opcion Valida\n";
        }
    } while (option != 0);

    if (option == 0)
    {
        ShowStartScreen();
    }
}
