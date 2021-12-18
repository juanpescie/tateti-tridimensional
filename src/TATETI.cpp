#include "TATETI.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>

using namespace std;
#define STRING(num) #num

string cartasDescripcion[6]{
	"Hacer perder turno a un jugador",
	"Bloquear una ficha de otro jugador",
	"Anular casillero",
	"Volver atras una jugada",
	"Mover ficha",
	" ",
};
const int CARTAS_MAXIMAS_POR_JUGADOR = 3;

Carta::Carta(int numero){
	this->numero = numero;
	this->descripcion = cartasDescripcion[numero % 6];
}

string Carta::obtenerDescripcion(){
	return this->descripcion;
}

bool esUnNumero(string cadena){
	for(unsigned int i = 0; i < cadena.length(); i++){
		if(!isdigit(cadena[i])){
			return false;
		}
	}

	return true;
}

bool validarCoordenadas(Tablero *tablero, int columna, int fila, int profundidad){
	if(columna > 0 && columna <= tablero->getAncho() &&
				fila > 0 && fila <= tablero->getAltura() &&
				profundidad > 0 && profundidad <= tablero->getProfundidad()){
			return true;
		}
		else{
			return false;
		}
}

void Carta::jugadorPierdeUnTurno(Tablero *tablero, Cola<Jugador*> *jugadores){
	Jugador *jugadorActual = jugadores->front();
	jugadores->acolar(jugadorActual);

	jugadorActual = jugadores->front();

	cout<<jugadorActual->obtenerNombre()<<" pierde un turno"<<endl;

	jugadores->acolar(jugadorActual);
}

void Carta::bloquearFicha(Tablero *tablero, Cola<Jugador*> *jugadores){
	string cadenaColumna, cadenaFila, cadenaProfundidad;
	bool listo = false;

	char fichaJugadorActual = jugadores->front()->obtenerFicha();

	while(!listo){
		cout<<"Ingrese las coordenadas de la ficha que desea bloquear: ";

		cout<<"Columna: ";
		cin>>cadenaColumna;

		cout<<"Fila: ";
		cin>>cadenaFila;

		cout<<"Profundidad: ";
		cin>>cadenaProfundidad;

		if(esUnNumero(cadenaColumna) && esUnNumero(cadenaFila) && esUnNumero(cadenaProfundidad)){
			int columna = atoi(cadenaColumna.c_str());
			int fila = atoi(cadenaFila.c_str());
			int profundidad = atoi(cadenaProfundidad.c_str());

			if(validarCoordenadas(tablero, columna, fila, profundidad)){
				if(!tablero->casilleroEstaVacio(profundidad, fila, columna) &&
					tablero->getCasilla(profundidad, fila, columna)->mostrarFicha() != fichaJugadorActual){

					tablero->getCasilla(profundidad, fila, columna)->bloquear();
					listo = true;

				}

				else{
					cout<<"No se puede bloquear este casillero"<<endl;
				}
			}

			else{
				cout<<"Coordenadas invalidas"<<endl;
			}
		}

		else{
			cout<<"No se ha ingresado un numero valido"<<endl;
		}
	}
}

void Carta::anularCasillero(Tablero *tablero, Cola<Jugador*> *jugadores){
	string cadenaColumna, cadenaFila, cadenaProfundidad;
	bool listo = false;

	while(!listo){
		cout<<"Ingrese las coordenadas del casillero que desea anular: ";

		cout<<"Columna: ";
		cin>>cadenaColumna;

		cout<<"Fila: ";
		cin>>cadenaFila;

		cout<<"Profundidad: ";
		cin>>cadenaProfundidad;

		if(esUnNumero(cadenaColumna) && esUnNumero(cadenaFila) && esUnNumero(cadenaProfundidad)){
			int columna = atoi(cadenaColumna.c_str());
			int fila = atoi(cadenaFila.c_str());
			int profundidad = atoi(cadenaProfundidad.c_str());

			if(validarCoordenadas(tablero, columna, fila, profundidad)){
				if(tablero->casilleroEstaVacio(profundidad, fila, columna)){
					tablero->getCasilla(columna, fila, profundidad)->deshabilitar();
					listo = true;
				}

				else{
					cout<<"No se puede anular este casillero"<<endl;
				}
			}

			else{
				cout<<"Coordenadas invalidas"<<endl;
			}
		}

		else{
			cout<<"No se ha ingresado un numero valido"<<endl;
		}
	}
}


