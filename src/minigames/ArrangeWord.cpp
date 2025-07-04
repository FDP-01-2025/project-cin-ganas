#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>

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
    srand(time(0));

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
        {"Gradas", "\"Puy6a ya me canse de subir tantas ....\""},
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

    cout << "Bienvenido al juego Ordena la palabra" << endl;
    cout << "En este juego tenes que adivinar palabras o frases que identifican a la UCA" << endl;

    char jugarDeNuevo = 's';

    while (jugarDeNuevo == 's' || jugarDeNuevo == 'S') {
        bool continuarRonda = true;

        while (continuarRonda) {
            cout << "Selecciona un nivel de dificultad para esta palabra:" << endl;
            cout << "1. Facil" << endl;
            cout << "2. Medio" << endl;
            cout << "3. Dificil" << endl;
            cout << "Ingresa 1, 2 o 3: ";

            int nivel;
            cin >> nivel;
            cin.ignore();

            vector<PalabraPista> palabrasSeleccionadas;

            if (nivel == 1) {
                palabrasSeleccionadas = nivelFacil;
            } else if (nivel == 2) {
                palabrasSeleccionadas = nivelMedio;
            } else if (nivel == 3) {
                palabrasSeleccionadas = nivelDificil;
            } else {
                cout << "Opcion no valida. Se usara nivel medio por defecto." << endl;
                palabrasSeleccionadas = nivelMedio;
            }

            PalabraPista actual = palabrasSeleccionadas[rand() % palabrasSeleccionadas.size()];

            string soloLetras;
            for (char c : actual.palabra) {
                if (c != ' ') soloLetras += c;
            }

            string desordenada = desordenarPalabra(soloLetras);

            cout << "Adivina la palabra o frase con estas letras: " << desordenada << endl;
            cout << "Pista: " << actual.pista << endl;

            cout << "Tu respuesta: ";
            string intento;
            getline(cin, intento);

            if (intento == actual.palabra) {
                cout << "Excelente, adivinaste la palabra!" << endl;
            } else {
                cout << "Incorrecto. La palabra era: " << actual.palabra << endl;
            }

            cout << "Queres intentar con otra palabra?: ";
            string respuesta;
            getline(cin, respuesta);
            if (respuesta.empty() || (respuesta[0] != 's' && respuesta[0] != 'S')) {
                continuarRonda = false;
            }
        }

        cout << "Queres jugar otra vez desde el principio?: ";
        string respuesta;
        getline(cin, respuesta);
        if (respuesta.empty() || (respuesta[0] != 's' && respuesta[0] != 'S')) {
            jugarDeNuevo = 'n';
        }
    }

    cout << "Gracias por jugar" << endl;
}

// Esta es la funcion principal que se necesita para compilar correctamente
int main() {
    playArrangeWord();
    return 0;
}