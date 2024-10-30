#include "Interfaz.h"

Deportista* Interfaz::clonarDeportista(Deportista* ptr)
{
    Deportista* ptr1 = new Triatlonista(ptr->getCedula(), ptr->getNombre(), ptr->getTelefono(), new Fecha(ptr->getFechaNacimiento()->getDia(), ptr->getFechaNacimiento()->getMes(), ptr->getFechaNacimiento()->getAnio()), ptr->getSexo(), ptr->getEstatura(), ptr->getHorasEntrenamiento(), ptr->getTemPromedio(), ptr->getMasaMuscular(), ptr->getPeso(), ptr->getPorcGrasaCorporal(), ptr->getCantParticIronMan(), ptr->getCantTriatGanados(), new Fecha(ptr->getFechaRegistro()->getDia(), ptr->getFechaRegistro()->getMes(), ptr->getFechaRegistro()->getAnio()));
    ptr1->setEstado(ptr->getEstado());
    return ptr1;
}
string Interfaz::leerCedula()
{
    string dato;
    cout << "Ingrese la cedula: ";
    cin >> dato;
    return dato;
}

string Interfaz::leerNombre()
{
    string dato;
    cout << "Ingrese el nombre: ";
    cin >> dato;
    return dato;
}

string Interfaz::leerTelefono()
{
    string dato;
    cout << "Ingrese el telefono: ";
    cin >> dato;
    return dato;
}

int Interfaz::leerHorasEntre()
{
    int dato;
    cout << "Ingrese las horas de entrenamiento: ";
    if (cin >> dato)
        return dato;
    else
        throw new ExcepcionValor();
}

double Interfaz::leerTemPromedio()
{
    double dato;
    cout << "Ingrese la temeperatura promedio: ";
    if (cin >> dato)
        return dato;
    else
        throw new ExcepcionValor();
}

char Interfaz::leerSexo()
{
    char dato;
    cout << "Ingrese el sexo (F/M): ";
    cin >> dato;
    dato = toupper(dato);
    if (dato == 'F' or dato == 'M')
        return dato;
    else
        throw new ExcepcionValor();
}

double Interfaz::leerEstatura()
{
    double dato;
    cout << "Ingrese la estatura: ";
    if (cin >> dato)
        return dato;
    else
        throw new ExcepcionValor();
}

double Interfaz::leerMasaMuscular()
{
    double dato;
    cout << "Ingrese el porcentaje de masa muscular: ";
    if (cin >> dato)
        return dato;
    else
        throw new ExcepcionValor();
}

double Interfaz::leerPeso()
{
    double dato;
    cout << "Ingrese el peso: ";
    if (cin >> dato)
        return dato;
    else
        throw new ExcepcionValor();
}

double Interfaz::leerGrasa()
{
    double dato;
    cout << "Ingrese el porcentaje de grasa corporal: ";
    if (cin >> dato)
        return dato;
    else
        throw new ExcepcionValor();
}

int Interfaz::leerCantIron()
{
    int dato;
    cout << "Ingrese la cantidad de participaciones en Iron Man: ";
    if (cin >> dato)
        return dato;
    else
        throw new ExcepcionValor();
}

int Interfaz::leerCantTriat()
{
    int dato;
    cout << "Ingrese la cantidad triatlones ganados: ";
    if (cin >> dato)
        return dato;
    else
        throw new ExcepcionValor();
}

string Interfaz::leerEstado()
{
    int dato = 0;
    cout << "Ingrese la el nuevo estado: ";
    cout << "1-Activo\n2-Inactivo\n";
    if (cin >> dato)
        dato = Rango::obtenerRango(dato, 1, 2);
    else
        throw new ExcepcionValor();
    switch (dato)
    {
     case 1: return "Activo"; break;
     case 2: return "Inactivo";
    }
}

int Interfaz::menuEditTriat()
{
    int opcion = 0;
    cout << "1-Cedula\n2-Nombre\n3-Fecha de nacimiento\n4-Telefono\n5-Horas de entrenamiento\n6-Temperatura promedio\n7-Sexo\n8-Estatura\n9-Masa Muscular\n10-peso\n11-Porcentaje de grasa corporal\n12-Participaciones en Iron Man\n13-Triatlones ganados\n14-Estado\n\n";
    cout << "Ingrese la opcion que desea editar: ";
    if (cin >> opcion)
        return opcion = Rango::obtenerRango(opcion, 1, 14);
    else
        throw new ExcepcionValor();
}

int Interfaz::menuEditIns()
{
    int opcion = 0;
    cout << "1-Cedula\n2-Nombre\n";
    cout << "Ingrese la opcion que desea editar: ";
    if (cin >> opcion)
        return opcion = Rango::obtenerRango(opcion, 1, 2);
    else
        throw new ExcepcionValor();
}

int Interfaz::menuEditCurso()
{
    int opcion = 0;
    cout << "1-Cogido del curso\n2-Nombre del curso\n3-Nivel\n4-Descripcion\n5-Cantidad de grupos\n";
    cout << "\nIngrese la opcion que desea editar: ";
    if (cin >> opcion)
        return opcion = Rango::obtenerRango(opcion, 1, 5);
    else
        throw new ExcepcionValor();
}

