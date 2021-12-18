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
	// pre: ninguna
	// post: devuelve una instancia del casilllero con la ficha vacia(espacio)
	Casillero();
	~Casillero();
	// pre: caracter
	// post: la ficha del casillero es la que se asigno con parametro 
	void setFicha(char ficha);
	// pre: ninguna
	// post: devuelve la ficha que contiene el casillero
	char mostrarFicha();
	// pre: ninguna
	// post: devuelve el estado del casillero, si esta habilitado o esta bloqueado
	Estado obtenerEstado();
	// pre: ninguna
	// post: el casillero queda habilitado para su uso 
	void habilitar();
	// pre: ninguna
	// post: el casillero queda deshabilitado para su uso 
	void deshabilitar();
	// pre: ninguna
	// post: el casillero queda bloqueado hasta que se desbloquee
	void bloquear();
	void asignarVecino1(int fila, int columna, Casillero* casillero);
	// pre: enteros positivos menores a 3
	// post: el casillero tiene un nuevo valor en el atributo vecinos en la coordenada que se le pasa por parametros
	void asignarVecino(int profundidad, int fila, int columna, Casillero* casillero);

	void mostrarVecinosDelAdyacente(int i, int j);
	void mostrarVecinos1();
	// pre: ninguna
	// post: muestra por consola por capas, los vecinos del casillero 
	void mostrarVecinos();
	int getLongitud1(int i, int j);
	// pre: ninguna
	// post: devuelve la cantidad de casillero seguidos con la misma ficha en linea
	int getLongitud(int profundidad, int fila, int columna);
	Casillero* getAdyacente1(int i, int j);
	// pre: ninguna 
	// post: devuelve el casillero que esta al lado en la posicion que se pasa por parametro 
	Casillero* getAdyacente(int profundidad, int fila, int columna);

	bool tieneAdyacente1(int i, int j);
	// pre: ninguna
	// post: devuelve true si su casillero vecino no es nulo, o false si lo es 
	bool tieneAdyacente(int profundidad, int fila, int columna);
	// pre: ninguna
	// post: devuelve true si el caracter que tiene el casillero no se el espacio " ", y true si tiene otro caracter
	bool estaOcupado();
	// pre: ninguna
	// post: devuelve true si el casillero tiene como estado igual a HABILITADO, false si no lo esta 
	bool estaDisponible();
	// pre: ninguna
	// post: devuelve true si los dos casilleros tienen la misma ficha, false si son distitnas
	bool tienenLaMismaFicha(Casillero* otroCasillero);
};


#endif /* CASILLERO_H_ */
