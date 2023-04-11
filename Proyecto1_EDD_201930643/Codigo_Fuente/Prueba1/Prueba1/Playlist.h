#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <iostream>
#include "ListaDoble.h"

using namespace std;

class Playlist
{
private:
	string nombre;
	string descripcion;

public:
	ListaDoble lista;
	Playlist();
	Playlist(string n, string d);

	string getNombre();
	string getDescripcion();
	void setNombre(string nuevoNombre);
	void setDescripcion(string nuevaDescripcion);
	void imprimirInfo();
	ListaDoble getLista();
};

#endif

