#pragma once
#include"ExcepcionPrograma.h"

class ExcepcionRango : public ExcepcionPrograma {
public:
	virtual string toString();
};