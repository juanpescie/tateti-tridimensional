#ifndef COLA_H_
#define COLA_H_

#include <iostream>

#include "Nodo.h"

#ifndef NULL
#define NULL 0
#endif

template <class T>
class Cola{
private:
	Nodo<T> *cola;

public:
	Cola();
	void acolar(T elemento);
	void desacolar();
	T front();
	~Cola();
};

template <class T>
Cola<T>::Cola(){
	this->cola = NULL;
}


template <class T>
void Cola<T>::acolar(T elemento){
	if(this->cola == NULL){
		this->cola = new Nodo<T>(elemento);
	}

	else{
		Nodo<T> *aux = this->cola;
		bool listo = false;

		while(!listo){
			if(aux->getSiguiente() == NULL){
				aux->setSiguiente(new Nodo<T>(elemento));
				listo = true;
			}
			else{
				aux = aux->getSiguiente();
			}
		}
	}
}

template <class T>
void Cola<T>::desacolar(){
	Nodo<T> *nodoARemover = this->cola;

	this->cola = this->cola->getSiguiente();

	delete nodoARemover;
}

template <class T>
T Cola<T>::front(){
	if(this->cola == NULL){
		std::cout<<"Cola vacia"<<std::endl;
		throw "Cola vacia";
	}

	else{
		return this->cola->getDato();
	}
}

template <class T>
Cola<T>::~Cola(){
	Nodo<T> *aux = NULL;
	while(this->cola){
		aux = this->cola;
		this->cola = aux->getSiguiente();
		delete aux;
	}
	std::cout<<"Se elimino la cola"<<std::endl;
}

#endif /* COLA_H_ */
