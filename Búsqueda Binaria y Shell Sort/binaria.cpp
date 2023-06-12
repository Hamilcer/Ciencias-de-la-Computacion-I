#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <ctime>
#include <windows.h>

using namespace std;

int binarySearch(int arr[], int n, int x)
{
    int left = 1, right = n;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        if (arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main(int argc, char **argv)
{
	/* 
		Se ejecuta el algoritmo de busqueda binaria 
		desde 10 hasta 200 con paso de 10 en 10
	*/
	for (int i = 10; i<=200; i+=10)
	{
		int n = i;
	    int a[n];
	    
	    // Este ciclo crea un arreglo ordenado de tama�o n
	    for(int j = 1; j<=n; j++)
	    {
	    	a[j]=j;
		}
	
	
	    LARGE_INTEGER start, end, freq;
	    double tiempo;
	
	    QueryPerformanceFrequency(&freq); 
	    QueryPerformanceCounter(&start); 
	    
	    binarySearch(a, n, n+1);
		
		QueryPerformanceCounter(&end); 
	    tiempo = ((double) (end.QuadPart - start.QuadPart) / (double) freq.QuadPart) * 1000000.0;
	
	    cout << tiempo << endl;
	    
	}
    return 0;
}

