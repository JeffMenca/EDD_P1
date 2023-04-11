#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "Nodo.h"

class ListaDoble {
private:
    Nodo* cabeza;
    Nodo* cola;

public:
    ListaDoble();
    ~ListaDoble();
    bool estaVacia() const;
    void insertarAlInicio(const Cancion& cancion);
    void insertarAlFinal(const Cancion& cancion);
    void eliminarPorPosicion(int posicion);
    void eliminarAlInicio();
    void reproducirNormal() const;
    void reproducirRepetir() const;
    void eliminarAlFinal();
    void imprimirAdelante() const;
    void imprimirAtras() const;
};

#endif // LISTADOBLE_H
