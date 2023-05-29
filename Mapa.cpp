#include <iostream>
#include <vector>
#include "Mapa.h"
#include "Personaje.h"



Mapa::Mapa(int Broad, int High){
    broad = Broad; // ancho
    high = High;   // largo
    Personaje Vacio ("vacio",0,0,0,0,0);
    vector < Personaje > v;
    for(int i = 0; i < high; i++){
        for (int a1 = 0; a1 < Broad; a1++){
           v.push_back(Vacio);
        }
        matrix.push_back(v);
    }


    
  


    // mustra el tablero recien hecho
    for(int l1 = 0; l1 < High; l1++){
        for (int a1 = 0; a1 < Broad; a1++){
            cout<< matrix[l1][a1].name <<" ";
        }
    cout <<endl;
    }




    cout << "Se creó un mapa de ancho " << broad << " y alto " << high << endl;
}

void Mapa::agregarPersonaje(Personaje *personaje) {
    cout << "El personaje " << personaje << " se unió al mapa" << endl;
}

void Mapa::eliminaPersonaje(Personaje *personaje) {
    cout << "El personaje " << personaje << " se eliminó del mapa" << endl;
}

