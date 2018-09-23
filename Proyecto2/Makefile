run: animacion
	./animacion
animacion: gfx.o Coordenada.o PoligonoIrreg.o animacion.o
	g++ gfx.o Coordenada.o PoligonoIrreg.o animacion.o -o animacion -lX11
animacion.o: animacion.cpp
	g++ animacion.cpp -c -Wall
PoligonoIrreg.o: PoligonoIrreg.cpp
	g++ PoligonoIrreg.cpp -c  -Wall
Coordenada.o: Coordenada.cpp
	g++ Coordenada.cpp -c  -Wall
gfx.o: gfx.c
	gcc gfx.c -c -Wall
clear:
	rm gfx.o Coordenada.o PoligonoIrreg.o animacion.o animacion