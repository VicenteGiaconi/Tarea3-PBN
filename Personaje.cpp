#include "Personaje.h"
#include <string>

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
}