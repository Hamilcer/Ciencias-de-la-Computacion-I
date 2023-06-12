#include <cstdlib>

#ifndef pila_h
#define pila_h

struct nodoPila
{
	int dato;
	nodoPila *sig;
};

class pila
{
	nodoPila *cab;

public:
	pila()
	{
		cab = new nodoPila;
		cab->dato = ' ';
		cab->sig = NULL;
	}
	void push(int v);
	int pop();
	bool pilaVacia();
	~pila();
};

void pila::push(int v)
{
	nodoPila *t = new nodoPila;
	t->dato = v;
	t->sig = cab->sig;
	cab->sig = t;
}

int pila::pop()
{
	int x;
	nodoPila *t = cab->sig;
	cab->sig = t->sig;
	x = t->dato;
	delete t;
	return x;
}

bool pila::pilaVacia()
{
	return cab->sig == NULL;
}

pila::~pila()
{
	nodoPila *t = cab;
	while (t != NULL)
	{
		cab = t;
		t = t->sig;
		delete cab;
	}
}

#endif
