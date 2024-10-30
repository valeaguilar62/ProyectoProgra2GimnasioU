#include"Instructor.h"
Instructor::Instructor(string id, string nom) : nombreI(nom), cedulaI(id) {}
Instructor::Instructor(const Instructor& i) {
	if ((&i) == NULL) {
		this->nombreI = "";
		this->cedulaI = "";
	}
	else {
		this->nombreI = i.nombreI;
		this->cedulaI = i.cedulaI;
	}
}


void Instructor::setIdInstructor(string id) { cedulaI = id; }
void Instructor::setNombreInstructor(string nom) { nombreI = nom; }
string Instructor::getIdInstructor() { return cedulaI; }
string Instructor::getNombreInstructor() { return nombreI; }

void Instructor::guardar(ostream& salida) {
	salida << cedulaI << DELIMITA_CAMPO;
	salida << nombreI << DELIMITA_CAMPO;
}
Instructor* Instructor::recuperar(istream& entrada) {
	string nom, ced;
	getline(entrada, ced, DELIMITA_CAMPO);
	getline(entrada, nom, DELIMITA_CAMPO);
	return new Instructor(ced, nom);
}

ostream& operator <<(ostream& out, const Instructor& i) {
	out << "Nombre del instructor: " << i.nombreI << endl;
	out << "Cedula: " << i.cedulaI << endl;
	return out;
}
string Instructor::toString()
{
	stringstream out;
	out << "Nombre del instructor: " << nombreI << endl;
	out << "Cedula: " << cedulaI << endl;
	return out.str();
}

bool Instructor::operator==(const Instructor& i2) {
	if (this->cedulaI == i2.cedulaI)
		return true;
	return false;
}
void Instructor::editar()
{
	int opcion = InterfazTriatlonista::menuEditInst();
	switch (opcion)
	{
	case 1: cedulaI = InterfazTriatlonista::leerCedula(); break;
	case 2: nombreI = InterfazTriatlonista::leerNombre(); 
	}
}
