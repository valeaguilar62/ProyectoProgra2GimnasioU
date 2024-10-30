#include "Pago.h"

Pago::Pago(Fecha* ptr, double dinero, int mes){
    fechaDePago = ptr;
    monto = dinero;
    mesCancelado = mes;
}
Pago:: ~Pago(){
    delete fechaDePago;
}

Fecha* Pago::getFecha() { return fechaDePago; }
double Pago::getMonto() { return monto; }
void Pago::setFecha(Fecha* ptr) { fechaDePago = ptr; }
void Pago::setMonto(double dinero) { monto = dinero; }

void Pago::guardar(ostream& salida)
{
    fechaDePago->guardar(salida);
    salida << mesCancelado << DELIMITA_CAMPO;
    salida << monto << DELIMITA_REGISTRO;
}
Pago* Pago::recuperar(istream& entrada)
{
    string monto, mes;
    Fecha* ptr = Fecha::recuperar(entrada);
    getline(entrada, mes, DELIMITA_CAMPO);
    getline(entrada, monto, DELIMITA_REGISTRO);
    return new Pago(ptr, convertirDouble(monto), convertirInt(mes));
}

string Pago::toString()
{
    stringstream out;
    out << "Fecha de pago: " << fechaDePago->toString() << "Mes cancelado: " << ManejoFecha::queFecha(mesCancelado) << " Monto cancelado: " << monto << endl;
    return out.str();
}