int Interfaz::menuEditGrupo()
{
    int opcion = 0;
    cout << "1-Instructor\n2-Cupo Maximo\n3-Fecha de inicio\n4-Semanas de duracion\n5-dia de la semana\n6-Hora de inicio\n7-Hora de finalizacion\n";
    cout << "\nIngrese la opcion que desea editar: ";
    if (cin >> opcion)
        return opcion = Rango::obtenerRango(opcion, 1, 7);
    else
        throw new ExcepcionValor();
}

Fecha* Interfaz::leerFecha()
{
    int dia = 0, mes = 0, anio = 0;
    cout << "Ingrese el dia: ";
    if (cin >> dia) {
        Rango::obtenerRango(dia, 1, 31);
        cout << "Ingrese el mes: ";
        if (cin >> mes) {
            Rango::obtenerRango(mes, 1, 12);
            cout << "Ingrese el anio: ";
            if (cin >> anio) {
                return new Fecha(dia, mes, anio);
            }
            else
                throw new ExcepcionValor();
        }
        else
            throw new ExcepcionValor();
    }
    else
        throw new ExcepcionValor();
}

string Interfaz::leerCodCurso()
{
    string dato;
    cout << "Ingrese el codigo del curso: ";
    cin >> dato;
    return dato;
}

string Interfaz::leerNombreCurso()
{
    string dato;
    cout << "Ingrese el nombre del curso: ";
    cin >> dato;
    return dato;
}

string Interfaz::leerDescricionCurso()
{
    string dato;
    cout << "Ingrese la descripcion del curso: ";
    getline(cin, dato, '\n');
    getline(cin, dato, '\n');
    return dato;
}

int Interfaz::leerCupoMaximo()
{
    int dato;
    cout << "Ingrese el cupo maximo del grupo: ";
    if (cin >> dato)
        return dato;
    else
        throw new ExcepcionValor();
}

int Interfaz::leerSemanasDuracion()
{
    int dato;
    cout << "Ingrese las semanas de duracion: ";
    if (cin >> dato)
        return dato;
    else
        throw new ExcepcionValor();
}

string Interfaz::leerDia()
{
    string dato;
    cout << "Ingrese el dia de la semana: ";
    cin >> dato;
    return dato;
}

Hora* Interfaz::leerHora()
{
    int horas = 0;
    int mins = 0;
    cout << "Ingrese los minutos: ";
    if (cin >> mins) {
        cout << "Ingrese las horas (hora militar): ";
        if(cin >> horas)
            return new Hora(horas, mins);
        else
            throw new ExcepcionValor();
    }
    else
        throw new ExcepcionValor();
}

int Interfaz::leerNivelCurso()
{
    int dato = 0;
    cout << "1-Principiante\n2-Intermedio\n3-Avanzado\n";
    cout << "Ingrese el nivel del curso: ";
    if (cin >> dato)
        return dato = Rango::obtenerRango(dato, 1, 3);
    else
        throw new ExcepcionValor();
}

int Interfaz::leerNumeroGrupos()
{
    int dato;
    cout << "Ingrese la cantidad de grupos del curso: ";
    if (cin >> dato)
        return dato;
    else
        throw new ExcepcionValor();
}

string Interfaz::leerCodigoReservacion()
{
    string dato;
    cout << "Ingrese el codigo de la reservacion: ";
    cin >> dato;
    return dato;
}

double Interfaz::leerMensualidad()
{
    double dato;
    cout << "Ingrese la mesualidad: ";
    if (cin >> dato)
        return dato;
    else
        throw new ExcepcionValor();
}

