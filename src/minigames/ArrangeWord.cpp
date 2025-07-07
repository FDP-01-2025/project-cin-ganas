#include <iostream> 
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>
#include <limits>

using namespace std;

struct PalabraPista {
    string palabra;
    string pista;
};

string desordenarPalabra(const string& palabraOriginal) {
    string desordenada = palabraOriginal;
    random_device rd;
    default_random_engine rng(rd());
    shuffle(desordenada.begin(), desordenada.end(), rng);
    return desordenada;
}

void playArrangeWord() {
    system("CLS");

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
    cout << "        +-------------------------------------------------------------+" << endl;
    cout << "                       Bienvenido al juego Ordena la palabra" << endl;
    cout << "        +-------------------------------------------------------------+" << endl;

    cout << "        +----------------------------------------------------------------------------+" << endl;
    cout << "         En este juego tenes que adivinar palabras o frases que identifiquen a la UCA" << endl;
    cout << "        +----------------------------------------------------------------------------+" << endl;

    cout << endl;
    cout << "        +-----------------------------+" << endl;
    cout << "        | Selecciona un nivel:        |" << endl;
    cout << "        |  1. Facil                   |" << endl;
    cout << "        |  2. Intermedio              |" << endl;
    cout << "        |  3. Dificil                 |" << endl;
    cout << "        +-----------------------------+" << endl;
    cout << endl;

    char jugarDeNuevo = 's';

    vector<PalabraPista> nivelFacil = {
        {"UCA", "El nombre de una de las universidades mas reconocidas del pais"},
        {"ICAS", "Donde los salones tienen aire acondicionado"},
        {"Buho", "Es la mascota que nos representa"},
        {"UNO", "\"Ey anda pedi prestado el ... para jugar\""},
        {"Jenga", "\"ojala en este juego llegues a botar la torre\""},
        {"Gatos", "Son animales que andan por todo el campus de la universidad y caminan en cuatro patas"},
        {"Libros", "\"Necesito prestar un ... de la biblioteca\""}
    };

    vector<PalabraPista> nivelMedio = {
        {"Las Terrazas", "\"Dicen que los capuchinos que venden en .... son buenos\""},
        {"La pea", "\"Ey vamos a ... tengo hambre, vamos a ver que comemos\""},
        {"El poli", "\"Ey en .... va a ver un partido ahora, vamos a verlo\""},
        {"Magnas", "Los asientos de las .... son incomodos"},
        {"Sultana", "\"Ey tengo ganas de Wendy's, salgamos por la .... que queda mas cerca\""},
        {"Ardillas", "Son animales que siempre se ven en los arboles"},
        {"Pericos", "Son animales que solo los ven y los escuchan los que madrugan"},
        {"Gradas", "\"Puya ya me canse de subir tantas ....\""},
        {"Carnet", "\"Mire le voy a dictar mi numero de ...\""}
    };

    vector<PalabraPista> nivelDificil = {
        {"Mercaduca", "Productos de estudiantes emprendedores"},
        {"Catedraticos", "Son los encargados de nuestra educacion"},
        {"Decanato", "Son las direcciones administrativas"},
        {"Cafeteria principal", "Uno de los lugares favoritos para ir a comer dentro de la universidad"},
        {"Parqueo anexo", "\"Puya hoy me toco ir a dejar el carro hasta el ...., me quedo bien lejos\""},
        {"Carteleras", "Siempre se encuentra informacion necesaria"},
        {"Tutorias", "Son minis repasos de las clases"},
        {"Parciales", "La razon del estres de todos los estudiantes"},
        {"Hola mundo", "Frase que conoce todo informatico"}
    };

    while (jugarDeNuevo == 's' || jugarDeNuevo == 'S') {
        bool continuarRonda = true;

        while (continuarRonda) {
            int nivel;
            while (true) {
                cout << "Selecciona un nivel de dificultad para esta palabra:" << endl;
                cout << "1. Facil" << endl;
                cout << "2. Medio" << endl;
                cout << "3. Dificil" << endl;
                cout << "Ingresa 1, 2 o 3: ";

                if (cin >> nivel && (nivel >= 1 && nivel <= 3)) {
                    cin.ignore();
                    break;
                } else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "        +--------------------------------------------------+" << endl;
                    cout << "           Entrada  no valida. Por favor ingresa 1, 2 o 3" << endl;
                    cout << "        +--------------------------------------------------+" << endl;
                }
            }

            vector<PalabraPista> palabrasSeleccionadas;
            if (nivel == 1) palabrasSeleccionadas = nivelFacil;
            else if (nivel == 2) palabrasSeleccionadas = nivelMedio;
            else palabrasSeleccionadas = nivelDificil;

            PalabraPista actual = palabrasSeleccionadas[rand() % palabrasSeleccionadas.size()];

            string soloLetras;
            for (char c : actual.palabra) if (c != ' ') soloLetras += c;

            string desordenada = desordenarPalabra(soloLetras);

            cout << "        +-------------------------------------------------------------+" << endl;
            cout << "                Adivina la palabra o frase con estas letras:" << endl;
            cout << "                      --> " << desordenada << endl;
            cout << "        +-------------------------------------------------------------+" << endl;

            cout << "        +-------------------------------------------------------------+" << endl;
            cout << "                      Pista: " << actual.pista << endl;
            cout << "        +-------------------------------------------------------------+" << endl;

            cout << "Tu respuesta: ";
            string intento;
            getline(cin, intento);

            if (intento == actual.palabra) {
                cout << "        +-------------------------------------------------------------+" << endl;
                cout << "                          Respuesta Correcta!" << endl;
                cout << "        +-------------------------------------------------------------+" << endl;
            } else {
                cout << "        +-------------------------------------------------------------+" << endl;
                cout << "                         Respuesta Incorrecta" << endl;
                cout << "        +-------------------------------------------------------------+" << endl;
                cout << "        +-------------------------------------------------------------+" << endl;
                cout << "                    La palabra era: " << actual.palabra << endl;
                cout << "        +-------------------------------------------------------------+" << endl;
            }

            cout << "¿Queres intentar con otra palabra?: ";
            string respuesta;
            getline(cin, respuesta);
            if (respuesta.empty() || (respuesta[0] != 's' && respuesta[0] != 'S')) {
                continuarRonda = false;
            }
        }

        cout << "¿Queres jugar otra vez desde el principio?: ";
        string respuesta;
        getline(cin, respuesta);
        if (respuesta.empty() || (respuesta[0] != 's' && respuesta[0] != 'S')) {
            jugarDeNuevo = 'n';
        }
    }

    cout << "        +--------------------------------------+" << endl;
    cout << "                   Gracias por jugar!" << endl;
    cout << "        +--------------------------------------+" << endl;
}

int main() {
    playArrangeWord();
    return 0;
}