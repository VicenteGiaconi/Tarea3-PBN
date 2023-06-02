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
    int count_e; // va ente 1 y 2 y es el encargado de ver a que equipo le toca
    int c_eq1;      // va recorriendo el equipo 1 para ver quien sigeue en  el turno
    int c_eq2;      // va recorriendo el equipo 2 para ver quien sigue en el turno
    int turno;
    void jugar();
    void chequearGanador();
    int calcularTurno();
    void mostrarMapa();
    void combate(Personaje *, Personaje *);
};