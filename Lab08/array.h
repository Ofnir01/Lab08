#ifndef ARRAY_H_
#define ARRAY_H_
#include <string>
#include <new>
#include <cstdlib>
#include "exceptions.h"
using std::string;

template<class T>
class Array {
private:
	T* ptr = nullptr;
	int arraySize;
	int arrayCapacity;
public:
	//default constructor
	Array();

	//Explicit value constructor.
	Array(int);

	//*******************************************************************************************
	//Append function. This function wil add a copy of a new element to the end of the array.	*
	//*******************************************************************************************
	void append(T);
	
	//*******************************************************************************************
	//Pop function. This function will remove the last element from the array.					*
	//*******************************************************************************************
	void pop();

	//*******************************************************************************************
	//get size. This function will return the number of items stored in the array.				*
	//*******************************************************************************************
	int getSize() const;

	//*******************************************************************************************
	//get capacity. This function will return the numer of items that can be stored on the		*
	//current array.																			*
	//*******************************************************************************************
	int getCapacity() const;


	//*******************************************************************************************
	//Overload the subscript operator. This will allow acces to an excisting element within		*
	//the array for read and write access.														*
	//*******************************************************************************************
	T &operator[](const int &);

	//Defualt destructor.
	~Array();
};


//Default constructor definition.
template <class T>
Array<T>::Array() {
		ptr = nullptr;
		arraySize = 0;
		arrayCapacity = 1;
		ptr = new T[arrayCapacity];
}

//Explicit value constructor ddefinition.
template <class T>
Array<T>::Array(int sub) {
	try {
		ptr = nullptr;
		arrayCapacity = sub;
		arraySize = 0;
		ptr = new T[arrayCapacity];
	}
	catch (std::bad_alloc) {
		throw MemoryException(arrayCapacity);
	}
}

//Append function definition.
template <class T>
void Array<T>::append(T newItem) {
	try {
		//Check if there is any space available by comparing arrayCapacity with arraySize.
		if (arrayCapacity == arraySize) {
			T* tempPtr;		//Create temporary pointer to hold a new array.
			arrayCapacity *= 2;
			tempPtr = new T[arrayCapacity];

			//Copy the elements from the previous array to the new allocated one.
			for (int index = 0; index < arraySize; index++) {
				tempPtr[index] = ptr[index];
			}

			delete[] ptr;
			ptr = tempPtr;

			ptr[arraySize] = newItem;
			arraySize += 1;
		}

		else {
			ptr[arraySize] = newItem;
			arraySize += 1;
		}
		
	}
	catch (std::bad_alloc) {
		throw MemoryException(arrayCapacity);
	}
}

//pop function definition.
template <class T>
void Array<T>::pop() {
	if (arraySize <= 0) {
		return;
	}

	else {
		arraySize -= 1;

		try {
			if (arraySize < (arrayCapacity / 4)) {
				T* tempPtr;
				arrayCapacity /= 2;
				tempPtr = new T[arrayCapacity];

				//Copy the elements from the previous array to the new allocated one.
				for (int index = 0; index < arraySize; index++) {
					tempPtr[index] = ptr[index];
				}

				delete[] ptr;
				ptr = tempPtr;
			}
		}

		catch (std::bad_alloc) {
			throw MemoryException(arrayCapacity);
		}
	}
}

//Get size function definition.
template <class T>
int Array<T>::getSize() const{
	return arraySize;
}

//Get capacity definition.
template <class T>
int Array<T>::getCapacity() const {
	return arrayCapacity;
}

//Overload [] operator.
template <class T>
T &Array<T>::operator[](const int &sub) {
	if (sub < 0 || sub >= arrayCapacity)
		throw SubscriptException("Subscript is out of limits.\n\n");

	return ptr[sub];
}

//*******************************************************************************************
//Overload the stand alone "<<" operator function to allow printinf out the contents of		*
//array.																					*
//*******************************************************************************************
template <class T>
std::ostream &operator << (std::ostream &out, Array<T> &obj) {
	out << "{ " ;

	for (int index = 0; index < obj.getSize(); index++) {
		if (index > 0)
			out << ", ";
		out << obj[index];
	}
	out << " }";

	return out;
}

//Destructor.
template <class T>
Array<T>::~Array() {
	delete[] ptr;
	ptr = nullptr;
}

#endif
