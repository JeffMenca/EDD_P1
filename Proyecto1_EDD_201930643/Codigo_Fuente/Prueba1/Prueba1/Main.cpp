#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <conio.h>
#include <limits>
#include <climits>
#include "Cancion.h"
#include "Pila.h"
#include "ListaDoble.h"
#include "Playlist.h"
#include "PilaPlay.h"
#include <vector>

using namespace std;

Pila store; // Se crea pila de Store de Spotify
PilaPlay playlists;

void printMenuCanciones()
{
	int opcionSeleccionada = 0;
	while (opcionSeleccionada != 5)
	{
		system("cls");
		cout << "" << endl;
		cout << "\033[1;32mMenu de Canciones \033[0m" << endl;
		cout << "\033[1;32m--------------------------- \033[0m" << endl;
		cout << "" << endl;
		cout << "\033[1m1. Insertar cancion \033[32m>\033[0m" << endl;
		cout << "\033[1m2. Eliminar cancion \033[32m>\033[0m" << endl;
		cout << "\033[1m3. Listar canciones \033[32m>\033[0m" << endl;
		cout << "\033[1m4. Buscar cancion \033[32m>\033[0m" << endl;
		cout << "\033[1m5. Regresar \033[32m>\033[0m" << endl;
		cout << "" << endl;
		cout << "\033[1;32m--------------------------- \033[0m" << endl;
		cout << "\033[1mSeleccione su opcion \033[32m>\033[0m ";
		cin >> opcionSeleccionada;

		if (cin.fail()) { // si la entrada falló
			cin.clear(); // restablecer el estado de cin
			cin.ignore(INT_MAX, '\n'); // descartar la entrada incorrecta
			system("cls");
			cout << "\033[31mOpcion no valida\033[0m" << endl;
			cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
			_getch();
		}
		else {
			if (opcionSeleccionada == 1)
			{
				int salir = 1;

				while (salir != 0) {
					string nombreCancionNueva;
					string pathCancionNueva;
					while (nombreCancionNueva.empty() || pathCancionNueva.empty())
					{
						system("cls");
						cout << "\033[1;32mInsertar cancion \033[0m" << endl;
						cout << "" << endl;
						cout << "\033[1mIngrese el nombre de la cancion \033[32m>\033[0m ";
						getline(cin.ignore(), nombreCancionNueva);
						cout << "\033[1mIngrese el path \033[32m>\033[0m ";
						getline(cin, pathCancionNueva);
					}
					try
					{
						Cancion cancion(nombreCancionNueva, pathCancionNueva);
						store.push(cancion);
						cout << "" << endl;
						cout << "\033[32mCancion ingresada correctamente\033[0m" << endl;
						cout << "" << endl;
						cout << "\033[1mDesea ingresar otra cancion? 1 es si y 0 es no \033[32m>\033[0m ";
						cin >> salir;
					}
					catch (const std::exception& e)
					{
						cout << "" << endl;
						cout << "\033[31mError al ingresar la cancion\033[0m" << endl;
						cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
						_getch();
					}
				}
			}
			else if (opcionSeleccionada == 2)
			{
				string nombreCancionEliminar;
				int idCancionEliminar;
				int opcionEliminar;
				system("cls");
				cout << "\033[1;32mEliminar cancion \033[0m" << endl;
				cout << "" << endl;

				cout << "\033[1m1. Eliminar por Id \033[32m>\033[0m " << endl;
				cout << "\033[1m2. Eliminar por Nombre \033[32m>\033[0m " << endl;
				cin >> opcionEliminar;

				if (opcionEliminar == 1)
				{
					cout << "" << endl;
					cout << "\033[1mIngrese el id de la cancion \033[32m>\033[0m ";
					cin >> idCancionEliminar;
					try
					{
						cout << "" << endl;
						store.eliminarPorId(idCancionEliminar);
						cout << "" << endl;
						cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
						_getch();
					}
					catch (const std::exception& e)
					{
						std::cerr << e.what() << '\n';
						cout << "" << endl;
						cout << "\033[31mError, id de la cancion invalido\033[0m" << endl;
						cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
						_getch();
					}
				}
				else if (opcionEliminar == 2)
				{
					cout << "" << endl;
					cout << "\033[1mIngrese el nombre de la cancion \033[32m>\033[0m ";
					getline(cin.ignore(), nombreCancionEliminar);
					try
					{
						cout << "" << endl;
						store.eliminarPorNombre(nombreCancionEliminar);
						cout << "" << endl;
						cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
						_getch();
					}
					catch (const std::exception& e)
					{
						std::cerr << e.what() << '\n';
						cout << "" << endl;
						cout << "\033[31mError, nombre de la cancion invalido\033[0m" << endl;
						cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
						_getch();
					}
				}
				else
				{
					opcionEliminar = 0;
					system("cls");
					cout << "\033[31mOpcion no valida\033[0m" << endl;
					cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
					_getch();
				}
			}
			else if (opcionSeleccionada == 3)
			{
				system("cls");
				cout << "\033[1;32mListar canciones \033[0m" << endl;
				cout << "" << endl;
				store.listar();
				cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
				_getch();
			}
			else if (opcionSeleccionada == 4)
			{
				string nombreCancionBuscar;
				system("cls");
				cout << "\033[1;32mBuscar cancion \033[0m" << endl;
				cout << "" << endl;
				cout << "\033[1mIngrese el nombre de la cancion \033[32m>\033[0m ";
				getline(cin.ignore(), nombreCancionBuscar);
				try
				{
					cout << "" << endl;
					int idx = store.buscarPorNombre(nombreCancionBuscar);
					cout << "" << endl;
					cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
					_getch();
				}
				catch (const std::exception& e)
				{
					std::cerr << e.what() << '\n';
					cout << "" << endl;
					cout << "\033[31mError, nombre de la cancion invalido\033[0m" << endl;
					cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
					_getch();
				}
			}
			else if (opcionSeleccionada == 5)
			{
				break;
			}
			else
			{
				opcionSeleccionada = 0;
				system("cls");
				cout << "\033[31mOpcion no valida\033[0m" << endl;
				cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
				_getch();
			}
		}


	}
}