void Carta::moverFicha(Tablero *tablero, Cola<Jugador*> *jugadores){
	bool listo = false;
	char ficha = jugadores->front()->obtenerFicha();

	while(!listo){
		string cadenaColumna, cadenaFila, cadenaProfundidad;
		string cadenaColumnaAMover, cadenaFilaAMover, cadenaProfundidadAMover;

		cout<<"Ingrese las coordenadas de la ficha que desea mover: "<<endl;
		cout<<"Columna: ";
		cin>>cadenaColumna;

		cout<<"Fila: ";
		cin>>cadenaFila;

		cout<<"Profundidad: ";
		cin>>cadenaProfundidad;

		cout<<"Ingrese la coordenada a la que desea mover la ficha: "<<endl;

		cout<<"Columna: ";
		cin>>cadenaColumnaAMover;

		cout<<"Fila: ";
		cin>>cadenaFilaAMover;

		cout<<"Profundidad: ";
		cin>>cadenaProfundidadAMover;

		if(esUnNumero(cadenaColumna) && esUnNumero(cadenaFila) && esUnNumero(cadenaProfundidad) &&
				esUnNumero(cadenaColumnaAMover) && esUnNumero(cadenaFilaAMover) && esUnNumero(cadenaProfundidadAMover)){

			int columna = atoi(cadenaColumna.c_str());
			int fila = atoi(cadenaFila.c_str());
			int profundidad = atoi(cadenaProfundidad.c_str());

			int columnaAMover = atoi(cadenaColumnaAMover.c_str());
			int filaAMover = atoi(cadenaFilaAMover.c_str());
			int profundidadAMover = atoi(cadenaProfundidadAMover.c_str());


			if(validarCoordenadas(tablero, columna, fila, profundidad) &&
					validarCoordenadas(tablero, columnaAMover, filaAMover, profundidadAMover)){


				if(tablero->getCasilla(profundidad, fila, columna)->mostrarFicha() == ficha &&
						tablero->casilleroEstaVacio(profundidadAMover, filaAMover, columnaAMover)
						&& tablero->getCasilla(profundidadAMover, filaAMover, columnaAMover)->estaDisponible()){
					tablero->setCasilla(profundidad, fila, columna, ' ');
					tablero->setCasilla(profundidadAMover, filaAMover, columnaAMover, ficha);
					listo = true;
				}

				else{
					cout<<"Movimiento invalido"<<endl;
				}
			}

			else{
				cout<<"Coordenadas invalidas"<<endl;
			}
		}

		else{
			cout<<"No se ha ingresado un numero valido"<<endl;
		}
	}
}

void Carta::utilizarCarta(Tablero *tablero, Cola<Jugador*> *jugadores){
	switch(this->numero % 6){
	case 0:
		this->jugadorPierdeUnTurno(tablero, jugadores);
		break;

	case 1:
		this->bloquearFicha(tablero, jugadores);
		break;

	case 2:
		this->anularCasillero(tablero, jugadores);
		break;

	case 3:
		this->moverFicha(tablero, jugadores);
		break;

	default:
		cout<<"Se utilizo la carta"<<endl<<endl;
		break;
	}
}

TATETI::TATETI(){
	    this->cantidadDeJugadores = 0;

		this->cantidadMaximaCartasPorJugador = CARTAS_MAXIMAS_POR_JUGADOR ;

	    this->tablero = NULL;

	    this->jugadores = new Cola<Jugador*>;

	    this->cartas = new Cola<Carta*>;

	    this->cantidadDeFichasPorJugador = 0;

	    this->nombreDelArchivoBMP = "";

	    this->cartasJugadores = new Cola<Lista<Carta*>*>;

}

