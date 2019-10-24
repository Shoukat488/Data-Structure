/************************************************************************
* This program gets the string from the file and save the string into   *
* DynamicSafeArray. The UniqueCharacters class replace the repeating    *
* characters with "-" and then save the output into the file.			*
*************************************************************************/

#include <bits/stdc++.h> 

using namespace std;


//-------------------------------------------------------------------//

//***********Declaration of  classes and their memebers**************//

//-------------------------------------------------------------------//

/************ Declaring class members of index bound exception*********/

class ArrayBoundException
{

public:
	ArrayBoundException();
	~ArrayBoundException();

	virtual const char* what() const throw();
};

/********* Declaring class members of lower index exception *******/

class LowerIndexException : public ArrayBoundException
{
public:
	LowerIndexException();
	~LowerIndexException();
	virtual const char* what() const throw();
} lowerBound;


/**************** Declaring class members of upper index exception*********************/
// its mainly purpose is to handle upper bound exception in arrays
class UppderIndexException : public ArrayBoundException
{
public:
	UppderIndexException();
	~UppderIndexException();
	virtual const char* what() const throw();
} upperBound;


/******************* Declaration of class members of Dynamic Safe Array**************/
class DynamicSafeArray{
	
	private:
		int size;
		int countChar;
		char * Data;
	public:
	
	     DynamicSafeArray(); // it is default constructor which assigns 0 to size and data
	     DynamicSafeArray(int Size); //Construtor to intialize and to allocate memory for variable memebers;
		 DynamicSafeArray(const DynamicSafeArray& rhs); // copy constructor
	     ~DynamicSafeArray();
	     int Size(); // it returns size of array
	     void ReSize(int nSize);
		 DynamicSafeArray& operator = (const DynamicSafeArray& rhs); // assignment operator overloading
		 char& operator [](int i); // it returns refence of of given element index
		 const char& operator[](int i) const; // it just return value at given index
		 bool find(char element); // 
		 void printArray();
		 int getCountChar();
		 void incCountChar();
		 friend ifstream& operator >> ( ifstream& infile , DynamicSafeArray& rhs);
		 friend ofstream& operator << ( ofstream& outfile , DynamicSafeArray& rhs);
};

/******************* Declaration of class members of UniqueCharacters**************/
// it is used to remove repeating characters and
// to place "-" on repeating places

class UniqueCharacters {

	public:
		UniqueCharacters();
		~UniqueCharacters();
		void makeItUnique(DynamicSafeArray & array);
};


//-------------------------------------------------------------------------------------------------//
//*************************************************************************************************//
//..............................Definitions of all the declared classes............................//
//*************************************************************************************************//
//-------------------------------------------------------------------------------------------------//


//************** Defining class members of index bound exception **************//

//constructor
ArrayBoundException::ArrayBoundException(){}

// Destructor
ArrayBoundException::~ArrayBoundException(){}

// it throws exception of 
// array bound when it is thrown by programmer

const char* ArrayBoundException::what() const throw() 
{ return "Array out of bound"; }

//************ Defining class members of upper index exception ************//

//default constructor
UppderIndexException::UppderIndexException(){}

//destructor
UppderIndexException::~UppderIndexException(){}

// it throws exception of upper
// bound when it is thrown by programmer
const char* UppderIndexException::what() const throw()
{ return "Upper index exception"; } // returns message

//*********** Defining class members of lower index exception *************//

//default constructor
LowerIndexException::LowerIndexException(){}

//destructor
LowerIndexException::~LowerIndexException(){}

// it throws exception of upper
// bound when it is thrown by programmer
const char* LowerIndexException::what() const throw()
{ return "Lower index exception"; }// returns message

//************ Defining class members of Dynamic Safe Array ****************//

// it is default constructor 
// which assigns 0 to size and data
DynamicSafeArray::DynamicSafeArray () 
	{
		size=0;
		countChar = 0 ;
	}
	
// Construtor to intialize and to
// allocate memory for variable memebers;
DynamicSafeArray::DynamicSafeArray (int Size) 
	{
		Data=new char[Size];
		size=Size;
		countChar = 0;
	}

// copy constructor
DynamicSafeArray::DynamicSafeArray(const DynamicSafeArray & rhs){
			
			 this->size= size;
			 this->countChar =  rhs.countChar;
			 this->Data= new char[size];
			 memcpy(this->Data,rhs.Data,(sizeof(char)*size));
}

