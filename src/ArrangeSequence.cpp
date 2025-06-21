// ArrangeSequence.cpp
#include <iostream>     // For input/output
#include <cstdlib>      // For rand(), srand()
#include <ctime>        // For time()
#include <windows.h>    // For Sleep()
#include <limits>       // For input validation
#include "ArrangeSequence.h"

using namespace std;

// Displays ASCII banner with the game title
void ShowArrangeSequenceTitle() {
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
                                                                                  
                                                                                  
                                                        
                                                               
)" << "\n\n";
    cout << " Welcome to MEMO-OWL — Memory Challenge Game \n" << endl;
    Sleep(2000); // Pause to let player read the title
}

// Validates integer input from user
int validateInt() {
    int number;
    while (true) {
        cin >> number;
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "❗ Invalid input. Please enter an integer: ";
        } else {
            return number;
        }
    }
}

// Function to display the owl story and ASCII art
void ShowOwlStory() {
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

    // Story text explaining the owl's challenge
    cout << " Este es el buho Sabio, estudiante en Ingenieria Informatica.\n";
    cout << "Pero... esta en peligro de reprobar su clase 😨\n";
    cout << "Para aprobar necesita pasar una ultima prueba de memoria...\n";
    cout << "¡Ayudalo a recordar los numeros correctamente y salvar su nota!\n\n";

    // Wait for user to press ENTER before starting
    cout << "Presiona ENTER para comenzar...";
    cin.ignore();  // Clears previous input
    cin.get();     // Waits for ENTER
    system("cls"); // Clears screen (Windows only)
}

// Main function to play the memory game
void PlayArrangeSequence() {
    const int N = 4;        // Number of numbers to memorize
    int numeros[N];         // Array to store random numbers
    int respuesta[N];       // Array to store user input

    ShowArrangeSequenceTitle();  // Show the game title
    ShowOwlStory();              // Show intro story

    srand(time(0));              // Seed random number generator

    cout << "Memoriza los siguientes " << N << " numeros:\n";

    // Generate and display random numbers
    for (int i = 0; i < N; i++) {
        numeros[i] = rand() % 100; // Random number between 0–99
        cout << numeros[i] << " "; // Print number to screen
    }
    cout << endl;

    Sleep(5000);    // Wait 5 seconds to let the user memorize
    system("cls");  // Clear screen

    // Prompt the user to enter the numbers they memorized
    cout << "Ingresa los " << N << " numeros que viste, uno por uno:\n";
    for (int i = 0; i < N; i++) {
        cout << "Numero #" << i + 1 << ": ";
        respuesta[i] = validateInt();  // Safe input with validation
    }

    // Check if user's input matches the original sequence
    bool acerto = true;
    for (int i = 0; i < N; i++) {
        if (respuesta[i] != numeros[i]) {
            acerto = false;  // If any number is incorrect, mark as failure
            break;
        }
    }

    // Show result based on whether user was correct
    if (acerto) {
        cout << "\n🎉 ¡Excelente! Has salvado al buho y aprobado la clase.\n";
    } else {
        cout << "\n Fallaste... el buho reprobo :(\n";
        cout << "Los numeros correctos eran: ";
        for (int i = 0; i < N; i++) {
            cout << numeros[i] << " ";  // Show correct sequence
        }
        cout << endl;
    }

    // Wait for user to press ENTER to return
    cout << "\nPresiona ENTER para volver al menú...";
    cin.ignore();  // Clear newline character left in buffer
    cin.get();     // Wait for ENTER
    system("cls"); // Clear screen before returning
}
