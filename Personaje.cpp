#include "Personaje.h"

#include <string>

Personaje::Personaje(std::string Name, int Health, int Attack, int Velocity,int Army, int X, int Y) : Posicion(X, Y){  // army es para poder diferenciar de que ejercito es
    name = Name;
    health = Health;
    attack = Attack;
    velocity = Velocity;
    army = Army;
}

int Personaje::ataque() {
    return attack;          // Retorna el ataque de cada personaje
}

void Personaje::recibirAtaque(Personaje *Enemigo) {
    health - Enemigo->attack;          //Toma el ataque del enemigo y se lo resta a la vida
}

void Personaje::moverse(int X, int Y) {
    // Lógica para moverse a las nuevas coordenadas X e Y
}

Personaje::~Personaje() {
}