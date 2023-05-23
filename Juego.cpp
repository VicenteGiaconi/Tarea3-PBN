#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <sstream>
#include "Juego.h"
#include "Mapa.h"

void Juego::jugar() {
    ifstream entrada;

    entrada.open("soldados.txt");

    list<string> lista_completa;
    list<string> lista1;
    list<string> lista2;
    string linea;

    while (getline(entrada, linea)) {
        lista_completa.push_back(linea);
    }

    string primera_linea = lista_completa.front();
    lista_completa.pop_front();

    istringstream iss(primera_linea);
    int Ancho, Alto;
    char delimiter = ',';
    string token;
    if (getline(iss, token, delimiter)) {
    Ancho = stoi(token);
    }

    if (getline(iss, token)) {
        Alto = stoi(token);
    }

    Mapa mapa(Ancho, Alto);

    list<string>::iterator itMitad = lista_completa.begin();
    advance(itMitad, lista_completa.size()/2);

    lista1 = list<string>(lista_completa.begin(), itMitad);
    if (!lista1.empty()) {
        string primera_linea = lista1.front();
        lista1.pop_front();
    }

    cout << "\nEjercito 1: " << endl;
    for (const auto& elemento : lista1) {
        istringstream iss(elemento);
        string Nombre;
        int Vida;
        int Ataque;
        int Velocidad;
        int X;
        int Y;

        char delimiter = ',';
        string token;
        if (getline(iss, token, delimiter)) {
            Nombre = token;
        }
        if (getline(iss, token, delimiter)) {
            Vida = stoi(token);
        }
        if (getline(iss, token, delimiter)) {
            Ataque = stoi(token);
        }
        if (getline(iss, token, delimiter)) {
            Velocidad = stoi(token);
        }
        if (getline(iss, token, delimiter)) {
            X = stoi(token);
        }
        if (getline(iss, token, delimiter)) {
            Y = stoi(token);
        }

        Posicion posicion(X, Y);
        Personaje *punteroAp;
        Personaje p(Nombre, Vida, Ataque, Velocidad, posicion);
        punteroAp = &p;
        mapa.agregarPersonaje(punteroAp);
    }

    lista2 = list<string>(itMitad, lista_completa.end());
    if (!lista2.empty()) {
        string primera_linea = lista2.front();
        lista2.pop_front();
    }

    cout << "\nEjercito 2: " << endl;
    for (const auto& elemento : lista2) {
        istringstream iss(elemento);
        string Nombre;
        int Vida;
        int Ataque;
        int Velocidad;
        int X;
        int Y;

        char delimiter = ',';
        string token;
        if (getline(iss, token, delimiter)) {
            Nombre = token;
        }
        if (getline(iss, token, delimiter)) {
            Vida = stoi(token);
        }
        if (getline(iss, token, delimiter)) {
            Ataque = stoi(token);
        }
        if (getline(iss, token, delimiter)) {
            Velocidad = stoi(token);
        }
        if (getline(iss, token, delimiter)) {
            X = stoi(token);
        }
        if (getline(iss, token, delimiter)) {
            Y = stoi(token);
        }

        Personaje *punteroAp;
        Posicion posicion(X, Y);
        Personaje p(Nombre, Vida, Ataque, Velocidad, posicion);
        punteroAp = &p;
        mapa.agregarPersonaje(punteroAp);
    }

    entrada.close();
}

void Juego::chequearGanador() {
    // Chequea si ha ganado uno de los ejercitos
}

int Juego::calcularTurno() {
    // Retorna el indice del personaje que debe jugar
    return 0;
}

void Juego::mostrarMapa() {
    // Muestra en consola el mapa del juego con sus personajes
}

void Juego::combate(Personaje *P1, Personaje *P2) {
    // Simula la pelea entre 2 personajes
}