#ifndef JUEGO_H
#define JUEGO_H
#include "Personaje.h"

class Juego
{
public:
    void jugar();
    void chequearGanador();
    int calcularTurno();
    void mostrarMapa();
    void combate(Personaje *, Personaje *);
};
#endif 