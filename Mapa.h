
#define MAPA_H

#include "Personaje.h"

class Mapa
{
public:                                     // despues pribado
    int broad;
    int high;
                                            // despues publico
    Mapa(int, int);                         // contructor 
    void agregarPersonaje(Personaje *);
    void eliminaPersonaje(Personaje *);
 
};
#endif 
