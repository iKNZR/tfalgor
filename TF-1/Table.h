#pragma once
#ifndef TABLE_H_INCLUDE
#define TABLE_H_INCLUDE
#include <iostream>
#include <conio.h>
#include <algorithm>
#include "Persona.h"
#include <vector>
#include "Arbol_Binario.h"

using namespace std;

template<typename DataType>
class Table
{
private:

	vector<DataType> data;
	Arbol_Binario<string> arbol_nombres;
	Arbol_Binario<string> arbol_apellidos;
	Arbol_Binario<int> arbol_edades;

public:

	Table()
	{

	}

	void push(DataType _data)
	{
		data.push_back(_data);
	}

	void pop(DataType _data)
	{
		data.pop_back();
	}

	void show()
	{
		data.at(0).mostrarAtributos();
		for (int i = 0; i < data.size(); i++)
		{
			data.at(i).MostrarDatos();
		}
	}

	Table<DataType> sortApellido()
	{
		Table<DataType> nueva_tabla;
		nueva_tabla.data = data;

		sort(nueva_tabla.data.begin(), nueva_tabla.data.end(),
			[&](Persona a, Persona b)->bool
		{
			return a.getApellido() < b.getApellido();
		}
		);

		return nueva_tabla;
	}

	vector<string> sortNombre()
	{
		Table<DataType> nueva_tabla;
		nueva_tabla.data = data;

		sort(nueva_tabla.data.begin(), nueva_tabla.data.end(),
			[&](Persona a, Persona b)->bool
		{
			return a.getNombre() < b.getNombre();
		}
		);

		return nueva_tabla;
	}

	vector<unsigned int> sortEdad()
	{
		Table<DataType> nueva_tabla;
		nueva_tabla.data = data;

		sort(nueva_tabla.data.begin(), nueva_tabla.data.end(),
			[&](Persona a, Persona b)->bool
		{
			return a.getEdad() < b.getEdad();
		}
		);

		return nueva_tabla;
	}

	vector<string> getColumnNombres()
	{
		vector<string> temp;
		for (int i = 0; i < data.size(); i++)
		{
			temp.push_back(data.at(i).getNombre());
		}
		return temp;
	}

	vector<string> getColumnApellidos()
	{
		vector<string> temp;
		for (int i = 0; i < data.size(); i++)
		{
			temp.push_back(data.at(i).getApellido());
		}
		return temp;
	}

	vector<int> getColumnEdades()
	{
		vector<int> temp;
		for (int i = 0; i < data.size(); i++)
		{
			temp.push_back(data.at(i).getEdad());
		}
		return temp;
	}

	void BusquedaNombre(string _nombre)
	{
		vector<string> nombres = getColumnNombres();

		for (int i = 0; i < nombres.size(); i++)
		{
			arbol_nombres.insert(nombres.at(i));
		}

		cout << arbol_nombres.search(_nombre)->dato;
	}

	void BusquedaApellido(string _apellido)
	{
		vector<string> apellidos = getColumnApellidos();

		for (int i = 0; i < apellidos.size(); i++)
		{
			arbol_apellidos.insert(apellidos.at(i));
		}

		cout << arbol_apellidos.search(_apellido)->dato;
	}

	void BusquedaEdad(int _edad)
	{
		vector<int> edades = getColumnEdades();

		for (int i = 0; i < edades.size(); i++)
		{
			arbol_edades.insert(edades.at(i));
		}
		cout << arbol_edades.search(_edad)->dato;
	}

	void Consulta(int column_number)
	{
		if (column_number == 0) //Nombre
		{
			int op = 0;
			char filter;

			//validación de opción de columna
			do
			{
				cout << "Filtrar por: " << endl;
				cout << "1. Inicia con " << endl;
				cout << "2. Finaliza con " << endl;
				cin >> op;

				if (op < 1 || op>2)
				{
					cout << "Elige una opcion valida" << endl;
				}

			} while (op < 1 || op>2);

			// filtramos por inicia con
			if (op == 1)
			{
				cout << "Elige la letra deseada: " << endl;
				cin >> filter;

				for (int i = 0; i < data.size(); i++)
				{
					string temp = data.at(i).getNombre();
					// Si la cadena empieza con 'filter', la mostramos
					if (temp[0] == filter)
					{
						cout << temp << endl;
					}
				}
			}

			//filtramos por termina con
			if (op == 2)
			{
				cout << "Elige la letra deseada: " << endl;
				cin >> filter;

				for (int i = 0; i < data.size(); i++)
				{
					string temp = data.at(i).getNombre();
					// Si la cadena termina con 'filter', la mostramos
					if (temp[temp.length() - 1] == filter)
					{
						cout << temp << endl;
					}
				}
			}
		}

		if (column_number == 1) //apellido
		{
			int op = 0;
			char filter;

			//validación de opción de columna
			do
			{
				cout << "Filtrar por: " << endl;
				cout << "1. Inicia con " << endl;
				cout << "2. Finaliza con " << endl;
				cin >> op;

				if (op < 1 || op>2)
				{
					cout << "Elige una opcion valida" << endl;
				}

			} while (op < 1 || op>2);

			// filtramos por inicia con
			if (op == 1)
			{
				cout << "Elige la letra deseada: " << endl;
				cin >> filter;

				for (int i = 0; i < data.size(); i++)
				{
					string temp = data.at(i).getApellido();
					// Si la cadena empieza con 'filter', la mostramos
					if (temp[0] == filter)
					{
						cout << temp << endl;
					}
				}
			}

			//filtramos por termina con
			if (op == 2)
			{
				cout << "Elige la letra deseada: " << endl;
				cin >> filter;

				for (int i = 0; i < data.size(); i++)
				{
					string temp = data.at(i).getNombre();
					// Si la cadena termina con 'filter', la mostramos
					if (temp[temp.length() - 1] == filter)
					{
						cout << temp << endl;
					}
				}
			}
		}

		if (column_number == 2) //edad
		{
			int op = 0;
			int filter;

			//validación de opción de columna
			do
			{
				cout << "Filtrar por: " << endl;
				cout << "1. Mayor a" << endl;
				cout << "2. Menor a" << endl;
				cout << "3. Igual a" << endl;
				cin >> op;

				if (op < 1 || op>3)
				{
					cout << "Elige una opcion valida" << endl;
				}

			} while (op < 1 || op>3);

			// filtramos por mayor
			if (op == 1)
			{
				cout << "Elige el numero deseado: " << endl;
				cin >> filter;

				for (int i = 0; i < data.size(); i++)
				{
					int temp = data.at(i).getEdad();
					if (temp > filter)
					{
						cout << temp << endl;
					}
				}
			}

			//filtramos por menor 
			if (op == 2)
			{
				cout << "Elige el numero deseado: " << endl;
				cin >> filter;

				for (int i = 0; i < data.size(); i++)
				{
					int temp = data.at(i).getEdad();
					if (temp < filter)
					{
						cout << temp << endl;
					}
				}
			}

			//filtramos por igual
			if (op == 3)
			{
				cout << "Elige el numero deseado: " << endl;
				cin >> filter;

				for (int i = 0; i < data.size(); i++)
				{
					int temp = data.at(i).getEdad();
					if (temp == filter)
					{
						cout << temp << endl;
					}
				}
			}
		}
	}

};


#endif // !
