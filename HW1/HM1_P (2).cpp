#include <iostream>
#include <cmath>   // abs, floor, ceil
#include <iomanip>   // fixed setprecision
using namespace std;

int main()
{
	srand(23464017);

	// generates 99999 in [0,9999]
	// then scales it between [0,1]
	// then shifts it to [-9.9999,-9.0001] or (-10,-9)
	double r = (rand()%9999)/10000.-9.9999;

	// The random value generated from my seed has 3 non-zero decimal places
	cout << fixed << setprecision(4);   // four decimal digits

	cout << "Random number: " << r << endl;
	cout << "Absolute value: " << abs(r) << endl;
	cout << "Its floor: " << (int)floor(r) << endl;   // (int) to remove .0
	cout << "Its ceiling: " << (int)ceil(r) << endl;
	cout << "Its decimal part: " << (int)(abs(r)*10000)%10000 << endl;

	return 0;
}