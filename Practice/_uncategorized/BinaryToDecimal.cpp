// Binary to decimal

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	string sourceNum; //sourceNum<>num1
	int targetNum, source =2, digit;


	do {
		targetNum = 0;


		cout << "Binary: ";
		cin >> sourceNum;

		for(int i=0;i<sourceNum.size();i++) {
			digit = sourceNum.at(i)-'0';
			targetNum += digit*pow(base,sourceNum.size()-i-1);
		}

		cout << "Decimal: " << targetNum << endl;



	} while(sourceNum!="-1");

	return 0;
}