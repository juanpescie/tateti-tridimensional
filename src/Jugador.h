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
	Jugador(std::string nombre, char ficha);
	std::string obtenerNombre();
	int obtenerNumeroDeJugador();
	int obtenerCantidadDePartidasGanadas();
	void agregarCarta();
	char obtenerFicha();
	void ganoLaPartida();
};

#endif /* JUGADOR_H_ */
