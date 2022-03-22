#include <iostream>
#include <vector>

#include "HM3_MatrixProcs.h"


//c
// iterates over all elements of the array and prints them
void print(int a[][N]) {
	for(int r=0;r<N;r++) {
		for(int c=0;c<N;c++) {
			cout << a[r][c] << (c!=(N-1)? "\t":"");
		}
		cout << endl;
	}

	return;
}

//d
// the function returns false when the first
// unequal elements are found
bool areEqual(int a[][N],int b[][N]) {
	for(int r=0;r<N;r++) {
		for(int c=0;c<N;c++) {
			if(a[r][c] != b[r][c]) return false;

		}
	}
	return true;
}

//e
// the function returns false when the first non-diagonal
// element != 1 or any other element != 0
bool isIdentity(int a[][N]) {
	for(int r=0;r<N;r++) {
		for(int c=0;c<N;c++) {
			if((r==c && a[r][c] != 1) || (r!=c && a[r][c] != 0))
				return false;
		}
	}
	return true;
}

//f
// iterates over every element, checks if they are even or odd
// then stores them in a vector of size 2 where entries 1 and 2
// are the number of evens and odds, respectively
bool isEven(const int ij) {
	if(ij%2) return false;

	return true;
}

void evenAndOdd(int a[][N], int& numOfEvens, int& numOfOdds) {
	for(int r=0;r<N;r++) {
		for(int c=0;c<N;c++) {
			if(isEven(a[r][c]))
				numOfEvens++;
			else
				numOfOdds++;
		}
	}
}

//g
// iterates, sums up each element of each column
// of the array
vector<int> sumOfColumns(int a[][N]) {
	vector<int> sumOfCol(N,0);

	for(int r=0;r<N;r++) {
		for(int c=0;c<N;c++) {
            sumOfCol.at(c)+=a[r][c];
		}
	}

	return sumOfCol;
}

//h
// sums up the rows of a
int* sumOfRows(int a[][N]) {
	static int sumOfRo[N];

	for(int r=0;r<N;r++) {
		for(int c=0;c<N;c++) {
            sumOfRo[r]+=a[r][c];
		}
	}

	return sumOfRo;
}

//i
// sorts by row then by column in place
void sortByRowAndColumn(int (*a)[N]) { //int *a

	int temp, k;

	// sort by row
	for(int r=0;r<N;r++) {
	    for(int c=1;c<N;c++) {
	        k = 0;
	        // compares each element to all previous elements
	        // in the row and switches them if the latest element
	        // is less than the earliest element
	        while((a[r][c-k-1]>a[r][c-k])  && (c>=k+1)) {
	            temp = a[r][c-k];
	            a[r][c-k] = a[r][c-k-1];
	            a[r][c-k-1] = temp;
	            k++;
	        }
	    }
	}
	////////////////////////////////////////////////////////////////////

	// sort by column
	for(int r=1;r<N;r++) {
	    for(int c=0;c<N;c++) {
	        k = 0;
	        // compares each element to all previous elements
	        // in the column and switches them if the latest element
	        // is less than the earliest element
	        while((k<=r-1) && (a[r-k-1][c]>a[r-k][c])) {
	            temp = a[r-k][c];
	            a[r-k][c] = a[r-k-1][c];
	            a[r-k-1][c] = temp;
	            k++;
	        }
	    }
	}

	return;
}