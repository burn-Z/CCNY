/*
 finds the upper and lower limits of
 numeric data types on this system
*/
 
#include <iostream>
#include <climits>

using namespace std;

int main() {
	cout << "Data type\tSize\tSupported Number Range" << endl;
	cout << "Char     \t" << sizeof(char) << "\t" << CHAR_MIN << " to " << CHAR_MAX << endl;
	cout << "short    \t" << sizeof(short) << "\t" << SHRT_MIN << " to " << SHRT_MAX << endl;
	cout << "long     \t" << sizeof(long) << "\t" << LONG_MIN << " to " << LONG_MAX << endl;
	cout << "long long\t" << sizeof(long long) << "\t" << LLONG_MIN << " to " << LLONG_MAX << endl;
	cout << "int      \t" << sizeof(int) << "\t" << INT_MIN << " to " << INT_MAX << endl;
	//cout << "float\t" << sizeof(float) << "\t" << FLT_MIN << " to " << FLT_MAX << endl;
	//cout << "double\t" << sizeof(double) << "\t" << DBL_MIN << " to " << DBL_MAX << endl;

	return 0;
}