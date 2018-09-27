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
		int numVertices;				//Numero de vertices del asteroide
		int factor;						//Tamaño del asteroide
		double velocidad;				//Velocidad del asteroide
		double inclinacion;				//Es la inclinacion de la trayectoria que seguira el asteroide
		int direccion;					//0 se mueve a la izquierda, 1 se mueve a la derecha.

	public:
		int getNumVertices();
		Asteroide(int n = 0);
		void anadeVertice(Coordenada);
		void imprimeVertices();
		vector<Coordenada> getVertices();
		Coordenada obtenerCentroDelAsteroide();
		void aplicarFactorYDesplazamiento(int);
		void trasladar(double x, double y);
		void rotar(float);
		void dibujar();
		void traslacion();
};

#endif
