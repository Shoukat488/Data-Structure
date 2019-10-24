#include <cstring>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<exception>
using namespace std;

//----------------------------------------------------------------------------//

//**********************Declaration of classes *******************************//

//----------------------------------------------------------------------------//


//-------- Defining class members of index bound exception-------//

	class ArrayBoundException
	{
		public:
		ArrayBoundException();
		~ArrayBoundException();
		virtual const char* what();
	};

//-------- Declaring class members of upper index exception-------//

class UppderIndexException: public ArrayBoundException
	{
		public:
		UppderIndexException();
		~UppderIndexException();
		virtual const char* what();
	};

//-------- Declaring class members of lower index exception-------//

	class LowerIndexException : public ArrayBoundException
	{
		
		public:
		LowerIndexException();
		~LowerIndexException();
		virtual const char* what();
	};


//---------------Declaring class Paths  and its memebers---------------//
class Paths {  // Paths class stores the given paths 

	private :
		int *paths; // array of paths
		int n; // number of rows
		int m; // number of columns

	public :				
		Paths();// it is default constructor which assign NULL to paths		
		~Paths(); // destructor
		Paths( int row, int column ); //Construtor to intialize the row, column and to allocate memory for paths variable;	
		Paths( const Paths &rhs ); // copy constructor
		Paths& operator =( const Paths &rhs ); // assignment operator overloading
		int& operator ()( int i , int j ); // it returns refence of of given element index
		const int& operator ()( int i , int j) const; // it just return value at given index
		long int getSize() const; // it returns size of array
		void Resize( long int newSize ); // resizes the array;
		friend ifstream& operator >> ( ifstream& in, Paths & maze );
		friend ofstream& operator << ( ofstream& out, Paths & maze );
		int getRow() const; // return row size
		int getCol() const; // return column size		
		void displayPaths();
};

//---------------Declaring Maze class and its memebers---------------//

	class Maze
	{
		public:
		Maze();
		~Maze();
		void countPaths(Paths & maze, int row, int col, int i , int j ,int *count) ;
	};


//--------------------------------------------------------------------------------------------------------------//
//**************************************************************************************************************//
//..................................Definitions of above declared classes.......................................//
//**************************************************************************************************************//
//--------------------------------------------------------------------------------------------------------------//


//-------- Declaring class members of index bound exception-------//
//constructor
ArrayBoundException::ArrayBoundException() {}

// destructor
ArrayBoundException::~ArrayBoundException() {}

// it throws message of exception
const char* ArrayBoundException::what()
	{ return "Array out of bound"; }

//-------- Defining class members of upper index exception-------//
//constructor
UppderIndexException::UppderIndexException() {}

// destructor
UppderIndexException::~UppderIndexException() {}

// it throws message of exception
const char* UppderIndexException::what()
	{ return "Upper index exception"; } // returns message 


//-------- Defining class members of lower index exception-------//
//constructor
LowerIndexException::LowerIndexException() {}

// destructor
LowerIndexException::~LowerIndexException() {}

// it throws message of exception
const char* LowerIndexException::what()
	{ return "Lower index exception"; }// returns message


//--------------Defining Paths members-------------//	
	
// Default construtor
Paths:: Paths() : m(0), n(0), paths(0) {} //Construtor to intialize the row, 
										  //column and to allocate memory for paths variable

Paths:: Paths( int row, int column )
	{					
		n = row;
		m = column;
		long int size = m*n;
		this->paths = new int[size];		
		memset( this->paths, 0, sizeof(int)*size );
	}

// copy constructor
Paths:: Paths( const Paths &rhs )
	{
		this->m = rhs.m;
		this->n = rhs.n;

		long int size = (rhs.m)*(rhs.n);
		this->paths = new int[ size ];
		memcpy( this->paths, rhs.paths, sizeof(int)*size );
	}

// assignment operator overloading
Paths&	Paths::operator=( const Paths &rhs )
	{
		if ( this != &rhs )
		{
			this->m = rhs.m;
			this->n = rhs.n;
			long int size = (rhs.m) * (rhs.n);

			if (this != 0)
				delete this->paths;
			
			this->paths = new int[size];
			memcpy( this->paths, rhs.paths, sizeof(int)*size );
		}
		return ( *this );
	}

// it returns refence of of given element index
int& Paths::operator ()( int i,  int j)
	{

		if ( i < 0  || j < 0) // lower index exception
			throw new LowerIndexException();
		else if ( i >= getRow() || j >= getCol() ) // upper index exception
			throw new UppderIndexException();
		else
		{
			int long offest = i * getCol();
			return *( (paths + offest) + j);
		}
	}

// it just return value at given index
const int& Paths:: operator()( int i,  int j) const
	{

		if ( i < 0  || j < 0) // lower index exception
			throw new LowerIndexException();
		else if ( i >= getRow() || j >= getCol() ) // upper index exception
			throw new UppderIndexException();
		else
		{
			int long offest = i * getCol();
			return *( (paths + offest) + j);
		}
	}

// it returns size of array

long int Paths::getSize() const
	{
		return ( m*n );
	}

