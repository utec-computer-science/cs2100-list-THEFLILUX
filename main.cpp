#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "DoublyLinkedList.h"
#include "DoublyLinkedList.cpp"

int main(int argc, const char * argv[]) {

    cout<<"\n"<< "----------SINGLE LINKED LIST----------" << "\n";
    CS::LinkedList<int> lista;

    //Insertion
    lista.push_front(4);
    lista.push_front(5);
    lista.push_front(6);
    lista.push_back(1);
    lista.push_back(2);
    lista.insert(4,1);
    lista.insert(5,1);
    lista.insert(6,1);
    lista.insert(1,4);
    lista.insert(2,3);

    //Print
    cout<<lista<< "\n";

    //Deletion
    lista.pop_front();
    lista.pop_back();

    //Iterator ++
    showLinkedList(lista);

    //Searching
    lista.search(3);

    //Maximun
    lista.get_max();

    //Minimun
    lista.get_min();

    cout<<"\n"<< "----------DOUBLY LINKED LIST----------" << "\n";

    CS::DoublyLinkedList<int> Doblelista;

    //Insertion
    Doblelista.push_front(32);
    Doblelista.push_front(67);
    Doblelista.push_front(23);
    Doblelista.push_back(57);
    Doblelista.push_back(51);
    Doblelista.push_back(64);
    Doblelista.insert(2,54);

    //Print
    cout<<Doblelista<<"\n";

    //Deletion
    Doblelista.pop_front();
    Doblelista.pop_back();

    //Iterator ++
    showDoublyLinkedList(Doblelista);

    //Iterator -- (Inverso)
    showDoublyLinkedList_reverse(Doblelista);

    //Searching
    Doblelista.search(2);

    //Maximun
    Doblelista.get_max();

    //Minimun
    Doblelista.get_min();

    cout<<"\n"<< "----------CIRCULAR LINKED LIST----------" << "\n";

    cout<<"\n"<< "----------DOUBLY CIRCULAR LINKED LIST----------" << "\n";

    return 0;
}

