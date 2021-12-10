#include "Casillero.h"
#include <iostream>

using namespace std;

Casillero::Casillero(){
	this->Ficha = ' ';
	this->estado = HABILITADO;
}

Casillero::~Casillero(){
	// borra los ppunteros a casilleros de vecinos y casillerosVecinos
	for(int i = 0; i<3; i++){
		for(int j = 0 ; j<3; j++){
			if(this->vecinos[i][j] != NULL){
					delete this->vecinos[i][j];
				}
		}
	}
	for(int a = 0; a<3; a++){
		for(int b = 0 ; b<3; b++){
			for (int c=0; c<3; c++){
				if(this->casillerosVecinos[a][b][c] != NULL){
					delete this->casillerosVecinos[a][b][c];
				}
			}
		}
	}
}

void Casillero::setFicha(char ficha){
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

