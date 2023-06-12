#include <iostream>

#ifndef lib_h
#define lib_h

using namespace std;

/*
	En esta libreria esta desarrolladad utilizando plantillas
	las cuales van a corresponder con la informacion que se guarda 
	en cada nodo.

	La prioridad es un valor de tipo entero, la mayor prioridad corresponde 
	al entero de mayor valor 
	
*/

template <class T>
// Cada nodo tiene una proriedad de tipo entero e informacion que se le asigne
struct Nodo {
	int valorPrioridad;
	T info;
};

template <class T>
class Monticulo{
	Nodo <T> *cola;
	// posAct determina la posicion actual, esto quiere decir el espacio libre para insertar
	int tam, posAct;
	public: Monticulo(int tamanio){
		tam = tamanio + 1;
		posAct = 0;
		cola = new Nodo<T>[tam];
	}
	bool insertar(int prioridad, T dato);
	int atender();
	void imprimirArreglo();
	bool MonticuloLleno();
	bool MonticuloVacio();
	~Monticulo();
};


template <class T>
bool Monticulo<T>::insertar(int prioridad, T dato){
	int posicionHijo = posAct + 1, posicionPadre = posicionHijo / 2;

	// Se comprueba que el monticulo no este lleno para atender 
	if (!MonticuloLleno()){		
		if (posAct >= 1){		

			// Se organiza de acuero a la prioridad 
			while (cola[posicionPadre].valorPrioridad < prioridad && posicionPadre > 0){
				cola[posicionHijo].valorPrioridad = cola[posicionPadre].valorPrioridad;
				cola[posicionHijo].info = cola[posicionPadre].info;
				posicionHijo = posicionPadre;
				posicionPadre /= 2;
			}			
		}
		cola[posicionHijo].valorPrioridad = prioridad;
		cola[posicionHijo].info = dato;
		posAct++;
		return true;
	}
	return false;
}

template <class T>
bool Monticulo<T>::MonticuloVacio(){
	if (posAct == 0){
		return true;
	}
	return false;
}


//	El criterio para atender es iniciando con el entero de mayor valor
template <class T>
int Monticulo<T>::atender(){
	if (posAct > 0){
		int posicionVacia = 1, posicionHijo = 2, posicionCambio = 2, posMayor;

		// se crea un nodo raiz el cual es el que va a ser atendido 
		Nodo <T> raiz;
		raiz.valorPrioridad = cola[1].valorPrioridad;
		raiz.info = cola[1].info;

		// Ahora se reroganiza la lista de acuerdo a las prioridades 
		while (posicionHijo <= posAct){
			if (cola[posicionHijo].valorPrioridad > cola[posAct].valorPrioridad){
				posicionCambio = posicionHijo;
				posMayor = posicionHijo;
			} else {
				posicionCambio = posAct;
				posMayor = posAct;
			}		
			if (posicionHijo + 1 <= posAct && cola[posicionHijo + 1].valorPrioridad > cola[posicionCambio].valorPrioridad) {
				posicionCambio = posicionHijo + 1;
			}
			cola[posicionVacia].valorPrioridad = cola[posicionCambio].valorPrioridad;
			cola[posicionVacia].info = cola[posicionCambio].info;
			posicionVacia = posicionCambio;
			posicionHijo = posicionVacia * 2;
		}	
		posAct--;		
		return raiz.valorPrioridad;	
	}
	return 0;		
}

// En este caso se sabe que se trabaja con enteros, asi que se definio la funcion imprimir 
template <class T>
void Monticulo<T>::imprimirArreglo(){
	for (int i = 1; i <= posAct; i++){
		cout << "- " << cola[i].valorPrioridad << " -";
	}
	cout << endl;
}

// Indica cuando no se puede agregar mas nodos
template <class T>
bool Monticulo<T>::MonticuloLleno(){
	if (posAct == tam){
		return true;
	}
	return false;
}

// Este es el destructor el cual eliminar la cola que es el arreglo de nodos
template <class T>
Monticulo<T>::~Monticulo(){
	delete cola;
}


#endif /* lib_h */
