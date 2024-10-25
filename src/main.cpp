#include "Persona.h"
#include "ListaCircularSimple.h"
#include "ListaCircularDoble.h"

int main() {
    ListaCircularSimple<Persona> listaSimple;
    ListaCircularDoble<Persona> listaDoble;

    // Pruebas de inserción desordenada
    listaSimple.insertar(Persona("Carlos", 25));
    listaSimple.insertar(Persona("Ana", 20));
    listaSimple.insertar(Persona("Luis", 30));

    listaDoble.insertar(Persona("Carlos", 25));
    listaDoble.insertar(Persona("Ana", 20));
    listaDoble.insertar(Persona("Luis", 30));

    std::cout << "Lista Circular Simple (Desordenada):\n";
    listaSimple.mostrar();

    std::cout << "\nLista Circular Doble (Desordenada):\n";
    listaDoble.mostrar();

    // Pruebas de inserción ordenada
    ListaCircularSimple<Persona> listaSimpleOrdenada;
    ListaCircularDoble<Persona> listaDobleOrdenada;

    listaSimpleOrdenada.insertarOrdenado(Persona("Carlos", 25));
    listaSimpleOrdenada.insertarOrdenado(Persona("Ana", 20));
    listaSimpleOrdenada.insertarOrdenado(Persona("Luis", 30));

    listaDobleOrdenada.insertarOrdenado(Persona("Carlos", 25));
    listaDobleOrdenada.insertarOrdenado(Persona("Ana", 20));
    listaDobleOrdenada.insertarOrdenado(Persona("Luis", 30));

    std::cout << "\nLista Circular Simple (Ordenada):\n";
    listaSimpleOrdenada.mostrar();

    std::cout << "\nLista Circular Doble (Ordenada):\n";
    listaDobleOrdenada.mostrar();

    // Pruebas de búsqueda y eliminación
    std::cout << "\nEliminando 'Ana' de ambas listas:\n";
    listaSimple.eliminar(Persona("Ana", 20));
    listaDoble.eliminar(Persona("Ana", 20));

    std::cout << "Lista Circular Simple (despues de eliminar):\n";
    listaSimple.mostrar();

    std::cout << "\nLista Circular Doble (despues de eliminar):\n";
    listaDoble.mostrar();

    return 0;
}