bool Interfaz::agregaTriatlonista(ContenedorTemplate<Deportista>* co, ContenedorTemplate<Instructor>* coI, ContenedorTemplate<Curso>* coC, ContenedorTemplate<Reserva>* coR, Fecha* actual, ContenedorTemplate<Expediente>* coE, double monto)
{
    try {
        int curso = 0;
        int cont = 0;
        int grupo = 0;
        Interfaz::muestraSoloCursos(coC);
        //cout << coC->toString();
        cout << "Seleccione el numero(#) de curso en el que desea matricular al nuevo cliente: ";
        if (cin >> curso) {

            if (coC->retornaObjeto(curso)) {
                if (!(coC->retornaObjeto(curso)->getGrupos()->vacia())) {
                    string ced = Interfaz::leerCedula();
                    Iterador<Deportista>* iter = new Iterador<Deportista>(co->getPpio());
                    while (iter->getPNodo() != NULL) {
                        if (iter->actual()->getCedula() == ced) {
                            throw new string("Error...cedula ya existe");
                        }
                        else {
                            iter->siguiente();
                        }
                    }
                    delete iter;
                    Iterador<Instructor>* iter1 = new Iterador<Instructor>(coI->getPpio());
                    while (iter1->getPNodo() != NULL) {
                        if (iter1->actual()->getIdInstructor() == ced) {
                            throw new string("Error...cedula ya existe");
                        }
                        else {
                            iter1->siguiente();
                        }
                    }
                    delete iter1;
                    if (!(coC->retornaObjeto(curso)->existeMatricula(ced))) {
                        //cout << (coC->retornaObjeto(curso)->getGrupos()->toString());
                        system("pause");
                        system("cls");
                        Interfaz::muestraSoloGrupos(coC, curso);
                        cout << "Seleccione el el numero(#) de grupo: ";
                        if (cin >> grupo) {
                            if (coC->retornaObjeto(curso)->getGrupos()->retornaObjeto(grupo)) {
                                if (coC->retornaObjeto(curso)->getGrupos()->retornaObjeto(grupo)->hayEspacio()) {
                                    string nombre = Interfaz::leerNombre();
                                    string telefono = Interfaz::leerTelefono();
                                    Fecha* fecha = Interfaz::leerFecha();
                                    char sexo = Interfaz::leerSexo();
                                    double estatura = Interfaz::leerEstatura();
                                    int horas = Interfaz::leerHorasEntre();
                                    double temperatura = Interfaz::leerTemPromedio();
                                    double masaM = Interfaz::leerMasaMuscular();
                                    double peso = Interfaz::leerPeso();
                                    double grasa = Interfaz::leerGrasa();
                                    int iron = Interfaz::leerCantIron();
                                    int triat = Interfaz::leerCantTriat();
                                    Deportista* ptrT = new Triatlonista(ced, nombre, telefono, fecha, sexo, estatura, horas, temperatura, masaM, peso, grasa, iron, triat, actual);
                                    Expediente* ptrE = new Expediente(ptrT);
                                    Interfaz::agregaPagos(ptrE, monto, actual, ced, nombre);//arreglar la fecha
                                    coE->agregarElemento(ptrE);
                                    co->agregarElemento(ptrT);
                                    coC->retornaObjeto(curso)->getGrupos()->retornaObjeto(grupo)->ingresarIntegrante(Interfaz::clonarDeportista(ptrT));
                                    coR->agregarElemento(new Reserva(coC->retornaObjeto(curso)->getCodigoCurso(), actual, coC->retornaObjeto(curso), Interfaz::clonarDeportista(ptrT)));
                                    return true;
                                }
                                else {
                                    throw new string("Error...no quedan cupos libres en el grupo seleccionado");
                                }
                            }
                            throw new string("Error...grupo no existe");
                        }
                        else
                            throw new ExcepcionValor();
                    }
                    else {
                        throw new string("Error...cliente ya esta matriculado en este curso");
                    }

                }
                else {
                    throw new string("Error...no hay grupos asociados al curso");
                }
            }
            else
                throw new string("Error...curso no existe");
        }
        else
            throw new ExcepcionValor();
    }
    catch (ExcepcionPrograma* e) {
        cout << e->toString() << endl;
    }

}

bool Interfaz::editaTriatlonista(ContenedorTemplate<Deportista>* co)
{
    int cliente;
    int opcion = 0;
    Interfaz::muestraSoloDeportistas(co);
    cout << "Ingrese el cliente que desea editar: ";
    if (!(cin >> cliente))
        throw new ExcepcionValor();
    cout << endl;
    system("pause");
    system("cls");
    Deportista* ptr = NULL;
    if (ptr=co->retornaObjeto(cliente)) {
        opcion = Interfaz::menuEditTriat();
        switch (opcion)
        {
        case 1: ptr->setCedula(Interfaz::leerCedula()) ; break;
        case 2: ptr->setNombre(Interfaz::leerNombre()); break;
        case 3: ptr->setFechaNacimiento(Interfaz::leerFecha()); break;
        case 4: ptr->setTelefono(Interfaz::leerTelefono()); break;
        case 5: ptr ->setHorasEntrenamiento(Interfaz::leerHorasEntre()); break;
        case 6: ptr->setTemPromedio(Interfaz::leerTemPromedio()); break;
        case 7: ptr->setSexo(Interfaz::leerSexo()); break;
        case 8: ptr->setEstatura(Interfaz::leerEstatura()); break;
        case 9: ptr->setMasaMuscular(Interfaz::leerMasaMuscular()); break;
        case 10: ptr->setPeso(Interfaz::leerPeso()); break;
        case 11: ptr->setPorcGrasa(Interfaz::leerGrasa()); break;
        case 12: ptr->setCantIronMan(Interfaz::leerCantIron()); break;
        case 13: ptr->setCantTriat(Interfaz::leerCantTriat()); break;
        case 14: ptr->setEstado(Interfaz::leerEstado()); break;
        }
    }
    else {
        throw new string("Error...deportista no existe");
    }
}

bool Interfaz::agregaCurso(ContenedorTemplate<Curso>* co)
{
    int i = 1;
    string cod = Interfaz::leerCodCurso();
    Iterador<Curso>* iter = new Iterador<Curso>(co->getPpio());
    while (iter->getPNodo() != NULL) {
        if (iter->actual()->getCodigoCurso() == cod) {
            throw new string("Error...codigo de curso ya existe");
        }
        else {
            iter->siguiente();
        }
    }
    delete iter;
    string nom = Interfaz::leerNombreCurso();
    string  desc = Interfaz::leerDescricionCurso();
    int niv = Interfaz::leerNivelCurso();
    int grup = Interfaz::leerNumeroGrupos();
    co->agregarElemento(new Curso(cod, nom, niv, desc, grup));
    return true;
}

