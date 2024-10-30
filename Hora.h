#pragma once
#include<iostream>
#include<sstream>
#include "Utilidad.h"
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'
using namespace std;

class Hora {
private:
	int horas;
	int minutos;
public:
	Hora(int = 0, int = 0);
	Hora(Hora&);
	virtual~Hora();
	void guardar(ostream&);
	static Hora* recuperar(istream&);
	friend ostream& operator << (ostream& out, const Hora& p);
};