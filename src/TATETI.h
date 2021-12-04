#ifndef TATETI_H_
#define TATETI_H_

#include "Lista.h"
#include "Cola.h"
#include "Tablero.h"
#include "Jugador.h"

class TATETI{
private:
	Tablero *tablero;
	int cantidadDeJugadores;
	Cola<Jugador*> *jugadores;

public:
	TATETI();
	void insertarFicha(int alto, int ancho, int profundidad);
	void imprimirTableros();
	void iniciarJuego();
	~TATETI();

private:
	void mostrarBienvenida();
	void pedirDimensionesDelTablero();
	void inicializarJugadores();
	void jugarPartida();
	bool validarCoordenadas(int columna, int fila, int profundidad);
	bool verificarGanador(char ficha); /*no implementada aun*/
};
#endif /* TATETI_H_ */