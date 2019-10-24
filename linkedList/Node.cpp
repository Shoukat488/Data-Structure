#include "Node.h"
#include "singlyLinkedList.h"

template<class T>
 Node<T>:: Node(): Data(0),next(0) {}
 template<class T>
 Node<T>::Node(int data, Node<T> *n) : Data(data) 
    {
        next = n;
    }
template<class T>
 Node<T>::Node(const Node<T>& rhs)
    {
        this->Data = rhs.Data;
        this->next = rhs.next;
    }
template<class T>    
 void Node<T>::setData(int data)
    {
        Data = data;
    }
template<class T>
 void Node<T>:: setNext(Node<T> *n)
    {
        next = n;
    }
template<class T>    
 int Node<T>:: getData()
    { return Data; }
template<class T>        
 Node<T>* Node<T>:: getNext()
    { return next; }
template<class T>        
Node<T>::~Node()
{
    if (next != 0)
        delete;
}