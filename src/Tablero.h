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
	// pre: numeros positivos en todos los parametros
	// post: genera una instancia de tablero con las dimensiones que se le pasan por parametro
	Tablero(unsigned int Profundidad, unsigned int cantidadFilas, unsigned int cantidadColumnas);
	// pre: ninguna
	// post: devuelve un numero entero con el numero de filas en el tablero
	int getAltura();
	// pre: ninguna
	// post: devuelve un numero entero con el numero de columnas en el tablero
	int getAncho();
	// pre: ninguna
	// post: devuelve un numero entero con el numero de capas en el tablero
	int getProfundidad();
	// pre: numeros positivos menores que la cantidad de capas, filas y columnas respectivamente
	// post: devuelve un puntero a casiillero que se encuentra en esa posicion del tablero
	Casillero* getCasilla(int profundidad, int fila, int columna);
	// pre: numeros positivos menores que la cantidad de capas, filas y columnas respectivamente
	// post: el casillero de esa posicion va a tener en su atributo ficha el caracter que se le pasa por parametro
	void setCasilla(int profundidad,int fila, int columna, char ficha);
	// pre: ninguna
	// devuelve true si los parametros coinciden con una direccion del tablero
	bool existeCasilla(int profundidad,int fila, int columna);
	// pre: el puntero a casillero no debe ser nulo
	// post: devuelve true si se formo tateti con la canatidad de fichas que se le pasa por parametro(fichasaraGanar),
	// el tablero tiene que tener en linea recta con el mismo caracter del casilleroAChequear
	// false en el caso contrario
	bool hayTateti(Casillero* casilleroAChequear, int cantidadDeFichasParaGanar);
	// pre: dimensiones validas
	// devuelve true si el casillero que se encuentra en esa posicion tiene un caracter distinto al espacio
	bool casilleroEstaVacio(int profundidad, int fila, int columna);
	// pre: nombre string no vacio 
	// post: genera un archivo bitmap con las proyecciones de las capas del tablero 
	void generarBitMap(std::string nombreDelArchivo);
	// pre: ninguna
	// post: muestra por consola los planos XY del tablero recorriendo la profunidad
	void mostrarTableroPorCapas();
	// pre: dimensiones validas
	// post: devuelve true si el casillero esta habilitado para ser usado
	bool casilleroEstaDisponible(int profundidad, int fila, int columna);
	~Tablero();
};




#endif /* TABLERO_H_ */