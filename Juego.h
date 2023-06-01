#pragma once

#include "Mapa.h"

class Juego{
public:
    Mapa * mapa;
    Posicion * pos;
    void jugar();
    void chequearGanador();
    int calcularTurno();
    void mostrarMapa();
    void combate(Personaje *, Personaje *);
};