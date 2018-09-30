run: animacion
	./animacion $(n)
animacion: gfx.o Coordenada.o Asteroide.o animacion.o
	g++ gfx.o Coordenada.o Asteroide.o animacion.o -o animacion -lX11
animacion.o: animacion.cpp
	g++ animacion.cpp -c -Wall
Asteroide.o: Asteroide.cpp
	g++ Asteroide.cpp -c  -Wall
Coordenada.o: Coordenada.cpp
	g++ Coordenada.cpp -c  -Wall
gfx.o: gfx.c
	gcc gfx.c -c -Wall
clear:
	rm gfx.o Coordenada.o Asteroide.o animacion.o animacion