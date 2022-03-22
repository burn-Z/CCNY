#include <iostream>
#include "point.hpp"

using namespace std;

#ifndef TRIANGLE_H
#define TRIANGLE_H

class triangle {
public:
	//triangle(point& p1, point& p2, point& p3);
	triangle(double p1x, double p1y,double p2x, double p2y, double p3x, double p3y);
	triangle(const triangle& t);  //overload copy constructor
	~triangle();   // destructor
	triangle& operator=(const triangle& t);
	void setVertex1(point p) {	this->vertices[0] = p;	}
	point getVertex1() {	return vertices[0];	}
	void setVertex2(point p) {	this->vertices[1] = p;	}
	point getVertex2() {	return vertices[1];	}
	void setVertex3(point p) {	this->vertices[2] = p;	}
	point getVertex3() {	return vertices[2];	}
	void print();
	friend void print(triangle t);
private:
	// point* vertex1;
	// point* vertex2;
	// point* vertex3;
	point* vertices;

};

/*// this doesn't work with destructor;
triangle::triangle(point& p1, point& p2, point& p3) {
	// this->vertex1 = &p1;
	// this->vertex2 = &p2;
	// this->vertex3 = &p3;
}
*/
triangle::triangle(double p1x, double p1y,double p2x, double p2y, double p3x, double p3y) {
	// this->vertex1 = new point(p1x, p1y);
	// this->vertex2 = new point(p2x, p2y);
	// this->vertex3 = new point(p3x, p3y);
	this->vertices = new point[3];

	this->vertices[0].setX(p1x);
	this->vertices[0].setY(p1y);
	this->vertices[1].setX(p2x);
	this->vertices[1].setY(p2y);
	this->vertices[2].setX(p3x);
	this->vertices[2].setY(p3y);
}

triangle::triangle(const triangle& t) {
/*	this->vertex1 = new point;
	this->vertex2 = new point;
	this->vertex3 = new point;*/
	this->vertices = new point[3];

/*	*(this->vertex1) = *(t.vertex1);
	*(this->vertex2) = *(t.vertex2);
	*(this->vertex3) = *(t.vertex3);*/
	this->vertices[0] = t.vertices[0];
	this->vertices[1] = t.vertices[1];
	this->vertices[2] = t.vertices[2];
}

triangle::~triangle() {
/*	delete this->vertex1;
	delete this->vertex2;
	delete this->vertex3;*/
	delete[] this-> vertices;

}

triangle& triangle::operator=(const triangle& t) {
	if(this != &t) {
/*		delete this->vertex1;
		delete this->vertex2;
		delete this->vertex3;*/
		delete[] this-> vertices;

/*		this->vertex1 = new point;
		this->vertex2 = new point;
		this->vertex3 = new point;*/
		this->vertices = new point[3];

/*		*(this->vertex1) = *(t.vertex1);
		*(this->vertex2) = *(t.vertex2);
		*(this->vertex3) = *(t.vertex3);*/
		this->vertices[0] = t.vertices[0];
		this->vertices[1] = t.vertices[1];
		this->vertices[2] = t.vertices[2];
	}
	return *this;
}

void triangle::print() {
	// cout << "vertex1: ";
	// this->vertex1->print();
	// cout << "vertex2: ";
	// this->vertex2->print();
	// cout << "vertex3: ";
	// this->vertex3->print();
	for(int i=0;i<3;i++) {;
		cout << "vertex" << i+1 << ": ";
		this->vertices[i].print();
	}
}

void print(triangle t) {
	t.print();
}


#endif