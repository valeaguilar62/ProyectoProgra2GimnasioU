#include "ExcepcionGrupo.h"

ExcepcionGrupo::ExcepcionGrupo(int motv) : motivo(motv) {}

string ExcepcionGrupo::toString()
{
	switch (motivo) {
	case 1: return "Error...no hay cursos y/o instructores registrados.\n";
	case 2: return "Error...el numero de grupos no puede ser modificado a una cantidad menor.\n";
	}
}
