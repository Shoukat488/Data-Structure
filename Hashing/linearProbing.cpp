#include<bits/stdc++.h> 
using namespace std; 

template<typename K, typename V> 

class HashStore 
{ 
	public: 
	V value; 
	K key; 
	
	HashStore(K key, V value) 
	{ 
		this->value = value; 
		this->key = key; 
	} 
}; 

template<typename K, typename V> 

class HashTable 
{ 
	HashStore<K,V> **arr; 
	int capacity; 
	int size; 
	HashStore<K,V> *dummy; 

	public: 
	HashTable() 
	{ 
		capacity = 20; 
		size=0; 
		arr = new HashStore<K,V>*[capacity]; 
		
		for(int i=0 ; i < capacity ; i++) 
			arr[i] = NULL; 
		
		dummy = new HashStore<K,V>(-1, -1); 
	} 
	int hashCode(K key) 
	{ 
		return key % capacity; 
	} 
	
	void insertNode(K key, V value) 
	{ 
		HashStore<K,V> *temp = new HashStore<K,V>(key, value); 
		
		int hashIndex = hashCode(key); 
		
		while(arr[hashIndex] != NULL && arr[hashIndex]->key != key 
			&& arr[hashIndex]->key != -1) 
		{ 
			hashIndex++; 
			hashIndex %= capacity; 
		} 
		
		if(arr[hashIndex] == NULL || arr[hashIndex]->key == -1) 
			size++; 
		arr[hashIndex] = temp; 
	} 
	
	V deleteNode(int key) 
	{ 
		int hashIndex = hashCode(key); 
		
		while(arr[hashIndex] != NULL) 
		{ 
			if(arr[hashIndex]->key == key) 
			{ 
				HashStore<K,V> *temp = arr[hashIndex]; 
				
				arr[hashIndex] = dummy; 
				
				size--; 
				return temp->value; 
			} 
			hashIndex++; 
			hashIndex %= capacity; 

		} 
		return 0; 
	} 
	V get(int key) 
	{ 
		int hashIndex = hashCode(key); 
		int counter=0; 
		while(arr[hashIndex] != NULL) 
		{ int counter = 0; 
			if(counter++>capacity) //to avoid infinite loop 
				return 0;		 
			if(arr[hashIndex]->key == key) 
				return arr[hashIndex]->value; 
			hashIndex++; 
			hashIndex %= capacity; 
		} 
		
		return 0; 
	} 
	int sizeofMap() 
	{ 
		return size; 
	} 
	bool isEmpty() 
	{ 
		return size == 0; 
	} 
	void display() 
	{ 
		for(int i=0 ; i<capacity ; i++) 
		{ 
			if(arr[i] != NULL && arr[i]->key != -1) 
				cout << "key = " << arr[i]->key 
					<<" value = "<< arr[i]->value << endl; 
		} 
	} 
}; 
int main() 
{ 
	HashTable<int, int> *h = new HashTable<int, int>; 
	h->insertNode(1,1); 
	h->insertNode(2,2); 
	h->insertNode(2,3); 
	h->display(); 
	cout << h->sizeofMap() <<endl; 
	cout << h->deleteNode(2) << endl; 
	cout << h->sizeofMap() <<endl; 
	cout << h->isEmpty() << endl; 
	cout << h->get(2); 

	return 0; 
} 
