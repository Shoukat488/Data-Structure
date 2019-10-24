#include<iostream>

using namespace std;

template<class T>
class Node {

    private:
    T Data;
    Node<T> *next;
    public:
    Node();
    Node(int data, Node<T> *n) ;
    Node(const Node<T>& rhs) ;
    void setData(int data);
    void setNext(Node<T> *n) ;
    int getData() ;
    Node<T>* getNext() ;
    friend class SinglyLinkedList;
    ~Node();
};
