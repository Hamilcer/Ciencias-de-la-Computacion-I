#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <ctime>
#include <windows.h>

using namespace std;

void insercion(int a[], int N)
{
  int i, j;
  int v;
  for (i = 1; i < N; i++)
  {
    j = i;
    v = a[j];
    while (a[j - 1] > v && j > 0)
    {
      a[j] = a[j - 1];
      j--;
    }
    a[j] = v;
  }
}

int main(int argc, char **argv)
{
  int N;
  cout << "ingrese el valor de N: ";
  cin >> N;
  int a[N - 1];

  /*
  Se crea un arreglo con tamaño N
  ordebado de mayor a menor
  es decir: [N, N-1, N-2 ... 1]
  */
  for (int i = 0; i < N; i++)
  {
    a[i] = N - i;
  }

  // Se crean las variables necesarias para medir el tiempo
  LARGE_INTEGER start, end, freq;
  double tiempo;

  // Se mide el tiempo de ejecucion del algoritmo
  QueryPerformanceFrequency(&freq);
  QueryPerformanceCounter(&start);
  insercion(a, N);
  QueryPerformanceCounter(&end);

  tiempo = ((double)(end.QuadPart - start.QuadPart) / (double)freq.QuadPart) * 1000000.0; // Convierte a microsegundos

  cout << "Tiempo de ejecución: " << tiempo << " microsegundos" << endl;

  return 0;
}