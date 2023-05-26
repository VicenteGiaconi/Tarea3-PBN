#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <string>
#include "Posicion.h"

using namespace std;

class Personaje
{
public:                                             // despues pribado
    string name;
    int health;
    int attack;
    int velocity;
    Posicion position;
                                                    // despues publico
    int ataque();
    void recibirAtaque();
    void moverse(int, int);
    Personaje(string, int, int, int, Posicion);
    ~Personaje();
};
#endif 