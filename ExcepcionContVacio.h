#pragma once
#include"ExcepcionPrograma.h"

class ExcepcionContVacio : public ExcepcionPrograma {
public:
	virtual string toString() {
		return "Error...no hay elementos registrados.\n";
	}
};