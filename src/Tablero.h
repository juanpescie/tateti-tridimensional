#ifndef TABLERO_H_
#define TABLERO_H_

#include "Casillero.h"
#include "Lista.h"

class Tablero{
private:

	Lista<Lista<Lista<Casillero*>*>*>* casilleros;
	int altura;
	int ancho;
	int profundidad;

public:
	Tablero(int cantidadColumnas, int cantidadFilas, int Profundidad);
	int getAltura();
	int getAncho();
	int getProfundidad();
	~Tablero();
	Casillero* getCasilla(int columna, int fila, int profundidad);
	void setCasilla(int columna, int fila, int profundidad, char ficha);

	void mostrarTodasLasFichasPorCapas();
	void mostrarTableroDelantero();//Muestra la cara delantera del tablero
	void mostrarTableroDeAtras();//Muestra la cara de atras del tablero
	void mostrarTableroIzquierdo();//Muestra la cara izquierdo del tablero
	void mostrarTableroDerecho();//Muestra la cara derecha del tablero
};



#endif /* TABLERO_H_ */
