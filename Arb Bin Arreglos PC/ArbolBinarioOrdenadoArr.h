#include "Pila.h"
#include "Cola.h"
#include <iostream>

#ifndef ARBOLBINARIO_h
#define ARBOLBINARIO_h

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

struct nodo
{
    int clave;
    int izq, der;
};

class arbinordArreglo
{
    nodo *arbol;
    cola *listodern, *listPreorden, *listPosorden;

public:
    arbinordArreglo(int tam);
    bool insertar(int dato);
    int buscarPadre(int dato);
    bool eliminar(int dato);
    int buscar_nodo(int dato);
    int getRaiz() { return arbol[0].izq; }
    cola inOrden();
    cola preOrden();
    cola posOrden();
    cola niveles();
    ~arbinordArreglo() { delete arbol; };

    void imprimir(int tam);
};

arbinordArreglo::arbinordArreglo(int tam)
{
    tam = tam + 1;
    arbol = new nodo[tam + 1];

    for (int i = 0; i < tam; i++)
    {
        arbol[i].clave = NULL;
        arbol[i].izq = NULL;
        arbol[i].der = i + 1;
    }
    arbol[0].izq = 0;
    arbol[tam - 1].der = 0;
}

bool arbinordArreglo::insertar(int dato)
{
    int posLibre = arbol[0].der;

    // No inserta si no hay espacio
    if (posLibre == 0)
    {
        return false;
    }

    // arctualiza posLibre en control
    arbol[0].der = arbol[posLibre].der;

    // inserta dato
    arbol[posLibre].clave = dato;
    arbol[posLibre].der = 0;
    arbol[posLibre].izq = 0;

    bool flag = true;

    // posAux me va a ayudar a enlazar el dato
    int posAux = arbol[0].izq;
    // Enlazar el dato insertado
    while (flag)
    {
        // Si es el primero que se inserta
        if (arbol[0].izq == 0)
        {
            arbol[0].izq = 1;
            flag = false;
        }
        else
        {
            // mira si es mayor el dato
            if (dato > arbol[posAux].clave)
            {
                if (arbol[posAux].der == 0)
                {
                    arbol[posAux].der = posLibre;
                    flag = false;
                }
                posAux = arbol[posAux].der;
            }
            // mira si es menor el dato
            else
            {
                if (arbol[posAux].izq == 0)
                {
                    arbol[posAux].izq = posLibre;
                    flag = false;
                }
                posAux = arbol[posAux].izq;
            }
        }
    }

    return true;
}

void arbinordArreglo::imprimir(int tam)
{
    cout << endl;
    for (int i = 0; i < tam + 1; i++)
    {
        cout << i << " - " << arbol[i].clave << " " << arbol[i].izq << " " << arbol[i].der << endl;
    }
}

int arbinordArreglo::buscarPadre(int dato)
{
    bool flag = true;
    int posPadre = arbol[0].izq;

    while (flag)
    {
        if (dato == arbol[arbol[posPadre].izq].clave || dato == arbol[arbol[posPadre].der].clave)
        {
            flag = false;
            break;
        }
        if (dato > arbol[posPadre].clave)
        {
            posPadre = arbol[posPadre].der;
        }
        else
        {
            posPadre = arbol[posPadre].izq;
        }
    }

    return posPadre;
}

