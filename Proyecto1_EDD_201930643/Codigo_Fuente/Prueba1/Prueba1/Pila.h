#ifndef PILA_H
#define PILA_H

#include <string>
#include <iostream>
#include "Cancion.h"

using namespace std;

class Pila
{
	static const int MAX = 100;
	Cancion arr[MAX]; // Arreglo que almacenará los elementos de la pila
	int top;          // Índice que apunta al tope de la pila

public:
    Pila();
    void push(Cancion cancion);
    void pushPos(Cancion cancion, int pos);
    void pop();
    Cancion Top();
    bool estaVacia();
    int buscarPorNombre(string nombre);
    Cancion buscarPorId(int id);
    void eliminarPorNombre(string nombre);
    void eliminarPorId(int id);
    void listar();
};

#endif