CC=g++
flags=-Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self
exe=p

$(exe): Posicion.o Personaje.o Mapa.o Juego.o main.o
	$(CC) $(flags) Posicion.o Personaje.o Mapa.o Juego.o main.o -o $(exe)

main.o: main.cpp
	$(CC) -c main.cpp -o main.o

Juego.o: Juego.cpp
	$(CC) -c Juego.cpp -o Juego.o

Mapa.o: Mapa.cpp
	$(CC) -c Mapa.cpp -o Mapa.o

Personaje.o: Personaje.cpp
	$(CC) -c Personaje.cpp -o Personaje.o

Posicion.o: Posicion.cpp
	$(CC) -c Posicion.cpp -o Posicion.o

all: $(exe) run clean

run:
	./$(exe)

clean:
	rm $(exe) *.o