#include<iostream>
using namespace std;

template<class T>
class Node  
{  
    public: 
    T data;  
    Node<T> *next;  

    public:
    Node();
    Node(T value);
    void setNext(Node<T> *n);
    void setData( T value);
}; 

template<class T>
class SLL {
	
	private:
		int size;
		Node<T> *head;
		
	public:
		SLL();		
		void Insert_at_Head(T);//Insert at Start 
		void Insert_at_End(T);//Insert at last
		void Insert_Before(T, T);//insert before a specific data
		void Insert_After(T, T);//Insert after a specific data
	    void Insert_at(int,T);//Insert at a specific position
	    void Delete_from_End();//Delete Last node
	    T Delete_from_front();//Delete first node from front 
	    void Delete_at(int);// Detele at a specific Position
	    void Delete_before(T);// Delete the node before the data
	    void Delete_After(T);//Delete the node after the data 
	    void Display();//Displays the list
		T& getFrontValue();
        T getEndValue();
	    int Search_data(T);//search the data and return the node number if present, else return -1.  
	    T Length_of_list();//counts the number of nodes in list
		bool isFull();
		bool isEmpty();
        void removeDuplicates();
	    void swapNode(int , int);
	    void sort();
		Node<T> * Reverse();
		int count(T value);
};
template< class T>
Node<T>::Node() {

	next = 0;
}
template<class T>
Node<T>::Node(T value)
{
	data = value ;
	next = 0 ;
}
template<class T>
void Node<T>::setData(T value)
{
		data = value ;
}
template<class T>
void Node<T>::setNext(Node<T> *node)
{
	next = node;
}


template < class T>
SLL<T>::SLL(){

	size = 0 ;
	head = 0;
}

template< class T>
void SLL<T>::Insert_at_Head(T value)
{
	Node<T> *newNode = new Node<T>(value);
	
	if(head == 0)
	head = newNode;
	else
	{
		newNode->next = head;
		head = newNode;
	}	
	size++;
}
template<class T>
T SLL<T>::getEndValue()
{
    Node<T> *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    return temp->data;
}
template < class T>
void SLL<T>::Insert_at_End(T value)
{
	
	if(head == 0)
	head = new Node<T>(value);
	else
	{
		Node<T> *temp = head;
		while(temp->next)
		{
			temp = temp->next ;
		}
		temp->next = new Node<T>(value);
	}
	size++;
}
template<class T>
bool SLL<T>::isEmpty()
{
	return size == 0;
}
template<class T>
bool SLL<T>::isFull()
{
	return (new Node<T>()) == nullptr;
}
template<class T>
T& SLL<T>::getFrontValue()
{
	return head->data;
}
template < class T>
void SLL<T>::Insert_Before(T matchData, T value)
{
	Node<T> *newNode = new Node<T>(value);
	Node<T> *temp = head;
	if(size == 1)
	{
		if(temp->data == matchData)
		{
			temp->next = head;
			head = temp;
			size++;
			return;
		}
		else
		{
			 cout<<"There is no value like "<<value<<endl;
			 return;
		}	
	}
	
	while( temp != 0 )
	{

		if(temp->next->data == matchData )
		{
			newNode->next = temp->next;
			temp->next = newNode;
			size++;
			return;
		}
		
		temp = temp->next;
	}

	cout<<"There is no value like "<<value<<endl;
}
template < class T>
void SLL<T>::Insert_After(T matchData, T value)
{
	Node<T> *newNode = new  Node<T>(value);
	Node<T> *temp = head;

	while( temp != 0)
	{
		if(temp->data == matchData )
		{
			newNode->next = temp->next;
			temp->next = newNode;
			size++;
			break;
		}
		temp = temp->next;
	}
}
template < class T>
void SLL<T>::Insert_at(int position,T value)
{
	Node<T> *newNode = new Node<T>(value);
	if(position > size -1)
	{
		cout<<"Invalid positions"<<endl;
	}
	else if(head == 0 & position > 1)
	{
		head = newNode;
		cout<<"There is no node available at "<<position<<endl;
	}
	else if ( position == 0)
	{
		newNode->next = head;
		head = newNode;
		size++;
	}
	else
	{
		
		Node<T> *temp = head;
		
		for(int count = 0 ; count < position -1 ; count++)
		{
			temp = temp->next;
		}
		
		newNode->next = temp->next;
		temp->next = newNode;
		size++;
	}
}
template< class T>
void SLL<T>::Delete_from_End()
{
	Node<T> *current = head;
	Node<T> *prevNode = head;
	
	current = current->next;
	
	while( current->next )
	{
		prevNode = prevNode->next;
		current = current->next;
	}
	
	prevNode->next = 0;
	size--;
	
}

template < class T>
T SLL<T>::Delete_from_front()
{
	if(head == 0){
	cout<<"There is no node to delete"<<endl;
	return 0;
	}
	else 
	{
		T temp = head->data;
		Node<T> *newNode = head->next;
		head = newNode;
		size--;
		return temp;
	}
}
template < class T>
void SLL<T>::Delete_at(int position)
{
	if(head == 0)
	cout<<"There is no node to delete"<<endl;
	else if(position > size -1)
	cout<<"There is no node available at "<<position<<endl;
	else if (position == 0) 
		Delete_from_front();
	else
	{
		Node<T> *temp = head;	
		for(int count = 0 ; count < position -1 ; count++)		
			temp = temp->next;	
 		temp->next = temp->next->next;
		size--;
	}
}

