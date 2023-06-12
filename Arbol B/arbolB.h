#ifndef ARBOLB_H
#define ARBOLB_H

#include <iostream>
using namespace std;

struct Nodo
{
	int *claves;
	Nodo **hijos;
	int Nclaves;
	bool hoja;
};

class arbolB
{
	Nodo *raiz;
	int d;

public:
	arbolB(int orden)
	{
		d = orden;
		raiz = crearNodo(true);
	}

	Nodo *crearNodo(bool hoja = false);
	Nodo *getRaiz();
	void dividirNodo(Nodo *actual, int i);
	void insertar(int calve);
	void insertarNoLleno(Nodo *x, int k);

	void imprimir(Nodo *x, int level = 0);
	void imprimirClaves(Nodo *x);
	void insertarClave(Nodo *x, int k, int pos);
	void insertarHijo(Nodo *padre, Nodo *insertado, int pos);
	Nodo *buscar(int k, Nodo *nodo = NULL);
	Nodo *buscarInsertar(int key, Nodo *nodo = NULL);
	Nodo *buscarPadre(int key, Nodo *nodoObjetivo, Nodo *nodo = NULL, Nodo *padre = NULL);
	Nodo *buscarAyudaHermano(int key, Nodo *nodo);
	void eliminar(int k, Nodo *x = NULL);
	void eliminarClave(Nodo *x, int pos);
};

Nodo *arbolB::getRaiz()
{
	return raiz;
}

Nodo *arbolB::crearNodo(bool hoja)
{
	Nodo *nuevo = new Nodo;
	nuevo->claves = new int[2 * d - 1];
	nuevo->hijos = new Nodo *[2 * d];
	nuevo->Nclaves = 0;
	nuevo->hoja = hoja;
	return nuevo;
}

void arbolB::dividirNodo(Nodo *x, int i)
{
	// y es un hijo completo de x para dividir
	Nodo *y = x->hijos[i];

	// crear un nodo nuevo y añadirlo a la lista de hijos de x
	Nodo *z = crearNodo(y->hoja);
	insertarHijo(x, z, i + 1);
	// x->hijos[i + 1] = z;

	// borrar
	// imprimirClaves(x);
	// inserta la clave de la mitad de y en x
	x->Nclaves++;
	insertarClave(x, y->claves[d - 1], i);

	// borrar
	// imprimirClaves(x);

	// dividir las claves de y, entre y & z
	for (int i = d; i < 2 * d - 1; i++)
	{
		z->claves[i - d] = y->claves[i];
		z->Nclaves++;
	}
	// Mirar si z tiene la mitad grande
	// imprimirClaves(z);
	////

	y->Nclaves = 0;
	for (int i = 0; i < d - 1; i++)
	{
		y->claves[i] = y->claves[i];
		y->Nclaves++;
	}

	// Mirar si y tiene la mitad pequeña
	// imprimirClaves(y);
	//////

	// si y no es una hoja, se reasignan los hijos de y, entre y & z
	if (!y->hoja)
	{
		for (int i = d; i < 2 * d; i++)
		{
			z->hijos[i - d] = y->hijos[i];
			// insertarHijo(z,y,i);
		}
		for (int i = 0; i < d - 1; i++)
		{
			y->hijos[i] = y->hijos[i];
		}
	}
}

void arbolB::insertar(int clave)
{
	Nodo *antiguaRaiz = raiz;

	bool nuevoNodo = false;
	if (buscarInsertar(clave) == NULL)
	{
		nuevoNodo = true;
	}

	if (raiz->Nclaves == 2 * d - 1 && nuevoNodo)
	{
		Nodo *nuevaRaiz = crearNodo();
		raiz = nuevaRaiz;
		nuevaRaiz->hijos[0] = antiguaRaiz;
		dividirNodo(nuevaRaiz, 0);
		insertarNoLleno(nuevaRaiz, clave);
	}
	else
	{
		insertarNoLleno(raiz, clave);
	}
	// imprimir(raiz);
}

