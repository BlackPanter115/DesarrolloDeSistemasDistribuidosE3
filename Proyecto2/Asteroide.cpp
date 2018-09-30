#include <iostream>
#include "Asteroide.hpp"
#include <vector>
#include <cmath>
#include "gfx.h"
#include <unistd.h>
#include <stdlib.h>

#define ANCHO 800
#define LARGO 600

const double PI = acos(-1.0);
using namespace std;

/*CONSTRUCTOR DE LA CLASE ASTEROIDE*/
Asteroide::Asteroide(int n)
{
	numVertices = 0;
	angulo = 360/n;
	double anguloCentral = 0;

	//Anade las coordenadas de los vertices calculados al vector vertices
	for (int i = 0; i < n; ++i){
		anadeVertice(Coordenada(cos((anguloCentral*PI)/180),sin((anguloCentral*PI)/180)));
		anguloCentral = anguloCentral + angulo;
	}

	//Inicializar valores para la traslacion
	factor = rand() % 100 + 10;
	velocidad = 100.0 / (double)factor;
	inclinacion = rand() % 3;
	direccion = rand() % 2;

	//Inicializar valores para la rotacion
	anguloOrigen = 0;
	if(rand()%2)
		//Giro a la izquierda
		velocidadDeGiro = 2;
	else
		//Giro a la derecha
		velocidadDeGiro = angulo - 2;

	//Colocar centro aleatoriamente dentro de la pantalla
	centroDelAsteroide.guardarX(rand() % (ANCHO +1));
	centroDelAsteroide.guardarY(rand() % (LARGO +1));
}	 

/*ANADE LAS COORDENADAS DE LOS VERTICES AL VECTOR*/
void Asteroide::anadeVertice(Coordenada c)
{
	vertices.push_back(c);
	numVertices++;
}

/*DEVUELVE EL NUMERO DE VERTICES DEL ASTEROIDE*/
int Asteroide::getNumVertices()
{
	return numVertices;
}

/*DEVUELVE EL VECTOR CORRESPONDIENTE A LOS VERTICES DEL ASTEROIDE*/
vector<Coordenada> Asteroide::getVertices()
{
	return vertices;
}

Coordenada Asteroide::obtenerCentroDelAsteroide() {
	return centroDelAsteroide;
}

void Asteroide::dibujar()
{
	/*CREACION DE UN ITERADOR DE TIPO COORDENADA PARA EL VECTOR VERTICES*/
	vector<Coordenada>::iterator i = vertices.begin();

	/*DIBUJAR LINEAS DESDE LA COORDENADA ACTUAL A LA SIGUIENTE HASTA LA PENULTIMA COORDENADA*/
	int cont = 1;
	while(cont < numVertices){
		gfx_line(i->obtenerX()*factor + centroDelAsteroide.obtenerX(), i->obtenerY()*factor + centroDelAsteroide.obtenerY(),
		(i+1)->obtenerX()*factor + centroDelAsteroide.obtenerX(), (i+1)->obtenerY()*factor + centroDelAsteroide.obtenerY());
		i++;
		cont++;
	}

	//Regresar el iterador al inicio del vector
	i = vertices.begin();

	//Declaracion de un iterador de tipo Coordenada apuntando al final del vector vertices
	vector<Coordenada>::iterator j = vertices.end();

	//Dibujar laúltima linea del asteroide desde la coordenada de inicio a la ultima
	gfx_line(i->obtenerX()*factor + centroDelAsteroide.obtenerX(), i->obtenerY()*factor + centroDelAsteroide.obtenerY(),
	 (j-1)->obtenerX()*factor + centroDelAsteroide.obtenerX(), (j-1)->obtenerY()*factor + centroDelAsteroide.obtenerY());

	//Aplicar los cambios en la ventana
	gfx_flush();
}

void Asteroide::traslacion()
{
	double x, y;
	//Si choca arriba o abajo cambia su inclinacion
	if(centroDelAsteroide.obtenerY() <= 0 || centroDelAsteroide.obtenerY() >= LARGO)
		inclinacion *= -1;
	//Si choca con el borde izquierdo se cambia la direccion 
	if(centroDelAsteroide.obtenerX() <= 0 || centroDelAsteroide.obtenerX() >= ANCHO){
		direccion = (direccion + 1) % 2;
		inclinacion *= -1;
	}

	//Al ser 0 se movera a la izquierda.
	if(direccion == 0)
		x = -velocidad;
	else
		x = velocidad;

	y = x * inclinacion; 
	
	centroDelAsteroide.guardarX(centroDelAsteroide.obtenerX() + x);
	centroDelAsteroide.guardarY(centroDelAsteroide.obtenerY() + y);
	rotacion();
}

void Asteroide::rotacion(){
	//Incrementa el angulo a partir del que se va dibujar dependiendo de su velocidad
	anguloOrigen += velocidadDeGiro;
	if(anguloOrigen >= 360){
		anguloOrigen -= 360;
	} 
	double anguloCentral = anguloOrigen;
	//Calcular vertices con respecto al nuevo angulo central
	for (vector<Coordenada>::iterator vertice = vertices.begin(); vertice < vertices.end(); vertice++){
		vertice->guardarX(cos((anguloCentral*PI)/180));
		vertice->guardarY(sin((anguloCentral*PI)/180));

		anguloCentral = anguloCentral + angulo;
	}
}