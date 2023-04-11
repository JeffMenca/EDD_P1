#ifndef PILAPLAY_H
#define PILAPLAY_H

#include <string>
#include <iostream>
#include "Playlist.h"

using namespace std;

class PilaPlay
{
    static const int MAX = 100;
    Playlist arr[MAX]; // Arreglo que almacenará los elementos de la pila
    int top;          // Índice que apunta al tope de la pila

public:
    PilaPlay();
    int push(Playlist playlist);
    void pop();
    Playlist Top();
    bool estaVacia();
    int buscarPorNombre(string nombre);
    void agregarCancionPlaylist(int id, Cancion c);
    int actualizarPorId(int id);
    void eliminarCancionPlaylist(int idPlay, int idCancion);
    void listarCancionPlaylist(int id);
    void eliminarPorId(int id);
    void eliminarPorNombre(string nombre);
    void reproducirNormal(int id);
    void reproducirRepetir(int id);
    void listar();
};

#endif