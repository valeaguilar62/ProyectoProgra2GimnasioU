#include "Fecha.h"
Fecha::Fecha(int d, int m, int a) :dia(d), mes(m), anio(a) {}
Fecha::Fecha(Fecha& ptr)
{
	if ((&ptr) == NULL) {
		dia = 0;
		mes = 0;
		anio = 0;
	}
	else {
		dia = ptr.dia;
		mes = ptr.mes;
		anio = ptr.anio;
	}
}
Fecha::~Fecha() {}

int Fecha::getDia()
{
	return dia;
}
int Fecha::getMes()
{
	return mes;
}
int Fecha::getAnio()
{
	return anio;
}

void Fecha::setDia(int d)
{
	dia = d;
}
void Fecha::setMes(int m)
{
	mes = m;
}
void Fecha::setAnio(int a)
{
	anio = a;
}

void Fecha::guardar(ostream& salida)
{
	salida << dia << DELIMITA_CAMPO << mes << DELIMITA_CAMPO << anio << DELIMITA_CAMPO;
}
Fecha* Fecha::recuperar(istream& entrada)
{
	string d, m, a;
	getline(entrada, d, DELIMITA_CAMPO);
	getline(entrada, m, DELIMITA_CAMPO);
	getline(entrada, a, DELIMITA_CAMPO);
	return new Fecha(convertirInt(d), convertirInt(m), convertirInt(a));
}

bool Fecha::operator>(const Fecha& fecha)
{
	if (this->anio > fecha.anio) { return true; }
	if (this->mes > fecha.mes) { return true; }
	if (this->anio == fecha.anio && this->mes == fecha.mes) {
		if (this->dia > fecha.dia) { return true; }
	}
	return false;
}

string Fecha::toString()
{
	stringstream out;
	out << dia << " / " << mes << " / " << anio << endl;
	return out.str();
}
