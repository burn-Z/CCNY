#include <iostream>
#include <cmath>   // round()

using namespace std;

int main()
{
	double X = 0;

	cout << "Enter a floating-point number with 6 digits" << endl;
	cout << "(3 in whole number part and 3 in decimal part i.e XXX.XXX)" << endl;
	cin >> X;

	cout << "\n\nThe decimal part:" << endl;

	// double to int so that there is no error with modulo
	cout << "    thousandths: " << static_cast<int>(1000*X)%10 << endl;
	cout << "    hundredths: " << static_cast<int>(100*X)%10 << endl;
	cout << "    tenths: " << static_cast<int>(10*X)%10 << endl;
	cout << "The whole number part:" << endl;
	cout << "    ones : " << (static_cast<int>(X))%10 << endl;
	cout << "    tens : " << ((static_cast<int>(X))%100)/10<< endl;
	cout << "    hundreds : " << static_cast<int>(X)/100<< endl;
	cout << "\nRounded value : " << round(X) << endl;

	return 0;
}