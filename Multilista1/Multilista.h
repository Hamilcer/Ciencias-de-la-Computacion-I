#include <iostream>

#ifndef Multilista_h
#define Multilista_h

using namespace std;

struct P
{
	string nombre;
	string carrera;
	string actividad;
	long int codigo;

	// Apuntadores
	int sigNombre;
	int sigCarrera;
	int sigActividad;
	int sigCodigo;
};

struct Cabeceras
{
	string nLista; // nombre de la lista
	int pos;	   // posición de la cabeza
};

class Multilista1
{
	P *Multi;
	Cabeceras *cab; // Es el arreglo de cabeceras
	int fin;
	int numListas;

public:
	Multilista1(int numElementos, int numListas)
	{
		Multi = new P[numElementos + 1];
		cab = new Cabeceras[numListas]; // numListas cuantas cabeceras de lista vamos a tener
		fin = 0;
		this->numListas = numListas;

		// Inicializar las cabeceras
		cab[0] = {"nombre", 0};
		cab[1] = {"sistemas", 0};
		cab[2] = {"industrial", 0};
		cab[3] = {"electrica", 0};
		cab[4] = {"catastral", 0};
		cab[5] = {"danza", 0};
		cab[6] = {"natacion", 0};
		cab[7] = {"beisbol", 0};
		cab[8] = {"basquet", 0};
		cab[9] = {"codigo", 0};
	}

	bool multilista_vacia();
	void insertar(P nuevo);

	void imprimir();
	void imprimirCod();

	//~Multilista1();
};

// funcion para verificar si esta vacia
bool Multilista1::multilista_vacia()
{
	if (fin == 0)
	{
		return true;
	}
	return false;
}

// funcion para insertar a la multilista
void Multilista1::insertar(P nuevo)
{
	fin++;
	//  nombres por orden alfabetico
	if (fin == 1)
	{
		cab[0].pos = fin;
		nuevo.sigNombre = 0;
	}
	else
	{

		int i = cab[0].pos;
		int anterior = 0;
		while (Multi[i].sigNombre != 0 && nuevo.nombre > Multi[i].nombre)
		{
			anterior = i;
			i = Multi[i].sigNombre;
		}

		if (i == cab[0].pos) // significa que es el primero
		{
			nuevo.sigNombre = cab[0].pos;
			cab[0].pos = fin;
		}
		else if (nuevo.nombre > Multi[i].nombre) // significa que es el ultimo
		{
			Multi[i].sigNombre = fin;
			nuevo.sigNombre = 0;
		}
		else // significa que esta intermedio
		{
			nuevo.sigNombre = Multi[anterior].sigNombre;
			Multi[anterior].sigNombre = fin;
		}
	}

	// Carrera, se agrega al final
	int posCabCarrera; // elegir a cual carrera corresponde
	for (int j = 0; j < numListas; j++)
	{
		if (cab[j].nLista == nuevo.carrera)
		{
			posCabCarrera = j;
		}
	}
	if (cab[posCabCarrera].pos == 0) // primero en insertar
	{
		cab[posCabCarrera].pos = fin;
		nuevo.sigCarrera = 0;
	}
	else
	{
		int i = cab[posCabCarrera].pos;
		while (Multi[i].sigCarrera != 0)
		{
			i = Multi[i].sigCarrera;
		}
		Multi[i].sigCarrera = fin;
		nuevo.sigCarrera = 0;
	}

	// actividad, se agrega al inicio
	int posCabActividad; // elegir a cual actividad corresponde
	for (int j = 0; j < numListas; j++)
	{
		if (cab[j].nLista == nuevo.actividad)
		{
			posCabActividad = j;
		}
	}
	if (cab[posCabActividad].pos == 0) // primero en insertar
	{
		cab[posCabActividad].pos = fin;
		nuevo.sigActividad = 0;
	}
	else
	{
		nuevo.sigActividad = cab[posCabActividad].pos;
		cab[posCabActividad].pos = fin;
	}

	// codigo, se agrega de mayor a menor 

	if (cab[9].pos == 0)
	{
		cab[9].pos = fin;
		nuevo.sigCodigo = 0;
	}
	else
	{
		int i = cab[9].pos;
		int anterior = 0;
		while (Multi[i].sigCodigo != 0 && Multi[i].codigo > nuevo.codigo)
		{
			anterior = i;
			i = Multi[i].sigCodigo;
		}
		if (Multi[i].codigo > nuevo.codigo)
		{
			Multi[i].sigCodigo = fin;
			nuevo.sigCodigo = 0;
		}
		else if (i == cab[9].pos)
		{
			nuevo.sigCodigo = cab[9].pos;
			cab[9].pos = fin;
		}
		else
		{
			nuevo.sigCodigo = i;
			Multi[anterior].sigCodigo = fin;
		}
	}
	Multi[fin] = nuevo;
}

