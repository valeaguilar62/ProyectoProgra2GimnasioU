#include "Gimnasio.h"

Gimnasio::Gimnasio(string nom,Fecha* actual, double mes)
{
    nombreG = nom;
    fechaActual = actual;
    mensualidad = mes;
    contenedorClientes = new ContenedorTemplate<Deportista>();
    contenedorReservas = new ContenedorTemplate<Reserva>();
    contenedorCursos = new ContenedorTemplate<Curso>();
    contenedorPagos = new ContenedorTemplate<Expediente>();
    contenedorInstructores = new ContenedorTemplate<Instructor>();
}

Gimnasio::~Gimnasio()
{
    delete contenedorClientes;
    delete contenedorCursos;
    delete contenedorPagos;
    delete contenedorReservas;
}

void Gimnasio::setFecha(Fecha* f) { fechaActual = f; }
void Gimnasio::setNombreGym(string nom) { nombreG = nom; }
void Gimnasio::setMensualidad(double men) { mensualidad = men; }

void Gimnasio::guardarContenedorTriatlonista(ostream& salida)
{
    contenedorClientes->guardarTodo(salida);
}
void Gimnasio::guardarContenedorReserva(ostream& salida)
{
    contenedorReservas->guardarTodo(salida);
}
void Gimnasio::guardarContenedorCurso(ostream& salida)
{
    contenedorCursos->guardarTodo(salida);
}
void Gimnasio::guardarContenedorInstructor(ostream& salida)
{
    contenedorInstructores->guardarTodo(salida);
}
void Gimnasio::guardarContenedorExpediente(ostream& salida)
{
    contenedorPagos->guardarTodo(salida);
}


void Gimnasio::recuperarContenedorTriatlonista(istream& entrada)
{
    while (!(entrada.eof()) && entrada.good()) {
       
        Deportista* ptr = Triatlonista::recuperar(entrada);
        if (entrada.eof() ) {
            break;
        }
        contenedorClientes->agregarElemento(ptr);
      
    }
}
void Gimnasio::recuperarContenedorReserva(istream& entrada)
{
    while (!(entrada.eof()) && entrada.good()) {

        auto ptr = Reserva::recuperar(entrada);
        if (entrada.eof()) {
            break;
        }
        contenedorReservas->agregarElementoFinal(ptr);

    }
}
void Gimnasio::recuperarContenedorCurso(istream& entrada)
{
    while (!(entrada.eof()) && entrada.good()) {

        auto ptr = Curso::recuperar(entrada);
        if (entrada.eof()) {
            break;
        }
        contenedorCursos->agregarElementoFinal(ptr);

    }
}
void Gimnasio::recuperarContenedorInstructor(istream& entrada)
{
    while (!(entrada.eof()) && entrada.good()) {

        auto ptr = Instructor::recuperar(entrada);
        if (entrada.eof()) {
            break;
        }
        contenedorInstructores->agregarElementoFinal(ptr);

    }

}
void Gimnasio::recuperarContenedorExpediente(istream& entrada)
{
    while (!(entrada.eof()) && entrada.good()) {

        auto ptr = Expediente::recuperar(entrada);
        if (entrada.eof()) {
            break;
        }
        contenedorPagos->agregarElementoFinal(ptr);

    }
}

ContenedorTemplate<Reserva>* Gimnasio::getContenedorReservas()
{
    return contenedorReservas;
}
ContenedorTemplate<Curso>* Gimnasio::getContenedorCursos()
{
    return contenedorCursos;
}
ContenedorTemplate<Deportista>* Gimnasio::getContenedorClientes()
{
    return contenedorClientes;
}
ContenedorTemplate<Expediente>* Gimnasio::getContenenedorExpediente()
{
    return contenedorPagos;
}

