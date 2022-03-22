#include <iostream>
#include "point.hpp"
#include "triangle.hpp"

using namespace std;

int main() {
	point p1(1,1);
	point p2(2,2);
	point p3(3,3);

	//triangle t1(p1, p2, p3);
	//t1.print();

	//triangle t2(1,1,2,2,3,3);
	//t2.print();
	//print(t2);   //  copy constructor is called

	//triangle t3(0,0,0,0,0,0);
	//t3 = t2;
	//t3.print();

	triangle t4(0,0,0,0,0,0);
	t4.setVertex1(p1);
	t4.setVertex2(p2);
	t4.setVertex3(p3);

	t4.print();

	return 0;
}