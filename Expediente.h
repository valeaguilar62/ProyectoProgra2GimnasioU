#pragma once
#include "ContenedorTemplate.h"
#include "Triatlonista.h"
#include "Pago.h"

class Expediente {
private:
	string cedula;
	string nombre;
	ContenedorTemplate<Pago>* registroPagos;
public:

	Expediente(Deportista*);
	virtual ~Expediente();

	ContenedorTemplate<Pago>* getPagos();
	string getCedula();
	string getNombre();
	int getCant();

	void setCedula(string);
	void setNombre(string);
	void setRegistroPagos(ContenedorTemplate<Pago>*);

	void guardar(ostream&);
	static Expediente* recuperar(istream&);

	string toString();
};
