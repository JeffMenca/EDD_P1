#ifndef CANCION_H
#define CANCION_H

#include <string>
#include <iostream>

using namespace std;

class Cancion
{
private:
	string nombre;
	string path;

public:
	Cancion();
	Cancion(string n, string p);

	string getNombre();
	string getPath();
	void imprimirInfo();
};

#endif

