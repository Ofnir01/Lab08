#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_
#include <exception>
#include <string>
using std::exception;

//***************************************************************************************
//This exception will be thrown if a numerical overflow happens, and it will print		*
//an informative message of the exception.												*
//***************************************************************************************
class OverflowException : public exception {
public:
	//Constructor that will receive a message where the exception was thrown
	OverflowException(const char* Overflow) : exception(Overflow) { }
};

//***************************************************************************************
//This exception will be thrown if a we try to access a subscript, that is not			*
//within the limits of an array, and it will print an informative						*
//message of the exception.																*
//***************************************************************************************
class SubscriptException : public exception {
public:
	//Constructor that will receive a message where the exception was thrown
	SubscriptException(const char *Overflow) : exception(Overflow) { }
};

//***************************************************************************************
//This exception will be thrown if someone tries to allocate memory, and there is no	*
//space for storing it on the heap, and it will print an informative message			*
//of the exception.																		*
//***************************************************************************************
class MemoryException : public exception {
private:
	int size;
public:
	//Constructor that will receive a message where the exception was thrown
	MemoryException(const char *Overflow) : exception(Overflow) { }

	//Constructor that will receive a size from the exception was thrown.
	MemoryException(int size1) : exception() { 
		size = size1;
	}

	//This function will return the amount of memory that was attempted to be allocated.
	int getSize() const{
		return size;
	}

};

#endif