void printMenuPlaylists()
{
	int opcionSeleccionada = 0;
	while (opcionSeleccionada != 7)
	{
		system("cls");
		cout << "" << endl;
		cout << "\033[1;32mMenu de Playlists \033[0m" << endl;
		cout << "\033[1;32m--------------------------- \033[0m" << endl;
		cout << "" << endl;
		cout << "\033[1m1. Crear playlist \033[32m>\033[0m" << endl;
		cout << "\033[1m2. Eliminar playlist \033[32m>\033[0m" << endl;
		cout << "\033[1m3. Listar playlists \033[32m>\033[0m" << endl;
		cout << "\033[1m4. Actualizar playlist \033[32m>\033[0m" << endl;
		cout << "\033[1m5. Agregar cancion \033[32m>\033[0m" << endl;
		cout << "\033[1m6. Eliminar cancion \033[32m>\033[0m" << endl;
		cout << "\033[1m7. Regresar \033[32m>\033[0m" << endl;
		cout << "" << endl;
		cout << "\033[1;32m--------------------------- \033[0m" << endl;
		cout << "\033[1mSeleccione su opcion \033[32m>\033[0m ";
		cin >> opcionSeleccionada;

		if (cin.fail()) { // si la entrada falló
			cin.clear(); // restablecer el estado de cin
			cin.ignore(INT_MAX, '\n'); // descartar la entrada incorrecta
			system("cls");
			cout << "\033[31mOpcion no valida\033[0m" << endl;
			cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
			_getch();
		}
		else {
			if (opcionSeleccionada == 1)
			{
				string nombrePlayNueva;
				string desPlayNueva;
				int agregarCanciones;
				int idPlaylistIngresada;
				int idCancionSeleccionada;

				while (nombrePlayNueva.empty())
				{
					system("cls");
					cout << "\033[1;32mCrear playlist \033[0m" << endl;
					cout << "" << endl;
					cout << "\033[1mIngrese el nombre de la playlist \033[32m>\033[0m ";
					getline(cin.ignore(), nombrePlayNueva);
					cout << "\033[1mIngrese la descripcion \033[32m>\033[0m ";
					getline(cin, desPlayNueva);
				}
				try
				{
					Playlist playlist(nombrePlayNueva, desPlayNueva);
					idPlaylistIngresada = playlists.push(playlist);
					cout << "" << endl;
					cout << "\033[32mPlaylist ingresada correctamente\033[0m" << endl;
					cout << "" << endl;
					cout << "\033[1mDesea ingresarle canciones? 1 es si y 0 es no \033[32m>\033[0m ";
					cin >> agregarCanciones;
					if (agregarCanciones == 1) {
						int salir = 1;
						while (salir != 0) {
							system("cls");
							store.listar();
							cout << "" << endl;
							cout << "\033[1mIngrese el id de la cancion para agregar a playlist \033[32m>\033[0m ";
							cin >> idCancionSeleccionada;
							if (cin.fail()) { // si la entrada falló
								cin.clear(); // restablecer el estado de cin
								cin.ignore(INT_MAX, '\n'); // descartar la entrada incorrecta
								system("cls");
								cout << "\033[31mId no valido\033[0m" << endl;
								cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
								_getch();
							}
							else {
								Cancion cancion = store.buscarPorId(idCancionSeleccionada);
								if (cancion.getNombre() != "" && cancion.getPath() != "") {
									playlists.agregarCancionPlaylist(idPlaylistIngresada, cancion);
									cout << "" << endl;
									cout << "\033[1mDesea ingresar otra cancion? 1 es si y 0 es no \033[32m>\033[0m ";
									cin >> salir;
								}
							}
						}
					}
				}
				catch (const std::exception& e)
				{
					cout << "" << endl;
					cout << "\033[31mError al ingresar la cancion\033[0m" << endl;
					cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
					_getch();
				}
			}
			else if (opcionSeleccionada == 2)
			{
				int idPlayEliminar;
				system("cls");
				cout << "\033[1;32mEliminar playlist \033[0m" << endl;
				cout << "" << endl;
				playlists.listar();
				cout << "" << endl;
				cout << "\033[1mIngrese el id de la playlist a eliminar \033[32m>\033[0m ";
				cin >> idPlayEliminar;
				try
				{
					cout << "" << endl;
					playlists.eliminarPorId(idPlayEliminar);
					cout << "" << endl;
					cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
					_getch();
				}
				catch (const std::exception& e)
				{
					std::cerr << e.what() << '\n';
					cout << "" << endl;
					cout << "\033[31mError, id de la playlist invalido\033[0m" << endl;
					cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
					_getch();
				}

			}
			else if (opcionSeleccionada == 3)
			{
				int idPlaySeleccionada;
				system("cls");
				cout << "\033[1;32mListar playlists \033[0m" << endl;
				cout << "" << endl;
				playlists.listar();

				cout << "" << endl;
				cout << "\033[1mIngrese el id de la playlist para listar sus canciones \033[32m>\033[0m ";
				cin >> idPlaySeleccionada;
				if (cin.fail()) { // si la entrada falló
					cin.clear(); // restablecer el estado de cin
					cin.ignore(INT_MAX, '\n'); // descartar la entrada incorrecta
					system("cls");
					cout << "\033[31mOpcion no valida\033[0m" << endl;
					cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
					_getch();
				}
				else {
					playlists.listarCancionPlaylist(idPlaySeleccionada);
				}


				cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
				_getch();
			}
			else if (opcionSeleccionada == 4)
			{
				int idPlayActualizar;
				system("cls");
				cout << "\033[1;32mActualizar playlist \033[0m" << endl;
				cout << "" << endl;
				playlists.listar();
				cout << "" << endl;
				cout << "\033[1mIngrese el id de la playlist a eliminar \033[32m>\033[0m ";
				cin >> idPlayActualizar;
				try
				{
					playlists.actualizarPorId(idPlayActualizar);
					cout << "" << endl;
					cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
					_getch();
				}
				catch (const std::exception& e)
				{
					std::cerr << e.what() << '\n';
					cout << "" << endl;
					cout << "\033[31mError, id de la playlist invalido\033[0m" << endl;
					cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
					_getch();
				}
			}
			else if (opcionSeleccionada == 5)
			{
				int idPlaySeleccionada;
				int idCancionSeleccionada;
				system("cls");
				cout << "\033[1;32mAgregar cancion a playlist \033[0m" << endl;
				cout << "" << endl;
				playlists.listar();

				cout << "" << endl;
				cout << "\033[1mIngrese el id de la playlist para agregar una cancion \033[32m>\033[0m ";
				cin >> idPlaySeleccionada;
				if (cin.fail()) { // si la entrada falló
					cin.clear(); // restablecer el estado de cin
					cin.ignore(INT_MAX, '\n'); // descartar la entrada incorrecta
					system("cls");
					cout << "\033[31mId no valido\033[0m" << endl;
					cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
					_getch();
				}
				else {

					int salir = 1;
					while (salir != 0) {
						system("cls");
						store.listar();
						cout << "" << endl;
						cout << "\033[1mIngrese el id de la cancion para agregar a playlist \033[32m>\033[0m ";
						cin >> idCancionSeleccionada;
						if (cin.fail()) { // si la entrada falló
							cin.clear(); // restablecer el estado de cin
							cin.ignore(INT_MAX, '\n'); // descartar la entrada incorrecta
							system("cls");
							cout << "\033[31mId no valido\033[0m" << endl;
							cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
							_getch();
						}
						else {
							Cancion cancion = store.buscarPorId(idCancionSeleccionada);
							if (cancion.getNombre() != "" && cancion.getPath() != "") {
								playlists.agregarCancionPlaylist(idPlaySeleccionada, cancion);
								cout << "" << endl;
								cout << "\033[1mDesea ingresar otra cancion? 1 es si y 0 es no \033[32m>\033[0m ";
								cin >> salir;
							}
						}
					}
				}


				cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
				_getch();
			}
			else if (opcionSeleccionada == 6)
			{
				int idPlaySeleccionada;
				int idCancionSeleccionada;
				system("cls");
				cout << "\033[1;32mEliminar cancion de playlist \033[0m" << endl;
				cout << "" << endl;
				playlists.listar();

				cout << "" << endl;
				cout << "\033[1mIngrese el id de la playlist para eliminar una cancion \033[32m>\033[0m ";
				cin >> idPlaySeleccionada;
				if (cin.fail()) { // si la entrada falló
					cin.clear(); // restablecer el estado de cin
					cin.ignore(INT_MAX, '\n'); // descartar la entrada incorrecta
					system("cls");
					cout << "\033[31mId no valido\033[0m" << endl;
					cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
					_getch();
				}
				else {
					system("cls");
					playlists.listarCancionPlaylist(idPlaySeleccionada);
					cout << "" << endl;
					cout << "\033[1mIngrese el id de la cancion para eliminar de la playlist \033[32m>\033[0m ";
					cin >> idCancionSeleccionada;
					if (cin.fail()) { // si la entrada falló
						cin.clear(); // restablecer el estado de cin
						cin.ignore(INT_MAX, '\n'); // descartar la entrada incorrecta
						system("cls");
						cout << "\033[31mId no valido\033[0m" << endl;
						cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
						_getch();
					}
					else {
						playlists.eliminarCancionPlaylist(idPlaySeleccionada, idCancionSeleccionada);
						cout << "" << endl;
					}
				}


				cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
				_getch();
			}
			else if (opcionSeleccionada == 7)
			{
				break;
			}
			else
			{
				opcionSeleccionada = 0;
				system("cls");
				cout << "\033[31mOpcion no valida\033[0m" << endl;
				cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
				_getch();
			}
		}


	}
}

