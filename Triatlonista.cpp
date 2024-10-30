#include "Triatlonista.h"

Triatlonista::Triatlonista(string ced, string nom, string tel, Fecha* nac, char sex, double esta, int horas, double tem, double masa, double peso, double grasa, int iron, int triat, Fecha* actual){
	cedula = ced;
	nombre = nom;
	telefono = tel;
	fechaNacimiento = nac;
	sexo = sex;
	estatura = esta;
	ptrNadador = new Nadador(masa, peso, grasa);
	ptrCiclista = new Ciclista(horas, tem);
	cantParticiEnIronMan = iron;
	cantTriatGanados = triat;
	estado = "Activo";
	fechaRegistro = actual;
}
Triatlonista::Triatlonista(Triatlonista& t) {
	this->cedula = t.cedula;
	this->nombre = t.nombre;
	this->telefono = t.telefono;
	this->fechaNacimiento = t.fechaNacimiento;
	this->sexo = t.sexo;
	this->estatura = t.estatura;
	this->ptrNadador = t.ptrNadador;
	this->ptrCiclista = t.ptrCiclista;
	this->fechaRegistro = t.fechaRegistro;
	this->estado = t.estado;
	this->cantParticiEnIronMan = t.cantParticiEnIronMan;
	this->cantTriatGanados = t.cantTriatGanados;
}

Triatlonista::~Triatlonista()
{
	delete fechaNacimiento;
	delete fechaRegistro;
	delete ptrNadador;
	delete ptrCiclista;
}

void Triatlonista::guardar(ostream& salida)
{
	fechaNacimiento->guardar(salida);
	fechaRegistro->guardar(salida);
	salida << cedula << DELIMITA_CAMPO << nombre << DELIMITA_CAMPO << telefono << DELIMITA_CAMPO << sexo << DELIMITA_CAMPO << estatura << DELIMITA_CAMPO;
	ptrCiclista->guardar(salida);
	ptrNadador->guardar(salida);
	salida << estado<<DELIMITA_CAMPO<<cantParticiEnIronMan << DELIMITA_CAMPO << cantTriatGanados << DELIMITA_REGISTRO;
}

Triatlonista* Triatlonista::recuperar(istream& entrada)
{
	string nom, ced, tel, sex, esta, iron, triat, activ;
	Fecha* fec1 = NULL;
	Fecha* fec2 = NULL;
	string temProm, masaM, peso, grasa;
	string hora;
	
	fec1 = Fecha::recuperar(entrada);
	fec2 = Fecha::recuperar(entrada);
	getline(entrada, ced, DELIMITA_CAMPO);
	getline(entrada, nom, DELIMITA_CAMPO);
	getline(entrada, tel, DELIMITA_CAMPO);
	getline(entrada, sex, DELIMITA_CAMPO);
	getline(entrada, esta, DELIMITA_CAMPO);
	getline(entrada, hora, DELIMITA_CAMPO);
	getline(entrada, temProm, DELIMITA_CAMPO);
	getline(entrada, masaM, DELIMITA_CAMPO);
	getline(entrada, peso, DELIMITA_CAMPO);
	getline(entrada, grasa, DELIMITA_CAMPO);
	getline(entrada, activ, DELIMITA_CAMPO);
	getline(entrada, iron, DELIMITA_CAMPO);
	getline(entrada, triat, DELIMITA_REGISTRO);
	
	Triatlonista* ptr = new Triatlonista(ced, nom, tel, fec1, convertirChar(sex), convertirDouble(esta), convertirInt(hora), convertirDouble(temProm), convertirDouble(masaM), convertirDouble(peso), convertirDouble(grasa), convertirInt(iron), convertirInt(triat),fec2);
	ptr->setEstado(activ);
	return ptr;
}

int Triatlonista::getHorasEntrenamiento()
{
	return ptrCiclista->getHorasEntrenamiento();
}

double Triatlonista::getTemPromedio()
{
	return ptrCiclista->getTemPromedio();
}

double Triatlonista::getMasaMuscular()
{
	return ptrNadador->getMasaMuscular();
}

double Triatlonista::getPeso()
{
	return ptrNadador->getPeso();
}

double Triatlonista::getPorcGrasaCorporal()
{
	return ptrNadador->getPorcGrasaCorporal();
}

int Triatlonista::getCantParticIronMan()
{
	return cantParticiEnIronMan;
}

int Triatlonista::getCantTriatGanados()
{
	return cantTriatGanados;
}

Fecha* Triatlonista::getFechaRegistro()
{
	return fechaRegistro;
}

string Triatlonista::getEstado()
{
	return estado;
}

void Triatlonista::setHorasEntrenamiento(int hora)
{
	ptrCiclista->setHorasEntrenamiento(hora);
}

