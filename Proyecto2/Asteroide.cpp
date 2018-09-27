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
	//Inicializar valores para la Traslacion
	factor = rand() % 100 + 10;
	if (factor > 80)
		velocidad = 1;
	else if (factor > 40)
		velocidad = 2;
	else
		velocidad = 3;
	inclinacion = rand() % 201-100;
	direccion = rand() % 2;
}	 

/*ANADE LAS COORDENADAS DE LOS VERTICES AL VECTOR*/
void Asteroide::anadeVertice(Coordenada c)
{
	vertices.push_back(c);
	numVertices++;
}

/*IMPRIME LAS COORDENADAS DE CADA VERTICE DEL ASTEROIDE*/
void Asteroide::imprimeVertices()
{
	vector<Coordenada>::iterator i;
	int j=1;

	//Se recorre el vector por medio de un iterador de tipo Coordenada
	for (i = vertices.begin(); i != vertices.end(); i++){
		cout<< j++ << ".(" << i->obtenerX() << "," << i->obtenerY() << ")\n";
	}
	
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

void Asteroide::aplicarFactorYDesplazamiento(int desplazamiento)
{
	centroDelAsteroide.guardarX(0);
	centroDelAsteroide.guardarY(0);
	for (int i = 0 ; i < (int)vertices.size(); i++){
		vertices[i].guardarX((vertices[i].obtenerX() * factor) + desplazamiento);
		vertices[i].guardarY((vertices[i].obtenerY() * factor) + desplazamiento);
		centroDelAsteroide.guardarX(centroDelAsteroide.obtenerX() + vertices[i].obtenerX());
		centroDelAsteroide.guardarY(centroDelAsteroide.obtenerY() + vertices[i].obtenerY());
	}
	centroDelAsteroide.guardarX(centroDelAsteroide.obtenerX() / vertices.size());
	centroDelAsteroide.guardarY(centroDelAsteroide.obtenerY() / vertices.size());

}

void Asteroide::trasladar(double x, double y)
{
	for (int i = 0 ; i < (int)vertices.size(); i++){
		vertices[i].guardarX(vertices[i].obtenerX() + x);
		vertices[i].guardarY(vertices[i].obtenerY() + y);
	}
}

void Asteroide::rotar(float angulo)
{
	double seno = sin(angulo);
	double coseno = cos(angulo);
	double xAux;
	double yAux;
	for (int i = 0 ; i < (int)vertices.size(); i++){
		xAux = (vertices[i].obtenerX() * coseno) - (vertices[i].obtenerY() * seno);
		yAux = (vertices[i].obtenerY() * coseno) + (vertices[i].obtenerX() * seno);
		vertices[i].guardarX(xAux);
		vertices[i].guardarY(yAux);
	}
}

void Asteroide::dibujar()
{
	
	/*CREACION DE UN ITERADOR DE TIPO COORDENADA PARA EL VECTOR VERTICES*/
	vector<Coordenada>::iterator i = vertices.begin();

	/*DIBUJAR LINEAS DESDE LA COORDENADA ACTUAL A LA SIGUIENTE HASTA LA PENULTIMA COORDENADA*/
	int cont = 1;
	while(cont < numVertices){
		gfx_line(i->obtenerX() + centroDelAsteroide.obtenerX(), i->obtenerY() + centroDelAsteroide.obtenerY(),
		(i+1)->obtenerX() + centroDelAsteroide.obtenerX(), (i+1)->obtenerY() + centroDelAsteroide.obtenerY());
		i++;
		cont++;
	}

	//Regresar el iterador al inicio del vector
	i = vertices.begin();

	//Declaracion de un iterador de tipo Coordenada apuntando al final del vector vertices
	vector<Coordenada>::iterator j = vertices.end();

	//Dibujar laúltima linea del asteroide desde la coordenada de inicio a la ultima
	gfx_line(i->obtenerX() + centroDelAsteroide.obtenerX(), i->obtenerY() + centroDelAsteroide.obtenerY(),
	 (j-1)->obtenerX() + centroDelAsteroide.obtenerX(), (j-1)->obtenerY() + centroDelAsteroide.obtenerY());

	//Aplicar los cambios en la ventana
	gfx_flush();
}

void Asteroide::traslacion() {
	double x, y;
	//Choca arriba o abajo
	if(centroDelAsteroide.obtenerY() <= 0 || centroDelAsteroide.obtenerY() >= LARGO-300)
		inclinacion *= -1;
	//choca con el borde izquierdo
	if(centroDelAsteroide.obtenerX() <= 0 || centroDelAsteroide.obtenerX() >= ANCHO)
		direccion = (direccion + 1) % 2;


	if(direccion == 0)
		x = -velocidad;
	else
		x = velocidad;

	y = x * inclinacion; 
	
	centroDelAsteroide.guardarX(centroDelAsteroide.obtenerX() + x);
	centroDelAsteroide.guardarY(centroDelAsteroide.obtenerY() + y);
}