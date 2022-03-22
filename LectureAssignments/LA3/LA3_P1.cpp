// Insertion sort to decreasing order
/*
The code is mostly the same, the only difference is that when comparing two adjacent
elements, we test for greatest rather than smallest, then move it to the front of the array
*/

#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> input = {8,3,2,7,9,1,4};

	int index;   // iterator for while loop
	int temp;
	for(int i=1;i<input.size();i++) {
		index = i;
		while(index>0 && input.at(index) > input.at(index-1)) { // switched < to > after &&
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