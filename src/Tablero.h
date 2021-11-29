#ifndef TABLERO_H_
#define TABLERO_H_

#include "Casillero.h"

class Tablero{
private:
	int alto;
	int ancho;
	Casillero ***tablero;

public:
	Tablero(int alto, int ancho);
	int obtenerAncho();
	int obtenerAlto();
	char obtenerFichaEnPosicion(int alto, int ancho);
	bool casilleroVacio(int alto, int ancho);
	void insertarFicha(char ficha, int alto, int ancho);
	void imprimirTablero();
	~Tablero();
};



#endif /* TABLERO_H_ */