bool Interfaz::agregaGrupo(ContenedorTemplate<Curso>* coC, ContenedorTemplate<Instructor>* coI)
{
    int curso = 0;
    int num = 0;
    int opcion = 0;
    Interfaz::muestraSoloCursos(coC);
    cout << "Seleccione el curso: ";
    if (cin >> curso) {
        if (coC->retornaObjeto(curso) != NULL) {
            system("pause");
            system("cls");
            if (coC->retornaObjeto(curso)->getGrupos()->cantidadElementos() <= coC->retornaObjeto(curso)->getNumGrupo()) {
                if (coC->retornaObjeto(curso)->getGrupos()->vacia()) {
                    num = 1;
                }
                else {
                    num = coC->retornaObjeto(curso)->getGrupos()->getPpio()->getPuntero()->getNumGrupo() + 1;
                }
                cout << coI->toString();
                cout << "Seleccione el instructor: ";
                if (cin >> opcion) {
                    if (coI->retornaObjeto(opcion) != NULL){
                        if (coC->retornaObjeto(curso)->getGrupos()->cantidadElementos() < coC->retornaObjeto(curso)->getNumGrupo()) {
                            int cupoMax = Interfaz::leerCupoMaximo();
                            cout << "---Fecha de inicio---" << endl;
                            Fecha* fechaInicio = Interfaz::leerFecha();
                            int semanas = Interfaz::leerSemanasDuracion();
                            string dia = Interfaz::leerDia();
                            cout << "---Hora de inicio---" << endl;
                            Hora* horaInicio = Interfaz::leerHora();
                            cout << "---Hora de finalizacion---" << endl;
                            Hora* horaFinal = Interfaz::leerHora();
                            coC->retornaObjeto(curso)->getGrupos()->agregarElemento(new Grupo(num, coI->retornaObjeto(opcion), cupoMax, fechaInicio, semanas, dia, horaInicio, horaFinal));
                            return true;
                        }
                        else {
                   
                        throw new string("Error...ya no se pueden aniadir mas grupos a este curso.");
                        }
                    }
                    else
                        throw new string("Error...instructor seleccionado no existe.");
                }
                else
                    throw new ExcepcionValor();
            }
            else 
                throw new string("Error...ya no se pueden aniadir mas grupos a este curso.");
        }
        else 
            throw new string("Error...curso no existe.");
    }
    else
        throw new ExcepcionValor();

}

void Interfaz::agregaPagos(Expediente* coE, double monto, Fecha* fechaActual,string ced, string nom)
{
    coE->setCedula(ced);
    coE->setNombre(nom);
    int cant;
    cout << "Ingrese la cantidad de meses que desea pagar: ";
    if (cin >> cant) {
        Fecha* aux = new Fecha(*fechaActual);
        coE->getPagos()->agregarElementoFinal(new Pago(fechaActual, monto, aux->getMes()));
        for (int i = 1; i <= cant - 1; i++) {
            coE->getPagos()->agregarElementoFinal(new Pago(fechaActual, monto, ManejoFecha::incrementaFecha(aux)));
            aux->setMes(ManejoFecha::incrementaFecha(aux));
        }
        delete aux;
    }
    else
        throw new ExcepcionValor();
}

bool Interfaz::actualizaExpediente(ContenedorTemplate<Expediente>* coE, double monto, Fecha* fechaActual)
{
    int opcion = 0;
    Iterador<Expediente>* iter = new Iterador<Expediente>(coE->getPpio());
    int contador = 1;
    while (iter->getPNodo() != NULL) {
        cout << "--------------- EXPEDIENTE #" << contador << " ---------------" << endl;
        cout << "Cedula: " << iter->actual()->getCedula() << endl <<
                "Nombre: " << iter->actual()->getNombre() << endl;
        cout << "----------------------------------------" << endl << endl;
        iter->siguiente();
        contador++;
    }
    cout << "Seleccione el numero(#) de expediente a actualizar: ";
    if (cin >> opcion) {
        if (coE->retornaObjeto(opcion) != NULL)
        {
            Interfaz::agregaPagos(coE->retornaObjeto(opcion), monto, fechaActual, coE->retornaObjeto(opcion)->getCedula(), coE->retornaObjeto(opcion)->getNombre());
            return true;
        }
        else {
            throw new string("Error...expediente no existe");

        }
    }
    else
        throw new ExcepcionValor();
}

bool Interfaz::agregaMatriculaEnCurso(ContenedorTemplate<Deportista>* coT, ContenedorTemplate<Curso>* coC, ContenedorTemplate<Reserva>* coR, Fecha* actual) {

    int opcion = 0;
    int triat = 0;
    int grupo = 0;
    int contador = 0;
    Interfaz::muestraSoloDeportistas(coT);
    cout << "Seleccione al cliente: ";
    if (cin >> triat) {
        system("pause");
        system("cls");
        if (coT->retornaObjeto(triat) != NULL) {

            if (coT->retornaObjeto(triat)->getEstado() == "Activo") {
                Iterador<Curso>* iter = new Iterador<Curso>(coC->getPpio());
                while (iter->getPNodo() != NULL) {
                    if (iter->actual()->existeMatricula(coT->retornaObjeto(triat)->getCedula())) {
                        contador++;
                    }
                    iter->siguiente();
                }
                delete iter;
                if (contador < 4) {
                    Interfaz::muestraSoloCursos(coC);
                    cout << "Seleccione el curso: ";
                    if (cin >> opcion) {
                        system("pause");
                        system("cls");
                        if (coC->retornaObjeto(opcion) != NULL) {
                            Interfaz::muestraSoloGrupos(coC, opcion);
                            cout << "Seleccione el grupo: ";
                            if (cin >> grupo) {
                                if (coC->retornaObjeto(opcion)->getGrupos()->retornaObjeto(grupo) != NULL) {
                                    if (!(coC->retornaObjeto(opcion)->getGrupos()->retornaObjeto(grupo)->existeMatricula(coT->retornaObjeto(triat)->getCedula()))) {
                                        coC->retornaObjeto(opcion)->getGrupos()->retornaObjeto(grupo)->ingresarIntegrante(Interfaz::clonarDeportista(coT->retornaObjeto(triat)));

                                        coR->agregarElemento(new Reserva(coC->retornaObjeto(opcion)->getCodigoCurso(), actual, coC->retornaObjeto(opcion), Interfaz::clonarDeportista(coT->retornaObjeto(triat))));
                                        return true;
                                    }
                                    else
                                        return false;
                                }
                                else
                                    throw new string("Error...grupo digitado no existe.");
                            }
                            else
                                throw new ExcepcionValor();
                        }
                        else
                            throw new string("Error...curso digitado no existe.");
                    }
                    else
                        throw new ExcepcionValor();
                }
                else
                    throw new string("Error...cliente no puede matricular mas de 4 cursos.");
            }
            else
                throw new string("Error...cliente digitado no se encuentra activo.");

        }
        else
            throw new string("Error...cliente digitado no existe.");
    }
    else
        throw new ExcepcionValor();
}

