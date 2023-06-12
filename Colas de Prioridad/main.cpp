#include "ColasDePrioridadArr.h"
#include <iostream>
#include <conio.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {	

	int tam, valor, opcion, dato, prioridad;
	
	cout << "Ingrese el tamanio del arreglo: ";
	cin >> tam;
	Monticulo <int> cola(tam);
	
	while (true){
		system("cls");
		cout << "\t\t\t\tMENU"<< endl << endl;
		cout <<	"1. Ingresar Número" << endl;
		cout << "2. Atender" << endl;
		cout << "3. Verificar si esta vacia" << endl;
		cout << "4. Verificar si esta llena" << endl;
		cout << "5. Imprimir" << endl;
		cout << "------0 para SALIR del programa------" << endl;
		cin >> opcion;
		
		
		if (opcion == 0){
			cola.~Monticulo();
			break;
		}
		
		switch (opcion) {
			
			case 1: 
				cout << "Escriba el número que desea ingresar a la cola:" << endl;
				cin >> dato;
				//cout << "Escriba la prioridad en cola, siendo este el mismo número:" << endl;
				// Este programa puede separar el dato de la prieridad
				// Ya que se ha pedido trabajar con enteros, el dato es igual a la prioridad
				prioridad = dato;
				cola.insertar(prioridad, dato);
				break;
			case 2:    
				cout << "Atendido" << endl;
				valor = cola.atender();
				cola.imprimirArreglo();
				if (cola.MonticuloVacio()){
					cout << "Cola vacia" << endl;				
				}							 
				break;
			case 3:
			    if (cola.MonticuloVacio()) {
			        cout << "La cola esta vacia" << endl;
			    } else {
			        cout << "La cola no esta vacia" << endl;
			    }
			    break;
			case 4:
			    if (cola.MonticuloLleno()) {
			        cout << "La cola esta llena" << endl;
			    } else {
			        cout << "La cola no esta llena" << endl;
			    }
			    break;
			case 5:
				cout << "Esta es la Cola:" << endl;
				cola.imprimirArreglo();
				break;
			default:
				cout << "Opción incorrecta" << endl;
		}
		
		system("pause");
	}	
			
	return 0;
}