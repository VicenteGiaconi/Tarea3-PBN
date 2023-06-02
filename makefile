CC=g++
exe=p
flags=-Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self

$(exe): Mapa.o Posicion.o Personaje.o Juego.o main.o
	$(CC) Mapa.o Posicion.o Personaje.o Juego.o main.o -o $(exe) $(flags)

main.o: main.cpp
	$(CC) -c main.cpp -o main.o

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