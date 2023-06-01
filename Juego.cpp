#include <iostream>
#include <fstream>
#include <sstream>

#include "Juego.h"

void Juego::jugar() {
    std::ifstream entrada;
    entrada.open("soldados_short.txt");
    std::string linea;
    std::string primera_linea;
    std::string cantidad_e1;
    std::string cantidad_e2;

    std::getline(entrada, primera_linea);       // Se guarda la primera linea en primera_linea
    
    std::istringstream iss(primera_linea);
    int Ancho, Alto;
    char delimiter = ',';
    std::string token;
    if (std::getline(iss, token, delimiter)) {
        Ancho = stoi(token);
    }
    if (getline(iss, token)) {
        Alto = stoi(token);
    }

    Mapa mapa(Ancho, Alto);
    
    
    std::getline(entrada, cantidad_e1);     // Se guarda la cantidad del ejercito1 en cantidad_e1

    Personaje *ejercito1[stoi(cantidad_e1)];

    for (int i = 0; i < stoi(cantidad_e1); i++) {       // Lee todos los personajes del segundo equipo
        std::getline(entrada, linea);       // Lee la linea y la guarda
        // objeto de tipo stringstream
        std::stringstream ss(linea);
        // variables de para punteros de linea 
        char delimiter = ',';
        std::string token;
        // variables aux de las caracteristicas
        std::string nombre;
        int vida;
        int ataque;
        int velocidad;
        int x;
        int y;

        if (std::getline(ss, token, delimiter)) {
                nombre = token;
            }
            if (getline(ss, token, delimiter)) {
                vida = stoi(token);
            }
            if (getline(ss, token, delimiter)) {
                ataque = stoi(token);
            }
            if (getline(ss, token, delimiter)) {
                velocidad = stoi(token);
            }
            if (getline(ss, token, delimiter)) {
                x = stoi(token);
            }
            if (getline(ss, token, delimiter)) {
                y = stoi(token);
            }
        Personaje *p = new Personaje(nombre, vida, ataque, velocidad, 1, x, y);
        ejercito1[i] = p;
        mapa.agregarPersonaje(p);
    }

    std::getline(entrada, cantidad_e2);

    Personaje *ejercito2[stoi(cantidad_e2)];

    for (int i = 0; i < stoi(cantidad_e2); i++) {       // Lee todos los personajes del segundo equipo
        std::getline(entrada, linea);       // Lee la linea y la guarda
        // objeto de tipo stringstream
        std::stringstream ss(linea);
        // variables de para punteros de linea 
        char delimiter = ',';
        std::string token;
        // variables aux de las caracteristicas
        std::string nombre;
        int vida;
        int ataque;
        int velocidad;
        int x;
        int y;

        if (std::getline(ss, token, delimiter)) {
                nombre = token;
            }
            if (getline(ss, token, delimiter)) {
                vida = stoi(token);
            }
            if (getline(ss, token, delimiter)) {
                ataque = stoi(token);
            }
            if (getline(ss, token, delimiter)) {
                velocidad = stoi(token);
            }
            if (getline(ss, token, delimiter)) {
                x = stoi(token);
            }
            if (getline(ss, token, delimiter)) {
                y = stoi(token);
            }
        Personaje *p = new Personaje(nombre, vida, ataque, velocidad, 2, x, y);
        ejercito2[i] = p;
        mapa.agregarPersonaje(p);
    }
    entrada.close();
}

void Juego::chequearGanador() {

}

int Juego::calcularTurno() {
    return 0;
}

void Juego::mostrarMapa() {
}

void Juego::combate(Personaje *, Personaje *) {

}