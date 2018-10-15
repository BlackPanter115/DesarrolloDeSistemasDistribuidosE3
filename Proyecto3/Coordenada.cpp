//
// Created by sonia on 14/10/18.
//

#include "Coordenada.h"
#include <iostream>

using namespace std;

/*CONSTRUCTOR DE LA CLASE COORDENADA*/
Coordenada::Coordenada(char xx, char yy) : x(xx), y(yy)
{ }

/*DEVUELVE EL VALOR ACTUAL DE LA COORDENADA X*/
char Coordenada::obtenerX(){
    return x;
}

/*DEVUELVE EL VALOR ACTUAL DE LA COORDENADA Y*/
char Coordenada::obtenerY(){
    return y;
}

/*ASIGNA UN VALOR ESPECIFICO A LA COORDENADA X*/
void Coordenada::guardarX(char i){
    x = i;
}

/*ASIGNA UN VALOR ESPECIFICO A LA COORDENADA Y*/
void Coordenada::guardarY(char j){
    y = j;
}