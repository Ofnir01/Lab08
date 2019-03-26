//This program will test arri.h which contains a class template call array.
//Emmanauel Torres.
//CS 1410. 3/15/19.
#include <iostream>
#include <cstdlib>
#include "array.h"
#include "exceptions.h"
using std::cerr;
using std::cout;
using std::cin;
using std::endl;

//This program will implement a class template call Array, which will store
//a user defined amount of elements within it. Then it will procede to print
//those elements to the screen.
int main() {
	int size;
	short input;
	bool repeat = true;

	//Greeting.
	cout << "Hello there! This program will ask you to input the number of elements that a the Array class might hold." << endl;
	cout << "Then it will procede to print all the contents hold in that array." << endl;
	cout << "Please enter a size: ";
	cin >> size;

	while (size < 1) {
		cout << "Invalid size, plesae try again. ";
		cin >> size;
	}

	try {
		Array<short> arr(size);
	}
	catch (MemoryException &error) {
		cerr << "Not enough space to allocate memory. Size tried to be allocated: " << error.getSize() << " bytes\n\n";
		exit(EXIT_FAILURE);
	}

	Array<short> arr(size);

	//for loop for entering data to the Array.
	for (int index = 0; index < size; index++) {
		cout << "Please enter a number for spot #" << index + 1 << ": ";
		cin >> input;

		arr.append(input);
	}

	//While loop for menu display.
	while (repeat) {
		//Print the contents of the array.
		cout << endl << "The contents are: ";
		cout << arr << endl << endl;

		cout << "What do you want to do next?" << endl;
		cout << "\t1. Delete last value. \n\t2. Add a new value. \n\t3. Terminate program.\n";
		cout << "Response: ";
		cin >> input;

		switch (input) {
		case 1:
			arr.pop();
			repeat = true;
			break;

		case 2:
			cout << "Please enter a value: ";
			cin >> input;
			arr.append(input);
			repeat = true;
			break;

		default:
			repeat = false;
		}
	}
}