#include <iostream>
#include <windows.h>
#include <limits>
#include "Instructions.h"

using namespace std;

// Espera a que el usuario presione ENTER
void WaitForEnter() {
    cout << "\nPresiona ENTER para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Muestra encabezado centrado con espacios
void PrintCenteredAscii() {
    cout << R"(
               __                        __                                      __      __                               
              /  |                      /  |                                    /  |    /  |                              
              $$/  _______    _______  _$$ |_     ______   __    __   _______  _$$ |_   $$/   ______   _______    _______ 
              /  |/       \  /       |/ $$   |   /      \ /  |  /  | /       |/ $$   |  /  | /      \ /       \  /       |
              $$ |$$$$$$$  |/$$$$$$$/ $$$$$$/   /$$$$$$  |$$ |  $$ |/$$$$$$$/ $$$$$$/   $$ |/$$$$$$  |$$$$$$$  |/$$$$$$$/ 
              $$ |$$ |  $$ |$$      \   $$ | __ $$ |  $$/ $$ |  $$ |$$ |        $$ | __ $$ |$$ |  $$ |$$ |  $$ |$$      \ 
              $$ |$$ |  $$ | $$$$$$  |  $$ |/  |$$ |      $$ \\__$$ |$$ \\_____   $$ |/  |$$ |$$ \\__$$ |$$ |  $$ | $$$$$$  |
              $$ |$$ |  $$ |/     $$/   $$  $$/ $$ |      $$    $$/ $$       |  $$  $$/ $$ |$$    $$/ $$ |  $$ |/     $$/ 
              $$/ $$/   $$/ $$$$$$$/     $$$$/  $$/        $$$$$$/   $$$$$$$/    $$$$/  $$/  $$$$$$/  $$/   $$/ $$$$$$$/  
    )" << endl;
}

// Muestra una instruccion
void ShowInstruction(const string& texto, int numero, int total) {
    system("cls");
    PrintCenteredAscii();
    cout << "\nRegla " << numero << " de " << total << ":\n";
    cout << texto << endl;
    WaitForEnter();
}

void ShowInstructions() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia buffer inicial

    ShowInstruction("Instruccion 1: En el menu ingresar una opcion 1. para jugar, 2. para ver instrucciones, 3.para ver los creditos .", 1, 6);
    ShowInstruction("Instruccion 2: Al presionar 1, aparecera un buho , el cual dara diversas opciones , como son: Jugar , Dormir , Comer, Ver estadisticas y salir , cada una tiene su respectivo numero para seleccionarlo. .", 2, 6);
    ShowInstruction("Instruccion 3: Al escoger la opcion de jugar , nos apareceran diversas opciones de minijuegos en los cuales podremos ganar monedas.", 3, 6);
    ShowInstruction("Instruccion 4: Al escoger la opcion de comer , aparecera un catalogo con las diversas comida que se le pueden dar a la mascota , con el incremento que ofrece y el precio..", 4, 6);
    ShowInstruction("Instruccion 5: Al escoger la opcion de estadisticas , podremos ver las estdisticas de nuestra mascota : Tipo , Nombre , Felicidad , Energia , Hambre , Monedas.", 5, 6);
    ShowInstruction("Instruccion 6: Al escoger la opcion de dormir... .", 5, 6);
    

    system("cls");
    cout << "Fin de las instrucciones.\n";
    cout << "Presiona ENTER para volver al menu...";
    cin.get();
    system("cls");
}
