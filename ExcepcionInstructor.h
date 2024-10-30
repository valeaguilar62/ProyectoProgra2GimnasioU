#pragma once
#include"ExcepcionPrograma.h"

class ExcepcionInstructor : public ExcepcionPrograma {
public:
	virtual string toString();
};