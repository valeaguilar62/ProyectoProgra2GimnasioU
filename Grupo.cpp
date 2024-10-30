#include "Grupo.h"

Grupo::Grupo(int numG, Instructor* i, int cupMax, Fecha* FIni, int sem, string d, Hora* HIni, Hora* HFini) {
	numDeGrupo = numG;
	ptrInstructor = new Instructor(*i);
	cupoMaximo = cupMax;
	cupoActual = cupMax;
	fechaInicio = new Fecha(*FIni);
	semanasDuracion = sem;
	dia = d;
	horaInicio = new Hora(*HIni);
	horaFinalizacion = new Hora(*HFini);
	integrantes = new ContenedorTemplate<Deportista>();
}
Grupo::~Grupo() {
	if (ptrInstructor != NULL)
		delete ptrInstructor;
	if (fechaInicio != NULL)
		delete fechaInicio;
	if (horaInicio != NULL)
		delete horaInicio;
	if (horaFinalizacion != NULL)
		delete horaFinalizacion;
}

void Grupo::setNumGrupo(int n) {
	numDeGrupo = n;
}
void Grupo::setIntructor(Instructor* i) {
	if (ptrInstructor != NULL)
		delete ptrInstructor;
	ptrInstructor = new Instructor(*i);
}
void Grupo::setCupoActual(int cup) {
	cupoActual = cup;
}
void Grupo::setCupoMaximo(int cup) {
	cupoMaximo = cup;
}
void Grupo::setSemanasDuracion(int sem) {
	semanasDuracion = sem;
}
void Grupo::setDia(string d) {
	dia = d;
}
void Grupo::setFechaIncio(Fecha* ptr) {
	fechaInicio = ptr;
}
void Grupo::setHoraInicio(Hora* ptr) {
	horaInicio = ptr;
}
void Grupo::setHoraFinal(Hora* ptr) {
	horaFinalizacion = ptr;
}
void Grupo::setIntegrantes(ContenedorTemplate<Deportista>* l) {
	this->integrantes = l;
}

int Grupo::getNumGrupo() {
	return numDeGrupo;
}
Instructor* Grupo::getInstructor() {
	return ptrInstructor;
}
void Grupo::setInstructor(Instructor* ptr)
{
	ptrInstructor = ptr;
}
int Grupo::getCupoActual() {
	return cupoActual;
}
int Grupo::getCupoMaximo() {
	return cupoMaximo;
}
int Grupo::getSemanasDuracion() {
	return semanasDuracion;
}
bool Grupo::hayEspacio()
{
	return cupoActual!=0;
}
string Grupo::getDia() {
	return dia;
}
Fecha* Grupo::getFechaIncio() {
	return fechaInicio;
}
Hora* Grupo::getHoraInicio() {
	return horaInicio;
}
Hora* Grupo::getHoraFinal() {
	return horaFinalizacion;
}
ContenedorTemplate<Deportista>* Grupo::getIntegrantes() {
	return integrantes;
}

bool Grupo::existeMatricula(string ced)
{
	Iterador<Deportista>* iter = new Iterador<Deportista>(integrantes->getPpio());
	while (iter->getPNodo() != NULL) {
		if (iter->actual()->getCedula() == ced) {
			return true;
		}
		iter->siguiente();
	}
	return false;
}


bool Grupo::ingresarIntegrante(Deportista* t) {
	if (cupoActual > 0) {
		integrantes->agregarElemento(t);
		cupoActual--;
		return true;
	}
	return false;
}
bool Grupo::operator==(const Grupo& g2) {
	if (this->numDeGrupo == g2.numDeGrupo)
		return true;
	return false;
}

string Grupo::toString()
{
	stringstream out;
	out << "Grupo #" << numDeGrupo << endl << ptrInstructor->toString()<< endl <<
		"Cupo Maximo: " << cupoMaximo << endl <<
		"Fecha de INICIO: " << fechaInicio->toString() << endl <<
		"Duracion: " << semanasDuracion << " semanas" << endl <<
		"Horario: " << endl <<
		"	Dia de la semana: " << dia << endl <<
		"	Hora de INICIO: " << *(horaInicio) << endl <<
		"	Hora de FINALIZACION: " << *(horaFinalizacion) << endl <<
		"------------- INTEGRANTES del curso --------------" << endl << (integrantes->toString()) << endl;
	return out.str();
}




void Grupo::guardar(ostream& guar) {

	guar << numDeGrupo << CAMPO;
	ptrInstructor->guardar(guar);
	guar << cupoActual << CAMPO;
	guar << cupoMaximo << CAMPO;
	fechaInicio->guardar(guar);
	guar << semanasDuracion << CAMPO;
	horaInicio->guardar(guar);
	horaFinalizacion->guardar(guar);
	guar << dia << CAMPO;

	integrantes->guardarTodo(guar);
}
Grupo* Grupo::recuperar(istream& entrada) {

	string numGrupo;
	string cupAc;
	string cupMax;
	string semanas;
	string d;
	int cupAcAux = 0, cupMaxAux = 0;

	getline(entrada, numGrupo, DELIMITA_CAMPO);
	Instructor* inst = Instructor::recuperar(entrada);
	getline(entrada, cupAc, DELIMITA_CAMPO);
	getline(entrada, cupMax, DELIMITA_CAMPO);
	Fecha* fecha = Fecha::recuperar(entrada);
	getline(entrada, semanas, DELIMITA_CAMPO);
	Hora* horaI = Hora::recuperar(entrada);
	Hora* horaF = Hora::recuperar(entrada);
	getline(entrada, d, DELIMITA_CAMPO);

	int cupo = convertirInt(cupMax) - convertirInt(cupAc);
	ContenedorTemplate<Deportista>* inte = new ContenedorTemplate<Deportista>();
	while (cupo>0) {
		Deportista* tir = Triatlonista::recuperar(entrada);
		inte->agregarElementoFinal(tir);
		cupo--;
	}

	Grupo* grup = new Grupo(convertirInt(numGrupo), inst, convertirInt(cupMax), fecha, convertirInt(semanas), d, horaI, horaF);
	grup->setIntegrantes(inte);
	grup->setCupoActual(convertirInt(cupAc));

	return grup;
}