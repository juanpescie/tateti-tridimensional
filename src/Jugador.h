#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <string>

class Jugador{
private:
	std::string nombre;
	int numeroDeJugador;

public:
	Jugador(std::string nombre, int identificacion);
	std::string obtenerNombre();
	int obtenerNumeroDeJugador();
};


#endif /* JUGADOR_H_ */
