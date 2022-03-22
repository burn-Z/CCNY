// DiagonalTraverseMatrix

#include <iostream>

using namespace std;

int main() {
	int input[3][3] = {{1,2,6},
					   {3,5,7},
					   {4,8,9}};

	int maxCol = sizeof(input[0])/sizeof(input[0][0]) - 1;
	int maxRow = sizeof(input)/sizeof(input[0]) - 1;

	int curCol = 0, curRow = 0;

	string dir = "DU";   // diagonally up
	while(curRow<=maxRow && curCol<=maxCol) {

		if(dir=="DU") {
			cout << input[curRow][curCol] << " ";
			while(curCol<maxCol && curRow>0) {
				curCol++;
				curRow--;
				cout << input[curRow][curCol] << " ";
			}
			if(curCol == maxCol) dir = "D";
			else dir = "R";
		}

		if(dir=="DD") {
			cout << input[curRow][curCol] << " ";
			while(curCol>0 && curRow<maxRow) {
				curCol--;
				curRow++;
				cout << input[curRow][curCol] << " ";
			}
			if(curRow == maxRow) dir = "R";
			else dir = "D";
		}

		if(dir=="R") {
			curCol++;
			if(curRow == maxRow) dir = "DU";
			else dir = "DD";
		}

		if(dir=="D") {
			curRow++;
			if(curCol == maxCol) dir = "DD";
			else dir = "DU";
		}

	}

	cout << endl;
	return 0;
}