#include <iostream>
#include <string>
#include "Personaje.h"

using namespace std;

Personaje::Personaje(string Name, int Health, int Attack, int Velocity,int Army, Posicion place) {  // arrmy es para poder diferenciar de que ejercito es
    name = Name;
    health = Health;
    attack = Attack;
    velocity = Velocity;
    army = Army;
    x = place.getX();
    y = place.getY();
}

int Personaje::ataque() {
    return attack;
}

void Personaje::recibirAtaque(Personaje *enemigo) {
    health = health -enemigo->attack;
    if (health < 0) {
        health = 0;
    }
        cout << enemigo->name << enemigo->army << " inflinje " << enemigo->attack << " de daño a " << name  << army << ", vida restante :" << health << endl;
}

void Personaje::moverse(int X, int Y) {
    cout << name << " se mueve  de (" << x << "," << y << ") a (" << X << "," << Y << ")" << endl;
    
}

Personaje::~Personaje() {
}

