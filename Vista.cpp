#include"Vista.h"

Gimnasio* Vista::G1 = new Gimnasio();


void Vista::recuperarTodoVista() {
	G1->recuperarTodoGym();
}
void Vista::guardarTodoVista() {
	G1->guardarTodoGym();
}

void Vista::bienvenida() {
	cout << endl << endl;
	cout << "\tBIENVENIDO AL GIMNASIO" << endl;
	cout << "\tDigite la fecha actual a continuacion..." << endl << endl;
	bool finaliza = false;
	while (!finaliza) {
		
		try {
			system("pause");
			system("cls");
			cin.clear();
			cin.ignore(255, '\n');
			G1->setFecha(Interfaz::leerFecha());
			G1->setMensualidad(Interfaz::leerMensualidad());
			finaliza = true;
		}
		catch (ExcepcionPrograma* e) {
			cout << e->toString();
		}
	}
	cout << endl;
	system("pause");
	system("cls");
}

int Vista::menuGeneral() {
	try {
		cin.clear();
		cin.ignore(255, '\n');
		int op;
		cout << endl << endl;
		cout << "------------ SISTEMA DE CONTROL DEL GIMNASIO --------------" << endl << endl;
		cout << "--------------------------- MENU --------------------------" << endl;
		cout << " 1 - Administracion general.                               " << endl;
		cout << " 2 - Control de deportistas.                               " << endl;
		cout << " 3 - Control de cursos.                                    " << endl;
		cout << " 4 - Control de grupos.                                    " << endl;
		cout << " 5 - Control de instructores.                              " << endl;
		cout << " 6 - Control de pagos.                                     " << endl;
		cout << " 7 - Guardar en archivos y salir.                          " << endl;
		cout << "-----------------------------------------------------------" << endl;
		cout << "Ingrese su opcion: ";
		if (cin >> op)
			op = Rango::obtenerRango(op, 1, 7);
		else
			throw new ExcepcionValor();
		system("cls");
		cout << endl << endl;
		return op;
	}
	catch (ExcepcionPrograma* e) {
		cout << e->toString();
	}
}

int Vista::menuAdministracionGeneral() {
	try {
	cin.clear();
	cin.ignore(255, '\n');
	int op;
	cout << "-------- DATOS DEL GIMNASIO --------" << endl;
	cout << " 1 - Nombre del gimnasio" << endl;
	cout << " 2 - Monto de mensualidad" << endl;
	cout << " 3 - Salir" << endl;
	cout << "------------------------------------" << endl;
	cout << "Ingrese su opcion: ";
	if (cin >> op)
		op = Rango::obtenerRango(op, 1, 3);
	else
		throw new ExcepcionValor();
	cout << endl << endl;
	system("cls");
	return op;
	}
	catch (ExcepcionPrograma* e) {
		cout << e->toString();
	}
}

int Vista::menuControlDeportistas() {
	try {
	cin.clear();
	cin.ignore(255, '\n');
	int op;
	cout << "-------- CONTROL DEPORTISTAS --------" << endl;
	cout << " 1 - Ingresa nuevo deportista." << endl;
	cout << " 2 - Modifica deportista." << endl;
	cout << " 3 - Listado de deportistas." << endl;
	cout << " 4 - Detalle de deportista especifico." << endl;
	cout << " 5 - Salir." << endl;
	cout << "------------------------------------" << endl;
	cout << "Ingrese su opcion: ";
	if (cin >> op)
		op = Rango::obtenerRango(op, 1, 5);
	else
		throw new ExcepcionValor();
	cout << endl << endl;
	system("cls");
	return op;
	}
	catch (ExcepcionPrograma* e) {
		cout << e->toString();
	}
}

int Vista::menuControlCursos() {
	try {
		cin.clear();
		cin.ignore(255, '\n');
	int op;
	cout << "---------- CONTROL CURSOS ----------" << endl;
	cout << " 1 - Ingresa nuevo curso." << endl;
	cout << " 2 - Modifica curso." << endl;
	cout << " 3 - Reporte curso especifico." << endl;
	cout << " 4 - Salir." << endl;
	cout << "-----------------------------------" << endl;
	cout << "Ingrese su opcion: ";
	if (cin >> op)
		op = Rango::obtenerRango(op, 1, 4);
	else
		throw new ExcepcionValor();
	cout << endl << endl;
	system("cls");
	return op;
	}
	catch (ExcepcionPrograma* e) {
		cout << e->toString();
	}
}

