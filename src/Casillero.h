#ifndef CASILLERO_H_
#define CASILLERO_H_

enum Estado{
	HABILITADO, DESHABILITADO
};

class Casillero{
private:
	int numeroDeFila;
	int numeroDeColumna;
	char ficha;
	Estado estado;

public:
	Casillero(int numeroDeFila, int numeroDeColumna);
	int obtenerNumeroDeFila();
	int obtenerNumeroDeColumna();
	char obtenerFicha();
	Estado obtenerEstado();
	void setFicha(char ficha);
	bool estaHabilitado();
	void deshabilitar();
	void habilitar();
	bool estaVacio();
};



#endif /* CASILLERO_H_ */
