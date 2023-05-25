#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <string>
#include "Posicion.h"

using namespace std;

class Personaje
{
private:
    string vnombre;
    int vvida;
    int vataque;
    int vvelocidad;
    Posicion vposicion;
public:
    int ataque();
    void recibirAtaque();
    void moverse(int, int);
    Personaje(string, int, int, int, Posicion);
    ~Personaje();
};
#endif 