#include <iostream>
#include "Juego.h"

using namespace std;

int main(int argc, char **argv) {

    Juego juego;
    juego.jugar();
    juego.calcularTurno();
    int counter = 0;
    while (counter < 44) { // Da una pura vuelta a las listas
        juego.mostrarMapa();
        juego.calcularTurno();
        counter++;
    }
    return 0;
}
