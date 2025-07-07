#include <iostream>
#include <windows.h>
#include <limits>
#include "./StartScreen.h"

using namespace std;

void WaitForEnter()
{
    cout << "\nPresiona ENTER para continuar...";
    cin.get();
}

void PrintCenteredAscii()
{
    cout << R"(
$$$$$$\                       $$\                                             $$\                                         
\_$$  _|                      $$ |                                            \__|                                        
  $$ |  $$$$$$$\   $$$$$$$\ $$$$$$\    $$$$$$\  $$\   $$\  $$$$$$$\  $$$$$$$\ $$\  $$$$$$\  $$$$$$$\   $$$$$$\   $$$$$$$\ 
  $$ |  $$  __$$\ $$  _____|\_$$  _|  $$  __$$\ $$ |  $$ |$$  _____|$$  _____|$$ |$$  __$$\ $$  __$$\ $$  __$$\ $$  _____|
  $$ |  $$ |  $$ |\$$$$$$\    $$ |    $$ |  \__|$$ |  $$ |$$ /      $$ /      $$ |$$ /  $$ |$$ |  $$ |$$$$$$$$ |\$$$$$$\  
  $$ |  $$ |  $$ | \____$$\   $$ |$$\ $$ |      $$ |  $$ |$$ |      $$ |      $$ |$$ |  $$ |$$ |  $$ |$$   ____| \____$$\ 
$$$$$$\ $$ |  $$ |$$$$$$$  |  \$$$$  |$$ |      \$$$$$$  |\$$$$$$$\ \$$$$$$$\ $$ |\$$$$$$  |$$ |  $$ |\$$$$$$$\ $$$$$$$  |
\______|\__|  \__|\_______/    \____/ \__|       \______/  \_______| \_______|\__| \______/ \__|  \__| \_______|\_______/                                                                                                                                                                                                                                                                                                                                                                           
)" << endl;
}

void ShowInstruction(const string &text, int num, int total)
{
    system("cls");
    PrintCenteredAscii();
    cout << "\nRegla " << num << " de " << total << ":\n";
    cout << text << endl;
    WaitForEnter();
}

void ShowInstructions()
{
    ShowInstruction("Instruccion 1: En el menu, ingresa una opcion: 1 para jugar, 2 para ver instrucciones, 3 para ver los creditos.", 1, 6);
    ShowInstruction("Instruccion 2: Al presionar 1, aparecera un buho que dara diversas opciones: Jugar, Dormir, Comer, Ver estadisticas y Salir. Cada una tiene su respectivo numero para seleccionarla.", 2, 6);
    ShowInstruction("Instruccion 3: Al escoger la opcion de Jugar, aparecera una lista de minijuegos en los cuales podras ganar monedas.", 3, 6);
    ShowInstruction("Instruccion 4: Al escoger la opcion de Comer, aparecera un catalogo con las comidas disponibles, mostrando el incremento que ofrecen y su precio.", 4, 6);
    ShowInstruction("Instruccion 5: En la opcion de Estadisticas podras ver los datos de tu mascota: Tipo, Nombre, Felicidad, Energia, Hambre y Monedas.", 5, 6);
    ShowInstruction("Instruccion 6: Al escoger la opcion de dormir, tu mascota descansara y recuperara energia.", 6, 6);

    system("cls");
    cout << "                                                     +------------------------------------------+\n";
    cout << "                                                     |      Fin de las instrucciones.           |\n";
    cout << "                                                     +------------------------------------------+\n";

    WaitForEnter();

    ShowStartScreen();
}
