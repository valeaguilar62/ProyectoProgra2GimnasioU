#pragma once
#include "Expediente.h"
#include"ManejoFecha.h"
#include "Reserva.h"
#include "Interfaz.h"

class Gimnasio
{
private:
	string nombreG;
	Fecha* fechaActual;
	double mensualidad;
	ContenedorTemplate<Deportista>* contenedorClientes;
	ContenedorTemplate<Reserva>* contenedorReservas;
	ContenedorTemplate<Curso>* contenedorCursos;
	ContenedorTemplate<Instructor>* contenedorInstructores;
	ContenedorTemplate<Expediente>* contenedorPagos;

public:
	Gimnasio(string="",Fecha * = NULL, double = 0.0);
	virtual ~Gimnasio();

	void setNombreGym(string);
	void setMensualidad(double);
	void setFecha(Fecha*);

	void guardarContenedorTriatlonista(ostream&);
	void recuperarContenedorTriatlonista(istream&);
	ContenedorTemplate<Reserva>* getContenedorReservas();
	ContenedorTemplate<Curso>* getContenedorCursos();
	void guardarContenedorReserva(ostream&);
	void guardarContenedorCurso(ostream&);
	void guardarContenedorInstructor(ostream&);
	void guardarContenedorExpediente(ostream&);
	void recuperarContenedorReserva(istream&);
	void recuperarContenedorCurso(istream&);
	void recuperarContenedorInstructor(istream&);
	void recuperarContenedorExpediente(istream&);
	void guardarTodoGym();
	void recuperarTodoGym();

	ContenedorTemplate<Deportista>* getContenedorClientes();
	ContenedorTemplate<Expediente>* getContenenedorExpediente();

	bool ingresaCurso();
	bool ingresaGrupo();
	bool ingresaCliente();
	bool ingresaInstructor();
	bool ingresaPago();
	bool ingresaMatriculaCurso();
	bool cancelaMatricula();
	bool editaCurso();
	bool editaCliente();
	bool editaGrupo();

	void mostrarCurso();
	void mostrarGrupo();
	void mostrarClientes();
	void mostrarClienteEspecifico();
	void mostrarExpediente();
	void mostrarClientesActivos();
	void mostrarClientesMorosos();
	void mostrarClientesInactivos();
	void mostrarDeportistasMatriculadosEnCurso();
	void mostrarSoloDeportistas();

	Deportista* retornaDepSegunCed(string ced);
	void setEstadoClientes();

};


