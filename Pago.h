#pragma once
#include "ManejoFecha.h"
class Pago
{
private: 
	Fecha* fechaDePago;
	double monto;
	int mesCancelado;
public:
	Pago(Fecha*, double, int);
	virtual ~Pago();

	Fecha* getFecha();
	double getMonto();
	void setFecha(Fecha*);
	void setMonto(double);

	void guardar(ostream&);
	static Pago* recuperar(istream&);

	string toString();
};

