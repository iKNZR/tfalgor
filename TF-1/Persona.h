#ifndef PERSONA_H_INCLUDE
#define PERSONA_H_INCLUDE

#include <iostream>
#include <string>
using namespace std;

class Persona
{
private:

	string nombre, apellido;
	unsigned int edad;

public:

	Persona() {};
	Persona(string nombre, string apellido, unsigned int edad)
	{
		this->nombre = nombre;
		this->apellido = apellido;
		this->edad = edad;
	}

	string getNombre() { return nombre; }
	string getApellido() { return apellido; }
	unsigned int getEdad() { return edad; }

	void mostrarAtributos()
	{
		cout << "Nombre \t Apellido \t edad" << endl;
	}

	void MostrarDatos()
	{
		cout << nombre << "\t" << apellido << "\t" << edad << endl;
	}
};

#endif // !PERSONA_H_INCLUDE
#pragma once
