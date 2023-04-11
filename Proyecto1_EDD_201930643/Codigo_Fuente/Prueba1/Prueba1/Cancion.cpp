#include "Cancion.h"

Cancion::Cancion()
{
    nombre = "";
    path = "";
}

Cancion::Cancion(string n, string p)
{
    nombre = n;
    path = p;
}

string Cancion::getNombre()
{
    return nombre;
}

string Cancion::getPath()
{
    return path;
}

void Cancion::imprimirInfo()
{
    cout << "\033[32mNombre:\033[0m " << nombre << endl;
    cout << "\033[32mPath:\033[0m " << path << endl;
}
