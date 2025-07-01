#include <iostream>
#include <cctype>
using namespace std;
#include "CreditsScreen.h"
#include "StartScreen.h"

void ShowCreditsScreen()
{

    // Variable
    char userOption;

    cout << R"(

                      ______                             __  __    __                         
                     /      \                           /  |/  |  /  |                        
                    /$$$$$$  |  ______    ______    ____$$ |$$/  _$$ |_     ______    _______ 
                    $$ |  $$/  /      \  /      \  /    $$ |/  |/ $$   |   /      \  /       |
                    $$ |      /$$$$$$  |/$$$$$$  |/$$$$$$$ |$$ |$$$$$$/   /$$$$$$  |/$$$$$$$/ 
                    $$ |   __ $$ |  $$/ $$    $$ |$$ |  $$ |$$ |  $$ | __ $$ |  $$ |$$      \ 
                    $$ \__/  |$$ |      $$$$$$$$/ $$ \__$$ |$$ |  $$ |/  |$$ \__$$ | $$$$$$  |
                    $$    $$/ $$ |      $$       |$$    $$ |$$ |  $$  $$/ $$    $$/ /     $$/ 
                     $$$$$$/  $$/        $$$$$$$/  $$$$$$$/ $$/    $$$$/   $$$$$$/  $$$$$$$/  
                                                                          
                                                                          
                        +--------------------------------------------------------------+
                        | Universidad Centroamericana "Jose Simeon Canas".             |
                        | Materia: Fundamentos de Programacion.                        |
                        | Docente: Ing. Gabriela Carolina Reynosa Perez.               |
                        |                                                              |
                        | Integrantes:                                                 |
                        | - 00087525 | Diego Roberto Olivares Ortega.                  |
                        | - 00019625 | Mauricio Rene Rodas Lazo.                       |
                        | - 00085025 | Amy Giselle Torres Ventura.                     |
                        | - 00177525 | Diego Sebastian Villacorta Villalobos.          |
                        +--------------------------------------------------------------+
    
Presiona la tecla "E" para Regresar: 
)";

    do
    {
        cin >> userOption;

        if (toupper(userOption) != 'E')
        {
            cout << "Por Favor. Presione la tecla \"E\" para Regresar.\n";
        }
    } while (toupper(userOption) != 'E');

    // If the key pressed is E, then go back to the start screen
    ShowStartScreen();
}
