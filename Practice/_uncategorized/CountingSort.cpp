/*	Counting sort
	Variation 2: Cummulative Summation count sort

ALGORITHM:	iterates through the input, counting the number
			of times each item occurs, and using those counts
			to compute an item's index in the final sorted array
*/

/*
STRENGTHS:	runs in O(n) time, making it asymptotically faster
			faster than comparison-based sorting algorithms like
			quicksort or merge sort
WEAKNESSES:	only works for known range of inputs
			needs a lot of space for big ranges
*/

#include <iostream>
#include <vector>
using namespace std;

/*
int main() {

	vector<int> input = {1,3,7,8,1,1,3}
	//0-10
	vector<int> counts(11), output;

	for(int i=0;i<input.size();i++) {
		count.at(input.at(i))++;
	}

	for(int i=0;i<counts.size();i++) {
		for(int j=0;j<counts.at(i);i++) {
			output.push_back(i);
		}
	}

	for(int i=0;i<output.size();i++){
		cout << output.at(i) << " ";
	}
	return 0;
}
*/

////////////////////////////////////////////////////////////////////////////////////

/*Variation 2
ALGORITHM:	stores a cummulative count
*/

/*
int main() {

	int input[] = {1,3,7,8,1,1,3};
	int counts[11] = {0};
	int ouput[sizeof(input)/sizeof(input[0])];

	for(int i=0;i<sizeof(input)/sizeof(input[0]);i++) {
		counts[input[i]]++;
	}

	for(int i =1;i<sizeof(counts)/sizeof(counts[0]);i++) {
		counts[i] += counts[i-1];
	}

	for(int i=0;i<sizeof(input)/sizeof(input[0]);i++) {
		output[counts[input[i]]-1] = input[i];
		counts[input[i]]--;
	}

	for(int i=0;i<sizeof(output)/sizeof(output[0]);i++) {
		cout << ouput[i] << " ";
	}

	return 0;
}
*/