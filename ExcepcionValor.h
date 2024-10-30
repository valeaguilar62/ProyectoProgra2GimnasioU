#pragma once
#include"ExcepcionPrograma.h"

class ExcepcionValor : public ExcepcionPrograma {
public:
	virtual string toString();
};