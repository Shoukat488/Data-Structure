#include<iostream>

using namespace std;

class HashStore{

    public:
    int data;
    string key;
	
    public:
    HashStore()
    {
		key = "";
    }
    HashStore( string key , int data)
    {
        this->data = data;
        this->key = key;
    }
    void set(string key , int data)
    {
    	this->data = data;
    	this->key = key;
	}
};

class HashTable {

    private:
    int size;
    int currentSize;
    HashStore **table ;

    public:
    HashTable(int size)
    {
        this->size = size;
        currentSize = 0;
        table = new HashStore*[size];
        for(int i = 0 ; i < size ; i++)
        table[i] = NULL ;
    }
    void put(string key , int data)
    {
        int hashedKey = hashKey(key);
        if(isOccupied(hashedKey))
        {
            int stopIndex = hashedKey;
            if(hashedKey == size -1)
            hashedKey = 0;
            hashedKey++;

            while (  hashedKey != (stopIndex) && isOccupied(hashedKey))
                hashedKey = (hashedKey+1)%size;
            
            if(!isOccupied(hashedKey))
            {
                currentSize++;
                table[hashedKey] = new HashStore(key , data);
            }
            else
                cout<<"Table is full ";
        }
        else if(!isFull())
        {
            currentSize++;
            table[hashedKey] = new HashStore(key , data);
        }
        else
                cout<<"Table is full ";
    }
    bool isOccupied(int key)
    {
    	if(key == size)
    	return false;
    	if(table[key]->key == "")
        return true;
        return false;
    }
    int hashKey(string key)
    {
        return ( key.length() % size);
    }
    bool isFull()
    {
        return currentSize == size -1 ;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout<<table[i]->data;
        }
        
    }
    int findKey(string key)    
    {
        int hashedKey = hashKey(key);
        if(table[hashedKey]->key != "" && table[hashedKey]->key == key) 
        return hashedKey;

        if(table[hashedKey]->key != "")
        {
            int stopIndex = hashedKey;
            if(hashedKey == size -1)
            hashedKey = 0;
            else
            hashedKey++;

            while ( table[hashedKey]->key != key && hashedKey != stopIndex)
            {
            
                hashedKey = (hashedKey+1)%size;
                
                if(table[hashedKey]->key == "")
                {
                    continue;
                }
            }
            
            if(table[hashedKey]->key == key)
            return hashedKey;
            else
            return -1;

        }
        else
        return -1;
    }
    int  get(string key)
    {
        int hashedKey = findKey(key);
        if(hashedKey != -1 )
        return table[hashedKey]->data;
        else
        return -1;
    }
};


int main()
{
    HashTable t(10);
    t.put( "43", 5);
    t.put( "61", 6);
    t.put( "12", 8);
    t.put( "43", 4);
    t.put( "54", 6);
    t.put( "54", 76);
    t.put( "65", 9);
    t.put( "67", 9);

    cout<<t.get("61");
    t.print();
}
