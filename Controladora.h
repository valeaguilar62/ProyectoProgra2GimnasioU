#pragma once
#include"ExcepcionCurso.h"
#include"ExcepcionInstructor.h"
#include"ExcepcionContVacio.h"
#include"Vista.h"

class Controladora {
public:
	static void control0();
	static void controlBienvenida();

	static int control1();
	static void control2();
	static void control3();
	
	
	static int control4();
	static void control5();
	static void control6();

	static int control7();
	static void control8();
	static void control9();

	static int control10();
	static void control11();
	static void control12();

	static int control13();
	static void control14();
	static void control15();

	static int control16();
	static void control17();
	static void control18();

	static void control19Guardar();

	static int control20();
	static void control21(int);
	static bool control22(int);

	static int control23();
	static void control24();
};

#include"Controladora.h"

void Controladora::controlBienvenida() {
	Vista::recuperarTodoVista();
	Vista::bienvenida();
}

int Controladora::control1() {
	return Vista::menuAdministracionGeneral();
}
void Controladora::control2() {
	int op = 0;
	do {
		op = control1();
		Vista::funcionesAdministracionGeneral(op);
		system("pause");
		system("cls");
	} while (op != 3);
}
void Controladora::control3() {
		Controladora::control2();
}

int Controladora::control4() {
	return Vista::menuControlDeportistas();
}
void Controladora::control5() {
	int op = 0;
	do {
		op = control4();
		Vista::funcionesControlDeportistas(op);
		system("pause");
		system("cls");
	} while (op != 5);
}
void Controladora::control6() {
	control5();
}

int Controladora::control7() {
	return Vista::menuControlCursos();
}
void Controladora::control8() {
	int op = 0;
	do {
		op = control7();
		Vista::funcionesControlCursos(op);
		system("pause");
		system("cls");

	} while (op != 4);
}
void Controladora::control9() {
		control8();
}

int Controladora::control10() {
	return Vista::menuControlGrupos();
}
void Controladora::control11() {
	int op = 0;
	do {
		op = control10();
		Vista::funcionesControlGrupos(op);
		system("pause");
		system("cls");
	} while (op != 7);
}
void Controladora::control12() {
	control11();
}

int Controladora::control13() {
	return Vista::menuControlInstructores();
}
void Controladora::control14() {
	int op = 0;
	do {
		op = control13();
		Vista::funcionesControlInstructor(op);
		system("pause");
		system("cls");
	} while (op != 2);
}
void Controladora::control15() {
	control14();
}

int Controladora::control16() {
	return Vista::menuControPagos();
}
void Controladora::control17() {
	int op = 0;
	do {
		op = control16();
		Vista::funcionesControlPagos(op);
		system("pause");
		system("cls");
	} while (op != 3);
}
void Controladora::control18() {
	control17();
}

void Controladora::control19Guardar() {
	Vista::guardarTodoVista();
	
}

int Controladora::control20() {
	return Vista::menuGeneral();
}
void Controladora::control21(int op) {
	switch (op) {
		case 1: {
			//  1 - Administracion general
			control3();
			break;
		}
		case 2: {
			// 2 - Control deportistas. 
			control6();
			break;
		}
		case 3: {
			// 3 - Control de cursos.
			control9();
			break;
		}
		case 4: {
			//4 - Control de grupos. 
			control12();
			op = 0;
			break;
		}
		case 5: { // 5 - Control de instructores
			control15();
			break;
		}
		case 6: {
			// 6 - Control de pagos. 
			control18();
			break;
		}
		case 7: {
			// 7 - Guardar en archivos y salir.
			control19Guardar();
			break;
		}
	}
}
bool Controladora::control22(int op) {
	if (op == 7) 
		return true;
	return false;
}

int Controladora::control23() {
	int op = 0;
	do {
		op =Vista::menuGeneral();
		control21(op);
		system("pause");
		system("cls");
	} while (op != 7);
	return op;
}

void Controladora::control0() {
	bool finalizado = false;
	int op = 0;
	controlBienvenida();
	while (!finalizado) {
		op = control23();
		finalizado = control22(op);
	}
	system("pause");
}