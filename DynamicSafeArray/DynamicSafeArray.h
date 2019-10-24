#pragma once
#include"ArrayException.h"
#include"ArrayExceptionLowerBound.h"
#include"ArrayExceptionUpperBound.h"
#include<iostream>
#include<conio.h>
using namespace std;

class DynamicSafeArray {
private:
	int *data;
	int size;

public:
	DynamicSafeArray();
	~DynamicSafeArray();
	DynamicSafeArray( int s);
	DynamicSafeArray(const DynamicSafeArray &obj);
	DynamicSafeArray & operator = (const DynamicSafeArray &obj);
	const int& operator [] (int index) const;
	int& operator [](int index);
	void reSize(int newSize);
	int arrayLength() const;

};

