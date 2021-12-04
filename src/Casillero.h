#ifndef CASILLERO_H_
#define CASILLERO_H_

enum Estado{
	HABILITADO, DESHABILITADO
};

class Casillero{
private:
	char ficha;
	Estado estado;

public:
	Casillero();
	char obtenerFicha();
	Estado obtenerEstado();
	void setFicha(char ficha);
	bool estaHabilitado();
	void deshabilitar();
	void habilitar();
	bool estaVacio();
};



#endif /* CASILLERO_H_ */
