#pragma once
#ifndef TABLE_H_INCLUDE
#define TABLE_H_INCLUDE
#include <iostream>
#include <conio.h>
#include <algorithm>
#include "Persona.h"
#include <vector>
#include <fstream>
#include "Arbol_Binario.h"

using namespace std;

template<typename DataType>
class Table {
private:
	vector<DataType> data;
	Arbol_Binario<string> arbol_nombres;
	Arbol_Binario<string> arbol_apellidos;
	Arbol_Binario<string> arbol_equipos;
	Arbol_Binario<char> arbol_generos;
	Arbol_Binario<int> arbol_edades;
	Arbol_Binario<int> arbol_numeros;
	ofstream guardar;
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
	Table<DataType> sortNombre()
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
	Table<DataType> sortEdad()
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
	Table<DataType> sortNumero()
	{
		Table<DataType> nueva_tabla;
		nueva_tabla.data = data;

		sort(nueva_tabla.data.begin(), nueva_tabla.data.end(),
			[&](Persona a, Persona b)->bool
		{
			return a.getNumero() < b.getNumero();
		}
		);

		return nueva_tabla;
	}
	Table<DataType> sortEquipo()
	{
		Table<DataType> nueva_tabla;
		nueva_tabla.data = data;

		sort(nueva_tabla.data.begin(), nueva_tabla.data.end(),
			[&](Persona a, Persona b)->bool
		{
			return a.getEquipo() < b.getEquipo();
		}
		);

		return nueva_tabla;
	}
	Table<DataType> sortGenero()
	{
		Table<DataType> nueva_tabla;
		nueva_tabla.data = data;

		sort(nueva_tabla.data.begin(), nueva_tabla.data.end(),
			[&](Persona a, Persona b)->bool
		{
			return a.getGenero() < b.getGenero();
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
	vector<string> getColumnEquipos()
	{
		vector<string> temp;
		for (int i = 0; i < data.size(); i++)
		{
			temp.push_back(data.at(i).getEquipo());
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
	vector<int> getColumnNumeros()
	{
		vector<int> temp;
		for (int i = 0; i < data.size(); i++)
		{
			temp.push_back(data.at(i).getNumero());
		}
		return temp;
	}
	vector<char> getColumnGenero()
	{
		vector<char> temp;
		for (int i = 0; i < data.size(); i++)
		{
			temp.push_back(data.at(i).getGenero());
		}
		return temp;
	}
	void BusquedaNombre(string _nombre)
	{
		vector<string> names = getColumnNombres();

		for (int i = 0; i < names.size(); i++)
		{
			arbol_nombres.insert(names.at(i));
		}

		cout << arbol_nombres.search(_nombre)->dato;
		cout << endl << endl;

		data.at(0).mostrarAtributos();
		for (int i = 0; i < data.size(); i++)
		{
			if (data.at(i).getNombre() == _nombre)
			{
				data.at(i).MostrarDatos();
			}
		}
	}
	void BusquedaGenero(char _genero)
	{
		vector<char> generos = getColumnGenero();

		for (int i = 0; i < generos.size(); i++)
		{
			arbol_generos.insert(generos.at(i));
		}

		cout << arbol_generos.search(_genero)->dato;
		cout << endl << endl;

		data.at(0).mostrarAtributos();
		for (int i = 0; i < data.size(); i++)
		{
			if (data.at(i).getGenero() == _genero)
			{
				data.at(i).MostrarDatos();
			}
		}
	}
	void BusquedaEquipos(string _equipo)
	{
		vector<string> equipo = getColumnEquipos();

		for (int i = 0; i < equipo.size(); i++)
		{
			arbol_equipos.insert(equipo.at(i));
		}

		cout << arbol_equipos.search(_equipo)->dato;
		cout << endl << endl;

		data.at(0).mostrarAtributos();
		for (int i = 0; i < data.size(); i++)
		{
			if (data.at(i).getEquipo() == _equipo)
			{
				data.at(i).MostrarDatos();
			}
		}
	}
	void BusquedaApellido(string _apellido)
	{
		vector<string> apellidos = getColumnApellidos();

		for (int i = 0; i < apellidos.size(); i++)
		{
			arbol_apellidos.insert(apellidos.at(i));
		}

		cout << arbol_apellidos.search(_apellido)->dato;
		cout << endl << endl;

		data.at(0).mostrarAtributos();
		for (int i = 0; i < data.size(); i++)
		{
			if (data.at(i).getApellido() == _apellido)
			{
				data.at(i).MostrarDatos();
			}
		}
	}
	void BusquedaEdad(int _edad)
	{
		vector<int> edades = getColumnEdades();

		for (int i = 0; i < edades.size(); i++)
		{
			arbol_edades.insert(edades.at(i));
		}
		cout << arbol_edades.search(_edad)->dato;
		cout << endl << endl;

		data.at(0).mostrarAtributos();
		for (int i = 0; i < data.size(); i++)
		{
			if (data.at(i).getEdad() == _edad)
			{
				data.at(i).MostrarDatos();
			}
		}
	}
	void BusquedaNumero(int _numero)
	{
		vector<int> numeros = getColumnNumeros();

		for (int i = 0; i < numeros.size(); i++)
		{
			arbol_numeros.insert(numeros.at(i));
		}
		cout << arbol_numeros.search(_numero)->dato;
		cout << endl << endl;

		data.at(0).mostrarAtributos();
		for (int i = 0; i < data.size(); i++)
		{
			if (data.at(i).getNumero() == _numero)
			{
				data.at(i).MostrarDatos();
			}
		}
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

				cout << endl;
				data.at(0).mostrarAtributos();
				for (int i = 0; i < data.size(); i++)
				{
					string temp = data.at(i).getNombre();
					// Si la cadena empieza con 'filter', la mostramos
					if (temp[0] == filter)
					{
						data.at(i).MostrarDatos();
					}
				}
			}

			//filtramos por termina con
			if (op == 2)
			{
				cout << "Elige la letra deseada: " << endl;
				cin >> filter;

				cout << endl;
				data.at(0).mostrarAtributos();

				for (int i = 0; i < data.size(); i++)
				{
					string temp = data.at(i).getNombre();
					// Si la cadena termina con 'filter', la mostramos
					if (temp[temp.length() - 1] == filter)
					{
						data.at(i).MostrarDatos();
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
					cout << endl;
					data.at(0).mostrarAtributos();
					// Si la cadena empieza con 'filter', la mostramos
					if (temp[0] == filter)
					{
						data.at(i).MostrarDatos();
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
					cout << endl;
					data.at(0).mostrarAtributos();
					if (temp[temp.length() - 1] == filter)
					{
						data.at(i).MostrarDatos();
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

				cout << endl;
				data.at(0).mostrarAtributos();

				for (int i = 0; i < data.size(); i++)
				{
					int temp = data.at(i).getEdad();
					if (temp > filter)
					{
						data.at(i).MostrarDatos();
					}
				}
			}

			//filtramos por menor 
			if (op == 2)
			{
				cout << "Elige el numero deseado: " << endl;
				cin >> filter;

				cout << endl;
				data.at(0).mostrarAtributos();

				for (int i = 0; i < data.size(); i++)
				{
					int temp = data.at(i).getEdad();
					if (temp < filter)
					{
						data.at(i).MostrarDatos();
					}
				}
			}

			//filtramos por igual
			if (op == 3)
			{
				cout << "Elige el numero deseado: " << endl;
				cin >> filter;

				cout << endl;
				data.at(0).mostrarAtributos();

				for (int i = 0; i < data.size(); i++)
				{
					int temp = data.at(i).getEdad();
					if (temp == filter)
					{
						data.at(i).MostrarDatos();
					}
				}
			}
		}

		if (column_number == 3)
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
				cout << endl;
				data.at(0).mostrarAtributos();

				for (int i = 0; i < data.size(); i++)
				{
					int temp = data.at(i).getNumero();
					if (temp > filter)
					{
						data.at(i).MostrarDatos();
					}
				}
			}

			//filtramos por menor 
			if (op == 2)
			{
				cout << "Elige el numero deseado: " << endl;
				cin >> filter;

				cout << endl;
				data.at(0).mostrarAtributos();
				for (int i = 0; i < data.size(); i++)
				{
					int temp = data.at(i).getNumero();


					if (temp < filter)
					{
						data.at(i).MostrarDatos();
					}
				}
			}

			//filtramos por igual
			if (op == 3)
			{
				cout << "Elige el numero deseado: " << endl;
				cin >> filter;
				cout << endl;
				data.at(0).mostrarAtributos();
				for (int i = 0; i < data.size(); i++)
				{
					int temp = data.at(i).getNumero();
					if (temp == filter)
					{
						data.at(i).MostrarDatos();
					}
				}
			}
		}

		if (column_number == 4)
		{
			int op = 0;
			char filter;

			do {
				cout << "Filtrar por: " << endl;
				cout << "1. Masculino" << endl;
				cout << "2. Femenino" << endl;
				cin >> op;
			} while (op < 1 || op>2);

			if (op == 1)
			{
				filter = 'M';
				cout << endl;
				data.at(0).mostrarAtributos();
				for (int i = 0; i < data.size(); i++)
				{
					char temp = data.at(i).getGenero();
					if (temp == filter)
					{
						data.at(i).MostrarDatos();
					}
				}
			}

			if (op == 2)
			{
				filter = 'F';
				cout << endl;
				data.at(0).mostrarAtributos();

				for (int i = 0; i < data.size(); i++)
				{
					char temp = data.at(i).getGenero();
					if (temp == filter)
					{
						data.at(i).MostrarDatos();
					}
				}
			}
		}

		if (column_number == 5)
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
				cout << endl;
				data.at(0).mostrarAtributos();

				for (int i = 0; i < data.size(); i++)
				{
					string temp = data.at(i).getEquipo();
					// Si la cadena empieza con 'filter', la mostramos
					if (temp[0] == filter)
					{
						data.at(i).MostrarDatos();
					}
				}
			}

			//filtramos por termina con
			if (op == 2)
			{
				cout << "Elige la letra deseada: " << endl;
				cin >> filter;
				cout << endl;
				data.at(0).mostrarAtributos();

				for (int i = 0; i < data.size(); i++)
				{
					string temp = data.at(i).getEquipo();
					// Si la cadena termina con 'filter', la mostramos
					if (temp[temp.length() - 1] == filter)
					{
						data.at(i).MostrarDatos();
					}
				}
			}
		}

		if (column_number == 6)
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
				cout << endl;
				data.at(0).mostrarAtributos();

				for (int i = 0; i < data.size(); i++)
				{
					int temp = data.at(i).getNumero();
					if (temp > filter)
					{
						data.at(i).MostrarDatos();
					}
				}
			}
		}
	}
	void Guardar()
	{
		guardar.open("datos.txt", ios::out);

		if (guardar.fail())
		{
			cout << "No se pudo abrir el archivo.";
			exit(0);
		}
		else
		{
			for (int i = 0; i < data.size(); i++)
			{
				guardar << data.at(i).getID() << " " << data.at(i).getNombre() << " " << data.at(i).getApellido() << " " << data.at(i).getEdad() << " " << data.at(i).getNumero() << " " << data.at(i).getGenero() << " " << data.at(i).getEquipo() << endl;
			}

			guardar.close();
			cout << endl << "Guardado!" << endl;
		}
	}
	bool empty()
	{
		if (data.size() == 0)
		{
			return true;
		}
		return false;
	}

	Table<DataType> ConsultaDoble()
	{
		Table<DataType> filtro1;
		Table<DataType> filtro2;

		int column_number1, column_number2;

		cout << "Ingrese las columnas a filtrar: " << endl;
		do { cout << "Primera Columna: "; cin >> column_number1; cout << endl; } while (column_number1 < 0 || column_number1 > 6);
		do { cout << "Segunda Columna: "; cin >> column_number2; cout << endl; } while (column_number2 < 0 || column_number2 > 6 || column_number2 == column_number1);

		int filtro_int_1;
		int filtro_int_2;
		char filtro_char_1;
		char filtro_char_2;

		if (column_number1 == 0) //Nombre
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
				filtro_char_1 = filter;

				for (int i = 0; i < data.size(); i++)
				{
					string temp = data.at(i).getNombre();
					// Si la cadena empieza con 'filter', la mostramos
					if (temp[0] == filter)
					{
						filtro1.push(data.at(i));
					}
				}
			}

			//filtramos por termina con
			if (op == 2)
			{
				cout << "Elige la letra deseada: " << endl;
				cin >> filter;
				filtro_char_1 = filter;

				for (int i = 0; i < data.size(); i++)
				{
					string temp = data.at(i).getNombre();
					// Si la cadena termina con 'filter', la mostramos
					if (temp[temp.length() - 1] == filter)
					{
						filtro1.push(data.at(i));
					}
				}
			}
		}

