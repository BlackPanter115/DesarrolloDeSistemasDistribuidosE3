#include "gfx.h"
#include <unistd.h>
#include "Asteroide.hpp"
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	if (argc < 2) {
		cout << endl << "Argumentos insuficientes, por favor escriba el comando de la siguiente manera: " << endl;
		cout << "\t./animacion [no. de Asteriodes]" << endl;
		cout << "\tmake n=[no de asteroides]" << endl << endl;
		return -1;
	}
	srand(time(NULL));				//Generador de numeros random

	/*DECLARACION DE VARIABLES*/
	int n = atoi(argv[1]); 					//Numero de asteroides para dibujar
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
	/*while(cont < n){
		//int factor = rand() % 100 + 10;
		//int desplazamiento = rand() % 600 + 100;
		//pol->aplicarFactorYDesplazamiento(desplazamiento);
		pol++;
		cont++;
	}*/

	//Calculo del angulo de rotacion

	/**DIBUJAR TODOS LOS ASTEROIDES CON ROTACION Y TRASLACION*/
	for(int i = 0 ; i < 1000 ; i++) {
		gfx_clear();
		pol = asteroides.begin();

		for (pol = asteroides.begin(); pol != asteroides.end(); pol++) {
			pol->dibujar();
			//pol->traslacion();
		}

		for(int j = 0; j<=n; j++){
			
			//Traslacion
			asteroides[j].traslacion();
		}

		//for(int t = 0; t < 100; t++){
			usleep(41666);
		//}
		
	}

	return 0;
}