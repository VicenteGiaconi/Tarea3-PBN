#ifndef POSICION_H
#define POSICION_H
#include "Posicion.h"

class Posicion{
public:                      // private despues
    int x;
    int y;
                            // public despues
    Posicion(int, int);
    int getX();
    int getY();
    void set(int, int);
    
};
#endif


// no entiendo las cosas en morado
// unica clase con pribado por ahora por que tiene metodos para sacar los datos