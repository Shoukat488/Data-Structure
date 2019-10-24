#pragma once
#include"ArrayException.h"
#include<iostream>
using namespace std;
class ArrayExceptionLowerBound: public ArrayException
{
public:
	ArrayExceptionLowerBound();
	char* what();
	~ArrayExceptionLowerBound();
};

