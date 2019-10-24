#include <bits/stdc++.h> 
using namespace std;

//------------------------------------------------------------------------------------------------------------------------//

//*********************************************Declaration of classes and its members************************************//

//-----------------------------------------------------------------------------------------------------------------------//

//-------- Declaration of class members of index bound exception-------//

class ArrayBoundException {

	public:
		ArrayBoundException();
		~ArrayBoundException();
		virtual const char* what() const throw();
	};

//-------- Declaring class members of upper index exception-------//

class UppderIndexException: public ArrayBoundException {

	public:
		UppderIndexException();
		~UppderIndexException();
		virtual const char* what() const throw();
	} upperBound;

//-------- Declaring class members of lower index exception-------//

class LowerIndexException : public ArrayBoundException {

	public:
		LowerIndexException();
		~LowerIndexException();
		virtual const char* what() const throw();
	} lowerBound;
//---------------Declaring Point2D classand its memebers----------------------------//

class Point2D {
	
	private:
		int x;
		int y;
	public:
		Point2D();
		Point2D(int x ,int y);
		~Point2D();
		void setXY(int x, int y);
		void displayXY();
		int getX();
		int getY();
};

//---------------Declaring class DynamicSafeArray2D  and its memebers---------------//

class DynamicSafeArray2D {  // DynamicSafeArray2D class stores the given paths 

	private:
		char **data; // 2D array of characters
		int n; // number of rows
		int m; // number of columns
	public:
		DynamicSafeArray2D();// it is default constructor which assign NULL to paths
		~DynamicSafeArray2D(); // destructor
		DynamicSafeArray2D( int row, int column ); //Construtor to intialize the row, column and to allocate memory for DynamicSafeArray2D variable;
		DynamicSafeArray2D( const DynamicSafeArray2D &rhs ); // copy constructor
		DynamicSafeArray2D& operator =( const DynamicSafeArray2D &rhs ); // assignment operator overloading
		char& operator ()( int i , int j ); // it returns refence of of given element index
		const char& operator ()( int i , int j) const; // it just return value at given index
		long int getSize() const; // it returns size of array
		void Resize( long int newSize ); // resizes the array;
		friend ifstream& operator >> ( ifstream& in, DynamicSafeArray2D & maze ); // isertion oeprator overlaoding
		friend ofstream& operator << ( ofstream& out, DynamicSafeArray2D & maze ); // exertion operator overloading
		int getRow() const; // return row size
		int getCol() const; // return column size		
		void displayPuzzle(); //displays all the puzzle
};

//---------------Declaring Puzzle class and its memebers---------------//

class Puzzle {

	public:
		Puzzle();
		~Puzzle();
		Point2D* solve( const DynamicSafeArray2D &maze, string word);		
	};

//--------------------------------------------------------------------------------------------------------------//
//**************************************************************************************************************//
//...............................Definitions of all classes declared above......................................//
//**************************************************************************************************************//
//--------------------------------------------------------------------------------------------------------------//


//-------- Defining class members of index bound exception-------//

//default constructor
ArrayBoundException::ArrayBoundException(){}
// destructor
ArrayBoundException::~ArrayBoundException(){}
// throws exception message
const char* ArrayBoundException::what() const throw()
	{ return "Array out of bound"; }


//-------- Defining class members of upper index exception-------//


UppderIndexException::UppderIndexException(){}

UppderIndexException::~UppderIndexException(){}


const char* UppderIndexException::what() const throw()
	{ return "Upper index exception"; }// returns message

//-------- Defining class members of lower index exception-------//

LowerIndexException::LowerIndexException(){}

LowerIndexException::~LowerIndexException(){}

const char* LowerIndexException::what() const throw()
	{ return "Lower index exception"; }// returns message

//---------------Declaring Point2D classand its memebers------------//

// default construtor
Point2D::Point2D() :x(0) , y(0) { }

//parameterized constructor
Point2D::Point2D(int x, int y )
{
	this->x = x;
	this->y = y;
}

// sets value of x and y
void Point2D::setXY(int x , int y)
{
	this->x = x;
	this->y = y;
}

// displays the dimensions
void Point2D::displayXY()
{
	cout<<"Row: "<<x <<", Column: "<<y<<endl;
}

// return x value
int Point2D::getX() { return x ;}

// return y value
int Point2D::getY() { return y ;}

//	--------------Defining DynamicSafeArray2D members-------------//	
	
// Default construtor
DynamicSafeArray2D:: DynamicSafeArray2D() : m(0), n(0), data(0) {} //Construtor to intialize the row,
																	// column and to allocate memory for paths variable

DynamicSafeArray2D:: DynamicSafeArray2D( int row, int column ) {
					
		n = row;
		m = column;
		data = new char *[n];

		for (int i = 0; i < n; i++)
		{
			*(data + i) = new char[m];
			memset(*(data + i), 0 , sizeof(char)*column);
		}
	}

