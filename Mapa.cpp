#include <iostream>
#include "Mapa.h"



Mapa::Mapa(int Ancho, int Alto) {
    ancho = Ancho;
    alto = Alto;
    cout << "Se creó un mapa de ancho " << ancho << " y alto " << alto << endl;
}

void Mapa::agregarPersonaje(Personaje *personaje) {
    cout << "El personaje " << personaje << " se unió al mapa" << endl;
}

void Mapa::eliminaPersonaje(Personaje *personaje) {
    cout << "El personaje " << personaje << " se eliminó del mapa" << endl;
}

