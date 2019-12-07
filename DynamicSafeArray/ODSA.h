#include<iostream>
#include "DSA.h"
#include<cstdlib>
#include <bits/stdc++.h>
using namespace std;
#ifndef ODSA_H
#define ODSA_H

class ODSA:public DSA
{
	protected:
	int *Odata;
	
	public:
		ODSA();
		ODSA(int a);
		ODSA(const ODSA &obj);
		~ODSA();
		void reSize(int a);
		ODSA &operator = (ODSA &obj);
		int &operator [] (int a);
		bool search(int a);
		void insert(int a);
		void printData();
};

#endif
