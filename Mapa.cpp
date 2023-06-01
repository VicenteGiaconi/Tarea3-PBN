#include <iostream>

#include  "Mapa.h"

Mapa::Mapa(int Broad, int High) {
    broad = Broad; // ancho
    high = High;   // largo
    Personaje *Vacio = new Personaje(".....",0,0,0,0,0,0);
    std::vector <Personaje*> v;
    for(int i = 0; i < high; i++){
        for (int a1 = 0; a1 < broad; a1++){
           v.push_back(Vacio);
        }
        matrix.push_back(v);
    }
}

void Mapa::agregarPersonaje(Personaje *person) {
    matrix[person->getY()][person->getX()] = person;

    // mustra el tablero recien hecho
    for(int l1 = 0; l1 < high; l1++){
        for (int a1 = 0; a1 < broad; a1++){
            std::cout<< matrix[l1][a1]->name <<" ";
        }
    std::cout << std::endl;
    }       
    std::cout <<std::endl;
    std::cout <<std::endl;
    std::cout <<std::endl;
}

void Mapa::eliminaPersonaje(Personaje *person) {
    Personaje *Vacio = new Personaje(".....",0,0,0,0,0,0);
    matrix[person->getY()][person->getX()] = Vacio;
}

/*
    // mustra el tablero recien hecho
    for(int l1 = 0; l1 < high; l1++){
        for (int a1 = 0; a1 < broad; a1++){
            std::cout<< matrix[l1][a1]->name <<" ";
        }
    std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
*/