#include <iostream>
#include <string>
#include "Personaje.h"
#include "Posicion.h"

using namespace std;

Personaje::Personaje(string Name, int Health, int Attack, int Velocity,int Army, int X, int Y) : Posicion(X, Y){  // arrmy es para poder diferenciar de que ejercito es
    name = Name;
    health = Health;
    attack = Attack;
    velocity = Velocity;
    army = Army;
}

int Personaje::ataque() {
    return attack;
}

void Personaje::recibirAtaque() {
    // Lógica para recibir un ataque
}

void Personaje::moverse(int X, int Y) {
    // Lógica para moverse a las nuevas coordenadas X e Y
}

Personaje::~Personaje() {
}