// assignment operator overloading function
DynamicSafeArray& DynamicSafeArray:: operator=( const DynamicSafeArray & rhs)
{
    if (this  != &rhs)
        {
        int s=rhs.size; 
        this->size=s;
		this->countChar =  rhs.countChar;
        this->Data= new char[s];
        memcpy(this->Data,rhs.Data, sizeof(char)*s);
        }
	return (*this);
         
}

// it returns refence of of given element index
char& DynamicSafeArray::operator [] (int i){   
   		
   			if(i < 0)
   			throw lowerBound;
   			else if(i > size)
   			throw upperBound;		
   			else
   			 return (*(Data+i));
}

// it just return value at given index
const char& DynamicSafeArray::operator [] (int i) const {   
   		
   			if(i < 0)
   			throw lowerBound; 
   			else if(i > size)
   			throw upperBound;
   			else
   			return (*(Data+i));
}

// it returns size of array
int DynamicSafeArray::Size ()
	{
		return size;
	}
	
// resizes the array;
void DynamicSafeArray::ReSize(int nSize)
{
	if (size != nSize )  
			{
				char * temp= new char[size];
			 	
			    for(int i=0; i<size ; i++)
			    	temp[i]= *(Data+i);

			    delete[] Data;
			    Data=0;
			    
			    Data = new char[nSize];
			    memset(this->Data, 0, sizeof(char)*nSize);

  				for(int i=0; i<size ; i++)
			    	*(Data+i)=temp[i];

			    size= nSize;
			    delete [] temp;
			    temp=0;
  	
				
			} 		
}

//Destructor 
// It wipe out the all data
DynamicSafeArray::~DynamicSafeArray(){

 if (Data != 0)
 {
 	delete [] Data;
 	Data=0;
 	size=0;
	countChar = 0 ;
 }
}
	
// it returns the number of character currently available in array
int DynamicSafeArray::getCountChar()
{ return countChar; }

// it makes increment in number of character variable
void DynamicSafeArray::incCountChar()
{ countChar++; }

// it display all the characters in array on console
void DynamicSafeArray::printArray()
{
	for(int i = 0 ; i < countChar -1 ; i ++)
		cout<< * ( Data + i ) ;
	cout<<endl;
}
// it gets string from input file
ifstream& operator >> (ifstream& infile, DynamicSafeArray & rhs)
{
	int n = rhs.Size();
	while(!infile.eof())
		infile.get( rhs.Data[ rhs.countChar++ ] );
		
    return infile;
}

// it prints the resulted string in the output file
ofstream& operator << (ofstream& outfile, DynamicSafeArray & rhs)
{
	int n = rhs.Size();
	int count = 0 ;
	for(int i = 0 ; i < rhs.countChar -1 ; i++)
		outfile << rhs.Data[ count++ ] ;

    return outfile;
}

// it returns true if character is found on the given index
bool DynamicSafeArray::find(char element)
{
	for(int i = 0 ; i < size ; i ++)
	{
		if(element == Data[i])
		return true;
	}
	
	return false;
}

// default constructor
UniqueCharacters::UniqueCharacters(){}

//destructor
UniqueCharacters::~UniqueCharacters(){}

// this function take dsa array in argument
// it replaces the repeating characters with "-"
void UniqueCharacters::makeItUnique(DynamicSafeArray & array)
{
	DynamicSafeArray mark(80); // initializing array of size 80
	
	for(int i = 0 ; i < array.getCountChar() ; i++ ) //it loops till the number of characters in array
	{
		if(array[i] == 32 ) // it checks if the given character is space if it true then
		continue;			// continue will run
		if( !mark.find( array[i] ) ) //if the character is not find in tha mark
			mark[i] = array[i] ;	 // array then it will push that into mark array
		else					// else it is mark array then it will replace
		array[i] = '-' ;        // the current character with "-"	
	}
}
	

int main(){
	
	DynamicSafeArray String(80); // initializing array of size 80
	UniqueCharacters obj; // initializing onj of  UniqueCharacters
	ifstream inFile("P3_inputFile.txt"); //open file in input mode
	ofstream outFile("P3_outputFile.txt"); // opem file in output mode

	if(!inFile.is_open()) // shows message if file is not open
		cout<<"failed to opend"<<endl;
	if(!outFile.is_open()) // shows message if file is not open
		cout<<"failed to opend"<<endl;
	
	inFile >> String; // copy file data into  array
	String.printArray(); // print the charactes at array 
	obj.makeItUnique(String); //calling makeUnique function
	String.printArray(); // print array after changings
	outFile << String; // save the out result array into file
	return 0; // end of program
}


