//
// Created by theflilux on 13/04/20.
//

#include <iostream>
#include "LinkedList.h"
using std::cout;
using std::ostream;

//Constructor
template <typename T>
CS::LinkedList<T>::LinkedList() {
    maxElem=0, head = nullptr, tail= nullptr;
}

//Cantidad de elementos en la lista
template <typename T>
int CS::LinkedList<T>::size() {
    int count = 0;
    ListNode<T>* actual = head;
    while(actual != nullptr) {
        count++;
        actual = actual->next;
    }
    return count;
}

template <typename T>
bool CS::LinkedList<T>::is_empty() {
    return head == nullptr;
}

//Insertar al principio
template <typename T>
void CS::LinkedList<T>::push_front(const T & data) {
    ListNode<T>* nuevo_nodo = new ListNode<T>();
    nuevo_nodo->data=data;
    if (is_empty()) {
        head = nuevo_nodo;
        tail = nuevo_nodo;
    } else {
        nuevo_nodo->next = head;
        head = nuevo_nodo;
    }
}

//Insertar al final
template <typename T>
void CS::LinkedList<T>::push_back(const T & data) {
    ListNode<T>* nuevo_nodo = new ListNode<T>();
    nuevo_nodo->data=data;
    if(is_empty()){
        head = nuevo_nodo;
        tail = nuevo_nodo;
    } else {
        ListNode<T>* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        nuevo_nodo->next = nullptr;
        temp->next = nuevo_nodo;
        tail = nuevo_nodo;
    }
}

//Insertar en una posicion
template <typename T>
void CS::LinkedList<T>::insert(const int &position, const T &data) {
    ListNode<T>* nuevo_nodo = new ListNode<T>();
    nuevo_nodo->data=data;
    if(is_empty()){
        head = nuevo_nodo;
        tail = nuevo_nodo;
    } else if(position == 1){ //Insertar al principio
        nuevo_nodo->next = head;
        head = nuevo_nodo;
    } else if(position==size()+1){ //Insertar al final
        ListNode<T>* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        nuevo_nodo->next = nullptr;
        temp->next = nuevo_nodo;
        tail = nuevo_nodo;
    } else if(position<size()+2){ //Insertar en medio
        ListNode<T>* temp = head;
        int _pos = 2;
        while(_pos != position){
            temp = temp->next;
            _pos = _pos+1;
        }
        nuevo_nodo->next = temp->next;
        temp->next = nuevo_nodo;
    } else{
        std::cout << "Esa posicion no existe";
    }
}

//Searching
template <typename T>
void CS::LinkedList<T>::search(const int & position){
    int _pos = 1;
    ListNode<T> * temp = head;
    while(_pos != position){
        temp = temp->next;
        _pos = _pos+1;
    }
    cout <<"\n"<< "El dato que se encuentra en la posicion ingresada es: " << temp->data << "\n";
}

template<typename T>
void CS::LinkedList<T>::pop_front() {
    if (head != nullptr) {
        ListNode<T> * temp = head;
        head = temp->next;
        temp->next = nullptr;
        delete temp;
    }
}

template<typename T>
void CS::LinkedList<T>::pop_back() {
    if(head != nullptr){
        ListNode<T>* temp = head;
        ListNode<T>* aux = head;
        while(temp->next->next != nullptr){
            temp = temp->next;
            aux = aux->next;
        }
        aux = temp->next;
        delete aux;
        temp->next = nullptr;
    }
}

template<typename T>
void CS::LinkedList<T>::clear() {
    ListNode<T>* temp = head;
    while (temp->next != nullptr){
        delete temp;
        temp = temp->next;
    }
    delete temp;
}

template<typename T>
void CS::LinkedList<T>::get_max() {
    if(is_empty()){
        cout << "La lista esta vacia"<< "\n";
    }
    else{
        ListNode<T> * temp = head;
        while(temp != nullptr){
            if(temp->data > maxElem){
                maxElem = temp->data;
            }
            temp = temp->next;
        }
        cout << "El elemento maximo es: "<< maxElem << "\n";
    }
}

template<typename T>
void CS::LinkedList<T>::get_min() {
    if(is_empty()){
        cout << "La lista esta vacia"<< "\n";
    }
    else{
        ListNode<T> * temp = head;
        while(temp != nullptr){
            if(temp->data < maxElem){
                maxElem = temp->data;
            }
            temp = temp->next;
        }
        cout << "El elemento minimo es: "<< maxElem << "\n";
    }
}

template<typename T>
void CS::LinkedList<T>::erase(const int &position) {
    ListNode<T> *temp = head;
    if(position==1){
        head = temp->next;
        delete temp;
        return;
    }
    for(int i=0; i<position-2;i++){
        temp = temp->next;
    }
    ListNode<T> *aux = temp->next;
    temp->next = aux->next;
    delete aux;
}

template<typename T>
void CS::LinkedList<T>::remove(const T &) {
    ListNode<T> *temp = head;
}

template<typename T>
void CS::LinkedList<T>::sort() {
    ListNode<T> *current, *temp;
    for (int i = size()-1; i >= 0; i--) {
        current = head;
        temp = head->next;
        for (int j = 0; j < size()-1; j++) {
            if (current->data > temp->data) {
                swap(current->data, temp->data);
            }
            current = temp;
            temp = temp->next;
        }
    }
}

template<typename T>
void CS::LinkedList<T>::reverse() {
    ListNode<T> *current, *temp, *aux;
    temp = nullptr;
    current = head;
    while (current != nullptr) {
        aux = current->next;
        current->next = temp;
        temp = current;
        current = aux;
    }
    head = temp;
}