// copy constructor
DynamicSafeArray2D:: DynamicSafeArray2D( const DynamicSafeArray2D &rhs ) {
		
		this->m = rhs.getCol();
		this->n = rhs.getRow();
		data = new char *[rhs.getRow()];

		for (int i = 0; i < rhs.getRow() ; i++)
		{
			*(data + i) = new char[rhs.getCol()];
			for (int j = 0; j < rhs.getCol() ; j++)
				*(*(this->data + i) + j) = rhs(i,j) ;
		}
	}

// assignment operator overloading
DynamicSafeArray2D&	DynamicSafeArray2D::operator=( const DynamicSafeArray2D &rhs ) {

		if ( this != &rhs )
		{
			this->m = rhs.getCol();
			this->n = rhs.getRow();

			for(int i = 0 ; i < this->n ; i ++)
				delete *(data + i) ;
			
			delete data ;
			data = new char *[rhs.getRow()];

			for (int i = 0; i < rhs.getRow(); i++)
			{
				*(data + i) = new char[rhs.getCol()];

				for (int j = 0; j < rhs.getCol(); j++)
					*(*(this->data + i) + j) = rhs(i,j);
			}
		}
		return ( *this );
	}

// it returns refence of of given element index

char& DynamicSafeArray2D::operator ()( int i,  int j) {

		if (i < 0 || j < 0) // lower index exception
			throw  lowerBound;
		else if ( i > getRow() || j > getCol() ) // upper index exception
			throw upperBound;
		else
			return *(*(data + i) + j); // else return the reults
		
	}

// it just return value at given index
const char& DynamicSafeArray2D:: operator()( int i,  int j) const {

		if (i < 0 || j < 0) // lower index exception
			throw  lowerBound;
		else if ( i > getRow() || j > getCol() ) // upper index exception
			throw upperBound;
		else
			return *(*(data + i) + j); // else return the reults
	}

// it returns size of array
long int DynamicSafeArray2D::getSize() const
	{ return ( m ); }

// resizes the array;
void DynamicSafeArray2D::Resize( long int newSize ) {

		if ( newSize > getSize() )
		{
			char **temp = new char* [ newSize ];  
			
			for (int i = 0; i < this->n; i++)
			{
				*(temp + i) = new char[m];

				for (int j = 0; j < m; j++)
					*(*(temp + i) + j) = *(*(data + i) + j);
			}
		
			for (int i = 0; i < n; i++)
			{
				if( *(data + i ) != 0 )
				delete *(data + i);
			}

			delete data;		
			data = new char *[n];

			for (int i = 0; i < n; i++)
			{
				*(data + i) = new char[m];

				for (int j = 0; j < m; j++)
					*(*(data + i) + j) = *(*(temp + i) + j);
			}
						
			for (int i = 0; i < n; i++)
			{
				if (*(temp + i) != 0)
					delete *(temp + i);
			}
			
			delete temp;
		}

		else
			cout << "New size is not valid";
	}

// destructor
DynamicSafeArray2D:: ~DynamicSafeArray2D() {

		for (int i = 0; i < n; i++)
		{
			if (*(data + i) != 0)
				delete *(data + i);
		}

		m = 0;
		n = 0;
	}

// get data from file and copy into  object
ifstream& operator >> ( ifstream& in, DynamicSafeArray2D & maze ) {

		string element;
		in >> maze.n;
		in >> maze.m;
		cout<<maze.n <<maze.m;
		
		maze.data = new char*[maze.n];
		
		for (int i = 0; i < maze.n; i++)
			{
				*(maze.data + i) = new char[maze.m];

				for (int j = 0; j <maze.m; j++)
					*(*(maze.data + i) + j) = 0;
			}

		for (int i = 0; i < maze.n ;  i ++)
		{	
			in >> element;

			for (int j = 0; j < maze.m; j++)
				*( *(maze.data + i ) + j ) = element[j] ;				
			cout<<endl;
		}
			
		return in;
	}
	
// friend function to write file into object

ofstream& operator << ( ofstream& out, DynamicSafeArray2D & maze ){

		out << maze.n << " " << maze.m << endl;

		for (int i = 0; i < maze.n; i++)
		{
			for (int j = 0; j < maze.m; j++)
			out << 	* ( *( maze.data + i ) + j) << " " ;
			out << endl;
		}

		return out;
	}

// return row size
int DynamicSafeArray2D::getRow() const
	{ return n; } // return column size
	
// return column size
int DynamicSafeArray2D::getCol() const
	{ return m; } // return row size
	
// function to print paths available at in array	
void DynamicSafeArray2D::displayPuzzle(){
	
		if( data != 0 )
		{			
			for( int i = 0 ; i < getRow() ; i++ )
			{				
				for(int j = 0 ; j < getCol() ; j ++)
				cout << * ( *( data + i ) + j);				
				cout << endl;
			}				
		}
		else
		cout << "No maze is given" << endl;

	}

//------------------Puzzle class definition----------------------//

Puzzle::Puzzle() {}

Puzzle::~Puzzle() {}

