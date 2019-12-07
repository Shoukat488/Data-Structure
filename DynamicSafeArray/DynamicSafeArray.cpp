#include "DynamicSafeArray.h"

DynamicSafeArray::DynamicSafeArray(): size(0), data(0){}
DynamicSafeArray::DynamicSafeArray(int s) : size(s)
{
	data = new int[size];

	memcpy(this->data, 0, sizeof(int)*(this->arrayLength()));
}

 DynamicSafeArray::DynamicSafeArray(const DynamicSafeArray &obj)
{
	this->size = obj.arrayLength();
	this->data = new int[obj.arrayLength()];
	
	memcpy(this->data, obj.data , sizeof(int)*obj.arrayLength());

}
 DynamicSafeArray& DynamicSafeArray::operator=(const DynamicSafeArray &obj)
 {
	 if (this != &obj)
	 {
		 this->size = obj.arrayLength();
		 this->data = new int[obj.arrayLength()];
		
		 memcpy(this->data, obj.data, sizeof(int)*obj.arrayLength());
	 }

	 return *this;
 }
 const int& DynamicSafeArray::operator[](int s) const
 {
	 if (s < 0) throw(new ArrayExceptionLowerBound());
	 else if (s >= size) throw(new ArrayExceptionUpperBound());
	 else
	 {
		 return this->data[s];
	 }
		 
 }
 int& DynamicSafeArray::operator[](int s)
 {
	 if (s < 0)
		 throw(new ArrayExceptionLowerBound());
	 else if (s >= size) 
		 throw(new ArrayExceptionUpperBound());
	 else
	 {
		 return this->data[s];
	 }

 }
 
 int DynamicSafeArray::arrayLength() const
 {
	 return size;
 }
DynamicSafeArray::~DynamicSafeArray()
{
	if (data != 0)
		delete data;
	data = 0;

}
void DynamicSafeArray::reSize(int newSize)
{
	if (newSize > size)
	{
		int *tempData = new int[newSize];
		memcpy(tempData, this->data, sizeof(data)*size);

		delete this->data;
		data = 0;
		this->data = new int[newSize];
		memcpy(this->data, tempData , sizeof(data)*size);

		delete tempData;

	}
	else
	{
		cout << "Invalid size";
	}
}
