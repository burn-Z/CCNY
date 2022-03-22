#include "HM5_P1_CheckedArray.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
	CheckedArray arr;

	try {
		int index = 15;
		cout << "Element at index " << index << ": " << arr[index] << endl;
	}

// First exception type
/*	catch(CheckedArray::ArrayOutOfRangeError& x){
		cout << "ArrayOutOfRangeError" << endl << endl;
	}*/

// Second exception type
/*	catch(out_of_range& x){
		cout << x.what() << endl << endl;
	}*/

// Third exception type
	catch(ArrayOutOfRange& x){
		cout << x.what() << endl << endl;
	}


	return 0;
}