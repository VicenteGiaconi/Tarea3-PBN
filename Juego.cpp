#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "Juego.h"
#include "Mapa.h"

using namespace std;

void Juego::jugar() {

    // apertura de archivos
    ifstream entrada;
    entrada.open("soldados_short.txt");

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
    // Se calculan las coordenadas centrales del mapa
    centro_X = Ancho/2;
    centro_Y = Alto/2;

    mapa = new Mapa(Ancho, Alto);

    for (int e = 1; e <= 2; e++){

        // lectura del ejercito 1
        advance(iArc, 1); 
        n_soldados1 =  stoi(*iArc);
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
            Personaje *p = new Personaje(nombre, vida, ataque, velocidad, e, pos);
            mapa->agregarPersonaje(p);
            if (p->army ==1) {
                ejercito1.push_back(p);
            } else if (p->army == 2) {
                ejercito2.push_back(p);
            }

        }
    }
    // Se calculan los promedios de velocidades de cada ejercito
    double svE1 = 0;
    double svE2 = 0;
    for (int i = 0; i < n_soldados1; i++) {
        svE1 = svE1 + ejercito1[i]->velocity;
        svE2 = svE2 + ejercito2[i]->velocity;
    }

    pvE1 = svE1/n_soldados1;
    pvE2 = svE2/n_soldados1;
    // se setean los contadores para poder jugar despues
    // se seta ell qequipo que va primero

    if (pvE1<pvE2){
        count_e = 2;
    } else{
        count_e = 1; // por defecto se mueve primero el primer ejercito si los dos promedios son iguales
    }
    c_eq1=0;      
    c_eq2=0;
    turno=0;     
    entrada.close();
}

void Juego::chequearGanador() {
    // Chequea si ha ganado uno de los ejercitos
}

