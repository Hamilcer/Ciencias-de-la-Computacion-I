#include <iostream>

#ifndef queue_h
#define queue_h

using namespace std;

template <class T> 
struct Nodo {
	Nodo <T> *sig;
	Nodo <T> *ant;
	T dato;
};

// Definición de la clase Queue
template <class T>
class Queue {
	Nodo <T> *cab;
	Nodo <T> *final;
	int tam;
	public: Queue() { // Constructor
		cab = NULL;
		final = NULL;
		tam = 0;
	}	
	T retornarElemento(int pos, char cabeza);
	int getTam() { return tam;}
	void Enqueue (T infoNueva, char cabeza);
	void Dequeue (char cabeza);
	bool queue_vacia ();
	~Queue();	
};	



// Función para retornar un elemento de la cola
template <class T>
T Queue<T>::retornarElemento(int pos, char cabeza){
	if (queue_vacia() || pos > tam || pos < 1){
		return T();
	} else {
		Nodo <T> *aux;
		int actual = 1;
		if (cabeza == 'I') { // Imprimir desde el primer Nodo hasta el último
			aux = cab;
			while (aux != NULL && actual<pos){
				aux = aux -> sig;			
				actual++;	
			}		
		
		return aux->dato;	
		} else { // Imprimir desde el último Nodo hasta el primero
			aux = final;
			while (aux != NULL && actual<pos){
				aux = aux -> ant;		
				actual++;		
			}
		return aux->dato;
		}
		
	}
	
}


// Función para agregar un elemento a la cola
template <class T>
void Queue<T>::Enqueue  (T infoNueva, char cabeza) { // cabeza indica si se va a operar en la cabeza ("I" de inicio) o en la cola ("F" de final) de la cola
	Nodo <T> *aux = new Nodo <T>;
	aux -> dato = infoNueva;
	if (queue_vacia()) { // Si la cola está vacía, el nuevo nodo se convierte en el primer y único elemento de la cola
		cab = final = aux;
		cab -> sig = NULL;
		cab -> ant = NULL;		
	} else if (cabeza == 'I') { // Si se quiere agregar el elemento al inicio de la cola
		aux -> sig = NULL;
		aux -> ant = final;
		final -> sig = aux;
		final = aux;
	} else {  // Si se quiere agregar el elemento al final de la cola
		aux -> sig = cab;
		aux -> ant = NULL;
		cab -> ant = aux;
		cab = aux;
	}
	tam++;
}


// Función para eliminar el primer elemento de la cola
template <class T>
void Queue<T>::Dequeue  (char cabeza){ // cabeza indica si se va a operar en la cabeza ("I" de inicio) o en la cola ("F" de final) de la cola
	T x;
	Nodo <T> *aux;
	if (cab != NULL) {
		if (cabeza == 'I'){ // Si se quiere eliminar el primer elemento de la cola
			aux = cab -> sig;
			aux -> ant = NULL;
			x = cab -> dato;
			delete cab;
			cab = aux;			
		} else { // Si se quiere eliminar el ultimo elemento de la cola
			aux = final -> ant;
			aux -> sig = NULL;
			x = final -> dato;
			delete final;
			final = aux;
		}
		tam--;	
	}
}


// Función para comprobar si la cola está vacía
template <class T>
bool Queue<T>::queue_vacia (){
	if (cab == NULL){
		return true;
	}
	return false;
}


// Destructor de la clase
template <class T>
Queue<T>::~Queue() {
	Nodo <T> *aux;
	while (cab != NULL){
		aux = cab;
		cab = aux -> sig;
		delete aux;
	}
	delete cab;
}

#endif 
