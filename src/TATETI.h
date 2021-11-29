#ifndef TATETI_H_
#define TATETI_H_

#include "Lista.h"

#include "Tablero.h"

class TATETI{
private:
	int alto;
	int ancho;
	int profundidad;
	Lista<Tablero*> *tableros;

public:
	TATETI(int alto, int ancho, int profundidad);
	void insertarFicha(int alto, int ancho, int profundidad);
	void imprimirTableros();
	~TATETI();
};

#endif /* TATETI_H_ */
