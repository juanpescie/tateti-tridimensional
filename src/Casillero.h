#ifndef CASILLERO_H_
#define CASILLERO_H_

class Casillero{
private:
	char Ficha;

public:
	Casillero();
	~Casillero();
	void setFicha(char ficha);
	char mostrarFicha();
};


#endif /* CASILLERO_H_ */