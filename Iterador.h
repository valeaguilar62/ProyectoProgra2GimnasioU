#pragma once
#include "NodoT.h"


template<class T>
class Iterador {
private:
	NodoT<T>* pNodo;
public:
	Iterador(NodoT<T>*);
	virtual ~Iterador();
	NodoT<T>* getPNodo();
	void siguiente();
	bool masElementos();
	bool vacia();
	void setPNodo(NodoT<T>*);
	T* actual();
	
};

template<class T>
Iterador<T>::Iterador(NodoT<T>* nod) {
	pNodo = nod;
}

template<class T>
Iterador<T>:: ~Iterador() {}

template<class T>
NodoT<T>* Iterador<T>::getPNodo() { return pNodo; }


template<class T>
inline void Iterador<T>::siguiente()
{
	pNodo = pNodo->getSig();
}

template<class T>
inline bool Iterador<T>::masElementos()
{
	if (pNodo->getSig() != NULL) {
		return true;
	}
	else {
		return false;
	}

}

template<class T>
inline bool Iterador<T>::vacia()
{
	return pNodo == NULL;
}

template<class T>
inline void Iterador<T>::setPNodo(NodoT<T>* nod)
{
	pNodo = nod;
}

template<class T>
inline T* Iterador<T>::actual()
{
	return pNodo->getPuntero();
}
