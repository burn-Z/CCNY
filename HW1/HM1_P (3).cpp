#include <iostream>
#include <iomanip> // setprecision
using namespace std;

int main()
{

	double a, b, c, d, highest, lowest, difference;

	cout << setprecision(16);   // for up to 16 digits

	cout << "Enter four real numbers between 0 and 1,000,000" << endl;
	cin >>  a >> b >> c >> d;

	highest = max(max(a,b),max(c,d));   // separates numbers into two pairs and compares the
	lowest = min(min(a,b),min(c,d));   // numbers within each pair, then compares the min
                                      // or max of each pair
	difference = highest - lowest;
	cout << "Difference between the highest and lowest number: "
		 << difference << endl;
	return 0;
}