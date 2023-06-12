#include "queue.h"
#include <iostream>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

Queue<int> colaDoble;  // crear una bicola de enteros


void imprimir(char cabeza){
	cout <<"La informaci�n de la Lista es: "<<endl; 
	
    for(int i = 1; i<=colaDoble.getTam(); i++)
    {
    	cout << "Informaci�n de la cola: " << colaDoble.retornarElemento(i, cabeza) << endl;
	}
}

int main(int argc, char** argv) {
	
    colaDoble.Enqueue(10, 'I');  // agregar un elemento al inicio
    colaDoble.Enqueue(20, 'I');  // agregar otro elemento al inicio
    colaDoble.Enqueue(50, 'I');  // agregar otro elemento al inicio
    colaDoble.Enqueue(70, 'F');  // agregar otro elemento al inicio
    colaDoble.Enqueue(30, 'F');  // agregar un elemento al final
    colaDoble.Enqueue(40, 'F');  // agregar otro elemento al final

    imprimir('I');  // imprimir la bicola por el inicio
    imprimir('F');  // imprimir la bicola por el final

    colaDoble.Dequeue('I');  // quitar un elemento del inicio
    colaDoble.Dequeue('F');  // quitar un elemento del final

    imprimir('I');  // imprimir la bicola por el inicio
    imprimir('F');  // imprimir la bicola por el final
    
	return 0;
}
