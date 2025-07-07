#include <iostream>
#include <limits>
using namespace std;


int validateInt() { //validates integer input
    int value;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cin.clear();  // clears error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears buffer
            cout << "Entrada invalida. Por favor ingresa un numero valido: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears everything and returns the value
            return value;
        }
    }
}