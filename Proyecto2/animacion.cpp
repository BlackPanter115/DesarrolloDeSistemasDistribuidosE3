#include "gfx.h"
#include <unistd.h>
#include "PoligonoIrreg.hpp"
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	srand (time(NULL));
	int n = 20;
	int vertices = 0;
	vector<PoligonoReg> asteroides;

	for(int i = 0; i<=n; i++){
		vertices = rand() % 8 + 3;
		PoligonoReg	p(vertices);
		asteroides.push_back(p);
	}

	int t;
	gfx_open(800, 600, "Ejemplo Micro Animacion GFX");
	gfx_color(0,200,100);

	vector<PoligonoReg>::iterator pol = asteroides.begin();
	int cont = 0;
	while(cont < n){
		int factor = rand() % 100 + 10;
		int desplazamiento = rand() % 600 + 100;
		pol->aplicarFactorYDesplazamiento(factor, desplazamiento);
		pol++;
		cont++;
	}
	double alfa = ((double) (rand () % 101) / 50) * M_PI;
	for(int i = 0 ; i < 6 ; i++) {
		gfx_clear();
		vector<PoligonoReg>::iterator pol = asteroides.begin();
		cont = 0;
		while(cont < n){
			srand (time(NULL));
			pol->dibujar();
			pol++;
			cont++;
		}
		for(int j = 0; j<=n; j++){
			asteroides[j].moverAlOrigen();
			asteroides[j].rotar(alfa*(i + 1));
			asteroides[j].regresarDelOrigen();
		}

		for(t = 0; t < 100; t++){
			usleep(41666); //24 por segundo
		}
	}
	return 0;
}