void Interfaz::muestraSoloCursos(ContenedorTemplate<Curso>* coC)
{
    Iterador<Curso>* iter = new Iterador<Curso>(coC->getPpio());
    int contador=1;
    while (iter->getPNodo() != NULL) {
        cout << "--------------- CURSO #" << contador << " ---------------" << endl;
        cout << "Codigo: " << iter->actual()->getCodigoCurso() << endl;
        cout << "Nombre: " << iter->actual()->getNombreCurso() << endl;
        cout << "Descripcion: " << iter->actual()->getDescripcion() << endl;
        cout << "Nivel: " << iter->actual()->getNivel() << endl;
        cout << "Numero de grupos: " << iter->actual()->getNumGrupo() << endl ;
        cout << "----------------------------------------" << endl << endl;
        iter->siguiente();
        contador++;
    }

}
void Interfaz::muestraSoloGrupos(ContenedorTemplate<Curso>* coC, int curso)
{
  
    Iterador<Grupo>* iter = new Iterador<Grupo>(coC->retornaObjeto(curso)->getGrupos()->getPpio());
    int contador = 1;
    while (iter->getPNodo() != NULL) {
        cout << "--------------- GRUPO #" << contador << " ---------------" << endl;
        cout << "Numero de grupo: " << iter->actual()->getNumGrupo() << endl <<
            "ID Instructor: " << iter->actual()->getInstructor()->getIdInstructor() << endl <<
            "Nombre Instructor: " << iter->actual()->getInstructor()->getNombreInstructor() << endl <<
            "Cupo Maximo: " << iter->actual()->getCupoMaximo() << endl <<
            "Cupu actual: " << iter->actual()->getCupoActual() << endl <<
            "Fecha de INICIO: " << iter->actual()->getFechaIncio()->toString() << endl <<
            "Duracion: " << iter->actual()->getSemanasDuracion() << " semanas" << endl <<
            "Horario: " << endl <<
            "	Dia de la semana: " << iter->actual()->getDia() << endl <<
            "	Hora de INICIO: " << *(iter->actual()->getHoraInicio()) << endl <<
            "	Hora de FINALIZACION: " << *(iter->actual()->getHoraFinal()) << endl;
        cout << "----------------------------------------" << endl << endl;
        iter->siguiente();
        contador++;
    }

}
void Interfaz::muestraSoloDeportistas(ContenedorTemplate<Deportista>* coD) {

    Iterador<Deportista>* iter = new Iterador<Deportista>(coD->getPpio());
    int contador = 1;
    while (iter->getPNodo() != NULL) {
        cout << "--------------- CLIENTE #" << contador << " ---------------" << endl;
        cout << "Nombre: " << iter->actual()->getNombre() << endl <<
                "ID: " << iter->actual()->getCedula() << endl <<
                "Estado: " << iter->actual()->getEstado() << endl <<
                "----------------------------------------" << endl << endl;
        iter->siguiente();
        contador++;
    }

}

bool Interfaz::editaCurso(ContenedorTemplate<Curso>* coC)
{
    int curso = 0;
    int opcion = 0;
    int cant = 0;
    Interfaz::muestraSoloCursos(coC);
    cout << "Seleccione el numero(#) de curso que desea editar: ";
    if (cin >> curso) {
        if (coC->retornaObjeto(curso) != NULL) {
            system("pause");
            system("cls");
            opcion = Interfaz::menuEditCurso();
            switch (opcion)
            {
            case 1: coC->retornaObjeto(curso)->setCodigoCurso(Interfaz::leerCodCurso()); break;
            case 2: coC->retornaObjeto(curso)->setNombreCurso(Interfaz::leerNombreCurso()); break;
            case 3: coC->retornaObjeto(curso)->setNivel(Interfaz::leerNivelCurso()); break;
            case 4: coC->retornaObjeto(curso)->setDescripcion(Interfaz::leerDescricionCurso()); break;
            case 5: {
                if ((cant = Interfaz::leerNumeroGrupos()) > coC->retornaObjeto(curso)->getNumGrupo()) {
                    coC->retornaObjeto(curso)->setNumGrupo(cant);
                }
                else {
                    throw new ExcepcionGrupo(2);
                }
            };
            }
        }
        else throw new string("Error...curso no existe.");
    }
    else
        throw new ExcepcionValor();
    
}

