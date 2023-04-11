#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Playlist.h"
#include "PilaPlay.h"

using namespace std;

PilaPlay::PilaPlay()
{             // Constructor
	top = -1; // Inicializamos el tope de la PilaPlay en -1, ya que la PilaPlay est� vac�a
}

int PilaPlay::push(Playlist playlist)
{ // M�todo para insertar elementos en la PilaPlay
	if (top == MAX - 1)
	{ // Verificamos si la PilaPlay est� llena
		cout << "Error: la PilaPlay est� llena." << endl;
		return -1; // Retornamos un valor indicando que la operaci�n de inserci�n fall�
	}
	top++;              // Incrementamos el �ndice del tope de la PilaPlay
	arr[top] = playlist; // Insertamos el elemento en el tope de la PilaPlay
	return top; // Retornamos la posici�n o id en la que se insert� la Playlist
}


void PilaPlay::pop()
{ // M�todo para sacar elementos de la PilaPlay
	if (top == -1)
	{ // Verificamos si la PilaPlay est� vac�a
		cout << "Error: la PilaPlay est� vac�a." << endl;
		return;
	}
	top--; // Decrementamos el �ndice del tope de la PilaPlay
}

bool PilaPlay::estaVacia()
{ // Regresa si esta vacia la PilaPlay
	return (top < 0);
}

Playlist PilaPlay::Top()
{ // M�todo para obtener el elemento en el tope de la PilaPlay
	return arr[top];
}

int PilaPlay::buscarPorNombre(string nombre)
{ // M�todo para buscar una Playlist por nombre
	for (int i = top; i >= 0; i--)
	{ // Recorremos la PilaPlay desde el tope hasta el fondo
		if (arr[i].getNombre() == nombre)
		{ // Si encontramos la Playlist con el nombre dado
			cout << "\033[1;32mResultado: \033[0m" << endl;
			cout << "" << endl;
			cout << "\033[32mId:\033[0m " << i << endl;
			arr[i].imprimirInfo();
			return i; // Retornamos el �ndice de la Playlist en la PilaPlay
		}
	}
	cout << "\033[31mNo se encontro la Playlist\033[0m" << endl;
	return -1; // Si no encontramos la Playlist, retornamos -1
}

void PilaPlay::agregarCancionPlaylist(int id, Cancion c)
{ // M�todo para buscar una Playlist por nombre
	for (int i = top; i >= 0; i--)
	{ // Recorremos la PilaPlay desde el tope hasta el fondo
		if (i == id)
		{ // Si encontramos la Playlist con el nombre dado
			arr[i].lista.insertarAlFinal(c);
			arr[i].lista.imprimirAdelante();
			return;
		}
	}
	cout << "\033[31mNo se encontro la Playlist\033[0m" << endl;
}

void PilaPlay::eliminarCancionPlaylist(int idPlay, int idCancion)
{ // M�todo para buscar una Playlist por nombre
	for (int i = top; i >= 0; i--)
	{ // Recorremos la PilaPlay desde el tope hasta el fondo
		if (i == idPlay)
		{ // Si encontramos la Playlist con el nombre dado
			arr[i].lista.eliminarPorPosicion(idCancion);
			return;
		}
	}
	cout << "\033[31mNo se encontro la Playlist\033[0m" << endl;
}


void PilaPlay::listarCancionPlaylist(int id)
{ // M�todo para buscar una Playlist por nombre
	for (int i = top; i >= 0; i--)
	{ // Recorremos la PilaPlay desde el tope hasta el fondo
		if (i == id)
		{ // Si encontramos la Playlist con el nombre dado
			try
			{
				string nombre = arr[i].getNombre();
				cout << "" << endl;
				cout << "\033[1;32mCanciones de la playlist \033[0m " << nombre << endl;
				cout << "" << endl;
				arr[i].lista.imprimirAdelante();
				cout << "" << endl;
			}
			catch (const std::exception&)
			{
				cout << "Error al acceder a las canciones";
			}
			return;
		}
	}
	cout << "\033[31mNo se encontro la Playlist\033[0m" << endl;
}

