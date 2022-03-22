#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

using namespace std;

class point {
public:
	point(double X=0, double Y=0): x(X), y(Y) {}
	void setX(double x) { this->x=x; }
	double getX() const { return this->x;}
	void setY(double y) { this->y=y; }
	double getY() const { return this->y;}
	void print() const ;
	friend double distO(point w);	// returns distance from origin
	friend double distO(pair<double,double> z);
	friend point operator+(point lhp, point rhp);
	friend point operator+(point lhp, pair<double,double> rhp);
	friend point operator+(pair<double,double> lhp, point rhp);
	friend point operator-(point lhp, point rhp);
	friend point operator-(point lhp, pair<double,double> rhp);
	friend point operator-(pair<double,double> lhp, point rhp);
	friend point operator*(point lhp, point rhp);
	friend point operator*(point lhp, pair<double,double> rhp);
	friend point operator*(pair<double,double> lhp, point rhp);
	friend point operator/(point lhp, point rhp);
	friend point operator/(point lhp, pair<double,double> rhp);
	friend point operator/(pair<double,double> lhp, point rhp);
	friend bool operator==(point lhp, point rhp);
	friend bool operator==(point lhp, pair<double,double> rhp);
	friend bool operator==(pair<double,double> lhp, point rhp);
	friend bool operator!=(point lhp, point rhp);
	friend bool operator!=(point lhp, pair<double,double> rhp);
	friend bool operator!=(pair<double,double> lhp, point rhp);
	friend bool operator<(point lhp, point rhp);
	friend bool operator<(point lhp, pair<double,double> rhp);
	friend bool operator<(pair<double,double> lhp, point rhp);
	friend bool operator>(point lhp, point rhp);
	friend bool operator>(point lhp, pair<double,double> rhp);
	friend bool operator>(pair<double,double> lhp, point rhp);
	friend bool operator<=(point lhp, point rhp);
	friend bool operator<=(point lhp, pair<double,double> rhp);
	friend bool operator<=(pair<double,double> lhp, point rhp);
	friend bool operator>=(point lhp, point rhp);
	friend bool operator>=(point lhp, pair<double,double> rhp);
	friend bool operator>=(pair<double,double> lhp, point rhp);
	point operator++();
	point operator++(int dummy);
	point operator--();
	point operator--(int dummy);
private:
	double x;
	double y;
};

void point::print() const{
	cout << "x,y: (" << this->x << "," << this->y << ")\n";
}

double distO(point w) {	return pow(pow(w.x,2)+pow(w.y,2),.5);	}
double distO(pair<double,double> z) {
	return pow(pow(z.first,2)+pow(z.second,2),.5);
}

point operator+(point lhp, point rhp)
{	return point(lhp.x + rhp.x, lhp.y + rhp.y);	}

point operator+(point lhp, pair<double,double> rhp)
{	return point(lhp.x + rhp.first, lhp.y + rhp.second);	}

point operator+(pair<double,double> lhp, point rhp)
{	return point(lhp.first + rhp.x, lhp.second + rhp.y);	}

point operator-(point lhp, point rhp)
{	return point(lhp.x - rhp.x, lhp.y - rhp.y);	}

point operator-(point lhp, pair<double,double> rhp)
{	return point(lhp.x - rhp.first, lhp.y - rhp.second);	}

point operator-(pair<double,double> lhp, point rhp)
{	return point(lhp.first - rhp.x, lhp.second - rhp.y);	}

point operator*(point lhp, point rhp)
{	return point(lhp.x * rhp.x, lhp.y * rhp.y);	}

point operator*(point lhp, pair<double,double> rhp)
{	return point(lhp.x * rhp.first, lhp.y * rhp.second);	}

point operator*(pair<double,double> lhp, point rhp)
{	return point(lhp.first * rhp.x, lhp.second * rhp.y);	}

point operator/(point lhp, point rhp) {
	if(rhp.x == 0 || rhp.y == 0) return lhp;

	return point(lhp.x / rhp.x, lhp.y / rhp.y);
}

point operator/(point lhp, pair<double,double> rhp) {
	if(rhp.first == 0 || rhp.second == 0) return lhp;

	return point(lhp.x / rhp.first, lhp.y / rhp.second);
}

point operator/(pair<double,double> lhp, point rhp) {
	if(rhp.x == 0 || rhp.y == 0) return point(lhp.first, lhp.second);

	return point(lhp.first / rhp.x, lhp.second / rhp.y);
}

bool operator==(point lhp, point rhp)
{	return (distO(lhp) == distO(rhp));	}

bool operator==(point lhp, pair<double,double> rhp)
{	return (distO(lhp) == distO(rhp));	}

bool operator==(pair<double,double> lhp, point rhp)
{	return (distO(lhp) == distO(rhp));	}

bool operator!=(point lhp, point rhp)
{	return !(lhp == rhp);	}

bool operator!=(point lhp, pair<double,double> rhp)
{	return !(lhp == rhp);	}

bool operator!=(pair<double,double> lhp, point rhp)
{	return !(lhp == rhp);	}

bool operator<(point lhp, point rhp)
{	return (distO(lhp) < distO(rhp));	}

bool operator<(point lhp, pair<double,double> rhp)
{	return (distO(lhp) < distO(rhp));	}

bool operator<(pair<double,double> lhp, point rhp)
{	return (distO(lhp) < distO(rhp));	}

bool operator>(point lhp, point rhp)
{	return (rhp<lhp);	}

bool operator>(point lhp, pair<double,double> rhp)
{	return (rhp<lhp);	}

bool operator>(pair<double,double> lhp, point rhp)
{	return (rhp<lhp);	}

bool operator<=(point lhp, point rhp)
{	return !(lhp>rhp);	}

bool operator<=(point lhp, pair<double,double> rhp)
{	return !(lhp>rhp);	}

bool operator<=(pair<double,double> lhp, point rhp)
{	return !(lhp>rhp);	}

bool operator>=(point lhp, point rhp)
{	return !(lhp<rhp);	}

bool operator>=(point lhp, pair<double,double> rhp)
{	return !(lhp<rhp);	}

bool operator>=(pair<double,double> lhp, point rhp)
{	return !(lhp<rhp);	}

point point::operator++() {
	x++;
	y++;
	return *this;
}

point point::operator++(int dummy) {
	point t = *this;
	x++;
	y++;
	return t;
}

point point::operator--() {
	x--;
	y--;
	return *this;
}

point point::operator--(int dummy) {
	point t = *this;
	x--;
	y--;
	return t;
}

#endif