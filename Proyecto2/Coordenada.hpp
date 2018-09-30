/*SE DEFINE LA CLASE COORDENADA QUE CONTIENE LAS COORDENADAS DE
  LOS VERTICES PARA DIBUJAR UN ASTEORIDE*/
#ifndef COORDENADA_HPP_
#define COORDENADA_HPP_

class Coordenada{
 
	private:
		double x;   
		double y;
 
	public:
		Coordenada(double = 0, double = 0); 
		double obtenerX();
		double obtenerY();
		void guardarX(double);
		void guardarY(double);
};

#endif