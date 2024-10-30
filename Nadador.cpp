#include "Nadador.h"

double Nadador::getMasaMuscular()
{
    return masaMuscular;
}

double Nadador::getPeso()
{
    return peso;
}

double Nadador::getPorcGrasaCorporal()
{
    return porcGrasaCorporal;
}

Nadador::Nadador(double musc, double peso, double grasa){
    masaMuscular = musc;
    this->peso = peso;
    porcGrasaCorporal = grasa;
}

Nadador::~Nadador() = default;

void Nadador::guardar(ostream& salida)
{
    salida << masaMuscular << DELIMITA_CAMPO << peso << DELIMITA_CAMPO << porcGrasaCorporal << DELIMITA_CAMPO;
}

Nadador* Nadador::recuperar(istream& entrada)
{
    string masa, pes, grasa;
    getline(entrada, masa, DELIMITA_CAMPO);
    getline(entrada, pes, DELIMITA_CAMPO);
    getline(entrada, grasa, DELIMITA_CAMPO);
    return new Nadador(convertirDouble(masa), convertirDouble(pes), convertirDouble(grasa));
}


void Nadador::setMasaMuscular(double masa)
{
    masaMuscular = masa;
}

void Nadador::setPeso(double pes)
{
    peso = pes;
}

void Nadador::setPorcGrasa(double grasa)
{
    porcGrasaCorporal = grasa;
}

ostream& operator<<(ostream& out, const Nadador& nadador)
{
    out << "Porcentaje de masa muscular: " << nadador.masaMuscular << endl << "Peso: " << nadador.peso << endl << "Porcentaje de grasa corporal: " << nadador.porcGrasaCorporal << endl;
    return out;
}
