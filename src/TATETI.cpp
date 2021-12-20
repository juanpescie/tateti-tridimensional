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
	"Intercambiar dos fichas",
};
const int CARTAS_MAXIMAS_POR_JUGADOR = 3;

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

void Carta::jugadorPierdeUnTurno(Tablero *tablero, Cola<Turnos*> *turnos){
	Turnos *turnoActual = turnos->front();
	turnos->desacolar();
	turnos->acolar(turnoActual);

	turnoActual = turnos->front();

	cout<<turnoActual->getJugador()->obtenerNombre()<<" pierde un turno"<<endl;
}

void Carta::bloquearFicha(Tablero *tablero, Cola<Turnos*> *turnos){
	string cadenaColumna, cadenaFila, cadenaProfundidad;
	bool listo = false;

	char fichaJugadorActual = turnos->front()->getJugador()->obtenerFicha();

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

void Carta::anularCasillero(Tablero *tablero, Cola<Turnos*> *turnos){
	string cadenaColumna, cadenaFila, cadenaProfundidad;
	bool listo = false;

	while(!listo){
		cout<<"Ingrese las coordenadas del casillero que desea anular: "<<endl;

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
					tablero->getCasilla(profundidad, fila, columna)->setFicha('/');
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

void Carta::volverAtrasUnTurno(Tablero *tablero, Cola<Turnos*> *turnos){
	int ultimaColumna = tablero->getUltimaColumna();
	int ultimaFila = tablero->getUltimaFila();
	int ultimaProfundidad = tablero->getUltimaProfundidad();
	char ficha = turnos->front()->getJugador()->obtenerFicha();

	/*if(validarCoordenadas(tablero, ultimaProfundidad-1, ultimaFila, ultimaColumna) &&
			tablero->getCasilla(ultimaProfundidad-1, ultimaFila, ultimaColumna)->mostrarFichaAnterior() == ficha){

	}*/
}

void Carta::cambiarFichaDeLugar(Tablero *tablero, Cola<Turnos*> *turnos){
	bool listo = false;
	char ficha = turnos->front()->getJugador()->obtenerFicha();

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
					tablero->setUltimaPosicion(profundidadAMover, filaAMover, columnaAMover);
					cout<<"x ultima: "<<tablero->getUltimaColumna() <<endl;
					cout<<"y Ultima: "<<tablero->getUltimaFila() <<endl;
					cout<<"z ultima: "<<tablero->getUltimaProfundidad()<<endl;
					cout<<endl;
					cout<<"VECINOS"<<endl;
					tablero->getCasilla(profundidadAMover, filaAMover, columnaAMover)->mostrarVecinos();
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

void Carta::intercambiarFichasDeLugar(Tablero *tablero, Cola<Turnos*> *turnos){
	bool listo = false;
	char ficha = turnos->front()->getJugador()->obtenerFicha();

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
						!tablero->casilleroEstaVacio(profundidadAMover, filaAMover, columnaAMover)){
					char fichaACambiar = tablero->getCasilla(profundidadAMover, filaAMover, columnaAMover)->mostrarFicha();
					tablero->setCasilla(profundidad, fila, columna, fichaACambiar);
					tablero->setCasilla(profundidadAMover, filaAMover, columnaAMover, ficha);
					tablero->setUltimaPosicion(profundidadAMover, filaAMover, columnaAMover);
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

void Carta::utilizarCarta(Tablero *tablero, Cola<Turnos*> *turnos){
	switch(this->numero % 6){
	case 0:
		this->jugadorPierdeUnTurno(tablero, turnos);
		break;

	case 1:
		this->bloquearFicha(tablero, turnos);
		break;

	case 2:
		this->anularCasillero(tablero, turnos);
		break;

	case 3:
		this->volverAtrasUnTurno(tablero, turnos);
		break;

	case 4:
		this->cambiarFichaDeLugar(tablero, turnos);
		break;

	case 5:
		this->intercambiarFichasDeLugar(tablero, turnos);
		break;

	default:
		cout<<"Se utilizo la carta"<<endl<<endl;
		break;
	}

}


Turnos::Turnos(Jugador *jugador, Lista<Carta*> *cartasDelJugador){
	this->jugador = jugador;
	this->cartasDelJugador = cartasDelJugador;
}

Lista<Carta*> *Turnos::getCartasDelJugador(){
	return this->cartasDelJugador;
}

Jugador* Turnos::getJugador(){
	return this->jugador;
}


Turnos::~Turnos(){
	delete this-> jugador;
	this->cartasDelJugador->reiniciarCursor();
	while(this->cartasDelJugador->avanzarCursor()){
		Carta* carta = this->cartasDelJugador->getCursor();
		delete carta;
	}
	delete this->cartasDelJugador;
}


TATETI::TATETI(){
	    this->cantidadDeJugadores = 0;

	    this->tablero = NULL;

	    this->turnos = new Cola<Turnos*>;

	    this->cartas = new Cola<Carta*>;

	    this->cantidadDeFichasPorJugador = 0;

	    this->nombreDelArchivoBMP = "";
}

TATETI::~TATETI(){
	delete this->tablero;
	// vamos borrando los punteros a turnos de las colas jugadores y desencola todos los nodos de la cola 
	while(this->turnos->front() != NULL){
		delete this->turnos->front();
		this->turnos->desacolar();
	}
	// borramos todos los punteros a carta y desacolamos los nodos de la cola de cartas 
	while(this->cartas->front() != NULL){
		delete this->cartas->front();
		this->cartas->desacolar();
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

int TATETI::getCantidadMaximaCartasPorJugador(){
	return this->cantidadMaximaCartasPorJugador;
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
		Lista<Carta*> *cartas = new Lista<Carta*>;

		this->turnos->acolar(new Turnos(jugadorActual, cartas));

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
	Lista<Carta*> *cartasJugadorActual = this->turnos->front()->getCartasDelJugador();

	if(cartasJugadorActual->contarElementos() < 3){
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

void TATETI::utilizarCarta(){
	Lista<Carta*> *cartasJugadorActual = this->turnos->front()->getCartasDelJugador();
	if(cartasJugadorActual->vacia()){
		return ;
	}

	cout<<"Cartas disponibles: "<<endl;
	this->mostrarCartas(cartasJugadorActual);

	char opcion;
	bool listo = false;
	bool jugadorPierdeUnTurno;

	while(!listo){
		cout<<"\nDesea utilizar una carta [Y/N]";
		cin>>opcion;

		if(opcion == 'N' || opcion == 'n'){
			listo = true;
		}

		else if(opcion == 'Y' || opcion == 'y'){
			string numeroDeCarta;
			cout<<"Ingrese el numero de la carta que desea utilizar: ";
			cin>>numeroDeCarta;

			if(esUnNumero(numeroDeCarta)){
				int numero = atoi(numeroDeCarta.c_str());

				if(numero > 0 && numero <= (int)cartasJugadorActual->contarElementos()){
					cartasJugadorActual->get(numero)->utilizarCarta(this->tablero, this->turnos);
					cartasJugadorActual->remover(numero);
					cout<<endl;
					this->imprimirTableros();
					cout<<endl;
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

}

bool TATETI::insertarFichas(){
	int contador = 0;
	string cadenaColumna, cadenaFila, cadenaProfundidad;
	bool finalizoLaPartida = false;

	while(contador < this->cantidadDeFichasPorJugador * this->cantidadDeJugadores
			&& !finalizoLaPartida){
		Turnos *turnoActual = this->turnos->front();
		Jugador *jugadorActual = turnoActual->getJugador();
		Lista<Carta*> *cartasJugadorActual = turnoActual->getCartasDelJugador();

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
					this->tablero->setUltimaPosicion(profundidad, fila, columna);
					if(this->tablero->hayTateti(this->getCantidadDeFichasPorJugador())){
						cout<<jugadorActual->obtenerNombre()<<" gano la partida"<<endl;
						jugadorActual->ganoLaPartida();
						return true;
					}


					this->repartirCartas();
					cout<<endl;
					this->imprimirTableros();
					cout<<endl;
					if(!finalizoLaPartida){
						this->utilizarCarta();
						// se setea la ultima posicion en coordenadadas en utilizarCarta
						if(this->tablero->hayTateti(this->getCantidadDeFichasPorJugador())){
							cout<<jugadorActual->obtenerNombre()<<" gano la partida"<<endl;
							jugadorActual->ganoLaPartida();
							finalizoLaPartida = true;
						}
					}


					turnos->desacolar();
					turnos->acolar(turnoActual);
					contador++;
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
		char ficha = this->turnos->front()->getJugador()->obtenerFicha();

		cout<<"\nIngrese la direccion a la que quiere mover la ficha: "<<endl;
		cout<<"[W/w]:arriba, [A/a]:izquierda, [S/s]: abajo, [D/d]: derecha, [F/f]: al frente, [B/b]: atras, [P/p]: pasar "<<endl;
		cin>>entrada;

		switch(entrada){
			case 'P': case 'p':
			return true;
		case 'W':case 'w':
			if(fila-1 != 0){
				if(this->tablero->casilleroEstaVacio(profundidad, fila-1, columna)
						&& this->tablero->getCasilla(profundidad, fila-1, columna)->estaDisponible()){
					this->tablero->getCasilla(profundidad, fila, columna)->setFicha(' ');
					this->tablero->getCasilla(profundidad, fila-1, columna)->setFicha(ficha);
					this->tablero->setUltimaPosicion(profundidad, fila-1, columna);
					if(this->tablero->hayTateti(this->getCantidadDeFichasPorJugador())){
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
					this->tablero->setUltimaPosicion(profundidad, fila, columna-1);
					if(tablero->hayTateti( this->getCantidadDeFichasPorJugador())){
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
					this->tablero->setUltimaPosicion(profundidad, fila+1, columna);
					if(tablero->hayTateti( this->getCantidadDeFichasPorJugador())){
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
					this->tablero->setUltimaPosicion(profundidad, fila, columna+1);
					if(tablero->hayTateti(this->getCantidadDeFichasPorJugador())){
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
					this->tablero->setUltimaPosicion(profundidad - 1, fila, columna);
					if(tablero->hayTateti( this->getCantidadDeFichasPorJugador())){
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
					this->tablero->setUltimaPosicion(profundidad +1, fila, columna);
					if(tablero->hayTateti( this->getCantidadDeFichasPorJugador())){
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

		Turnos *turnoActual = this->turnos->front();
		Jugador* jugadorActual = turnoActual->getJugador();
		Lista<Carta*> *cartasJugadorActual = turnoActual->getCartasDelJugador();

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

			if(this->validarCoordenadas(columna, fila, profundidad) ){

				char ficha = jugadorActual->obtenerFicha();
				if((tablero->getCasilla(profundidad, fila, columna)->mostrarFicha() == ficha) && 
					(tablero->getCasilla(profundidad, fila, columna)->estaDisponible()) ){
					if(this->pedirDireccionAMover(columna, fila, profundidad)){
						cout<<jugadorActual->obtenerNombre()<<" gano la partida"<<endl;
						jugadorActual->ganoLaPartida();
						finalizoLaPartida = true;
					}

					this->repartirCartas();
					cout<<endl;
					this->imprimirTableros();
					cout<<endl;

					if(!finalizoLaPartida){
						this->utilizarCarta();
						// se setea la ultima posicion en coordenadadas en utilizarCarta
						if(this->tablero->hayTateti(this->getCantidadDeFichasPorJugador())){
							cout<<jugadorActual->obtenerNombre()<<" gano la partida"<<endl;
							jugadorActual->ganoLaPartida();
							finalizoLaPartida = true;
						}
					}

					this->turnos->desacolar();
					this->turnos->acolar(turnoActual);

				}

				else{
					cout<<"La ficha indicada no pertenece a "<<jugadorActual->obtenerNombre()<<"o esta bloqueado"<<endl;
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
		Turnos *turnoActual = this->turnos->front();
		Jugador *jugador = turnoActual->getJugador();

		cout<<jugador->obtenerNombre()<<": "<<jugador->obtenerCantidadDePartidasGanadas()<<endl;

		this->turnos->desacolar();
		this->turnos->acolar(turnoActual);
		contador++;
	}
}