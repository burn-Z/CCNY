#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int main() {
	string sourceNum;
	cin >> sourceNum;

	string tNbin, tN;   // target number in binary and target number

	// Hexadecimal to 3-digit binary
	int digit;   // stores each character of sourceNum as an int
	for(int i=sourceNum.length()-1;i>=0;i--) {
		digit = 0;
		if('a' <= sourceNum.at(i) && sourceNum.at(i) <= 'f') digit = sourceNum.at(i) - 'a' + 10;
		else if('A' <= sourceNum.at(i) && sourceNum.at(i) <= 'F') digit = sourceNum.at(i) - 'A' + 10;
		else digit = sourceNum.at(i)-'0';

		// converts each digit to binary
	    while(digit>0) {
	    	char sNchar = '0' + (digit%2);
	        tNbin.insert(0,1,sNchar);
	        digit /= 2;
	    }
	}

	//	Binary to Octal
	int xpo=0, sum=0;   // exponent to convert binary to octal digit
	char s;   // stores sum as character
	for(int i=tNbin.length()-1;i>=0;i--) {
		sum += (tNbin.at(i)-'0') * pow(2,xpo);   // sums each 3 bin digits
		xpo++;

		if(xpo==3) {
			s = '0' + sum;
			tN.insert(0,1,s);
			sum=0;
			xpo = 0; //resets exponent to 0
		}
	}

	cout << "Octal: " << tN << endl;

	return 0;
}