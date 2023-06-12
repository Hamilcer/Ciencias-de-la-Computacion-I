#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

//Llenar Arreglo ordenado de mayor a menor
void llenarArreglo(int a[], int N){
    for(int i=0; i<N; i++){
		a[i]=rand() % 99999;
    }
}

void imprimirArreglo(int a[], int N){
    for(int i=0; i<N; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}


void quickSort(int a[], int izq, int der) {
    int i, j, v;
    if (der > izq) {
        v = a[der];
        i = izq -1;
        j = der;
        for (;;) {
            while (a[++i] < v);
            while (a[--j] > v && j >= 0);
            if(i>=j) {
                break;
            }
            swap(a[i], a[j]);
        }
        swap(a[i], a[der]);
        quickSort(a, izq, i-1);
        quickSort(a, i+1, der);
    }
}

int main(){
	int N;
	srand(time(NULL));
	
	for(N=10; N<=200; N=N+10){
		int *a = new int[N];
	
		llenarArreglo(a, N);
		//imprimirArreglo(a, N);
		
		LARGE_INTEGER start, end, freq;
	    double tiempo;
	
	    QueryPerformanceFrequency(&freq); 
	    QueryPerformanceCounter(&start); 
	    
	    // Se toma solo el tiempo del algoritmo en mirosegundos
		quickSort(a, 0, N-1);
		
		QueryPerformanceCounter(&end); 
	    tiempo = ((double) (end.QuadPart - start.QuadPart) / (double) freq.QuadPart) * 1000000.0;
	
	    cout << tiempo << endl;
	    
		//Descomentar si desea ver el arreglo ordenado
		//imprimirArreglo(a, N);
		
		delete []a;
	}
    return 0;
}
