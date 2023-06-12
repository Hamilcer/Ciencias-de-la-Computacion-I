#include "Pila.h"
#include "arbolBinarioOrdenadoArr.h"
#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;


int main(int argc, char **argv)
{
	int tam = 8;
	arbinordArreglo miArbol = arbinordArreglo(tam);
	miArbol.insertar(100);
	miArbol.insertar(90);
	miArbol.insertar(80);
	miArbol.insertar(110);
	miArbol.insertar(95);
	miArbol.insertar(120);
	miArbol.eliminar(95);
	miArbol.eliminar(90);
	miArbol.insertar(30);
	miArbol.insertar(140);
	miArbol.insertar(108);
	miArbol.eliminar(120);
	miArbol.eliminar(30);
	miArbol.insertar(128);
	miArbol.insertar(97);
	miArbol.insertar(85);
	miArbol.eliminar(110);
	miArbol.eliminar(100);

	cout<< " Recorrido InOrden "<<endl;
	miArbol.inOrden().imprimir();
	cout << endl;
	cout<< " Recorrido PreOrden "<<endl;
	miArbol.preOrden().imprimir();
	cout << endl;
	cout<< " Recorrido PosOrden "<<endl;
	miArbol.posOrden().imprimir();
	cout << endl;
	cout<< " Recorrido Por Niveles "<<endl;
	miArbol.niveles().imprimir();
	cout << endl<< endl;;
	
	cout<< "Valores del nodo en cada posicion del array"<<endl;
	miArbol.imprimir(tam);
	return 0;
}
