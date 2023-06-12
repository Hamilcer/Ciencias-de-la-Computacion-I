#include <iostream>
#include <windows.h>

using namespace std;

unsigned bits(int x, int k, int j)
{
    return (x >> k) & ~(~0 << j);
}

void cambioresiduos(int a[], int izq, int der, int b)
{
    int i, j;
    if (der > izq && b >= 0)
    {
        i = izq;
        j = der;
        while (j != i)
        {
            while (!bits(a[i], b, 1) && i < j)
                i++;
            while (bits(a[j], b, 1) && j > i)
                j--;
            swap(a[i], a[j]);
        }
        if (!bits(a[i], b, 1))
            j++;
        cambioresiduos(a, izq, j - 1, b - 1);
        cambioresiduos(a, j, der, b - 1);
    }
}

void llenar(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = (n - i);
    }
}

void imprimir(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main(void)
{
    int n, k = 0, izq, der;

    for (int i = 5; i <= 200; i = i + 5)
    {
        n = i;
        int *a = new int[n];
        // Se llena el arreglo de tama�o n ordenado de mayor a menor
        llenar(a, n);
        izq = 0;
        der = n - 1;


		LARGE_INTEGER start, end, freq;
	    double tiempo;
	
	    QueryPerformanceFrequency(&freq); 
	    QueryPerformanceCounter(&start); 
	    
	    // Se toma solo el tiempo del algoritmo
        cambioresiduos(a, izq, der, n);
        
        
		QueryPerformanceCounter(&end); 
	    tiempo = ((double) (end.QuadPart - start.QuadPart) / (double) freq.QuadPart) * 1000000.0;
	
	    cout << tiempo << endl;
	    
		
		//imprimir(a, n); // Descomentar si desea ver el arreglo ordenado
	
		delete []a;
    }

    return 0;
}

