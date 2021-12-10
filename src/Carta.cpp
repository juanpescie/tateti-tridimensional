#include "Carta.h"

Carta::Carta(int numero){
	this->numero = numero;
	this->descripcion = descripcionCartas[this->numero % 6];
}

std::string Carta::obtenerDescripcion(){
	return this->descripcion;
}


