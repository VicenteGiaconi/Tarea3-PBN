#include <iostream>
#include "Mapa.h"

using namespace std;

void Mapa::crearMapa() {
    // Crea el mapa
}

void Mapa::agregarPersonaje() {
    // Crea un personnaje
}

void Mapa::eliminaPersonaje() {
    //Elimina un personaje
}

Mapa::Mapa(int Ancho, int Alto) {
    ancho = Ancho;
    alto = Alto;
    cout << "Se creó un mapa de ancho " << ancho << " y alto " << alto << endl;
}