void Triatlonista::setTemPromedio(double tem)
{
	ptrCiclista->setTemPromedio(tem);
}

void Triatlonista::setMasaMuscular(double masa)
{
	ptrNadador->setMasaMuscular(masa);
}

void Triatlonista::setPeso(double peso)
{
	ptrNadador->setPeso(peso);
}

void Triatlonista::setPorcGrasa(double grasa)
{
	ptrNadador->setPorcGrasa(grasa);
}
void Triatlonista::setCantIronMan(int num)
{
	cantParticiEnIronMan = num;
}

void Triatlonista::setCantTriat(int num)
{
	cantTriatGanados = num;
}

void Triatlonista::setFechaRegistro(Fecha* ptr)
{
	fechaRegistro = ptr;
}

void Triatlonista::setEstado(string est)
{
	estado = est;
}

string Triatlonista::toString()
{
	stringstream out;
	out << "Fecha de nacimiento: " << fechaNacimiento->toString();
	out << "Fecha de registro: " << fechaRegistro->toString();
	out << "Cedula: " << cedula << endl << "Nombre: " << nombre << endl << "Telefono: " << telefono << endl << "Sexo: " << sexo << endl << "Estatura: " << estatura << endl;
	out << "Estado:" << estado << endl;
	out << *(ptrCiclista);
	out << *(ptrNadador);
	out << "Cantidad de participaciones en Iron Man: " << cantParticiEnIronMan << endl << "Cantidad de tritlones ganados: " << cantTriatGanados << endl;
	return out.str();
}

bool Triatlonista::operator!=(const Triatlonista& t2)
{
	return this->cedula != t2.cedula;
}



//void Triatlonista::editar()
//{
//	int opcion = InterfazTriatlonista::menuEditTriat();
//	switch (opcion)
//	{
//	case 1: cedula = InterfazTriatlonista::leerCedula(); break;
//	case 2: nombre = InterfazTriatlonista::leerNombre(); break;
//	case 3: telefono = InterfazTriatlonista::leerTelefono(); break;
//	case 4: fechaNacimiento = InterfazTriatlonista::leerFecha(); break;
//	case 5: setHorasEntrenamiento(InterfazTriatlonista::leerHorasEntre()); break;
//	case 6: setTemPromedio(InterfazTriatlonista::leerTemPromedio()); break;
//	case 7: sexo = InterfazTriatlonista::leerSexo(); break;
//	case 8: estatura = InterfazTriatlonista::leerEstatura(); break;
//	case 9: setMasaMuscular(InterfazTriatlonista::leerMasaMuscular()); break;
//	case 10: setPeso(InterfazTriatlonista::leerPeso()); break;
//	case 11: setPorcGrasa(InterfazTriatlonista::leerGrasa()); break;
//	case 12: cantParticiEnIronMan = InterfazTriatlonista::leerCantIron();break;
//	case 13: cantTriatGanados = InterfazTriatlonista::leerCantTriat();
//
//	}
//}

//
//ostream& operator << (ostream& out, const Triatlonista& p)
//{
//	out << "Fecha de nacimiento: " << * (p.fechaNacimiento);
//	out << "Fecha de registro: " << *(p.fechaRegistro);
//	out << "Cedula: " << p.cedula << endl << "Nombre: " << p.nombre << endl << "Telefono: " << p.telefono << endl << "Sexo: " << p.sexo << endl << "Estatura: " << p.estatura << endl;
//	out << "Estado" << p.estado << endl;
//	out << *(p.ptrCiclista);
//	out << *(p.ptrNadador);
//	out << "Cantidad de participaciones en Iron Man: " << p.cantParticiEnIronMan << endl << "Cantidad de tritlones ganados: " << p.cantTriatGanados << endl;
//	return out;
//}
Fecha* Triatlonista::getFechaNacimiento()
{
	return fechaNacimiento;
}
;

string Triatlonista::getCedula()
{
	return cedula;
}

string Triatlonista::getNombre()
{
	return nombre;
}

string Triatlonista::getTelefono()
{
	return telefono;
}

void Triatlonista::setCedula(string ced)
{
	cedula = ced;
}

void Triatlonista::setNombre(string nom)
{
	nombre = nom;
}

void Triatlonista::setTelefono(string tel)
{
	telefono = tel;
}

void Triatlonista::setFechaNacimiento(Fecha* ptr)
{
	fechaNacimiento = ptr;
}
char Triatlonista::getSexo()
{
	return sexo;
}

double Triatlonista::getEstatura()
{
	return estatura;
}

void Triatlonista::setSexo(char sex)
{
	sexo = sex;
}

void Triatlonista::setEstatura(double esta)
{
	estatura = esta;
}