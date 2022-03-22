/*	Selection sort

ALGORITHM:	selects the smallest element and moves it to the front
*/

/*
STRENGTHS:	space efficient, requires a constant O(1) space
WEAKNESSES:	slow, O(n^2) time, too slow for big data sets
*/

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main() {
	vector<int> input ={8,3,2,7,9,1,4};
	int smallest, temp, index, count=0, size = input.size();

	while(count<size) {
		// finds smallest value
		smallest = INT_MAX;
		for(int i=count;i<size;i++) {
			if(smallest > input.at(i)) {
				smallest = input.at(i);
				index = i;
			}
		}

		temp = input.at(count);
		input.at(count) = smallest;
		input.at(index) = temp;

		count++;
	}

	for(int i=0;i<size;i++)
		cout << input.at(i) << " ";
	cout << endl;

	return 0;
}