void printMenuReproduccion()
{
	int opcionSeleccionada = 0;
	while (opcionSeleccionada != 3)
	{
		system("cls");
		cout << "" << endl;
		cout << "\033[1;32mMenu de Reproduccion \033[0m" << endl;
		cout << "\033[1;32m--------------------------- \033[0m" << endl;
		cout << "" << endl;
		cout << "\033[1m1. Reproduccion normal \033[32m>\033[0m" << endl;
		cout << "\033[1m2. Reproduccion repetir \033[32m>\033[0m" << endl;
		cout << "\033[1m3. Regresar \033[32m>\033[0m" << endl;
		cout << "" << endl;
		cout << "\033[1;32m--------------------------- \033[0m" << endl;
		cout << "\033[1mSeleccione su opcion \033[32m>\033[0m ";
		cin >> opcionSeleccionada;

		if (cin.fail()) { // si la entrada falló
			cin.clear(); // restablecer el estado de cin
			cin.ignore(INT_MAX, '\n'); // descartar la entrada incorrecta
			system("cls");
			cout << "\033[31mOpcion no valida\033[0m" << endl;
			cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
			_getch();
		}
		else {
			if (opcionSeleccionada == 1)
			{
				int idPlayReproducir;
				system("cls");
				cout << "\033[1;32mReproducir playlist normal \033[0m" << endl;
				cout << "" << endl;
				playlists.listar();
				cout << "" << endl;
				cout << "\033[1mIngrese el id de la playlist a reproducir \033[32m>\033[0m ";
				cin >> idPlayReproducir;
				try
				{
					cout << "" << endl;
					playlists.reproducirNormal(idPlayReproducir);
					cout << "" << endl;
					cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
					_getch();
				}
				catch (const std::exception& e)
				{
					std::cerr << e.what() << '\n';
					cout << "" << endl;
					cout << "\033[31mError, id de la playlist invalido\033[0m" << endl;
					cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
					_getch();
				}
			}
			else if (opcionSeleccionada == 2)
			{
				int idPlayReproducir;
				system("cls");
				cout << "\033[1;32mReproducir playlist repetir \033[0m" << endl;
				cout << "" << endl;
				playlists.listar();
				cout << "" << endl;
				cout << "\033[1mIngrese el id de la playlist a reproducir \033[32m>\033[0m ";
				cin >> idPlayReproducir;
				try
				{
					cout << "" << endl;
					playlists.reproducirRepetir(idPlayReproducir);
					cout << "" << endl;
					cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
					_getch();
				}
				catch (const std::exception& e)
				{
					std::cerr << e.what() << '\n';
					cout << "" << endl;
					cout << "\033[31mError, id de la playlist invalido\033[0m" << endl;
					cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
					_getch();
				}

			}
			else if (opcionSeleccionada == 3)
			{
				break;
			}
			else
			{
				opcionSeleccionada = 0;
				system("cls");
				cout << "\033[31mOpcion no valida\033[0m" << endl;
				cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
				_getch();
			}
		}


	}
}

