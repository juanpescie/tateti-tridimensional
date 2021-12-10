#ifndef TATETI_H_
#define TATETI_H_

#include "Lista.h"
#include "Cola.h"
#include "Tablero.h"
#include "Jugador.h"
//#include "Carta.h"

class TATETI{
private:
	int cantidadDeFichasPorJugador;
	Tablero *tablero;
	int cantidadDeJugadores;
	Cola<Jugador*> *jugadores;
	//Cola<Carta*> *cartas;

public:
	TATETI();
	void insertarFicha(int alto, int ancho, int profundidad);
	void imprimirTableros();
	void iniciarJuego();
	void jugarPartida();
	void mostrarScore();
	~TATETI();

private:
	void mostrarBienvenida();
	void pedirDimensionesDelTablero();
	void inicializarJugadores();
	int getCantidadDeFichasPorJugador();
	//void crearCartas();
	bool validarCoordenadas(int columna, int fila, int profundidad);
	bool insertarFichas();
	void moverFichas();
	bool pedirDireccionAMover(int columna, int fila, int profundidad);
};
#endif /* TATETI_H_ */
