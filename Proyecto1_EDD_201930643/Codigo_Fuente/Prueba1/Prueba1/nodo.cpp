#include "Nodo.h"

Nodo::Nodo(const Cancion& cancion, Nodo* anterior, Nodo* siguiente) :
	cancion(cancion), anterior(anterior), siguiente(siguiente)
{
}

Cancion Nodo::getCancion() const
{
	return cancion;
}

Nodo* Nodo::getAnterior() const
{
	return anterior;
}

Nodo* Nodo::getSiguiente() const
{
	return siguiente;
}

void Nodo::setAnterior(Nodo* anterior)
{
	try
	{
		this->anterior = anterior;
	}
	catch (const std::exception&)
	{

	}
}

void Nodo::setSiguiente(Nodo* siguiente)
{
	this->siguiente = siguiente;
}
