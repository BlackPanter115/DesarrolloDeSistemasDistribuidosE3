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

PoligonoReg::PoligonoReg(int n) : PoligonoIrreg(n)
{
	num = n;
	angulo = 360/n;
	double x,y;
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

void PoligonoReg::dibujar()
{
	srand (time(NULL));
	int factor = rand() % 100 + 10;
	int desplazamiento = rand() % 600 + 100;
	int cont = 1;

	vector<Coordenada> vertices = getVertices();
	vector<Coordenada>::iterator i = vertices.begin();
	while(cont < num){
		gfx_line( (i->obtenerX()*factor)+desplazamiento, (i->obtenerY()*factor)+desplazamiento, ((i+1)->obtenerX()*factor)+desplazamiento, ((i+1)->obtenerY()*factor)+desplazamiento );
		i++;
		cont++;
	}
	i = vertices.begin();
	vector<Coordenada>::iterator j = vertices.end();
	gfx_line( (i->obtenerX()*factor)+desplazamiento, (i->obtenerY()*factor)+desplazamiento, ((j-1)->obtenerX()*factor)+desplazamiento, ((j-1)->obtenerY()*factor)+desplazamiento );
	gfx_flush();
}