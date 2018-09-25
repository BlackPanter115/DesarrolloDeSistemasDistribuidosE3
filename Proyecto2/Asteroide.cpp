#include <iostream>
#include "Asteroide.hpp"
#include <vector>
#include <cmath>
#include "gfx.h"
#include <unistd.h>
#include <stdlib.h>

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

void Asteroide::aplicarFactorYDesplazamiento(int factor, int desplazamiento)
{
	CentroDelAsteroide.guardarX(0);
	CentroDelAsteroide.guardarY(0);
	for (int i = 0 ; i < (int)vertices.size(); i++){
		vertices[i].guardarX((vertices[i].obtenerX() * factor) + desplazamiento);
		vertices[i].guardarY((vertices[i].obtenerY() * factor) + desplazamiento);
		CentroDelAsteroide.guardarX(CentroDelAsteroide.obtenerX() + vertices[i].obtenerX());
		CentroDelAsteroide.guardarY(CentroDelAsteroide.obtenerY() + vertices[i].obtenerY());
	}
	CentroDelAsteroide.guardarX(CentroDelAsteroide.obtenerX() / vertices.size());
	CentroDelAsteroide.guardarY(CentroDelAsteroide.obtenerY() / vertices.size());

}

void Asteroide::moverAlOrigen()
{
	for (int i = 0 ; i < (int)vertices.size(); i++){
		vertices[i].guardarX(vertices[i].obtenerX() - CentroDelAsteroide.obtenerX());
		vertices[i].guardarY(vertices[i].obtenerY() - CentroDelAsteroide.obtenerY());
	}
}

void Asteroide::regresarDelOrigen()
{
	for (int i = 0 ; i < (int)vertices.size(); i++){
		vertices[i].guardarX(vertices[i].obtenerX() + CentroDelAsteroide.obtenerX());
		vertices[i].guardarY(vertices[i].obtenerY() + CentroDelAsteroide.obtenerY());
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
		gfx_line(i->obtenerX(), i->obtenerY(), (i+1)->obtenerX(), (i+1)->obtenerY());
		i++;
		cont++;
	}

	//Regresar el iterador al inicio del vector
	i = vertices.begin();

	//Declaracion de un iterador de tipo Coordenada apuntando al final del vector vertices
	vector<Coordenada>::iterator j = vertices.end();

	//Dibujar laúltima linea del asteroide desde la coordenada de inicio a la ultima
	gfx_line(i->obtenerX(), i->obtenerY(), (j-1)->obtenerX(), (j-1)->obtenerY());

	//Aplicar los cambios en la ventana
	gfx_flush();
}