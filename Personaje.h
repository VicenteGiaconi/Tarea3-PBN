#pragma once
#include <string>
#include "Posicion.h"

using namespace std;

class Personaje {
public:                                             // despues privado
    string name;
    int health;
    int attack;
    int velocity;
    int army;
    int x;
    int y;
                                                    // despues publico
    int ataque();
    void recibirAtaque(Personaje *);
    void moverse(int, int);
    Personaje(string name , int health, int attack, int velocity,int army, Posicion place);
    ~Personaje();
};