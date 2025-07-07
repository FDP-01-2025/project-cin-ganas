#include <iostream>
#include <cstdlib>
#include <limits>
#include "MainMenu.h"
#include "../pet/Pet.h"
#include "../util/SavingSystem.h"
#include "../minigames/TriviaUCA.h"
#include "../minigames/ArrangeSequence.h"
#include "../minigames/ArrangeWord.h"
#include "../minigames/TicTacToe.h"
using namespace std;

void MiniGames() // shows the mini game menu
{
    int option = 0;

    do
    {

        system("cls"); // Clears screen before printing

        cout << R"(

                                 $$$$$\ $$\   $$\ $$$$$$$$\  $$$$$$\   $$$$$$\   $$$$$$\  
                                   \__$$ |$$ |  $$ |$$  _____|$$  __$$\ $$  __$$\ $$  __$$\ 
                                      $$ |$$ |  $$ |$$ |      $$ /  \__|$$ /  $$ |$$ /  \__|
                                      $$ |$$ |  $$ |$$$$$\    $$ |$$$$\ $$ |  $$ |\$$$$$$\  
                                $$\   $$ |$$ |  $$ |$$  __|   $$ |\_$$ |$$ |  $$ | \____$$\ 
                                $$ |  $$ |$$ |  $$ |$$ |      $$ |  $$ |$$ |  $$ |$$\   $$ |
                                \$$$$$$  |\$$$$$$  |$$$$$$$$\ \$$$$$$  | $$$$$$  |\$$$$$$  |
                                 \______/  \______/ \________| \______/  \______/  \______/ 
                                                            
                                                                                           
                                               +---------------------------+
                                               | 1. Ordenar la palabra.    |
                                               | 2. Trivia UCA.            |
                                               | 3. Ordenar la secuencia.  |
                                               | 4. Tres en raya.          |
                                               | 5. Regresar a tu TamaUCA. |
                                               +---------------------------+

Selecciona una Opcion (1-5):
)";

        cin >> option;
        if (cin.fail())                                          // if cin fails, this condition becomes true
        {                                                        // clears data type errors
            cin.clear();                                         // clears the error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears buffer
            cout << "Entrada invalida. Vuelve a intentar con un numero valido.";
            system("pause"); // makes the user able to see the message
            continue;
        }

        switch (option)
        {
        case 1:
        {
            playArrangeWord();
            break;
        }

        case 2:
        {
            TriviaUCA();
            break;
        }

        case 3:
        {
            PlayArrangeSequence();
            break;
        }

        case 4:
        {
            TicTacToe();
            break;
        }

        case 5:
        {
            Pet savedPet = Load(); // Loading the saved Pet
            MainMenu(savedPet);    // Go to the main menu with the saved pet
            break;
        }

        default:
        {
            cout << "Escribe un juego valido." << endl;
            system("pause");
        }
        }

    } while (option != 5);
}