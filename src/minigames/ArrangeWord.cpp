#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

struct PalabraPista {
    string palabra;
    string pista;
};

string desordenarPalabra(const string& palabraOriginal) {
    string desordenada = palabraOriginal;
    random_shuffle(desordenada.begin(), desordenada.end());
    return desordenada;
}

void playArrangeWord() {
    srand(time(0));

    vector<PalabraPista> palabrasPistas = {
        {"UCA", "El nombre de una de las universidades mas reconocidas del pais"},
        {"Las Terrazas", "\"Dicen que los capuchinos que venden en .... son buenos\""},
        {"ICAS", "Donde los salones tienen aire acondicionado"},
        {"La pea", "\"Ey vamos a ... tengo hambre, vamos a ver que comemos\""},
        {"El poli", "\"Ey en .... va a ver un partido ahora, vamos a verlo\""},
        {"Buho", "Es la mascota que nos representa"},
        {"Magnas", "Los asientos de las .... son incomodos"},
        {"Sultana", "\"Ey tengo ganas de Wendy's, salgamos por la .... que queda más cerca\""},
        {"Mercaduca", "Productos de estudiantes emprendedores"},
        {"Catedraticos", "Son los encargados de nuestra educacion"},
        {"Decanato", "Son las direcciones administrativas"},
        {"Cafeteria principal", "Uno de los lugares favoritos para ir a comer dentro de la universidad"},
        {"Parqueo anexo", "\"Puya hoy me toco ir a dejar el carro hasta el ...., me quedo bien lejos\""},
        {"Carteleras", "Siempre se encuentra informacion necesaria"},
        {"Carnet", "\"Mire le voy a dictar mi numero de ...\""},
        {"Ardillas", "Son animales que siempre se ven en los arboles"},
        {"Gatos", "Son animales que andan por todo el campus de la universidad y caminan en cuatro patas"},
        {"Pericos", "Son animales que solo los ven y los escuchan los que madrugan"},
        {"Gradas", "\"Puy6a ya me canse de subir tantas ....\""},
        {"Tutorias", "Son minis repasos de las clases"},
        {"Parciales", "La razon del estres de todos los estudiantes"},
        {"UNO", "\"Ey anda pedi prestado el ... para jugar\""},
        {"Jenga", "\"ojala en este juego llegues a botar la torre\""},
        {"Libros", "\"Necesito prestar un ... de la biblioteca\""},
        {"Hola mundo", "Frase que conoce todo informatico"}
    };

    cout << "¡Bienvenido al juego \"Ordena la palabra\"!" << endl;
    cout << "Aquí tendrás que adivinar palabras o frases que representan cosas que identifican a la UCA." << endl;
    cout << "¿Estás listo para comenzar? Presiona ENTER para continuar...";
    cin.get();

    char jugarDeNuevo = 's';

    while (jugarDeNuevo == 's' || jugarDeNuevo == 'S') {
        vector<PalabraPista> palabrasRestantes = palabrasPistas;
        random_shuffle(palabrasRestantes.begin(), palabrasRestantes.end());

        size_t indice = 0;
        while (indice < palabrasRestantes.size()) {
            PalabraPista actual = palabrasRestantes[indice];

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
                cout << "¡Excelente, adivinaste la palabra!" << endl;
            } else {
                cout << "Oh oh, no es correcto. La palabra era: " << actual.palabra << endl;
            }

            indice++;

            if (indice < palabrasRestantes.size()) {
                cout << "¿Queres intentar con otra palabra? ";
                string respuesta;
                getline(cin, respuesta);
                if (respuesta.empty() || (respuesta[0] != 's' && respuesta[0] != 'S')) {
                    break;
                }
            } else {
                cout << "¡Felicidades! Has adivinado todas las palabras disponibles." << endl;
            }
        }

        cout << "¿Queres jugar otra vez desde el principio? ";
        string respuesta;
        getline(cin, respuesta);
        if (respuesta.empty() || (respuesta[0] != 's' && respuesta[0] != 'S')) {
            jugarDeNuevo = 'n';
        } else {
            cout << "¡Perfecto! Preparando un nuevo desafío para ti..." << endl;
        }
    }

    cout << "Gracias por jugar" << endl;

}