#include <iostream>
#include "arbolB.h"

int main(int argc, char const *argv[])
{
    arbolB miArbol = arbolB(2);

    miArbol.insertar(62);
    miArbol.insertar(51);
    miArbol.insertar(47);
    miArbol.insertar(78);
    miArbol.insertar(87);
    miArbol.insertar(39);
    miArbol.insertar(37);
    miArbol.insertar(35);
    miArbol.insertar(100);
    miArbol.insertar(32);
    miArbol.insertar(43);
    miArbol.insertar(96);
    miArbol.insertar(90);
    miArbol.insertar(81);
    miArbol.insertar(83);
    miArbol.insertar(25);
    miArbol.insertar(10);
    miArbol.insertar(98);
    miArbol.insertar(92);
    miArbol.insertar(105);
    miArbol.insertar(20);
    miArbol.insertar(15);
    miArbol.insertar(12);
    miArbol.insertar(5);
    miArbol.insertar(120);
    miArbol.insertar(110);
    miArbol.insertar(130);

    miArbol.eliminar(110);
    miArbol.eliminar(81);
    miArbol.eliminar(130);
    miArbol.eliminar(25);
    miArbol.eliminar(5);
    miArbol.eliminar(83);
    miArbol.eliminar(120);
    miArbol.eliminar(10);
    miArbol.eliminar(15);
    miArbol.eliminar(92);
    miArbol.eliminar(98);
    miArbol.eliminar(12);
    miArbol.eliminar(20);
    miArbol.eliminar(105);
    miArbol.eliminar(90);
    miArbol.eliminar(43);
    miArbol.eliminar(32);
    miArbol.eliminar(96);
    miArbol.eliminar(47);
    miArbol.eliminar(78);
    miArbol.eliminar(37);
    miArbol.eliminar(87);

    miArbol.imprimir(miArbol.getRaiz());

    return 0;
}