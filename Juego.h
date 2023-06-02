#pragma once

#include "Mapa.h"

class Juego{
public:
    Mapa * mapa;
    Posicion * pos;
    int turno_actual = 0; // Se usa en calcularTurno
    int n_soldados1;
    int centro_X; // Coordenadas centrales
    int centro_Y;
    double pvE1; // Promedio de velocidad del ejercito1
    double pvE2; // Promedio de velocidad del ejercito2
    vector <Personaje *> ejercito1;
    vector <Personaje *> ejercito2;
    void jugar();
    void chequearGanador();
    int calcularTurno();
    void mostrarMapa();
    void combate(Personaje *, Personaje *);
};