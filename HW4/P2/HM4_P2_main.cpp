#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct Product
{
	string description;	// Product description
	int partNum;		// Part number
	double cost;		// Product cost

	Product(): description(""), partNum(0), cost(0) {};
	Product(string d, int p, double c):
			description(d), partNum(p), cost(c) {};
	void Print() const;
};

//b
void Product::Print() const {
	cout << endl << "Description: " << description << endl;
	cout << "Number: " << partNum << endl;
	cout << "Part Cost: $" << cost << endl;
}

const int S = 5;
//d
void print(Product**);
//e
Product* findMax(Product*);
//g
void outputProducts(ostream&,Product***);
//f
void readProducts(string, Product**&); //populates dynamic array
void writeProducts(string, Product**&);


int main() {
	//c
	Product* items = new Product[S];

	string d;
	int pN;
	double c;
	cout << "Enter item information" << endl;
	for(int i=0;i<S;i++) {
		cout << endl << "Enter description: ";
		getline(cin,d);

		cout << "Enter part number: ";
		cin >> pN;

		cout << "Enter cost: ";
		cin >> c;

		cin.ignore();
		*(items+i) = Product(d,pN,c);
	}

	//d
	cout << endl << "==============================" << endl;
	cout << "(d)Testing print function" << endl;
	print(&items);

	//e
	cout << endl << "==============================" << endl;
	cout << "(e)Testing findMax function" << endl;
	findMax(items)->Print();

	//f
	Product** tbt = new Product*[3];
	for(int i=0;i<3;i++) tbt[i] = new Product[3];
	string ifN = "Poptbt.txt";
	readProducts(ifN, tbt); //using a file to populate array

	//g
	cout << endl << "============================================================" << endl;
	cout << "(g)Testing with cout stream" << endl;
	outputProducts(cout, &tbt);

	//h
	string ofN = "Testbench.txt";
	cout << endl << "============================================================" << endl;
	cout << "Writing matrix into: Testbench.txt" << endl;
	writeProducts(ofN, tbt);

	delete[] items;
	delete[] *tbt;
	delete[] tbt;
	return 0;
}

void print(Product** p) {
	Product* cp = *p;
	for(int r=0;r<S;r++) {
		cp[r].Print();
	}
	return;
}

Product* findMax(Product* p) {
	static Product max = *p;

	for(int i=0;i<S;i++) {
		if(p[i].cost > max.cost) max = *(p+i);
	}

	return &max;
}

void outputProducts(ostream& out,Product*** rcp) {
	Product** p = *rcp;
	for(int r=0;r<3;r++) {
		out << setfill('-') << setw(91) << "" << endl;
		out << setfill(' ');
		for (int c=0;c<3;++c) {
			out << setw(15) << left << "|Description:";
			out << setw(15) << left << p[r][c].description;
		}
		out << "|" << endl;
		for (int c=0;c<3;++c) {
			out << setw(15) << left << "|Part Num:";
			out << setw(15) << left << p[r][c].partNum;
		}
		out << "|" << endl;
		for (int c=0;c<3;++c) {
			out << setw(15) << left << "|Cost:";
			out << setw(15) << left << p[r][c].cost;
		}
		out << "|" << endl;
	}
	out << setfill('-') << setw(91) << "" << endl;
	out << setfill(' ');
	return;
}

void readProducts(string fN, Product**& p) {
	ifstream inFs;
	inFs.open(fN);
	if(!inFs.is_open()) {
		cout << "Could not open the file!" << endl;
		return;
	}

	string d;
	int pN;
	double c;
	for(int ro=0;ro<3;ro++) {
		for(int col=0;col<3;col++) {
			inFs >> d >> pN >> c;

			if(!inFs.fail()) p[ro][col] = Product(d,pN,c);
		}
	}
	inFs.close();
}

void writeProducts(string fN, Product**& p) { //output file stream
	ofstream outFs;
	outFs.open(fN);
	if(!outFs.is_open()) {
		cout << "Could not open the file!" << endl;
		return;
	}
	outputProducts(outFs, &p);
	outFs.close();
	return;
}