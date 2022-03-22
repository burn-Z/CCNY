// Spiral Matrix 1

#include <iostream>

using namespace std;

int main() {
	int input[][3] = {{1,2,3},
					  {4,5,6},
					  {7,8,9}};
	bool seen[3][3] = {{false}};

	int firstRow = 0, lastRow = sizeof(input)/sizeof(input[0]) - 1;
	int firstCol = 0, lastCol = sizeof(input[0])/sizeof(input[0][0]) - 1;

	char dir = 'R';
	while(firstRow<=lastRow && firstCol<=lastCol) {
		//Right on first row
		if(dir=='R') {
			for(int i=firstCol;i<=lastCol;i++) {
				if(!seen[firstRow][i]) {
					cout << input[firstRow][i] << " ";
					seen[firstRow][i] = true;
				}
			}
			firstRow++;
			dir = 'D';
		}

		//Down on last Column
		if(dir=='D') {
			for(int i=firstRow;i<=lastRow;i++) {
				if(!seen[i][lastCol]) {
					cout << input[i][lastCol] << " ";
					seen[i][lastCol] = true;
				}
			}
			lastCol--;
			dir = 'L';
		}

		//Left on last row
		if(dir=='L') {
			for(int i=lastCol;i>=firstCol;i--) {
				if(!seen[lastRow][i]) {
					cout << input[lastRow][i] << " ";
					seen[lastRow][i] = true;
				}
			}
			lastRow--;
			dir = 'U';
		}

		//Up on first Column
		if(dir=='U') {
			for(int i=lastRow;i>=firstRow;i--) {
				if(!seen[i][firstCol]) {
					cout << input[i][firstCol] << " ";
					seen[i][firstCol] = true;
				}
			}
			firstCol++;
			dir == 'R';
		}

	}
	cout << endl;

	return 0;
}