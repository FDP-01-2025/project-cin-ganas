#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <random>
#include <limits> // For input validation
#include "../util/SavingSystem.h"

using namespace std;

struct WordHint
{
    string word;
    string hint;
};

string shuffleWord(const string &original)
{
    string shuffled = original;
    random_device rd;
    default_random_engine rng(rd());
    shuffle(shuffled.begin(), shuffled.end(), rng);
    return shuffled;
}

void playArrangeWord()
{
    bool playerWon = false;
    system("cls");

    // ASCII Game Title
    cout << R"(
                           /$$$$$$                  /$$                               /$$          
                          /$$__  $$                | $$                              | $$          
                         | $$  \ $$  /$$$$$$   /$$$$$$$  /$$$$$$  /$$$$$$$   /$$$$$$ | $$  /$$$$$$ 
                         | $$  | $$ /$$__  $$ /$$__  $$ /$$__  $$| $$__  $$ |____  $$| $$ /$$__  $$
                         | $$  | $$| $$  \__/| $$  | $$| $$$$$$$$| $$  \ $$  /$$$$$$$| $$| $$  \ $$
                         | $$  | $$| $$      | $$  | $$| $$_____/| $$  | $$ /$$__  $$| $$| $$  | $$
                         |  $$$$$$/| $$      |  $$$$$$$|  $$$$$$$| $$  | $$|  $$$$$$$| $$|  $$$$$$/
                          \______/ |__/       \_______/ \_______/|__/  |__/ \_______/|__/ \______/ 
    )" << endl;

    cout << endl;
    cout << "                               +-------------------------------------------------------------+\n";
    cout << "                                            Bienvenido al juego Ordena la palabra           \n";
    cout << "                               +-------------------------------------------------------------+\n";

    cout << "                        +----------------------------------------------------------------------------+\n";
    cout << "                         En este juego tenes que adivinar palabras o frases que identifiquen a la UCA \n";
    cout << "                        +----------------------------------------------------------------------------+\n";

    // Word banks by difficulty
    vector<WordHint> easy = {
        {"UCA", "El nombre de una de las universidades mas reconocidas del pais"},
        {"ICAS", "Donde los salones tienen aire acondicionado"},
        {"Buho", "Es la mascota que nos representa"},
        {"UNO", "\"Ey anda pedi prestado el ... para jugar\""},
        {"Jenga", "\"ojala en este juego llegues a botar la torre\""},
        {"Gatos", "Son animales que andan por todo el campus de la universidad y caminan en cuatro patas"},
        {"Libros", "\"Necesito prestar un ... de la biblioteca\""}};

    vector<WordHint> medium = {
        {"Las Terrazas", "\"Dicen que los capuchinos que venden en .... son buenos\""},
        {"La pea", "\"Ey vamos a ... tengo hambre, vamos a ver que comemos\""},
        {"El poli", "\"Ey en .... va a ver un partido ahora, vamos a verlo\""},
        {"Magnas", "Los asientos de las .... son incomodos"},
        {"Sultana", "\"Ey tengo ganas de Wendy's, salgamos por la .... que queda mas cerca\""},
        {"Ardillas", "Son animales que siempre se ven en los arboles"},
        {"Pericos", "Son animales que solo los ven y los escuchan los que madrugan"},
        {"Gradas", "\"Puya ya me canse de subir tantas ....\""},
        {"Carnet", "\"Mire le voy a dictar mi numero de ...\""}};

    vector<WordHint> difficult = {
        {"Mercaduca", "Productos de estudiantes emprendedores"},
        {"Catedraticos", "Son los encargados de nuestra educacion"},
        {"Decanato", "Son las direcciones administrativas"},
        {"Cafeteria principal", "Uno de los lugares favoritos para ir a comer dentro de la universidad"},
        {"Parqueo anexo", "\"Puya hoy me toco ir a dejar el carro hasta el ...., me quedo bien lejos\""},
        {"Carteleras", "Siempre se encuentra informacion necesaria"},
        {"Tutorias", "Son minis repasos de las clases"},
        {"Parciales", "La razon del estres de todos los estudiantes"},
        {"Hola mundo", "Frase que conoce todo informatico"}};

    int level;
    while (true)
    {
        cout << "\nSelecciona un nivel de dificultad para esta palabra:" << endl;
        cout << "1. Facil" << endl;
        cout << "2. Medio" << endl;
        cout << "3. Dificil" << endl;
        cout << "Ingresa 1, 2 o 3: ";

        if (cin >> level && (level >= 1 && level <= 3))
        {
            cin.ignore(); // clear newline
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada  no valida. Por favor ingresa 1, 2 o 3\n";
        }
    }

    vector<WordHint> selectedWords;
    if (level == 1)
    {
        selectedWords = easy;
    }
    else if (level == 2)
    {
        selectedWords = medium;
    }
    else
    {
        selectedWords = difficult;
    }

    random_device rd;
    default_random_engine rng(rd());
    uniform_int_distribution<size_t> dist(0, selectedWords.size() - 1);

    WordHint current = selectedWords[dist(rng)];

    string lettersOnly;
    for (char c : current.word)
    {
        if (c != ' ')
            lettersOnly += c;
    }

    string scrambled = shuffleWord(lettersOnly);

    cout << "        +-------------------------------------------------------------+\n";
    cout << "                Adivina la palabra o frase con estas letras:           \n";
    cout << "                      --> " << scrambled << "\n";
    cout << "        +-------------------------------------------------------------+\n";

    cout << "        +-------------------------------------------------------------+\n";
    cout << "                      Pista: " << current.hint << "\n";
    cout << "        +-------------------------------------------------------------+\n";

    cout << "\nTu respuesta: ";
    string guess;
    getline(cin, guess);

    if (guess == current.word)
    {
        playerWon = true;
        cout << "        +-------------------------------------------------------------+\n";
        cout << "                          ¡Respuesta Correcta!                         \n";
        cout << "        +-------------------------------------------------------------+\n";
    }
    else
    {
        cout << "        +-------------------------------------------------------------+\n";
        cout << "                         Respuesta Incorrecta                         \n";
        cout << "        +-------------------------------------------------------------+\n";
        cout << "        +-------------------------------------------------------------+\n";
        cout << "                    La palabra era: " << current.word << "\n";
        cout << "        +-------------------------------------------------------------+\n";
    }

    // Score
    if (playerWon)
    {
        finishGame(7, 7, 3, 3);
    }
    else
    {
        finishGame(0, 0, 5, 5);
    }

    Sleep(5000);
}