void arbolB::insertarNoLleno(Nodo *x, int k)
{
	int i = x->Nclaves - 1;

	if (x->hoja)
	{
		while (i >= 0 && k < x->claves[i])
		{
			x->claves[i + 1] = x->claves[i];
			i--;
		}
		x->claves[i + 1] = k;
		x->Nclaves++;
		// imprimirClaves(x);
	}
	else
	{
		while (i >= 0 && k < x->claves[i])
		{
			i--;
		}
		i++;
		Nodo *prueba = buscarInsertar(k, x->hijos[i]);
		bool dividir = false;
		if (prueba == NULL) // si no hay espacio se divide
		{
			dividir = true;
		}
		else if (prueba->Nclaves == 2 * d - 1)
		{
			dividir = true;
		}

		if (x->hijos[i]->Nclaves == 2 * d - 1 && dividir)
		{
			dividirNodo(x, i);
			if (k > x->claves[i])
			{
				i++;
			}
		}
		insertarNoLleno(x->hijos[i], k);
	}
}

// Esta funcion permite insertar la clave en la pos adecuada
void arbolB::insertarClave(Nodo *x, int k, int pos)
{
	for (int i = x->Nclaves - 1; i > pos; i--)
	{
		x->claves[i] = x->claves[i - 1];
	}
	if (x->Nclaves == 1)
	{
		x->claves[1] = x->claves[0];
	}
	x->claves[pos] = k;
}

// Esta funcion permite insertar el hijo en la pos adecuada
void arbolB::insertarHijo(Nodo *padre, Nodo *insertado, int pos)
{
	for (int i = 2 * d; i > pos; i--)
	{
		padre->hijos[i] = padre->hijos[i - 1];
	}
	padre->hijos[pos] = insertado;
}

void arbolB::imprimir(Nodo *x, int level)
{
	cout << "Nivel " << level << ": ";
	for (int i = 0; i < x->Nclaves; i++)
	{
		cout << x->claves[i] << " ";
	}
	cout << endl;
	level++;

	if (!x->hoja)
	{
		for (int i = 0; i < x->Nclaves + 1; i++)
		{
			imprimir(x->hijos[i], level);
		}
	}
}

void arbolB::imprimirClaves(Nodo *x)
{
	for (int i = 0; i < x->Nclaves; i++)
	{
		cout << x->claves[i] << " ";
	}
	cout << endl;
}

Nodo *arbolB::buscar(int key, Nodo *nodo)
{
	if (nodo == NULL)
	{
		nodo = getRaiz();
	}
	int i = 0;
	while (i < nodo->Nclaves && key > nodo->claves[i])
	{
		i++;
	}
	if (i < nodo->Nclaves && key == nodo->claves[i])
	{
		return nodo;
	}
	else if (nodo->hoja)
	{
		return NULL;
	}
	else
	{
		return buscar(key, nodo->hijos[i]);
	}
}

// Esta funcion se utiliza para buscar cual debe ser el nodo en donde se debe insertar
Nodo *arbolB::buscarInsertar(int key, Nodo *nodo)
{
	if (nodo == NULL)
	{
		nodo = getRaiz();
	}
	int i = 0;
	while (i < nodo->Nclaves && key > nodo->claves[i])
	{
		i++;
	}
	if (nodo->Nclaves < 2 * d - 1)
	{
		return nodo;
	}
	else if (!nodo->hoja)
	{
		return buscarInsertar(key, nodo->hijos[i]);
	}
	else
	{
		return NULL;
	}
}

Nodo *arbolB::buscarPadre(int key, Nodo *nodoObjetivo, Nodo *nodo, Nodo *padre)
{
	if (nodo == NULL)
	{
		nodo = getRaiz();
	}
	int i = 0;
	while (i < nodo->Nclaves && key > nodo->claves[i])
	{
		i++;
	}

	int j = 0;
	while (padre != NULL && j < padre->Nclaves && padre->hijos[j] != nodoObjetivo) // saber si el nodo que se busca es el hijo
	{
		j++;
	}
	bool esHijo = false;
	if (padre != NULL && padre->hijos[j] == nodoObjetivo)
	{
		esHijo = true;
	}

	if (i <= nodo->Nclaves && key == nodo->claves[i] && esHijo)
	{
		return padre;
	}
	else if (esHijo)
	{
		return padre;
	}
	else if (nodo->hoja)
	{
		return NULL;
	}
	else
	{
		padre = nodo;
		return buscarPadre(key, nodoObjetivo, nodo->hijos[i], padre);
	}
}

