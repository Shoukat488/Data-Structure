#include <bits/stdc++.h> 
using namespace std;
class UDSA;

class PriorityQueue{

	private:
	int size;
	int current;
	UDSA *queue;
	public:
	PriorityQueue(int size);
	void push(int data);
	int pop();
	int peek();
};
class UDSA{
	
	private:
		int size;
		int countint;
		int * Data;
	public:
	
	     UDSA(); // it is default constructor which assigns 0 to size and data
	     UDSA(int Size); //Construtor to intialize and to allocate memory for variable memebers;
		 UDSA(const UDSA& rhs); // copy constructor
	     ~UDSA();
	     int Size(); // it returns size of array
	     void ReSize(int nSize);
		 UDSA& operator = (const UDSA& rhs); // assignment operator overloading
		 int& operator [](int i); // it returns refence of of given element index
		 const int& operator[](int i) const; // it just return value at given index
		 bool find(int element); // 
		 void printArray();
		 int get(int index);
		 void set(int element ,int index);
		 friend ifstream& operator >> ( ifstream& infile , UDSA& rhs);
		 friend ofstream& operator << ( ofstream& outfile , UDSA& rhs);
};

PriorityQueue::PriorityQueue(int size)
{
	queue = new UDSA(size);
	current = -1;
	this->size = size;
}
void PriorityQueue::push(int data)
{
	queue->set(data, ++current);

    for(int i = 1 ; i < size ; i++)
    {
        int temp = queue->get(i);
        int j = i;
        for ( ; j > 0 && queue->get(j-1) < temp; j--)
        {
            queue->set(queue->get(j-1) , j );
        }
        
        queue->set(temp , j);
    }
}
int PriorityQueue::pop()
{
	int Temp = queue->get(0);
	queue->set(0,0);
	current--;

    for(int i = 1 ; i < size ; i++)
    {
        int temp = queue->get(i);
        int j = i;
        for ( ; j > 0 && queue->get(j-1) < temp; j--)
        {
            queue->set(queue->get(j-1) , j );
        }
        
        queue->set(temp , j);
    }

	return Temp;
}
int PriorityQueue::peek()
{
	return queue->get(0);
}
UDSA::UDSA () 
	{
		size=0;
		countint = 0 ;
	}
	
// Construtor to intialize and to
// allocate memory for variable memebers;
UDSA::UDSA (int Size) 
	{
		Data=new int[Size];
		size=Size;
		countint = 0;
		for(int i = 0 ; i < size ; i++)
		Data[i] = 0;
	}

// copy constructor
UDSA::UDSA(const UDSA & rhs){
			
			 this->size= size;
			 this->countint =  rhs.countint;
			 this->Data= new int[size];
			 memcpy(this->Data,rhs.Data,(sizeof(int)*size));
}
int UDSA::get(int index)
{
	return Data[index];
}
void UDSA::set(int element ,int index)
{
	Data[index] = element;
}
// assignment operator overloading function
UDSA& UDSA:: operator=( const UDSA & rhs)
{
    if (this  != &rhs)
        {
        int s=rhs.size; 
        this->size=s;
		this->countint =  rhs.countint;
        this->Data= new int[s];
        memcpy(this->Data,rhs.Data, sizeof(int)*s);
        }
	return (*this);
         
}

// it returns refence of of given element index
int& UDSA::operator [] (int i){   
   		
   			if(i < 0 && i >= size)
			   cout<<"Array is full"<<endl;
			else
   			return (*(Data+i));
}

// it just return value at given index
const int& UDSA::operator [] (int i) const {   
   		
   			if(i < 0 && i >= size)
			   cout<<"Array is full"<<endl;
			else
   			return (*(Data+i));
}

// it returns size of array
int UDSA::Size ()
	{
		return size;
	}
	
// resizes the array;
void UDSA::ReSize(int nSize)
{
	if (size != nSize )  
			{
				int * temp= new int[size];
			 	
			    for(int i=0; i<size ; i++)
			    	temp[i]= *(Data+i);

			    delete[] Data;
			    Data=0;
			    
			    Data = new int[nSize];
			    memset(this->Data, 0, sizeof(int)*nSize);

  				for(int i=0; i<size ; i++)
			    	*(Data+i)=temp[i];

			    size= nSize;
			    delete [] temp;
			    temp=0;
  	
				
			} 		
}

//Destructor 
// It wipe out the all data
UDSA::~UDSA(){

 if (Data != 0)
 {
 	delete [] Data;
 	Data=0;
 	size=0;
	countint = 0 ;
 }
}
	

// it display all the intacters in array on console
void UDSA::printArray()
{
	for(int i = 0 ; i < countint -1 ; i ++)
		cout<< * ( Data + i ) ;
	cout<<endl;
}
// it gets string from input file
ifstream& operator >> (ifstream& infile, UDSA & rhs)
{
	// int n = rhs.Size();
	// while(!infile.eof())
	// 	infile.get( rhs.Data[ rhs.countint++ ] );
		
    return infile;
}

// it prints the resulted string in the output file
ofstream& operator << (ofstream& outfile, UDSA & rhs)
{
	// int n = rhs.Size();
	// int count = 0 ;
	// for(int i = 0 ; i < rhs.countint -1 ; i++)
	// 	outfile << rhs.Data[ count++ ] ;

    return outfile;
}

// it returns true if intacter is found on the given index
bool UDSA::find(int element)
{
	for(int i = 0 ; i < size ; i ++)
	{
		if(element == Data[i])
		return true;
	}
	
	return false;
}
int main()
{
	PriorityQueue p(10);
	p.push(4);
	p.push(10);
	p.push(5);
	p.push(53);
	cout<<p.pop()<<endl;
	cout<<p.pop()<<endl;
	cout<<p.pop()<<endl;
	cout<<p.pop()<<endl;
}
