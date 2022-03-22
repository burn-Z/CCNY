#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string sourceNum;  //hex number
	int targetNum, source = 16, digit; // decimal number

	do {
		targetNum = 0;


		cin >> sourceNum;
		int snLen = sourceNum.size();
		for(int i=0;i<snLen;i++) {
			if('a' <= sourceNum.at(i) && sourceNum.at(i) <= 'f') {
				digit = sourceNum.at(i) - 'a' + 10;
			}
			else if('A' <= sourceNum.at(i) && sourceNum.at(i) <= 'F') {
				digit = sourceNum.at(i) - 'A' + 10;
			} else {
				digit = sourceNum.at(i)-'0';
			}
			targetNum += digit*pow(source, snLen-i-1);
		}
		cout << targetNum << endl;



	} while(sourceNum!="-1");

	return 0;
}