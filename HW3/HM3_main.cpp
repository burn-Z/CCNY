#include <iostream>
#include <vector>

#include "HM3_MatrixProcs.h"


int main() {


int A[N][N], B[N][N];

// user inputs matrix A
cout << "Input matrix A elements" << endl;
for(int i=0;i<N;i++) {
	for(int j=0;j<N;j++) {
		cout << "A(" << i << "," << j << "): ";
		cin >> A[i][j];
	}
}

cout <<"==================================" << endl;

// user inputs matrix B
cout << "Input matrix B elements" << endl;
for(int i=0;i<N;i++) {
	for(int j=0;j<N;j++) {
		cout << "B(" << i << "," << j << "): ";
		cin >> B[i][j];
	}
}

cout <<"==================================" << endl;
cout <<"TESTING STARTED: N = 4" << endl;
cout <<"==================================" << endl;

///////////////////////////////////////////////////////

cout << "Parts (a), (b) and (c)" << endl;
cout << "TESTING: print() function" << endl;

cout << "Matrix A" << endl;
print(A);

cout << "\nMatrix B" << endl;
print(B);


cout <<"==================================" << endl;
////////////////////////////////////////////////////////

//testing areEqual()
cout << "TESTING: areEqual()" << endl;
cout << areEqual(A,B) << endl;

////////////////////////////////////////////////////////////////////

//testing isIdentity()
cout << "TESTING: isIdentity()" << endl;
cout << "A:\t" << isIdentity(A) << endl;
cout << "B:\t" << isIdentity(B) << endl;

////////////////////////////////////////////////////////////////////

//testing evenAndOdd()
int evensA = 0, oddsA = 0;
int evensB = 0, oddsB = 0;
evenAndOdd(A, evensA, oddsA);
evenAndOdd(B, evensB, oddsB);
cout << "TESTING: evenAndOdd()" << endl;
cout << "A: " << evensA << " even numbers and "
     << oddsA << " odd numbers" << endl;
cout << "B: " << evensB << " even numbers and "
     << oddsB << " odd numbers" << endl;

////////////////////////////////////////////////////////////////////

//testing sumOfColumns()
vector<int> sOcA = sumOfColumns(A);
vector<int> sOcB = sumOfColumns(B);
cout << "TESTING: sumOfColumns()" << endl;
cout << "Sum of columns in A:";
for(int i=0;i<N;i++) cout << " " << sOcA[i];
cout << "\nSum of columns in B:";
for(int i=0;i<N;i++) cout << " " << sOcB[i];
cout << endl;

////////////////////////////////////////////////////////////////////

//testing sumOfRows()
int *sOrA = sumOfRows(A);
cout << "TESTING: sumOfRows()" << endl;
cout << "Sum of Rows in A\n" << endl;
for(int i=0;i<N;i++) cout << sOrA[i] << endl;

/////////////////////////////////////////////////////////////////////

//testing sortByRowAndColumn()
cout << "TESTING: sortByRowAndColumn()" << endl;
cout << "A" << endl;
sortByRowAndColumn(A);
print(A);

////////////////////////////////////////////////////////////////////

cout <<"==================================" << endl;
cout <<"TESTING ENDED" << endl;


return 0;
}