bool Interfaz::editaGrupo(ContenedorTemplate<Curso>* coC, ContenedorTemplate<Instructor>* coI)
{
    int curso = 0;
    int grupo = 0;
    int inst = 0;
    int opcion = 0;
    Interfaz::muestraSoloCursos(coC);
    cout << "Seleccione el curso al cual pertenece el grupo que desea editar: ";
    if (cin >> curso) {
        system("pause");
        system("cls");
        if (coC->retornaObjeto(curso) != NULL) {
            Interfaz::muestraSoloGrupos(coC, curso);
            cout << "Seleccione el grupo a editar: ";
            if (cin >> grupo) {
                if (coC->retornaObjeto(curso)->getGrupos()->retornaObjeto(grupo) != NULL) {
                    system("pause");
                    system("cls");
                    opcion = Interfaz::menuEditGrupo();
                    switch (opcion)
                    {
                    case 1: {
                        cout << coI->toString();
                        cout << "Seleccione el instructor con el que desea hacer el cambio: ";
                        if (cin >> inst) {
                            system("pause");
                            system("cls");
                            if (coI->retornaObjeto(inst) != NULL) {
                                coC->retornaObjeto(curso)->getGrupos()->retornaObjeto(grupo)->setInstructor(new Instructor(*coI->retornaObjeto(inst)));
                                return true;
                            }
                            else {
                                throw new string("Error...instructor digitado no existe.");
                            }
                        }
                        else
                            throw new ExcepcionValor();
                    }; break;
                    case 2: {
                        int aux = Interfaz::leerCupoMaximo();
                        if (aux > coC->retornaObjeto(curso)->getGrupos()->retornaObjeto(grupo)->getCupoMaximo()) {
                            coC->retornaObjeto(curso)->getGrupos()->retornaObjeto(grupo)->setCupoMaximo(aux);
                            return true;
                        }
                        else {
                            return false;
                        }
                    }break;
                    case 3: cout << "---Fecha de inicio---\n"; coC->retornaObjeto(curso)->getGrupos()->retornaObjeto(grupo)->setFechaIncio(Interfaz::leerFecha()); break;
                    case 4: coC->retornaObjeto(curso)->getGrupos()->retornaObjeto(grupo)->setSemanasDuracion(Interfaz::leerSemanasDuracion()); break;
                    case 5: coC->retornaObjeto(curso)->getGrupos()->retornaObjeto(grupo)->setDia(Interfaz::leerDia()); break;
                    case 6: cout << "---Hora de inicio---\n"; coC->retornaObjeto(curso)->getGrupos()->retornaObjeto(grupo)->setHoraInicio(Interfaz::leerHora()); break;
                    case 7: cout << "---Hora de finalizacion---\n"; coC->retornaObjeto(curso)->getGrupos()->retornaObjeto(grupo)->setHoraFinal(Interfaz::leerHora()); break;
                    }
                    return true;
                }
                else
                    throw new string("Error...grupo digitado no existe.");
            }
            else
                throw new ExcepcionValor();

        }
        else
            throw new string("Error...curso digitado no existe.");
    }
    else
        throw new ExcepcionValor();
}

bool Interfaz::cancelaMatricula(ContenedorTemplate<Curso>* coC, ContenedorTemplate<Reserva>* coR){
    int curso = 0;
    int grupo = 0;
    int triat = 0;
 
    Interfaz::muestraSoloCursos(coC);
    cout << "Seleccione el curso: ";
    if (cin >> curso) {
        system("pause");
        system("cls");
        if (coC->retornaObjeto(curso) != NULL) {

            Interfaz::muestraSoloGrupos(coC, curso);
            cout << "Seleccione el grupo: ";
            if (cin >> grupo) {
                system("pause");
                system("cls");
                if (coC->retornaObjeto(curso)->getGrupos()->retornaObjeto(grupo) != NULL) {
                 
                    Interfaz::muestraSoloDeportistas(coC->retornaObjeto(curso)->getGrupos()->retornaObjeto(grupo)->getIntegrantes());
                    cout << "Seleccione el cliente que desea desmatricular: ";
                    if (cin >> triat) {
                        if (coC->retornaObjeto(curso)->getGrupos()->retornaObjeto(grupo)->getIntegrantes()->retornaObjeto(triat) != NULL) {
                            coC->retornaObjeto(curso)->getGrupos()->retornaObjeto(grupo)->setCupoActual(coC->retornaObjeto(curso)->getGrupos()->retornaObjeto(grupo)->getCupoActual() - 1);
                            eliminaReservacion(coC->retornaObjeto(curso)->getCodigoCurso(), coC->retornaObjeto(curso)->getGrupos()->retornaObjeto(grupo)->getIntegrantes()->retornaObjeto(triat)->getCedula(), coR);
                            coC->retornaObjeto(curso)->getGrupos()->retornaObjeto(grupo)->getIntegrantes()->eliminarElemento(triat);
                            return true;
                        }
                        else
                            return false;
                    }
                    else
                        throw new ExcepcionValor();
                }
                else
                    throw new string("Error...grupo no existe.");
            }
            else
                throw new ExcepcionValor();
        }
        else
            throw new string("Error...curso no existe.");
    }
    else
        throw new ExcepcionValor();
}

