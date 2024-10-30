#pragma once
#include "ManejoFecha.h"
#include "Gimnasio.h"
#include"ExcepcionCurso.h"
#include"ExcepcionInstructor.h"
#include"ExcepcionContVacio.h"

class Vista {
public:
	static Gimnasio* G1;
public:

	static void recuperarTodoVista();
	static void guardarTodoVista();
	static void bienvenida();
	static int menuGeneral();

	static int menuAdministracionGeneral();
	static int menuControlDeportistas();
	static int menuControlCursos();
	static int menuControlGrupos();
	static int menuControlInstructores();
	static int menuControPagos();

	static void funcionesAdministracionGeneral(int);
	static void listadoDeDeportistas();
	static void funcionesControlDeportistas(int);
	static void funcionesControlCursos(int);
	static void funcionesControlGrupos(int);
	static void funcionesControlInstructor(int);
	static void funcionesControlPagos(int);
};