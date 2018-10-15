//
// Created by sonia on 14/10/18.
//

#ifndef _PUZZLE_H_
#define _PUZZLE_H_
#include "Coordenada.h"
#include <string.h>
#include <vector>
#include <queue>
#define MAX_NODOS 1000

using namespace std;

class Puzzle {
    private:
        static char objetivo[3][3];             //Nodo al que se quiere llegar
        static queue<Puzzle*> hijos;            //Se guardaran los hijos realizados
        static int numNodos;
        static vector<Coordenada> *solucion;
        char tablero[3][3];                     //tablero actual
        Coordenada vacio;                       //Tendra las coordenadas del espacio vacio en el puzzle
        Coordenada vacioAnterior;               //Se guardara la coordenada donde se encontraba el vacio
        vector<Coordenada> movimientos;         //Se guardan las coordenadas de los movimientos realizados

    public:
        Puzzle(char*);                          //Constructor con una cadena
        Puzzle(Puzzle*);                        //Constructor con un puzzle
        void mover(Coordenada&);                //Mover a las coordenadas mandadas
        void mostrarTablero();                  //Mostrar el tablero del puzzle
        void establecerObjetivo(char*);         //Se establece el puzzle objetivo
        char getValor(Coordenada&);             //Obtener el valor
        void setValor(Coordenada&, char);       //Establecer el valor
        bool generarNodos();                    //Generar Nodos
        bool solucionar();                      //Buscar la solucion para llegar al puzzle objetivo
        bool esObjetivo();                      //Comprobar si el nodo es el puzzle objetivo
        void setSolucion(vector<Coordenada>*);
        void mostrarSolucion();
};


#endif //PROYECTO3_PUZZLE_H
