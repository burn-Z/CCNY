#include <iostream>
#include <string>

using namespace std;

class A{
public:
	void setA1(int a1) {	this->a1 = a1;	}
	int getA1() const {	return this->a1;	}
	virtual void print() {
		cout << getA1() << ", " << getA2() << ", " << getB1() << endl;
	}
protected:
	void setA2(int a2) {	this->a2 = a2;	}
	int getA2() const {	return this->a2;	}
private:
	int a1 = 0;
	string a2 = "";
};

/*default inheritance is private
-public and protected of base are priv of derived
-functions of A cannot be accessed through an object of B
*/

/* protected inheritance
public/protected of base are protected of derived
functions of A inacessible through B
*/

/*class B : protected A{
public:
	void setB1(double b1) {	this->b1 = b1;	}
	double getB1() const {	return this->b1;	}
	void print() override {
		cout << getA1() << ", " << getA2() << ", " << getB1() << endl;
	}
private:
	double b1 = 0;
}*/
class B {
public:
	void setB1(double b1) {	this->b1 = b1;	}
	double getB1() const {	return this->b1;	}
private:
	double b1 = 0;
};

class C : public A, public B{
public:
	void setC1(char c1) {	this->c1 = c1;	}
	char getC1() const {	return this->c1;	}
	void modA1(int a1) {	setA1(a1);	}
private:
	char c1 = 'a';
};

int main() {


	return 0;
}