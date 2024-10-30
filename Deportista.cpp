#include "Deportista.h"

Deportista::Deportista(string ced, string nom, string tel, Fecha* nac)
{
	cedula = ced;
	nombre = nom;
	telefono = tel;
	fechaNacimiento = nac;
}

Deportista::~Deportista() {
}


