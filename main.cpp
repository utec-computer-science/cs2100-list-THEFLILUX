#include<iostream>
using namespace std;

template <typename T>
class Node {
public:
    typedef T value_t;
    typedef unsigned int size_t;

public:
    value_t value;

public:
    Node(const value_t& _value):value(_value){
    }

    size_t size(){
        return 0;
    }

    ~Node(void){
    }

    value_t& operator*(void){
        return value;
    }

    template <typename _T>
    inline friend ostream& operator<< (ostream& _out, const Node<_T>& _node){
        _out << "Nodo: " <<  _node.value;
        return _out;
    }
};

template <typename T>
class ForwardListNode : public Node<T> {
public:
    typedef typename Node<T>::value_t value_t;

public:
    ForwardListNode<T>* next;

public:
    ForwardListNode(const T& _value):Node<T>(_value),next(nullptr){
    }

    ~ForwardListNode(void){
    }

    template <typename _T>
    inline friend ostream& operator<< (ostream& _out, const ForwardListNode<_T>& _node){
        _out << "Nodo: [v: " <<  _node.value << ", p: " << _node.next << "]";
        return _out;
    }
};

template <typename T>
class DoubleListNode : public Node<T> {
public:
    typedef typename Node<T>::value_t value_t;

public:
    DoubleListNode<T>* next;
    DoubleListNode<T>* prev;

public:
    DoubleListNode(const T& _value):Node<T>(_value),next(nullptr){
    }

    ~DoubleListNode(void){
    }

    template <typename _T>
    inline friend ostream& operator<< (ostream& _out, const DoubleListNode<_T>& _node){
        _out << "Nodo: [v: " <<  _node.value << ", p_next: " << _node.next << ", p_prev: " << _node.next << "]";
        return _out;
    }
};

template <typename T>
class CircularListNode : public Node<T> {
public:
    typedef typename Node<T>::value_t value_t;

public:
    CircularListNode<T>* next;
    CircularListNode<T>* prev;

public:
    CircularListNode(const T& _value):Node<T>(_value),next(nullptr),prev(nullptr){
    }

    ~CircularListNode(void){
    }

    template <typename _T>
    inline friend ostream& operator<< (ostream& _out, const CircularListNode<_T>& _node){
        _out << "Nodo: [v: " <<  _node.value << ", p_next: " << _node.next << ", p_prev: " << _node.next << "]";
        return _out;
    }
};

template <typename Node>
class Iterator{
public:
    typedef Node node_t;
    typedef typename node_t::value_t value_t;

protected:
    node_t * pointer;
public:

    Iterator(node_t* _pointer = nullptr):pointer(_pointer){
    }

    ~Iterator(void){
    }

    virtual bool operator!= (Iterator it){
        return pointer != it.pointer;
    }

    virtual value_t& operator* (void) {
        return **pointer;
    }
};





template <typename Node>
class List {
protected:
    typedef Node node_t;
    typedef typename node_t::value_t value_t;

    node_t* head;

public:
    List(const List&):head(nullptr){
    }

    List(value_t*):head(nullptr){
    }

    List(node_t*):head(nullptr){
    }

    List(int):head(nullptr){
    }

    List(void):head(nullptr){
    }

    ~List(void){
    }


    virtual void push_back(const value_t& element) = 0;
    virtual void push_front(const value_t& element) = 0;

    virtual value_t& front(void) = 0;
    virtual value_t& back(void) = 0;

    virtual node_t* pop_back(void) = 0;
    virtual node_t* pop_front(void) = 0;

    virtual value_t& operator[] (const int&) = 0;

    virtual bool empty(void){
        return head == nullptr;
    };

    virtual unsigned int size(void) = 0;

    template<typename _T>
    inline friend ostream& operator<< (ostream& out, const List<_T>&){
        out << "Nothing to print in father" << endl;
        return out;
    }


    List& operator<< (const value_t& _value){
        this->push_back(_value);
        return *this;
    }

    List& operator>> (const value_t& _value){
        this->push_front(_value);
        return *this;
    }
};


#define DEFAULT_NODE 0
#define FOWARD_NODE 1
#define DOUBLE_NODE 2
#define CIRCULAR_NODE 3


template <typename T, typename NT>
struct NodeTraits{
    static const int nodeType = DEFAULT_NODE;
};

template <typename NT>
struct NodeTraits< ForwardListNode<NT>, NT >{
    static const int nodeType = FOWARD_NODE;
};

template <typename NT>
struct NodeTraits< DoubleListNode<NT>, NT >{
    static const int nodeType = DOUBLE_NODE;
};

template <typename NT>
struct NodeTraits< CircularListNode<NT>, NT >{
    static const int nodeType = CIRCULAR_NODE;
};



