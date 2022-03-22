#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ostream>
#include <istream>
#include <iomanip>
#include "point.hpp"
#include "triangle.hpp"



using namespace std;

void loadTriangles(string fN, vector<triangle>& Triangles) {
	ifstream inFs;
	inFs.open(fN);

	if(!inFs.is_open()) {
		cout << "Could not open the file!" << endl;
		return;
	}

	char d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13;
	double p1x, p1y, p2x, p2y, p3x, p3y;
	while(!inFs.eof()) {
		inFs >> d1 >> d2 >> p1x >> d3 >> p1y >> d4 >> d5 >> d6
			 >> p2x >> d7 >> p2y >> d8 >> d9 >> d10 >> p3x
			 >> d11 >> p3y >> d12 >> d13;
		if(!inFs.fail() && d1 == '{' && d2 == '(' && d3 == ',' && d4 == ')'
		   && d5 == ',' && d6 == '(' && d7 == ',' && d8 == ')' && d9 == ','
			&& d10 == '(' && d11 == ',' && d12 == ')' && d13 == '}') {
			Triangles.push_back(triangle(p1x, p1y, p2x, p2y, p3x, p3y));
		}
	}
	inFs.close();
}

void outputTriangles(ostream &oS, vector<triangle>& Triangles) {
	oS << setfill('*') << setw(47) << "" << endl;
	oS << setfill(' ');
	oS << left << setw(15) << "Vertex 1" << setw(15) << "Vertex 2"
	   << setw(15) << "Vertex 3" << endl;
	oS << setfill('*') << setw(47) << "" << endl;
	oS << setfill(' ');

	for(size_t i=0;i<Triangles.size();i++) {
		oS << left << setw(15) << Triangles.at(i).getVertices()[0].print()
		   << setw(15) << Triangles.at(i).getVertices()[1].print()
		   << setw(15) << Triangles.at(i).getVertices()[2].print()
		   << endl;
	}

	oS << setfill('*') << setw(47) << "" << endl;
	oS << setfill(' ');
}

void writeTriangles(string oFileName,vector<triangle>& Triangles) {
	ofstream outFS;
	outFS.open(oFileName);

	if(!outFS.is_open()) {
		cout << "Could not open the output file" << endl;
		return;
	}

	outputTriangles(outFS, Triangles);
	outFS.close();
}

int main() {


	vector<triangle> Triangles;

	// string ifileName = "triangles.txt";
	// loadTriangles(ifileName, Triangles);

	// string oFileName = "triangles_table.txt";
	// outputTriangles(cout, Triangles);
	// writeTriangles(oFileName, Triangles);

/*	for(size_t i = 0;i<Triangles.size();i++) {
		Triangles.at(i).print();
	}*/

////////////////////////////////////////////////////
///////TESTING EXTRACTION OPERATOR/////////////////
	cout << "Enter (2)triangle vertices" << endl;
	cout << "Format: {(a,b),(c,d),(e,f)}" << endl << endl;

	triangle t;
	for(int i = 0;i<2;i++) {
		cin >> t;
		Triangles.push_back(t);
	}
	cout << endl;
////////////////////////////////////////////////////
	for(size_t i = 0;i<Triangles.size();i++) {
		cout << Triangles.at(i) << endl;
	}

	return 0;
}