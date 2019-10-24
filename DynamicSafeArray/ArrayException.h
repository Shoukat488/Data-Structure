#pragma once
#include<iostream>
using namespace std;

class ArrayException : public exception
{
public:
	ArrayException();
	char* what();
	~ArrayException();
};

