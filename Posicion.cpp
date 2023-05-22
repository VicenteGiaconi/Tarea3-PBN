#include "Posicion.h"

int Posicion::getX() {
    return X;
}

int Posicion::getY() {
    return Y;
}

void Posicion::set(int x, int y) {
    X = x;
    Y = y;
}

Posicion::Posicion(int x, int y)
{
    X = x;
    Y = y;
}