//LISTO
#pragma once

#include <vector>
#include <iostream>
#include "Personaje.h"

class Mapa{
public:                                     // despues pribado
    int broad;
    int high;
    vector < vector < Personaje >> matrix;
                                             // despues publico
    Mapa(int, int);                         // contructor 
    void agregarPersonaje(Personaje);
    void eliminaPersonaje(Personaje);
 
};