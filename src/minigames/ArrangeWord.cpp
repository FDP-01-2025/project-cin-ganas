#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>
#include "../util/SavingSystem.h"
#include <limits> // To validate input
#include <windows.h>

using namespace std;

struct WordHint
{
    string word;
    string hint;
};

string shuffleWord(const string &originalWord)
{
    string shuffled = originalWord;
    random_device rd;
    default_random_engine rng(rd());
    shuffle(shuffled.begin(), shuffled.end(), rng);
    return shuffled;
}

void playArrangeWord()
{
    system("CLS");

    // Game title in ASCII

    cout << R"(
                                

                         /$$   /$$  /$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$$   /$$$$$$  /$$      /$$  /$$$$$$ 
                        | $$  | $$ /$$__  $$ /$$__  $$ /$$__  $$| $$__  $$ /$$__  $$| $$$    /$$$ /$$__  $$
                        | $$  | $$| $$  \__/| $$  \ $$| $$  \__/| $$  \ $$| $$  \ $$| $$$$  /$$$$| $$  \ $$
                        | $$  | $$| $$      | $$$$$$$$| $$ /$$$$| $$$$$$$/| $$$$$$$$| $$ $$/$$ $$| $$$$$$$$
                        | $$  | $$| $$      | $$__  $$| $$|_  $$| $$__  $$| $$__  $$| $$  $$$| $$| $$__  $$
                        | $$  | $$| $$    $$| $$  | $$| $$  \ $$| $$  \ $$| $$  | $$| $$\  $ | $$| $$  | $$
                        |  $$$$$$/|  $$$$$$/| $$  | $$|  $$$$$$/| $$  | $$| $$  | $$| $$ \/  | $$| $$  | $$
                         \______/  \______/ |__/  |__/ \______/ |__/  |__/|__/  |__/|__/     |__/|__/  |__/
                                                                                   

    )" << endl;

    cout << endl;
    cout << "                                          +-------------------------------------------------------------+" << endl;
    cout << "                                                         Bienvenido al juego Ordena la palabra" << endl;
    cout << "                                          +-------------------------------------------------------------+" << endl;

    // Brief description of the game

    cout << "                                     +-------------------------------------------------------------------------------+" << endl;
    cout << "                                       En este juego tenes que adivinar palabras o frases que identifiquen a la UCA" << endl;
    cout << "                                     +-------------------------------------------------------------------------------+" << endl;

    // Difficulty levels the user must choose

    cout << endl;
    cout << "                                                         +-----------------------------+" << endl;
    cout << "                                                         | Selecciona un nivel:        |" << endl;
    cout << "                                                         |  1. Facil                   |" << endl;
    cout << "                                                         |  2. Intermedio              |" << endl;
    cout << "                                                         |  3. Dificil                 |" << endl;
    cout << "                                                         +-----------------------------+" << endl;
    cout << endl;

    char playAgain = 's';

    // Word classification by difficulty level

    // Easy level

    vector<WordHint> easyLevel = {
        {"UCA", "El nombre de una de las universidades mas reconocidas del pais"},
        {"ICAS", "Donde los salones tienen aire acondicionado"},
        {"Buho", "Es la mascota que nos representa"},
        {"UNO", "\"Ey anda pedi prestado el ... para jugar\""},
        {"Jenga", "\"ojala en este juego llegues a botar la torre\""},
        {"Gatos", "Son animales que andan por todo el campus de la universidad y caminan en cuatro patas"},
        {"Libros", "\"Necesito prestar unos ... de la biblioteca\""}};

    // Medium level

    vector<WordHint> mediumLevel = {
        {"Las Terrazas", "\"Dicen que los capuchinos que venden en .... son buenos\""},
        {"La pea", "\"Ey vamos a ... tengo hambre, vamos a ver que comemos\""},
        {"El poli", "\"Ey en .... va a ver un partido ahora, vamos a verlo\""},
        {"Magnas", "Los asientos de las .... son incomodos"},
        {"Sultana", "\"Ey tengo ganas de Wendy's, salgamos por la .... que queda mas cerca\""},
        {"Ardillas", "Son animales que siempre se ven en los arboles"},
        {"Pericos", "Son animales que solo los ven y los escuchan los que madrugan"},
        {"Gradas", "\"Puya ya me canse de subir tantas ....\""},
        {"Carnet", "\"Mire le voy a dictar mi numero de ...\""}};

    // Hard level

    vector<WordHint> hardLevel = {
        {"Mercaduca", "Productos de estudiantes emprendedores"},
        {"Catedraticos", "Son los encargados de nuestra educacion"},
        {"Decanato", "Son las direcciones administrativas"},
        {"Cafeteria principal", "Uno de los lugares favoritos para ir a comer dentro de la universidad"},
        {"Parqueo anexo", "\"Puya hoy me toco ir a dejar el carro hasta el ...., me quedo bien lejos\""},
        {"Carteleras", "Siempre se encuentra informacion necesaria"},
        {"Tutorias", "Son minis repasos de las clases"},
        {"Parciales", "La razon del estres de todos los estudiantes"},
        {"Hola mundo", "Frase que conoce todo informatico"}};

    // Function to avoid repeated words

    vector<WordHint> copyEasy, copyMedium, copyHard;

    int level;

    while (true)
    {
        cout << "Selecciona un nivel de dificultad para esta palabra:" << endl;
        cout << "1. Facil" << endl;
        cout << "2. Medio" << endl;
        cout << "3. Dificil" << endl;
        cout << "Ingresa 1, 2 o 3: ";

        if (cin >> level && (level >= 1 && level <= 3))
        {
            cin.ignore(); // Clears newline
            break;
        }
        else
        {
            cin.clear(); // Clears error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "        +--------------------------------------------------------------+" << endl;
            cout << "         Respuesta ingresada invalida. Por favor ingresa 1, 2 o 3" << endl;
            cout << "        +--------------------------------------------------------------+" << endl;
        }
    }

    vector<WordHint> *original;
    vector<WordHint> *copy;

    if (level == 1)
    {
        original = &easyLevel;
        copy = &copyEasy;
    }
    else if (level == 2)
    {
        original = &mediumLevel;
        copy = &copyMedium;
    }
    else
    {
        original = &hardLevel;
        copy = &copyHard;
    }

    // Restart if temporary copy is empty
    if (copy->empty())
    {
        *copy = *original;
        shuffle(copy->begin(), copy->end(), default_random_engine(random_device{}()));
    }

    // Remove current word
    WordHint current = copy->back();
    copy->pop_back();

    string lettersOnly;
    for (char c : current.word)
        if (c != ' ')
            lettersOnly += c;

    string shuffled = shuffleWord(lettersOnly);

    cout << "        +-------------------------------------------------------------+" << endl;
    cout << "                Adivina la palabra o frase con estas letras:" << endl;
    cout << "                --> " << shuffled << endl;
    cout << "        +-------------------------------------------------------------+" << endl;

    cout << "        +-------------------------------------------------------------+" << endl;
    cout << "                Pista: " << current.hint << endl;
    cout << "        +-------------------------------------------------------------+" << endl;

    cout << "Tu respuesta: ";

    string attempt;
    getline(cin, attempt);

    if (attempt == current.word)
    {
        cout << "        +-------------------------------------------------------------+" << endl;
        cout << "                          Respuesta Correcta!" << endl;
        cout << "        +-------------------------------------------------------------+" << endl;
        finishGame(7, 7, 3, 3);
    }
    else
    {
        cout << "        +-------------------------------------------------------------+" << endl;
        cout << "                         Respuesta Incorrecta" << endl;
        cout << "        +-------------------------------------------------------------+" << endl;
        cout << "        +-------------------------------------------------------------+" << endl;
        cout << "                    La palabra era: " << current.word << endl;
        cout << "        +-------------------------------------------------------------+" << endl;
        finishGame(0, 0, 5, 5);
    }

    Sleep(5000);
}