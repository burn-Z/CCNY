// Book, title, author, numpages

#include <iostream>
#include <string.h>
using namespace std;

class Book1 {
	public:
		//Book();   // Constructor
		Book1(string t = "No title", string a = "No author" , int n = 0);   // overloading constructor
		void setTitle(string t);   // setter
		string getTitle() const;   // getter
		void setAuthor(string a);
		string getAuthor() const;
		void setNumPages(int n);
		int getNumpages() const;
		void print();
	private:
		string title;
		string author;
		int numPages;
};

/*
Book1::Book1() {
	title = "No Title";
	author = "No Author";
	numPages = 0;
}
*/

Book1::Book1(string t, string a, int n) {
	title = t;
	author = a;
	numPages = n;
}

void Book1::setTitle(string t){
	title = t;
}
string Book1::getTitle() const {
	return title;
}

void Book1::setAuthor(string a) {
	author  = a;
}
string Book1::getAuthor() const {
	return author;
}

void Book1::setNumPages(int n) {
	numPages = n;
}
int Book1::getNumpages() const {
	return numPages;
}

void Book1::print() {
	cout << title << endl;
	cout << author << endl;
	cout << numPages << endl;
}

int main() {
	Book1 b;
	Book1 c("The little prince","A.S",120);

	b.print();
	c.print();

	//b.setTitle("The little prince");
	//b.setAuthor("A.S");
	//b.setNumPages(120);

	//cout << b.getTitle() << endl;
	//cout << b.getAuthor() << endl;
	//cout << b.getNumpages() << endl;


	return 0;
}