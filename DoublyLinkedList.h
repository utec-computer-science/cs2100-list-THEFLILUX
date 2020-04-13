//
// Created by theflilux on 13/04/20.
//

#ifndef CS2100_LIST_THEFLILUX_DOUBLYLINKEDLIST_H
#define CS2100_LIST_THEFLILUX_DOUBLYLINKEDLIST_H

#include <iostream>

using std::cout;
using std::ostream;

namespace CS{

    template <typename T>
    struct DoublyListNode {
        T data;
        DoublyListNode<T>* next;
        DoublyListNode<T>* prev;
    };

    template <typename T>
    class iterator4{
    private:
        DoublyListNode<T> * pointer;
    public:
        iterator4(){pointer = nullptr;}
        explicit iterator4(DoublyListNode<T> * ptr) {
            this->pointer = ptr;
        }

        void operator ++(){
            this->pointer = this->pointer->next;
        }

        void operator --(){
            this->pointer = this->pointer->prev;
        }

        T operator * (){
            return this->pointer->data;
        }

        bool operator == (const iterator4 & it){
            return this->pointer == it.pointer;
        }

        bool operator != (const iterator4 & it){
            return this->pointer != it.pointer;
        }

    };

    template <typename T>
    class DoublyLinkedList {
    private:
        DoublyListNode<T>* head;
        int maxElem;
    public:
        typedef iterator4<T> iterator;
        DoublyLinkedList();

        //Maximun
        void get_max(){
            if(is_empty()){
                cout << "El stack esta vacio"<< "\n";
            }
            else{
                DoublyListNode<T> * temp = head;
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
                DoublyListNode<T> * temp = head;
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

        iterator rbegin(){
            DoublyListNode<T>* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            return iterator(temp);
        }

        iterator rend(){
            return iterator(nullptr);
        }

        //Printing
        friend ostream& operator << (ostream &os, const DoublyLinkedList & linkedList){
            DoublyListNode<T> * pointer = linkedList.head;
            while(pointer != nullptr){
                os<<pointer->data << " ";
                pointer = pointer->next;
            }
            return os;
        }

    };

    //Printing Iterator
    template <typename T>
    void showDoublyLinkedList(DoublyLinkedList<T> x){
        typename CS::DoublyLinkedList<T>::iterator it;
        for(it = x.begin(); it != x.end(); ++it){
            cout <<*it<<" ";
        }
        cout<<"\n";
    }

    //Printing Iterator
    template <typename T>
    void showDoublyLinkedList_reverse(DoublyLinkedList<T> x){
        typename CS::DoublyLinkedList<T>::iterator it;
        for(it = x.rbegin(); it != x.rend(); --it){
            cout <<*it<<" ";
        }
        cout<<"\n";
    }

}


#endif //CS2100_LIST_THEFLILUX_DOUBLYLINKEDLIST_H
