#include "Coordenada.hpp"
#include <iostream>
using namespace std;

/*CONSTRUCTOR DE LA CLASE COORDENADA*/
Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy)
{ }
	
/*DEVUELVE EL VALOR ACTUAL DE LA COORDENADA X*/
double Coordenada::obtenerX(){
		return x;
}
	
/*DEVUELVE EL VALOR ACTUAL DE LA COORDENADA Y*/	
double Coordenada::obtenerY(){
	return y;
}

/*ASIGNA UN VALOR ESPECIFICO A LA COORDENADA X*/
void Coordenada::guardarX(double i){
	x = i;
}
	
/*ASIGNA UN VALOR ESPECIFICO A LA COORDENADA Y*/	
void Coordenada::guardarY(double j){
	y = j;
}