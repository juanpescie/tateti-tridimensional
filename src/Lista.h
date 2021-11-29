#ifndef LISTA_H_
#define LISTA_H_

#ifndef NULL
#define NULL 0
#endif

#include "Nodo.h"
#include <iostream>
using namespace std;

template<class T>
class Lista{
private:
	Nodo<T>* primero;
	unsigned int tamanio;
	Nodo<T>* cursor;
public:
	Lista();
	Lista(Lista<T> &otraLista);
	bool vacia()const;
	unsigned int contarElementos()const;
	void add(T elemento);
	void add(T elemento, unsigned int posicion);
	void add(Lista<T> &otraLista);
	T get(unsigned int posicion);
	void asignar(T elemento, unsigned int posicion);
	void remover(unsigned int posicion);
	void reiniciarCursor();
	bool avanzarCursor();
	T getCursor()const;
	void mostrarElementos();
	bool buscarElemento(T elemento);
	~Lista();
private:
	Nodo<T>* getNodo(unsigned int posicion)const;
};

template <class T>
Lista<T>::Lista(){
	this->primero = NULL;
	this->tamanio = 0;
	this->cursor = NULL;
}

template <class T>
Lista<T>::Lista(Lista<T> &otraLista){
	this->primero = NULL;
	this->tamanio = 0;
	this->cursor = NULL;
	this->add(otraLista);
}

template <class T>
bool Lista<T>::vacia()const{
	return (this->tamanio == 0);
}

template <class T>
unsigned int Lista<T>::contarElementos()const{
	return this->tamanio;
}

template <class T>
void Lista<T>::add(T elemento){
	this->add(elemento, this->tamanio + 1);
}

template <class T>
void Lista<T>::add(T elemento, unsigned int posicion){
	if((posicion > 0) && (posicion <= this->tamanio + 1)){
		Nodo<T>* nuevo = new Nodo<T>(elemento);
		if(posicion == 1){
			nuevo->setSiguiente(this->primero);
			this->primero = nuevo;
		}

		else{
			Nodo<T>* nodoAnterior = this->getNodo(posicion - 1);
			nuevo->setSiguiente(nodoAnterior->getSiguiente());
			nodoAnterior->setSiguiente(nuevo);
		}

		this->tamanio++;
		this->reiniciarCursor();
	}
}

template <class T>
void Lista<T>::add(Lista<T> &otraLista){
	otraLista.reiniciarCursor();

	while(otraLista.avanzarCursor()){
		this->add(otraLista.getCursor());
	}
}

template <class T>
T Lista<T>::get(unsigned int posicion){
	if((posicion <= 0) || (posicion > this->tamanio)){
		throw "Posicion Invalida";
	}

	return this->getNodo(posicion)->getDato();
}

template <class T>
void Lista<T>::asignar(T elemento, unsigned int posicion){
	if((posicion <= 0) || (posicion > this->tamanio)){
		throw "Posicion invalida";
	}

	this->getNodo(posicion)->setDato(elemento);
}

template <class T>
void Lista<T>::remover(unsigned int posicion){
	if((posicion > 0) && (posicion <= this->tamanio)){
		Nodo<T> *nodoARemover;

		if(posicion == 1){
			nodoARemover = this->primero;
			this->primero->setSiguiente(nodoARemover->getSiguiente());
		}

		else{
			Nodo<T> *anterior = this->getNodo(posicion - 1);
			nodoARemover = anterior->getSiguiente();
			anterior->setSiguiente(nodoARemover->getSiguiente());
		}

		delete nodoARemover;
		this->tamanio--;
		this->reiniciarCursor();
	}
}

template <class T>
void Lista<T>::reiniciarCursor(){
	this->cursor = NULL;
}

template <class T>
bool Lista<T>::avanzarCursor(){
	if(this->cursor == NULL){
		this->cursor = this->primero;
	}

	else{
		this->cursor = this->cursor->getSiguiente();
	}

	return (this->cursor != NULL);
}

template <class T>
T Lista<T>::getCursor()const{
	if(this->cursor == NULL){
		throw "Accion invalida";
	}

	else{
		return this->cursor->getDato();
	}
}

template <class T>
Lista<T>::~Lista(){
	while(this->primero != NULL){
		Nodo<T> *nodoARemover = this->primero;
		this->primero->setSiguiente(nodoARemover->getSiguiente());
		delete nodoARemover;
	}

	cout<<"Se elimino la lista"<<endl;
}

template <class T>
Nodo<T>* Lista<T>::getNodo(unsigned int posicion)const{
	Nodo<T> *nodoABuscar = this->primero;

	for(unsigned int i=1; i < posicion; i++){
		nodoABuscar = nodoABuscar->getSiguiente();
	}

	return nodoABuscar;
}

template <class T>
void Lista<T>::mostrarElementos(){
	this->reiniciarCursor();

	while(this->avanzarCursor()){
		cout<<this->getCursor()<<endl;
	}
}

template <class T>
bool Lista<T>::buscarElemento(T elemento){
	this->reiniciarCursor();

	while(this->avanzarCursor()){
		if(this->getCursor() == elemento){
			return true;
		}
	}

	return false;
}

#endif /* LISTA_H_ */