void Multilista1::imprimirCod()
{
	int i = cab[0].pos;
	cout << "codigo:" << endl;

	cout << Multi[i].nombre;
}

void Multilista1::imprimir()

{
	// nombres

	cout << endl
		 << "nombres:" << endl;
	int i = cab[0].pos;
	while (Multi[i].sigNombre != 0)
	{
		cout << Multi[i].nombre << " ";
		i = Multi[i].sigNombre;
	}
	cout << Multi[i].nombre << endl;

	// carreras
	i = cab[1].pos;
	cout << endl
		 << "sistemas:" << endl;
	while (Multi[i].sigCarrera != 0)
	{
		cout << Multi[i].nombre << " ";
		i = Multi[i].sigCarrera;
	}
	cout << Multi[i].nombre << endl;

	i = cab[2].pos;
	cout << endl
		 << "industrial:" << endl;
	while (Multi[i].sigCarrera != 0)
	{
		cout << Multi[i].nombre << " ";
		i = Multi[i].sigCarrera;
	}
	cout << Multi[i].nombre << endl;

	i = cab[3].pos;
	cout << endl
		 << "electrica:" << endl;
	while (Multi[i].sigCarrera != 0)
	{
		cout << Multi[i].nombre << " ";
		i = Multi[i].sigCarrera;
	}
	cout << Multi[i].nombre << endl;

	i = cab[4].pos;
	cout << endl
		 << "catastral:" << endl;
	while (Multi[i].sigCarrera != 0)
	{
		cout << Multi[i].nombre << " ";
		i = Multi[i].sigCarrera;
	}
	cout << Multi[i].nombre << endl;

	// actividad
	i = cab[5].pos;
	cout << endl
		 << "danza:" << endl;
	while (Multi[i].sigActividad != 0)
	{
		cout << Multi[i].nombre << " ";
		i = Multi[i].sigActividad;
	}
	cout << Multi[i].nombre << endl;

	i = cab[6].pos;
	cout << endl
		 << "natacion:" << endl;
	while (Multi[i].sigActividad != 0)
	{
		cout << Multi[i].nombre << " ";
		i = Multi[i].sigActividad;
	}
	cout << Multi[i].nombre << endl;

	i = cab[7].pos;
	cout << endl
		 << "beisbol:" << endl;
	while (Multi[i].sigActividad != 0)
	{
		cout << Multi[i].nombre << " ";
		i = Multi[i].sigActividad;
	}
	cout << Multi[i].nombre << endl;

	i = cab[8].pos;
	cout << endl
		 << "basquet:" << endl;
	while (Multi[i].sigActividad != 0)
	{
		cout << Multi[i].nombre << " ";
		i = Multi[i].sigActividad;
	}
	cout << Multi[i].nombre << endl;

	i = cab[9].pos;
	cout << endl
		 << "codigo:" << endl;
	while (Multi[i].sigCodigo != 0)
	{
		cout << Multi[i].nombre << " " << Multi[i].codigo << endl;
		i = Multi[i].sigCodigo;
	}
	cout << Multi[i].nombre << " " << Multi[i].codigo << endl;
}
#endif