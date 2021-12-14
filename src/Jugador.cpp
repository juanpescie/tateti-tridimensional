#include "Jugador.h"
#include "Lista.h"
//#include "Carta.h"

Jugador::Jugador(std::string nombre, char ficha){
	this->nombre = nombre;
	this->numeroDeCartasActual = 0;
	this->cantidadDePartidasGanadas = 0;
	this->ficha = ficha;
	this->cantidadDeCartasDisponibles = 0;
}

std::string Jugador::obtenerNombre(){
	return this->nombre;
}

int Jugador::obtenerCantidadDePartidasGanadas(){
	return this->cantidadDePartidasGanadas;
}

void Jugador::ganoLaPartida(){
	this->cantidadDePartidasGanadas++;
}

char Jugador::obtenerFicha(){
	return this->ficha;
}

void Jugador::agregarCarta(){
	this->cantidadDeCartasDisponibles++;
}
