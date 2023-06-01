#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "Juego.h"
#include "Mapa.h"

void Juego::jugar() {

    // apertura de archivos
    ifstream entrada;
    entrada.open("soldados.txt");

    vector<string> lista_completa;
    string linea;
    // de archivo a lista

    while (getline(entrada, linea)) {
        lista_completa.push_back(linea);
    }
    // contador del archivo
    auto iArc = lista_completa.begin();
    // coordenadas 
    string coordenadas = *iArc;
    // preparacio de las cordenadas
    istringstream iss(coordenadas);
    int Ancho, Alto;
    char delimiter = ',';
    string token;
    if (getline(iss, token, delimiter)) {
    Ancho = stoi(token);
    }
    if (getline(iss, token)) {
        Alto = stoi(token);
    }
    mapa = new Mapa(Ancho, Alto);

    for (int e = 1; e <= 2; e++){

        // lectura del ejercito 1
        advance(iArc, 1); 
        int n_soldados1 =  stoi(*iArc);
        // se avansa la cantidad de soldados que tiene el archivo en el ejercito 1

        // for que guarde a cada soldado en su lugar
        for (int i = 0; i < n_soldados1; i++){
            // variables de punteros del archivo
            advance(iArc, 1);
            stringstream linea(*iArc);
            // variables de para punteros de linea 
            char delimiter = ',';
            string token;
            // variables aux de las caracteristicas
            string nombre;
            int vida;
            int ataque;
            int velocidad;
            int x;
            int y;

            if (getline(linea, token, delimiter)) {
                nombre = token;
            }
            if (getline(linea, token, delimiter)) {
                vida = stoi(token);
            }
            if (getline(linea, token, delimiter)) {
                ataque = stoi(token);
            }
            if (getline(linea, token, delimiter)) {
                velocidad = stoi(token);
            }
            if (getline(linea, token, delimiter)) {
                x = stoi(token);
            }
            if (getline(linea, token, delimiter)) {
                y = stoi(token);
            }
            Personaje *p = new Personaje(nombre, vida, ataque, velocidad, e, x, y);
            mapa->agregarPersonaje(p);

        }
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

    // mustra el tablero recien hecho
    for(int l1 = 0; l1 < mapa->high; l1++){
        for (int a1 = 0; a1 < mapa->broad; a1++){
            cout<< mapa->matrix[l1][a1]->name <<" ";
        }
    cout <<endl;
    }
    cout <<endl;
    cout <<endl;
    cout <<endl;
    // Muestra en consola el mapa del juego con sus personajes
}

void Juego::combate(Personaje *P1, Personaje *P2) {
    // Simula la pelea entre 2 personajes
}
