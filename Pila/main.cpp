#include <iostream>
#include "Pila.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char **argv)
{

	cout << "Por favor ingrese la expresion a trabajar:" << endl;
  char c;
  Pila<char> guardar(50);
  while(cin.get(c))
  {
    while(c>='0' && c<='9')
    {
      cout.put(c);
      cin.get(c);
    }
    if (c==')')
      cout.put(guardar.sacar());
    if (c=='+')
      guardar.meter(c);
    if (c=='*')
      guardar.meter(c);
    if (c!='(')
      cout << ' ';
    if(c=='\n'){
     break;
    }
  }
 
  cout<< '\n';

	cout << "Por favor copie y pegue el resultado anterior:" << endl;
  // Segundo programa
  Pila<int> acc(50);
  int x;

  while (cin.get(c))
  {
    x = 0;
    while (c == ' ')
      cin.get(c);
    if (c == '\n')
    {
      break;
    }
    while (c >= '0' && c <= '9')
    {
      x = 10 * x + (c - '0');
      cin.get(c);
    }

	//para las operaciones 
    if (c == '+')
    {
      if (x != 0)
        acc.meter(x);
      x = acc.sacar() + acc.sacar();
    }

    if (c == '*')
    {
      if (x != 0)
        acc.meter(x);
      x = acc.sacar() * acc.sacar();
    }
    
    if (c == '-')
    {
      if (x != 0)
        acc.meter(x);
      int b = acc.sacar();
      x = acc.sacar() - b;
    }

    acc.meter(x);
  }

	int resultado_dado = acc.sacar() ;
  cout << "El resultado es: " << resultado_dado << endl;
  
  // Comparación con el cálculo manual
  int resultado_esperado = ( 5 * (((9 + 10) * (4 * 6)) +20));  //se ingresa la expresion a evaluar 
  cout << "El resultado esperado es: " << resultado_esperado << endl;

  if (resultado_dado == resultado_esperado)
    cout << "El resultado del programa es correcto." << endl;
  else
    cout << "El resultado del programa es incorrecto." << endl;



  return 0;
}