TATETI::~TATETI(){
	delete this->tablero;
	// vamos borrando los punteros a jugador de las colas jugadores y desencola todos los nodos de la cola 
	while(this->jugadores->front() != NULL){
		delete this->jugadores->front();
		this->jugadores->desacolar();
	}
	// borramos todos los punteros a carta y desacolamos los nodos de la cola de cartas 
	while(this->cartas->front() != NULL){
		delete this->cartas->front();
		this->cartas->desacolar();
	}
	// borramos los punteros a a cartas y las listas de cartas que hay dentor de la cola cartasJugadores
	while(this->cartasJugadores->front() != NULL){
		Lista<Carta*>* listaCartas = this->cartasJugadores->front();
		listaCartas->reiniciarCursor();
		while(listaCartas->avanzarCursor()){
			delete listaCartas->getCursor();
		}
		delete listaCartas;
	}
}
int TATETI::getCantidadDeFichasPorJugador(){
	return this->cantidadDeFichasPorJugador;
}

void TATETI::imprimirTableros(){
	this->tablero->mostrarTableroPorCapas();
}

void TATETI::iniciarJuego(){
	this->mostrarBienvenida();

	cout<<"\n";

	this->pedirDimensionesDelTablero();

	cout<<"\n";

	this->inicializarJugadores();

	cout<<"\n";

	this->pedirNombreDelArchivoBMP();

	this->crearCartas();

}

void TATETI::mostrarBienvenida(){
	cout<<"\t\t\t\t.:: Tateti ::."<<endl;

}

bool esUnNumero1(string cadena){
	for(unsigned int i = 0; i < cadena.length(); i++){
		if(!isdigit(cadena[i])){
			return false;
		}
	}

	return true;
}


void TATETI::pedirDimensionesDelTablero(){
    cout<<"Ingrese las dimensiones del tablero: "<<endl;
    string dimension;

    int contadorDeDimensiones = 0, numeroDeColumnas, numeroDeFilas, profundidad;
    int cantFichasPorJugador = 0;

    while(contadorDeDimensiones < 3){
        switch(contadorDeDimensiones){
        case 0:
            cout<<"Ingrese el numero de columnas del tablero: ";
            cin>>dimension;

            if(esUnNumero1(dimension)){
                numeroDeColumnas = atoi(dimension.c_str());
                contadorDeDimensiones++;
            }
            else{
                cout<<"No se ha ingresado un numero valido."<<endl;
            }
            break;

        case 1:
            cout<<"Ingrese el numero de filas del tablero: ";
            cin>>dimension;

            if(esUnNumero1(dimension)){
                numeroDeFilas = atoi(dimension.c_str());
                contadorDeDimensiones++;
            }
            else{
                cout<<"No se ha ingresado un numero valido."<<endl;
            }
            break;

        case 2:
            cout<<"Ingrese la profundidad del tablero: ";
            cin>>dimension;

            if(esUnNumero1(dimension)){
                profundidad = atoi(dimension.c_str());
                contadorDeDimensiones++;
            }
            else{
                cout<<"No se ha ingresado un numero valido."<<endl;
            }
            break;
        }
    }

    while(cantFichasPorJugador == 0){
        cout << "Ingrese la cantidad de fichas por jugador: ";
        cin >> cantFichasPorJugador;
    }

    this->cantidadDeFichasPorJugador = cantFichasPorJugador;
    this->tablero = new Tablero(profundidad, numeroDeFilas, numeroDeColumnas);
}