// resizes the array;
void Paths::Resize( long int newSize )
	{
		if ( newSize > getSize() )
		{
			int *temp = new int[ newSize ];  
			
			for (int i = 0; i < getSize(); i++)
				*( temp + i ) = *( paths + i );
			delete paths;

			paths = new int[newSize];
			memcpy( paths, temp, sizeof(int)*newSize );

			delete temp;
			temp = 0;
		}
		else
			cout << "New size is not valid";
	}

// destructor
Paths:: ~Paths()
	{
		delete paths;
		paths = 0;
		m = 0;
		n = 0;
	}

// gets data from file and copy into  object
ifstream& operator >> ( ifstream& in, Paths & maze )
	{
		int row = 0, col = 0; 
		char charElement;
		int intElement;
		in >> maze.n;
		in >> maze.m;
		
		maze.paths = new int[ maze.getRow() * maze.getCol() ];
		in.get( charElement );
		
		for(int i = 0 ; i < maze.n ; i ++)
		{
			for( int  j = 0 ; j < maze.m ; j++)
			{
				in.get( charElement );		
				intElement = charElement - 48 ;
				
				maze(i,j) = intElement ;
			}
			in.get( charElement );
		}				
		return in;
	}
	
// friend function to write file into object
ofstream& operator << ( ofstream& out, Paths & maze )
	{
		int row = 0, col = 0;
		out << maze.n << " " << maze.m << endl;

		while ( row <= maze.n )
		{
			if ( col > maze.m )
			{
				out << endl;
				++row;
				col = 0;
			}
			else
			{
		 		out << *( maze.paths + row + col ) ;
				++col;
			}
		}
		return out;
	}

// return row size
int Paths::getRow() const
	{
		return n;
	}

// return column size
int Paths::getCol() const
	{
		return m;
	}
	
// function to print paths available at in array
void Paths::displayPaths()
	{				
		if( paths != 0 )
		{			
			for( int i = 0 ; i < getRow() ; i++ )
			{				
				for(int j = 0 ; j < getCol() ; j ++)
				cout << * ( ( paths + i*getCol() ) + j);				
				cout << endl;
			}						
		}		
		else		
		cout << "No maze is given" << endl;		
	}



//-----------------------Maze Definitions-------------------//

// default constructor
Maze::Maze() {}
// destructor
Maze::~Maze() {}

// countPaths function take DSA array , number of row , number of column,
// initial row , initial column and counter variable .
// it uses backtracking and recurson to solve the problem
// 1- First of all it checks if initial column value is equal and initial row
// values is not equal or vice versa if it is true then it simply return
// 2- If above two conditions do not meet the criteria then 
// it checks if value on given paths is equal to 1 if it is
// then it  returns 
// 3- First three conditions are fail then it checks if
// value on given path is euqual to 0 if it is then it
// increases intial column value and makes recursive call to function
// 4- When the above code is exectued it means all columns in the
// respective row have done then it simply makes recursive call to function with
// the incerement in row
// 5- When all operations on the row have done then it means we are at the
// destination. Therefore it check if initial and given size of row and col are 
// equal if they are then incraese the counter variable
void Maze::countPaths(Paths & array , int row, int col, int i , int j , int *count) 
{ 
// It checks if initial column value
// is equal and initial row values is
// not equal if it is true then it 
// simply return
    if( ( j == col && i != row ) ) 
    	return;
// It checks if initial row value is
// equal and initial column values is
// not equal if it is true then it 
// simply returns	
	if( i == row && j != col  ) 
    	return;
// it checks if value on given path is 
// equal to 1 if it is then it returns	
    if( array( i , j ) == 1)	
    	return;
// it checks if value on given path is
// euqual to 0 if it is then it
// increases intial column value and
// makes recursive call to function
    if( array( i , j ) == 0)
        countPaths(array,row,col,i , j+1 , count);
// It simply makes recursive call to 
// function with the incerement in row
    countPaths(array,row,col,i+1 , j , count );
// it check if initial and given size 
// of row and col are equal if they 
// are then incraese the counter variable
// and return
    if(i == row -1 && j == col - 1 ) 
    {
       ++(*count) ;  
		return;
    }
}


//****************************************** Main Function ***********************************//

	int main()
	{
		ifstream inFile("P2_inputFile.txt"); // file where maze is data is given
		ofstream outFile("P2_outputFile.txt"); //file where output will be save
		int countPaths = 0; // make the variable equal to 0
		if( !inFile.is_open() ) // if file is not open show message
			cout << "Failed to open file" << endl;
		if( !inFile.is_open() ) // if file is not open show message
			cout << "Failed to open file" << endl;
							
		Paths p;  // array object
		Maze m;   // maze obect

		inFile >> p; // copying data from file to array
		
		cout << "-----------Maze given--------------" << endl << endl;
		p.displayPaths(); // print the given maze
		
		cout << endl; 
		
		cout << "------------------------------------" << endl;
		cout << endl;
		m.countPaths(p,p.getRow(), p.getCol() , 0 , 0 , &countPaths); // it will solve the maze and and will store the results in countPaths
		
		if(countPaths == 0) // if on path is available print "No paths"
		{
			outFile<<"No paths"; // at output file
			cout<<"No paths";
		}			
		else
		{
			outFile<<countPaths; // else print the number of paths
			cout<<"Number of Paths:" ;
			cout<<countPaths; //print the number of paths
		}

		return 0;

	}
