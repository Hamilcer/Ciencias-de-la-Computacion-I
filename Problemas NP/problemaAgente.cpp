#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>         
#include <windows.h>
#include <unistd.h> 
#include <fstream> // Biblioteca para manejar archivos

using namespace std;

int N = 1000; // N�mero de ciudades
int **dist; // Matriz de distancias

// Funci�n para calcular la distancia entre dos ciudades
int distance(int x1, int y1, int x2, int y2) {
    return round(sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}

// Funci�n para calcular la distancia total de una ruta
int route_distance(int route[]) {
    int d = 0;
    for (int i = 0; i < N - 1; i++) {
        d += dist[route[i]][route[i+1]];
    }
    d += dist[route[N-1]][route[0]];
    return d;
}

int main() {
	ofstream archivo("datos.txt", ios::app); // Abrir el archivo "datos.txt" para escritura
  
	srand(time(NULL));
    if (archivo.is_open())  // Comprobar si se abri� correctamente el archivo
    {
    	for(int nCiudades = 1; nCiudades <= 1000; nCiudades++)
		{ 
			LARGE_INTEGER start, end, freq;
		    double tiempo;
		
		    QueryPerformanceFrequency(&freq); // Obtiene la frecuencia del contador de rendimiento
		    QueryPerformanceCounter(&start); // Obtiene el contador de rendimiento en el inicio de la secci�n de c�digo
	
			
			N = nCiudades;
			dist = new int*[N];
			for(int i = 0; i<N; i++){
				dist[i] = new int[N];
			}
	    
			int x[N]; // Coordenadas X de las ciudades
		    int y[N]; // Coordenadas Y de las ciudades
		
			for(int j=0; j<N; j++)
			{
				x[j]=1+rand()%N; // genera numeros aleatorios entre 1  y n
				y[j]=1+rand()%N;
			}
		
		
		
		
		    // Calcular la matriz de distancias
		    for (int i = 0; i < N; i++) {
		        for (int j = 0; j < N; j++) {
		            dist[i][j] = distance(x[i], y[i], x[j], y[j]);
		        }
		    }
		
		    int route[N];
		    for (int i = 0; i < N; i++) {
		        route[i] = i;
		    }
		
		    int best_distance = route_distance(route);
		    int best_route[N];
		    copy(route, route + N, best_route);
		
		    while (next_permutation(route, route + N)) {
		        int d = route_distance(route);
		        if (d < best_distance) {
		            best_distance = d;
		            copy(route, route + N, best_route);
		        }
		    }
	
			
			for(int i = 0; i<N; i++){
				delete [] dist[i];
			}
			delete []dist;
			
			QueryPerformanceCounter(&end); // Obtiene el contador de rendimiento en el fin de la secci�n de c�digo
		
		    tiempo = ((double) (end.QuadPart - start.QuadPart) / (double) freq.QuadPart) * 1000000.0; // Convierte a microsegundos
		
		
		    cout << endl<< "Numero de ciudades: " << nCiudades<< endl;
		
		    cout << "La ruta m�s corta es: ";
		    
		    for (int i = 0; i < N; i++) {
		        cout << best_route[i] + 1 << " ";
		    }
		    
		    cout << endl << "La distancia total es: " << best_distance << endl;
		    
		    cout << "Tiempo de ejecuci�n: " << tiempo << " microsegundos" << endl;
		    
  			sleep(1);
		    archivo << "Tiempo de ejecuci�n: " << tiempo << " microsegundos" << endl; // Escribir informaci�n en el archivo
		}
	} else {
	    cout << "No se pudo abrir el archivo." << endl;
	}
    
    return 0;
}