void TATETI::inicializarJugadores(){
	string cadena;
	bool seIngresoUnNumero = false;
	while(!seIngresoUnNumero){
		cout<<"Ingrese la cantidad de jugadores: ";
		cin>>cadena;

		if(esUnNumero1(cadena)){
			this->cantidadDeJugadores = atoi(cadena.c_str());
			seIngresoUnNumero = true;
		}
		else{
			cout<<"Entrada no valida\n"<<endl;
		}
	}

	int contador = 1;

	while(contador <= this->cantidadDeJugadores){
		cout<<"\nJugador "<<contador<<endl;
		cout<<"Ingrese el nombre del jugador: ";
		cin>>cadena;

		char ficha;
		cout<<"Ingrese la ficha del jugador: ";
		cin>>ficha;

		Jugador *jugadorActual = new Jugador(cadena, ficha);
		this->jugadores->acolar(jugadorActual);

		Lista<Carta*> *cartas = new Lista<Carta*>;
		this->cartasJugadores->acolar(cartas);

		cout<<"Se genero la lista de cartas de: "<<cadena<<endl;
		contador++;
	}

}

void TATETI::pedirNombreDelArchivoBMP(){
	cout<<"Ingrese el nombre del archivo BMP o la ruta donde desea guardar los archivos BMP(no agregar extension): ";
	cin>>this->nombreDelArchivoBMP;
}

void TATETI::crearCartas(){
	int contadorCartasEmitidas = 1;

	while(contadorCartasEmitidas <= this->cantidadDeJugadores * 2){
		// se agrega una instancia de carta con un numero en el rango de cartas disponibles 
		this->cartas->acolar(new Carta(rand() % 6));
		contadorCartasEmitidas++;
	}
}

void TATETI::repartirCartas(){
	Lista<Carta*> *cartasJugadorActual = this->cartasJugadores->front();

	if(cartasJugadorActual->contarElementos() < this->cantidadMaximaCartasPorJugador){
		Carta *carta = this->cartas->front();
		cartasJugadorActual->add(carta);
		this->cartas->desacolar();
		this->cartas->acolar(carta);
	}

}

void TATETI::mostrarCartas(Lista<Carta*> *cartas){
	int contador = 1;
	cartas->reiniciarCursor();
	while(cartas->avanzarCursor()){
		Carta *cartaActual = cartas->getCursor();
		cout<<contador<<": "<<cartaActual->obtenerDescripcion()<<endl;
		contador++;
	}
}

void TATETI::jugarPartida(){

	if(this->insertarFichas()){
		cout<<"Estado final del tablero: "<<endl<<endl;
		this->imprimirTableros();
		cout<<endl;
		this->tablero->generarBitMap("Tablero_final.bmp");
		return;
	}

	this->moverFichas();

	cout<<"Estado final del tablero: "<<endl<<endl;
	this->imprimirTableros();
	cout<<endl;

	this->tablero->generarBitMap("Tablero_final.bmp");
}

void intToString(int n, char cadena[]){
	int nroDig = 0;
	int aux = n;

	while(aux>0){
		aux = aux/10;
		nroDig++;
	}

	cadena[nroDig] = '\0';

	aux = n;
	int pos = nroDig-1, dig;

	while(pos >= 0){
		dig = aux % 10;
		aux = aux/10;
		cadena[pos] = dig + '0';
		pos--;
	}
}

bool TATETI::utilizarCarta(Lista<Carta*> *cartas){
	if(cartas->vacia()){
		return false;
	}

	cout<<"Cartas disponibles: "<<endl;
	this->mostrarCartas(cartas);

	char opcion;
	bool listo = false;

	while(!listo){
		cout<<"\nDesea utilizar una carta [Y/N]";
		cin>>opcion;

		if(opcion == 'N' || opcion == 'n'){
			return false;
		}

		else if(opcion == 'Y' || opcion == 'y'){
			string numeroDeCarta;
			cout<<"Ingrese el numero de la carta que desea utilizar: ";
			cin>>numeroDeCarta;

			if(esUnNumero(numeroDeCarta)){
				int numero = atoi(numeroDeCarta.c_str());

				if(numero > 0 && numero <= cartas->contarElementos()){
					cartas->get(numero)->utilizarCarta(this->tablero, this->jugadores);
					cartas->remover(numero);
					listo = true;
				}

				else{
					cout<<"No se ingreso un numero valido"<<endl;
				}
			}

			else{
				cout<<"No se ingreso un numero valido"<<endl;
			}
		}

		else{
			cout<<"No se ingreso una opcion correcta"<<endl;
		}
	}
	return true;
}

