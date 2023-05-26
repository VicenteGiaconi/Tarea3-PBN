#include "Posicion.h"

Posicion::Posicion(int X, int Y){
    x = X;
    y = Y;
}

int Posicion::getX() {
    return x;
}

int Posicion::getY() {
    return y;
}

void Posicion::set(int X, int Y) {
    x = X;
    y = Y;
}
