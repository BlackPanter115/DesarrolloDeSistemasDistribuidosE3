/*SE DEFINE LA CLASE ASTEROIDE*/
#ifndef ASTEROIDE_HPP_
#define ASTEROIDE_HPP_

#include <vector>
#include "Coordenada.hpp"

using namespace std;

class Asteroide{
 
	private:
		vector<Coordenada> vertices;	//Vector de Coordenadas referentes a cada vertice del asteoride
		Coordenada CentroDelAsteroide;	//Coordenada del centro del asteroide
		double angulo;					//Angulo entre los lados del asteoride
		int numVertices;				//Numero de vertices del asteroide
 
	public:
		int getNumVertices();
		Asteroide(int n = 0);
		void anadeVertice(Coordenada);
		void imprimeVertices();
		vector<Coordenada> getVertices();
		void aplicarFactorYDesplazamiento(int, int);
		void moverAlOrigen();
		void regresarDelOrigen();
		void rotar(float);
		void dibujar();
};

#endif
