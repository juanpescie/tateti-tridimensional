#include "Jugador.h"

Jugador::Jugador(std::string nombre, int identificacion){
	this->nombre = nombre;
	this->numeroDeJugador = identificacion;
}

std::string Jugador::obtenerNombre(){
	return this->nombre;
}

int Jugador::obtenerNumeroDeJugador(){
	return this->numeroDeJugador;
}





