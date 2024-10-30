#include"Curso.h"

#define CAMPO '\t' //Secuecia de escape: tabulador
#define REGISTR '\n'  //Salto de linea

Curso::Curso(string cod, string nom, int niv, string desc, int num) {
	codigoCurso = cod;
	nombreCurso = nom;
	descripcion = desc;
	setNivel(niv);
	numGrupo = num;
	grupos = new ContenedorTemplate<Grupo>();
}
Curso::Curso(const Curso& c) {
	this->codigoCurso = c.codigoCurso;
	this->nombreCurso = c.nombreCurso;
	this->descripcion = c.descripcion;
	this->nivel = c.nivel;
	this->numGrupo = c.numGrupo;
	this->grupos = c.grupos;
}
Curso::~Curso() {}

void Curso::setCodigoCurso(string cod) {
	codigoCurso = cod;
}
void Curso::setNombreCurso(string nom)
{
	nombreCurso = nom;
}
void Curso::setDescripcion(string desc) {
	descripcion = desc;
}
void Curso::setNumGrupo(int num)
{
	numGrupo = num;
}
void Curso::setNivel(int niv) {
	switch (niv) {
	case 1: nivel = "Principiante"; break;
	case 2: nivel = "Intermedio"; break;
	case 3: nivel = "Avanzado"; break;
	default: nivel = "";break;
	}

}
void Curso::setGrupos(ContenedorTemplate<Grupo>* g) {
	grupos = g;
}

string Curso::getCodigoCurso() {
	return codigoCurso;
}
string Curso::getNombreCurso()
{
	return nombreCurso;
}
string Curso::getDescripcion() {
	return descripcion;
}
string Curso::getNivel() {
	return nivel;
}
int Curso::getNumGrupo()
{
	return numGrupo;
}
ContenedorTemplate<Grupo>* Curso::getGrupos() {
	return grupos;
}

int Curso::retornaNivelString(string niv)
{
	if (niv == "Principiante")return 1;
	if (niv == "Intermedio")return 2;
	if (niv == "Avanzado")return 3;
}

bool Curso::existeMatricula(string ced)
{
	Iterador<Grupo>* iter = new Iterador<Grupo>(grupos->getPpio());
	while (iter->getPNodo() != NULL) {
		if (iter->getPNodo()->getPuntero()->existeMatricula(ced)) {
			delete iter;
			return true;
		}
		iter->siguiente();
	}
	delete iter;
	return false;
}


string Curso::toString()
{
	stringstream out;
	out << "Codigo de curso: " << codigoCurso << endl;
	out << "Nombre: " << nombreCurso << endl;
	out << "Nivel: " << nivel << endl;
	out << "Descripcion: " << descripcion << endl;
	out << "--------------------- GRUPOS ---------------------" << endl;
	out << (grupos->toString()) << endl;
	return out.str();
}
bool Curso::operator==(const Curso& c2) {
	if (this->codigoCurso == c2.codigoCurso)
		return true;
	return false;
}

Curso* Curso::recuperar(istream& leer) {
	string cod;
	string nom;
	string niv;
	string des;
	string num;
	string canti;

	getline(leer, cod, CAMPO);
	getline(leer, nom, CAMPO);
	getline(leer, des, CAMPO);
	getline(leer, niv, CAMPO);
	getline(leer, num, CAMPO);
	getline(leer, canti, CAMPO);
	int cant = convertirInt(num);
	int aux = convertirInt(canti);
	ContenedorTemplate<Grupo>* grupo = new ContenedorTemplate<Grupo>();
	while (aux > 0) {
		Grupo* g1 = Grupo::recuperar(leer);

		grupo->agregarElementoFinal(g1);

		aux--;
	}

	Curso* curso = new Curso(cod, nom, retornaNivelString(niv), des, convertirInt(num));

	curso->setGrupos(grupo);
	return curso;
}

void Curso::guardar(ostream& guar) {
	guar << codigoCurso << CAMPO;
	guar << nombreCurso << CAMPO;
	guar << descripcion << CAMPO;
	guar << nivel << CAMPO;
	guar << numGrupo << CAMPO;
	guar << grupos->cantidadElementos() << CAMPO;
	grupos->guardarTodo(guar);
}