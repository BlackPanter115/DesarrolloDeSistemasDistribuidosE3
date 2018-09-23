#ifndef POLIGONOIRREG_HPP_
#define POLIGONOIRREG_HPP_

#include <vector>
#include "Coordenada.hpp"

using namespace std;

class PoligonoIrreg{
 
	private:
		vector<Coordenada> vertices;
		static int numVertices;
 
	public:
		static int getNumVertices();
		PoligonoIrreg();
		PoligonoIrreg(int n);
		void anadeVertice(Coordenada);
		void imprimeVertices();
		vector<Coordenada> getVertices();
};

class PoligonoReg : public PoligonoIrreg 
{ 
	private: 
		double angulo;
		int num;
	public: 
		PoligonoReg(int n = 0);
		void obtieneArea();
		void dibujar();
};

#endif