template <typename Node>
class ForwardList : public List<Node>{
public:
    typedef Node node_t;
    typedef typename node_t::value_t value_t;

    friend class ForwardIterator;
    class ForwardIterator: public Iterator<node_t> {
    public:
        typedef typename Iterator<node_t>::node_t node_t;
        typedef typename Iterator<node_t>::value_t value_t;

    public:
        ForwardIterator (node_t* pointer = nullptr)
                :Iterator<node_t>(pointer){
        }

        ~ForwardIterator (void){
        }

        ForwardIterator& operator++ (void){
            Iterator<node_t>::pointer = Iterator<node_t>::pointer->next;
            return *this;
        }

    };

protected:
    node_t *head;
    node_t *tail;

    template<int nodeType>
    void __addBack__(Node**,Node**,value_t);
    void __addFront__(Node**,Node**,value_t);
    void __deleteBack__(Node**,Node**);
    void __deleteFront__(Node**,Node**);
    void __search__(Node**,Node**,value_t);
    void __insert__(Node**,Node**,value_t ,value_t);

public:

    void push_back(const value_t& element){
        __addBack__<NodeTraits<node_t,value_t>::nodeType>(&head,&tail,element);
    }

    void push_front(const value_t& element){
        __addFront__<NodeTraits<node_t,value_t>::nodeType>(&head,&tail,element);
    }

    void search(const value_t& position){
        __search__<NodeTraits<node_t,value_t>::nodeType>(&head,&tail,position);
    }

    void insert(const value_t& position,const value_t& element);{
        __insert__<NodeTraits<node_t,value_t>::nodeType>(&head,&tail,position);
    }

    ForwardList(void)
            :List<node_t>(), head(nullptr), tail(nullptr){
    }

    ~ForwardList (void){
    }

    ForwardIterator begin(){
        return ForwardIterator(head);
    }

    ForwardIterator end(){
        return ForwardIterator(tail);
    }

    value_t& front(void){
        return head->value;
    };

    value_t& back(void){
        return tail->value;
    };

    void pop_back(Node**,Node**){
        __deleteBack__<NodeTraits<node_t,value_t>::nodeType>(&head,&tail);
    };

    void pop_front(Node**,Node**){
        __deleteFront__<NodeTraits<node_t,value_t>::nodeType>(&head,&tail);
    };

    value_t& operator[] (const int& _position){
        node_t * tmp = head;
        for (int i = 0; i < _position; i++, tmp = tmp->next);
        return tmp->value;
    }

    bool empty(void){
        return head == nullptr;
    }

    unsigned int size(void){
        int i = 0;
        for (node_t * tmp = head; tmp != nullptr; i++, tmp = tmp->next);
        return i;
    }

    /*template<typename _T>
    inline friend ostream& operator<< (ostream& out, ForwardList<_T>& _list){
        typename ForwardList<_T>::ForwardIterator it = _list.begin();
        for(; it != _list.end(); ++it){
            out << *it << " -> ";
        }
        out << *it << " -> ";
        if (!_list.head) return out;
        ForwardListNode<T> *tmp = _list.head;
        while(tmp){
            out << *tmp << " -> ";
            tmp = tmp->next;
        }

        return out;
    }*/
};

template <typename Node, typename ValueNode, int nodeType>
class ListHelper{
public:
    static void addBack(Node** head, Node** tail, ValueNode element){
        cout << "Hola no tengo trait definido" << endl;

    }

    static void addFront(Node** head, Node** tail, ValueNode element){
        cout << "Hola no tengo trait definido" << endl;

    }

    static void deleteBack(Node** head, Node** tail){
        cout << "Hola no tengo trait definido" << endl;

    }

    static void deleteFront(Node** head, Node** tail){
        cout << "Hola no tengo trait definido" << endl;

    }

    static void search(Node** head, Node** tail, ValueNode position){
        cout << "Hola no tengo trait definido" << endl;

    }

    static void insert(Node** head, Node** tail, ValueNode position, ValueNode element){
        cout << "Hola no tengo trait definido" << endl;

    }

};

template <typename Node, typename ValueNode>
class ListHelper<Node,ValueNode,FOWARD_NODE>{
public:
    static void addBack(Node** head, Node** tail, ValueNode element){
        auto new_node = new Node(element);
        if ((*tail) != nullptr) {
            (*tail)->next = new_node;
            (*tail) = new_node;
        } else {
            (*head) = new_node;
            (*tail) = new_node;
        }
        cout << new_node->value << endl;
    }

    static void addFront(Node** head, Node** tail, ValueNode element){
        auto new_node = new Node(element);
        if ((*head) != nullptr) {
            (*head)->next = new_node;
            (*head) = new_node;
        } else {
            (*head) = (*tail) = new_node;
        }
        cout << new_node->value << endl;
    }