void cargaMasiva()
{
	system("cls");
	cout << "\033[1;32mInsertar cancion \033[0m" << endl;
	cout << "" << endl;

	ifstream archivo("prueba.txt"); // Abrir el archivo en modo lectura
	string linea;

	try
	{
		if (archivo.is_open()) { // Verificar si se pudo abrir el archivo
			cout << "Archivo encontrado" << endl;
			while (getline(archivo, linea)) { // Leer el archivo línea por línea
				if (linea.find("<Insertar>") != string::npos) { // Si la línea contiene "<Insertar>"
					while (getline(archivo, linea)) { // Leer el archivo hasta encontrar "</Insertar>"
						if (linea.find("</Insertar>") != string::npos) {
							break; // Salir del ciclo while
						}
						else if (linea.find("<cancion>") != string::npos) { // Si la línea contiene "<cancion>"
							string nombre, path;
							int pos = -1; // Valor por defecto para pos

							while (getline(archivo, linea)) { // Leer el archivo hasta encontrar "</cancion>"
								if (linea.find("</cancion>") != string::npos) {
									// Se encontró el fin de la canción, guardar los datos
									cout << "Insertando...Nombre: " << nombre << ", Path: " << path << ", Pos: " << pos << endl;
									try
									{
										Cancion cancion(nombre, path);
										store.pushPos(cancion, pos);
									}
									catch (const std::exception& e)
									{
										cout << "" << endl;
										cout << "\033[31mError al ingresar la cancion\033[0m " << nombre << endl;
									}
									break; // Salir del ciclo while
								}
								else if (linea.find("<Nombre>") != string::npos) { // Si la línea contiene "<Nombre>"
									nombre = linea.substr(linea.find("<Nombre>") + 8, linea.find("</Nombre>") - linea.find("<Nombre>") - 8); // Extraer el nombre de la canción
								}
								else if (linea.find("<Path>") != string::npos) { // Si la línea contiene "<Path>"
									path = linea.substr(linea.find("<Path>") + 6, linea.find("</Path>") - linea.find("<Path>") - 6); // Extraer el path de la canción
								}
								else if (linea.find("<Pos>") != string::npos) { // Si la línea contiene "<Pos>"
									pos = stoi(linea.substr(linea.find("<Pos>") + 5, linea.find("</Pos>") - linea.find("<Pos>") - 5)); // Extraer la posición de la canción (convertir a entero)
								}
							}
						}
						else if (linea.find("<Lista>") != string::npos) { // Si la línea contiene "<Lista>"
							string nombre, descripcion;
							vector<int> posiciones_canciones;

							int idPlaylistIngresada;
							while (getline(archivo, linea)) { // Leer el archivo hasta encontrar "</Lista>"
								if (linea.find("</Lista>") != string::npos) {
									// Se encontró el fin de la lista, guardar los datos
									cout << "Insertando lista...Nombre: " << nombre << ", Descripcion: " << descripcion << endl;
									try
									{
										Playlist playlist(nombre, descripcion);
										idPlaylistIngresada = playlists.push(playlist);
										for (int i = 0; i < posiciones_canciones.size(); i++) {
											int idCancion = posiciones_canciones[i]; // Restar 1 para obtener el índice correcto
											if (idCancion >= 0 && idCancion < posiciones_canciones.size()) {
												// La posición de la canción es válida, agregarla a la playlist
												Cancion cancion = store.buscarPorId(posiciones_canciones[idCancion]);
												if (cancion.getNombre() != "" && cancion.getPath() != "") {
													playlists.agregarCancionPlaylist(idPlaylistIngresada, cancion);
												}
											}
										}
									}
									catch (const std::exception& e)
									{
										cout << "" << endl;
										cout << "\033[31mError al ingresar la cancion\033[0m" << endl;
										cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
										_getch();
									}
									break; // Salir del ciclo while
								}
								else if (linea.find("<Nombre>") != string::npos) { // Si la línea contiene "<Nombre>"
									nombre = linea.substr(linea.find("<Nombre>") + 8, linea.find("</Nombre>") - linea.find("<Nombre>") - 8); // Extraer el nombre de la lista
								}
								else if (linea.find("<Descripcion>") != string::npos) { // Si la línea contiene "<Descripcion>"
									descripcion = linea.substr(linea.find("<Descripcion>") + 13, linea.find("</Descripcion>") - linea.find("<Descripcion>") - 13); // Extraer la descripción de la lista
								}
								else if (linea.find("<Canciones>") != string::npos) { // Si la línea contiene "<Canciones>"
									while (getline(archivo, linea)) { // Leer el archivo hasta encontrar "</Canciones>"
										if (linea.find("</Canciones>") != string::npos) {
											// Se encontró el fin de la sección de canciones, salir del ciclo
											break;
										}
										else if (linea.find("<pos>") != string::npos) { // Si la línea contiene "<Pos>"
											int pos = stoi(linea.substr(linea.find("<pos>") + 5, linea.find("</pos>") - linea.find("<pos>") - 5)); // Extraer la posición de la canción
											posiciones_canciones.push_back(pos); // Agregar la posición al vector de posiciones de canciones
										}
									}
								}
							}
						}

					}
				}
				else if (linea.find("<Eliminar>") != string::npos) { // Si la línea contiene "<Insertar>"
					while (getline(archivo, linea)) { // Leer el archivo hasta encontrar "</Insertar>"
						if (linea.find("</Eliminar>") != string::npos) {
							break; // Salir del ciclo while
						}
						else if (linea.find("<cancion>") != string::npos) { // Si la línea contiene "<cancion>"
							string nombre;
							int pos = -1; // Valor por defecto para pos

							while (getline(archivo, linea)) { // Leer el archivo hasta encontrar "</cancion>"
								if (linea.find("</cancion>") != string::npos) {
									// Se encontró el fin de la canción, guardar los datos
									cout << "Eliminando...Nombre: " << nombre << ", Id: " << pos << endl;
									try
									{
										if (pos != -1) {
											store.eliminarPorId(pos);
										}
										else {
											store.eliminarPorNombre(nombre);
										}
									}
									catch (const std::exception& e)
									{
										cout << "" << endl;
										cout << "\033[31mError al eliminar la cancion\033[0m " << nombre << endl;
									}
									break; // Salir del ciclo while
								}
								else if (linea.find("<Nombre>") != string::npos) { // Si la línea contiene "<Nombre>"
									nombre = linea.substr(linea.find("<Nombre>") + 8, linea.find("</Nombre>") - linea.find("<Nombre>") - 8); // Extraer el nombre de la canción
								}
								else if (linea.find("<id>") != string::npos) { // Si la línea contiene "<Pos>"
									pos = stoi(linea.substr(linea.find("<id>") + 5, linea.find("</id>") - linea.find("<id>") - 5)); // Extraer la posición de la canción (convertir a entero)
								}
							}
						}
						else if (linea.find("<Lista>") != string::npos) { // Si la línea contiene "<Lista>"
							string nombre, descripcion;
							vector<int> posiciones_canciones;
							int pos = -1; // Valor por defecto para pos

							while (getline(archivo, linea)) { // Leer el archivo hasta encontrar "</cancion>"
								if (linea.find("</Lista>") != string::npos) {
									// Se encontró el fin de la canción, guardar los datos
									cout << "Eliminando...Nombre: " << nombre << ", Id: " << pos << endl;
									try
									{
										if (posiciones_canciones.size() > 0) {
											for (int i = 0; i < posiciones_canciones.size(); i++) {
												int idCancion = posiciones_canciones[i]; // Restar 1 para obtener el índice correcto
												if (idCancion >= 0 && idCancion < posiciones_canciones.size()) {
													// La posición de la canción es válida, agregarla a la playlist
													Cancion cancion = store.buscarPorId(posiciones_canciones[idCancion]);
													if (cancion.getNombre() != "" && cancion.getPath() != "") {
														playlists.eliminarCancionPlaylist(pos, posiciones_canciones[idCancion]);
													}
												}
											}
										}
										else {
											if (pos != -1) {
												playlists.eliminarPorId(pos);
											}
											else {
												playlists.eliminarPorNombre(nombre);
											}
										}

									}
									catch (const std::exception& e)
									{
										cout << "" << endl;
										cout << "\033[31mError al eliminar la cancion\033[0m " << nombre << endl;
									}
									break; // Salir del ciclo while
								}
								else if (linea.find("<Nombre>") != string::npos) { // Si la línea contiene "<Nombre>"
									nombre = linea.substr(linea.find("<Nombre>") + 8, linea.find("</Nombre>") - linea.find("<Nombre>") - 8); // Extraer el nombre de la canción
								}
								else if (linea.find("<id>") != string::npos) { // Si la línea contiene "<Pos>"
									pos = stoi(linea.substr(linea.find("<id>") + 5, linea.find("</id>") - linea.find("<id>") - 5)); // Extraer la posición de la canción (convertir a entero)
								}
								else if (linea.find("<canciones>") != string::npos) { // Si la línea contiene "<Canciones>"
									while (getline(archivo, linea)) { // Leer el archivo hasta encontrar "</Canciones>"
										if (linea.find("</canciones>") != string::npos) {
											// Se encontró el fin de la sección de canciones, salir del ciclo
											break;
										}
										else if (linea.find("<pos>") != string::npos) { // Si la línea contiene "<Pos>"
											int pos = stoi(linea.substr(linea.find("<pos>") + 5, linea.find("</pos>") - linea.find("<pos>") - 5)); // Extraer la posición de la canción
											posiciones_canciones.push_back(pos); // Agregar la posición al vector de posiciones de canciones
										}
									}
								}
							}
						}

					}
				}
			}
		}
		else {
			cout << "No se encontro" << endl;
		}
		cout << "" << endl;
		cout << "Presione para continuar..." << endl;
		_getch();
		archivo.close(); // Cerrar el archivo
	}
	catch (const std::exception&)
	{
		cout << "Ocurrio un error en el archivo, probablemente sintactico" << endl;
	}

}

