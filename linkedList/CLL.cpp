#include<iostream>

using namespace std;

template<class T>
class CLL;

template<class T>
class Node;

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
class CLL {
	
	private:
		int size;
		Node<T> *head;
		
	public:
		CLL();		
		void Insert_at_Head(T);//Insert at Start 
		void Insert_at_End(T);//Insert at last
		void Insert_Before(T, T);//insert before a specific data
		void Insert_After(T, T);//Insert after a specific data
	    void Insert_at(int,T);//Insert at a specific position
	    void Delete_from_End();//Delete Last node
	    void Delete_from_front();//Delete first node from front 
	    void Delete_at(int);// Detele at a specific Position
	    void Delete_before(T);// Delete the node before the data
	    void Delete_After(T);//Delete the node after the data 
	    void Display();//Displays the list
	    int Search_data(T);//search the data and return the node number if present, else return -1.  
	    T Length_of_list();//counts the number of nodes in list
	    void  evenFirst();
		bool isEmpty();
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
CLL<T>::CLL(){

	size = 0 ;
	head = 0;
}

template< class T>
void CLL<T>::Insert_at_Head(T value)
{
	Node<T> *newNode = new Node<T>(value);
	
	if(head == 0)
	{
		head = newNode;
		newNode->next = head;	
	}
	else
	{	
		Node<T> *temp = head;
		
		while(temp->next != head)
		temp = temp->next;

		newNode->next = head;
		head = newNode;
		temp->next = head;
	}
	size++;
}
template < class T>
void CLL<T>::Insert_at_End(T value)
{
	
	if(head == 0)
	{
		head = new Node<T>(value);
		head->next = head;	
	}
	else
	{
		Node<T> *temp = head;
		while(temp->next != head)
		{
			temp = temp->next ;
		}
		temp->next = new Node<T>(value);
		temp->next->next = head;
	}
	size++;
}
template < class T>
void CLL<T>::Insert_Before(T matchData, T value)
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
void CLL<T>::Insert_After(T matchData, T value)
{
	Node<T> *newNode = new  Node<T>(value);
	Node<T> *temp = head;

	while( temp != 0)
	{
		if(temp->data == matchData )
		{
			if(temp->next == head)
			{
					temp->next = newNode;
					newNode->next = head;
			}
			else
			{
				newNode->next = temp->next;
				temp->next = newNode;	
			}
			size++;
			return;
		}
		temp = temp->next;
	}
}
template < class T>
void CLL<T>::Insert_at(int position,T value)
{
	Node<T> *newNode = new Node<T>(value);
	if(position > size -1)
		cout<<"Invalid positions"<<endl;
	else if(head == 0 & position > 1)
		cout<<"There is no node available at "<<position<<endl;
	else if ( position == 0 )
	{
		if(head == 0)
		head = newNode;
		else
		Insert_at_Head(value);
	}
	else
	{	
		Node<T> *temp = head;
		
		for(int count = 0 ; count < position -1 ; count++)
		{
			temp = temp->next;
		}

		if(temp->next == head)
			Insert_at_End(value);
		else
		{
			newNode->next = temp->next;
			temp->next = newNode;
			size++;	
		}	
	}
}
template< class T>
void CLL<T>::Delete_from_End()
{
	if(head==0)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	Node<T> *current = head;
	if(current->next == head)	
	{
		head = 0;
		size--;
		return;
	}

	while( current->next->next != head)
		current = current->next;
	current->next = current->next->next;
	size--;
	
}

template < class T>
void CLL<T>::Delete_from_front()
{
	if(head == 0)
	{
		cout<<"There is no node to delete"<<endl;
		return;
	}

	if(size==1)
	{
		head = 0;
		size--;
		return;
	}

	Node<T> *temp = head;

	while (temp->next != head)
	temp = temp->next;
	
	head = head->next;
	temp->next = head;
	size--;
}
template < class T>
void CLL<T>::Delete_at(int position)
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
		if(temp->next == head)
			Delete_from_End();
		else
		{
			temp->next = temp->next->next;
			size--;
		}			
	}
}

template < class T>
void CLL<T>::Delete_before(T matchData)
{
	Node<T> *temp = head;

	if(head == 0)
	cout<<"There is no node to delete"<<endl;
	else if(size == 1)
	cout<<"There is no data to delete before "<<matchData<<endl;
	else if (size == 2)
	{
		if(temp->next->data == matchData)
			Delete_from_front();
		else
		cout<<"There is no node available at "<<matchData<<endl;
	}
	else
	{
		while( temp->next != head)
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
void CLL<T>::Delete_After(T matchData)
{
		Node<T> *temp = head;
		if(size==1)
		{
			head =  0;
			size--;
			return;
		}
		while( temp->next != head)
		{
			if(temp->data == matchData )
			{
				if(temp->next == head)
					Delete_from_front();
				else
				{
					temp->next = temp->next->next;
					size--;
				}
				return;
			}				
			temp = temp->next;
		}
		cout<<"There is no node available at "<<matchData<<endl;
}
template <class T>
void CLL<T>::Display()
{
	Node<T> *temp = head;
	if(size==0 )
	{
		cout<<"Null"<<endl;
		return;
	}
	while (temp->next != head)
	{
		cout<< temp->data <<" ,";
		temp =  temp->next;
	}
	cout<< temp->data <<" ,";
	cout<<endl;
}
template<class T>
T CLL<T>::Length_of_list()
{
	return size;
}
template<class T>
int CLL<T>::Search_data(T value)
{
	int count = 0 ;
	Node<T> *temp = head;
	if(!isEmpty())
	while(true )
	{
		if(temp->next == head)
		{
			if(temp->data == value)
			{
				return count;			
			}
			break;
		}

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
bool CLL<T>::isEmpty()
{
	return size == 0 ;
}
template<class T>
void CLL<T>::evenFirst()
{
	if(head==0 || size == 1)
	return;
	CLL<T> *temp = new CLL<T>(); 
	Node<T> *temp2 = head;
	do
	{
		if((temp2->data)%2 == 0 )
		temp->Insert_at_End(temp2->data);
		temp2 = temp2->next;
	}while(temp2 != head);
	
	do
	{
		if((temp2->data)%2 != 0 )
		temp->Insert_at_End(temp2->data);
		temp2 = temp2->next;
	}while(temp2 != head);
	
	temp2 = head;
	Node<T> *tempList = temp->head;

	do
	{
		temp2->data = tempList->data;
		temp2 = temp2->next; 
		tempList = tempList->next;
	}while(tempList != temp->head);
	
}

int main()
{
    CLL<int> list;
    list.Insert_at_End(17);
    list.Insert_at_End(15);
    list.Insert_at_End(8);
    list.Insert_at_End(12);
    list.Insert_at_End(10);
    list.Insert_at_End(5);
    list.Insert_at_End(4);
    list.Insert_at_End(1);
    list.Insert_at_End(7);
    list.Insert_at_End(6);
	list.evenFirst();
	list.Display();
	
}