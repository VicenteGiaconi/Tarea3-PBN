#pragma once

class Posicion {
private:
    int x;
    int y;
public:                            // public despues
    Posicion(int, int);
    int getX();
    int getY();
    void set(int, int);
};