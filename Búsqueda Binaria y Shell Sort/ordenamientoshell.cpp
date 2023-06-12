#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <ctime>
#include <windows.h>

using namespace std;


void ordenshell(int a[], int N)
{
    int i, j, h;
    int v;

    for (h = 0; h <= N / 9; h = 3 * h + 1);
    for (; h > 0; h /= 3)
        for (i = h; i < N; i += 1)
        {
            v = a[i];
            j = i;
            while (j > h - 1 && a[j - h] > v)
            {
                a[j] = a[j - h];
                j -= h;
            }
            a[j] = v;
        }
}

int main(int argc, char **argv)
{
	/* 
		Se ejecuta el algoritmo de busqueda binaria 
		desde 50 hasta 2000 con paso de 50 en 50
	*/
    for (int i = 50; i <= 2000; i += 50)
    {

        int N = i;
        int a[N - 1];


	    // Este ciclo crea un arreglo ordenado de mayor a menor de tama�o n
        for (int i = 0; i < N; i++)
        {
            a[i] = N - i;
        }

        LARGE_INTEGER start, end, freq;
	    double tiempo;
	
	    QueryPerformanceFrequency(&freq); 
	    QueryPerformanceCounter(&start); 
	    
        ordenshell(a, N);
        
        QueryPerformanceCounter(&end);

	    tiempo = ((double) (end.QuadPart - start.QuadPart) / (double) freq.QuadPart) * 1000000.0; 
	
	    cout << tiempo << endl;
    }
    return 0;
}

