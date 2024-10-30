#pragma once
#include"Fecha.h"
#include"Hora.h"
#include"Instructor.h"
#include"Triatlonista.h"
#include"ContenedorTemplate.h"
#define CAMPO '\t' //Secuecia de escape: tabulador
#define REGISTR '\n'  //Salto de linea

class Grupo {
private:
	int numDeGrupo;
	Instructor* ptrInstructor;
	int cupoActual;
	int cupoMaximo;
	Fecha* fechaInicio;
	int semanasDuracion;
	string dia;
	Hora* horaInicio;
	Hora* horaFinalizacion;
	ContenedorTemplate<Deportista>* integrantes;

public:
	Grupo(int = 0, Instructor* = NULL, int = 0, Fecha* = NULL, int = 0, string = "", Hora* = NULL, Hora* = NULL);
	virtual ~Grupo();

	void setNumGrupo(int);
	void setIntructor(Instructor*);
	void setCupoActual(int cup);
	void setCupoMaximo(int cup);
	void setSemanasDuracion(int sem);
	void setDia(string d);
	void setFechaIncio(Fecha* ptr);
	void setHoraInicio(Hora* ptr);
	void setHoraFinal(Hora* ptr);
	void setIntegrantes(ContenedorTemplate<Deportista>*);
	void setInstructor(Instructor*);

	int getNumGrupo();
	Instructor* getInstructor();
	int getCupoActual();
	int getCupoMaximo();
	int getSemanasDuracion();
	bool hayEspacio();
	string getDia();
	Fecha* getFechaIncio();
	Hora* getHoraInicio();
	Hora* getHoraFinal();
	ContenedorTemplate<Deportista>* getIntegrantes();

	bool existeMatricula(string);
	bool ingresarIntegrante(Deportista*);
	bool operator==(const Grupo&);

	string toString();

	void guardar(ostream& guar);
	static Grupo* recuperar(istream&);

};