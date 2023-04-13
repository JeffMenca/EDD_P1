#include "ListaSimple.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>

ListaSimple::ListaSimple() :
	cabeza(nullptr), cola(nullptr)
{
}

ListaSimple::~ListaSimple()
{
	while (!estaVacia()) {
		eliminarAlInicio();
	}
}

bool ListaSimple::estaVacia() const
{
	return cabeza == nullptr;
}

void ListaSimple::insertarAlInicio(const Cancion& cancion)
{
	Nodo* nuevoNodo = new Nodo(cancion, cabeza);
	if (estaVacia()) {
		cola = nuevoNodo;
	}
	cabeza = nuevoNodo;
}

void ListaSimple::insertarAlFinal(const Cancion& cancion)
{
	Nodo* nuevoNodo = new Nodo(cancion, nullptr);
	if (estaVacia()) {
		cabeza = nuevoNodo;
	}
	else {
		cola->setSiguiente(nuevoNodo);
	}
	cola = nuevoNodo;
}

void ListaSimple::eliminarPorPosicion(int posicion) {
	if (!estaVacia()) {
		if (posicion == 0) { // Si queremos eliminar el primer nodo
			eliminarAlInicio();
			cout << "\033[31mSe eliminó correctamente la canción\033[0m" << endl;
		}
		else {
			Nodo* nodoAEliminar = cabeza;
			Nodo* nodoAnterior = nullptr;
			for (int i = 0; i < posicion && nodoAEliminar != nullptr; i++) {
				nodoAnterior = nodoAEliminar;
				nodoAEliminar = nodoAEliminar->getSiguiente();
			}
			if (nodoAEliminar != nullptr) { // Si se encontró el nodo a eliminar
				if (nodoAEliminar == cabeza) {
					cabeza = nodoAEliminar->getSiguiente();
				}
				else {
					nodoAnterior->setSiguiente(nodoAEliminar->getSiguiente());
				}
				if (nodoAEliminar == cola) {
					cola = nodoAnterior;
				}
				delete nodoAEliminar;
				cout << "" << endl;
				cout << "\033[31mSe eliminó correctamente la canción\033[0m" << endl;
			}
			else {
				cout << "\033[31mPosición fuera de rango en la playlist\033[0m" << endl;
			}
		}
	}
	else {
		cout << "\033[31mLa playlist está vacía\033[0m" << endl;
	}
}

void ListaSimple::eliminarAlInicio()
{
	if (!estaVacia()) {
		Nodo* nodoAEliminar = cabeza;
		cabeza = cabeza->getSiguiente();
		if (cabeza == nullptr) {
			cola = nullptr;
		}
		delete nodoAEliminar;
	}
}

void ListaSimple::eliminarAlFinal()
{
	if (!estaVacia()) {
		if (cabeza == cola) {
			delete cabeza;
			cabeza = nullptr;
			cola = nullptr;
		}
		else {
			Nodo* nodoAnterior = cabeza;
			while (nodoAnterior->getSiguiente() != cola) {
				nodoAnterior = nodoAnterior->getSiguiente();
			}
			delete cola;
			cola = nodoAnterior;
			cola->setSiguiente(nullptr);
		}
	}
}

void ListaSimple::imprimirAdelante() const {
	if (!estaVacia()) {
		Nodo* actual = cabeza;
		int posicion = 0;
		while (actual != nullptr) {
			cout << posicion << ". " << actual->getCancion().getNombre() << " - " << actual->getCancion().getPath() << endl;
			actual = actual->getSiguiente();
			posicion++;
		}
	}
	else {
		cout << "\033[31mLa playlist esta vacia\033[0m" << endl;
	}
}

