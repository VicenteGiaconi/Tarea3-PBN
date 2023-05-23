#include <iostream>
#include <string>
#include "Personaje.h"

using namespace std;

using namespace std;

int Personaje::ataque() {
    return vataque;
}

void Personaje::recibirAtaque() {

}

void Personaje::moverse(int x, int y) {
    // Se mueve a las coordenadas nuevas
}

Personaje::Personaje(string name, int health, int attack, int speed, Posicion posicion)
: vposicion(posicion) {
    vnombre = name;
    vvida = health;
    vataque = attack;
    vvelocidad = speed;
    cout << "Se creó a " << vnombre << "en las coordenadas (" << vposicion.getX() << "," << vposicion.getY() << ")" << endl;
}
Personaje::~Personaje() {}