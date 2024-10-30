#pragma once
#include"Iterador.h"


template<class T>
class ContenedorTemplate {
private:
	NodoT<T>* ppio;
public:
	ContenedorTemplate();
	virtual ~ContenedorTemplate();

	NodoT<T>* getPpio();

	int cantidadElementos();
	void agregarElemento(T*);
	void agregarElementoFinal(T*);
	bool eliminarElemento(int);
	bool existeElemetno(T*);
	T* retornaObjeto(int);
	Iterador<T>* obtenerIterador(NodoT<T>*);

	void eliminarTodos();

	ContenedorTemplate<T>& operator =(ContenedorTemplate<T>&);
	bool operator !=(ContenedorTemplate<T>&);

	string toString();
	void guardarTodo(ostream&);
	bool vacia();

};



template<class T>
ContenedorTemplate<T>::ContenedorTemplate() {
	ppio = NULL;
}
template<class T>
ContenedorTemplate<T>::~ContenedorTemplate() {
	Iterador<T>* iter = obtenerIterador(ppio);
	while (iter->getPNodo() != NULL) {
		ppio = ppio->getSig();
		delete iter->getPNodo();
		iter->setPNodo(ppio);
	}
	ppio = NULL;
	delete iter;
}

template<class T>
inline NodoT<T>* ContenedorTemplate<T>::getPpio()
{
	if (ppio != NULL) {
		return ppio;
	}
	else {
		return NULL;
	}
}

template<class T>
int ContenedorTemplate<T>::cantidadElementos() {
	Iterador<T>* iter = obtenerIterador(ppio);
	int cantidad = 0;
	while (iter->getPNodo() != NULL) {
		iter->siguiente();
		cantidad++;
	}
	delete iter;
	return cantidad;
}
template<class T>
void ContenedorTemplate<T>::agregarElemento(T* ptr) {
	ppio = new NodoT<T>(ptr, ppio);
}
template<class T>
void ContenedorTemplate<T>::agregarElementoFinal(T* ptr) {
	NodoT<T>* pExt = ppio;
	if (ppio == nullptr) { //la lista está vacía
		this->agregarElemento(ptr);
	}
	else {
		while (pExt->getSig() != nullptr) {
			pExt = pExt->getSig();
		}

		NodoT<T>* nN = new NodoT<T>(ptr, NULL);
		pExt->setSig(nN);
	}
}

template<class T>
inline bool ContenedorTemplate<T>::eliminarElemento(int pos)
{
	Iterador<T>* iter = new Iterador<T>(ppio);
	Iterador<T>* iterBorrar = new Iterador<T>(ppio);
	int contador = 1;
	if (pos <= cantidadElementos()) {
		if (pos == 1) {
			ppio = ppio->getSig();
			delete iter->getPNodo();
			return true;
		}
		while (contador != pos - 1) {
			iter->siguiente();
			contador++;
		}
		iterBorrar->setPNodo(iter->getPNodo());
		iterBorrar->siguiente();
		iter->getPNodo()->setSig(iterBorrar->getPNodo()->getSig());
		delete iterBorrar->getPNodo();
		delete iter;
		delete iterBorrar;
		return true;
	}
	delete iter;
	delete iterBorrar;
	return false;
}
template<class T>
inline bool ContenedorTemplate<T>::existeElemetno(T* ptr)
{
	Iterador<T>* iter = new Iterador<T>(ppio);
	while (iter->getPNodo() != NULL) {
		if (iter->actual() == ptr) {
			return true;
		}
		iter->siguiente();
	}
	return false;
}
template<class T>
inline T* ContenedorTemplate<T>::retornaObjeto(int n)
{
	int contador = 1;
	Iterador<T>* iter = obtenerIterador(ppio);
	if ((n <= cantidadElementos() && n != 0)) {
		while (contador < n) {
			contador++;
			iter->siguiente();
		}

		T* aux = iter->actual();
		delete iter;
		return aux;
	}
	return NULL;
}
template<class T>
inline Iterador<T>* ContenedorTemplate<T>::obtenerIterador(NodoT<T>* nod) {
	return new Iterador<T>(nod);
}
template<class T>
void ContenedorTemplate<T>::eliminarTodos() {
	NodoT<T>* pExt = ppio;
	NodoT<T>* pExtAux = ppio;
	while (pExt != NULL) {
		pExtAux = pExtAux->getSig();
		delete pExt;
		NodoT<T>* pExt = pExtAux;
	}
	delete pExtAux;
	ppio = NULL;
	return true;
}

template<class T>
bool ContenedorTemplate<T>::operator !=(ContenedorTemplate<T>& c2) {

	if (this->cantidadElementos() != c2.cantidadElementos())
		return true;

	NodoT<T>* pExt = ppio;
	NodoT<T>* pExtAux = c2.ppio;
	while (pExt != NULL or pExtAux != NULL) {
		if (pExt != pExtAux)
			return true;
		pExt = pExt->getSig();
		pExtAux = pExtAux->getSig();
	}

	return false;
}
template<class T>
ContenedorTemplate<T>& ContenedorTemplate<T>::operator = (ContenedorTemplate<T>& c2) {
	if (this != &c2) {
		this->eliminarTodos();
		NodoT<T>* pExt = ppio;
		NodoT<T>* pExtAux = c2.ppio;
		while (pExtAux != NULL) {
			this->agregarElemento(pExtAux);
			pExtAux = pExtAux->getSig();
		}

	}
	return *this;
}

template<class T>
inline string ContenedorTemplate<T>::toString()
{
	stringstream out;
	Iterador<T>* iter = new Iterador<T>(getPpio());
	int contador = 1;
	while (!(iter->vacia())) {
		out << contador << "- " << (iter->actual()->toString()) << endl;
		out << "--------------------------------------------------" << endl;
		iter->siguiente();
		contador++;
	}
	return out.str();
}

template<class T>
inline void ContenedorTemplate<T>::guardarTodo(ostream& salida)
{
	Iterador<T>* iter = new Iterador<T>(ppio);
	while (iter->getPNodo() != NULL) {
		iter->getPNodo()->getPuntero()->guardar(salida);
		iter->siguiente();
	}
}

template<class T>
inline bool ContenedorTemplate<T>::vacia()
{
	if (ppio == NULL) { 
		return true; 
	}
	else {
		return false;
	}
}
