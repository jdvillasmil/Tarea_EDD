#ifndef LISTACIRCULARDOBLE_H
#define LISTACIRCULARDOBLE_H

#include <iostream>

template <typename T>
class NodoDoble {
public:
    T data;
    NodoDoble* next;
    NodoDoble* prev;

    NodoDoble(T data) : data(data), next(nullptr), prev(nullptr) {}
};

template <typename T>
class ListaCircularDoble {
private:
    NodoDoble<T>* head;

public:
    ListaCircularDoble() : head(nullptr) {}

    void insertar(T data);
    void insertarOrdenado(T data);
    void eliminar(T data);
    bool buscar(T data);
    void mostrar();
};

// Implementación de las funciones
template <typename T>
void ListaCircularDoble<T>::insertar(T data) {
    NodoDoble<T>* nuevo = new NodoDoble<T>(data);
    if (!head) {
        head = nuevo;
        head->next = head;
        head->prev = head;
    } else {
        NodoDoble<T>* temp = head->prev;
        temp->next = nuevo;
        nuevo->prev = temp;
        nuevo->next = head;
        head->prev = nuevo;
    }
}

template <typename T>
void ListaCircularDoble<T>::insertarOrdenado(T data) {
    NodoDoble<T>* nuevo = new NodoDoble<T>(data);
    if (!head) {
        head = nuevo;
        head->next = head;
        head->prev = head;
    } else if (data < head->data) {
        NodoDoble<T>* temp = head->prev;
        temp->next = nuevo;
        nuevo->prev = temp;
        nuevo->next = head;
        head->prev = nuevo;
        head = nuevo;
    } else {
        NodoDoble<T>* temp = head;
        while (temp->next != head && temp->next->data < data)
            temp = temp->next;
        nuevo->next = temp->next;
        nuevo->prev = temp;
        temp->next->prev = nuevo;
        temp->next = nuevo;
    }
}

template <typename T>
void ListaCircularDoble<T>::eliminar(T data) {
    if (!head) return;

    NodoDoble<T>* temp = head;

    // Si el elemento a eliminar es el head
    if (temp->data.nombre == data.nombre && temp->data.edad == data.edad) {
        if (head == head->next) {
            delete head;
            head = nullptr;
            return;
        }
        NodoDoble<T>* last = head->prev;
        last->next = head->next;
        head->next->prev = last;
        NodoDoble<T>* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    // Buscar el nodo a eliminar
    do {
        temp = temp->next;
    } while (temp != head && !(temp->data.nombre == data.nombre && temp->data.edad == data.edad));

    if (temp == head) return; // No se encontró

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

template <typename T>
bool ListaCircularDoble<T>::buscar(T data) {
    if (!head) return false;
    NodoDoble<T>* temp = head;
    do {
        if (temp->data.nombre == data.nombre && temp->data.edad == data.edad) return true;
        temp = temp->next;
    } while (temp != head);
    return false;
}

template <typename T>
void ListaCircularDoble<T>::mostrar() {
    if (!head) return;
    NodoDoble<T>* temp = head;
    do {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    } while (temp != head);
}

#endif // LISTACIRCULARDOBLE_H
