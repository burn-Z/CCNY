// Book, title, author, numpages

#include <iostream>
#include <string.h>
using namespace std;

class Book2 {
	public:
		//Book();   // Constructor
		Book2(string title = "No title", string author = "No author" , int numPages = 0);   // overloading constructor
		void setTitle(string title);   // setter
		string getTitle() const;   // getter
		void setAuthor(string author);
		string getAuthor() const;
		void setNumPages(int numPages);
		int getNumpages() const;
		void print();
	private:
		string title;
		string author;
		int numPages;
};

/*
Book::Book() {
	title = "No Title";
	author = "No Author";
	numPages = 0;
}
*/

Book2::Book2(string title, string author, int numPages) {
	this->title = title;
	this->author = author;
	this->numPages = numPages;
}

void Book2::setTitle(string title){
	this->title = title;
}
string Book2::getTitle() const {
	return this->title;   // (this->) not needed but code is more readable
}

void Book2::setAuthor(string author) {
	this->author = author;
}
string Book2::getAuthor() const {
	return author;
}

void Book2::setNumPages(int numPages) {
	this->numPages = numPages;
}
int Book2::getNumpages() const {
	return numPages;
}

void Book2::print() {
	cout << this->getTitle() << endl;
	cout << this->getAuthor() << endl;
	cout << this->getNumpages() << endl;
}

bool operator==(const Book2& lb, const Book2& rb) {
	return lb.getTitle()==rb.getTitle();
}

bool operator<(const Book2& lb, const Book2& rb) {
	return lb.getTitle()<rb.getTitle();
}

bool operator!=(const Book2& lb, const Book2& rb) {
	return !(lb==rb);
}

bool operator>(const Book2& lb, const Book2& rb) {
	return rb<lb;
}

bool operator<=(const Book2& lb, const Book2& rb) {
	return !(lb>rb);
}

bool operator>=(const Book2& lb, const Book2& rb) {
	return !(lb<rb);
}

int main() {
	Book2 b1("The little princ", "B", 121);
	Book2 b2("The little prince","A.S",120);

	cout << "==\t" << (b1==b2) << endl;
	cout << "!=\t" << (b1!=b2) << endl;
	cout << "<=\t" << (b1<=b2) << endl;
	cout << ">=\t" << (b1>=b2) << endl;
	cout << "<\t" << (b1<b2) << endl;
	cout << ">\t" << (b1>b2) << endl;
	//b.print();
	//c.print();

	//b.setTitle("The little prince");
	//b.setAuthor("A.S");
	//b.setNumPages(120);

	//cout << b.getTitle() << endl;
	//cout << b.getAuthor() << endl;
	//cout << b.getNumpages() << endl;


	return 0;
}