#include<iostream>
#include "DSA.h"
using namespace std;
#ifndef UDSA_H
#define UDSA_H

class UDSA: public DSA
{
	public:
		UDSA();
		UDSA(int a);
		UDSA(const UDSA &obj);
		UDSA &operator = (UDSA &obj);
		~UDSA();
};

#endif
