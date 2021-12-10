#include <iostream>

#include "TATETI.h"

using namespace std;

int main(){
	TATETI *tateti = new TATETI;

	tateti->iniciarJuego();

	tateti->jugarPartida();

	tateti->mostrarScore();

	return 0;
}