Nodo *arbolB::buscarAyudaHermano(int key, Nodo *nodo)
{
	Nodo *padre = buscarPadre(key, nodo);
	// solo busca ayuda hermano der
	if (padre->hijos[0] == nodo)
	{
		if (padre->hijos[1]->Nclaves > d - 1)
		{
			return padre->hijos[1];
		}
	}
	else if (padre->hijos[padre->Nclaves] == nodo) // solo buscar ayuda izq
	{
		if (padre->hijos[padre->Nclaves - 1]->Nclaves > d - 1)
		{
			return padre->hijos[padre->Nclaves - 1];
		}
	}
	else // tiene hermano der e izq
	{
		int i = 0;
		while (padre->hijos[i] != nodo) // buscar el nodo
		{
			i++;
		}
		if (padre->hijos[i - 1]->Nclaves > d - 1)
		{
			return padre->hijos[i - 1];
		}
		if (padre->hijos[i + 1]->Nclaves > d - 1)
		{
			return padre->hijos[i + 1];
		}
	}
	return NULL;
}

void arbolB::eliminar(int k, Nodo *x)
{

	Nodo *nodoClave;
	if (x != NULL)
	{
		nodoClave = x;
	}
	else
	{
		nodoClave = buscar(k);
	}

	Nodo *padre = buscarPadre(k, nodoClave);

	if (padre == NULL && nodoClave->hoja) // significa que se baja un nivel del arbol
	{
		raiz = nodoClave->hijos[0];
		return;
	}

	Nodo *ayudaHermano = NULL;
	if (padre != NULL)
	{

		ayudaHermano = buscarAyudaHermano(k, nodoClave); // para caso 2.
	}

	if (!nodoClave->hoja) // case 3
	{
		int i = 0;
		while (nodoClave->claves[i] != k) // buscar la posicion clave a reemplaza
		{
			i++;
		}

		int j = 0;
		while (j < nodoClave->Nclaves + 1 && nodoClave->hijos[j]->claves[0] < k) // buscar pos hijo que va a reemplazar
		{
			j++;
		}
		nodoClave->claves[i] = nodoClave->hijos[j]->claves[0];
		eliminar(nodoClave->hijos[j]->claves[0], nodoClave->hijos[j]);
	}
	else if (nodoClave->Nclaves >= d && nodoClave->hoja) // caso 1 BORRADO DE UNA CALVE EN HOJA CON MAS DE D CLAVES
	{
		int i = 0;
		while (nodoClave->claves[i] != k) // buscar clave a eliminar
		{
			i++;
		}
		eliminarClave(nodoClave, i);
		return;
	}
	else if (nodoClave->Nclaves == d - 1 && ayudaHermano != NULL) // caso 2.1
	{
		int i = 0;
		while (padre->hijos[i] != nodoClave) // buscar la posicion nodo
		{
			i++;
		}

		int j = 0;
		while (j < padre->Nclaves && padre->claves[j] <= nodoClave->claves[0]) // buscar posicion clave padre
		{
			j++;
		}
		if (j >= padre->Nclaves || (i > 0 && padre->hijos[i - 1] == ayudaHermano))
		{
			j--;
		}

		int m = 0;
		while (m < nodoClave->Nclaves && padre->claves[j] <= nodoClave->claves[m]) // buscar posicion donde debe ir la clave del padre
		{
			m++;
		}
		m--;
		if (m < 0)
		{
			m++;
		}

		if (i > 0 && padre->hijos[i - 1] == ayudaHermano) // El hermano es izq
		{
			insertarClave(nodoClave, padre->claves[j], m);
			padre->claves[j] = ayudaHermano->claves[ayudaHermano->Nclaves - 1];
		}
		else if (i < padre->Nclaves + 1 && padre->hijos[i + 1] == ayudaHermano) // El hermano es der
		{
			insertarClave(nodoClave, padre->claves[j], m);
			padre->claves[j] = ayudaHermano->claves[0];
		}
		int h = 0;
		while (ayudaHermano->claves[h] != padre->claves[j]) // Buscar la clave que subio al padre
		{
			h++;
		}

		eliminarClave(ayudaHermano, h);

		if (!ayudaHermano->hoja) // Esto significa que el primer hijo de quien ayuda pasa a ser hijo del nodoClave
		{
			nodoClave->hijos[nodoClave->Nclaves] = ayudaHermano->hijos[0];
			for (int i = 0; i < ayudaHermano->Nclaves + 1; i++)
			{
				ayudaHermano->hijos[i] = ayudaHermano->hijos[i + 1];
			}
		}

		return;
	}
	else if (ayudaHermano == NULL) // caso 2.2, si esto pasa es porque amos hermanos tienen d-1, de otro modo entra a caso2.1
	{
		/*
			cuando el hermano no puede ayudar se coge el de la DERECHA
		*/
		int i = 0;
		while (i < padre->Nclaves && padre->claves[i] < k) // buscar clave padre mas cercana a k
		{
			i++;
		}
		if (i >= padre->Nclaves)
		{
			i--;
		}
		int claveMasCercana = i;

		int j = 0;
		while (nodoClave->claves[j] != k) // buscar posicion clave en el nodo
		{
			j++;
		}

		int m = 0;
		while (padre->hijos[m] != nodoClave) // buscar la posicion nodo
		{
			m++;
		}

		if (nodoClave->claves[j] < padre->claves[i]) // Se une con en el la derecha
		{
			nodoClave->claves[j] = padre->claves[i]; // se "une" el nodo con la clave que baja
			for (int i = 0; i < padre->hijos[m + 1]->Nclaves; i++)
			{
				insertarClave(nodoClave, padre->hijos[m + 1]->claves[i], nodoClave->Nclaves++);
			}

			if (!padre->hijos[m + 1]->hoja) // significa que se tiene que unir los hijos con el de la der
			{
				for (int i = 0; i < padre->hijos[m + 1]->Nclaves + 1; i++)
				{
					nodoClave->hijos[nodoClave->Nclaves - 1 + i] = padre->hijos[m + 1]->hijos[i];
				}
			}

			for (int i = m + 1; i < padre->Nclaves; i++)
			{
				padre->hijos[i] = padre->hijos[i + 1];
			}
			if (padre->Nclaves - 1 < d - 1)
			{
				padre->hoja = true;
				eliminar(padre->claves[i], padre);
				padre->hoja = false;
			}
			else
			{
				eliminarClave(padre, claveMasCercana);
			}
		}
		else // se une con el de la izquierda
		{
			nodoClave->claves[j] = padre->claves[i]; // se "une" el nodo con la clave que baja
			for (int i = padre->hijos[m - 1]->Nclaves - 1; i >= 0; i--)
			{
				insertarClave(nodoClave, padre->hijos[m - 1]->claves[i], 0);
				nodoClave->Nclaves++;
			}

			if (!padre->hijos[m - 1]->hoja) // significa que se tiene que unir los hijos con el de la izq
			{
				Nodo *aux = padre->hijos[m - 1];
				for (int i = 0; i < nodoClave->Nclaves + 1; i++)
				{
					aux->hijos[aux->Nclaves + 1 + i] = nodoClave->hijos[i];
				}
				nodoClave->hijos = aux->hijos;
			}

			for (int i = m - 1; i < padre->Nclaves; i++) // se acomodan los hijos del padre
			{
				padre->hijos[i] = padre->hijos[i + 1];
			}
			if (padre->Nclaves - 1 < d - 1)
			{
				padre->hoja = true;
				eliminar(padre->claves[i], padre);
				padre->hoja = false;
			}
			else
			{
				padre->Nclaves--;
			}
		}

	}
}

void arbolB::eliminarClave(Nodo *x, int pos)
{
	for (int i = pos; i < x->Nclaves - 1; i++)
	{
		x->claves[i] = x->claves[i + 1];
	}
	x->Nclaves--;
}

#endif