bool Interfaz::eliminaReservacion(string cod, string ced, ContenedorTemplate<Reserva>* coR)
{
    Iterador<Reserva>* iter1 = new Iterador<Reserva>(coR->getPpio());
    Iterador<Reserva>* iter2 = new Iterador<Reserva>(coR->getPpio());
    if (iter1->actual()->getCodigo() == cod && iter1->actual()->getDeportista()->getCedula() == ced) {
        iter1->getPNodo()->setSig(iter1->getPNodo()->getSig());
        delete iter2->getPNodo();
        return true;
    }
    else {
        while (iter1->getPNodo() != NULL) {
            if (iter1->getPNodo()->getSig()->getPuntero()->getCodigo() == cod && iter1->getPNodo()->getSig()->getPuntero()->getDeportista()->getCedula() == ced) {
                iter2->setPNodo(iter1->getPNodo());
                iter2->siguiente();
                iter1->getPNodo()->setSig(iter2->getPNodo()->getSig());
                delete iter2->getPNodo();
                delete iter2;
                delete iter1;
                return true;
            }
            iter1->siguiente();
        }
    }
    return false;
}

bool Interfaz::agregaInstructor(ContenedorTemplate<Deportista>*co, ContenedorTemplate<Instructor>* coI)
{
    string ced = Interfaz::leerCedula();
    Iterador<Deportista>* iter = new Iterador<Deportista>(co->getPpio());
    while (iter->getPNodo() != NULL) {
        if (iter->actual()->getCedula() == ced) {
            throw new  string("Error...cedula ya existe.");
        }
        else {
            iter->siguiente();
        }
    }
    delete iter;
    Iterador<Instructor>* iter1 = new Iterador<Instructor>(coI->getPpio());
    while (iter1->getPNodo() != NULL) {
        if (iter1->actual()->getIdInstructor() == ced) {
            throw new  string("Error...cedula ya existe.");
        }
        else {
            iter1->siguiente();
        }
    }
    delete iter1;
    string nom = Interfaz::leerNombre();
    coI->agregarElemento(new Instructor(ced, nom));
    return true;
}


void Interfaz::mostrarCursoEspecif(ContenedorTemplate<Curso>* coC) {
    int cur = 1;
    int i = coC->cantidadElementos();
    int curso = 0;
    if (coC->cantidadElementos() != 0) {
        cout << "Codigos de Cursos: " << endl;
        do {
            cout << "#" << cur << " - " << coC->retornaObjeto(cur)->getCodigoCurso() << endl;
            cur++;
        } while (cur <= i);

        cout << "Seleccione el numero(#) de curso segun codigo: ";
        if (cin >> curso) {
            if (coC->retornaObjeto(curso) != NULL) {
                system("pause");
                system("cls");
                cout << coC->retornaObjeto(curso)->toString();
            }
            else
                throw new string("Error...curso digitado no existe.");
        }
        else
            throw new ExcepcionValor();
    }
    else
        throw new string("Error...no hay cursos registrados.");
}

void Interfaz::mostrarGrupoEspecif(ContenedorTemplate<Curso>* coC) {
    int cur = 1;
    int i = coC->cantidadElementos();
    int curso = 0;

    if (coC->cantidadElementos() != 0) {
    cout << "Codigos de Cursos: " << endl;
    do {
        cout << "#" << cur << " - " << coC->retornaObjeto(cur)->getCodigoCurso() << endl;
        cur++;
    } while (cur <= i);
    cout << "\nSeleccione el numero(#) de curso segun el codigo: ";
    if (cin >> curso) {
        if (coC->retornaObjeto(curso) != NULL) {
            system("pause");
            system("cls");
            ContenedorTemplate<Grupo>* coG = coC->retornaObjeto(curso)->getGrupos();
            if (coG->cantidadElementos() != 0) {
                int curG = 1;
                int iG = coG->cantidadElementos();
                cout << "Hay " << coG->cantidadElementos() << " elementos." << endl;
                int grupo;

                cout << "Numero de grupos: " << endl;
                do {
                    cout << "#" << curG << " - " << coG->retornaObjeto(curG)->getNumGrupo() << endl;
                    curG++;
                } while (curG <= iG);

                cout << "Seleccione el numero(#) del grupo: ";
                if (cin >> grupo) {

                    if (coG->retornaObjeto(grupo) != NULL) {
                        system("pause");
                        system("cls");
                        cout << coG->retornaObjeto(grupo)->toString();
                    }
                    else
                        throw new string("Error...grupo no existe.");
                }
                else
                    throw new ExcepcionValor();
            }
            else
                throw new string("Error...no hay grupos registrados.");
        }
        else
            throw new string("Error...curso no existe.");
    }
    else
        throw new ExcepcionValor();
    }
    else
        throw new string("Error...no hay elementos registrados.");
}

void Interfaz::mostrarClientes(ContenedorTemplate<Deportista>* coC) { 
    cout << (coC->toString());
}

void Interfaz::mostrarClientesEspecif(ContenedorTemplate<Deportista>* coC) { 
    int triA = 1;
    int ced = 0;
    int i = coC->cantidadElementos();

    if (coC->cantidadElementos() != 0) {
        do {
            cout << "#" << triA << " - " << coC->retornaObjeto(triA)->getCedula() << endl;
            triA++;
        } while (triA <= i);

        cout << "\nSeleccione el numero(#) segun la cedula del cliente: " << endl;
        if (cin >> ced) {
            if (coC->retornaObjeto(ced) != NULL) {
                cout << coC->retornaObjeto(ced)->toString();
            }
            else
                throw new string("Error...cliente no existe");
        }
        else throw new ExcepcionValor();
    }
    else
        throw new string("Error...no hay clientes registrados");
}

