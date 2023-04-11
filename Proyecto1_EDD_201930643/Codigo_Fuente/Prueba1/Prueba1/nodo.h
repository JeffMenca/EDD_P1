#ifndef NODO_H
#define NODO_H

#include "Cancion.h"

class Nodo {
private:
    Cancion cancion;
    Nodo* anterior;
    Nodo* siguiente;

public:
    Nodo(const Cancion& cancion, Nodo* anterior = nullptr, Nodo* siguiente = nullptr);
    Cancion getCancion() const;
    Nodo* getAnterior() const;
    Nodo* getSiguiente() const;
    void setAnterior(Nodo* anterior);
    void setSiguiente(Nodo* siguiente);
};

#endif // NODO_H