int Vista::menuControlGrupos() {
	try {
		cin.clear();
		cin.ignore(255, '\n');
	int op;
	cout << "-------------- CONTROL GRUPOS --------------" << endl;
	cout << " 1 - Ingresa nuevo grupo." << endl;
	cout << " 2 - Modifica grupo." << endl;
	cout << " 3 - Matricula en grupo especifico." << endl;
	cout << " 4 - Reporte grupo especifico." << endl;
	cout << " 5 - Reporte deportistas matriculados en grupo." << endl;
	cout << " 6 - Cancelacion de matricula en grupo." << endl;
	cout << " 7 - Salir." << endl;
	cout << "--------------------------------------------" << endl;
	cout << "Ingrese su opcion: ";
	if (cin >> op)
		op = Rango::obtenerRango(op, 1, 7);
	else
		throw new ExcepcionValor();
	cout << endl << endl;
	system("cls");
	return op;
    }
    catch (ExcepcionPrograma* e) {
	    cout << e->toString();
    }
}

int Vista::menuControlInstructores() {
    try {
	cin.clear();
	cin.ignore(255, '\n');
	int op;
	cout << "-------- CONTROL INSTRUCTORES -------" << endl;
	cout << " 1 - Ingresar instructor." << endl;
	cout << " 2 - Salir" << endl;
	cout << "------------------------------------" << endl;
	cout << "Ingrese su opcion: ";
	if (cin >> op)
		op = Rango::obtenerRango(op, 1, 2);
	else
		throw new ExcepcionValor();
	cout << endl << endl;
	system("cls");
	return op;
    }
    catch (ExcepcionPrograma* e) {
	cout << e->toString();
    }
}

int Vista::menuControPagos() {
	try {
		cin.clear();
		cin.ignore(255, '\n');
	int op;
	cout << "--------- CONTROL DE PAGOS ---------" << endl;
	cout << " 1 - Registro de nuevo pago" << endl;
	cout << " 2 - Reporte de pagos por deportista" << endl;
	cout << " 3 - Salir" << endl;
	cout << "------------------------------------" << endl;
	cout << "Ingrese su opcion: ";
	if (cin >> op)
		op = Rango::obtenerRango(op, 1, 3);
	else
		throw new ExcepcionValor();
	cout << endl << endl;
	system("cls");
	return op;
	}
	catch (ExcepcionPrograma* e) {
		cout << e->toString();
	}
}


void Vista::funcionesAdministracionGeneral(int op) {
	try {
		switch (op) {
		case 1: { //Nombre del gimnasio
			G1->setNombreGym(Interfaz::leerNombre());
			system("pause");
			system("cls");
			break;
		}
		case 2: { //Mensualidad
			G1->setMensualidad(Interfaz::leerMensualidad());
			system("pause");
			system("cls");
			break;
		}
		case 3: break;
		}
	}
	catch (ExcepcionPrograma* e) {
		cout << e->toString() << endl;
	}
}

void Vista::listadoDeDeportistas() {
	int op;
	do {
		cout << "-------- LISTADO DE DEPORTISTAS --------" << endl;
		cout << " 1 - Listado general." << endl;
		cout << " 2 - Listado de deportistas activos." << endl;
		cout << " 3 - Listado de deportistas inactivos." << endl;
		cout << " 4 - Listado de deportistas en morosidad." << endl;
		cout << " 5 - Salir." << endl;
		cout << "----------------------------------------" << endl;
		cout << "Ingrese su opcion: ";
		if (cin >> op)
			op = Rango::obtenerRango(op, 1, 5);
		else
			throw new ExcepcionValor();
		system("cls");
		G1->setEstadoClientes();

		switch (op) {
		case 1: { // 1 - Listado general

			G1->mostrarSoloDeportistas();
			system("pause");
			system("cls");
			break;
		}
		case 2: { // 2 - Listado de deportistas activos
			G1->mostrarClientesActivos();
			system("pause");
			system("cls");
			break;
		}
		case 3: { // 3 - Listado de deportistas inactivos
			G1->mostrarClientesInactivos();
			system("pause");
			system("cls");
			break;
		}
		case 4: { // 4 - Listado de deportistas en morosidad
			G1->mostrarClientesMorosos();
			system("pause");
			system("cls");
			break;
		}
		case 5:	break;
		}
	} while (op != 5);
}

