#pragma once
#include"Deportista.h"
#include"Curso.h"

class Reserva {
private:
	string codigo;
	Fecha* fechaReserva;
	Curso* ptrCurso;
	Deportista* ptrDeportista;
public:
	Reserva(string = "", Fecha* = NULL, Curso* = NULL, Deportista* = NULL);
	virtual~Reserva();

	string getCodigo();
	Fecha* getFecha();
	Curso* getCurso();
	Deportista* getDeportista();

	string toString();

	static Reserva* recuperar(istream&);
	void guardar(ostream&);
};