#include <iostream>
#include "Node.h"

using namespace std;

template<class T>
class SinglyLinkedList
{
private:
    Node<T> *head;
    int size;
public:
    SinglyLinkedList();
    SinglyLinkedList(const SinglyLinkedList<T> &rhs);
    SinglyLinkedList<T>& operator = ( const SinglyLinkedList<T> &rhs);
    void deleteList();
    void insertAtFront(const T &);
    void insertAtLast(const T &);
    void removeAtFront();
    void removeAtLast();
    void print() const;
    int getSize() const;
    ~SinglyLinkedList();
};
