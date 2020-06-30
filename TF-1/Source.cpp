#include <iostream>
#include <conio.h>
#include "Table.h"

using namespace std;

int main()
{
	Table<Persona> tabla;

	Persona p1("Leo", "Saman", 12);
	Persona p2("Ali", "White", 21);
	Persona p3("Nore", "Ael", 13);
	Persona p4("Keinm", "Zimmer", 14);

	tabla.push(p1);
	tabla.push(p2);
	tabla.push(p3);
	tabla.push(p4);

	Table<Persona> tabla2;

	while (1)
	{
		int opcion;

		do {
			cout << "MENU" << endl << endl;
			cout << "1. Mostrar tabla" << endl;
			cout << "2. Buscar" << endl;
			cout << "3. Ordenar" << endl << endl;
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
					int edad;
					cout << "1. Buscar por nombre" << endl;
					cout << "2. Buscar por apellido" << endl;
					cout << "3. Buscar por edad" << endl << endl;
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
					default:
						break;
					}
				} while (op < 1 || op>3);
				break;
			case 3:
				int num_columna;
				cout << "Ingrese el numero de la columna: " << endl;
				cin >> num_columna;
				tabla.Consulta(num_columna);
				cout << endl << endl;
			}

		} while (opcion < 1 || opcion>3);
	}
	_getch();
}