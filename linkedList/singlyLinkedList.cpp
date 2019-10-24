#include "singlyLinkedList.h"

template<class T>
SinglyLinkedList<T>::SinglyLinkedList() : size(0) , head (0) {}
template<class T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList& rhs)
{

}
template <class T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator = (const SinglyLinkedList<T> &rhs)
{

}
template <class T>
void SinglyLinkedList<T>::insertAtFront(const T &value)
{
    Node<T> *newNode = new Node<T>(value);

    if( head == 0 )
    head = newNode;
    else
    {
        newNode->next = head ;
    }
    

}