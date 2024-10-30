#include"Expediente.h"
#include"ContenedorTemplate.h"

Expediente::Expediente(Deportista* ptrDeportista) {
	cedula = ptrDeportista->getCedula();
	nombre = ptrDeportista->getNombre();
	registroPagos = new ContenedorTemplate<Pago>();
}
Expediente:: ~Expediente() {}

ContenedorTemplate<Pago>* Expediente::getPagos() { return registroPagos; }
string Expediente::getCedula() { return cedula; }
string Expediente::getNombre() { return nombre; }
int Expediente::getCant() { return registroPagos->cantidadElementos(); }

void Expediente::setCedula(string ced) { cedula = ced; }
void Expediente::setNombre(string nom) { nombre = nom; }
void Expediente::setRegistroPagos(ContenedorTemplate<Pago>* ptr) { registroPagos = ptr; }

void  Expediente::guardar(ostream& salida) {
	salida << cedula << DELIMITA_CAMPO;
	salida << nombre << DELIMITA_CAMPO;
	salida << registroPagos->cantidadElementos() << DELIMITA_REGISTRO;
	registroPagos->guardarTodo(salida);
}
Expediente* Expediente::recuperar(istream& entrada) {
	string ced, nom;
	string cant;

	int cont = 0;
	
	getline(entrada, ced, DELIMITA_CAMPO);
	getline(entrada, nom, DELIMITA_CAMPO);
	getline(entrada, cant, DELIMITA_REGISTRO);
	ContenedorTemplate<Pago>* pagos = new ContenedorTemplate<Pago>();
	while (cont < convertirInt(cant)) {
		Pago* p1 = Pago::recuperar(entrada);
		pagos->agregarElementoFinal(p1);
		cont++;
	}

	Triatlonista* auxDep = new Triatlonista(ced, nom);
	Expediente* auxExp = new Expediente(auxDep);
	auxExp->setRegistroPagos(pagos);
	return auxExp;
}

string Expediente::toString()
{
	stringstream out;
	out << "------------------- EXPEDIENTE -------------------" << endl
		<< "Cedula: " << cedula << endl
		<< "Nombre: " << nombre << endl
		<< (registroPagos->toString()) << endl;
	return out.str();
}
