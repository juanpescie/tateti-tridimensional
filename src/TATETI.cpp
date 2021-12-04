#include "TATETI.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>

using namespace std;


TATETI::TATETI(){
	this->cantidadDeJugadores = 0;

	this->tablero = NULL;

	this->jugadores = new Cola<Jugador*>;

}

void TATETI::imprimirTableros(){
	this->tablero->mostrarTodasLasFichasPorCapas();
}

void TATETI::iniciarJuego(){
	this->mostrarBienvenida();

	cout<<"\n";

	this->pedirDimensionesDelTablero();

	cout<<"\n";

	this->inicializarJugadores();

	cout<<"\n";
}

/*TATETI::~TATETI(){
	delete this->tablero;
	delete this->jugadores;
}*/

void TATETI::mostrarBienvenida(){
	cout<<"\t\t\t\t.:: Tateti ::."<<endl;

}

bool esUnNumero(string cadena){
	for(unsigned int i = 0; i < cadena.length(); i++){
		if(!isdigit(cadena[i])){
			return false;
		}
	}

	return true;
}


void TATETI::pedirDimensionesDelTablero(){
	cout<<"Ingrese las dimensiones del tablero: "<<endl;
	string dimension;

	int contadorDeDimensiones = 0, numeroDeColumnas, numeroDeFilas, profundidad;

	while(contadorDeDimensiones < 3){
		switch(contadorDeDimensiones){
		case 0:
			cout<<"Ingrese el numero de columnas del tablero: ";
			cin>>dimension;

			if(esUnNumero(dimension)){
				numeroDeColumnas = atoi(dimension.c_str());
				contadorDeDimensiones++;
			}
			else{
				cout<<"No se ha ingresado un numero valido."<<endl;
			}
			break;

		case 1:
			cout<<"Ingrese el numero de filas del tablero: ";
			cin>>dimension;

			if(esUnNumero(dimension)){
				numeroDeFilas = atoi(dimension.c_str());
				contadorDeDimensiones++;
			}
			else{
				cout<<"No se ha ingresado un numero valido."<<endl;
			}
			break;

		case 2:
			cout<<"Ingrese la profundidad del tablero: ";
			cin>>dimension;

			if(esUnNumero(dimension)){
				profundidad = atoi(dimension.c_str());
				contadorDeDimensiones++;
			}
			else{
				cout<<"No se ha ingresado un numero valido."<<endl;
			}
			break;
		}
	}

	this->tablero = new Tablero(numeroDeColumnas, numeroDeFilas, profundidad);
}

void TATETI::inicializarJugadores(){
	string cadena;
	bool seIngresoUnNumero = false;
	while(!seIngresoUnNumero){
		cout<<"Ingrese la cantidad de jugadores: ";
		cin>>cadena;

		if(esUnNumero(cadena)){
			this->cantidadDeJugadores = atoi(cadena.c_str());
			seIngresoUnNumero = true;
		}
		else{
			cout<<"Entrada no valida\n"<<endl;
		}
	}

	int contador = 1;

	while(contador <= this->cantidadDeJugadores){
		cout<<"Jugador "<<contador<<endl;
		cout<<"\nIngrese el nombre del jugador: ";
		cin>>cadena;

		char ficha;
		cout<<"Ingrese la ficha del jugador";
		cin>>ficha;

		this->jugadores->acolar(new Jugador(cadena, contador, ficha));

		contador++;
	}

}

void TATETI::jugarPartida(){
	bool finalizoLaPartida = false;
	string cadenaColumna, cadenaFila, cadenaProfundidad;

	while(!finalizoLaPartida){
		Jugador *jugadorActual = this->jugadores->front();
		cout<<"Turno de: "<<jugadorActual->obtenerNombre()<<endl;
		cout<<"Ingresar coordenadas: "<<endl;

		cout<<"Columna: ";
		cin>>cadenaColumna;

		cout<<"Fila: ";
		cin>>cadenaFila;

		cout<<"Profundidad: ";
		cin>>cadenaProfundidad;

		if(esUnNumero(cadenaColumna) ||
				esUnNumero(cadenaFila) ||
				esUnNumero(cadenaProfundidad)){

			int columna = atoi(cadenaColumna.c_str());
			int fila = atoi(cadenaFila.c_str());
			int profundidad = atoi(cadenaProfundidad.c_str());

			if(validarCoordenadas(columna,fila,profundidad)){
				if(!this->tablero->casilleroEstaVacio(columna, fila, profundidad)){
					this->tablero->getCasilla(columna, fila, profundidad)->setFicha(jugadorActual->obtenerFicha());

					if(this->verificarGanador(jugadorActual->obtenerFicha())){
						cout<<jugadorActual->obtenerNombre()<<" gano la partida"<<endl;
						jugadorActual->ganoLaPartida();
					}

					this->jugadores->desacolar();
					this->jugadores->acolar(jugadorActual);
				}
				else{
					cout<<"El casillero no esta vacio"<<endl;
				}
			}
			else{
				cout<<"Coordenadas invalidas"<<endl;
			}
		}

		else{
			cout<<"No se ha ingresado un numero"<<endl;
		}
	}
}


bool TATETI::validarCoordenadas(int columna, int fila, int profundidad){
	if(columna > 0 && columna <= this->tablero->getAncho() &&
			fila > 0 && fila <= this->tablero->getAltura() &&
			profundidad > 0 && profundidad <= this->tablero->getProfundidad()){
		return true;
	}
	else{
		return false;
	}
}