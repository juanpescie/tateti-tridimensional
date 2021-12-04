#include "Tablero.h"
#include <iostream>
using namespace std;

Tablero::Tablero(int cantidadColumnas, int cantidadFilas, int Profundidad){
	this->casilleros = new Lista<Lista<Lista<Casillero*>*>*>();
	this->altura = cantidadFilas;
	this->ancho = cantidadColumnas;
	this->profundidad = Profundidad;

	for(int i=0; i<profundidad; i++){
		Lista<Lista<Casillero*>*>* capa = new Lista<Lista<Casillero*>*>();
		for(int j=0; j<cantidadColumnas; j++){
			Lista<Casillero*>* columna = new Lista<Casillero*>();
			for(int k=0; k<cantidadFilas; k++){
				Casillero* casillero = new Casillero();
				casillero->setFicha(' ');
				columna->add(casillero);
			}
			capa->add(columna);
		}
		this->casilleros->add(capa);
	}
}

int Tablero::getAltura(){
	return this->altura;
}
int Tablero::getAncho(){
	return this->ancho;
}

int Tablero::getProfundidad(){
	return this->profundidad;
}

Casillero* Tablero::getCasilla(int columna, int fila, int profundidad){
	return this->casilleros->get(profundidad)->get(columna)->get(fila);
}


void Tablero::setCasilla(int columna, int fila, int profundidad, char ficha){
	this->casilleros->get(profundidad)->get(columna)->get(fila)->setFicha(ficha);
}

void Tablero::mostrarTodasLasFichasPorCapas(){
	for(int i=1; i<=this->getProfundidad(); i++){
		cout << "Capa numero: " << i << endl;
		for(int j=1; j<=this->getAncho(); j++){
			for(int k=1; k<=this->getAltura(); k++){
				cout << this->getCasilla(k,j,i)->mostrarFicha();
			}
			cout << endl;
		}
	}
}

void Tablero::mostrarTableroDelantero(){
	cout << "Tablero delantero: " << endl;
	for(int i=1; i<=this->getAncho(); i++){
		cout << "|";
		for(int j=1; j<=this->getAltura(); j++){
			cout << this->getCasilla(j,i,1)->mostrarFicha();
			cout << "|";
		}
		cout << endl;
	}
}

//Lo muestra al reves de como deberia mostrarlo
void Tablero::mostrarTableroDeAtras(){
	cout << "Tablero de atras: " << endl;
	for(int i=1; i<=this->getAncho(); i++){
		cout << "|";
		for(int j=1; j<=this->getAltura(); j++){
			cout << this->getCasilla(j,i,this->getProfundidad())->mostrarFicha();
			cout << "|";
		}
		cout << endl;
	}
}

void Tablero::mostrarTableroIzquierdo(){
	cout << "Tablero izquierdo " << endl;
	for(int i=1; i<=this->getAncho(); i++){
		cout << "|";
		for(int j=this->getProfundidad(); j>=1; j--){
			cout << this->getCasilla(1,i,j)->mostrarFicha();
			cout << "|";
		}
		cout << endl;
	}
}

void Tablero::mostrarTableroDerecho(){
	cout << "Tablero derecho " << endl;
	for(int i=1; i<=this->getAltura(); i++){
		cout << "|";
		for(int j=1; j<=this->getProfundidad(); j++){
			cout << this->getCasilla(this->getAncho(),i,j)->mostrarFicha();
			cout << "|";
		}
		cout << endl;
	}
}

