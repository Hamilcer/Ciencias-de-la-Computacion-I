#include "lista.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <sstream>



using namespace std;

struct Estud{string nombre;
			   int cod;	
};

std::ostream& operator<<(std::ostream& os, const Estud& est) { //eso es para imprimir bien 
    os << "Nombre: " << est.nombre << ", Codigo: " << est.cod;
    return os;
}

void mostrarListaEnteros(lista<int> a) {
    cout<<"///// Lista de enteros ///// "<<endl;
    cout<<endl<<"Se comprueba si la lista esta vacia SI(1) NO(0): "<<a.lista_vacia()<<"."<<endl;

    cout<<endl<<"Se llena la lista con 10 elementos"<<endl;
    for(int cont=0; cont<10; cont++){
        a.insertar((cont)*10, cont);
    }
    cout<<endl<<"Se comprueba si la lista tiene informacion SI(0) NO(1): "<<a.lista_vacia()<<"."<<endl;
    cout<<endl<<"**Lista inicial**"<<endl;
    a.mostrar_lista();
    cout<<endl;

    cout<<endl<<"Se muestra el tamaño de la lista: "<<a.getTam()<<"."<<endl;

    cout<<endl<<"Se busca por el dato No. 5: "<<a.buscar(5)<<"."<<endl;

    cout<<endl<<"Se elimina el dato No. 3, SI(1) NO(0): "<<a.borrar(3)<<"."<<endl;

    cout<<endl<<"Se inserta el dato 250 en la posicion 5."<<endl;
    a.insertar(250, 5-1);
    
    cout<<endl<<"Se modficia el dato en la posicion 6 con un dato 117."<<endl;
    a.insertar(117, 6-1);

    cout<<"Se inserta el dato 28 al final."<<endl;
    a.insertar_final(28);

    cout<<"Insertamos el dato 500 al inicio."<<endl;
    a.insertar_inicio(500);
    
    cout<<endl<<"**Lista final tras modificaciones**"<<endl;
    a.mostrar_lista();
    cout<<endl;
}

void mostrarListaFloat(lista<float> b) {
    cout<<"///// Lista de Float ///// "<<endl;
    cout<<endl<<"Se comprueba si la lista esta vacia SI(1) NO(0): "<<b.lista_vacia()<<"."<<endl;

    cout<<endl<<"Se llena la lista con 10 elementos"<<endl;
    for(float cont=0.05; cont<10; cont++){
        b.insertar((cont)*10, cont);
    }
    cout<<endl<<"Se comprueba si la lista tiene informacion SI(0) NO(1): "<<b.lista_vacia()<<"."<<endl;
    cout<<endl<<"**Lista inicial**"<<endl;
    b.mostrar_lista();
    cout<<endl;

    cout<<endl<<"Se muestra el tamaño de la lista: "<<b.getTam()<<"."<<endl;

    cout<<endl<<"Se busca por el dato No. 5: "<<b.buscar(5)<<"."<<endl;

    cout<<endl<<"Se elimina el dato No. 3, SI(1) NO(0): "<<b.borrar(3)<<"."<<endl;

    cout<<endl<<"Se inserta el dato 2.56 en la posicion 5."<<endl;
    b.insertar(2.56, 5-1);
    
    cout<<endl<<"Se modificia el dato en la posicion 6."<<endl;
    b.insertar(1.17, 6-1);

    cout<<"Se inserta el dato 33.5 al final."<<endl;
    b.insertar_final(33.5);

    cout<<"Se inserta el dato 9.1 al inicio."<<endl;
    b.insertar_inicio(9.1);
    
    cout<<endl<<"**Lista final tras modificaciones**"<<endl;
    b.mostrar_lista();
    cout<<endl;
}