bool Gimnasio::ingresaCurso()
{
    if (!(contenedorInstructores->vacia())) {
        if (Interfaz::agregaCurso(contenedorCursos)) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

bool Gimnasio::ingresaGrupo()
{
    if (!(contenedorCursos->vacia())) {
        if (Interfaz::agregaGrupo(contenedorCursos, contenedorInstructores)) {
            return true;
        }
    }
    else {
        return false;
    }
}

bool Gimnasio::ingresaCliente()
{
        bool encontrado = false;
        if (!(contenedorCursos->vacia())) {
            Iterador<Curso>* iter = new Iterador<Curso>(contenedorCursos->getPpio());
            while (iter->getPNodo() != NULL && !encontrado)
            {
                if (!(iter->actual()->getGrupos()->vacia())) {
                    encontrado = true;
                    if (Interfaz::agregaTriatlonista(contenedorClientes, contenedorInstructores, contenedorCursos, contenedorReservas, fechaActual, contenedorPagos, mensualidad)) {

                        return true;
                    }
                    else {
                        throw new string("Error... al ingresar datos");
                    }
                }
                iter->siguiente();
            }
            delete iter;
        }
        else {
            throw new ExcepcionCurso();
        }
}

bool Gimnasio::ingresaInstructor()
{
    if (Interfaz::agregaInstructor(contenedorClientes, contenedorInstructores)) {
        return true;
    }
    else {
        return false;
    }
}

bool Gimnasio::ingresaPago()
{
    if (!(contenedorClientes->vacia())) {
        if (Interfaz::actualizaExpediente(contenedorPagos, mensualidad, fechaActual)) {
            return true;
        }
    }
    else {
        return false;
    }
}

bool Gimnasio::ingresaMatriculaCurso()
{
    if (Interfaz::agregaMatriculaEnCurso(contenedorClientes, contenedorCursos, contenedorReservas, fechaActual)) {
        return true;
    }
    else {
        return false;
    }
}

bool Gimnasio::cancelaMatricula()
{
    if (Interfaz::cancelaMatricula(contenedorCursos, contenedorReservas)) {
        return true;
    }
    else {
        return false;
    }
}


bool Gimnasio::editaCurso()
{
    if (Interfaz::editaCurso(contenedorCursos)) {
        return true;
    }
    else {
        return false;
    }
}

bool Gimnasio::editaCliente()
{
    if (Interfaz::editaTriatlonista(contenedorClientes)) {
        return true;
    }
    else {
        return false;
    }
}

bool Gimnasio::editaGrupo()
{
    if (Interfaz::editaGrupo(contenedorCursos,contenedorInstructores)) {
        return true;
    }
    else {
        return false;
    }
}

Deportista* Gimnasio::retornaDepSegunCed(string ced) {

    Deportista* dep = NULL;

    if (!(contenedorClientes->vacia())) {

        Iterador<Deportista>* iterDep = new Iterador<Deportista>(contenedorClientes->getPpio());
            while (iterDep->getPNodo() != NULL) {
                if (iterDep->actual()->getCedula() == ced) {
                    dep= iterDep->actual();
                }
                iterDep->siguiente();
            }
    }
    return dep;
}

void Gimnasio::setEstadoClientes() {

    if (!(contenedorClientes->vacia()) && !(contenedorPagos->vacia())) {

        Iterador<Expediente>* iterExp = new Iterador<Expediente>(contenedorPagos->getPpio());
        Iterador<Pago>* iterPago = new Iterador<Pago>(NULL);
       
        while (iterExp->getPNodo()!=NULL) {

            if (!(iterExp->actual()->getPagos()->vacia())) {

                iterPago->setPNodo(iterExp->actual()->getPagos()->getPpio()); //obtiene iterador del contenedor de pagos de cada expediente

                while (iterPago->masElementos()) { //se posiciona en la ultima fecha ingresada al contenedor de pagos del expedinete
                    iterPago->siguiente();
                }
                if ((iterPago->actual()->getFecha()->getMes() < fechaActual->getMes()) or (iterPago->actual()->getFecha()->getAnio() < fechaActual->getAnio())) { // compara si el mes del ultimo pago es menor al actual

                    if (this->retornaDepSegunCed(iterExp->actual()->getCedula()) != NULL) {
                        if (this->retornaDepSegunCed(iterExp->actual()->getCedula())->getEstado() == "Activo")
                            this->retornaDepSegunCed(iterExp->actual()->getCedula())->setEstado("Moroso"); // si esta inactivo no realiza cambio
                       
                    }
                }
            }
            iterExp->siguiente(); // pasa se expedinte para comprobar los   
        }
    }
    
}

void Gimnasio::mostrarCurso() {
      Interfaz::mostrarCursoEspecif(contenedorCursos);
}
void Gimnasio::mostrarGrupo() {
      Interfaz::mostrarGrupoEspecif(contenedorCursos);
}
void Gimnasio::mostrarClientes() {
      Interfaz::mostrarClientes(contenedorClientes);
}
void Gimnasio::mostrarClienteEspecifico() {
      Interfaz::mostrarClientesEspecif(contenedorClientes);
}
void Gimnasio::mostrarExpediente() {
      Interfaz::mostrarExpedienteEspecif(contenedorPagos);
}

void Gimnasio::mostrarClientesActivos() {
      Interfaz::mostrarClientesActivos(contenedorClientes);
}
void Gimnasio::mostrarClientesMorosos() {
      Interfaz::mostrarClientesMorosos(contenedorClientes);
}
void Gimnasio::mostrarClientesInactivos() {
      Interfaz::mostrarClientesInactivos(contenedorClientes);
}

void Gimnasio::mostrarDeportistasMatriculadosEnCurso() {
    Interfaz::mostrarDeportistasMatriculadosEnCurso(contenedorCursos);
}

void Gimnasio::mostrarSoloDeportistas() {
    Interfaz::muestraSoloDeportistas(contenedorClientes);
}

void  Gimnasio::guardarTodoGym() {

    string rutaDeportista = "deportista.txt";
    string rutaReserva = "reserva.txt";
    string rutaCurso = "curso.txt";
    string rutaPago = "pago.txt";
    string rutaInstructor = "instructor.txt";
   
    ofstream salida;
    salida.open(rutaDeportista.c_str());
    this->guardarContenedorTriatlonista(salida);
    salida.close();
    salida.open(rutaInstructor.c_str());
    this->guardarContenedorInstructor(salida);
    salida.close();
    salida.open(rutaCurso.c_str());
    this->guardarContenedorCurso(salida);
    salida.close();
    salida.open(rutaPago.c_str());
    this->guardarContenedorExpediente(salida);
    salida.close();
    salida.open(rutaReserva.c_str());
    this->guardarContenedorReserva(salida);
    salida.close();
}
void  Gimnasio::recuperarTodoGym() {
    
    string rutaDeportista = "deportista.txt";
    string rutaReserva = "reserva.txt";
    string rutaCurso = "curso.txt";
    string rutaPago = "pago.txt";
    string rutaInstructor = "instructor.txt";

    ifstream entrada;
    entrada.open(rutaDeportista.c_str());
    this->recuperarContenedorTriatlonista(entrada);
    entrada.close();
    entrada.open(rutaCurso.c_str());
    this->recuperarContenedorCurso(entrada);
    entrada.close();
    entrada.open(rutaInstructor.c_str());
    this->recuperarContenedorInstructor(entrada);
    entrada.close();
    entrada.open(rutaPago.c_str());
    this->recuperarContenedorExpediente(entrada);
    entrada.close();
    entrada.open(rutaReserva.c_str());
    this->recuperarContenedorReserva(entrada);
    entrada.close();
}