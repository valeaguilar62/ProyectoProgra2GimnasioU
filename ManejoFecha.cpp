#include "ManejoFecha.h"

string ManejoFecha::queFecha(int mes)
{
	string fecha;
	
	switch (mes)
	{
	case 1: fecha = "Enero"; break;
	case 2: fecha = "Febrero"; break;
	case 3: fecha = "Marzo"; break;
	case 4: fecha = "Abril"; break;
	case 5: fecha = "Mayo"; break;
	case 6: fecha = "Junio"; break;
	case 7: fecha = "Julio"; break;
	case 8: fecha = "Agosto"; break;
	case 9: fecha = "Septiembre"; break;
	case 10: fecha = "Octubre"; break;
	case 11: fecha = "Noviembre"; break;
	case 12: fecha = "Diciembre"; 
	}
	return fecha;
}

int ManejoFecha::incrementaFecha(Fecha* fecha)
{
	/*Fecha* ptr = new Fecha(fecha->getDia(), fecha->getMes(), fecha->getAnio());
	if (ptr->getDia() == 28 && ptr->getMes() == 2) {
		ptr->setDia(1);
		ptr->setMes(ptr->getMes() + 1);
	}
	else {
		if (ptr->getDia() == 30) {
			if (ptr->getMes() == 4 || ptr->getMes() == 6 || ptr->getMes() == 9 || ptr->getMes() == 11) {
				ptr->setDia(1);
				ptr->setMes(ptr->getMes() + 1);
			}
			else {
				if (ptr->getDia() == 31) {
					if (ptr->getMes() == 12) {
						ptr->setDia(1);
						ptr->setMes(1);
						ptr->setAnio(ptr->getAnio() + 1);
					}
					else {
						ptr->setDia(1);
						ptr->setMes(ptr->getMes() + 1);
					}
				}
				else {
					ptr->setDia(ptr->getDia() + 1);
				}
			}
		}
	}*/
	int mes = 0;
	if (fecha->getMes() == 12) {
		mes = 1;
	}
	else {
		mes = fecha->getMes() + 1;
	}
	return mes;
}
