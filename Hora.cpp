#include"Hora.h"

Hora::Hora(int h, int m) :horas(h), minutos(m) {}
Hora::Hora(Hora& ptr) {
	if ((&ptr) == NULL) {
		horas = 0;
		minutos = 0;
	}
	else {
		horas = ptr.horas;
		minutos = ptr.minutos;
	}
}
Hora::~Hora() {}

void Hora::guardar(ostream& salida) {
	salida << horas << DELIMITA_CAMPO << minutos << DELIMITA_CAMPO;
}
Hora* Hora::recuperar(istream& entrada) {
	string h, m;
	getline(entrada, h, DELIMITA_CAMPO);
	getline(entrada, m, DELIMITA_CAMPO);
	return new Hora(convertirInt(h), convertirInt(m));
}

ostream& operator <<(ostream& out, const Hora& p) {
	out << p.horas << " : " << p.minutos;
	return out;
}