int PilaPlay::actualizarPorId(int id) {
	// M�todo para buscar una Playlist por ID
	if (id >= 0 && id <= top) { // Si el ID est� en el rango v�lido
		// Pedimos los nuevos valores para nombre y descripci�n
		string nuevoNombre, nuevaDesc;
		cout << "" << endl;
		cout << "\033[1;32mIngrese el nuevo nombre (o enter para mantener el mismo): \033[0m";
		getline(cin.ignore(), nuevoNombre);
		cout << "\033[1;32mIngrese la nueva descripcion (o enter para mantener la misma): \033[0m";
		getline(cin, nuevaDesc);


		// Actualizamos los valores si corresponde
		if (nuevoNombre != "") {
			arr[id].setNombre(nuevoNombre);
		}
		if (nuevaDesc != "") {
			arr[id].setDescripcion(nuevaDesc);
		}

		cout << "" << endl;
		cout << "\033[1;32mSe actualizo la playlist \033[0m";
		return id; // Retornamos el �ndice de la Playlist en la PilaPlay
	}
	cout << "" << endl;
	cout << "\033[31mID de Playlist inv�lido\033[0m" << endl;
	return -1; // Si el ID es inv�lido, retornamos -1
}


void PilaPlay::reproducirNormal(int id) {
	// M�todo para buscar una Playlist por ID
	if (id >= 0 && id <= top) { // Si el ID est� en el rango v�lido
		arr[id].lista.reproducirNormal();
		cout << "" << endl;
		cout << "\033[31mSe termino de reproducir la playlist\033[0m" << endl;
		return;
	}
	cout << "" << endl;
	cout << "\033[31mID de Playlist inv�lido\033[0m" << endl;
}

void PilaPlay::reproducirRepetir(int id) {
	// M�todo para buscar una Playlist por ID
	if (id >= 0 && id <= top) { // Si el ID est� en el rango v�lido
		arr[id].lista.reproducirRepetir();
		cout << "" << endl;
		cout << "\033[31mSe termino de reproducir la playlist\033[0m" << endl;
		return;
	}
	cout << "" << endl;
	cout << "\033[31mID de Playlist inv�lido\033[0m" << endl;
}


void PilaPlay::eliminarPorId(int id)
{ // M�todo para eliminar una Playlist por id
	int confirmacion = 0;
	if (id < 0 || id > top)
	{ // Verificamos si el id es v�lido
		cout << "\033[31mNo se encontro una Playlist con ese id\033[0m" << endl;
		return;
	}
	cout << "" << endl;
	cout << "\033[31mSeguro que desea eliminar la Playlist? ingrese 1 o 0\033[0m " << endl;
	cin >> confirmacion;
	if (confirmacion == 1)
	{
		for (int i = id; i < top; i++)
		{ // Desplazamos los elementos siguientes a la Playlist a eliminar
			arr[i] = arr[i + 1];
		}
		top--; // Decrementamos el tope de la PilaPlay
		cout << "" << endl;
		cout << "\033[31mSe elimino la Playlist con id:\033[0m " << id << "." << endl;
	}
}

void PilaPlay::eliminarPorNombre(string nombre)
{ // M�todo para eliminar una Playlist por su nombre
	int confirmacion = 0;
	int index = -1;
	for (int i = 0; i <= top; i++)
	{ // Buscamos la Playlist con el nombre dado
		if (arr[i].getNombre() == nombre)
		{
			index = i;
			break;
		}
	}
	if (index == -1)
	{ // Verificamos si se encontr� una Playlist con el nombre dado
		cout << "\033[31mNo se encontr� una Playlist con ese nombre\033[0m" << endl;
		return;
	}
	cout << "" << endl;
	cout << "\033[31mSeguro que desea eliminar la Playlist? ingrese 1 o 0\033[0m " << endl;
	cin >> confirmacion;
	if (confirmacion == 1)
	{
		for (int i = index; i < top; i++)
		{ // Desplazamos los elementos siguientes a la Playlist a eliminar
			arr[i] = arr[i + 1];
		}
		top--; // Decrementamos el tope de la PilaPlay
		cout << "" << endl;
		cout << "\033[31mSe elimin� la Playlist con nombre:\033[0m " << nombre << "." << endl;
	}
}




void PilaPlay::listar()
{
	if (estaVacia()) // Verifica si la PilaPlay esta vacia
	{
		cout << "\033[31mNo hay playlists creadas\033[0m" << endl;
		return;
	}

	cout << "\033[1;32mPlaylists en el store \033[0m" << endl;
	cout << "" << endl;
	for (int i = top; i >= 0; i--)
	{
		cout << "\033[32mId:\033[0m " << i << endl; // Se imprimen las Playlistes
		arr[i].imprimirInfo();
		cout << endl;
	}
}