bool TATETI::insertarFichas(){
	int contador = 0;
	string cadenaColumna, cadenaFila, cadenaProfundidad;
	bool finalizoLaPartida = false;

	while(contador < this->cantidadDeFichasPorJugador * this->cantidadDeJugadores
			&& !finalizoLaPartida){
		Jugador *jugadorActual = this->jugadores->front();
		Lista<Carta*> *cartasJugadorActual = this->cartasJugadores->front();

		string nombreDelArchivoBMP = this->nombreDelArchivoBMP;
		char numero[3];

		intToString(contador, numero);
		nombreDelArchivoBMP += numero;
		nombreDelArchivoBMP += ".bmp";

		cout<<"\nTurno de: "<<jugadorActual->obtenerNombre()<<endl;
		cout<<"Ingresar coordenadas: "<<endl;

		cout<<"Columna: ";
		cin>>cadenaColumna;

		cout<<"Fila: ";
		cin>>cadenaFila;

		cout<<"Profundidad: ";
		cin>>cadenaProfundidad;

		if(esUnNumero1(cadenaColumna) ||
				esUnNumero1(cadenaFila) ||
				esUnNumero1(cadenaProfundidad)){

			int columna = atoi(cadenaColumna.c_str());
			int fila = atoi(cadenaFila.c_str());
			int profundidad = atoi(cadenaProfundidad.c_str());

			if(validarCoordenadas(columna,fila,profundidad)){
				if(this->tablero->casilleroEstaVacio(profundidad, fila, columna)
						&& this->tablero->getCasilla(profundidad, fila, columna)->estaDisponible()){

					this->tablero->getCasilla(profundidad, fila, columna)->setFicha(jugadorActual->obtenerFicha());

					if(tablero->hayTateti(tablero->getCasilla(profundidad, fila, columna),this->getCantidadDeFichasPorJugador())){
						cout<<jugadorActual->obtenerNombre()<<" gano la partida"<<endl;
						jugadorActual->ganoLaPartida();
						finalizoLaPartida = true;
					}

					this->repartirCartas();
					jugadores->desacolar();
					jugadores->acolar(jugadorActual);
					cout<<endl;
					this->imprimirTableros();
					cout<<endl;
					contador++;

					this->utilizarCarta(cartasJugadorActual);
					this->cartasJugadores->desacolar();
					this->cartasJugadores->acolar(cartasJugadorActual);
					this->tablero->generarBitMap(nombreDelArchivoBMP);
				}

				else{
					cout<<"El casillero no esta vacio"<<endl;
				}
			}
			else{
				cout<<"Coordenadas invalidas"<<endl;
			}
		}

		else{
			cout<<"No se ha ingresado un numero"<<endl;
		}
	}

	return finalizoLaPartida;
}

