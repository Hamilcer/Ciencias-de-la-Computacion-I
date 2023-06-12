#include <iostream>

#ifndef LISTA_H
#define LISTA_H

using namespace std;


template <class T>
struct nodo {T Dato;
             nodo<T> * sig;};

template <class T>
class lista{nodo <T> *cab;
			int tam;
			
	public: lista(){cab=NULL; tam=0;}
			void mostrar_lista();
	        int getTam(){return tam;}
			bool lista_vacia();
			void insertar(T Dato, int pos);
			void insertar_final(T Dato);
			void insertar_inicio(T Dato);
			bool borrar(int pos);
			T buscar (int pos);
			bool modificar(T infoNueva,int pos);	
};


// Función para mostrar la lista 
template <class T>
void lista<T>::mostrar_lista(){
    if(lista_vacia()==1){
        std::cout<<"La lista no tiene informacion."<<std::endl;
    } else {
        std::cout<<"La informacion de la lista es: "<<std::endl;
        nodo <T> *aux;
        aux = cab;
        int pos = 0;
        while(aux!=NULL && pos<=tam){
            std::cout<<"Info "<<pos<<": "<<aux->Dato<<std::endl;
            aux = aux -> sig;
            pos++;
        }
    }
}


// Función para verificar si la lista está vacía
template <class T>
bool lista<T>::lista_vacia(){
	if(tam==0 || cab==NULL){
        return true;
    }
    return false;
}


// Función para insertar un nodo al inicio de la lista
template <class T>
void lista<T>::insertar_inicio(T Dato){
    nodo  <T> *nuevo;
    nuevo = new nodo<T>;
    nuevo -> Dato = Dato;
    nuevo -> sig = cab;
    cab=nuevo;
    tam++;
}

// Función para insertar un nodo al final de la lista

template <class T>
void lista<T>::insertar_final(T Dato){
    nodo<T> *nuevo, *aux;
    nuevo = new nodo<T>;
    nuevo -> Dato = Dato;
    nuevo -> sig = NULL;
    if(cab==NULL){
        cab = nuevo;
    } else {
        aux = cab;
        while(aux->sig!=NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
    tam++;
}

// Función para insertar un nodo en una posición específica de la lista
template <class T>
void lista<T>::insertar(T Dato, int pos){
    if(pos>tam){
        insertar_final(Dato);
    } else if(pos==0){
        insertar_inicio(Dato);
    } else {
        nodo<T> *nuevo, *aux;
        nuevo = new nodo<T>;
        nuevo -> Dato = Dato;
        aux = cab;
        int p=1;
        while(p<pos && aux!=NULL){
            aux = aux -> sig;
            p++;
        }
        nuevo -> sig = aux -> sig;
        aux -> sig = nuevo;
        tam++;
    }
}

// Función para borrar un nodo de una posición específica de la lista
template <class T>
bool lista<T>::borrar(int pos){
    if(pos>=tam || pos<0){
        return false;
    } else {
        nodo<T> *aux, *borrar;
        if(pos==0){
            borrar = cab;
            cab = cab->sig;
        } else {
            aux = cab;
            int p=1;
            while(p<pos && aux->sig!=NULL){
                aux = aux->sig;
                p++;
            }
            borrar = aux->sig;
            aux->sig = borrar->sig;
        }
        delete borrar;
        tam--;
        return true;
    }
}

// Función para buscar el valor de un nodo en una posición específica de la lista
template <class T>
T lista<T>::buscar(int pos){
	if(pos>=tam || cab==NULL){
        return T();
    } else {
    nodo <T> *aux;
    aux = cab;
    int p=1;
    while(p<pos && aux!=NULL){
        aux = aux->sig;
        p++;
    }
    return aux->Dato;
	}
}

// Función para modificar el valor de un nodo en una posición específica de la lista
template <class T>
bool lista<T>::modificar(T infoNueva, int pos){
    if(pos>=tam || cab==NULL){
        return false;
    } else {
        nodo <T> *aux;
        aux = cab;
        int p=0;
        while(p<pos && aux!=NULL){
            aux = aux -> sig;
            p++;
        }
        aux -> Dato = infoNueva;
        return true;
    }
}

#endif