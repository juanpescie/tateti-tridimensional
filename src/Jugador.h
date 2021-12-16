#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "Lista.h"
#include <string>

class Jugador{
private:
	std::string nombre;
	char ficha;
	int numeroDeCartasActual;
	int cantidadDePartidasGanadas;
	int cantidadDeCartasDisponibles;

public:
	// pre: atributos validos, y no vacios, ficha disitnto de espacio
	// post: una instancia de jugador con los atributos que se le pasan por parametros, con un nombre, y un identificador de ficha para el tablero 
	Jugador(std::string nombre, char ficha);
	// pre: ninguna 
	// post: devuelve el atributo nojmbre del jugador
	std::string obtenerNombre();
	// pre: ninguna
	// post: devuelve la cantidad de juegos que gano ese juagdor
	int obtenerCantidadDePartidasGanadas();
	// pre ninguna
	// post: suma 1 a la cantidad de cartas disponibles para el jugador 
	void agregarCarta();
	// pre: ninguna
	// post: devuelve el caracter que tiene como identificador ese jugador
	char obtenerFicha();
	// pre: el jugador gano la gano la partida
	// post: el jugador suma 1 en su atributo cantidadDePartidasGanadas
	void ganoLaPartida();
};

#endif /* JUGADOR_H_ */