int Juego::calcularTurno() {
    Personaje *moviendo; 
    turno++;

    // seleccion del personaje qe le corresponde moverse
    // aca se deviera de agregar si es que esta muerto o no el personaje
    if (count_e == 2){ // se mueve un personaje del ejercito 2
        moviendo = ejercito2[c_eq2];
    } else{
        moviendo = ejercito1[c_eq1];
    }

    // revison del cuadrante
    int cx = moviendo-> x;
    int cy = moviendo-> y;
    int origin = 0;
    Posicion mov1(cx,cy); // movimiento predeterminado 1
    Posicion mov2(cx,cy); // movimiento predeterminado 2
    Posicion mov3(cx,cy); // movimiento predeterminado 3

    if (cx == centro_X && cy ==centro_Y){         //personaje esta en el centro
        cout<<moviendo->name << " no se mueve " <<endl;
    } else if(cx < centro_X && cy < centro_Y){    // esta en el cuadrante 1
        cout<<moviendo->name << " cuadrante 1" <<endl;
        mov1.set(cx+1,cy+1);
        mov2.set(cx,cy+1);
        mov3.set(cx+1,cy);
    } else if (cx == centro_X && cy < centro_Y){  // esta en el cuadrante 2
        cout<<moviendo->name << " cuadrante 2" <<endl;
        mov1.set(cx,cy+1);
    } else if (cx >centro_X && cy < centro_Y){    // esta en el cuadrante 3
        cout<<moviendo->name << " cuadrante 3" <<endl;
        mov1.set(cx-1,cy+1);
        mov2.set(cx,cy+1);
        mov3.set(cx-1,cy);
    } else if (cx < centro_X && cy == centro_Y){  // esta en el cuadrante 4
        cout<<moviendo->name << " cuadrante 4" <<endl;
        mov1.set(cx+1,cy);
    } else if (cx >centro_X && cy == centro_Y){    // esta en el cuadrante 5
        cout<<moviendo->name << " cuadrante 5" <<endl;
        mov1.set(cx-1,cy);
    } else if (cx <centro_X && cy > centro_Y){    // esta en el cuadrante 6
        cout<<moviendo->name << " cuadrante 6" <<endl;
        mov1.set(cx+1,cy-1);
        mov2.set(cx,cy-1);
        mov3.set(cx+1,cy);
    } else if (cx ==centro_X && cy > centro_Y){    // esta en el cuadrante 7
        cout<<moviendo->name << " cuadrante 7" <<endl;
        mov1.set(cx,cy);
    } else if (cx >centro_X && cy > centro_Y){    // esta en el cuadrante 8
        cout<<moviendo->name << " cuadrante 8" <<endl;
        mov1.set(cx-1,cy-1);
        mov2.set(cx,cy-1);
        mov3.set(cx-1,cy);
    }
    cout<<mapa->matrix[cy][cx]->x<<endl;
    // verificando mov1
    int camino = 0; // verifica si el personaje ya se movio
    if (mapa->matrix[mov1.getY()][mov1.getX()]->army==0){
        cout<<"esta vacio se mueve para aca"<<endl;
        // cambiar la lista
        if (count_e == 1){ // esta en el ejercito 1
            ejercito2[c_eq2]->x = mov1.getX();
            ejercito2[c_eq2]->y = mov1.getY();
        }else{ //esta en el ejercito 2
            ejercito1[c_eq1]->x = mov1.getX();
            ejercito1[c_eq1]->y = mov1.getY();
        }
        // cambiar en el mapa

        camino = 1;
    } else if (mapa->matrix[mov1.getY()][mov1.getX()]->army==mapa->matrix[cy][cx]->army) {
        cout<<"son amigos"<<endl;
    } else {
        cout<<"son enemigos va al combate"<<endl;
        camino = 1;
    }

    // verificando mov2
    if (camino==0){
        if (mapa->matrix[mov2.getY()][mov2.getX()]->army==0){
            cout<<"esta vacio se mueve para aca"<<endl;
            if (count_e == 1){ // esta en el ejercito 1
                ejercito2[c_eq2]->x = mov2.getX();
                ejercito2[c_eq2]->y = mov2.getY();
            }else{ //esta en el ejercito 2
                ejercito1[c_eq1]->x = mov2.getX();
                ejercito1[c_eq1]->y = mov2.getY();
            }
            camino = 1;
        } else if (mapa->matrix[mov2.getY()][mov2.getX()]->army==mapa->matrix[cy][cx]->army) {
            cout<<"son amigos"<<endl;
        } else {
            cout<<"son enemigos va al combate"<<endl;
            camino = 1;
        }
    }

    // verificando mov3
    if (camino==0){
        if (mapa->matrix[mov3.getY()][mov3.getX()]->army==0){
            cout<<"esta vacio se mueve para aca"<<endl;
            if (count_e == 1){ // esta en el ejercito 1
                ejercito2[c_eq2]->x = mov3.getX();
                ejercito2[c_eq2]->y = mov3.getY();
            }else{ //esta en el ejercito 2
                ejercito1[c_eq1]->x = mov3.getX();
                ejercito1[c_eq1]->y = mov3.getY();
            }
            camino = 1;
        } else if (mapa->matrix[mov3.getY()][mov3.getX()]->army==mapa->matrix[cy][cx]->army) {
            cout<<"son amigos"<<endl;
        } else {
            cout<<"son enemigos va al combate"<<endl;
            camino = 1;
        }
    }

    // no se mueve el gerrero




    // eleccion de mov prioritario
    // testeo de lugar
    // mov 1 si es que hay un enemigo o esta vacia la posicion del mapa
    

    // los movimientos estan en orden de prioridad
    // si es que no hay nadie avansa y se queda en esa posicion
    // si es que hay un enemigo ataca y muere o sobrevive
    // si hay un amigo pasa a la seguna prioridad de moverse


    if (count_e == 2){ // se mueve un personaje del ejercito 2
        if (c_eq1<ejercito2.size()){
            c_eq2++;
        } else{
            c_eq2 = 0;
        }
        c_eq1++;
        count_e = 1; // para que despues le toque moverse al otro equipo
    } else{
        if (c_eq1<ejercito1.size()){
            c_eq1++;
        } else{
            c_eq1 = 0;
        }
        count_e = 2; // para que despues le toque moverse al otro equipo
    }


    return turno;
    



    // Aqui se define hacia que lado se mueve el personaje y como actua si choca con un enemigo o un amigo
    /*

    // Aqui se define hacia que lado se mueve el personaje y como actua si choca con un enemigo o un amigo

    if (pvE1 > pvE2) { // Si la velocidad promedio del ejercito1 es mayor a la del ejercito2, se mueven primero los del ejercito1
        if ((ejercito1[turno_actual]->x < centro_X) && (ejercito1[turno_actual]->y < centro_Y)) {
            if (mapa->matrix[ejercito1[turno_actual]->y+1][ejercito1[turno_actual]->x+1]->army !=1) {
                if (mapa->matrix[ejercito1[turno_actual]->y+1][ejercito1[turno_actual]->x+1]->army ==2) {
                    combate(ejercito1[turno_actual], mapa->matrix[ejercito1[turno_actual]->y+1][ejercito1[turno_actual]->x+1]);
                }
            }
        } else if ((ejercito1[turno_actual]->x < centro_X) && (ejercito1[turno_actual]->y > centro_Y)) {
            if (mapa->matrix[ejercito1[turno_actual]->y-1][ejercito1[turno_actual]->x+1]->army !=1) {
                if (mapa->matrix[ejercito1[turno_actual]->y-1][ejercito1[turno_actual]->x+1]->army ==2) {
                    combate(ejercito1[turno_actual], mapa->matrix[ejercito1[turno_actual]->y-1][ejercito1[turno_actual]->x+1]);
                }
            }
        } else if ((ejercito1[turno_actual]->x > centro_X) && (ejercito1[turno_actual]->y < centro_Y)) {
            if (mapa->matrix[ejercito1[turno_actual]->y+1][ejercito1[turno_actual]->x-1]->army !=1) {
                if (mapa->matrix[ejercito1[turno_actual]->y+1][ejercito1[turno_actual]->x-1]->army ==2) {
                    combate(ejercito1[turno_actual], mapa->matrix[ejercito1[turno_actual]->y+1][ejercito1[turno_actual]->x-1]);
                }
            }
        } else if ((ejercito1[turno_actual]->x > centro_X) && (ejercito1[turno_actual]->y > centro_Y)) {
            if (mapa->matrix[ejercito1[turno_actual]->y-1][ejercito1[turno_actual]->x-1]->army !=1) {
                if (mapa->matrix[ejercito1[turno_actual]->y-1][ejercito1[turno_actual]->x-1]->army ==2) {
                    combate(ejercito1[turno_actual], mapa->matrix[ejercito1[turno_actual]->y-1][ejercito1[turno_actual]->x-1]);
                }
            }
        } else if ((ejercito1[turno_actual]->x == centro_X) && (ejercito1[turno_actual]->y > centro_Y)) {
            if (mapa->matrix[ejercito1[turno_actual]->y-1][ejercito1[turno_actual]->x]->army !=1) {
                if (mapa->matrix[ejercito1[turno_actual]->y-1][ejercito1[turno_actual]->x]->army ==2) {
                    combate(ejercito1[turno_actual], mapa->matrix[ejercito1[turno_actual]->y-1][ejercito1[turno_actual]->x]);
                }
            }
        } else if ((ejercito1[turno_actual]->x == centro_X) && (ejercito1[turno_actual]->y < centro_Y)) {
            if (mapa->matrix[ejercito1[turno_actual]->y+1][ejercito1[turno_actual]->x]->army !=1) {
                if (mapa->matrix[ejercito1[turno_actual]->y+1][ejercito1[turno_actual]->x]->army ==2) {
                    combate(ejercito1[turno_actual], mapa->matrix[ejercito1[turno_actual]->y+1][ejercito1[turno_actual]->x]);
                }
            }
        } else if ((ejercito1[turno_actual]->x < centro_X) && (ejercito1[turno_actual]->y == centro_Y)) {
            if (mapa->matrix[ejercito1[turno_actual]->y][ejercito1[turno_actual]->x+1]->army !=1) {
                if (mapa->matrix[ejercito1[turno_actual]->y][ejercito1[turno_actual]->x+1]->army ==2) {
                    combate(ejercito1[turno_actual], mapa->matrix[ejercito1[turno_actual]->y][ejercito1[turno_actual]->x+1]);
                }
            }
        } else if ((ejercito1[turno_actual]->x > centro_X) && (ejercito1[turno_actual]->y == centro_Y)) {
            if (mapa->matrix[ejercito1[turno_actual]->y][ejercito1[turno_actual]->x-1]->army !=1) {
                if (mapa->matrix[ejercito1[turno_actual]->y][ejercito1[turno_actual]->x-1]->army ==2) {
                    combate(ejercito1[turno_actual], mapa->matrix[ejercito1[turno_actual]->y][ejercito1[turno_actual]->x-1]);
                }
            }
        }

        if ((ejercito2[turno_actual]->x < centro_X) && (ejercito2[turno_actual]->y < centro_Y)) {
            if (mapa->matrix[ejercito2[turno_actual]->y+1][ejercito2[turno_actual]->x+1]->army !=2) {
                if (mapa->matrix[ejercito2[turno_actual]->y+1][ejercito2[turno_actual]->x+1]->army ==1) {
                    combate(ejercito2[turno_actual], mapa->matrix[ejercito2[turno_actual]->y+1][ejercito2[turno_actual]->x+1]);
                }
            }
        } else if ((ejercito2[turno_actual]->x < centro_X) && (ejercito2[turno_actual]->y > centro_Y)) {
            if (mapa->matrix[ejercito2[turno_actual]->y-1][ejercito2[turno_actual]->x+1]->army !=2) {
                if (mapa->matrix[ejercito2[turno_actual]->y-1][ejercito2[turno_actual]->x+1]->army ==1) {
                    combate(ejercito2[turno_actual], mapa->matrix[ejercito2[turno_actual]->y-1][ejercito2[turno_actual]->x+1]);
                }
            }
        } else if ((ejercito2[turno_actual]->x > centro_X) && (ejercito2[turno_actual]->y < centro_Y)) {
            if (mapa->matrix[ejercito2[turno_actual]->y+1][ejercito2[turno_actual]->x-1]->army !=2) {
                if (mapa->matrix[ejercito2[turno_actual]->y+1][ejercito2[turno_actual]->x-1]->army ==1) {
                    combate(ejercito2[turno_actual], mapa->matrix[ejercito2[turno_actual]->y+1][ejercito2[turno_actual]->x-1]);
                }
            }
        } else if ((ejercito2[turno_actual]->x > centro_X) && (ejercito2[turno_actual]->y > centro_Y)) {
            if (mapa->matrix[ejercito2[turno_actual]->y-1][ejercito2[turno_actual]->x-1]->army !=2) {
                if (mapa->matrix[ejercito2[turno_actual]->y-1][ejercito2[turno_actual]->x-1]->army ==1) {
                    combate(ejercito2[turno_actual], mapa->matrix[ejercito2[turno_actual]->y-1][ejercito2[turno_actual]->x-1]);
                }
            }
        } else if ((ejercito2[turno_actual]->x == centro_X) && (ejercito2[turno_actual]->y > centro_Y)) {
            if (mapa->matrix[ejercito2[turno_actual]->y-1][ejercito2[turno_actual]->x]->army !=2) {
                if (mapa->matrix[ejercito2[turno_actual]->y-1][ejercito2[turno_actual]->x]->army ==1) {
                    combate(ejercito2[turno_actual], mapa->matrix[ejercito2[turno_actual]->y-1][ejercito2[turno_actual]->x]);
                }
            }
        } else if ((ejercito2[turno_actual]->x == centro_X) && (ejercito2[turno_actual]->y < centro_Y)) {
            if (mapa->matrix[ejercito2[turno_actual]->y+1][ejercito2[turno_actual]->x]->army !=2) {
                if (mapa->matrix[ejercito2[turno_actual]->y+1][ejercito2[turno_actual]->x]->army ==1) {
                    combate(ejercito2[turno_actual], mapa->matrix[ejercito2[turno_actual]->y+1][ejercito2[turno_actual]->x]);
                }
            }
        } else if ((ejercito2[turno_actual]->x < centro_X) && (ejercito2[turno_actual]->y == centro_Y)) {
            if (mapa->matrix[ejercito2[turno_actual]->y][ejercito2[turno_actual]->x+1]->army !=2) {
                if (mapa->matrix[ejercito2[turno_actual]->y][ejercito2[turno_actual]->x+1]->army ==1) {
                    combate(ejercito2[turno_actual], mapa->matrix[ejercito2[turno_actual]->y][ejercito2[turno_actual]->x+1]);
                }
            }
        } else if ((ejercito2[turno_actual]->x > centro_X) && (ejercito2[turno_actual]->y == centro_Y)) {
            if (mapa->matrix[ejercito2[turno_actual]->y][ejercito2[turno_actual]->x-1]->army !=2) {
                if (mapa->matrix[ejercito2[turno_actual]->y][ejercito2[turno_actual]->x-1]->army ==1) {
                    combate(ejercito2[turno_actual], mapa->matrix[ejercito2[turno_actual]->y][ejercito2[turno_actual]->x-1]);
                }
            }
        }
    } else { // Si la velocidad promedio del ejercito2 es mayor a la del ejercito1, se mueven primero los del ejercito2
        if ((ejercito2[turno_actual]->x < centro_X) && (ejercito2[turno_actual]->y < centro_Y)) {
            if (mapa->matrix[ejercito2[turno_actual]->y+1][ejercito2[turno_actual]->x+1]->army !=2) {
                if (mapa->matrix[ejercito2[turno_actual]->y+1][ejercito2[turno_actual]->x+1]->army ==1) {
                    combate(ejercito2[turno_actual], mapa->matrix[ejercito2[turno_actual]->y+1][ejercito2[turno_actual]->x+1]);
                }
            }
        } else if ((ejercito2[turno_actual]->x < centro_X) && (ejercito2[turno_actual]->y > centro_Y)) {
            if (mapa->matrix[ejercito2[turno_actual]->y-1][ejercito2[turno_actual]->x+1]->army !=2) {
                if (mapa->matrix[ejercito2[turno_actual]->y-1][ejercito2[turno_actual]->x+1]->army ==1) {
                    combate(ejercito2[turno_actual], mapa->matrix[ejercito2[turno_actual]->y-1][ejercito2[turno_actual]->x+1]);
                }
            }
        } else if ((ejercito2[turno_actual]->x > centro_X) && (ejercito2[turno_actual]->y < centro_Y)) {
            if (mapa->matrix[ejercito2[turno_actual]->y+1][ejercito2[turno_actual]->x-1]->army !=2) {
                if (mapa->matrix[ejercito2[turno_actual]->y+1][ejercito2[turno_actual]->x-1]->army ==1) {
                    combate(ejercito2[turno_actual], mapa->matrix[ejercito2[turno_actual]->y+1][ejercito2[turno_actual]->x-1]);
                }
            }
        } else if ((ejercito2[turno_actual]->x > centro_X) && (ejercito2[turno_actual]->y > centro_Y)) {
            if (mapa->matrix[ejercito2[turno_actual]->y-1][ejercito2[turno_actual]->x-1]->army !=2) {
                if (mapa->matrix[ejercito2[turno_actual]->y-1][ejercito2[turno_actual]->x-1]->army ==1) {
                    combate(ejercito2[turno_actual], mapa->matrix[ejercito2[turno_actual]->y-1][ejercito2[turno_actual]->x-1]);
                }
            }
        } else if ((ejercito2[turno_actual]->x == centro_X) && (ejercito2[turno_actual]->y > centro_Y)) {
            if (mapa->matrix[ejercito2[turno_actual]->y-1][ejercito2[turno_actual]->x]->army !=2) {
                if (mapa->matrix[ejercito2[turno_actual]->y-1][ejercito2[turno_actual]->x]->army ==1) {
                    combate(ejercito2[turno_actual], mapa->matrix[ejercito2[turno_actual]->y-1][ejercito2[turno_actual]->x]);
                }
            }
        } else if ((ejercito2[turno_actual]->x == centro_X) && (ejercito2[turno_actual]->y < centro_Y)) {
            if (mapa->matrix[ejercito2[turno_actual]->y+1][ejercito2[turno_actual]->x]->army !=2) {
                if (mapa->matrix[ejercito2[turno_actual]->y+1][ejercito2[turno_actual]->x]->army ==1) {
                    combate(ejercito2[turno_actual], mapa->matrix[ejercito2[turno_actual]->y+1][ejercito2[turno_actual]->x]);
                }
            }
        } else if ((ejercito2[turno_actual]->x < centro_X) && (ejercito2[turno_actual]->y == centro_Y)) {
            if (mapa->matrix[ejercito2[turno_actual]->y][ejercito2[turno_actual]->x+1]->army !=2) {
                if (mapa->matrix[ejercito2[turno_actual]->y][ejercito2[turno_actual]->x+1]->army ==1) {
                    combate(ejercito2[turno_actual], mapa->matrix[ejercito2[turno_actual]->y][ejercito2[turno_actual]->x+1]);
                }
            }
        } else if ((ejercito2[turno_actual]->x > centro_X) && (ejercito2[turno_actual]->y == centro_Y)) {
            if (mapa->matrix[ejercito2[turno_actual]->y][ejercito2[turno_actual]->x-1]->army !=2) {
                if (mapa->matrix[ejercito2[turno_actual]->y][ejercito2[turno_actual]->x-1]->army ==1) {
                    combate(ejercito2[turno_actual], mapa->matrix[ejercito2[turno_actual]->y][ejercito2[turno_actual]->x-1]);
                }
            }
        }

        if ((ejercito1[turno_actual]->x < centro_X) && (ejercito1[turno_actual]->y < centro_Y)) {
            if (mapa->matrix[ejercito1[turno_actual]->y+1][ejercito1[turno_actual]->x+1]->army !=1) {
                if (mapa->matrix[ejercito1[turno_actual]->y+1][ejercito1[turno_actual]->x+1]->army ==2) {
                    combate(ejercito1[turno_actual], mapa->matrix[ejercito1[turno_actual]->y+1][ejercito1[turno_actual]->x+1]);
                }
            }
        } else if ((ejercito1[turno_actual]->x < centro_X) && (ejercito1[turno_actual]->y > centro_Y)) {
            if (mapa->matrix[ejercito1[turno_actual]->y-1][ejercito1[turno_actual]->x+1]->army !=1) {
                if (mapa->matrix[ejercito1[turno_actual]->y-1][ejercito1[turno_actual]->x+1]->army ==2) {
                    combate(ejercito1[turno_actual], mapa->matrix[ejercito1[turno_actual]->y-1][ejercito1[turno_actual]->x+1]);
                }
            }
        } else if ((ejercito1[turno_actual]->x > centro_X) && (ejercito1[turno_actual]->y < centro_Y)) {
            if (mapa->matrix[ejercito1[turno_actual]->y+1][ejercito1[turno_actual]->x-1]->army !=1) {
                if (mapa->matrix[ejercito1[turno_actual]->y+1][ejercito1[turno_actual]->x-1]->army ==2) {
                    combate(ejercito1[turno_actual], mapa->matrix[ejercito1[turno_actual]->y+1][ejercito1[turno_actual]->x-1]);
                }
            }
        } else if ((ejercito1[turno_actual]->x > centro_X) && (ejercito1[turno_actual]->y > centro_Y)) {
            if (mapa->matrix[ejercito1[turno_actual]->y-1][ejercito1[turno_actual]->x-1]->army !=1) {
                if (mapa->matrix[ejercito1[turno_actual]->y-1][ejercito1[turno_actual]->x-1]->army ==2) {
                    combate(ejercito1[turno_actual], mapa->matrix[ejercito1[turno_actual]->y-1][ejercito1[turno_actual]->x-1]);
                }
            }
        } else if ((ejercito1[turno_actual]->x == centro_X) && (ejercito1[turno_actual]->y > centro_Y)) {
            if (mapa->matrix[ejercito1[turno_actual]->y-1][ejercito1[turno_actual]->x]->army !=1) {
                if (mapa->matrix[ejercito1[turno_actual]->y-1][ejercito1[turno_actual]->x]->army ==2) {
                    combate(ejercito1[turno_actual], mapa->matrix[ejercito1[turno_actual]->y-1][ejercito1[turno_actual]->x]);
                }
            }
        } else if ((ejercito1[turno_actual]->x == centro_X) && (ejercito1[turno_actual]->y < centro_Y)) {
            if (mapa->matrix[ejercito1[turno_actual]->y+1][ejercito1[turno_actual]->x]->army !=1) {
                if (mapa->matrix[ejercito1[turno_actual]->y+1][ejercito1[turno_actual]->x]->army ==2) {
                    combate(ejercito1[turno_actual], mapa->matrix[ejercito1[turno_actual]->y+1][ejercito1[turno_actual]->x]);
                }
            }
        } else if ((ejercito1[turno_actual]->x < centro_X) && (ejercito1[turno_actual]->y == centro_Y)) {
            if (mapa->matrix[ejercito1[turno_actual]->y][ejercito1[turno_actual]->x+1]->army !=1) {
                if (mapa->matrix[ejercito1[turno_actual]->y][ejercito1[turno_actual]->x+1]->army ==2) {
                    combate(ejercito1[turno_actual], mapa->matrix[ejercito1[turno_actual]->y][ejercito1[turno_actual]->x+1]);
                }
            }
        } else if ((ejercito1[turno_actual]->x > centro_X) && (ejercito1[turno_actual]->y == centro_Y)) {
            if (mapa->matrix[ejercito1[turno_actual]->y][ejercito1[turno_actual]->x-1]->army !=1) {
                if (mapa->matrix[ejercito1[turno_actual]->y][ejercito1[turno_actual]->x-1]->army ==2) {
                    combate(ejercito1[turno_actual], mapa->matrix[ejercito1[turno_actual]->y][ejercito1[turno_actual]->x-1]);
                }
            }
        }
    }

    if (turno_actual < n_soldados1-1) {
        turno_actual++;
    } else {
        turno_actual = 0;
    }
    return turno_actual;
    */

}

