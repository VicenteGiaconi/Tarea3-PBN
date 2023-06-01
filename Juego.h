#pragma once

#include "Personaje.h"
#include "Mapa.h"

class Juego {
public:
    Mapa *mapa;
    void jugar();
    void chequearGanador();
    int calcularTurno();
    void mostrarMapa();
    void combate(Personaje *, Personaje *);
};