template < class T>
void SLL<T>::Delete_before(T matchData)
{
	Node<T> *temp = head;

	if(head == 0)
	cout<<"There is no node to delete"<<endl;
	else if(size == 1)
	cout<<"There is no data to delete before "<<matchData<<endl;
	else if (size == 2)
	{
		if(temp->next->data == matchData)
		{
			head = temp->next;
			size--;
		}
		else
		cout<<"There is no node available at "<<matchData<<endl;
			
	}
	else
	{
		while( temp != 0)
		{
			if(temp->next->next->data == matchData )
			{
				temp->next = temp->next->next;
				size--;
				break;
			}	
			temp = temp->next;
		}
	}
}
template < class T>
void SLL<T>::Delete_After(T matchData)
{
		Node<T> *temp = head;
		while( temp != 0)
		{
			if(temp->data == matchData )
			{

				temp->next = temp->next->next;
				size--;
				break;
			}
			
			temp = temp->next;
		}

		cout<<"There is no node available at "<<matchData<<endl;

}
template <class T>
void SLL<T>::Display()
{
	Node<T> *temp = head;

	while (temp != 0)
	{
		cout<< temp->data <<" ,";
		temp =  temp->next;
	}

	cout<<endl;
}
template<class T>
T SLL<T>::Length_of_list()
{
	return size;
}
template<class T>
int SLL<T>::Search_data(T value)
{
	int count = 0 ;
	Node<T> *temp = head;

	while(temp != 0 )
	{
		if(temp->data == value)
		{
			return count;			
		}
		temp =  temp->next;
		count++;
	}
	return -1;
}
template<class T>
void SLL<T>::removeDuplicates()
{
	if(head==0)
	return;
	else
	{
		int count = 0;
		
		Node<T> *temp = head;
		SLL<T> *mark = new SLL<T>();
		
		while(temp != 0)
		{
			if(mark->Search_data(temp->data) != -1)
			Delete_at(count);
			else
			{
				mark->Insert_at_End(temp->data);
			}
			count++;
			temp =temp->next;
		}
	}
}

template<class T>
void SLL<T>::swapNode(int x , int y )
{
    if( ( x < 0  && y >= size ) || ( x == y ) || ( x > y ))
    return;

    Node<T> *prevX , *prevY  , *nextY , *p ;
    if( x ==  y-1)
    {
    	p = head;
        Node<T> *Px , *Py ;
        for(int i = 0 ; i < x  ; i++)
        {
            prevX = p;
            p = p->next;
        }
        Px = p;
        p = head;
        for(int i = 0 ; i < y  ; i++)
        {
            p = p->next;
        }

        Py = p;
		prevX->next = Py;
		Px->next = Py->next;
		Py->next = Px;
	}
    else if(x == 0 && y < size -1)
    {
        p = head;
        for(int i = 0 ; i < y  ; i++)
        {
            prevY = p;
            p = p->next;
        }
        nextY = p->next;
        prevY->next = head;
        p->next = head->next;
        head->next = nextY;
        head = p;
    }
    else if(x ==0 && y == size -1)
    {
        p = head;
        for(int i = 0 ; i < y  ; i++)
        {
            prevY = p;
            p = p->next;
        }
        prevY->next = head;
        p->next = head->next;
        head->next = 0;
        head = p;
    }
    else if( x > 0 && y == size -1)
    {
        p = head;
        Node<T> *Px , *Py;

        for(int i = 0 ; i < x  ; i++)
        {
            prevX = p;
            p = p->next;
        }
        Px = p;
        p = head;
        for(int i = 0 ; i < y  ; i++)
        {
            prevY = p;
            p = p->next;
        }
        Py = p;

        Py->next = Px->next;
        prevX->next = Py;
        prevY->next = Px;
        Px->next = 0;
    }
    else if( x > 0 && y < size -1)
    {
        p = head;
        Node<T> *Px , *Py , *NextY;

        for(int i = 0 ; i < x  ; i++)
        {
            prevX = p;
            p = p->next;
        }
        Px = p;
        p = head;
        for(int i = 0 ; i < y  ; i++)
        {
            prevY = p;
            p = p->next;
        }
        Py = p;
        NextY = Py->next;
        Py->next = Px->next;
        prevX->next = Py;
        prevY->next = Px;
        Px->next = NextY;
        prevY->next = Px;
    }
	
}
template< class T>
void SLL<T>::sort()
{
	if(head == 0)
	return;
	else
	{
		int i = 0 ;
		int j  ;
		Node<T> *temp1 = head;
		Node<T> *temp2 ;
		while( temp1 != 0 && i < size )
		{
			temp2 = head;
			j = 0;
			while( j < size - i  )
			{
				if(temp2->next == 0)
				break;
				
				if( (temp2->data ) > (temp2->next->data))
					j ++; // swapNode(temp2->data);
				else
				temp2 = temp2->next;
				j++;
			}
			temp1 = temp1->next;
			i++;
		}
		
	}
}
template<class T>
Node<T> * SLL<T>::Reverse()
{
	if(head == 0 )
	{
		return 0;
	}
	
	Node<T> * p = head;
	Node<T> *q = p->next;
	
	if(q == 0)
	return 0;
	head  = q;
	q = Reverse();
	
	p->next->next = p;
	p->next = 0;
	
	return q;
}
template<class T>
int SLL<T>::count(T value)
{
	Node<T> *temp = head;
	int count_var  = 0;
	while(temp)
	{
		if(temp->data == value)
		 count_var++;
		 
		 temp = temp->next;
	}
	
	return count_var;
}
int main()
{

}