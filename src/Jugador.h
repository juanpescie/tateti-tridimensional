#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "Lista.h"
#include <string>
//#include "Carta.h"

class Jugador{
private:
	std::string nombre;
	char ficha;
	int numeroDeCartasActual;
	int cantidadDePartidasGanadas;
	//Lista<Carta*> *cartas;

public:
	Jugador(std::string nombre, char ficha);
	std::string obtenerNombre();
	int obtenerNumeroDeJugador();
	int obtenerCantidadDePartidasGanadas();
	char obtenerFicha();
	//void agregarCarta(Carta *carta);
	//void mostrarCartas();
	void ganoLaPartida();
};

#endif /* JUGADOR_H_ */
