#pragma once
#include "Utilidad.h"

template<class T>
class NodoT {
private:
	T* puntero;
	NodoT<T>* sig;
public:
	NodoT(T* obj = NULL, NodoT<T>* nodoObj = NULL);
	virtual ~NodoT();

	T* getPuntero();
	NodoT<T>* getSig();
	void setPuntero(T*);
	void setSig(NodoT<T>*);

	friend ostream& operator << (ostream& out, const NodoT<T>& n) {
		out <<	*(n.getPuntero()) << endl;
		return out;
	}
};

template<class T>
 NodoT<T>::NodoT(T* obj, NodoT<T>* nodoObj): puntero(obj), sig(nodoObj) {}

template<class T>
 NodoT<T>::~NodoT() {
	
	delete puntero;
}

template<class T>
 T* NodoT<T>::getPuntero() { return puntero; }

template<class T>
 NodoT<T>* NodoT<T>::getSig() { return sig; }

template<class T>
 void NodoT<T>::setPuntero(T* obj) { puntero = obj; }

template<class T>
 void NodoT<T>::setSig(NodoT<T>* nodoObj) { sig = nodoObj; }

 