void Juego::mostrarMapa() {
    string interior = "     ";
    for (int a2 = 0; a2 < mapa->broad; a2++){
        cout<<"_______";
    }
    cout <<endl;

    for(int l1 = 0; l1 < mapa->high; l1++){
        for (int a1 = 0; a1 < mapa->broad; a1++){
            // desde aca esta el nombre seleccionado
            interior = "     ";
            int largo_nombre = mapa->matrix[l1][a1]->name.size();
            for (int i = 0; i<5;i++){
                if (i<largo_nombre){
                    interior[i] = mapa->matrix[l1][a1]->name[i];
                }
            }
            cout<<"|"<< interior<<"|";
        }
        cout <<endl;
        for (int a2 = 0; a2 < mapa->broad; a2++){
            interior = "_____";
            cout<<"|";
            for (int i2 = 0; i2<5 ;i2++){
                if (i2 == 2){
                    if (mapa->matrix[l1][a2]->army == 0){
                        cout<<"_";
                    } else {
                        cout<<mapa->matrix[l1][a2]->army;
                    }
                } else{
                    cout<<"_";
                }
            }

            cout<<"|";
        }
        cout <<endl;
    } 
}

void Juego::combate(Personaje *P1, Personaje *P2) {
    // Se inicia la pelea entre los dos personajes
    cout << "Comienza la pelea entre " << P1->name << P1->army << " y " << P2->name << P2->army << endl;
    if (P1->velocity != P2->velocity) { // Se comparan las velocidades
        if (P1->velocity > P2->velocity) { // Si tienen distintas velocidades, el con mayor velocidad parte
            cout << "La velocidad de " << P1->name << P1->army << " es " << P1->velocity << ", la de " << P2->name << P2->army << " es " << P2->velocity << ", parte " << P1->name << P1->army << endl; 
            while ((P1->health > 0) && (P2->health > 0)) {
                P2->recibirAtaque(P1);
                if (P2->health > 0) {
                    P1->recibirAtaque(P2);
                }
            }
        } else {
            cout << "La velocidad de " << P2->name << P2->army << " es " << P2->velocity << ", la de " << P1->name << P1->army << " es " << P1->velocity << ", parte " << P2->name << P2->army << endl;
            while ((P1->health > 0) && (P2->health > 0)) {
                P1->recibirAtaque(P2);
                if (P1->health > 0) {
                    P2->recibirAtaque(P1);
                }
            }
        }
    } else {
        if (P1->attack != P2->attack) { // Si tienen la misma velocidad, se compara el ataque
            if (P1->attack > P2->attack) { // Si tienen distintos ataques, el con mayor ataque parte
                cout << "El ataque de " << P1->name << P1->army << " es " << P1->velocity << ", el de " << P2->name << P2->army << " es " << P2->velocity << ", parte " << P1->name << P1->army << endl; 
                while ((P1->health > 0) && (P2->health > 0)) {
                    P2->recibirAtaque(P1);
                    if (P2->health > 0) {
                        P1->recibirAtaque(P2);
                    }
                }
            } else {
                cout << "El ataque de " << P2->name << P2->army << " es " << P2->velocity << ", el de " << P1->name << P1->army << " es " << P1->velocity << ", parte " << P2->name << P2->army << endl;
                while ((P1->health > 0) && (P2->health > 0)) {
                    P1->recibirAtaque(P2);
                    if (P1->health > 0) {
                        P2->recibirAtaque(P1);
                    }
                }
            }
        } else {
            if (P1->health != P2->health) { // Si tienen el mismo ataque, se comparan por salud
                if (P1->health > P2->health) { // Si tienen distinta salud, el con mayor salud parte
                    cout << "La salud de " << P1->name << P1->army << " es " << P1->velocity << ", la de " << P2->name << P2->army << " es " << P2->velocity << ", parte " << P1->name << P1->army << endl; 
                    while ((P1->health > 0) && (P2->health > 0)) {
                        P2->recibirAtaque(P1);
                        if (P2->health > 0) {
                            P1->recibirAtaque(P2);
                        }
                    }
                } else {
                    cout << "La salud de " << P2->name << P2->army << " es " << P2->velocity << ", la de " << P1->name << P1->army << " es " << P1->velocity << ", parte " << P2->name << P2->army << endl;
                    while ((P1->health > 0) && (P2->health > 0)) {
                        P1->recibirAtaque(P2);
                        if (P1->health > 0) {
                            P2->recibirAtaque(P1);
                        }
                    }
                }
            }
        }
    }
    // Finalia el combate, falta eliminar al perdedor de la matriz y reemplazarlo en el vector de su ejercito
    if (P1->health == 0) {
        if (P1->army == 1) {
            ejercito1[turno_actual] = mapa->Vacio;
        } else {
            ejercito2[turno_actual] = mapa->Vacio;
            cout << "Murio uno del equipo " << P1->army << endl;
        }
        int X = P2->x;
        int Y = P2->y;
        mapa->eliminaPersonaje(P1);
        cout << X << endl;
        cout << Y << endl;
        cout << "Combate finalizado, ha ganado " << P2->name << P2->army << endl;
        
    } else if (P2->health == 0) {
        if (P1->army == 1) {
            ejercito1[turno_actual] = mapa->Vacio;
        } else {
            ejercito2[turno_actual] = mapa->Vacio;
            cout << "Murio uno del equipo " << P2->army << endl;
        }

        int X = P2->x;
        int Y = P2->y;
        mapa->eliminaPersonaje(P2);
        cout << X << endl;
        cout << Y << endl;
        cout << "Combate finalizado, ha ganado " << P1->name << P1->army << endl;
        P1->moverse(X, Y);
    }
}