    static void deleteBack(Node** head, Node** tail){
        if((*head) != nullptr){
            auto temp = (*head);
            auto aux = (*head);
            while(temp->next->next != nullptr){
                temp = temp->next;
                aux = aux->next;
            }
            aux = temp->next;
            delete aux;
            temp->next = nullptr;
        }
    }

    static void deleteFront(Node** head, Node** tail){
        if ((*head) != nullptr) {
            auto temp = (*head);
            (*head) = temp->next;
            temp->next = nullptr;
            delete temp;
        }
    }

    static void search(Node** head, Node** tail, ValueNode position){
        int _pos = 1;
        auto temp = (*head);
        while(_pos != position){
            temp = temp->next;
            _pos = _pos+1;
        }
        cout <<"\n"<< "El dato que se encuentra en la posicion ingresada es: " << temp->data << "\n";
    }

    static void insert(Node** head, Node** tail, ValueNode position, ValueNode element){
        auto nuevo_nodo = new Node(element);
        if((*head)== nullptr && (*tail)== nullptr){
            (*head) = nuevo_nodo;
            (*tail) = nuevo_nodo;
        } else if(position == 1){ //Insertar al principio
            nuevo_nodo->next = (*head);
            (*head) = nuevo_nodo;
        } else if(position==size()+1){ //Insertar al final
            auto temp = (*head);
            while(temp->next != nullptr){
                temp = temp->next;
            }
            nuevo_nodo->next = nullptr;
            temp->next = nuevo_nodo;
            (*tail) = nuevo_nodo;
        } else if(position<size()+2){ //Insertar en medio
            auto temp = (*head);
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
};

template <typename Node, typename ValueNode>
class ListHelper<Node,ValueNode,DOUBLE_NODE>{
public:
    static void addBack(Node** head, Node** tail, ValueNode element){
        auto new_node = new Node(element);
        if ((*tail) != nullptr) {
            (*tail)->next = new_node;
            new_node->prev = (*tail);
            (*tail) = new_node;
        } else {
            (*head) = (*tail) = new_node;
        }
        cout << new_node->value << endl;
    }

    static void addFront(Node** head, Node** tail, ValueNode element){
        auto new_node = new Node(element);
        if ((*head) != nullptr) {
            (*head)->prev = new_node;
            new_node->next = (*head);
            (*head) = new_node;
        } else {
            (*head) = (*tail) = new_node;
        }
        cout << new_node->value << endl;
    }

    static void deleteBack(Node** head, Node** tail){
        if((*tail) != nullptr){
            auto temp = (*tail);
            (*tail) = temp->prev;
            temp->prev = nullptr;
            (*tail)->next = nullptr;
            delete temp;
        }
    }

    static void deleteFront(Node** head, Node** tail){
        if ((*head) != nullptr) {
            auto temp = (*head);
            (*head) = temp->next;
            temp->next = nullptr;
            (*head)->prev = nullptr;
            delete temp;
        }
    }

    static void search(Node** head, Node** tail, ValueNode position){
        int _pos = 1;
        auto temp = (*head);
        while(_pos != position){
            temp = temp->next;
            _pos = _pos+1;
        }
        cout <<"\n"<< "El dato que se encuentra en la posicion ingresada es: " << temp->data << "\n";
    }

    static void insert(Node** head, Node** tail, ValueNode position, ValueNode element){
        auto nuevo_nodo = new Node(element);
        if((*head)== nullptr && (*tail)== nullptr){
            (*head) = nuevo_nodo;
            (*tail) = nuevo_nodo;
        } else if(position == 1){ //Insertar al principio
            head->prev = nuevo_nodo;
            nuevo_nodo->next = (*head);
            (*head) = nuevo_nodo;
        } else if(position==size()+1){ //Insertar al final
            nuevo_nodo->prev = (*tail);
            nuevo_nodo->next = nullptr;
            (*tail) = nuevo_nodo;
        } else if(position<size()+2){ //Insertar en medio
            auto temp = (*head);
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
};

template <typename Node, typename ValueNode>
class ListHelper<Node,ValueNode,CIRCULAR_NODE>{
public:
    static void addBack(Node** head, Node** tail, ValueNode element){
        auto new_node = new Node(element);
        if((*tail) != nullptr){
            (*tail)->next = new_node;
            new_node->next = (*head);
            (*tail) = new_node;
        } else {
            (*head) = (*tail) = new_node;
            new_node->next=new_node;
        }
        cout << new_node->value << endl;
    }

    static void addFront(Node** head, Node** tail, ValueNode element){
        auto new_node = new Node(element);
        if((*head) != nullptr){
            (*head)->next = new_node;
            new_node->next = (*head);
            (*head) = new_node;
        } else {
            (*head) = (*tail) = new_node;
            new_node->next=new_node;
        }
        cout << new_node->value << endl;
    }

    static void deleteBack(Node** head, Node** tail){
        if((*head) != nullptr){
            auto temp = (*tail);
            auto aux = (*head);
            while(aux->next != (*tail)){
                aux = aux->next;
            }
            aux->next = temp->next;
            (*head) = aux->next;
            delete temp;
        }
    }

    static void deleteFront(Node** head, Node** tail){
        if ((*head) != nullptr) {
            auto temp = (*tail);
            auto aux = (*head);
            temp->next = aux->next;
            (*head) =temp->next;
            delete aux;
        }
    }

    static void search(Node** head, Node** tail, ValueNode position){
        int _pos = 1;
        auto temp = (*head);
        while(_pos != position){
            temp = temp->next;
            _pos = _pos+1;
        }
        cout <<"\n"<< "El dato que se encuentra en la posicion ingresada es: " << temp->data << "\n";
    }

    static void insert(Node** head, Node** tail, ValueNode position, ValueNode element){
        auto nuevo_nodo = new Node(element);
        if((*head)== nullptr && (*tail)== nullptr){
            nuevo_nodo->next=nuevo_nodo;
            (*head) = nuevo_nodo;
        } else if(position == 1){ //Insertar al principio
            auto temp = (*head);
            while(temp->next != (*head)){
                temp = temp->next;
            }
            temp->next = nuevo_nodo;
            nuevo_nodo->next = (*head);
            (*head) = nuevo_nodo;
        } else if(position==size()){ //Insertar al final
            auto temp = (*head);
            while(temp->next != (*head)){
                temp = temp->next;
            }
            temp->next = nuevo_nodo;
            nuevo_nodo->next = (*head);
        } else if(position<size()+2){ //Insertar en medio
            auto temp = (*head);
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
};

template< typename Node>  template <int nodeType>
void ForwardList<Node>::__addBack__(
        typename ForwardList<Node>::node_t ** head,
        typename ForwardList<Node>::node_t ** tail,
        typename ForwardList<Node>::value_t element){

    ListHelper<ForwardList<Node>::node_t,ForwardList<Node>::value_t,nodeType>::addBack(head,tail,element);
}

template< typename Node>  template <int nodeType>
void ForwardList<Node>::__addFront__(
        typename ForwardList<Node>::node_t ** head,
        typename ForwardList<Node>::node_t ** tail,
        typename ForwardList<Node>::value_t element){

    ListHelper<ForwardList<Node>::node_t,ForwardList<Node>::value_t,nodeType>::addFront(head,tail,element);
}

template< typename Node>  template <int nodeType>
void ForwardList<Node>::__deleteBack__(
        typename ForwardList<Node>::node_t ** head,
        typename ForwardList<Node>::node_t ** tail){

    ListHelper<ForwardList<Node>::node_t,ForwardList<Node>::value_t,nodeType>::deleteBack(head,tail);
}

template< typename Node>  template <int nodeType>
void ForwardList<Node>::__deleteFront__(
        typename ForwardList<Node>::node_t ** head,
        typename ForwardList<Node>::node_t ** tail){

    ListHelper<ForwardList<Node>::node_t,ForwardList<Node>::value_t,nodeType>::deleteFront(head,tail);
}

template< typename Node>  template <int nodeType>
void ForwardList<Node>::__search__(
        typename ForwardList<Node>::node_t ** head,
        typename ForwardList<Node>::node_t ** tail,
        typename ForwardList<Node>::value_t position){

    ListHelper<ForwardList<Node>::node_t,ForwardList<Node>::value_t,nodeType>::search(head,tail,position);
}

template< typename Node>  template <int nodeType>
void ForwardList<Node>::__insert__(
        typename ForwardList<Node>::node_t ** head,
        typename ForwardList<Node>::node_t ** tail,
        typename ForwardList<Node>::value_t position,
        typename ForwardList<Node>::value_t element){

    ListHelper<ForwardList<Node>::node_t,ForwardList<Node>::value_t,nodeType>::insert(head,tail,position,element);
}


typedef ForwardListNode<int> forward_node_t;
typedef ForwardList<forward_node_t> list_t;
typedef list_t::ForwardIterator iterator_t;

typedef DoubleListNode<int> double_node_t;
typedef ForwardList<double_node_t> dlist_t;

typedef CircularListNode<int> circular_node_t;
typedef ForwardList<circular_node_t> clist_t;

int main (int, char *[]){
    list_t list;
    list << 10 << 12 << 3;

    dlist_t dlist;
    dlist << 10 << 12 << 3;

    clist_t clist;
    clist << 15 << 13 << 10;



    return 0;
}
