#include "lista.h"
#include <iostream>
#include <locale.h>


using namespace std;

// Definición de la estructura de un ingrediente
struct ingrediente {
    string nombre;
    double cantidad;
    string medida;
};

// Definición de la estructura de una receta
struct receta {
    string nombre;
    lista<ingrediente> ingredientes;
    int tiempo;
    int porciones;
    string instrucciones;  
};


// Función para agregar una nueva receta a la lista
void agregar_receta(lista<receta>& lista_recetas) {
    string nombre_receta;
    cout << "Ingrese el nombre de la receta: ";
    cin >> nombre_receta;
    
    // Verificar si la receta ya existe en la lista
    for (int i = 0; i < lista_recetas.getTam(); i++) {
        if (lista_recetas.buscar(i).nombre == nombre_receta) {
            cout << "La receta ya existe en la lista" << endl;
            return;
        }
    }
    
    receta nueva_receta;
    nueva_receta.nombre = nombre_receta;
    
    int cantidad_ingredientes;
    cout << "Ingrese la cantidad de ingredientes: ";
    cin >> cantidad_ingredientes;
    
    // Agregar cada ingrediente a la lista de ingredientes de la receta
    for (int i = 0; i < cantidad_ingredientes; i++) {
        ingrediente nuevo_ingrediente;
        cout << "Ingrese el nombre del ingrediente " << i+1 << ": ";
        cin >> nuevo_ingrediente.nombre;
        cout << "Ingrese la cantidad del ingrediente" << i+1 << ": ";
        cin >> nuevo_ingrediente.cantidad;
        cout << "Ingrese la medida del ingrediente (taza. cucharada, pizca, etc)" << i+1 << ": ";
        cin >> nuevo_ingrediente.medida;
        
        nueva_receta.ingredientes.insertar_final(nuevo_ingrediente);
    }
    
    int tiempo_cocina;
    cout << "Ingrese el tiempo (minutos) de preparacion: ";
    cin >> tiempo_cocina; 
    nueva_receta.tiempo = tiempo_cocina;
    
    int cantidad_porciones;
    cout << "Ingrese el numero de porciones: ";
    cin >> cantidad_porciones; 
    cin.ignore();  // Ignorar el carácter de nueva línea en el búfer de entrada
    nueva_receta.porciones = cantidad_porciones;
    
    string instrucciones_receta;
    cout << "Ingrese las instrucciones de la receta: ";
    getline(cin, instrucciones_receta);
    nueva_receta.instrucciones = instrucciones_receta;
    
    // Agregar la receta a la lista de recetas
    lista_recetas.insertar_final(nueva_receta);
    cout << "Receta agregada correctamente" << endl;
} 

// Función para buscar una receta por su nombre
void buscar_receta(lista<receta>& lista_recetas) {
    string nombre_receta;
    cout << "Ingrese el nombre de la receta que desea buscar: ";
    cin >> nombre_receta;
    
    // Buscar la receta en la lista
    for (int i = 0; i < lista_recetas.getTam(); i++) {
        if (lista_recetas.buscar(i).nombre == nombre_receta) {
        	
        	int tiempo_cocina = lista_recetas.buscar(i).tiempo;
			int cantidad_porciones = lista_recetas.buscar(i).porciones;
			string instrucciones_preparacion = lista_recetas.buscar(i).instrucciones;
        	
        	cout << "---------- RECETA ----------" << endl;
        	cout << "Tiempo de preparación: " << tiempo_cocina << " minutos" << endl;
        	cout << "Porciones: " << cantidad_porciones << endl;
            cout << "Ingredientes de la receta " << nombre_receta << ":" << endl;
            
			lista<ingrediente> lista_ingredientes = lista_recetas.buscar(i).ingredientes;
            for (int j = 0; j < lista_ingredientes.getTam(); j++) {  // aca es donde deberia de estar el error
                ingrediente ingrediente_actual = lista_ingredientes.buscar(j);
                cout << "- " << ingrediente_actual.cantidad << " " << ingrediente_actual.medida << " de " << ingrediente_actual.nombre << endl;
            }
            
            
            cout << "Instrucciones de preparación: " << instrucciones_preparacion << endl;
            cout << "----------------------------------" << endl;
            return;
        }
    }
    
    cout << "La receta no se encuentra en la lista" << endl;
}

int main() {
	setlocale(LC_ALL, "");
    lista<receta> lista_recetas;
    int opcion;
    do {
        cout << "---------- Menú ----------" << endl;
        cout << "1. Agregar una nueva receta" << endl;
        cout << "2. Buscar una receta por nombre" << endl;
        cout << "3. Salir" << endl;
	    cout << "Ingrese una opción: ";
	    cin >> opcion;
	    
	    switch (opcion) {
	        case 1:
	            agregar_receta(lista_recetas);
	            break;
	        case 2:
	            buscar_receta(lista_recetas);
	            break;
	        case 3:
	            cout << "Saliendo del programa..." << endl;
	            break;
	        default:
	            cout << "Opción inválida" << endl;
	            break;
	    }
	    
	    cout << endl;
	} while (opcion != 3);
	
	return 0;
}