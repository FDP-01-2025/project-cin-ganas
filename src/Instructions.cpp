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

    ShowInstruction("Instruccion 1: Memoriza los numeros que se muestran por unos segundos.", 1, 5);
    ShowInstruction("Instruccion 2: Se borraran de la pantalla y deberas ingresarlos uno por uno.", 2, 5);
    ShowInstruction("Instruccion 3: Si todos los numeros coinciden, ganas.", 3, 5);
    ShowInstruction("Instruccion 4: Si fallas en al menos uno, pierdes.", 4, 5);
    ShowInstruction("Instruccion 5: Usa solo numeros enteros. No ingreses letras ni simbolos.", 5, 5);

    system("cls");
    cout << "Fin de las instrucciones.\n";
    cout << "Presiona ENTER para volver al menu...";
    cin.get();
    system("cls");
}
