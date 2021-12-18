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
	// pre: numero positivo
	// post: devuelve una instancia de carta dentro de las opciones 
	Carta(int numero);
	// pre: ninguna
	// post: devuelve un string con la funcionalidad describiendo que hace la carta
	std::string obtenerDescripcion();
	// pre: recibe el tablero para aplicar la carta, y la cola de jugadores en caso de que la carta aplique a un jugador
	// post: dependiendo de la carta, aplica su funcionalidad en el juego
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
	int cantidadMaximaCartasPorJugador;
	Tablero *tablero;
	int cantidadDeJugadores;
	Cola<Jugador*> *jugadores;
	std::string nombreDelArchivoBMP;
	Cola<Carta*> *cartas;
	Cola<Lista<Carta*>*> *cartasJugadores;

public:
	// pre: ninguna
	// post: devuelve una instancia del juego TATETI, con un tablero nulo, y sin dimensiones, louego se le pide 
	TATETI();
	void insertarFicha(int alto, int ancho, int profundidad);
	// pre: ninguna
	// post: llama al metodo del tablero mostrarTableroPorCapas y muestra por pantalla las capas
	void imprimirTableros();
	// pre: ninguna
	// post: realiza una serie de inputs para inicializar los atributos de TATETTI
	// pregunta por la cantidad de jugadores, la cantidad de fichas de cada jugador, los nombres, sus identificadores(fichas)
	// el nombre del archivo bmp donde se vna a guardar los tableros
	void iniciarJuego();
	// pre: ninguna
	// post: juega la partida un turno y dibuja el tablero
	void jugarPartida();
	// pre: ninguna
	// post: muestra la cantidad de partidas ganadas de cada jugador por consola 
	void mostrarScore();
	~TATETI();

private:
	// pre: ninguna 
	// post: muestra el mensjae indicando la introduccion al juego 
	void mostrarBienvenida();
	// pre: ninguna
	// post: se crea un tablero con las dimensiones que se reicibieron por input
	void pedirDimensionesDelTablero();
	// pre: ninguna
	// post: se realiza ua serie de inputs para fijar el numero de jugadores, y los nombres e identificadores en el tablero de cada jugador 
	// los jugadores se vana agregando, y se empieza dandole una carta al azar a cada uno
	// la cola jugadores contiene a todos los jugadores que si ingresaron
	void inicializarJugadores();
	// pre: ninguna
	// post el atributo nombreArchivoBMP va a tener string que el usuario escribio por consola
	void pedirNombreDelArchivoBMP();
	// pre: ninguna
	// post: devuelve la cantidad de fichas por jugador 
	int getCantidadDeFichasPorJugador();
	// pre: ninguna
	// post: agrega a la cola de cartas la cantidad de cartas correspondientes a la cantidad de jugadores
	void crearCartas();
	// pre: numero enteros 
	// post: devuelve true si en una coordenada dentro del tablero y flase si esta fuera de rango 
	bool validarCoordenadas(int columna, int fila, int profundidad);
	// pre: 	ninguna
	// post: 	maneja el turno, l pide al usuario una serie de valores para ubicar las fichas
	// y devuelve si se termino el juego o no  
	bool insertarFichas();
	// pre: ninguna 
	// post: muta el estado del tablero con una serie de inputs que responde el usuario
	// mueve la ficha de donde esta a un casillero 
	void moverFichas();
	// pre: ninguna
	// post: le pide al usuario por input la direccion a donde mover la ficha 
	// y devuelve true si puede mover la ficha en esa direccion, y false si no la puede mover
	bool pedirDireccionAMover(int columna, int fila, int profundidad);
	// pre: ninguna
	// post: reparte cartas en la cola de cartas del jugador actual 
	void repartirCartas();
	// pre: puntero a carta no nulo
	// post: le pregunta al usuario si desea usar una de las cartas que tiene en la cola
	// si el usuario dice que quiere usar una, se desacola la carta que quiere usar y devuelve true, si no la usa devuevle false 
	bool utilizarCarta(Lista<Carta*> *cartas);

	//funciones de prueba
	// pre: lista de puntero a cartas
	// post: imprime la lista con todas las cartas 
	void mostrarCartas(Lista<Carta*> *cartas);
};
#endif /* TATETI_H_ */