bool TATETI::pedirDireccionAMover(int columna, int fila, int profundidad){
	bool listo = false;
	char entrada;

	while(!listo){
		char ficha = this->jugadores->front()->obtenerFicha();

		cout<<"\nIngrese la direccion a la que quiere mover la ficha: "<<endl;
		cout<<"[W/w]:arriba, [A/a]:izquierda, [S/s]: abajo, [D/d]: derecha, [F/f]: al frente, [B/b]: atras"<<endl;
		cin>>entrada;

		switch(entrada){
		case 'W':case 'w':
			if(fila-1 != 0){
				if(tablero->casilleroEstaVacio(profundidad, fila-1, columna)
						&& tablero->getCasilla(profundidad, fila-1, columna)->estaDisponible()){
					tablero->getCasilla(profundidad, fila, columna)->setFicha(' ');
					tablero->getCasilla(profundidad, fila-1, columna)->setFicha(ficha);

					if(tablero->hayTateti(tablero->getCasilla(profundidad, fila-1, columna), this->getCantidadDeFichasPorJugador())){
						return true;
					}

					listo = true;

				}

				else{
					cout<<"Movimiento invalido"<<endl;
				}
			}

			else{
				cout<<"Movimiento invalido"<<endl;
			}

			break;

		case 'A' :case 'a':
			if(columna-1 != 0){
				if(tablero->casilleroEstaVacio(profundidad, fila, columna-1)
						&& tablero->getCasilla(profundidad, fila, columna-1)->estaDisponible()){
					tablero->getCasilla(profundidad, fila, columna)->setFicha(' ');
					tablero->getCasilla(profundidad, fila, columna-1)->setFicha(ficha);

					if(tablero->hayTateti(tablero->getCasilla(profundidad, fila, columna-1), this->getCantidadDeFichasPorJugador())){
						return true;
					}

					listo = true;
				}

				else{
					cout<<"Movimiento invalido"<<endl;
				}

			}

			else{
				cout<<"Movimiento invalido"<<endl;
			}

			break;

		case 'S':case 's':
			if(fila+1 <= tablero->getAltura()){
				if(tablero->casilleroEstaVacio(profundidad, fila+1, columna)
						&& tablero->getCasilla(profundidad, fila+1, columna)->estaDisponible()){
					tablero->getCasilla(profundidad, fila, columna)->setFicha(' ');
					tablero->getCasilla(profundidad, fila+1, columna)->setFicha(ficha);

					if(tablero->hayTateti(tablero->getCasilla(profundidad, fila+1, columna), this->getCantidadDeFichasPorJugador())){
						return true;
					}

					listo = true;
				}

				else{
					cout<<"Movimiento invalido"<<endl;
				}
			}

			else{
				cout<<"Movimiento invalido"<<endl;
			}

			break;

		case 'D':case 'd':
			if(columna+1 <= tablero->getAncho()){
				if(tablero->casilleroEstaVacio(profundidad, fila, columna+1)
						&& tablero->getCasilla(profundidad, fila, columna+1)->estaDisponible()){
					tablero->getCasilla(profundidad, fila, columna)->setFicha(' ');
					tablero->getCasilla(profundidad, fila, columna+1)->setFicha(ficha);

					if(tablero->hayTateti(tablero->getCasilla(profundidad, fila, columna+1), this->getCantidadDeFichasPorJugador())){
						return true;
					}

					listo = true;
				}

				else{
					cout<<"Movimiento invalido"<<endl;
				}
			}

			else{
				cout<<"Movimiento invalido"<<endl;
			}

			break;

		case 'F': case 'f':
			if(profundidad-1 != 0){
				if(tablero->casilleroEstaVacio(profundidad-1, fila, columna)
						&& tablero->getCasilla(profundidad-1, fila, columna)->estaDisponible()){
					tablero->getCasilla(profundidad, fila, columna)->setFicha(' ');
					tablero->getCasilla(profundidad-1, fila, columna)->setFicha(ficha);

					if(tablero->hayTateti(tablero->getCasilla(profundidad-1, fila, columna), this->getCantidadDeFichasPorJugador())){
						return true;
					}

					listo = true;
				}

				else{
					cout<<"Movimiento invalido"<<endl;
				}
			}

			else{
				cout<<"Movimiento invalido"<<endl;
			}

			break;

		case 'B': case 'b':
			if(profundidad+1 <= tablero->getProfundidad()){
				if(tablero->casilleroEstaVacio(profundidad+1, fila, columna)
						&& tablero->getCasilla(profundidad+1, fila, columna)->estaDisponible()){
					tablero->getCasilla(profundidad, fila, columna)->setFicha(' ');
					tablero->getCasilla(profundidad+1, fila, columna)->setFicha(ficha);

					if(tablero->hayTateti(tablero->getCasilla(profundidad+1, fila, columna), this->getCantidadDeFichasPorJugador())){
						return true;
					}

					listo = true;
				}
				else{
					cout<<"Movimiento invalido"<<endl;
				}
			}

			else{
				cout<<"Movimiento invalido"<<endl;
			}

			break;

		default:
			cout<<"Entrada no valida"<<endl;
			break;
		}

	}

	return false;
}


