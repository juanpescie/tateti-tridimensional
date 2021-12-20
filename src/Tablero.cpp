#include "Tablero.h"
#include <iostream>
using namespace std;

bool Tablero::profundidadValida(int profundidad){
	return (profundidad >= 1 && profundidad <= this->getProfundidad());
}

bool Tablero::alturaValida(int altura){
	return (altura >= 1 && altura <= this->getAltura());
}

bool Tablero::anchoValido(int ancho){
	return (ancho >= 1 && ancho <= this->getAncho());
}

Tablero::Tablero(unsigned int Profundidad, unsigned int cantidadFilas, unsigned int cantidadColumnas){
	this->profundidad = Profundidad;
	this->altura = cantidadFilas;
	this->ancho = cantidadColumnas;
	this->casilleros = new Lista<Lista<Lista<Casillero*>*>*>();
	this->ultimaPosicionX = 0;
	this->ultimaPosicionY = 0;
	this->ultimaPosicionZ = 0;

	for(int i=0; i<Profundidad; i++){
		Lista<Lista<Casillero*>*>* capa = new Lista<Lista<Casillero*>*>();
		for(int j=0; j<cantidadColumnas; j++){
			Lista<Casillero*>* columna = new Lista<Casillero*>();
			for(int k=0; k<cantidadFilas; k++){
				Casillero* casillero = new Casillero();
				columna->add(casillero);
			}
			capa->add(columna);
		}
		this->casilleros->add(capa);
	}

	for(int i=1; i<=Profundidad; i++){
		for(int j=1; j<=cantidadColumnas; j++){
			for(int k=1; k<=cantidadFilas; k++){
				Casillero* casillero = getCasilla(i,k,j);
				for(int l=-1; l<2; l++){
					for(int m=-1; m<2; m++){
						for(int n=-1; n<2; n++){
							if(existeCasilla(i+l,k+m,j+n)){
								Casillero* casilleroVecino = getCasilla(i+l,k+m,j+n);
								casillero->asignarVecino(l+1,m+1,n+1, casilleroVecino);
							}
							else{
								casillero->asignarVecino(l+1,m+1,n+1, NULL);
							}
						}
					}
				}
			}
		}
	}
}
Tablero::~Tablero(){
	Lista<Lista<Lista<Casillero*>*>*>* capa = this->casilleros;
	capa->reiniciarCursor();
	while(capa->avanzarCursor()){
		Lista<Lista<Casillero*>*>* columna = capa->getCursor();
		columna->reiniciarCursor();
		while(columna->avanzarCursor()){
			Lista<Casillero*>* fila = columna->getCursor();
			fila->reiniciarCursor();
			while(fila->avanzarCursor()){
				delete fila->getCursor(); //borra el puntero a casillero 
			}
			delete fila;
		}
		delete columna;
	}
	delete capa;

}

int Tablero::getAltura(){
	return this->altura;
}

int Tablero::getAncho(){
	return this->ancho;
}

int Tablero::getProfundidad(){
	return this->profundidad;
}
void Tablero::setUltimaPosicion(int profundidad, int fila, int columna){
	this->ultimaPosicionX = columna, this->ultimaPosicionY = fila, this->ultimaPosicionZ = profundidad;
}

int Tablero::getUltimaProfundidad(){
	return this->ultimaPosicionZ;
}

int Tablero::getUltimaColumna(){
	return this->ultimaPosicionX;
}

int Tablero::getUltimaFila(){
	return this->ultimaPosicionY;
}

Casillero* Tablero::getCasilla(int profundidad, int fila, int columna){
	return this->casilleros->get(profundidad)->get(columna)->get(fila);
}

void Tablero::setCasilla(int profundidad,int fila, int columna, char ficha){
	this->casilleros->get(profundidad)->get(columna)->get(fila)->setFicha(ficha);
}

bool Tablero::existeCasilla(int profundidad,int fila, int columna){
	return(profundidadValida(profundidad) && alturaValida(fila) && anchoValido(columna));
}