bool arbinordArreglo::eliminar(int dato)
{
    int posNodo = buscar_nodo(dato);

    // No existe el nodo
    if (buscar_nodo(dato) == -1)
    {
        return false;
    }

    // buscar el nodo padre
    int posPadre = buscarPadre(dato);

    // sin hijos
    if (arbol[posNodo].der == 0 && arbol[posNodo].izq == 0)
    {
        // Desconbecta padre de hijo
        if (arbol[arbol[posPadre].izq].clave == dato)
        {
            arbol[posPadre].izq = NULL;
        }
        else
        {
            arbol[posPadre].der = NULL;
        }

        // se elimina el dato
        arbol[posNodo].clave = NULL;

        // se actualiza los espacios libres
        arbol[posNodo].der = arbol[0].der;
        arbol[0].der = posNodo;
    }
    // con dos hijos
    else if (arbol[posNodo].der != 0 && arbol[posNodo].izq != 0)
    {
        int hijoR, padreR;
        padreR = posNodo;
        hijoR = arbol[padreR].der;
        while (arbol[hijoR].izq != 0)
        {
            padreR = hijoR;
            hijoR = arbol[padreR].izq;
        }

        arbol[padreR].izq = 0;
        if (arbol[hijoR].der != 0)
        {
            arbol[padreR].izq = arbol[hijoR].der;
        }

        arbol[hijoR].der = arbol[posNodo].der;
        arbol[hijoR].izq = arbol[posNodo].izq;

        arbol[posNodo].clave = 0;
        arbol[posNodo].izq = 0;
        arbol[posNodo].der = 0;

        // se actualiza los espacios libres
        arbol[posNodo].der = arbol[0].der;
        arbol[0].der = posNodo;

        if (arbol[posPadre].izq == posNodo)
        {
            arbol[posPadre].izq = hijoR;
        }
        else
        {
            arbol[posPadre].der = hijoR;
        }
    }
    // con un hijo
    else
    {
        // posicion hijo => izq:true - der:false
        bool hijoizq = (arbol[arbol[posPadre].izq].clave == dato) ? true : false;

        // posicion del nieto para ser reemplaza
        int posNieto = (arbol[posNodo].izq == 0) ? arbol[posNodo].der : arbol[posNodo].izq;

        // enlazar abuelo con nieto
        if (hijoizq)
        {
            arbol[posPadre].izq = posNieto;
        }
        else
        {
            arbol[posPadre].der = posNieto;
        }

        // se elimina el dato
        arbol[posNodo].clave = NULL;

        // eliminar posicion del hijo
        arbol[posNodo].der = NULL;
        arbol[posNodo].izq = NULL;

        // se actualiza los espacios libres
        arbol[posNodo].der = arbol[0].der;
        arbol[0].der = posNodo;
    }

    return true;
}

int arbinordArreglo::buscar_nodo(int dato)
{
    bool flag = true;
    int posAux = arbol[0].izq;

    while (flag)
    {
        if (dato == arbol[posAux].clave)
        {
            return posAux;
        }

        if (arbol[posAux].izq == 0 && arbol[posAux].der == 0)
        {
            flag = false;
            break;
        }

        if (dato > arbol[posAux].clave)
        {
            posAux = arbol[posAux].der;
        }
        else
        {
            posAux = arbol[posAux].izq;
        }
    }
    // si llego hasta aqui es que el nodo no esta
    return -1;
}

cola arbinordArreglo::inOrden()
{
    cola miCola;
    int pos = getRaiz();

    pila pila;
    while (!pila.pilaVacia() || pos != 0)
    {
        if (pos != 0)
        {
            pila.push(pos);
            pos = arbol[pos].izq;
        }
        else
        {
            pos = pila.pop();
            miCola.insertar(arbol[pos].clave);
            pos = arbol[pos].der;
        }
    }
    return miCola;
}

cola arbinordArreglo::preOrden()
{
    cola miCola;
    int pos = getRaiz();
    pila pila;

    pila.push(pos);

    while (!pila.pilaVacia())
    {
        pos = pila.pop();
        miCola.insertar(arbol[pos].clave);

        if (arbol[pos].der != 0)
        {
            pila.push(arbol[pos].der);
        }

        if (arbol[pos].izq != 0)
        {
            pila.push(arbol[pos].izq);
        }
    }
    return miCola;
}

cola arbinordArreglo::posOrden()
{
    int n = 0, pos = getRaiz();
    
    cola miCola;
    pila pila;

    while (!pila.pilaVacia() || pos != 0)
    {
        if (pos != 0)
        {
            pila.push(pos);
            pos = arbol[pos].izq;
        }
        else
        {
            int aux = pila.pop();
            pila.push(aux);
            if (arbol[aux].der != 0 && n != arbol[aux].der)
            {
                pos = arbol[aux].der;
            }
            else
            {
                miCola.insertar(arbol[aux].clave);
                n = pila.pop();
            }
        }
    }
    return miCola;
}

cola arbinordArreglo::niveles()
{
    cola miCola, aux;
    int pos = arbol[0].izq;
    aux.insertar(pos);

    while (!aux.colaVacia())
    {
        pos = aux.atender();
        miCola.insertar(arbol[pos].clave);

        if (arbol[pos].izq != 0)
        {
            aux.insertar(arbol[pos].izq);
        }
        if (arbol[pos].der != 0)
        {
            aux.insertar(arbol[pos].der);
        }
    }
    return miCola;
}

#endif
