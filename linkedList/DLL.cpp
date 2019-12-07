#include<iostream>

using namespace std;

template <class T>
class DNode ;

template <class T>
class DLL ;

template <class T>
class DNode{

    public :
    T Data;
    DNode<T> *next;
    DNode<T> *prev;

    public:

    DNode();
    DNode(T Data);
    void  setNext(DNode *node);
    void setPrev(DNode *node);
    DNode<T> getNext();
    DNode<T> getPrev();

};

template<class T>
class DLL{
    private:
    DNode<T> * head;
    DNode<T> * tail;
    int size;
    public:
    DLL();
    void insertAtFront(T value);
    void insertAtEnd(T value);
    void insertAt(int position, T value);
    void deleteFromFront();
    void deleteFromEnd();
    void deleteAt(int position);
    void printInForward();
    void printInReverse();
	int getLength();
	int search(T value);
	void sort();
    void swapingNode(int index);
};

template<class T>
DNode<T>::DNode(): prev(0), next(0) {}

template<class T>
DNode<T>::DNode(T value) : Data(value), prev(0) , next(0) {}

template<class T>
void DNode<T>::setNext(DNode *node)
{
    next = node;
}

template<class T>
void DNode<T>::setPrev(DNode *node)
{
    prev = node;
}

template<class T>
DNode<T> DNode<T>::getNext(){ return next ;}

template<class T>
DNode<T> DNode<T>::getPrev(){ return prev ;}

template<class T>
DLL<T>::DLL()
{
    head = 0;
    tail = 0;
    size = 0;
}

template<class T>
void DLL<T>::printInForward()
{
    DNode<T> *temp = head;
    
    while(temp != tail)
    {
        cout<< temp->Data<<" , ";
        temp = temp->next;
    }
    cout<< temp->Data<<" , ";
    cout<<endl;
}
template<class T>
void DLL<T>::printInReverse()
{
	DNode<T> *temp = tail;
	
	while(temp != head)
	{
		cout<<temp->Data<<" , ";
		temp = temp->prev;
	}
		cout<<temp->Data<<" , ";
		cout<<endl;
}
template<class T>
void DLL<T>::insertAtFront(T value)
{
    DNode<T> *newNode = new DNode<T>(value);

    if(size==0)
    {
        head = newNode;
        tail = newNode;

        newNode->next  = tail;
        newNode->prev = tail;        
    }
    else
    {

        DNode<T> *temp = head;
        while (temp != tail)
        {
            temp = temp->next;
        }

        newNode->next = head;
        newNode->prev = head->prev;
        head->prev = newNode;
        head = newNode;
        temp->next = head;
    }
    size++;
    
}
template<class T>
void DLL<T>::insertAtEnd(T value)
{
	DNode<T> *newNode = new DNode<T>(value);
	if(head == 0)
	{
		head = newNode;
        tail = newNode;

        newNode->next  = tail;
        newNode->prev = tail;	
	}
	else
	{
		newNode->next = tail->next;
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	size++;
}
template<class T>
void DLL<T>::insertAt(int pos, T value)
{
	if(size == 0 && pos > 0)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	else if(pos == 0)
	{
		insertAtFront(value);
	}
	else if(pos == size -1 )
	{
		insertAtEnd(value);
	}
	else
	{
		DNode<T> *temp = head;
		
		for(int i = 0 ; i < pos ; i++)
		{
			temp = temp->next;
		}
		
		DNode<T> *newNode = new DNode<T>(value);
		
		newNode->next = temp;
		newNode->prev = temp->prev;
		temp->prev->next = newNode;
		temp->prev = newNode;
		
		size++;
	}
}
template<class T>
void DLL<T>::deleteFromFront()
{
	if(head==0)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	else
	{
		head->next->prev = head->prev ;
		head = head->next;
		tail->next = head;
		size--;
	}
}
template<class T>
void DLL<T>::deleteFromEnd()
{
	if(head == 0)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	else
	{
		tail->prev->next = head ;
		tail = tail->prev;
		head->prev = tail;
		size--;
	}
}
template<class T>
void DLL<T>::deleteAt(int pos)
{
	if(head == 0)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	else if(pos == 0)
	deleteFromFront();
	else if(pos == size - 1)
	deleteFromEnd();
	else
	{
		DNode<T> *temp = head;
		
		for(int i = 0 ; i < pos ; i ++)
		temp = temp->next;
		
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		size--;
	}
}
template<class T>
int DLL<T>::getLength() {
	return size;
}

template<class T>
int DLL<T>::search(T value)
{
	if(head == 0)
	{
		cout<<"List is empty"<<endl;
		return -1;
	}
	else
	{
		DNode<T> *temp = head;
		int count = 0;
		while(temp != tail )
		{
			if(temp->Data == value)
			return count;
			
			temp = temp->next;
			count++;
		}
		
		if(temp->Data = value)
			return count;
	}
	
	cout<<"Not found"<<endl;
}
template<class T>
void DLL<T>::swapingNode(int index)
{
    DNode<T> *p = head;
	if(size < 2)
	return;
    if(index == 0 && size == 2)
    {
    	DNode<T> *temp = head;
		head = tail;
		tail = temp;
		head->next = head->prev;
		head->prev = 0;
		tail->prev = head;
		tail->next = 0;
    }
	else if( index == 0 && size > 2)
	{
		DNode<T> *temp = head->next;
		head->next = head->next->next;
		head->next->prev = head;
		temp->next = head;
		temp->prev = 0;
		head = temp;
	}
	else if(index > 0)
	{
		DNode<T> *temp = head;
		
		for(int i = 0 ; i < index  ; i ++)
		temp = temp->next;

		DNode<T> *nextNode = temp->next;
		if(temp== tail)
		{
			return;
		}
		if(nextNode == tail)
		{
			nextNode->next = temp;
			nextNode->prev = temp->prev;
			temp->prev->next = nextNode;
			temp->prev = nextNode;
			temp->next = 0;
			tail = temp;
		}
		else
		{
			DNode<T>  * nextToNextNode = nextNode->next;
			DNode<T>  * prevNode = temp->prev;
			temp->next = nextToNextNode;
			nextToNextNode->prev = temp;
			prevNode->next = nextNode;
			nextNode->prev = prevNode;
			nextNode->next = temp;
			temp->prev = nextNode;
			
		}
	
	}
}
template<class T>
void DLL<T>::sort()
{
	if(size==1 || size == 0)
	return;
	if(size == 2)
	{
		swapingNode(0);
	}
	else
	{
		DNode<T> *temp = head;
		int i = 0 ;
		while(temp->next)
		{
			DNode<T> *inner = temp;
			 int j = i;
			while(inner->next)
			{
				if((inner->Data) > (inner->next->Data))
				swapingNode(j);
				inner = inner->next;
				j++;
			}
			temp = temp->next;
			i++;
		}
	}
	
}
int main()
{
    DLL<int> list ;
    list.insertAtEnd(1);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.insertAtEnd(9);
    list.insertAtEnd(8);
    list.insertAtEnd(5);
    list.insertAtEnd(9);
    list.insertAtEnd(8);
    list.printInForward();
	// list->swapingNode(4);
	list.sort();
	list.printInForward();
}