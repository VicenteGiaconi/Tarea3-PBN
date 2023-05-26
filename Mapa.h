
#define MAPA_H

#include "Personaje.h"

class Mapa
{
private:
    int ancho;
    int alto;
public:
    Mapa(int, int);                         // contructor 
    void agregarPersonaje(Personaje *);
    void eliminaPersonaje(Personaje *);
 
};
#endif 
