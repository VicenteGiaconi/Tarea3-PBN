#pragma once

#include <string>
#include <vector>

#include "Personaje.h"

class Mapa {
public:
    int broad;
    int high;
    std::vector <std::vector <Personaje*>> matrix;

    Mapa(int, int);
    void agregarPersonaje(Personaje *);
    void eliminaPersonaje(Personaje *);
};