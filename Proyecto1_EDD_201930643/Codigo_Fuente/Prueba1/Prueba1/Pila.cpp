#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Cancion.h"
#include "Pila.h"

using namespace std;

Pila::Pila()
{             // Constructor
	top = -1; // Inicializamos el tope de la pila en -1, ya que la pila est� vac�a
}

void Pila::push(Cancion cancion)
{ // M�todo para insertar elementos en la pila
	if (top == MAX - 1)
	{ // Verificamos si la pila est� llena
		cout << "Error: la pila est� llena." << endl;
		return;
	}
	top++;              // Incrementamos el �ndice del tope de la pila
	arr[top] = cancion; // Insertamos el elemento en el tope de la pila
}

void Pila::pushPos(Cancion cancion, int pos)
{ // M�todo para insertar elementos en la pila en una posici�n espec�fica
	if (top == MAX - 1)
	{ // Verificamos si la pila est� llena
		cout << "Error: la pila est� llena." << endl;
		return;
	}
	int insert_pos;
	if (pos == -1) {
		insert_pos = top + 1; // Inserta al final de la pila
	}
	else {
		insert_pos = pos; // Usa la posici�n ingresada
	}
	if (insert_pos < 0 || insert_pos > top + 1) {
		cout << "Error: posici�n inv�lida." << endl;
		return;
	}
	for (int i = top; i >= insert_pos; i--) {
		arr[i + 1] = arr[i]; // Desplaza los elementos hacia arriba
	}
	arr[insert_pos] = cancion; // Inserta el elemento en la posici�n indicada
	top++; // Incrementa el �ndice del tope de la pila
}


void Pila::pop()
{ // M�todo para sacar elementos de la pila
	if (top == -1)
	{ // Verificamos si la pila est� vac�a
		cout << "Error: la pila est� vac�a." << endl;
		return;
	}
	top--; // Decrementamos el �ndice del tope de la pila
}

bool Pila::estaVacia()
{ // Regresa si esta vacia la pila
	return (top < 0);
}

Cancion Pila::Top()
{ // M�todo para obtener el elemento en el tope de la pila
	return arr[top];
}

int Pila::buscarPorNombre(string nombre)
{ // M�todo para buscar una Cancion por nombre
	for (int i = top; i >= 0; i--)
	{ // Recorremos la pila desde el tope hasta el fondo
		if (arr[i].getNombre() == nombre)
		{ // Si encontramos la Cancion con el nombre dado
			cout << "\033[1;32mResultado: \033[0m" << endl;
			cout << "" << endl;
			cout << "\033[32mId:\033[0m " << i << endl;
			arr[i].imprimirInfo();
			return i; // Retornamos el �ndice de la Cancion en la pila
		}
	}
	cout << "\033[31mNo se encontro la cancion\033[0m" << endl;
	return -1; // Si no encontramos la Cancion, retornamos -1
}

Cancion Pila::buscarPorId(int id)
{ // M�todo para buscar una Cancion por ID
	for (int i = top; i >= 0; i--)
	{ // Recorremos la pila desde el tope hasta el fondo
		if (i == id)
		{ // Si encontramos la Cancion con el ID dado
			cout << "" << endl;
			cout << "\033[1;32mSe agrego la cancion: \033[0m" << endl;
			return arr[i]; // Retornamos la Cancion encontrada
		}
	}
	cout << "" << endl;
	cout << "\033[31mNo se encontro la cancion\033[0m" << endl;
	return Cancion(); // Si no encontramos la Cancion, retornamos un objeto Cancion vac�o
}


void Pila::eliminarPorNombre(string nombre)
{
	int confirmacion = 0;
	system("cls");                     // M�todo para eliminar una Cancion por nombre
	int idx = buscarPorNombre(nombre); // Buscamos la Cancion por nombre
	if (idx == -1)
	{ // Si no encontramos la Cancion
		cout << "\033[31mNo se encontro la cancion:\033[0m " << nombre << endl;
		return;
	}
	cout << "" << endl;
	cout << "\033[31mSeguro que desea eliminar la cancion? ingrese 1 o 0\033[0m " << endl;
	cin >> confirmacion;
	if (confirmacion == 1)
	{
		for (int i = idx; i < top; i++)
		{ // Desplazamos los elementos siguientes a la Cancion a eliminar
			arr[i] = arr[i + 1];
		}
		top--; // Decrementamos el tope de la pila
		cout << "" << endl;
		cout << "\033[31mSe elimino la cancion:\033[0m " << nombre << endl;
	}
}

void Pila::eliminarPorId(int id)
{ // M�todo para eliminar una Cancion por id
	int confirmacion = 0;
	if (id < 0 || id > top)
	{ // Verificamos si el id es v�lido
		cout << "\033[31mNo se encontro una cancion con ese id\033[0m" << endl;
		return;
	}
	cout << "" << endl;
	cout << "\033[31mSeguro que desea eliminar la cancion? ingrese 1 o 0\033[0m " << endl;
	cin >> confirmacion;
	if (confirmacion == 1)
	{
		for (int i = id; i < top; i++)
		{ // Desplazamos los elementos siguientes a la Cancion a eliminar
			arr[i] = arr[i + 1];
		}
		top--; // Decrementamos el tope de la pila
		cout << "" << endl;
		cout << "\033[31mSe elimino la cancion con id:\033[0m " << id << "." << endl;
	}
}

void Pila::listar()
{
	if (estaVacia()) // Verifica si la pila esta vacia
	{
		cout << "\033[31mEl store esta vacio\033[0m" << endl;
		return;
	}

	cout << "\033[1;32mCanciones en el store \033[0m" << endl;
	cout << "" << endl;
	for (int i = top; i >= 0; i--)
	{
		cout << "\033[32mId:\033[0m " << i << endl; // Se imprimen las canciones
		arr[i].imprimirInfo();
		cout << endl;
	}
}