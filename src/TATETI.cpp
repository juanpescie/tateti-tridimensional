#include "TATETI.h"
#include <iostream>

using namespace std;


TATETI::TATETI(int alto, int ancho, int profundidad){
	this->alto = alto;
	this->ancho = ancho;
	this->profundidad = profundidad;

	this->tableros = new Lista<Tablero*>;

	for(int i=0; i < profundidad; i++){
		this->tableros->add(new Tablero(alto, ancho));
	}
}

void TATETI::imprimirTableros(){
	this->tableros->reiniciarCursor();

	int contador = 1;

	while(tableros->avanzarCursor()){
		cout<<"###\t TABLERO "<<contador<<" \t###"<<endl;
		this->tableros->getCursor()->imprimirTablero();
		contador++;
	}
}

TATETI::~TATETI(){
	this->tableros->reiniciarCursor();

	while(tableros->avanzarCursor()){
		delete this->tableros->getCursor();
	}

	delete this->tableros;
}

