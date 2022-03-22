// Transpose a Matrix over the right diagonal(/)

#include <iostream>

using namespace std;

int main() {
	int input[][3] = {{1,2,3},
					  {4,5,6},
					  {7,8,9}};

	int temp;

	for(int r=0;r<3;r++) {
		for(int c=2-r;c<3;c++) {
			temp = input[r][c];
			input[r][c] = input[2-c][2-r];
			input[2-c][2-r] = temp;
		}
	}

	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			cout << input[i][j] << "\t";
		}
		cout << endl;
	}

	cout << endl;
	return 0;
}