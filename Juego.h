#include "Personaje.h"

class Juego
{
public:
    void jugar();
    void chequearGanador();
    int calcularTurno();
    void motrarMapa();
    void combate(Personaje *, Personaje *);
};