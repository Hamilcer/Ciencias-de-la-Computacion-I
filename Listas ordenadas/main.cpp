#include "listaOrdenada.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <sstream>
using namespace std;

std::ostream& operator<<(std::ostream& os, const Estud& est) { //eso es para imprimir bien 
    os << "Nombre: " << est.nombre << ", Codigo: " << est.cod;
    return os;
}


int main(int argc, char** argv) {
	
	//añadir los carácteres especiales 
	setlocale(LC_ALL, "");
	
	do{
		// Crear una lista de estudiantes
	    listaOrdenada estudiantes;
	
	    // Llenar la lista con 10 elementos
	    Estud est1 = {"Juan", 103};
	    estudiantes.insertar(est1);
	
	    Estud est2 = {"Maria", 109};
	    estudiantes.insertar(est2);
	
	    Estud est3 = {"Pedro", 110};
	    estudiantes.insertar(est3);
	
	    Estud est4 = {"Luis", 102};
	    estudiantes.insertar(est4);
	
	    Estud est5 = {"Ana", 115};
	    estudiantes.insertar(est5);
	
	    Estud est6 = {"Carla", 111};
	    estudiantes.insertar(est6);
	
	    Estud est7 = {"Miguel", 106};
	    estudiantes.insertar(est7);
	
	    Estud est8 = {"Sofia", 120};
	    estudiantes.insertar(est8);
	
	    Estud est9 = {"Diego", 108};
	    estudiantes.insertar(est9);
	
	    Estud est10 = {"Lucia", 100};
	    estudiantes.insertar(est10);
	
	    // Imprimir la lista ordenada por código
	    cout << "Lista ordenada por codigo: " << endl;
	    estudiantes.mostrar_lista();
	    cout << endl;
	
	    // Eliminar dos elementos
	    estudiantes.borrar(109);
	    estudiantes.borrar(111);
	
	    // Imprimir la nueva lista ordenada por código
	    cout << "Lista sin los elementos eliminados: " << endl;
	    estudiantes.mostrar_lista();
	    cout << endl;
	
	    // Modificar dos elementos
	    estudiantes.modificar(102);
	    estudiantes.modificar(115);
	
	    // Imprimir la nueva lista ordenada por código
	    cout << "Lista con los elementos modificados: " << endl;
	    estudiantes.mostrar_lista();
	    cout << endl;
		
		
		
		
	
        cout<<"\n*****Deseas hacer uso del programa nuevamente? (1 para SI; otra tecla para NO)"<<endl;
    }while((getch() ) =='1'); //Condición para hacer de nuevo el cálculo
	
	
	return 0;
}