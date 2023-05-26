#include <iostream>
#include "Mapa.h"



Mapa::Mapa(int Broad, int High) {
    broad = Broad;
    high = High;
    cout << "Se creó un mapa de ancho " << broad << " y alto " << high << endl;
}

void Mapa::agregarPersonaje(Personaje *personaje) {
    cout << "El personaje " << personaje << " se unió al mapa" << endl;
}

void Mapa::eliminaPersonaje(Personaje *personaje) {
    cout << "El personaje " << personaje << " se eliminó del mapa" << endl;
}

