#pragma once
#include"Fecha.h"
#include"Hora.h"
#include"Grupo.h"
#include"ContenedorTemplate.h"

class Curso {
private:
	string codigoCurso;
	string nombreCurso;
	string nivel;
	string descripcion;
	int numGrupo;
	ContenedorTemplate<Grupo>* grupos;

public:
	Curso(string = "", string = "", int = 0, string = "", int = 0);
	Curso(const Curso&);
	virtual~Curso();

	void setCodigoCurso(string cod);
	void setNombreCurso(string nom);
	void setNivel(int niv);
	void setDescripcion(string desc);
	void setNumGrupo(int num);
	void setGrupos(ContenedorTemplate<Grupo>*);

	string getCodigoCurso();
	string getNombreCurso();
	string getDescripcion();
	string getNivel();
	int getNumGrupo();
	ContenedorTemplate<Grupo>* getGrupos();

	static int retornaNivelString(string);

	bool existeMatricula(string);
	string toString();
	bool operator==(const Curso&);

	static Curso* recuperar(istream&);
	void guardar(ostream&);

};