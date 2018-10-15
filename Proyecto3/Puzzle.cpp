//
// Created by sonia on 14/10/18.
//

#include "Puzzle.h"
#include "Coordenada.h"
#include <iostream>

//Atributos estaticos
char Puzzle::objetivo[3][3] = {0,0,0,0,0,0,0,0,0};
queue<Puzzle*> Puzzle::hijos;
int Puzzle::numNodos = 0;
vector<Coordenada> * Puzzle::solucion = nullptr;

//Constructores
Puzzle::Puzzle(char* cadena) {
    for(int i = 0; i < strlen(cadena); i++){
        tablero[i/3][i%3] = *(cadena + i);

        //Buscar la casilla vacia (x) y guardar en vacio
        if(tablero[i/3][i%3] == 'x')
            vacio = Coordenada((char)(i%3),(char)(i/3));
    }
    //Inicializar la variable vacioAnterior
    vacioAnterior = Coordenada(-1, -1);
}

//Copiar los atributos de puzzle padre
Puzzle::Puzzle(Puzzle *padre) {
    vacio = Coordenada(padre->vacio.obtenerX(), padre->vacio.obtenerY());
    vacioAnterior = Coordenada(padre->vacio.obtenerX(), padre->vacio.obtenerY());
    memcpy(tablero, padre->tablero, 9);
    for (vector<Coordenada>:: iterator mov = padre->movimientos.begin(); mov < padre->movimientos.end(); mov++) {
        movimientos.push_back(*mov);
    }
}

void Puzzle:: mostrarTablero(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3;j++){
            cout << " " << tablero[i][j];
        }
        cout << endl;
    }
}

//Guardar la cadena recibida en forma de puzzle para el puzzle objetivo
void Puzzle::establecerObjetivo(char *obj) {
    for(int i = 0; i < strlen(obj); i++){
        objetivo[i/3][i%3] = *(obj + i);
    }
}

//Coordenada a donde se va a mover el espacio
void Puzzle::mover(Coordenada &c) {
    movimientos.push_back(c);
    setValor(vacio, getValor(c));
    setValor(c, 'x');
    vacio.guardarX(c.obtenerX());
    vacio.guardarY(c.obtenerY());
}

char Puzzle::getValor(Coordenada &c) {
    return tablero[c.obtenerY()][c.obtenerX()];
}

void Puzzle::setValor(Coordenada &c, char valor) {
    tablero[c.obtenerY()][c.obtenerX()] = valor;
}

bool Puzzle::generarNodos() {
    Coordenada destino;
    Puzzle *nuevo;
    if (numNodos >= MAX_NODOS)
        return false;

    //Caso cuando no se tiene un vacio anterior
    if(vacioAnterior.obtenerX() == -1) {

        //Se puede mover arriba
        if (vacio.obtenerY() > 0) {
            nuevo = new Puzzle(this);
            hijos.push(nuevo);
            numNodos++;
            destino.guardarX(vacio.obtenerX());
            destino.guardarY(vacio.obtenerY() - (char) 1);
            nuevo->mover(destino);
        }

        //Se puede mover abajo
        if (vacio.obtenerY() < 2) {
            nuevo = new Puzzle(this);
            hijos.push(nuevo);
            numNodos++;
            destino.guardarX(vacio.obtenerX());
            destino.guardarY(vacio.obtenerY() + (char) 1);
            nuevo->mover(destino);
        }

        //Se puede mover izquierda
        if (vacio.obtenerX() > 0) {
            nuevo = new Puzzle(this);
            hijos.push(nuevo);
            numNodos++;
            destino.guardarX(vacio.obtenerX() - (char) 1);
            destino.guardarY(vacio.obtenerY());
            nuevo->mover(destino);
        }

        //Se puede mover derecha
        if (vacio.obtenerX() < 2) {
            nuevo = new Puzzle(this);
            hijos.push(nuevo);
            numNodos++;
            destino.guardarX(vacio.obtenerX() + (char) 1);
            destino.guardarY(vacio.obtenerY());
            nuevo->mover(destino);
        }
    }

    //Caso cuando ya te tiene un vacio anterior guardado
    else{
        //Se puede mover arriba
        if (vacio.obtenerY() > 0 && vacioAnterior.obtenerY() >= vacio.obtenerY()) {
            nuevo = new Puzzle(this);
            hijos.push(nuevo);
            numNodos++;
            destino.guardarX(vacio.obtenerX());
            destino.guardarY(vacio.obtenerY() - (char) 1);
            nuevo->mover(destino);
        }

        //Se puede mover abajo
        if (vacio.obtenerY() < 2 && vacioAnterior.obtenerY() <= vacio.obtenerY()) {
            nuevo = new Puzzle(this);
            hijos.push(nuevo);
            numNodos++;
            destino.guardarX(vacio.obtenerX());
            destino.guardarY(vacio.obtenerY() + (char) 1);
            nuevo->mover(destino);
        }

        //Se puede mover izquierda
        if (vacio.obtenerX() > 0 && vacioAnterior.obtenerX() >= vacio.obtenerX()) {
            nuevo = new Puzzle(this);
            hijos.push(nuevo);
            numNodos++;
            destino.guardarX(vacio.obtenerX() - (char) 1);
            destino.guardarY(vacio.obtenerY());
            nuevo->mover(destino);
        }

        //Se puede mover derecha
        if (vacio.obtenerX() < 2 && vacioAnterior.obtenerX() <= vacio.obtenerX()) {
            nuevo = new Puzzle(this);
            hijos.push(nuevo);
            numNodos++;
            destino.guardarX(vacio.obtenerX() + (char) 1);
            destino.guardarY(vacio.obtenerY());
            nuevo->mover(destino);
        }
    }

    return true;
}

bool Puzzle::solucionar() {
    //En caso de no ser el puzzle objetivo se generan nodos
    if(!esObjetivo()){
        generarNodos();
        while(!hijos.empty()) {
            Puzzle *hijo = hijos.front();
            hijos.pop();
            //Al ser el objetivo, se regresa true para finalizar la creacion de nodos
            if (hijo->esObjetivo()) {
                setSolucion(&hijo->movimientos);
                return true;
            }
            //En caso contrario se siguen generando nodos
            if (!hijo->generarNodos())
                return false;
        }
    }
}

bool Puzzle::esObjetivo() {
    for (int i = 0; i < 3; i++) {
        for(int j = 0 ; j < 3; j++){
            if(tablero[i][j] != objetivo[i][j])
                return false;
        }
    }
    return true;
}

void Puzzle::setSolucion(vector<Coordenada> *sol) {
    solucion = sol;
}

void Puzzle::mostrarSolucion() {
    mostrarTablero();
    cout << endl;
    for(vector<Coordenada>::iterator i = solucion->begin(); i != solucion->end(); i++){
        mover(*i);
        mostrarTablero();
        cout << endl;
    }
}