#pragma once
#ifndef PERSONA_H_INCLUDE
#define PERSONA_H_INCLUDE

#include <iostream>
#include <string>
using namespace std;

class Persona
{
private:

	string nombre, apellido;
	string equipo;
	char genero;
	int edad, numero, id;

public:

	Persona() {};
	Persona(int id, string nombre, string apellido, int edad, int numero, char genero, string equipo)
	{
		this->id = id;
		this->nombre = nombre;
		this->apellido = apellido;
		this->edad = edad;
		this->genero = genero;
		this->equipo = equipo;
		this->numero = numero;
	}

	string getNombre() { return nombre; }
	string getApellido() { return apellido; }
	string getEquipo() { return equipo; }
	char getGenero() { return genero; }
	int getNumero() { return numero; }
	int getEdad() { return edad; }
	int getID() { return id; }

	void mostrarAtributos()
	{
		cout << "ID \t Nombre \t Apellido \t Edad \t Genero \t Equipo \t Numero" << endl;
	}

	void MostrarDatos()
	{
		cout << id << "\t" << " " << nombre << "\t\t" << " " << apellido << "\t\t" << " " << edad << "\t" << " " << genero << "\t\t" << " " << equipo << "\t\t" << "   " << numero << endl;
	}
};

#endif // !PERSONA_H_INCLUDE