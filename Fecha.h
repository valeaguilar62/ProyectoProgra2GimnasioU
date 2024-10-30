#pragma once
#include<iostream>
#include<sstream>
#include "Utilidad.h"
constexpr auto DELIMITA_CAMPO = '\t';
constexpr auto DELIMITA_REGISTRO = '\n';
using namespace std;

class Fecha {
private:
	int mes;
	int dia;
	int anio;
public:
public:
	Fecha(int = 0, int = 0, int = 0);
	Fecha(Fecha&);
	virtual~Fecha();
	int getDia();
	int getMes();
	int getAnio();
	void setDia(int);
	void setMes(int);
	void setAnio(int);
	void guardar(ostream&);
	static Fecha* recuperar(istream&);
	bool operator > (const Fecha&);
	friend ostream& operator << (ostream& out, const Fecha& p);
	string toString();
};


