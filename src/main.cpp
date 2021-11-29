#include <iostream>

#include "TATETI.h"

using namespace std;

const int dimension = 3;

int main(){
	TATETI *tateti = new TATETI(dimension, dimension, dimension);

	tateti->imprimirTableros();

	delete tateti;

	return 0;
}