void printMenu()
{
	int opcionSeleccionada = 0;
	while (opcionSeleccionada != 5)
	{
		system("cls");
		cout << "" << endl;
		cout << "\033[1;32mSpotify (version terminal) \033[0m" << endl;
		cout << "\033[1;32m--------------------------- \033[0m" << endl;
		cout << "" << endl;
		cout << "\033[1m1. Canciones \033[32m>\033[0m" << endl;
		cout << "\033[1m2. Playlists \033[32m>\033[0m" << endl;
		cout << "\033[1m3. Reproduccion \033[32m>\033[0m" << endl;
		cout << "\033[1m4. Carga masiva \033[32m>\033[0m" << endl;
		cout << "\033[1m5. Salir \033[32m>\033[0m" << endl;
		cout << "" << endl;
		cout << "\033[1;32m--------------------------- \033[0m" << endl;
		cout << "\033[1mSeleccione su opcion \033[32m>\033[0m ";
		cin >> opcionSeleccionada;

		if (cin.fail()) { // si la entrada falló
			cin.clear(); // restablecer el estado de cin
			cin.ignore(INT_MAX, '\n'); // descartar la entrada incorrecta
			system("cls");
			cout << "\033[31mOpcion no valida\033[0m" << endl;
			cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
			_getch();
		}
		else {
			switch (opcionSeleccionada)
			{
			case 1:
				printMenuCanciones();
				break;
			case 2:
				printMenuPlaylists();
				break;
			case 3:
				printMenuReproduccion();
				break;
			case 4:
				cargaMasiva();
				break;
			case 5:
				system("cls");
				cout << "\033[31mSaliendo...\033[0m" << endl;
				cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
				_getch();
				break;
				// más casos posibles
			default:
				system("cls");
				cout << "\033[31mOpcion no valida\033[0m" << endl;
				cout << "\033[1mPresione una tecla para continuar... \033[32m>\033[0m" << endl;
				_getch();
			}
		}
	}
}

int main()
{
	printMenu();
	return 0;
}
