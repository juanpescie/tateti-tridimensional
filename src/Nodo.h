#ifndef NODO_H_
#define NODO_H_

#ifndef NULL
#define NULL 0
#endif

template <class T>
class Nodo{
private:
	T dato;
	Nodo<T> *sig;

public:
	Nodo(T dato);
	T getDato();
	Nodo<T> *getSiguiente();
	void setSiguiente(Nodo<T> *nodo);
	void setDato(T nuevo);
	bool haySiguiente();
};

template <class T>
Nodo<T>::Nodo(T dato){
	this->dato = dato;
	this->sig = NULL;
}

template <class T>
T Nodo<T>::getDato(){
	return this->dato;
}

template <class T>
Nodo<T> *Nodo<T>::getSiguiente(){
	return this->sig;
}

template <class T>
void Nodo<T>::setSiguiente(Nodo<T> *nodo){
	this->sig = nodo;
}

template <class T>
void Nodo<T>::setDato(T nuevo){
	this->dato = nuevo;
}

template <class T>
bool Nodo<T>::haySiguiente(){
	return (this->sig != NULL);
}




#endif /* NODO_H_ */
