#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <string>
#include "Posicion.h"

using namespace std;

class Personaje {
public:                                             // despues pribado
    string name;
    int health;
    int attack;
    int velocity;
    int x;
    int y;

                                                    // despues publico
    int ataque();
    void recibirAtaque();
    void moverse(int, int);
    Personaje(string name , int health, int attack, int velocity, Posicion Place);
    ~Personaje();
};
#endif 