#ifndef MAPA_H
#define MAPA_H
#include "Personaje.h"

class Mapa
{
private:
    int ancho;
    int alto;

public:
    void crearMapa();
    void agregarPersonaje(Personaje *);
    void eliminaPersonaje(Personaje *);
    Mapa(int, int);
};
#endif