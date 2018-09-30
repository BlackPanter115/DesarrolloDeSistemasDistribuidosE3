/*SE DEFINE LA CLASE ASTEROIDE*/
#ifndef ASTEROIDE_HPP_
#define ASTEROIDE_HPP_

#include <vector>
#include "Coordenada.hpp"

using namespace std;

class Asteroide{
 
	private:
		vector<Coordenada> vertices;	//Vector de Coordenadas referentes a cada vertice del asteoride
		Coordenada centroDelAsteroide;	//Coordenada del centro del asteroide
		double angulo;					//Angulo entre los lados del asteoride
		double velocidadDeGiro;			//Velocidad con la que gira el asteroide
		double anguloOrigen;			//Angulo a partir del cual se calculan los vertices
		int numVertices;				//Numero de vertices del asteroide
		int factor;						//Tamaño del asteroide
		double velocidad;				//Velocidad del asteroide
		double inclinacion;				//Es la inclinacion de la trayectoria que seguira el asteroide
		int direccion;					//0 se mueve a la izquierda, 1 se mueve a la derecha.

	public:
		int getNumVertices();
		Asteroide(int n = 0);
		void anadeVertice(Coordenada);
		vector<Coordenada> getVertices();
		Coordenada obtenerCentroDelAsteroide();
		void dibujar();
		void traslacion();
		void rotacion();
};

#endif
