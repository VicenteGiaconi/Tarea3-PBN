#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <sstream>

#include "Juego.h"

#include "Mapa.h"

#include "Personaje.h"

void Juego::jugar() {

    // apertura de archivos
    ifstream entrada;
    entrada.open("soldados.txt");

    list<string> lista_completa;
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
    Mapa mapa(Ancho, Alto);

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

        Posicion pos(x,y);
        Personaje p(nombre, vida, ataque, velocidad, pos);
        cout<<p.name <<endl;
        
        /*
        Posicion posicion(X, Y);
        Personaje *punteroAp;
        Personaje p(Nombre, Vida, Ataque, Velocidad, posicion);
        punteroAp = &p;
        mapa.agregarPersonaje(punteroAp);
    
        */
 
    }




    entrada.close();
}




    /*
    // para que sirben
    list<string> lista1;
    list<string> lista2;



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
*/