		if (column_number1 == 1) //apellido
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
				filtro_char_1 = filter;

				for (int i = 0; i < data.size(); i++)
				{
					string temp = data.at(i).getApellido();
					// Si la cadena empieza con 'filter', la mostramos
					if (temp[0] == filter)
					{
						filtro1.push(data.at(i));
					}
				}
			}

			//filtramos por termina con
			if (op == 2)
			{
				cout << "Elige la letra deseada: " << endl;
				cin >> filter;
				filtro_char_1 = filter;

				for (int i = 0; i < data.size(); i++)
				{
					string temp = data.at(i).getNombre();
					// Si la cadena termina con 'filter', la mostramos
					if (temp[temp.length() - 1] == filter)
					{
						filtro1.push(data.at(i));
					}
				}
			}
		}

		if (column_number1 == 2) //edad
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
				filtro_int_1 = filter;

				for (int i = 0; i < data.size(); i++)
				{
					int temp = data.at(i).getEdad();
					if (temp > filter)
					{
						filtro1.push(data.at(i));
					}
				}
			}

			//filtramos por menor 
			if (op == 2)
			{
				cout << "Elige el numero deseado: " << endl;
				cin >> filter;
				filtro_int_1 = filter;

				for (int i = 0; i < data.size(); i++)
				{
					int temp = data.at(i).getEdad();
					if (temp < filter)
					{
						filtro1.push(data.at(i));
					}
				}
			}

			//filtramos por igual
			if (op == 3)
			{
				cout << "Elige el numero deseado: " << endl;
				cin >> filter;
				filtro_int_1 = filter;

				for (int i = 0; i < data.size(); i++)
				{
					int temp = data.at(i).getEdad();
					if (temp == filter)
					{
						filtro1.push(data.at(i));
					}
				}
			}
		}

		if (column_number1 == 3) //numero
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
				filtro_int_1 = filter;

				for (int i = 0; i < data.size(); i++)
				{
					int temp = data.at(i).getNumero();
					if (temp > filter)
					{
						filtro1.push(data.at(i));
					}
				}
			}

			//filtramos por menor 
			if (op == 2)
			{
				cout << "Elige el numero deseado: " << endl;
				cin >> filter;
				filtro_int_1 = filter;

				for (int i = 0; i < data.size(); i++)
				{
					int temp = data.at(i).getNumero();
					if (temp < filter)
					{
						filtro1.push(data.at(i));
					}
				}
			}

			//filtramos por igual
			if (op == 3)
			{
				cout << "Elige el numero deseado: " << endl;
				cin >> filter;
				filtro_int_1 = filter;

				for (int i = 0; i < data.size(); i++)
				{
					int temp = data.at(i).getNumero();
					if (temp == filter)
					{
						filtro1.push(data.at(i));
					}
				}
			}
		}

		if (column_number1 == 4) //genero
		{
			int op = 0;
			char filter;

			do {
				cout << "Filtrar por: " << endl;
				cout << "1. Masculino" << endl;
				cout << "2. Femenino" << endl;
				cin >> op;
			} while (op < 1 || op>2);

			if (op == 1)
			{
				filter = 'M';
				filtro_char_1 = filter;

				for (int i = 0; i < data.size(); i++)
				{
					char temp = data.at(i).getGenero();
					if (temp == filter)
					{
						filtro1.push(data.at(i));
					}
				}
			}

			if (op == 2)
			{
				filter = 'F';
				filtro_char_1 = filter;

				for (int i = 0; i < data.size(); i++)
				{
					char temp = data.at(i).getGenero();
					if (temp == filter)
					{
						filtro1.push(data.at(i));
					}
				}
			}
		}

		if (column_number1 == 5) //equipo
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
				filtro_char_1 = filter;

				for (int i = 0; i < data.size(); i++)
				{
					string temp = data.at(i).getEquipo();
					// Si la cadena empieza con 'filter', la mostramos
					if (temp[0] == filter)
					{
						filtro1.push(data.at(i));
					}
				}
			}

			//filtramos por termina con
			if (op == 2)
			{
				cout << "Elige la letra deseada: " << endl;
				cin >> filter;
				filtro_char_1 = filter;

				for (int i = 0; i < data.size(); i++)
				{
					string temp = data.at(i).getEquipo();
					// Si la cadena termina con 'filter', la mostramos
					if (temp[temp.length() - 1] == filter)
					{
						filtro1.push(data.at(i));
					}
				}
			}
		}

		if (column_number2 == 0) //Nombre
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
				filtro_char_2 = filter;

				for (int i = 0; i < filtro1.data.size(); i++)
				{
					string temp = filtro1.data.at(i).getNombre();
					// Si la cadena empieza con 'filter', la mostramos
					if (temp[0] == filter)
					{
						filtro2.push(filtro1.data.at(i));
					}
				}
			}

			//filtramos por termina con
			if (op == 2)
			{
				cout << "Elige la letra deseada: " << endl;
				cin >> filter;
				filtro_char_2 = filter;

				for (int i = 0; i < filtro1.data.size(); i++)
				{
					string temp = filtro1.data.at(i).getNombre();
					// Si la cadena termina con 'filter', la mostramos
					if (temp[temp.length() - 1] == filter)
					{
						filtro2.push(filtro1.data.at(i));
					}
				}
			}
		}

		if (column_number2 == 1) //apellido
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
				filtro_char_2 = filter;

				for (int i = 0; i < filtro1.data.size(); i++)
				{
					string temp = filtro1.data.at(i).getApellido();
					// Si la cadena empieza con 'filter', la mostramos
					if (temp[0] == filter)
					{
						filtro2.push(filtro1.data.at(i));
					}
				}
			}

			//filtramos por termina con
			if (op == 2)
			{
				cout << "Elige la letra deseada: " << endl;
				cin >> filter;
				filtro_char_2 = filter;

				for (int i = 0; i < filtro1.data.size(); i++)
				{
					string temp = filtro1.data.at(i).getNombre();
					// Si la cadena termina con 'filter', la mostramos
					if (temp[temp.length() - 1] == filter)
					{
						filtro2.push(filtro1.data.at(i));
					}
				}
			}
		}

		if (column_number2 == 2) //edad
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
				filtro_int_2 = filter;

				for (int i = 0; i < filtro1.data.size(); i++)
				{
					int temp = filtro1.data.at(i).getEdad();
					if (temp > filter)
					{
						filtro2.push(filtro1.data.at(i));
					}
				}
			}

			//filtramos por menor 
			if (op == 2)
			{
				cout << "Elige el numero deseado: " << endl;
				cin >> filter;
				filtro_int_2 = filter;

				for (int i = 0; i < filtro1.data.size(); i++)
				{
					int temp = filtro1.data.at(i).getEdad();
					if (temp < filter)
					{
						filtro2.push(filtro1.data.at(i));
					}
				}
			}

			//filtramos por igual
			if (op == 3)
			{
				cout << "Elige el numero deseado: " << endl;
				cin >> filter;

				for (int i = 0; i < filtro1.data.size(); i++)
				{
					int temp = filtro1.data.at(i).getEdad();
					if (temp == filter)
					{
						filtro2.push(filtro1.data.at(i));
					}
				}
			}
		}

		if (column_number2 == 3) //numero
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
				filtro_int_2 = filter;

				for (int i = 0; i < filtro1.data.size(); i++)
				{
					int temp = filtro1.data.at(i).getNumero();
					if (temp > filter)
					{
						filtro2.push(filtro1.data.at(i));
					}
				}
			}

			//filtramos por menor 
			if (op == 2)
			{
				cout << "Elige el numero deseado: " << endl;
				cin >> filter;
				filtro_int_2 = filter;

				for (int i = 0; i < filtro1.data.size(); i++)
				{
					int temp = filtro1.data.at(i).getNumero();
					if (temp < filter)
					{
						filtro2.push(filtro1.data.at(i));
					}
				}
			}

			//filtramos por igual
			if (op == 3)
			{
				cout << "Elige el numero deseado: " << endl;
				cin >> filter;
				filtro_int_2 = filter;

				for (int i = 0; i < filtro1.data.size(); i++)
				{
					int temp = filtro1.data.at(i).getNumero();
					if (temp == filter)
					{
						filtro2.push(filtro1.data.at(i));
					}
				}
			}
		}

		if (column_number2 == 4) //genero
		{
			int op = 0;
			char filter;

			do {
				cout << "Filtrar por: " << endl;
				cout << "1. Masculino" << endl;
				cout << "2. Femenino" << endl;
				cin >> op;
			} while (op < 1 || op>2);

			if (op == 1)
			{
				filter = 'M';
				filtro_char_2 = filter;
				for (int i = 0; i < filtro1.data.size(); i++)
				{
					char temp = filtro1.data.at(i).getGenero();
					if (temp == filter)
					{
						filtro2.push(filtro1.data.at(i));
					}
				}
			}

			if (op == 2)
			{
				filter = 'F';
				filtro_char_2 = filter;
				for (int i = 0; i < filtro1.data.size(); i++)
				{
					char temp = filtro1.data.at(i).getGenero();
					if (temp == filter)
					{
						filtro2.push(filtro1.data.at(i));
					}
				}
			}
		}

		if (column_number2 == 5) //equipo
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
				filtro_char_2 = filter;

				for (int i = 0; i < filtro1.data.size(); i++)
				{
					string temp = filtro1.data.at(i).getEquipo();
					// Si la cadena empieza con 'filter', la mostramos
					if (temp[0] == filter)
					{
						filtro2.push(filtro1.data.at(i));
					}
				}
			}

			//filtramos por termina con
			if (op == 2)
			{
				cout << "Elige la letra deseada: " << endl;
				cin >> filter;
				filtro_char_2 = filter;

				for (int i = 0; i < filtro1.data.size(); i++)
				{
					string temp = filtro1.data.at(i).getEquipo();
					// Si la cadena termina con 'filter', la mostramos
					if (temp[temp.length() - 1] == filter)
					{
						filtro2.push(filtro1.data.at(i));
					}
				}
			}
		}

		return filtro2;
	}
};

#endif //