#include "Corredor.h"

Corredor::Corredor(string ced, string nom, string tel, Fecha* nac, char sex, double esta) :Deportista(ced, nom, tel, nac)
{
    sexo = sex;
    estatura = esta;
}

Corredor::~Corredor() = default;