void ListaSimple::reproducirNormal() const {
	if (!estaVacia()) {
		Nodo* actual = cabeza;
		int posicion = 0;
		char tecla = 0;
		while (actual != nullptr) {
			system("cls");
			cout << "\033[1;32mPresione 'a' para regresar a la cancion anterior o 's' para la siguiente \033[0m" << endl;
			cout << "" << endl;
			cout << "\033[1;32mLista de reproduccion \033[0m" << endl;
			Nodo* siguiente = actual->getSiguiente();
			while (siguiente != nullptr) {
				cout << "Siguiente: " << siguiente->getCancion().getNombre() << endl;
				siguiente = siguiente->getSiguiente();
			}
			cout << "" << endl;
			cout << "Reproduciendo: " << actual->getCancion().getNombre() << " - " << actual->getCancion().getPath() << endl;
			// Aquí obtienes el path del nodo actual
			string path = actual->getCancion().getPath();
			// Aquí buscas la canción en el path y la reproduces
			for (int i = 0; i < 7; i++) {
				if (_kbhit()) { // Si se ha presionado una tecla
					tecla = _getch();
					if (tecla == 's') { // Si se presionó 's', pasa a la siguiente canción
						actual = actual->getSiguiente();
						if (actual == nullptr) { // Si llega al final de la lista para la reproduccion
							break;
						}
						posicion++;
						break;
					}
					else if (tecla == 'a') { // Si se presionó 'a', retrocede a la canción anterior
						if (posicion > 0) {
							actual = cabeza;
							for (int i = 0; i < posicion - 1; i++) {
								actual = actual->getSiguiente();
							}
							posicion--;
						}
						break;
					}
				}
				this_thread::sleep_for(chrono::seconds(1));
			}
			if (tecla == 0) { // Si no se presionó ninguna tecla, pasa a la siguiente canción
				actual = actual->getSiguiente();
				if (actual == nullptr) { // Si llega al final de la lista para la reproduccion
					break;
				}
				posicion++;
			}
			tecla = 0; // Reinicia el valor de la variable tecla
		}
	}
	else {
		cout << "\033[31mLa playlist esta vacia\033[0m" << endl;
	}
}

void ListaSimple::reproducirRepetir() const {
	if (!estaVacia()) {
		Nodo* actual = cabeza;
		int posicion = 0;
		char tecla = 0;
		bool terminar = false;
		while (actual != nullptr && !terminar) {
			system("cls");
			cout << "\033[1;32mPresione 'a' para regresar a la cancion anterior, 's' para la siguiente y 't' para terminar \033[0m" << endl;
			cout << "" << endl;
			cout << "\033[1;32mLista de reproduccion \033[0m" << endl;
			Nodo* siguiente = actual->getSiguiente();
			while (siguiente != nullptr) {
				cout << "Siguiente: " << siguiente->getCancion().getNombre() << endl;
				siguiente = siguiente->getSiguiente();
			}
			cout << "" << endl;
			cout << "Reproduciendo: " << actual->getCancion().getNombre() << " - " << actual->getCancion().getPath() << endl;
			// Aquí obtienes el path del nodo actual
			string path = actual->getCancion().getPath();
			// Aquí buscas la canción en el path y la reproduces
			for (int i = 0; i < 7; i++) {
				if (_kbhit()) { // Si se ha presionado una tecla
					tecla = _getch();
					if (tecla == 's') { // Si se presionó 's', pasa a la siguiente canción
						actual = actual->getSiguiente();
						if (actual == nullptr) { // Si llega al final de la lista para la reproduccion
							actual = cabeza;
						}
						posicion++;
						break;
					}
					else if (tecla == 'a') { // Si se presionó 'a', retrocede a la canción anterior
						if (posicion > 0) {
							actual = cabeza;
							for (int i = 0; i < posicion - 1; i++) {
								actual = actual->getSiguiente();
							}
							posicion--;
						}
						break;
					}
					else if (tecla == 't') { // Si se presionó 't', termina la reproducción
						terminar = true;
						break;
					}
				}
				this_thread::sleep_for(chrono::seconds(1));
			}
			if (tecla == 0) { // Si no se presionó ninguna tecla, pasa a la siguiente canción
				actual = actual->getSiguiente();
				if (actual == nullptr) { // Si llega al final de la lista para la reproduccion
					actual = cabeza;
				}
				posicion++;
			}
			tecla = 0; // Reinicia el valor de la variable tecla
		}
	}
	else {
		cout << "\033[31mLa playlist esta vacia\033[0m" << endl;
	}
}
