#include "ODSA.h"

ODSA::ODSA()
{
	Odata = new int;
}
ODSA::ODSA(int a):DSA()
{
	Odata = new int[a];
}
ODSA::ODSA(const ODSA &obj)
{
	size = obj.size;
	index = obj.index;
	Odata = obj.Odata;
}
ODSA& ODSA::operator =(ODSA &obj)
{
	
	size = obj.size;
	index = obj.index;
	Odata = obj.Odata;
	
	return *this;
	
}
int& ODSA::operator[](int a)
{
	if(a<0 || a >index)
	{
		cout<<"Out of bound"<<endl;
		exit(0);
	}
	
	return Odata[a];
}
bool ODSA::search(int a)
{
	for(int i = 0 ; i<index; i++)
	{
		if(*(Odata+i)==a)
		return true;
	}
	return false;
}
void ODSA::insert(int a)
{
	if(index == size)
	{
		reSize(size + 3);
	}

	Odata[index++] = a;
	
	sort(Odata, Odata+index); 
}
void ODSA::reSize(int a)
{
	if(a==size || a < size)
	{
		cout<<"Enter valid size";
	}
	else
	{
		int *newData = new int[a];
		
		for(int i = 0 ; i < size; i++)
		{
			newData[i] = Odata[i];
		}
		
		Odata = new int[a];
		
		for(int i = 0 ; i< size; i++)
		{
			Odata[i] = newData[i];
		}
		
		size = a;
		delete newData;
	}
}
ODSA::~ODSA()
{
	delete Odata;
}
void ODSA::printData()
{
		for(int i = 0; i < index; i++)
	{
		cout<<Odata[i]<<",";
	}
}