bool Tablero::hayTateti(Casillero* casilleroAChequear, int cantidadDeFichasParaGanar){
    int longitudesAdyacentes[3][3][3];
    int sumaLongitudes[13];

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                if(i == 1 && j == 1 && k == 1){
                    longitudesAdyacentes[i][j][k] = 1;
                }
                else{
                    longitudesAdyacentes[i][j][k] = casilleroAChequear->getLongitud(i,j,k);
                }
            }
        }
    }
    sumaLongitudes[0] = longitudesAdyacentes[0][0][0] + longitudesAdyacentes[2][2][2];
    sumaLongitudes[1] = longitudesAdyacentes[0][0][1] + longitudesAdyacentes[2][2][1];
    sumaLongitudes[2] = longitudesAdyacentes[0][0][2] + longitudesAdyacentes[2][2][0];
    sumaLongitudes[3] = longitudesAdyacentes[0][1][0] + longitudesAdyacentes[2][1][2];
    sumaLongitudes[4] = longitudesAdyacentes[0][1][1] + longitudesAdyacentes[2][0][1];
    sumaLongitudes[5] = longitudesAdyacentes[0][1][2] + longitudesAdyacentes[2][1][0];
    sumaLongitudes[6] = longitudesAdyacentes[0][2][0] + longitudesAdyacentes[2][0][2];
    sumaLongitudes[7] = longitudesAdyacentes[0][2][1] + longitudesAdyacentes[2][0][1];
    sumaLongitudes[8] = longitudesAdyacentes[0][2][2] + longitudesAdyacentes[2][0][0];
    sumaLongitudes[9] = longitudesAdyacentes[1][0][0] + longitudesAdyacentes[1][2][2];
    sumaLongitudes[10] = longitudesAdyacentes[1][0][1] + longitudesAdyacentes[1][2][1];
    sumaLongitudes[11] = longitudesAdyacentes[1][0][2] + longitudesAdyacentes[1][2][0];
    sumaLongitudes[12] = longitudesAdyacentes[1][1][0] + longitudesAdyacentes[1][1][2];

    for(int i=0; i<13; i++){
        if(sumaLongitudes[i] + 1 == cantidadDeFichasParaGanar){
            return true;
        }
    }
    return false;
}

bool Tablero::casilleroEstaVacio(int profundidad, int fila, int columna){
	if(this->getCasilla(profundidad, fila, columna)->mostrarFicha() == ' '){
		return true;
	}
	else{
		return false;
	}
}

bool Tablero::casilleroEstaDisponible(int profundidad, int fila, int columna){
	Casillero *casilleroSolicitado = this->getCasilla(profundidad, fila, columna);

	if(casilleroSolicitado->estaDisponible()){
		return true;
	}

	return false;
}

void Tablero::mostrarTableroPorCapas(){
	for(int i=1; i<=this->getProfundidad(); i++){
		cout << "Capa numero: " << i << endl;
		for(int j=1; j<=this->getAncho(); j++){
			for(int k=1; k<=this->getAltura(); k++){
				if(this->getCasilla(i,j,k) != NULL){
					cout << this->getCasilla(i,j,k)->mostrarFicha();
					cout << "|";
				}
				else{
					cout << "0";
					cout << "|";
				}

			}
			cout << endl;
		}
	}
}

void Tablero::generarBitMap(std::string nombreDelArchivo){
	BMP imagenTablero;
	RGBApixel negro;

	negro.Red = 0, negro.Blue = 0, negro.Green = 0;

	int fontHeight = 40;

	int alturaImagen = profundidad*(altura*fontHeight) + fontHeight;
	int anchoImagen = (int)(0.6 * (fontHeight) * (ancho)) + fontHeight;

	imagenTablero.SetSize(anchoImagen, alturaImagen);

	char texto[256] = "";

	int altura = 0;

	for(int i=1; i <= this->profundidad; i++){

		for(int j=1; j <= this->ancho; j++){
			int contador = 0;
			for(int k=1; k <= this->altura; k++){
				texto[contador++] = this->getCasilla(i, j, k)->mostrarFicha();

				if(k != this->altura){
					texto[contador++] = '|';
				}
			}
			PrintString(imagenTablero, texto, 0, altura, fontHeight, negro);
			altura += fontHeight;
		}
		altura += 10;
	}


	imagenTablero.WriteToFile(nombreDelArchivo.c_str());
}
