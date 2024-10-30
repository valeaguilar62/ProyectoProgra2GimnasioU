#pragma once
#include "Fecha.h"

class InterfazTriatlonista
{
public:
	static string leerCedula();
	static string leerNombre();
	static string leerTelefono();
	static int leerHorasEntre();
	static double leerTemPromedio();
	static char leerSexo();
	static double leerEstatura();
	static double leerMasaMuscular();
	static double leerPeso();
	static double leerGrasa();
	static int leerCantIron();
	static int leerCantTriat();
	static int menuEditTriat();
	static int menuEditInst();
	static Fecha* leerFecha();
};

