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

//MergeSort
void mergeSortList(int list[], int start1, int end1, int start2, int end2) {
    int finalStart = start1;
    int finalEnd = end2;
    int indexC = 0;
    int result[(end2 - start1) + 1];
    while ((start1 <= end1) && (start2 <= end2)) {
        if (list[start1] < list[start2]) {
            result[indexC] = list[start1];
            start1++;
        } else {
            result[indexC] = list[start2];
            start2++;
        }
        indexC++;
    }
    //Desplaza la secci�n restante de la lista.
    if (start1 <= end1) {
        for (int i = start1; i <= end1; i++){
            result[indexC] = list[i];
            indexC++;
        }
    } else {
        for (int i = start2; i <= end2; i++){
            result[indexC] = list[i];
            indexC++;
        }
    }
    
    //Agrega el resultado a la lista.
    indexC = 0;
    for (int i = finalStart; i <= finalEnd; i++){
        list[i] = result[indexC];
        indexC++;
    }
}

void mergeSort(int vector[], int first, int last){
    int middle;
    if (first < last){
        middle = (first + last ) / 2;
        mergeSort(vector, first, middle);
        mergeSort(vector, middle + 1, last);
        mergeSortList(vector, first, middle, middle + 1, last);
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
		mergeSort(a, 0, N-1);
		QueryPerformanceCounter(&end); 
	    tiempo = ((double) (end.QuadPart - start.QuadPart) / (double) freq.QuadPart) * 1000000.0;
	
	    cout << tiempo << endl;
		
		//Descomentar si desea ver el arreglo ordenado
		//imprimirArreglo(a, N);
		
		delete []a;
	}
    return 0;
}