void TATETI::moverFichas(){
	bool finalizoLaPartida = false;

	int contador = this->cantidadDeFichasPorJugador * this->cantidadDeJugadores;
	while(!finalizoLaPartida){
		string cadenaColumna, cadenaFila, cadenaProfundidad;

		Jugador* jugadorActual = jugadores->front();
		Lista<Carta*> *cartasJugadorActual = this->cartasJugadores->front();

		string nombreDelArchivoBMP = this->nombreDelArchivoBMP;

		char numero[5];

		intToString(contador, numero);

		nombreDelArchivoBMP += numero;
		nombreDelArchivoBMP += ".bmp";

		cout<<"Turno de "<<jugadorActual->obtenerNombre()<<endl;

		cout<<"Ingrese las coordenadas de la ficha que desea mover: "<<endl;
		cout<<"Columna: ";
		cin>>cadenaColumna;

		cout<<"Fila: ";
		cin>>cadenaFila;

		cout<<"Profundidad: ";
		cin>>cadenaProfundidad;

		if(esUnNumero1(cadenaColumna) && esUnNumero1(cadenaFila) && esUnNumero1(cadenaProfundidad)){

			int columna = atoi(cadenaColumna.c_str());
			int fila = atoi(cadenaFila.c_str());
			int profundidad = atoi(cadenaProfundidad.c_str());

			if(this->validarCoordenadas(columna, fila, profundidad)){

				char ficha = jugadorActual->obtenerFicha();
				if(tablero->getCasilla(profundidad, fila, columna)->mostrarFicha() == ficha){
					if(this->pedirDireccionAMover(columna, fila, profundidad)){
						cout<<jugadorActual->obtenerNombre()<<" gano la partida"<<endl;
						jugadorActual->ganoLaPartida();
						finalizoLaPartida = true;
					}

					this->repartirCartas();
					jugadores->desacolar();
					jugadores->acolar(jugadorActual);
					cout<<endl;
					this->imprimirTableros();

					this->utilizarCarta(cartasJugadorActual);
					this->tablero->generarBitMap(nombreDelArchivoBMP);
					this->cartasJugadores->desacolar();
					this->cartasJugadores->acolar(cartasJugadorActual);
					cout<<endl;
					contador++;
				}

				else{
					cout<<"La ficha indicada no pertenece a "<<jugadorActual->obtenerNombre()<<endl;
				}
			}

			else{
				cout<<"Coordenadas invalidas"<<endl;
			}
		}

		else{
			cout<<"No se ha ingresado un numero valido"<<endl;
		}
	}
}


bool TATETI::validarCoordenadas(int columna, int fila, int profundidad){
	if(columna > 0 && columna <= this->tablero->getAncho() &&
			fila > 0 && fila <= this->tablero->getAltura() &&
			profundidad > 0 && profundidad <= this->tablero->getProfundidad()){
		return true;
	}
	else{
		return false;
	}
}

void TATETI::mostrarScore(){
	cout<<"\t\t\t\t.:: SCORE ::."<<endl;

	int contador = 0;

	while(contador < this->cantidadDeJugadores){
		Jugador *jugador = this->jugadores->front();

		cout<<jugador->obtenerNombre()<<": "<<jugador->obtenerCantidadDePartidasGanadas()<<endl;

		jugadores->desacolar();
		jugadores->acolar(jugador);
		contador++;
	}
}