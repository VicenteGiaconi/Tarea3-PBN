//LISTO
#include "Mapa.h"
#include "Posicion.h"

Mapa::Mapa(int Broad, int High){
    broad = Broad; // ancho
    high = High;   // largo
    Posicion pos (0,0);
    Personaje *Vacio = new Personaje("",0,0,0,0,pos);
    vector < Personaje*> v;
    for(int i = 0; i < high; i++){
        for (int a1 = 0; a1 < Broad; a1++){
           v.push_back(Vacio);
        }
        matrix.push_back(v);
    }
}

void Mapa::agregarPersonaje(Personaje *person){
    matrix[person->y][person->x] = person;
}

void Mapa::eliminaPersonaje(Personaje *person) {
    matrix[person->y][person->x] = Vacio;
}

Mapa::~Mapa() {
    delete Vacio;
    for (int i = 0; i < high; i++) {
        for (int j = 0; j < broad; j++) {
            delete matrix[i][j];
        }
    }
}

/*
    // mustra el tablero recien hecho
    for(int l1 = 0; l1 < high; l1++){
        for (int a1 = 0; a1 < broad; a1++){
            cout<< matrix[l1][a1].name <<" ";
        }
    cout <<endl;
    }
    cout <<endl;
    cout <<endl;
    cout <<endl;
*/