Point2D* Puzzle::solve(const DynamicSafeArray2D &maze , string word) {

			bool flag = false; // used to identify if word is found
			int Size  = word.size(); // size of word
			int row = maze.getRow(); // size of row
			int col = maze.getCol(); // size of column
			int x; // row 
			int y; // column
			int l = 0; // it used to point right index
 			int countSize = 0; // it counts size of successful matches
			
			// iteration row wise , it will check all the rows
			for( int i = 0 ; i < row ; i++ ) 
			{
				l = 0 ; // each time when row is check make the l = 0
				countSize = 0; // each time when row is check make the countSize = 0
				for( int j = 0; j < col ; j++ ) // travel the row in forward direction
				{
						if( j > 0 && maze(i,j-1) == word[l-1] && maze(i,j) != word[l]) 	
						{
							countSize = 0;
							l=0;					
						}
						if(maze(i,j) == word[l]) // if characters are equal then save dimension
						{						 // and increase size and l value
							if(l==0)
							{
								x = i;
								y = j;	
							}							
							countSize++;
							l++;
						}
							else
						{
							l = 0 ;
							countSize = 0;
						}															
						if(Size == countSize) // if word size and the counter size are equal then 
						{					// set flag
							flag = true;
							break;				
						}											
				}

				if(flag != true) //if word size and the counter size are not equal then
				{
				
			
				countSize = 0;		  // set countSize to 0
				l = 0;				  // set l to 0
				
				for(int j = col -1 ; j >= 0 ; j--) // travel the row in reverse direction
				{
					if( j < col-1 && maze(i,j+1) == word[l-1] && maze(i,j) != word[l])	
					{
						countSize = 0;
						l=0;						
					}					
					if( maze(i,j) == word[l] ) // if characters are equal then save dimension
					{							// and increase size and l value
						if(l==0)
						{
							x = i;
							y = j;	
						}							
						countSize++;
						l++;
					}																	
					else
					{
						l = 0 ;
						countSize = 0;
		
					}
					if(Size == countSize) // if word size and the counter size are equal then
					{					  // set flag
						flag = true;
						break;
					}										
				}				
				}
				else
				break;
			
			}
// now travel column wise 
			if ( flag != true )
			for( int i = 0 ; i < col ; i++ ) // travel in downward direction
			{
				l = 0 ; // each time when column is check make the l = 0
				countSize = 0; // each time when column is check make the countSize = 0
				for( int j = 0; j < row ; j++ )
				{					
					if( j > 0 && maze(j-1,i) == word[l-1] && maze(j,i) != word[l])	
					{
						countSize = 0;
						l=0;						
					}					
					if(maze(j,i) == word[l])// if characters are equal then save dimension
						{					// and increase size and l value
							if(l==0)
							{
								x = j;
								y = i;	
							}							
							countSize++;
							l++;
						}
					else
					{
						l = 0 ;
						countSize = 0;
		
					}															
					if(Size == countSize) // if word size and the counter size are equal then
					{					// set flag				
						flag = true;
						break;						
					}																
				}
				
				if(flag != true)
				{
				
				countSize = 0;				
				l = 0;
				
				for(int j = row -1 ; j >= 0 ; j--) // travel in upward direction
				{
		
					if( j > 0 && maze(j-1,i) == word[l-1] && maze(j,i) != word[l])	
					{
						countSize = 0;
						l=0;						
					}
					if( maze(j,i) == word[l] ) // if characters are equal then save dimension
					{							// and increase size and l value
						if(l==0)
						{
							x = j;
							y = i;	
						}
						countSize++;
						l++;
					}																	
						else
					{
						l = 0 ;
						countSize = 0;
		
					}
					if(Size == countSize) // if word size and the counter size are equal then
					{						// set flag						
						flag = true;
						break;
					}										
				}				
				}
				else
				break;
				
				}
				
				Point2D *path;
				path = new Point2D();
				if( flag == true)			
					path->setXY(x,y);				
				else
					path->setXY(-1,-1);			
				
				return path;
				
	}


//*************************Main Function************************//

	int main()
	{
		ifstream file("P1_inputFile.txt"); // file where maze is data is given
		ofstream outFile("P1_outputFile.txt"); // it saves the results
		int numberOfWords ;
		Puzzle m;   // maze obect
		DynamicSafeArray2D p ;  // array object
		Point2D *path;
		if( !file.is_open() )
			cout << "Failed to open file" << endl;						
		if( !outFile.is_open() )
			cout << "Failed to open file" << endl;	

		file >> p; // copying data from file to array
		cout << "-----------Words given--------------" << endl;
		file >> numberOfWords;
		string words[numberOfWords];
		for( int i  ; i < numberOfWords ; i ++)
		{
			file>>words[i];
			cout<<words[i]<<endl;
		}
		cout << "-----------Puzzle given--------------" << endl << endl;
		p.displayPuzzle();
		
		cout << endl;	
		cout << "------------------------------------" << endl;
		cout << endl;
		for(int i = 0 ; i < numberOfWords ; i ++)
		{
			path = m.solve(p,words[i]); // it will solve the maze and and will store the results in file	

			if(path->getX() < 0)
			{
				outFile<<'n'<<endl;
				cout<<words[i]<<" not found"<<endl;
			}
			else
			{
				outFile<<path->getX()<<path->getY()<<endl;
				cout<<words[i]<<" is found"<<endl;
				path->displayXY();
			}
			
		}
			

		return 0;

	}
