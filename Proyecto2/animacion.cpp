#include "gfx.h"
#include <unistd.h>
#include "Asteroide.hpp"
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	srand(time(NULL));				//Generador de numeros random

	/*DECLARACION DE VARIABLES*/
	int n = 20; 					//Numero de asteroides para dibujar
	int vertices = 0;				//Numero de vertices para cada asteoride
	vector<Asteroide> asteroides;	//Vector de tipo Asteroide


	/*GENERACION DE NUMERO DE VERTICES PARA CADA ASTEROIDE*/
	for(int i = 0; i<=n; i++){
		vertices = rand() % 8 + 3;
		Asteroide	p(vertices);
		asteroides.push_back(p);
	}

	/*CREACION DE LA VENTANA DE LA ANIMACION*/
	gfx_open(800, 600, "Proyecto 2 - Equipo 3");
	gfx_color(0,200,100);


	//Declaracion de un iterador para el vector asteorides
	vector<Asteroide>::iterator pol = asteroides.begin();

	/*GENERACION DEL FACTOR DE ESCALA Y DE DESPLAZAMIENTO PARA CADA ASTEROIDE*/
	int cont = 0;
	while(cont < n){
		//int factor = rand() % 100 + 10;
		int desplazamiento = rand() % 600 + 100;
		pol->aplicarFactorYDesplazamiento(desplazamiento);
		pol++;
		cont++;
	}

	//Calculo del angulo de rotacion
	double alfa = ((double) (rand () % 101) / 50) * M_PI;

	/**DIBUJAR TODOS LOS ASTEROIDES CON ROTACION*/
	for(int i = 0 ; i < 1000 ; i++) {
		gfx_clear();
		pol = asteroides.begin();
		cont = 0;

		for (pol = asteroides.begin(); pol != asteroides.end(); pol++) {
			pol->dibujar();
			pol->traslacion();
		}

		/*for(int j = 0; j<=n; j++){
			asteroides[j].trasladar(-asteroides[j].obtenerCentroDelAsteroide().obtenerX(),-asteroides[j].obtenerCentroDelAsteroide().obtenerY());
			asteroides[j].rotar(alfa*(i + 1));
			asteroides[j].trasladar(asteroides[j].obtenerCentroDelAsteroide().obtenerX(),asteroides[j].obtenerCentroDelAsteroide().obtenerY());
		
			//Traslacion
			asteroides[j].traslacion();
		}*/

		//for(int t = 0; t < 100; t++){
			usleep(600000);
		//}
		
	}

	return 0;
}