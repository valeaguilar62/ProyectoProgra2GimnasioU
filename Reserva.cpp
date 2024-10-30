#include"Reserva.h"

Reserva::Reserva(string cod, Fecha* fPtr, Curso* cPtr, Deportista* dPtr) {
	codigo = cod;
	fechaReserva = new Fecha(*fPtr);
	ptrCurso = new Curso(*cPtr);
	ptrDeportista = dPtr;
}
Reserva::~Reserva() {
	if (ptrCurso != NULL)
		delete ptrCurso;
	if (ptrDeportista != NULL)
		delete ptrDeportista;
}

string Reserva::getCodigo() { return codigo; }
Fecha* Reserva::getFecha() { return fechaReserva; }
Curso* Reserva::getCurso() { return ptrCurso; }
Deportista* Reserva::getDeportista() { return ptrDeportista; }


string Reserva::toString()
{
	stringstream out;
	out << "Codigo de la reserva: " << codigo << endl;
	out << "Fecha de reservacion: " << fechaReserva->toString() << endl;
	out << "Curso reservado: " << ptrCurso->getCodigoCurso() << endl;
	out << "Reserva realizada por cliente con cedula: " << ptrDeportista->getCedula() << endl;
	return out.str();
}

Reserva* Reserva::recuperar(istream& leer) {

	string cod;
	getline(leer, cod, DELIMITA_CAMPO);
	Fecha* fecha = Fecha::recuperar(leer);
	Curso* curso = Curso::recuperar(leer);
	Deportista* deportista = Triatlonista::recuperar(leer);
	return new Reserva(cod, fecha, curso, deportista);
}
void Reserva::guardar(ostream& guardar) {

	guardar << codigo << DELIMITA_CAMPO;
	fechaReserva->guardar(guardar);
	ptrCurso->guardar(guardar);
	ptrDeportista->guardar(guardar);

}