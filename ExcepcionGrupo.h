#pragma once
#include"ExcepcionPrograma.h"

class ExcepcionGrupo : public ExcepcionPrograma {
private:
	int motivo;
public:
	ExcepcionGrupo(int=0);
	virtual string toString();
};