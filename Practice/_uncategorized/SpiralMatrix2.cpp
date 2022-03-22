// Spiral Matrix 1

#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int input[n][n];

	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			input[i][j] = 0;
		}
	}

	int firstRow = 0, lastRow = sizeof(input)/sizeof(input[0])-1;
	int firstCol = 0, lastCol = sizeof(input[0])/sizeof(input[0][0])-1;

	char dir = 'R';
	int counter = 1;
	while(firstRow<=lastRow && firstCol<=lastCol) {

		//Right on first row
		if(dir=='R') {
			for(int i=firstCol;i<=lastCol;i++) {
				if(input[firstRow][i]==0) {
					input[firstRow][i] = counter;
					counter++;
				}
			}
			firstRow++;
			dir = 'D';
		}

		//Down on last Column
		if(dir=='D') {
			for(int i=firstRow;i<=lastRow;i++) {
				if(input[i][lastCol]==0) {
					input[i][lastCol] = counter;
					counter++;
				}
			}
			lastCol--;
			dir = 'L';
		}

		//Left on last row
		if(dir=='L') {
			for(int i=lastCol;i>=firstCol;i--) {
				if(input[lastRow][i]==0) {
					input[lastRow][i] = counter;
					counter++;
				}
			}
			lastRow--;
			dir = 'U';
		}

		//up on first Column
		if(dir=='U') {
			for(int i=lastRow;i>=firstRow;i--) {
				if(input[i][firstCol]==0) {
					input[i][firstCol] = counter;
					counter++;
				}
			}
			firstCol++;
			dir == 'R';
		}
	}

	for(int i=0;i<sizeof(input)/sizeof(input[0]);i++) {
		for(int j=0;j<sizeof(input[0])/sizeof(input[0][0]);j++) {
			cout << input[i][j] << "\t";
		}
		cout << endl;
	}
	return 0;
}