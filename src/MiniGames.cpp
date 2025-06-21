#include <iostream>
#include <cstdlib>
#include <limits>
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
                      | 4. Explorar el campus.    |
                      | 5. Regresar a tu TamaUCA. |
                      +---------------------------+)";

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
            // ArrangeWord();
            break;
        }

        case 2:
        {
            // TriviaUCA();
            break;
        }

        case 3:
        {
            // ArrangeSequence();
            break;
        }

        case 4:
        {
            // Game4();
            break;
        }

        case 5:
        {
            // GameScreen();
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