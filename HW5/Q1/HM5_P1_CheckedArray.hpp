#include <stdexcept>
#include <cstring>
#include <string>

using namespace std;

const int MAX = 10; // array size

class CheckedArray {
public:
	CheckedArray();
	class ArrayOutOfRangeError {};
	int& operator[](int);
private:
	int s[MAX];
};

CheckedArray::CheckedArray() {
	this->s;
}

// First exception type
/*int& CheckedArray::operator[](int i) {
	if(i>=MAX) throw CheckedArray::ArrayOutOfRangeError();
	return s[i];
}*/

// Second exception type
/*int& CheckedArray::operator[](int i) {
	if(i>=MAX) throw out_of_range("out_of_range");
	return s[i];
}*/

// Third exception type
class ArrayOutOfRange : public out_of_range {
public:
	explicit ArrayOutOfRange (const string& errorMsg, int s, int aI):
	out_of_range(errorMsg) {
		this->size = s;
		this->attemptedIndex = aI;
	}
	const char* what() const noexcept {
		string temp = " ("+to_string(attemptedIndex)+","+to_string(size)+")";
		char* message = new char[100]; //stores message, to return const char*
		strcpy(message,out_of_range::what());
		strcat(message,temp.c_str());
		return message;
	}
protected:
	int size;
	int attemptedIndex;
};



int& CheckedArray::operator[](int i) {
	if(i>=MAX) throw ArrayOutOfRange("ArrayOutOfRange", MAX, i);
	return s[i];
}