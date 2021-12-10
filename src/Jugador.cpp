#include "Jugador.h"
#include "Lista.h"
//#include "Carta.h"

Jugador::Jugador(std::string nombre, char ficha){
	this->nombre = nombre;
	this->numeroDeCartasActual = 0;
	this->cantidadDePartidasGanadas = 0;
	this->ficha = ficha;
	//this->cartas = new Lista<Carta*>;
}

std::string Jugador::obtenerNombre(){
	return this->nombre;
}

int Jugador::obtenerCantidadDePartidasGanadas(){
	return this->cantidadDePartidasGanadas;
}

void Jugador::ganoLaPartida(){
	this->cantidadDePartidasGanadas++;
}

char Jugador::obtenerFicha(){
	return this->ficha;
}

/*void Jugador::agregarCarta(Carta *carta){
	this->cartas->add(carta);

}

void Jugador::mostrarCartas(){
	for(int i = 1; i <= this->numeroDeCartasActual; i++){
		cout<<i<<": "<<this->cartas->get(i)->mostrarDescripcion()<<endl;
	}

	cout<<endl;
}*/
