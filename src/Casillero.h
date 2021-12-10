#ifndef CASILLERO_H_
#define CASILLERO_H_

enum Estado{
	HABILITADO, DESHABILITADO, BLOQUEADO
};

class Casillero{
private:
	char Ficha;
	Estado estado;
	Casillero* vecinos[3][3];
	Casillero* casillerosVecinos[3][3][3];

public:
	Casillero();
	~Casillero();
	void setFicha(char ficha);
	char mostrarFicha();
	Estado obtenerEstado();
	void habilitar();
	void deshabilitar();
	void bloquear();
	void asignarVecino1(int fila, int columna, Casillero* casillero);
	void asignarVecino(int profundidad, int fila, int columna, Casillero* casillero);
	void mostrarVecinosDelAdyacente(int i, int j);
	void mostrarVecinos1();
	void mostrarVecinos();
	int getLongitud1(int i, int j);
	int getLongitud(int profundidad, int fila, int columna);
	Casillero* getAdyacente1(int i, int j);
	Casillero* getAdyacente(int profundidad, int fila, int columna);

	bool tieneAdyacente1(int i, int j);
	bool tieneAdyacente(int profundidad, int fila, int columna);
	bool estaOcupado();
	bool tienenLaMismaFicha(Casillero* otroCasillero);
};


#endif /* CASILLERO_H_ */
