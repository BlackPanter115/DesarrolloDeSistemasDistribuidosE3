#include <iostream>
#include "PoligonoIrreg.hpp"
#include <vector>
#include <cmath>
#include "gfx.h"
#include <unistd.h>
#include <stdlib.h> 
const double PI = acos(-1.0);
using namespace std;

int PoligonoIrreg::numVertices = 0;

PoligonoIrreg::PoligonoIrreg()
{
	numVertices = 0;
}

PoligonoIrreg::PoligonoIrreg(int n)
{
	numVertices = n;
}	

void PoligonoIrreg::anadeVertice(Coordenada c)
{
	vertices.push_back(c);
	numVertices++;
}

void PoligonoIrreg::imprimeVertices()
{
	vector<Coordenada>::iterator i;
	int j=1;
	for (i = vertices.begin(); i != vertices.end(); i++){
		cout<< j++ << ".(" << i->obtenerX() << "," << i->obtenerY() << ")\n";
	}
	
}

int PoligonoIrreg::getNumVertices()
{
	return numVertices;
}

vector<Coordenada> PoligonoIrreg::getVertices()
{
	return vertices;
}

void PoligonoIrreg::aplicarFactorYDesplazamiento(int factor, int desplazamiento) {
	CentroDelPoligono.guardarX(0);
	CentroDelPoligono.guardarY(0);
	for (int i = 0 ; i < (int)vertices.size(); i++){
		vertices[i].guardarX((vertices[i].obtenerX() * factor) + desplazamiento);
		vertices[i].guardarY((vertices[i].obtenerY() * factor) + desplazamiento);
		CentroDelPoligono.guardarX(CentroDelPoligono.obtenerX() + vertices[i].obtenerX());
		CentroDelPoligono.guardarY(CentroDelPoligono.obtenerY() + vertices[i].obtenerY());
	}
	CentroDelPoligono.guardarX(CentroDelPoligono.obtenerX() / vertices.size());
	CentroDelPoligono.guardarY(CentroDelPoligono.obtenerY() / vertices.size());

}

void PoligonoIrreg::moverAlOrigen() {
	for (int i = 0 ; i < (int)vertices.size(); i++){
		vertices[i].guardarX(vertices[i].obtenerX() - CentroDelPoligono.obtenerX());
		vertices[i].guardarY(vertices[i].obtenerY() - CentroDelPoligono.obtenerY());
	}
}

void PoligonoIrreg::regresarDelOrigen() {
	for (int i = 0 ; i < (int)vertices.size(); i++){
		vertices[i].guardarX(vertices[i].obtenerX() + CentroDelPoligono.obtenerX());
		vertices[i].guardarY(vertices[i].obtenerY() + CentroDelPoligono.obtenerY());
	}
}

void PoligonoIrreg::rotar(float angulo) {
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

PoligonoReg::PoligonoReg(int n) : PoligonoIrreg(n)
{
	num = n;
	angulo = 360/n;
	double anguloCentral = 0;

	for (int i = 0; i < n; ++i){
		anadeVertice(Coordenada(cos((anguloCentral*PI)/180),sin((anguloCentral*PI)/180)));
		anguloCentral = anguloCentral + angulo;
	}

} 

void PoligonoReg::obtieneArea()
{
	vector<Coordenada> vertices = getVertices();
	vector<Coordenada>::iterator i;
	int j=0;
	for (i = vertices.begin(); i != vertices.end(); i++){
		j++;
	}

	double a = sin(((angulo/2)*PI)/180);
	double b = cos(((angulo/2)*PI)/180);

	cout << "El area es: " << (a*b)*j << "\n";

}

void PoligonoReg::dibujar(){
	int cont = 1;

	vector<Coordenada> vertices = getVertices();
	vector<Coordenada>::iterator i = vertices.begin();
	while(cont < num){
		gfx_line(i->obtenerX(), i->obtenerY(), (i+1)->obtenerX(), (i+1)->obtenerY());
		i++;
		cont++;
	}
	i = vertices.begin();
	vector<Coordenada>::iterator j = vertices.end();
	gfx_line(i->obtenerX(), i->obtenerY(), (j-1)->obtenerX(), (j-1)->obtenerY());
	gfx_flush();
}