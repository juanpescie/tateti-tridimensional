#ifndef TATETI_H_
#define TATETI_H_

#include "Lista.h"
#include "Cola.h"
#include "Tablero.h"
#include "Jugador.h"

class Carta{
private:
	int numero;
	std::string descripcion;

public:
	Carta(int numero);
	std::string obtenerDescripcion();
	void utilizarCarta(Tablero *tablero, Cola<Jugador*> *jugadores);

private:
	void jugadorPierdeUnTurno(Tablero *tablero, Cola<Jugador*> *jugadores);
	void bloquearFicha(Tablero *tablero, Cola<Jugador*> *jugadores);
	void anularCasillero(Tablero *tablero, Cola<Jugador*> *jugadores);
	void moverFicha(Tablero *tablero, Cola<Jugador*> *jugadores);
};

class TATETI{
private:
	int cantidadDeFichasPorJugador;
	Tablero *tablero;
	int cantidadDeJugadores;
	Cola<Jugador*> *jugadores;
	std::string nombreDelArchivoBMP;
	Cola<Carta*> *cartas;
	Cola<Lista<Carta*>*> *cartasJugadores;

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
	void pedirNombreDelArchivoBMP();
	int getCantidadDeFichasPorJugador();
	void crearCartas();
	bool validarCoordenadas(int columna, int fila, int profundidad);
	bool insertarFichas();
	void moverFichas();
	bool pedirDireccionAMover(int columna, int fila, int profundidad);
	void repartirCartas();
	bool utilizarCarta(Lista<Carta*> *cartas);

	//funciones de prueba
	void mostrarCartas(Lista<Carta*> *cartas);
};
#endif /* TATETI_H_ */