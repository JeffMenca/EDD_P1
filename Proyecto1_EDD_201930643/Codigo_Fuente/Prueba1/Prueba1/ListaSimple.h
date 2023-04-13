#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include "Cancion.h"

class Nodo {
public:
	Nodo(const Cancion& cancion, Nodo* siguiente = nullptr) :
		cancion(cancion), siguiente(siguiente) {}

	Cancion getCancion() const { return cancion; }
	Nodo* getSiguiente() const { return siguiente; }

	void setCancion(const Cancion& cancion) { this->cancion = cancion; }
	void setSiguiente(Nodo* siguiente) { this->siguiente = siguiente; }

private:
	Cancion cancion;
	Nodo* siguiente;
};

class ListaSimple {
public:
	ListaSimple();
	~ListaSimple();

	bool estaVacia() const;

	void insertarAlInicio(const Cancion& cancion);
	void insertarAlFinal(const Cancion& cancion);

	void eliminarPorPosicion(int posicion);
	void eliminarAlInicio();
	void eliminarAlFinal();

	void imprimirAdelante() const;

	void reproducirNormal() const;
	void reproducirRepetir() const;

private:
	Nodo* cabeza;
	Nodo* cola;
};

#endif // !LISTASIMPLE_H
