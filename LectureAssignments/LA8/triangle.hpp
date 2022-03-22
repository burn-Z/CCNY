#include <iostream>
#include "point.hpp"

using namespace std;

#ifndef TRIANGLE_H
#define TRIANGLE_H

class triangle {
public:
	triangle(double p1x = 0, double p1y = 0, double p2x = 0,
			 double p2y = 0, double p3x = 0, double p3y = 0);
	triangle(const triangle& t);  //overload copy constructor
	~triangle();   // destructor
	triangle& operator=(const triangle& t);
	void setVertex1(point p) {	this->vertices[0] = p;	}
	point getVertex1() {	return vertices[0];	}
	void setVertex2(point p) {	this->vertices[1] = p;	}
	point getVertex2() {	return vertices[1];	}
	void setVertex3(point p) {	this->vertices[2] = p;	}
	point getVertex3() {	return vertices[2];	}
	point* getVertices() {	return this->vertices;	}
	//void print();
	//friend void print(triangle t);
	friend ostream& operator<<(ostream& out, const triangle& T);
	friend istream& operator>>(istream& in, triangle& T);
private:
	point* vertices;

};

triangle::triangle(double p1x, double p1y,double p2x, double p2y, double p3x, double p3y) {
	this->vertices = new point[3];

	this->vertices[0].setX(p1x);
	this->vertices[0].setY(p1y);
	this->vertices[1].setX(p2x);
	this->vertices[1].setY(p2y);
	this->vertices[2].setX(p3x);
	this->vertices[2].setY(p3y);
}

triangle::triangle(const triangle& t) {
	this->vertices = new point[3];

	this->vertices[0] = t.vertices[0];
	this->vertices[1] = t.vertices[1];
	this->vertices[2] = t.vertices[2];
}

triangle::~triangle() {
	delete[] this-> vertices;
}

triangle& triangle::operator=(const triangle& t) {
	if(this != &t) {
		delete[] this-> vertices;

		this->vertices = new point[3];

		this->vertices[0] = t.vertices[0];
		this->vertices[1] = t.vertices[1];
		this->vertices[2] = t.vertices[2];
	}
	return *this;
}

ostream& operator<<(ostream& out, const triangle& T) {
	out << "{" << T.vertices[0].print() << ","
			   << T.vertices[1].print() << ","
			   << T.vertices[2].print() << "}";

	return out;
}

///////////////////////////////////////////////////////
istream& operator>>(istream& in, triangle& T) {
	//{,,}
	char b1, c1, c2, b2;

	in >> b1 >> T.vertices[0] >> c1 >> T.vertices[1] >> c2
	   >> T.vertices[2] >> b2;

	return in;
}
//////////////////////////////////////////////////////
/*void triangle::print() {
	cout << "{";
	for(int i=0;i<3;i++) {;
		//cout << "vertex" << i+1 << ": ";
		this->vertices[i].print();
		cout << (i!=2? ",":"");
	}
	cout << "}" << endl;

}*/

/*void print(triangle t) {
	t.print();
}*/


#endif