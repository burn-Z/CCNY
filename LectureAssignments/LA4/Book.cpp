// Book, title, author, numpages

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

class Book {
	public:
		//Book();   // Constructor
		Book(string title = "No title", string author = "No author" , int numPages = 0);   // overloading constructor
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

Book::Book(string title, string author, int numPages) {
	this->title = title;
	this->author = author;
	this->numPages = numPages;
}

void Book::setTitle(string title){
	this->title = title;
}
string Book::getTitle() const {
	return this->title;   // (this->) not needed but code is more readable
}

void Book::setAuthor(string author) {
	this->author = author;
}
string Book::getAuthor() const {
	return author;
}

void Book::setNumPages(int numPages) {
	this->numPages = numPages;
}
int Book::getNumpages() const {
	return numPages;
}

void Book::print() {
	cout << this->getTitle() << endl;
	cout << this->getAuthor() << endl;
	cout << this->getNumpages() << endl;
}

bool operator==(const Book& lb, const Book& rb) {
	return lb.getTitle()==rb.getTitle();
}

bool operator<(const Book& lb, const Book& rb) {
	return lb.getTitle()<rb.getTitle();
}

bool operator!=(const Book& lb, const Book& rb) {
	return !(lb==rb);
}

bool operator>(const Book& lb, const Book& rb) {
	return rb<lb;
}

bool operator<=(const Book& lb, const Book& rb) {
	return !(lb>rb);
}

bool operator>=(const Book& lb, const Book& rb) {
	return !(lb<rb);
}

int main() {
	vector<Book> v;
	v.push_back(Book("The little princ", "B", 121));
	v.push_back(Book("The little prince","A.S",120));
	v.push_back(Book("A thousand cries", "K.D", 1));
	v.push_back(Book("Live!", "B.K", 22));

	sort(v.begin(),v.end());

	for(int i =0;i<4;i++) {
		cout << "Book " << i << endl;
		cout << "Title: " << v.at(i).getTitle() << endl;
		cout << "Author: " << v.at(i).getAuthor() << endl;
		cout << "Number of Pages: " << v.at(i).getNumpages() << endl;
		cout << endl;
	}

	// cout << "==\t" << (b1==b2) << endl;
	// cout << "!=\t" << (b1!=b2) << endl;
	// cout << "<=\t" << (b1<=b2) << endl;
	// cout << ">=\t" << (b1>=b2) << endl;
	// cout << "<\t" << (b1<b2) << endl;
	// cout << ">\t" << (b1>b2) << endl;


	return 0;
}