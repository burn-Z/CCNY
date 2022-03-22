#include <cmath>
#include <iostream>
#include "HM4_P1_point.h"

using namespace std;

// reads points from [x,y]
istream& operator>>(istream& inP, point& p) {
	char b1, c, b2;
	double x, y;

	inP >> b1 >> x >> c >> y >> b2;

	if(b1 == '[' && c == ',' && b2 == ']') {
		p.setX(x);
		p.setY(y);
	} else {
		cout << "Invalid format" << endl;
		inP.clear();
	}

	return inP;
}

// prints points in the form [x,y]
ostream& operator<<(ostream& outP, const point& p) {
	outP << "[" << p.x << "," << p.y << "]";

	return outP;
}