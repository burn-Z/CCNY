/*	Insertion Sort


ALGORITHM:	inserts elements from an unsorted array into a sorted
			subsection of the array, one item at a time
*/

/*
STRENGTHS:	space efficient, O(1) space since it is done in place
WEAKNESSES:	slow, O(n^2) time, too slow for big data sets
*/

#include<iostream>
#include<vector>

using namespace std;

//*
int main() {

	vector<int> input = {8,3,2,7,9,1,4};

	int index;   // iterator for while loop
	int temp;
	for(int i=1;i<input.size();i++) {
		index = i;
		while(index>0 && input.at(index) < input.at(index-1)) {
			temp = input.at(index);
			input.at(index) = input.at(index-1);
			input.at(index-1) = temp;
			index--;
		}
	}

	for(int i=0;i<input.size();i++)
		cout << input.at(i) << " ";

	cout << endl;
	return 0;
}
//*/

//////////////////////////////////////////////////////////////////////////

/*
	Variation 2: finds the right spot for the element
*/

/*
int main() {

	vector<int> input = {8,3,2,7,9,1,4};

	int temp, index;
	for(int i=1;i<input.size();i++){
		temp = input.at(i);
		index = i-1;
		while(index>=0 && temp < input.at(index)) {
			input.at(index+1) = input.at(index);
			index--;
		}
		input.at(++index) = temp;
	}

	for(int i=0;i<input.size();i++)
		cout << input.at(i) << " ";

	return 0;
}
*/