#pragma once
#include"Rango.h"
#include"ExcepcionValor.h"
#include"ExcepcionGrupo.h"
#include"ExcepcionCurso.h"
#include "ContenedorTemplate.h"
#include "Expediente.h"
#include "ManejoFecha.h"
#include "Reserva.h"
using namespace std;

class Interfaz
{
public:
	static Deportista* clonarDeportista(Deportista*);
	static string leerCedula();
	static string leerNombre();
	static string leerTelefono();
	static int leerHorasEntre();
	static double leerTemPromedio();
	static char leerSexo();
	static double leerEstatura();
	static double leerMasaMuscular();
	static double leerPeso();
	static double leerGrasa();
	static int leerCantIron();
	static int leerCantTriat();
	static string leerEstado();

	static int menuEditTriat();
	static int menuEditIns();
	static int menuEditCurso();
	static int menuEditGrupo();
	static bool editaCurso(ContenedorTemplate<Curso>*);
	static bool editaGrupo(ContenedorTemplate<Curso>*, ContenedorTemplate<Instructor>*);

	static Fecha* leerFecha();
	static string leerCodCurso();
	static string leerNombreCurso();
	static string leerDescricionCurso();
	static int leerCupoMaximo();
	static int leerSemanasDuracion();
	static string leerDia();
	static Hora* leerHora();
	static int leerNivelCurso();
	static int leerNumeroGrupos();
	static string leerCodigoReservacion();
	static double leerMensualidad();

	static bool agregaTriatlonista(ContenedorTemplate<Deportista>*, ContenedorTemplate<Instructor>*, ContenedorTemplate<Curso>*, ContenedorTemplate<Reserva>*, Fecha*, ContenedorTemplate<Expediente>*, double);
	static bool editaTriatlonista(ContenedorTemplate<Deportista>*);
	static bool agregaInstructor(ContenedorTemplate<Deportista>*, ContenedorTemplate<Instructor>*);
	static bool agregaCurso(ContenedorTemplate<Curso>*);
	static bool agregaGrupo(ContenedorTemplate<Curso>*, ContenedorTemplate<Instructor>*);
	static void agregaPagos(Expediente*, double, Fecha*,string,string);
	static bool actualizaExpediente(ContenedorTemplate<Expediente>*, double, Fecha*);
	static bool agregaMatriculaEnCurso(ContenedorTemplate<Deportista>*, ContenedorTemplate<Curso>*, ContenedorTemplate<Reserva>*, Fecha*);
	static bool cancelaMatricula(ContenedorTemplate<Curso>*, ContenedorTemplate<Reserva>*);
	static bool eliminaReservacion(string, string, ContenedorTemplate<Reserva>*);
	
	static void mostrarCursoEspecif(ContenedorTemplate<Curso>*);
	static void mostrarGrupoEspecif(ContenedorTemplate<Curso>*);
	static void mostrarClientes(ContenedorTemplate<Deportista>*);
	static void mostrarClientesEspecif(ContenedorTemplate<Deportista>*);
	static void mostrarExpedienteEspecif(ContenedorTemplate<Expediente>*);
	static void mostrarClientesActivos(ContenedorTemplate<Deportista>*);
	static void mostrarClientesMorosos(ContenedorTemplate<Deportista>*);
	static void mostrarClientesInactivos(ContenedorTemplate<Deportista>*);
	static void mostrarDeportistasMatriculadosEnCurso(ContenedorTemplate<Curso>*);

	static void muestraSoloCursos(ContenedorTemplate<Curso>*);
	static void muestraSoloGrupos(ContenedorTemplate<Curso>* coC, int curso);
	static void muestraSoloDeportistas(ContenedorTemplate<Deportista>* coD);
};

