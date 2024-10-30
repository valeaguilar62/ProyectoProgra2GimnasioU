#pragma once
#include"Utilidad.h"
#include"InterfazTriatlonista.h"
#include<iostream>
using namespace std;

#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'


class Instructor {
private:
	string cedulaI;
	string nombreI;
public:
	Instructor(string = "", string = "");
	Instructor(const Instructor&);

	void setIdInstructor(string);
	void setNombreInstructor(string);
	string getIdInstructor();
	string getNombreInstructor();

	void guardar(ostream&);
	static Instructor* recuperar(istream&);

	friend ostream& operator <<(ostream&, const Instructor&);

	string toString();
	bool operator==(const Instructor&);
	void editar();
};


