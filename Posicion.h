#ifndef POSICION_H
#define POSICION_H

class Posicion
{
private:
    int X;
    int Y;
public:
    int getX();
    int getY();
    void set(int, int);
    Posicion(int, int);
};
#endif