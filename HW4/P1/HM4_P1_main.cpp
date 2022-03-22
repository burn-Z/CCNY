#include <cmath>

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

#include "HM4_P1_point.h"
#include "HM4_P1_Line.h"

void loadLines(string f, vector<Line>& v) {
	ifstream inF;
	inF.open(f);

	if(!inF.is_open()) {
		cout << "Could not open the inF!" << endl;
		return;
	}

	string w, cb, lineString;
	char c1, b1, c2, b2, c3, b3, b4, c4;
	double x1,x2,y1,y2;

	getline(inF, w);
	getline(inF, cb);

	int count = 1;   // used to check line#:
	string temp1;	// used to store line#:
	char temp2;		// stores # of line
	istringstream coord;
	if(w == "lines:" && cb == "{") {
		getline(inF, lineString);
		while(lineString != "}" && !inF.eof()) {
			temp1 = "[line:[";
			temp2 = '0' + count;
			temp1.insert(5,1,temp2);

			if(!inF.fail() && lineString.substr(0,8) == temp1) {

				coord.clear();
				coord.str(lineString.substr(8,lineString.length()-1));

				coord >> x1 >> c1 >> y1 >> b1 >> c2 >> b2 >> x2 >> c3 >>
						y2 >> b3 >> b4 >> c4;

				if(c1 == ',' && b1 == ']' && c2 == ',' && b2 == '['
					&& c3 == ',' && b3 == ']' && b4 == ']') {
					v.push_back(Line(x1,y1,x2,y2));
				}
			}
			getline(inF, lineString);
			count++;
		}
	}
	inF.close();
}

int main() {

//c
	cout << "Testing started" << endl;
	cout << "======================================" << endl;
	Line a;
	cout << "Testing default constructor" << endl;
	cout << "Line a:[[" << a.getVertex1().getX() << "," << a.getVertex1().getY() <<
			"],[" << a.getVertex2().getX() << "," << a.getVertex2().getY() <<
			"]" << endl;
//b
	double ax1 = 1.1, ay1 = 3.6, ax2 = 2.5, ay2 = 6.9;
	point p1(ax1,ay1);
	point p2(ax2,ay2);
	a.setVertex1(p1);
	a.setVertex2(p2);
	cout << "======================================" << endl;
	cout << "Testing setters and getters" << endl;
	cout << "Line a:[[" << ax1 << "," << ay1 << "],[" << ax2 << "," << ay2 << "]] <--> " << endl;
	cout << "[[" << a.getVertex1().getX() << "," << a.getVertex1().getY() <<
			"],[" << a.getVertex2().getX() << "," << a.getVertex2().getY() <<
			"]]" << endl;
	cout << "Slope:\t" << a.getSlope() << endl;
	cout << "Length:\t" << a.getLength() << endl;
//d
	double bx1 = 1, by1 = 1, bx2 = 3, by2 = 3;
	Line b(bx1,by1,bx2,by2);
	cout << "======================================" << endl;
	cout << "Testing overloaded constructor and cout extension" << endl;
	cout << "Line b:[[" << bx1 << "," << by1 << "],[" << bx2 << "," << by2 << "]] <--> " << endl;
	cout << b << endl;
//e
	Line c = a;
	cout << "======================================" << endl;
	cout << "Testing assignment operator" << endl;
	cout << "Line c = a:[[" << ax1 << "," << ay1 << "],[" << ax2 << "," << ay2 << "]] <--> " << endl;
	cout << c << endl;

	Line d(b);
	cout << "Testing assignment operator" << endl;
	cout << "Line d(b):[[" << bx1 << "," << by1 << "],[" << bx2 << "," << by2 << "]] <--> " << endl;
	cout << d << endl;
//f
	double ex3 = -3, ey3 = -3, ex4 = 2, ey4 = 2;
	Line e(ex3,ey3,ex4,ey4);
	Line f;
	cout << "======================================" << endl;
	cout << "Testing parallel function" << endl;
	cout << "Line e:" << e << endl;
	cout << "e parallel to a?\t" << f.parallel(a,e) << endl;
	cout << "e parallel to b?\t" << f.parallel(b,e) << endl;
//g
	cout << "======================================" << endl;
	cout << "Testing comparators" << endl;
	cout << "a>b?\t" << (b>a) << endl;
	cout << "e<b?\t" << (e<b) << endl;
	cout << "c==d\t" << (c==d) << endl;
//h
	vector<Line> Lines;
	string fN = "lines.txt";
	loadLines(fN, Lines);
//i
	sort(Lines.begin(), Lines.end());
	cout << "======================================" << endl;
	cout << "Testing loadLines function" << endl;
	for(size_t i = 0;i<Lines.size();i++) {
		cout << Lines.at(i) << endl;
	}
//j
	cout << "======================================" << endl;
	cout << "Testing cin extension" << endl;
	cout << "Enter 2 lines in the form [[w,x],[y,z]]" << endl;
	vector<Line> moLines;
	Line ll;
	for(int i=0;i<2;i++) {
		cout << "Line " << i+1 << ": ";
		cin >> ll;
		moLines.push_back(ll);
	}

	cout << endl;
	for(int i=0;i<2;i++) {
		cout << moLines.at(i) << endl;
	}

	return 0;
}