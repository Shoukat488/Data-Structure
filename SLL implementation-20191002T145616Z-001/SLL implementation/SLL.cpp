#include "SLL.h"

SLL::SLL()
:head(0)
, size(0)

{
	head = new Node;
}

SLL::SLL(int, Node*){
	
}

void SLL::Insert_at_Head(int x){//Insert at Start
 Node *n = new Node(x);
 n -> next = head;
 head = n;
 size++;
}
void SLL::Insert_at_End(int x){//Insert at last

	Node *current = head;
	
	if (!size) {
		head = new Node(x);
		size++;
		return;
	}
		
	
	
	while (current -> next) current = current -> next;
	
	current -> next = new Node(x);
	
	size++;

}
void SLL::Insert_Before(int x, int y){//insert before a specific data
	Node *current = head;
	while (current -> next && current -> next -> data != y)
		current = current -> next;
	Node *n = new Node(x);
	n -> next = current -> next;
	current -> next = n;
	size++; 
}
void SLL::Insert_After(int x, int y){//Insert after a specific data
	Node *current = head;
	while (current -> next && current -> data != y)
		current = current -> next;
	Node *n = new Node(x);
	n -> next = current -> next;
	current -> next = n;
	size++; 

}
void SLL::Insert_at(int x, int y){//Insert at a specific position

	Node *current = head;
	for (int i = 0; i < y - 1; i++) 
		current = current -> next;
	Node *n = new Node(x);
	n -> next = current -> next;
	current -> next = n;
	size++; 

}
void SLL::Delete_from_End(){//Delete Last node
	Node *current = head;
	while (current -> next -> next) current = current -> next;
	current -> next = 0;
	size--;
}
void SLL::Delete_from_front(){//Delete first node from front 
	head = head -> next;
	size--;
}
void SLL::Delete_at(int y){// Detele at a specific Position
	Node *current = head;
	for (int i = 0; i < y - 2; i++)
		current = current -> next;
	current -> next = current -> next -> next;
	size--; 
}
void SLL::Delete_before(int x){// Delete the node before the data
	Node *current = head;
	while (current -> next && current -> next -> data != x)
		current = current -> next;
	current -> next = current -> next -> next;
	size--;
}
void SLL::Delete_After(int x){//Delete the node after the data 
	Node *current = head;
	while (current -> next && current -> data != x)
		current = current -> next;
	current -> next = current -> next -> next;
	size--;
}
void SLL::Display(){//Displays the list
	Node *current = head;
	cout << "{";
	for (int i = 0; i < size; i++) {
		cout << current -> data;
		if (i != size - 1) cout << ", ";
		current = current -> next;
	} cout << "}" << endl;

}
int SLL::Search_data(int x){//search the data and return the node number if present, else return -1.  
	Node *current = head;
	int index = 0;
	while (current) {
		if (current -> data == x) return index;
		current = current -> next;
		index++;
	}
	return -1;
}
int SLL::Length_of_list(){//counts the number of nodes in list	
	return size;
}
