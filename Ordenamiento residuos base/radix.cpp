#include <iostream>
#include <windows.h>

using namespace std;

void llenarArreglo(int a[], int N){
    for(int i=0; i<N; i++){
        a[i] = (N-i);
    }
}

void imprimirArreglo(int a[], int N){
    for(int i=0; i<N; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}


int max(int a[], int N){
    int max = a[0];
    for(int i=1; i<N; i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    return    max;
}

void contadorSort(int a[], int N, int div){
    int output[N];
    int cont[10] = {0};
    
    for(int i=0; i<N; i++){
        cont[(a[i]/div)%10]++;
    }
    for(int i=1; i<10; i++){
        cont[i] += cont[i-1];
    }
    for(int i=N-1; i>=0; i--){
        output[cont[(a[i]/div)%10]-1]=a[i];
        cont[(a[i]/div)%10]--;
    }
    for(int i=0; i<N; i++){
        a[i]=output[i];
    }
}
void radixSort(int a[], int N){
    int m = max(a, N);
    for(int div=1; m/div>0; div*=10){
        contadorSort(a, N, div);
    }
}

int main(){	
	for(int n=0; n<=200; n+=5){
		
		int *a = new int[n];
		
		llenarArreglo(a, n);
		
		LARGE_INTEGER start, end, freq;
	    double tiempo;
	
	    QueryPerformanceFrequency(&freq); 
	    QueryPerformanceCounter(&start); 
	    
	    // Se toma solo el tiempo del algoritmo
		radixSort(a, n);
		
		QueryPerformanceCounter(&end); 
	    tiempo = ((double) (end.QuadPart - start.QuadPart) / (double) freq.QuadPart) * 1000000.0;
	
	    cout << tiempo << endl;
	    
	    
		//imprimirArreglo(a, n); // Descomentar si desea ver el arreglo ordenado
		
		delete []a;
	}
    return 0;
}
