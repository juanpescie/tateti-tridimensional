#ifndef CARTA_H_
#define CARTA_H_

#include <string>
#include "Cola.h"
#include "Tablero.h"
#include "Jugador.h"

std::string descripcionCartas[6]{
	"Hacer perder turno a un jugador",
	"Bloquear una ficha de otro jugador",
	"Anular casillero",
	"Volver atras una jugada",
	"Mover ficha",
	" ",
};


class Carta{
private:
	int numero;
	std::string descripcion;

public:
	Carta(int numero);
	std::string obtenerDescripcion();

/*private:
	void jugadorPierdeUnTurno(Tablero *tablero, Cola<Jugador*> *jugadores);
	void bloquearFicha(Tablero *tablero, Cola<Jugador*> *jugadores);
	void anularCasillero(Tablero *tablero, Cola<Jugador*> *jugadores);
	void moverFicha(Tablero *tablero, Cola<Jugador*> *jugadores);*/

};


#endif /* CARTA_H_ */
