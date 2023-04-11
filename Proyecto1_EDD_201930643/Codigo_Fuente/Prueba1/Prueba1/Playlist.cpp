#include "Playlist.h"
#include "ListaDoble.h"

Playlist::Playlist()
{
    nombre = "";
    descripcion = "";
}

Playlist::Playlist(string n, string d)
{
    nombre = n;
    descripcion = d;
}

string Playlist::getNombre()
{
    return nombre;
}

string Playlist::getDescripcion()
{
    return descripcion;
}

void Playlist::setNombre(string nuevoNombre)
{
    if (nuevoNombre != "") {
        nombre = nuevoNombre;
    }
}

void Playlist::setDescripcion(string nuevaDescripcion)
{
    if (nuevaDescripcion != "") {
        descripcion = nuevaDescripcion;
    }
}


ListaDoble Playlist::getLista()
{
    return lista;
}

void Playlist::imprimirInfo()
{
    cout << "\033[32mNombre:\033[0m " << nombre << endl;
    cout << "\033[32mDescripcion:\033[0m " << descripcion << endl;
}
