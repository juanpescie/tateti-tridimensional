#ifndef TABLERO_H_
#define TABLERO_H_

#include "Casillero.h"
#include "Lista.h"
#include "EasyBMP.h"
#include "EasyBMP_font.h"

class Tablero{
private:

	Lista<Lista<Lista<Casillero*>*>*>* casilleros;

	int altura;
	int ancho;
	int profundidad;
	bool profundidadValida(int profundidad);
	bool alturaValida(int altura);
	bool anchoValido(int ancho);

public:
	Tablero(int Profundidad, int cantidadFilas, int cantidadColumnas);
	int getAltura();
	int getAncho();
	int getProfundidad();
	Casillero* getCasilla(int profundidad, int fila, int columna);
	void setCasilla(int profundidad,int fila, int columna, char ficha);
	bool existeCasilla(int profundidad,int fila, int columna);
	bool hayTateti(Casillero* casilleroAChequear, int cantidadDeFichasParaGanar);
	bool casilleroEstaVacio(int profundidad, int fila, int columna);
	void generarBitMap(std::string nombreDelArchivo);
	void mostrarTableroPorCapas();
};




#endif /* TABLERO_H_ */
