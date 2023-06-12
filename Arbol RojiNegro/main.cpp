#include <iostream>
#include "ArbolRojiNegro.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char **argv)
{

	ArbolRojiNegro<int> arbolito;

	arbolito.insertarNodo(86);
	arbolito.insertarNodo(65);
	arbolito.insertarNodo(70);
	arbolito.insertarNodo(73);
	arbolito.insertarNodo(93);
	arbolito.insertarNodo(69);
	arbolito.insertarNodo(25);
	arbolito.insertarNodo(66);
	arbolito.insertarNodo(68);
	arbolito.insertarNodo(47);
	arbolito.insertarNodo(62);
	arbolito.insertarNodo(10);

	arbolito.eliminarNodo(10);
	arbolito.eliminarNodo(25);
	arbolito.eliminarNodo(65);
	arbolito.eliminarNodo(66);
	arbolito.eliminarNodo(73);
	arbolito.eliminarNodo(93);
	arbolito.eliminarNodo(47);
	arbolito.eliminarNodo(62);

	cout << "Recorridos en el arbol:" << endl;

	NodoArbol<int> *nodoAux; // NodoArbol auxiliar para imprimir

	cout << "InOrden" << endl;
	Cola<NodoArbol<int> *> CInOrden = arbolito.obtenerInOrden(arbolito.obtenerRaiz());
	while (!CInOrden.isVacia())
	{
		nodoAux = CInOrden.dequeue();
		cout << nodoAux->info << " - " << ((nodoAux->color) ? "ROJO" : "NEGRO") << endl;
	}

	cout << "PreOrden" << endl;
	Cola<NodoArbol<int> *> CPreOrden = arbolito.obtenerPreOrden(arbolito.obtenerRaiz());
	while (!CPreOrden.isVacia())
	{
		nodoAux = CPreOrden.dequeue();
		cout << nodoAux->info << " - " << ((nodoAux->color) ? "ROJO" : "NEGRO") << endl;
	}

	cout << "PostOrden" << endl;
	Cola<NodoArbol<int> *> CPostOrden = arbolito.obtenerPostOrden(arbolito.obtenerRaiz());
	while (!CPostOrden.isVacia())
	{
		nodoAux = CPostOrden.dequeue();
		cout << nodoAux->info << " - " << ((nodoAux->color) ? "ROJO" : "NEGRO") << endl;
	}

	cout << "Niveles" << endl;
	Cola<NodoArbol<int> *> CNiveles = arbolito.obtenerNiveles(arbolito.obtenerRaiz());
	while (!CNiveles.isVacia())
	{
		nodoAux = CNiveles.dequeue();
		cout << nodoAux->info << " - " << ((nodoAux->color) ? "ROJO" : "NEGRO") << endl;
	}

	cout << endl;
	cout << "Arbol final:" << endl;
	arbolito.imprimir();

	return 0;
}
