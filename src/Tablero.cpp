#include "Tablero.h"

#include <iostream>

using namespace std;

Tablero::Tablero(int alto, int ancho){
	this->alto = alto, this->ancho = ancho;

	this->tablero = new Casillero**[alto];

	for(int i=0; i < alto; i++){
		this->tablero[i] = new Casillero*[ancho];
		for(int j=0; j < ancho; j++){
			this->tablero[i][j] = new Casillero(i, j);
		}
	}
}

int Tablero::obtenerAncho(){
	return this->ancho;
}

int Tablero::obtenerAlto(){
	return this->alto;
}

char Tablero::obtenerFichaEnPosicion(int alto, int ancho){
	return this->tablero[alto][ancho]->obtenerFicha();
}

bool Tablero::casilleroVacio(int alto, int ancho){
	return this->tablero[alto][ancho]->estaVacio();
}

void Tablero::insertarFicha(char ficha, int alto, int ancho){
	if(alto < 0 || alto >= this->alto || ancho < 0 || ancho >= this->ancho){
		cout<<"Coordenadas invalidas"<<endl;
	}

	else if(this->casilleroVacio(alto, ancho)){
		this->tablero[alto][ancho]->setFicha(ficha);
	}

	else{
		cout<<"El casillero no esta vacio"<<endl;
	}
}

void Tablero::imprimirTablero(){
	for(int i=0; i < this->alto; i++){
		for(int j=0; j < this->ancho; j++){
			cout<<this->obtenerFichaEnPosicion(i, j);

			if(j != this->ancho-1){
				cout<<"  |";
			}
		}
		if(i != this->alto-1){
			cout<<'\n';
			cout<<"-----------"<<endl;
		}
	}

	cout<<endl;
}

Tablero::~Tablero(){
	for(int i = 0; i < this->alto; i++){
		for(int j = 0; j < this->ancho; j++){
			delete this->tablero[i][j];
		}
		delete this->tablero[i];
	}

	delete this->tablero;
}
