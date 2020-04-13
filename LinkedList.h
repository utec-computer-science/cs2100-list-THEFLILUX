//
// Created by theflilux on 13/04/20.
//

#ifndef CS2100_LIST_THEFLILUX_LINKEDLIST_H
#define CS2100_LIST_THEFLILUX_LINKEDLIST_H

#include <iostream>
#include "Queue.h"

using std::cout;
using std::ostream;

namespace CS{

    template <typename T>
    struct ListNode {
        T data;
        ListNode<T>* next;
    };

    template <typename T>
    class iterator2{
    private:
        ListNode<T> * pointer;
    public:
        iterator2(){pointer = nullptr;}
        explicit iterator2(ListNode<T> * ptr) {
            this->pointer = ptr;
        }

        void operator ++(){
            this->pointer = this->pointer->next;
        }

        T operator * (){
            return this->pointer->data;
        }

        bool operator == (const iterator2 & it){
            return this->pointer == it.pointer;
        }

        bool operator != (const iterator2 & it){
            return this->pointer != it.pointer;
        }

    };

    template <typename T>
    class LinkedList {
    private:
        ListNode<T>* head;
        int maxElem;
    public:
        typedef iterator2<T> iterator;
        LinkedList();

        //Maximun
        void get_max(){
            if(is_empty()){
                cout << "El stack esta vacio"<< "\n";
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

        //Minimun
        void get_min(){
            if(is_empty()){
                cout << "El stack esta vacio"<< "\n";
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

        int size();
        bool is_empty();
        void push_front(const T & data);
        void push_back(const T & data);
        void insert(const int &position, const T &data);
        void pop_front();
        void pop_back();
        void pop(const int &position);

        //Searching
        void search(const int & position);

        iterator begin(){
            return iterator(head);
        }

        iterator end(){
            return iterator(nullptr);
        }

        //Printing
        friend ostream& operator << (ostream &os, const LinkedList & linkedList){
            ListNode<T> * pointer = linkedList.head;
            while(pointer != nullptr){
                os<<pointer->data << " ";
                pointer = pointer->next;
            }
            return os;
        }

    };

    //Printing Iterator
    template <typename T>
    void showLinkedList(LinkedList<T> x){
        typename CS::LinkedList<T>::iterator it;
        for(it = x.begin(); it != x.end(); ++it){
            cout <<*it<<" ";
        }
    }
}

#endif //CS2100_LIST_THEFLILUX_LINKEDLIST_H
