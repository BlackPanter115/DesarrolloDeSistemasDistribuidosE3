#include "gfx.h"
#include <unistd.h>
#include "PoligonoIrreg.hpp"
#include <stdlib.h>
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
	gfx_clear();

	vector<PoligonoReg>::iterator i = asteroides.begin();
	int cont = 0;
	while(cont < n){
		srand (time(NULL));
		i->dibujar();
		i++;
		cont++;
	}

	for(t = 0; t < 100; t++){
		usleep(41666); //24 por segundo
	}
	return 0;
}