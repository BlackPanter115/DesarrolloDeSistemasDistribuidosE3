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
		return -1;
	}

	srand(time(NULL));				//Generador de numeros random

	/*DECLARACION DE VARIABLES*/
	int n = atoi(argv[1]); 			//Numero de asteroides para dibujar
	int vertices;					//Numero de vertices para cada asteoride
	vector<Asteroide> asteroides;	//Vector de tipo Asteroide


	/*GENERACION DE NUMERO DE VERTICES PARA CADA ASTEROIDE*/
	for(int i = 0; i<n; i++){
		vertices = rand() % 12 + 5;
		Asteroide	p(vertices);
		asteroides.push_back(p);
	}

	/*CREACION DE LA VENTANA DE LA ANIMACION*/
	gfx_open(800, 600, "Proyecto 2 - Equipo 3");
	gfx_color(0,200,100);

	//Declaracion de un iterador para el vector asteorides
	vector<Asteroide>::iterator ast = asteroides.begin();

	/**DIBUJAR TODOS LOS ASTEROIDES CON ROTACION Y TRASLACION*/
	for(int i = 0 ; i < 1000 ; i++) {
		gfx_clear();
		ast = asteroides.begin();

		for (ast = asteroides.begin(); ast != asteroides.end(); ast++){
			ast->dibujar();
		}

		for(int j = 0; j<=n; j++){
			asteroides[j].traslacion();
		}
			
		usleep(41666);
	}

	return 0;
}