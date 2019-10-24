#include "ArrayException.h"



ArrayException::ArrayException()
{
}
char* ArrayException::what()
{
	return " Array bound exception";
}

ArrayException::~ArrayException()
{
}
