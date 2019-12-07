#include "UDSA.h"

UDSA::UDSA()
{
	
}
UDSA::UDSA(int a): DSA(a)
{
	
}
UDSA::UDSA(const UDSA &obj)
{
	data = obj.data;
	size = obj.size;
	index = obj.index;
}
UDSA::~UDSA()
{
		
}
