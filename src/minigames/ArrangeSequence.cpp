#include <iostream>  // For input/output
#include <cstdlib>   // For rand(), srand()
#include <ctime>     // For time()
#include <windows.h> // For Sleep()
#include <limits>    // For input validation
#include "ArrangeSequence.h"
#include "../util/IntValidation.h"
#include "../util/SavingSystem.h"

using namespace std;

// Shows the ASCII title of the game
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
    Sleep(2000); // Wait so the player can read
}

// Shows the owl's story and ASCII art
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

// Main game
void PlayArrangeSequence()
{
    const int N = 4;  // Number of numbers
    int numeros[N];   // Generated numbers
    int respuesta[N]; // User's answers

    ShowArrangeSequenceTitle(); // Title
    ShowOwlStory();             // Story

    srand(time(0)); // Seed

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

    Sleep(5000); // Wait before clearing screen
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
        cout << "\nFallaste. El buho reprobo.\n";
        cout << "Los numeros correctos eran: ";
        for (int i = 0; i < N; i++)
        {
            cout << numeros[i] << " ";
        }
        cout << endl;
        finishGame(0, 0, 7, 7);
    }

    cout << "\nPresiona ENTER para volver al menu...";
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    system("cls");
}
