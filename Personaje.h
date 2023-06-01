#pragma once

#include "Posicion.h"

#include <string>

class Personaje: public Posicion{
public:
    std::string name;
    int health;
    int attack;
    int velocity;
    int army;

    int ataque();
    void recibirAtaque(Personaje *);
    void moverse(int, int);
    Personaje(std::string name , int health, int attack, int velocity,int army, int x, int y);
    ~Personaje();
};