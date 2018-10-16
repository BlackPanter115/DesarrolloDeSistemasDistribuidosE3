//
// Created by sonia on 14/10/18.
//

#ifndef COORDENADA_H_
#define COORDENADA_H_


class Coordenada {
    private:
        char x;
        char y;

    public:
        Coordenada(char = 0, char = 0);
        char obtenerX();
        char obtenerY();
        void guardarX(char);
        void guardarY(char);
    };


#endif //PROYECTO3_COORDENADA_H