void  Interfaz::mostrarExpedienteEspecif(ContenedorTemplate<Expediente>* coC) { 
   
    int ced = 0;
    Iterador<Expediente>* iter = new Iterador<Expediente>(coC->getPpio());
    int contador = 1;
    while (iter->getPNodo() != NULL) {
        cout << "--------------- EXPEDIENTE #" << contador << " ---------------" << endl;
        cout << "Cedula: " << iter->actual()->getCedula() << endl <<
            "Nombre: " << iter->actual()->getNombre() << endl;
        cout << "----------------------------------------" << endl << endl;
        iter->siguiente();
        contador++;
    }

    cout << "Seleccione el numero(#) de expediente a consultar: " << endl;
    if (cin >> ced){
        system("pause");
        system("cls");
        if (coC->retornaObjeto(ced) != NULL) {
            cout << coC->retornaObjeto(ced)->toString();
        }
        else
            throw new string("Error...expediente digitado no existe.");
    }
    else
        throw new ExcepcionValor();
}

void Interfaz::mostrarClientesActivos(ContenedorTemplate<Deportista>* coC) { 
    int triA = 1;
    int i = coC->cantidadElementos();
    do {
        if (coC->retornaObjeto(triA) != NULL) {
            if (coC->retornaObjeto(triA)->getEstado() == "Activo") {
                cout << "----------------------------------------" << endl;
                cout << "Nombre: " << coC->retornaObjeto(triA)->getNombre() << endl <<
                    "ID: " << coC->retornaObjeto(triA)->getCedula() << endl <<
                    "Estado: " << coC->retornaObjeto(triA)->getEstado() << endl <<
                    "----------------------------------------" << endl << endl;
            }
        }
        triA++;
    } while (triA <= i); 
}

void Interfaz::mostrarClientesMorosos(ContenedorTemplate<Deportista>* coC) { 
    int triA = 1;
    int i = coC->cantidadElementos();
    do {
        if (coC->retornaObjeto(triA) != NULL) {
            if (coC->retornaObjeto(triA)->getEstado() == "Moroso") {
                cout << "----------------------------------------" << endl;
                cout << "Nombre: " << coC->retornaObjeto(triA)->getNombre() << endl <<
                    "ID: " << coC->retornaObjeto(triA)->getCedula() << endl <<
                    "Estado: " << coC->retornaObjeto(triA)->getEstado() << endl <<
                    "----------------------------------------" << endl << endl;
            }
        }
        triA++;
    } while (triA <= i);
}

void Interfaz::mostrarClientesInactivos(ContenedorTemplate<Deportista>* coC) { 
    int triA = 1;
    int i = coC->cantidadElementos();
    do {
        if (coC->retornaObjeto(triA) != NULL) {
            if (coC->retornaObjeto(triA)->getEstado() == "Inactivo") {
                cout << "----------------------------------------" << endl;
                cout << "Nombre: " << coC->retornaObjeto(triA)->getNombre() << endl <<
                    "ID: " << coC->retornaObjeto(triA)->getCedula() << endl <<
                    "Estado: " << coC->retornaObjeto(triA)->getEstado() << endl <<
                    "----------------------------------------" << endl << endl;
            }
        }
        triA++;
    } while (triA <= i);
}

void Interfaz::mostrarDeportistasMatriculadosEnCurso(ContenedorTemplate<Curso>* coC) {
    int cur = 1;
    int i = coC->cantidadElementos();
    int curso = 0;

    if (coC->cantidadElementos() != 0) {
        cout << "Codigos de Cursos: " << endl;
        do {
            cout << "#" << cur << " - " << coC->retornaObjeto(cur)->getCodigoCurso() << endl;
            cur++;
        } while (cur <= i);
        cout << "Seleccione el numero(#) de curso segun el codigo: ";
        if (cin >> curso) {

            if (coC->retornaObjeto(curso) != NULL) {
                system("pause");
                system("cls");
                ContenedorTemplate<Grupo>* coG = coC->retornaObjeto(curso)->getGrupos();
                int curG = 1;
                int iG = coG->cantidadElementos();
                if (coG->cantidadElementos() != 0) {
                    cout << "Hay " << coG->cantidadElementos() << " elementos." << endl;
                    int grupo;

                    cout << "Numero de grupos: " << endl;
                    do {
                        cout << "#" << curG << " - " << coG->retornaObjeto(curG)->getNumGrupo() << endl;
                        curG++;
                    } while (curG <= iG);

                    cout << "Seleccione el nuemro(#)grupo: ";
                    if (cin >> grupo) {

                        if (coG->retornaObjeto(grupo) != NULL) {
                            system("pause");
                            system("cls");
                            Interfaz::muestraSoloDeportistas(coG->retornaObjeto(grupo)->getIntegrantes());

                        }
                        else
                            throw new string("Error...grupo no existe.");
                    }
                    else
                        throw new ExcepcionValor();
                }
                else
                    throw new string("Error...no hay clientes registrados.");
            }
            else
                throw new string("Error...curso no existe.");
        }
        else
            throw new ExcepcionValor();
    }
    else
        throw new string("Error...no hay cursos registrados.");
}


