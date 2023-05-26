#include <iostream>
#include <string>
#include "Personaje.h"
#include "Posicion.h"

using namespace std;


Personaje::Personaje(string Name, int Health, int Attack, int Velocity , Posicion Pos){
    name = Name;
    health = Health;
    attack = Attack;
    velocity = Velocity;
    position = Pos; 

    //cout << "Se creó a " << name  << " en las coordenadas (" << position.getX() << "," << position.getY() << ")" << endl;
}

int Personaje::ataque() {
    return attack;
}

void Personaje::recibirAtaque() {

}

void Personaje::moverse(int X, int Y) {
    // Se mueve a las coordenadas nuevas
}

Personaje::~Personaje() {
    cout << "Se eliminó " << name  << endl;
}