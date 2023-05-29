//LISTO
#include "Mapa.h"

Mapa::Mapa(int Broad, int High){
    broad = Broad; // ancho
    high = High;   // largo
    Personaje Vacio (".....",0,0,0,0,0,0);
    vector < Personaje > v;
    for(int i = 0; i < high; i++){
        for (int a1 = 0; a1 < Broad; a1++){
           v.push_back(Vacio);
        }
        matrix.push_back(v);
    }
}

void Mapa::agregarPersonaje(Personaje person){
    matrix[person.getY()][person.getX()] = person;
}

void Mapa::eliminaPersonaje(Personaje person) {
    Personaje Vacio (".....",0,0,0,0,0,0);
    matrix[person.getY()][person.getX()] = Vacio;
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


