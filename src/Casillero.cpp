#include "Casillero.h"

Casillero::Casillero(){
	this->Ficha = '\0';
}

Casillero::~Casillero(){

}

void Casillero::setFicha(char ficha){
	this->Ficha = ficha;
}

char Casillero::mostrarFicha(){
	return this->Ficha;
}