#include <iostream>
#include <iomanip>   // fixed setprecision
#include <cmath>   // pow

#define _USE_MATH_DEFINES   // M_PI

using namespace std;

int main()
{
	double r, h, v, a;   // radius, height, volume, area,...respectively

	cout << "Enter radius and height of the cylinder in inches:" << endl;
	cin >> r >> h;

	v = M_PI*pow(r,2)*h;

	a = 2.*M_PI*((r*h)+pow(r,2));

	cout << fixed << setprecision(2);

	cout << "Volume: " << v << " cubic inches" << endl;
	cout << "Surface Area: " << a << " square inches" << endl;

	return 0;
}