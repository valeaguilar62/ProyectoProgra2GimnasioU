#include "Ciclista.h"

Ciclista::Ciclista(int horas, double tem){
    horasEntrenamiento = horas;
    temPromedio = tem;
}

Ciclista::~Ciclista() = default;

void Ciclista::guardar(ostream& salida)
{
    salida << horasEntrenamiento << DELIMITA_CAMPO << temPromedio << DELIMITA_CAMPO;
}

Ciclista* Ciclista::recuperar(istream& entrada)
{
    string horas, tem;

    getline(entrada, horas, DELIMITA_CAMPO);
    getline(entrada, tem, DELIMITA_CAMPO);
    return new Ciclista(convertirInt(horas), convertirDouble(tem));
}

int Ciclista::getHorasEntrenamiento()
{
    return horasEntrenamiento;
}

double Ciclista::getTemPromedio()
{
    return temPromedio;
}

//char Ciclista::getSexo()
//{
//    throw string("Ruta Equivocada");
//    return 0;
//}
//
//double Ciclista::getEstatura()
//{
//    throw string("Ruta Equivocada");
//    return 0.0;
//}
//
//double Ciclista::getMasaMuscular()
//{
//    throw string("Ruta Equivocada");
//    return 0.0;
//}
//
//double Ciclista::getPeso()
//{
//    throw string("Ruta Equivocada");
//    return 0.0;
//}
//
//double Ciclista::getPorcGrasaCorporal()
//{
//    throw string("Ruta Equivocada");
//    return 0.0;
//}
//
//int Ciclista::getCantParticIronMan()
//{
//    throw string("Ruta Equivocada");
//    return 0;
//}
//
//int Ciclista::getCantTriatGanados()
//{
//    throw string("Ruta Equivocada");
//    return 0;
//}

void Ciclista::setHorasEntrenamiento(int horas)
{
    horasEntrenamiento = horas;
}

void Ciclista::setTemPromedio(double tem)
{
    temPromedio = tem;
}

//void Ciclista::setSexo(char sex)
//{
//    throw string("Ruta Equivocada");
//}
//
//void Ciclista::setEstatura(double esta)
//{
//    throw string("Ruta Equivocada");
//}
//
//void Ciclista::setMasaMuscular(double masa)
//{
//    throw string("Ruta Equivocada");
//}
//
//void Ciclista::setPeso(double)
//{
//    throw string("Ruta Equivocada");
//}
//
//void Ciclista::setPorcGrasa(double grasa)
//{
//    throw string("Ruta Equivocada");
//}
//
//void Ciclista::setCantIronMan(int num)
//{
//    throw string("Ruta Equivocada");
//}
//
//void Ciclista::setCantTriat(int num)
//{
//    throw string("Ruta Equivocada");
//}

ostream& operator<<(ostream& out, const Ciclista& ciclista)
{
    out << "Horas de entrenamiento: " << ciclista.horasEntrenamiento << endl << "Temperatura promedio: " << ciclista.temPromedio << endl;
    return out;
}
