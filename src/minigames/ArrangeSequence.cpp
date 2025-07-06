#include <iostream>  // Para entrada/salida
#include <cstdlib>   // Para rand(), srand()
#include <ctime>     // Para time()
#include <windows.h> // Para Sleep()
#include <limits>    // Para validacion de entrada
#include "ArrangeSequence.h"
#include "../util/IntValidation.h"
#include "../util/SavingSystem.h"

using namespace std;

// Muestra el titulo en ASCII del juego
void ShowArrangeSequenceTitle()
{
    system("cls");
    cout << R"(
                       __       __  ________  __       __   ______                                   __ 
                      /  \     /  |/        |/  \     /  | /      \                                 /  |
                      $$  \   /$$ |$$$$$$$$/ $$  \   /$$ |/$$$$$$  |          ______   __   __   __ $$ |
                      $$$  \ /$$$ |$$ |__    $$$  \ /$$$ |$$ |  $$ | ______  /      \ /  | /  | /  |$$ |
                      $$$$  /$$$$ |$$    |   $$$$  /$$$$ |$$ |  $$ |/      |/$$$$$$  |$$ | $$ | $$ |$$ |
                      $$ $$ $$/$$ |$$$$$/    $$ $$ $$/$$ |$$ |  $$ |$$$$$$/ $$ |  $$ |$$ | $$ | $$ |$$ |
                      $$ |$$$/ $$ |$$ |_____ $$ |$$$/ $$ |$$ \__$$ |        $$ \__$$ |$$ \_$$ \_$$ |$$ |
                      $$ | $/  $$ |$$       |$$ | $/  $$ |$$    $$/         $$    $$/ $$   $$   $$/ $$ |
                      $$/      $$/ $$$$$$$$/ $$/      $$/  $$$$$$/           $$$$$$/   $$$$$/$$$$/  $$/ 
                                                                                                                    
                                                                                                                    
    )" << "\n";

    cout << "                                          Bienvenido a MEMO-OWL - Juego de Memoria\n"
         << endl;
    Sleep(2000); // Espera para que el jugador lea
}

// Muestra la historia del buho y arte ASCII
void ShowOwlStory()
{
    cout << R"(
                                                       __              __
                                                       \ `-._......_.-` /
                                                        `.  '.    .'  .'
                                                         //  _`\/`_  \\
                                                        ||  /\O||O/\  ||
                                                        |\  \_/||\_/  /|
                                                        \ '.   \/   .' /
                                                        / ^ `'~  ~'`   \
                                                       /  _-^_~ -^_ ~-  |
                                                       | / ^_ -^_- ~_^\ |
                                                       | |~_ ^- _-^_ -| |
                                                       | \  ^-~_ ~-_^ / |
                                                       \_/;-.,____,.-;\_/
                                                ==========(_(_(==)_)_)=========

)" << endl;

    cout << "Este es el buho Sabio, estudiante de Ingenieria Informatica.\n";
    cout << "Pero esta en peligro de reprobar la clase.\n";
    cout << "Para aprobar necesita pasar una ultima prueba de memoria.\n";
    cout << "Ayudalo a recordar los numeros correctamente y salvar su nota.\n\n";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Presiona ENTER para comenzar...";
    cin.get();
    system("cls");
}

// Juego principal
void PlayArrangeSequence()
{
    const int N = 4;  // Cantidad de numeros
    int numeros[N];   // Numeros generados
    int respuesta[N]; // Respuesta del usuario

    ShowArrangeSequenceTitle(); // Titulo
    ShowOwlStory();             // Historia

    srand(time(0)); // Semilla

    cout << "                                      ------------------------------------------------------\n";
    cout << "                                                Memoriza los siguientes " << N << " numeros:\n";

    cout << "                                                           ";

    for (int i = 0; i < N; i++)
    {
        numeros[i] = rand() % 100;
        cout << numeros[i] << " ";
    }
    cout << "\n                                      ------------------------------------------------------\n";
    cout << endl;

    Sleep(5000);
    system("cls");

    cout << "Ingresa los " << N << " numeros que viste, uno por uno:\n";
    for (int i = 0; i < N; i++)
    {
        cout << "Numero #" << i + 1 << ": ";
        respuesta[i] = validateInt();
    }

    bool acerto = true;
    for (int i = 0; i < N; i++)
    {
        if (respuesta[i] != numeros[i])
        {
            acerto = false;
            break;
        }
    }

    if (acerto)
    {
        cout << "\nMuy bien. Has salvado al buho y aprobado la clase.\n";
        finishGame(7, 7, 3, 3);
    }
    else
    {
        ;
        cout << "\nFallaste. El buho reprobo.\n";
        cout << "Los numeros correctos eran: ";
        for (int i = 0; i < N; i++)
        {
            cout << numeros[i] << " ";
        }
        cout << endl;
        finishGame(0, 0, 5, 5);
    }

    cout << "\nPresiona ENTER para volver al menu...";
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    system("cls");
}
