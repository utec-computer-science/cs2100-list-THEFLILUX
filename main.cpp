#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"

int main(int argc, const char * argv[]) {

    cout<<"\n"<< "----------FORWARD LINKED LIST----------" << "\n";
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
    lista.erase(3);

    //Iterator ++
    showLinkedList(lista);

    //Sort
    lista.sort();

    //Print
    cout<<lista<< "\n";

    //Reverse
    lista.reverse();

    //Print
    cout<<lista<< "\n";

    //Searching
    lista.search(3);

    //Maximun
    lista.get_max();

    //Minimun
    lista.get_min();

    lista.clear();

    return 0;
}

