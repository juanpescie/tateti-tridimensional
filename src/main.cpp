#include <iostream>

#include "TATETI.h"

using namespace std;

int main(){
	TATETI *tateti = new TATETI;

	tateti->iniciarJuego();

	bool finalizarJuego = false;

	while(!finalizarJuego){
		cout<<"\n[J/j]: iniciar partida"<<endl;
		cout<<"[M/m]: mostrar marcador"<<endl;
		cout<<"[S/s]: salir"<<endl;

		char opcion;
		cin>>opcion;

		switch(opcion){
		case 'J':case 'j':
			tateti->jugarPartida();
			break;

		case 'M':case 'm':
			tateti->mostrarScore();
			break;

		case 'S':case 's':
			finalizarJuego = true;
			break;
		}
	}

	return 0;
}