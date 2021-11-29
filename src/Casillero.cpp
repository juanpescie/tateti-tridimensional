#include "Casillero.h"

Casillero::Casillero(int numeroDeFila, int numeroDeColumna){
	this->numeroDeFila = numeroDeFila;
	this->numeroDeColumna = numeroDeColumna;
	this->ficha = ' ';
	this->estado = HABILITADO;
}

int Casillero::obtenerNumeroDeFila(){
	return this->numeroDeFila;
}

int Casillero::obtenerNumeroDeColumna(){
	return this->numeroDeColumna;
}

char Casillero::obtenerFicha(){
	return this->ficha;
}

Estado Casillero::obtenerEstado(){
	return this->estado;
}

bool Casillero::estaHabilitado(){
	return (this->estado == HABILITADO);
}

void Casillero::deshabilitar(){
	if(this->estado == HABILITADO){
		this->estado = DESHABILITADO;
	}
}

void Casillero::habilitar(){
	if(this->estado == DESHABILITADO){
		this->estado = HABILITADO;
	}
}

bool Casillero::estaVacio(){
	return (this->ficha == ' ');
}

void Casillero::setFicha(char ficha){
	if(this->estaVacio() && this->estaHabilitado()){
		this->ficha = ficha;
	}
}
