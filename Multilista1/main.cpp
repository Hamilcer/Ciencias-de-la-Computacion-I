#include "Multilista.h"
#include <iostream>

using namespace std;
std::ostream &operator<<(std::ostream &os, const P &p)
{
    os << "Nombre: " << p.nombre << ", Carrera: " << p.carrera
       << ", Actividad: " << p.actividad << ", Codigo: " << p.codigo;
    return os;
}

int main()
{
    Multilista1 ml(10, 10); // Crear la multilista con capacidad para 10 elementos y 10 cabeceras

    // Insertar elementos
    P p1 = {"raquel", "electrica", "danza", 72};
    P p2 = {"jaime", "industrial", "natacion", 25};
    P p3 = {"arturo", "electrica", "basquet", 45};
    P p4 = {"andres", "catastral", "danza", 50};
    P p5 = {"ariana", "sistemas", "basquet", 36};
    P p6 = {"juanny", "industrial", "natacion", 56};
    P p7 = {"may", "sistemas", "danza", 42};
    P p8 = {"italia", "catastral", "beisbol", 87};
    P p9 = {"mario", "sistemas", "basquet", 69};
    P p10 = {"pilar", "sistemas", "beisbol", 30};

    
    ml.insertar(p1);
    ml.insertar(p2);
    ml.insertar(p3);
    ml.insertar(p4);
    ml.insertar(p5);
    ml.insertar(p6);
    ml.insertar(p7); 
    ml.insertar(p8);
    ml.insertar(p9);
    ml.insertar(p10);

    ml.imprimir();

    return 0;
}