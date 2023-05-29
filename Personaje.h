#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <string>
#include "Posicion.h"

using namespace std;

class Personaje : public Posicion{
public:                                             // despues privado
    string name;
    int health;
    int attack;
    int velocity;
    int army;


                                                    // despues publico
    int ataque();
    void recibirAtaque();
    void moverse(int, int);
    Personaje(string name , int health, int attack, int velocity,int army, int x, int y);
    ~Personaje();
};
#endif 