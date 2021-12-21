#include "Casillero.h"
#include <iostream>

using namespace std;

Casillero::Casillero(){
	this->Ficha = ' ';
	this->estado = HABILITADO;
}

Casillero::~Casillero(){
	// borra los punteros a casilleros de vecinos
	for(int i = 0; i<3; i++){
		for(int j = 0 ; j<3; j++){
				for (int k = 0; k <3; k++){
					// en este bloque borra el puntero a casillero de la matriz 3 X 3 de vecinos
					if(this->casillerosVecinos[i][j][k] != NULL){
						delete this->casillerosVecinos[i][j][k];
				}
			}
		}
	}
}

void Casillero::setFicha(char ficha){
	this->fichaAnterior = this->Ficha;
	this->Ficha = ficha;
}

char Casillero::mostrarFicha(){
	return this->Ficha;
}

Estado Casillero::obtenerEstado(){
	return this->estado;
}

void Casillero::habilitar(){
	if(this->estado != HABILITADO){
		this->estado = HABILITADO;
	}
}

void Casillero::deshabilitar(){
	if(this->estado != DESHABILITADO){
		this->estado = DESHABILITADO;
	}
}

void Casillero::bloquear(){
	if(this->estado != BLOQUEADO){
		this->estado = BLOQUEADO;
	}
}

char Casillero::mostrarFichaAnterior(){
	return this->fichaAnterior;
}

void Casillero::asignarVecino(int profundidad, int fila, int columna, Casillero* casillero){
	this->casillerosVecinos[profundidad][fila][columna] = casillero;
}

void Casillero::mostrarVecinos(){
	for(int i=0; i<3; i++){
		cout <<"Capa de vecinos nro: " << i << endl;
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				if(this->casillerosVecinos[i][j][k] != NULL){
					cout << this->casillerosVecinos[i][j][k]->mostrarFicha();
					cout << "|";
				}
				else if(this->casillerosVecinos[i][j][k] == NULL){
					cout << " ";
					cout << "|";
				}
			}
			cout << endl;
		}
	}
}


Casillero* Casillero::getAdyacente(int profundidad, int fila, int columna){
	return this->casillerosVecinos[profundidad][fila][columna];
}


bool Casillero::tieneAdyacente(int profundidad, int fila, int columna){
	if( (profundidad >= 0 && profundidad<=2) && (fila>= 0 && fila<=2) && (columna >= 0 && columna<=2)){
		return this->casillerosVecinos[profundidad][fila][columna] != NULL;
	}
	return false;
}

bool Casillero::estaOcupado(){
	return (this != NULL);
}

bool Casillero::estaDisponible(){
	if(this->estado == HABILITADO){
		return true;
	}

	return false;
}

bool Casillero::tienenLaMismaFicha(Casillero* otroCasillero){
	if(otroCasillero->estaOcupado()){
		return this->mostrarFicha() == otroCasillero->mostrarFicha();
	}

	return false;
}

int Casillero::getLongitud(int profundidad, int fila, int columna){
	if(this->tieneAdyacente(profundidad, fila, columna) == false || this->mostrarFicha() == ' '){
		return 0;
	}
	Casillero* casilleroAdyacente = this->getAdyacente(profundidad, fila, columna);
	if(this->tienenLaMismaFicha(casilleroAdyacente) == true){
		return (1 + casilleroAdyacente->getLongitud(profundidad, fila, columna));
	}
	return 0;
}