void mostrarListaChar(lista<char> c) {
    cout<<"///// Lista de Char ///// "<<endl;
    cout<<endl<<"Se comprueba si la lista esta vacia SI(1) NO(0): "<<c.lista_vacia()<<"."<<endl;

    cout<<endl<<"Se llena la lista con 10 elementos"<<endl;
    for(char cont='a'; cont<='j'; cont++){
    	c.insertar((int)cont, (float)cont/10);
	}
    cout<<endl<<"Se comprueba si la lista tiene informacion SI(0) NO(1): "<<c.lista_vacia()<<"."<<endl;

	cout<<endl<<"**Lista inicial**"<<endl;
    c.mostrar_lista();
    cout<<endl;

    cout<<endl<<"Se muestra el tamaño de la lista: "<<c.getTam()<<"."<<endl;

    cout<<endl<<"Se busca por el dato No. 5: "<<c.buscar(5)<<"."<<endl;

    cout<<endl<<"Se elimina el dato No. 3, SI(1) NO(0): "<<c.borrar(3)<<"."<<endl;

    cout<<endl<<"Insertamos el dato M en la posicion 5."<<endl;
    c.insertar('m', 5-1);
    
    cout<<endl<<"Se modificia el dato en la posicion 6."<<endl;
    c.insertar('w', 6-1);

    cout<<"Insertamos el dato X al final."<<endl;
    c.insertar_final('x');

    cout<<"Insertamos el dato Z al inicio."<<endl;
    c.insertar_inicio('z');
    
    cout<<endl<<"**Lista final tras modificaciones**"<<endl;
    c.mostrar_lista();
    cout<<endl;
}

void mostrarListaEstud(lista<Estud> d) {
    cout<<"///// Lista de Estudiantes ///// "<<endl;
    cout<<endl<<"Se comprueba si la lista esta vacia SI(1) NO(0): "<<d.lista_vacia()<<"."<<endl;

    cout<<endl<<"Se llena la lista con 10 elementos"<<endl;
    Estud cont[10] = {
    	{"Juan", 101}, {"Maria", 102}, {"Pedro", 103}, {"Ana", 104}, {"Luis", 105}, {"Laura", 106},
    	{"Carlos", 107}, {"Sofia", 108}, {"Andres", 109}, {"Lucia", 110} 
	};

	for (int i = 0; i < 10; i++) {
	    d.insertar(cont[i], i);
	} 
	
    cout<<endl<<"Se comprueba si la lista tiene informacion SI(0) NO(1): "<<d.lista_vacia()<<"."<<endl;

	cout<<endl<<"**Lista inicial**"<<endl;
    d.mostrar_lista();
    cout<<endl;

    cout<<endl<<"Se muestra el tamaño de la lista: "<<d.getTam()<<"."<<endl;

    cout<<endl<<"Se busca por el dato No. 5: "<<d.buscar(5)<<"."<<endl;

    cout<<endl<<"Se elimina el dato No. 3, SI(1) NO(0): "<<d.borrar(3)<<"."<<endl;

    cout<<endl<<"Insertamos el dato M en la posicion 5."<<endl;
    d.insertar({"Mauricio", 117}, 5-1);
    
    cout<<endl<<"Se modificia el dato en la posicion 6."<<endl;
    d.insertar({"Hamilton", 180}, 6-1);

    cout<<"Insertamos el dato X al final."<<endl;
    d.insertar_final({"Ariadna", 113});

    cout<<"Insertamos el dato Z al inicio."<<endl;
    d.insertar_inicio({"Felipe", 120});
    
    cout<<endl<<"**Lista final tras modificaciones**"<<endl;
    d.mostrar_lista();
    cout<<endl;
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	//añadir los carácteres especiales 
	setlocale(LC_ALL, "");
	
	lista<int> a;
	lista<float> b;
	lista<char> c;
	lista<Estud> d;
	
	int menu;	
	do{
		system("cls");
		cout<<"***Programa de listas simples***";
		cout<<"\n1. Para probar una lista de enteros";
		cout<<"\n2. Para probar una lista de float";
		cout<<"\n3. Para probar una lista de char";
		cout<<"\n4. Para probar una lista de Estudiantes";
		cout<<"\nIngrese la opcion a probar: ";
		cin>>menu;
		
		
		switch(menu){
	        case 1:
	        	// Insertar elementos en la lista de enteros
	        	cout<<endl;
				mostrarListaEnteros(a);
	        break;
	        
	        case 2:
	        	// Insertar elementos en la lista de flotantes
	        	cout<<endl;
   				mostrarListaFloat(b);				
	        break;
	        
	        case 3:	
	        	// Insertar elementos en la lista de caracteres
	        	cout<<endl;
    			mostrarListaChar(c);
	        break;
	        
	        case 4:
	        	// Insertar elementos en la lista de estudiantes
	        	cout<<endl;
				mostrarListaEstud(d);
	        break;
	        
	        default:
	    		cout<<"\nSelecciono una opcion no valida"<<endl;
	    	break;
	}
        cout<<"\n*****Deseas hacer uso del programa nuevamente? (1 para SI; otra tecla para NO)"<<endl;
    }while((getch() ) =='1'); //Condición para hacer de nuevo el cálculo
	
   
	return 0;
}
