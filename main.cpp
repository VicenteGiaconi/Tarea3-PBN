#include <iostream>
#include "Juego.h"

using namespace std;

int main(int argc, char **argv) {

    Juego juego;
    juego.jugar();
    juego.mostrarMapa();
    int counter = 0;
    while (counter < juego.n_soldados1) { // Da una pura vuelta a las listas
        juego.calcularTurno();
        counter++;
    }

    return 0;
}