void Vista::funcionesControlDeportistas(int op) {
	try {
		switch (op) {
		case 1: { // 1 - Ingresa nuevo deportista. 
			if (G1->ingresaCliente())
				cout << "Cliente ingresado exitosamente..." << endl << endl;
			else
				throw new string("No es posible ingresar al cliente...");

			system("pause");
			system("cls");
			break;
		}
		case 2: { // 2 - Modifica deportista.
			if (G1->editaCliente())
				cout << "Cliente editado exitosamente..." << endl << endl;
			else
				throw new ExcepcionContVacio();
			system("pause");
			system("cls");
			break;
		}
		case 3: { // 3 - Listado de deportistas.

			Vista::listadoDeDeportistas();
			break;
		}
		case 4: { // 4 - Detalle de deportista especifico.
			G1->mostrarClienteEspecifico();
			system("pause");
			system("cls");
			break;
		}
		case 5:	break;
		}
	}
	catch (ExcepcionPrograma* e) {
		cout << e->toString() << endl;
	}
	catch(string* e){
		cout << *e << endl;
	}
}

void Vista::funcionesControlCursos(int op) {
	try {
		switch (op) {
		case 1: { // 1 - Ingresa nuevo curso
			if (G1->ingresaCurso())
				cout << "Curso ingresado exitosamente..." << endl << endl;
			else
				throw new ExcepcionInstructor();;
			system("pause");
			system("cls");
			break;
		}
		case 2: { // 2 - Modifica curso.
			if (G1->editaCurso())
				cout << "Curso editado exitosamente..." << endl << endl;
			else
				throw new ExcepcionContVacio();
			system("pause");
			system("cls");
			break;
		}
		case 3: { // 3 - Reporte curso especifico
			G1->mostrarCurso();
			system("pause");
			system("cls");
			break;
		}
		case 4:break;
		}
	}
	catch (ExcepcionPrograma* e) {
		cout << e->toString() << endl;
	}
	catch (string* e) {
		cout << *e << endl;
	}
}

void Vista::funcionesControlGrupos(int op) {
	try {
		switch (op) {
		case 1: { // 1 - Ingresa nuevo grupo.
			if (G1->ingresaGrupo())
				cout << "Grupo ingresado exitosamente..." << endl << endl;
			else
				throw new ExcepcionGrupo(1);
			system("pause");
			system("cls");
			break;
		}
		case 2: { // 2 - Modifica grupo.
			if (G1->editaGrupo())
				cout << "Grupo editado exitosamente..." << endl << endl;
			else
				throw new ExcepcionContVacio();
			system("pause");
			system("cls");
			break;
		}
		case 3: { // 3 - Matricula en grupo especifico
			if (G1->ingresaMatriculaCurso())
				cout << "Matricula realizada exitosamente..." << endl << endl;
			else
				throw new ExcepcionValor();
			system("pause");
			system("cls");
			break;
		}
		case 4: { // 4 - Reporte grupo especifico.
			G1->mostrarGrupo();
			break;
		}
		case 5: { // 5 - Reporte deportistas matriculados en grupo.
			G1->mostrarDeportistasMatriculadosEnCurso();
			system("pause");
			system("cls");
			break;
		}
		case 6: { // 6 - Cancela matricula en grupo.
			if (G1->cancelaMatricula())
				cout << "Matricula cancelada exitosamente..." << endl << endl;
			else
				cout << "No es posible cancelar la matricula..." << endl << endl;
			system("pause");
			system("cls");
			break;
		}
		case 7:break;
		}
	}
	catch (ExcepcionPrograma* e) {
		cout << e->toString() << endl;
	}
	catch (string* e) {
		cout << *e << endl;
	}
}

void Vista::funcionesControlInstructor(int op) {
	try {
		switch (op) {
		case 1: { // 1 - Ingresar instructor
			if (G1->ingresaInstructor())
				cout << "Instructor ingresado exitosamente..." << endl << endl;
			else
				cout << "No es posible ingresar el instructor..." << endl << endl;
			system("pause");
			system("cls");
			break;
		}
		case 2: break;
		}
	}
	catch (string* e) {
		cout << *e << endl;
	}
}

void Vista::funcionesControlPagos(int op) {
	try {
		switch (op) {
		case 1: { // 1 - Registro de nuevo pago
			if (G1->ingresaPago())
				cout << "Pago realizado exitosamente..." << endl << endl;
			else
				cout << "No es posible realizar el pago..." << endl << endl;
			system("pause");
			system("cls");
			break;
		}
		case 2: { // 2 - Reporte de pagos por deportista
			G1->mostrarExpediente();
			system("pause");
			system("cls");
			break;
		}
		case 3: break;
		}
	}
	catch (ExcepcionPrograma* e) {
		cout << e->toString() << endl;
	}
	catch (string* e) {
		cout << *e << endl;
	}
}




































