//
// Created by theflilux on 13/04/20.
//

#ifndef CS2100_LIST_THEFLILUX_LINKEDLIST_H
#define CS2100_LIST_THEFLILUX_LINKEDLIST_H

#include <iostream>
using namespace  std;

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
        ListNode<T>* tail;
        int maxElem;
    public:
        typedef iterator2<T> iterator;
        LinkedList();
        ~LinkedList()=default;

        //Maximun
        void get_max();

        //Minimun
        void get_min();

        int size();
        bool is_empty();
        void push_front(const T & data);
        void push_back(const T & data);
        void insert(const int &position, const T &data);
        void pop_front();
        void pop_back();
        void erase(const int &position);
        void remove(const T &element);
        void sort();
        void reverse();
        void clear();

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
            cout<<"\n";
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
