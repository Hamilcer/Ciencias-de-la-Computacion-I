#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

int main()
{
	 

    int pesoObjetos;
    cout << "Introduzca la capacidad de la mochila: ";
    cin >> pesoObjetos;
    
    LARGE_INTEGER start, end, freq;
    double tiempo;

    QueryPerformanceFrequency(&freq); // Obtiene la frecuencia del contador de rendimiento
    QueryPerformanceCounter(&start); 
    
    // Inicializar semilla aleatoria
    srand(time(NULL));
    
    int cantObjetos = pesoObjetos * 50; 
    pesoObjetos = pesoObjetos + 1;

    int **A = new int*[cantObjetos+1]; // Asignar memoria din�mica
    for(int i=0; i<cantObjetos+1; i++) {
        A[i] = new int[pesoObjetos];
    }

    int *p = new int[cantObjetos+1];
    int *b = new int[cantObjetos+1];

    p[0] = 0;
    b[0] = 0;

    for (int q = 1; q < cantObjetos+1; ++q)
    {
        p[q] = rand() % pesoObjetos/2 + pesoObjetos/5; // Generar peso aleatorio 
    }
    for (int q = 1; q < cantObjetos+1; ++q)
    {
        b[q] = rand() % 20 + 1; // Generar beneficio aleatorio
    }

    for (int a = 0; a < pesoObjetos; a++)
    {
        A[0][a] = 0;
        if (a < cantObjetos)
        {
            A[a][0] = 0;
        }
    }

    for (int i = 1; i <= cantObjetos; ++i)
    {
        for (int j = 1; j <= pesoObjetos - 1; ++j)
        {
            if (j - p[i] < 0)
            {
                A[i][j] = A[i - 1][j];
            }
            else
            {
                A[i][j] = max(A[i - 1][j], A[i - 1][j - p[i]] + b[i]);
            }
        }
    }

    int may = -1, V = 0;
    for (int i = 0; i < cantObjetos+1; ++i)
    {
        for (int j = 0; j < pesoObjetos; ++j)
        {
            if (A[i][j] > may)
            {
                may = A[i][j];
                V = A[i][j];
            }
        }
    }
    
     QueryPerformanceCounter(&end); // Obtiene el contador de rendimiento en el fin de la secci�n de c�digo

    tiempo = ((double) (end.QuadPart - start.QuadPart) / (double) freq.QuadPart) * 1000000.0; // Convierte a microsegundos

    cout << "Tiempo de ejecuci�n: " << tiempo << " microsegundos" << endl;
    cout << "El mayor beneficio es: " << V << endl;

    // Imprimir elementos de la soluci�n
    int j = pesoObjetos - 1;
    for (int i = cantObjetos; i > 0; i--)
    {
        if (A[i][j] != A[i-1][j])
        {
            cout << "Elemento " << i << " - Peso: " << p[i] << " - Beneficio: " << b[i] << endl;
            j = j - p[i];
        }
    }

    // Liberar memoria din�mica
    for(int i=0; i<cantObjetos+1; i++) {
        delete[] A[i];
    }
    delete[] A;
    delete[] p;
    delete[] b;

    return 0;
}

