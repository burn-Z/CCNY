#include<iostream>
#include "HM5_P2_Stack.hpp"

using namespace std;

int main() {
	Stack<string> cups; // using cups for better visualization

	cout << "Empty stack of cups? " << cups.empty() << endl;
	cout << "Number of cups: " << cups.size() << endl;
	cout << "Removing top cup...";
	cups.pop();

	cout << endl << "Add 3 to stack:(color)" << endl;

	string temp;
	for(int i=0;i<3;i++) {
		cout << "Add cup "<< i+1 << ": ";
		cin >> temp;
		cups.push(temp);
	}

	cout << endl << "Empty stack of cups? " << cups.empty() << endl;
	cout << "Number of cups: " << cups.size() << endl;
	cout << "Accessing top cup: " << cups.top() << endl;

	cout << "Removing top cup..." << endl;
	cups.pop();
	cout << "Accessing top cup: " << cups.top() << endl;

	return 0;
}