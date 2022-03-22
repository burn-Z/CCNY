#include <cmath>
#include <iostream>
#include <iomanip>
#include "HM4_P1_point.h"
#include "HM4_P1_Line.h"

using namespace std;

void Line::setVertex1(point p) {
	*p1 = p;
	if(p2 != nullptr) {
		this->m = ((p1->getY())-(p2->getY()))/((p1->getX())-(p2->getX()));
		this->len = pow(pow((p2->getX())-(p1->getX()),2)+pow((p2->getY())-(p1->getY()),2),.5);
	}
}

void Line::setVertex2(point p) {
	*p2 = p;
	if(p1 != nullptr) {
		this->m = ((p1->getY())-(p2->getY()))/((p1->getX())-(p2->getX()));
		this->len = pow(pow((p2->getX())-(p1->getX()),2)+pow((p2->getY())-(p1->getY()),2),.5);
	}
}

Line::Line() {
	this->p1 = new point;
	this->p2 = new point;
	this->m = 0;
	this->len = 0;
}

Line::Line(double x1, double y1, double x2, double y2) {
	this->p1 = new point(x1,y1);
	this->p2 = new point(x2,y2);
	this->m = (y1-y2)/(x1-x2);
	this->len = pow(pow(x2-x1,2)+pow(y2-y1,2),.5);
}

Line::Line(const Line& a) {
	this->p1 = new point;
	this->p2 = new point;

	*(this->p1) = *(a.p1);
	*(this->p2) = *(a.p2);
	this->m = a.m;
	this->len = a.len;
}

Line::~Line() {
	delete this->p1;
	delete this->p2;
}

Line& Line::operator=(const Line& a) {
	if(this != &a) {
		delete this->p1;
		delete this->p2;

		this->p1 = new point;
		this->p2 = new point;

		*(this->p1) = *(a.p1);
		*(this->p2) = *(a.p2);
		this->m = a.m;
		this->len = a.len;
	}
	return *this;
}

// compares the slope of two lines
bool Line::parallel(const Line& a, const Line& b) {
	return (a.m == b.m);
}

// compares the length of two lines
bool operator<(const Line& a, const Line& b) {
	return (a.len < b.len);
}

bool operator==(const Line& a, const Line& b) {
	return (a.len == b.len);
}

bool operator>(const Line& a, const Line& b) {
	return (b<a);
}

// [[x,y],[x,y]]
istream& operator>>(istream& in, Line& a) {
	char b1, c1, b2;
	point pp1, pp2;

	in >> b1 >> pp1 >> c1 >> pp2 >> b2;

	if(b1 == '[' && b2 == ']' && c1 == ',') {
		a.setVertex1(pp1);
		a.setVertex2(pp2);
	} else {
		cout << "Invalid format" << endl;
		in.clear();
	}

	return in;
}

ostream& operator<<(ostream& out, const Line& l) {
	out << "[" << l.getVertex1() << "," << l.getVertex2() << "]" << endl;
	out << fixed << setprecision(2);
	out << "Slope:\t" << l.getSlope() << endl;
	out << "Length:\t" << l.getLength() << endl;
	out << setprecision(0);

	return out;
}


