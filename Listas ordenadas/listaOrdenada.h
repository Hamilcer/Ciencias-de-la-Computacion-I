#include <iostream>

#ifndef listaOrdenada_h
#define listaOrdenada_h

using namespace std;

struct Estud {
	string nombre;
	int cod;
};


struct nodo {
	Estud Dato;
	nodo *sig;
};

class listaOrdenada {
		nodo *cab = new nodo;
		nodo *fin = NULL;
		int tam;

	public:
		listaOrdenada() {
			Estud vacio = {"NULO", -1};
			cab->Dato= vacio;
			cab->sig=NULL;
			tam=0;
		}
		void mostrar_lista();
		int getTam() {
			return tam;
		}
		bool lista_vacia();
		void insertar(Estud Dato);
		bool borrar(int codigo);
		Estud buscar (int codigo);
		bool modificar(int  codigo);
};


// Verificar si la lista esta vacia
bool listaOrdenada::lista_vacia() {
	if(tam==0 || cab==NULL) {
		return true;
	}
	return false;
}
// Mostrar los elementos de la lista
void listaOrdenada::mostrar_lista() {
	if(lista_vacia()) {
		cout << "La lista esta vacia." << endl;
		return;
	}
	nodo *p = cab->sig;
	while(p != NULL) {
		cout << "Codigo: " << p->Dato.cod << " Nombre: " << p->Dato.nombre << endl;
		p = p->sig;
	}
}


// Insertar un elemento en orden según su código
void listaOrdenada::insertar(Estud Dato) {
	nodo *p = cab->sig;
	nodo *ant = cab;
	nodo *nuevo = new nodo;
	nuevo->Dato = Dato;
	while(p != NULL && p->Dato.cod < Dato.cod) {
		ant = p;
		p = p->sig;
	}
	ant->sig = nuevo;
	nuevo->sig = p;
	tam++;
}

// Borrar un elemento según su código
bool listaOrdenada::borrar(int codigo) {
	nodo *p = cab->sig;
	nodo *ant = cab;
	while(p != NULL && p->Dato.cod != codigo) {
		ant = p;
		p = p->sig;
	}
	if(p == NULL) {
		return false;
	}
	ant->sig = p->sig;
	delete p;
	tam--;
	return true;
}

// Buscar un elemento según su código
Estud listaOrdenada::buscar (int codigo) {
	nodo *p = cab->sig;
	while(p != NULL && p->Dato.cod != codigo) {
		p = p->sig;
	}
	if(p == NULL) {
		Estud vacio = {"NULO", -1};
		return vacio;
	}
	return p->Dato;
}

// Modificar el nombre de un elemento según su código
bool listaOrdenada::modificar(int codigo) {
	nodo *p = cab->sig;
	while(p != NULL && p->Dato.cod != codigo) {
		p = p->sig;
	}
	if(p == NULL) {
		return false;
	}
	cout << "Ingrese el nuevo nombre: ";
	cin >> p->Dato.nombre;
	return true;
}



#endif