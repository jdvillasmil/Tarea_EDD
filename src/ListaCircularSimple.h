#ifndef LISTACIRCULARSIMPLE_H
#define LISTACIRCULARSIMPLE_H

#include <iostream>

template <typename T>
class NodoSimple {
public:
    T data;
    NodoSimple* next;

    NodoSimple(T data) : data(data), next(nullptr) {}
};

template <typename T>
class ListaCircularSimple {
private:
    NodoSimple<T>* head;

public:
    ListaCircularSimple() : head(nullptr) {}

    void insertar(T data);
    void insertarOrdenado(T data);
    void eliminar(T data);
    bool buscar(T data);
    void mostrar();
};

// Implementación de las funciones
template <typename T>
void ListaCircularSimple<T>::insertar(T data) {
    NodoSimple<T>* nuevo = new NodoSimple<T>(data);
    if (!head) {
        head = nuevo;
        head->next = head;
    } else {
        NodoSimple<T>* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = nuevo;
        nuevo->next = head;
    }
}

template <typename T>
void ListaCircularSimple<T>::insertarOrdenado(T data) {
    NodoSimple<T>* nuevo = new NodoSimple<T>(data);
    if (!head) {
        head = nuevo;
        head->next = head;
    } else if (data < head->data) {
        NodoSimple<T>* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = nuevo;
        nuevo->next = head;
        head = nuevo;
    } else {
        NodoSimple<T>* temp = head;
        while (temp->next != head && temp->next->data < data)
            temp = temp->next;
        nuevo->next = temp->next;
        temp->next = nuevo;
    }
}

template <typename T>
void ListaCircularSimple<T>::eliminar(T data) {
    if (!head) return;

    NodoSimple<T>* temp = head;
    NodoSimple<T>* prev = nullptr;

    // Si el elemento a eliminar es el head
    if (temp->data.nombre == data.nombre && temp->data.edad == data.edad) {
        while (temp->next != head) // Encuentra el último nodo
            temp = temp->next;
        NodoSimple<T>* toDelete = head;
        if (head == head->next) {
            head = nullptr;
        } else {
            temp->next = head->next;
            head = head->next;
        }
        delete toDelete;
        return;
    }

    // Buscar el nodo a eliminar
    do {
        prev = temp;
        temp = temp->next;
    } while (temp != head && !(temp->data.nombre == data.nombre && temp->data.edad == data.edad));

    if (temp == head) return; // No se encontró

    prev->next = temp->next;
    delete temp;
}

template <typename T>
bool ListaCircularSimple<T>::buscar(T data) {
    if (!head) return false;
    NodoSimple<T>* temp = head;
    do {
        if (temp->data.nombre == data.nombre && temp->data.edad == data.edad) return true;
        temp = temp->next;
    } while (temp != head);
    return false;
}

template <typename T>
void ListaCircularSimple<T>::mostrar() {
    if (!head) return;
    NodoSimple<T>* temp = head;
    do {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    } while (temp != head);
}

#endif // LISTACIRCULARSIMPLE_H

