#include <cstdlib>
#include <iostream>

#ifndef cola_h
#define cola_h

using namespace std;

struct nodoCola
{
	int dato;
	nodoCola *sig;
};

class cola
{
	nodoCola *cab, *fin;

public:
	cola()
	{
		cab = fin = NULL;
	}
	void insertar(int i);
	int atender();
	bool colaVacia();
	void imprimir();
	~cola();
};

void cola::insertar(int i)
{
	nodoCola *nuevo;
	nuevo = new nodoCola;
	nuevo->dato = i;
	nuevo->sig = NULL;
	if (cab == NULL)
	{
		cab = nuevo;
	}
	else
	{
		fin->sig = nuevo;
	}

	fin = nuevo;
}

int cola::atender()
{
	int x;
	nodoCola *aux = cab;
	cab = aux->sig;
	x = aux->dato;
	delete aux;
	return x;
}

bool cola::colaVacia()
{
	return (cab == NULL);
}

void cola::imprimir()
{
	nodoCola *nodoAux;
	nodoAux = cab;
	while (nodoAux != NULL)
	{
		cout << nodoAux->dato << " - ";
		nodoAux = nodoAux->sig;
	}
}

cola::~cola()
{
	nodoCola *aux;
	while (cab != NULL)
	{
		aux = cab;
		cab = aux->sig;
		delete aux;
	}
	delete cab;
}

#endif
