#ifndef ARRAY_H_
#define ARRAY_H_
#include <string>
#include <new>
#include <cstdlib>
using std::string;

class Array {
private:
	string* ptr = nullptr;
	int arraySize;
	int arrayCapacity;
	
	//---------------------------------------
	/*
	void memError();
	void subError();			IMPORTANT.
	*/
	//-----------------------------------------

public:
	//default constructor
	Array();

	//Explicit value constructor.
	Array(int);

	//*******************************************************************************************
	//Append function. This function wil add a copy of a new element to the end of the array.	*
	//*******************************************************************************************
	void append(string);
	
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
	string operator[](const int &) const;

	//Defualt destructor.
	~Array();
};


//Default constructor definition.
Array::Array() {
		ptr = nullptr;
		arraySize = 0;
		arrayCapacity = 1;
		ptr = new string[arrayCapacity];
}

//Explicit value constructor ddefinition.
Array::Array(int sub) {
	ptr = nullptr;
	arrayCapacity = sub;
	arraySize = 0;
	ptr = new string[arrayCapacity];
}

//Append function definition.
void Array::append(string newItem) {
	//Check if there is any space available by comparing arrayCapacity with arraySize.
	if (arrayCapacity == arraySize) {
		string* tempPtr;		//Create temporary pointer to hold a new array.
		arrayCapacity *= 2;
		tempPtr = new string[arrayCapacity];

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

//pop function definition.
void Array::pop() {
	arraySize -= 1;

	if (arraySize < (arrayCapacity / 4)) {
		string* tempPtr;
		arrayCapacity /= 2;
		tempPtr = new string[arrayCapacity];

		//Copy the elements from the previous array to the new allocated one.
		for (int index = 0; index < arraySize; index++) {
			tempPtr[index] = ptr[index];
		}

		delete[] ptr;
		ptr = tempPtr;
	}
}

//Get size function definition.
int Array::getSize() const{
	return arraySize;
}

//Get capacity definition.
int Array::getCapacity() const {
	return arrayCapacity;
}

//Overload [] operator.
string Array::operator[](const int &sub) const {
	if (sub < 0 || sub >= arraySize)
		int something; //do something

	return ptr[sub];
}

//*******************************************************************************************
//Overload the stand alone "<<" operator function to allow printinf out the contents of		*
//array.																					*
//*******************************************************************************************
std::ostream &operator << (std::ostream &out, const Array &obj) {
	out << "{ " ;

	for (int index = 0; index < obj.getSize(); index++) {
		out << obj[index] << ", ";
	}
	out << " }";

	return out;
}

Array::~Array() {
	delete[] ptr;
	ptr = nullptr;
}

#endif
