//
// Created by theflilux on 13/04/20.
//

#include <iostream>
#include "DoublyLinkedList.h"
using std::cout;
using std::ostream;

//Constructor
template <typename T>
CS::DoublyLinkedList<T>::DoublyLinkedList() {
    maxElem=0, head = nullptr;
}

//Cantidad de elementos en la lista
template <typename T>
int CS::DoublyLinkedList<T>::size() {
    int count = 0;
    DoublyListNode<T>* actual = head;
    while(actual != nullptr) {
        count++;
        actual = actual->next;
    }
    return count;
}

template <typename T>
bool CS::DoublyLinkedList<T>::is_empty() {
    return head == nullptr;
}

//Insertar al principio
template <typename T>
void CS::DoublyLinkedList<T>::push_front(const T & data) {
    DoublyListNode<T>* nuevo_nodo = new DoublyListNode<T>();
    nuevo_nodo->data=data;
    if (is_empty()) {
        head = nuevo_nodo;
    } else {
        head->prev = nuevo_nodo;
        nuevo_nodo->next = head;
        head = nuevo_nodo;
    }
}

//Insertar al final
template <typename T>
void CS::DoublyLinkedList<T>::push_back(const T & data) {
    DoublyListNode<T>* nuevo_nodo = new DoublyListNode<T>();
    nuevo_nodo->data=data;
    if(is_empty()){
        head = nuevo_nodo;
    } else {
        DoublyListNode<T>* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        nuevo_nodo->next = nullptr;
        temp->next = nuevo_nodo;
        nuevo_nodo->prev = temp;
    }
}

//Insertar en una posicion
template <typename T>
void CS::DoublyLinkedList<T>::insert(const int &position, const T &data) {
    DoublyListNode<T>* nuevo_nodo = new DoublyListNode<T>();
    nuevo_nodo->data=data;
    if(is_empty()){
        head = nuevo_nodo;
    } else if(position == 1){ //Insertar al principio
        head->prev = nuevo_nodo;
        nuevo_nodo->next = head;
        head = nuevo_nodo;
    } else if(position==size()+1){ //Insertar al final
        DoublyListNode<T>* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        nuevo_nodo->next = nullptr;
        temp->next = nuevo_nodo;
        nuevo_nodo->prev = temp;
    } else if(position<size()+2){ //Insertar en medio
        DoublyListNode<T>* temp = head;
        int _pos = 2;
        while(_pos != position){
            temp = temp->next;
            _pos = _pos+1;
        }
        nuevo_nodo->next = temp->next;
        temp->next->prev = nuevo_nodo;
        temp->next = nuevo_nodo;
        nuevo_nodo->prev = temp;
    } else{
        std::cout << "Esa posicion no existe";
    }

}

//Searching
template <typename T>
void CS::DoublyLinkedList<T>::search(const int & position){
    int _pos = 1;
    DoublyListNode<T> * temp = head;
    while(_pos != position){
        temp = temp->next;
        _pos = _pos+1;
    }
    cout <<"\n"<< "El dato que se encuentra en la posicion ingresada es: " << temp->data << "\n";
}

template<typename T>
void CS::DoublyLinkedList<T>::pop_front() {
    if (head != nullptr) {
        DoublyListNode<T> * temp = head;
        head = temp->next;
        temp->next = nullptr;
        head->prev = nullptr;
        delete temp;
    }
}

template<typename T>
void CS::DoublyLinkedList<T>::pop_back() {
    if(head != nullptr){
        DoublyListNode<T>* temp = head;
        DoublyListNode<T>* aux = head;
        while(temp->next->next != nullptr){
            temp = temp->next;
            aux = aux->next;
        }
        aux = temp->next;
        delete aux;
        temp->next = nullptr;
    }
}
