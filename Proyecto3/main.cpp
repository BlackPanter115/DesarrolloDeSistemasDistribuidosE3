#include <iostream>
#include "Puzzle.h"

using namespace std;

int main() {
    char cadenaIni[10], cadenaFin[10];

    //Solicitar el puzzle inicial como una cadena de caracteres
    cout << "Ingresa el puzzle inicial: " << endl;
    cin >> cadenaIni;
    //Crear el puzzle inicial
    Puzzle a(cadenaIni);
    a.mostrarTablero();

    //Solicitar el puzzle objetivo como una cadena de caracteres
    cout << "Ingresa el puzzle objetivo: " << endl;
    cin >> cadenaFin;
    a.establecerObjetivo(cadenaFin);

    if(a.solucionar()){
        cout << "Solucion: " <<endl;
        a.mostrarSolucion();
    }

    else
        cout << "No tiene solucion. " <<endl;
    return 0;
}