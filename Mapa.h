//LISTO
#pragma once

#include <vector>
#include <iostream>
#include "Personaje.h"

class Mapa{
public:                                     // despues pribado
    int broad;
    int high;
    Personaje *Vacio;
    vector < vector < Personaje*>> matrix;
                                             // despues publico
    Mapa(int, int);                         // contructor
    ~Mapa();
    void agregarPersonaje(Personaje *);
    void eliminaPersonaje(Personaje *);
 
};