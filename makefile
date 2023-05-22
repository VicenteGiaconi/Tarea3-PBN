CC=g++
exe=p

$(exe): Juego.o Mapa.o Personaje.o Posicion.o main.o
	$(CC) Juego.o Mapa.o Personaje.o Posicion.o main.o -o $(exe)

Posicion.o: Posicion.cpp
	$(CC) -c Posicion.cpp -o Posicion.o

Personaje.o: Personaje.cpp
	$(CC) -c Personaje.cpp -o Personaje.o
	
Mapa.o: Mapa.cpp
	$(CC) -c Mapa.cpp -o Mapa.o

Juego.o: Juego.cpp
	$(CC) -c Juego.cpp -o Juego.o

run:
	./$(exe)

all: $(exe) run clean

clean:
	rm *.o $(exe)