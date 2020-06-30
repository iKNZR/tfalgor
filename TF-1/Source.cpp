#include <iostream>
#include <conio.h>
#include "Table.h"

using namespace std;
using namespace System;

int main()
{
	Table<Persona> tabla;

	Persona p1(1, "Leo", "Saman", 12, 10, 'M', "Resn");
	Persona p2(2, "Ali", "White", 21, 9, 'F', "Qeu");
	Persona p3(3, "Leo", "Ael", 9, 8, 'M', "Enieo");
	Persona p4(4, "Kei", "Zimmer", 14, 11, 'M', "Neiro");
	Persona p5(5, "Ane", "Leir", 18, 11, 'F', "Koeni");
	Persona p6(6, "Len", "Kern", 20, 13, 'M', "Aeiw");
	Persona p7(7, "Nir", "Menoe", 6, 15, 'F', "Jeui");

	tabla.push(p1);
	tabla.push(p2);
	tabla.push(p3);
	tabla.push(p4);
	tabla.push(p5);
	tabla.push(p6);
	tabla.push(p7);

	Table<Persona> tabla2;

	while (1)
	{
		int opcion;

		do {
			cout << "MENU" << endl << endl;
			cout << "1. Mostrar tabla" << endl;
			cout << "2. Buscar" << endl;
			cout << "3. Consulta" << endl;
			cout << "4. Ordenar" << endl;
			cout << "5. Guardar en txt" << endl;
			cout << "6. Doble Consulta" << endl << endl;
			cin >> opcion;

			switch (opcion)
			{
			case 1:
				tabla.show(); break;
			case 2:
				int op;
				do {
					string name;
					string apellido;
					string equipo;
					int numero;
					int edad;
					char genero;
					cout << "Buscar por:" << endl;
					cout << "1. Nombre" << endl;
					cout << "2. Apellido" << endl;
					cout << "3. Edad" << endl;
					cout << "4. Genero" << endl;
					cout << "5. Equipo" << endl;
					cout << "6. Numero" << endl << endl;
					cin >> op;

					switch (op)
					{

					case 1:
						cout << "Ingrese el nombre a buscar: " << endl; cin >> name;
						tabla.BusquedaNombre(name);
						cout << endl << endl;
						break;
					case 2:
						cout << "Ingrese el Apellido a buscar: " << endl; cin >> apellido;
						tabla.BusquedaApellido(apellido);
						cout << endl << endl;
						break;
					case 3:
						cout << "Ingrese la edad a buscar: " << endl; cin >> edad;
						tabla.BusquedaEdad(edad);
						cout << endl << endl;
						break;
					case 4:
						cout << "Ingrese el genero a buscar: " << endl; cin >> genero;
						tabla.BusquedaGenero(genero);
						cout << endl << endl;
						break;
					case 5:
						cout << "Ingrese el equipo a buscar: " << endl; cin >> equipo;
						tabla.BusquedaEquipos(equipo);
						cout << endl << endl;
						break;
					case 6:
						cout << "Ingrese el numero a buscar: " << endl; cin >> numero;
						tabla.BusquedaNumero(numero);
						cout << endl << endl;
						break;
					default:
						break;
					}
				} while (op < 1 || op>6);
				break;
			case 3:
				int sub_menu;
				int num_columna;
				do {
					cout << "Ingrese el numero de la columna: " << endl;
					cin >> num_columna;
				} while (num_columna < 0 || num_columna>5);
				tabla.Consulta(num_columna);
				cout << endl << endl;

				break;
			case 4:
				int num_columna1;
				Table<Persona> nombres_ordenados;
				Table<Persona> apellidos_ordenados;
				Table<Persona> edades_ordenados;
				Table<Persona> generos_ordenados;
				Table<Persona> equipos_ordenados;
				Table<Persona> numeros_ordenados;

				do {
					cout << "Elija el numero de la columna: " << endl;
					cin >> num_columna1;
				} while (num_columna1 < 1 || num_columna1>6);

				switch (num_columna1) {
				case 1:
					nombres_ordenados = tabla.sortNombre();
					nombres_ordenados.show();
					break;
				case 2:
					apellidos_ordenados = tabla.sortApellido();
					apellidos_ordenados.show();
					break;
				case 3:
					generos_ordenados = tabla.sortGenero();
					apellidos_ordenados.show();
					break;
				case 4:
					equipos_ordenados = tabla.sortEquipo();
					equipos_ordenados.show();
					break;
				case 5:
					numeros_ordenados = tabla.sortNumero();
					numeros_ordenados.show();
					break;
				default:
					break;
				}
				break;
			}

			if (opcion == 5)
			{
				tabla.Guardar();
			}

			if (opcion == 6)
			{
				Table<Persona> resultado;
				resultado = tabla.ConsultaDoble();
				resultado.show();
			}
			_getch();
			Console::Clear();
		} while (opcion < 1 || opcion>5);
	}
	_getch();
}