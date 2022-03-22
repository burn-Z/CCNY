/*
Hexadecimal to Octal
Reference:   https://byjus.com/maths/convert-hexadecimal-to-octal/
*/

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int main() {
	int source, target;   // chosen source/target number from menu
	string sourceName, targetName, sourceNum;   // source/target name, number in source system
	int targetNum;  // converted number
	char confirm;   // to comfirm close


	while(true) {
		targetNum = 0;   // for later conversions
/////////////////////////////////////////////////////////////////////////////
////////////////////////MAIN  MENU//////////////////////////////////////////
		cout << "=================================================" << endl;
		cout << "Number System Conversion=========================" << endl;
		cout << "=================================================" << endl;
		cout << "CHOOSE YOUR SOURCE NUMBER SYSTEM:" << endl;
		cout << "(2) BINARY" << endl;
		cout << "(3) TERNARY" << endl;
		cout << "(4) QUATERNARY" << endl;
		cout << "(5) QUINARY" << endl;
		cout << "(6) SENARY" << endl;
		cout << "(7) SEPTENARY" << endl;
		cout << "(8) OCTAL" << endl;
		cout << "(9) NONARY" << endl;
		cout << "(10) DECIMAL" << endl;
		cout << "(16) HEXADECIMAL" << endl;
		cout << "INPUT ANY OTHER VALUE TO EXIT THE PROGRAM" << endl;
		cout << "=================================================" << endl;
/////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
		cin >> source;

		// NAME OF SOURCE SYSTEM FOR FURTHER OUTPUTS
		switch(source) {
			case 2: sourceName = "BINARY:"; break;
			case 3: sourceName = "TERNARY: "; break;
			case 4: sourceName = "QUATERNARY: "; break;
			case 5: sourceName = "QUINARY: "; break;
			case 6: sourceName = "SENARY: "; break;
			case 7: sourceName = "SEPTENARY: "; break;
			case 8: sourceName = "OCTAL: "; break;
			case 9: sourceName = "NONARY: "; break;
			case 10: sourceName = "DECIMAL: "; break;
			case 16: sourceName = "HEXADECIMAL: ";
		}

		// MENU BRANCHING
		switch(source) {
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9: {
				cout << "=================================================" << endl;
				cout << "Source Number System: " << source << "==========================" << endl;
				cout << "=================================================" << endl;
				cout << "CHOOSE YOUR TARGET NUMBER SYSTEM:\n(10) DECIMAL" << endl;
				cout << "INPUT ANY OTHER VALUE TO QUIT THE PROGRAM." << endl;
				cout << "=================================================" << endl;
				cin >> target;

				switch(target) {
					case 10: {
						targetName = "Decimal: ";

						cout << "=================================================" << endl;
						cout << "Source Number System: " << source << endl;
						cout << "Target Number System: " << target << endl;
						cout << "=================================================" << endl;
						cout << "INPUT YOUR NUMBER IN SOURCE NUMBER SYSTEM:" << endl;
						cout << sourceName;
						cin >> sourceNum;

////////////////////////////////////////////////////////////////////////////////////////////////////
						//ANY NUMBER SYSTEM TO DECIMAL
						int digit;
						for(int i=0;i<sourceNum.size();i++) {
							digit = sourceNum.at(i)-'0';
							targetNum += digit*pow(source,sourceNum.size()-i-1);
						}
////////////////////////////////////////////////////////////////////////////////////////////////////

						cout << targetName << targetNum << endl;
						cout << "YOU WILL BE RETURNED TO THE MAIN MENU." << endl;
						continue;
					}
					default: {
						cout << "Confirm Close====================================" << endl;
						cout << "=================================================" << endl;
						cout << "ARE YOU SURE YOU WANT TO QUIT THE PROGRAM?(Y/N)" << endl;
						cout << "=================================================" << endl;
						cin >> confirm;

						if(confirm == 'Y') {
							cout << "BYE!" << endl;
							cout << "=================================================" << endl;
							return 0;
						} else {
							cout << "YOU WILL BE RETURNED TO THE MAIN MENU." << endl;
							continue;
						}
					}
				}
			}
			case 10: {
				cout << "=================================================" << endl;
				cout << "Source Number System: " << source << endl;
				cout << "=================================================" << endl;
				cout << "CHOOSE YOUR TARGET NUMBER SYSTEM:" << endl;
				cout << "(2) BINARY" << endl;
				cout << "(3) TERNARY" << endl;
				cout << "(4) QUATERNARY" << endl;
				cout << "(5) QUINARY" << endl;
				cout << "(6) SENARY" << endl;
				cout << "(7) SEPTENARY" << endl;
				cout << "(8) OCTAL" << endl;
				cout << "(9) NONARY" << endl;
				cout << "(16) HEXADECIMAL" << endl;
				cout << "INPUT ANY OTHER VALUE TO EXIT THE PROGRAM" << endl;
				cout << "=================================================" << endl;

				cin >> target;

				// NAME OF TARGET SYSTEM FOR FURTHER OUTPUTS
				switch(target) {
					case 2: targetName = "BINARY:"; break;
					case 3: targetName = "TERNARY: "; break;
					case 4: targetName = "QUATERNARY: "; break;
					case 5: targetName = "QUINARY: "; break;
					case 6: targetName = "SENARY: "; break;
					case 7: targetName = "SEPTENARY: "; break;
					case 8: targetName = "OCTAL: "; break;
					case 9: targetName = "NONARY: "; break;
					case 16: targetName = "HEXADECIMAL: ";
				}

				switch(target) {
					case 2:
					case 3:
					case 4:
					case 5:
					case 6:
					case 7:
					case 8:
					case 9:
					case 16: {
						cout << "=================================================" << endl;
						cout << "Source Number System: " << source
							 << ", Target Number System: " << target << endl;
						cout << "INPUT YOUR NUMBER IN SOURCE BASE:\nDECIMAL: ";
						cin >> sourceNum;

//////////////////////////////////////////////////////////////////////////////////////////////////
						//Decimal to any number system
						string tN;   // targetNum to string
					    long int sN = 0; //sourceNum to int
					    for(int i=0;i<sourceNum.length();i++)
					        sN += (sourceNum.at(i)-'0')*pow(10,sourceNum.length()-i-1);

					    while(sN>0) {
					        int mod = sN%target;
					        char m = '0' + mod;  // mod integer to char
					        switch(mod) {
					            case 10: tN.insert(0,1,'a'); break;
					            case 11: tN.insert(0,1,'b'); break;
					            case 12: tN.insert(0,1,'c'); break;
					            case 13: tN.insert(0,1,'d'); break;
					            case 14: tN.insert(0,1,'e'); break;
					            case 15: tN.insert(0,1,'f'); break;
					            default: tN.insert(0,1,m);
					        }
					        sN /= target;
					    }
/////////////////////////////////////////////////////////////////////////////////////////////////

						cout << targetName << tN << endl;
						cout << "=================================================" << endl;
						cout << "YOU WILL BE RETURNED TO THE MAIN MENU." << endl;
						continue;
					}
					default: {
					cout << "Confirm Close====================================" << endl;
					cout << "=================================================" << endl;
					cout << "ARE YOU SURE YOU WANT TO QUIT THE PROGRAM?(Y/N)" << endl;
					cout << "=================================================" << endl;
					cin >> confirm;

					if(confirm == 'Y') {
						cout << "BYE!" << endl;
						cout << "=================================================" << endl;
						return 0;
					} else {
						cout << "YOU WILL BE RETURNED TO THE MAIN MENU." << endl;
						continue;
					}
					}
				}
			}
			case 16:{
				cout << "Source Number System: " << source << endl;
				cout << "=================================================" << endl;
				cout << "CHOOSE YOUR TARGET NUMBER SYSTEM:" << endl;
				cout << "(8) OCTAL" << endl;
				cout << "(10) DECIMAL" <<  endl;
				cout << "INPUT ANY OTHER VALUE TO QUIT THE PROGRAM" << endl;

				cin >> target;

				switch(target) {
					case 8: targetName = "OCTAL: "; break;
					case 10: targetName = "DECIMAL: ";
				}

				switch(target) {
					case 8:
					case 10: {
					cout << "=================================================" << endl;
					cout << "Source Number System: " << source
						 << ", Target Number System: " << target << endl;
					cout << "=================================================" << endl;
					cout << "INPUT YOUR NUMBER IN SOURCE NUMBER SYSTEM:" << endl;

					// VALIDATION LOOP
					int tries = 0, i;
					while(tries<5) {
						cout << sourceName;
						cin >> sourceNum;
						int snLen = sourceNum.length();   // sourceNum length
						for(i=0;i<snLen;i++) {
							if(!(isxdigit(sourceNum[i]))) {
								cout << "NOT A VALID NUMBER! TRY AGAIN:" << endl;
								tries++;
								break;
							}
						}
						// this statement runs if the input is an hexadecimal
						if(i==snLen) {
							cout << targetName;
///////////////////////////////////////////////////////////////////////////////////////////////////////
							//Hexadecimal to Decimal
							if(target==10) {
								int digit;
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
							}
//////////////////////////////////////////////////////////////////////////////////////////////////////
							//Hexadecimal to Octal
							else {
								string tNbin, tN;   // target number in binary and target number

								// Hexadecimal to binary
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

								//	3-digit Binary to Octal
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
								cout << tN << endl;
							}
//////////////////////////////////////////////////////////////////////////////////////////////////////
							tries=5;  // to return to main menu
						}
					}
					if(tries == 5) {
						cout << "YOU WILL BE RETURNED TO THE MAIN MENU." << endl;
						continue;
					}
					// END OF VALIDATION


					}
					default: {
					cout << "Confirm Close====================================" << endl;
					cout << "=================================================" << endl;
					cout << "ARE YOU SURE YOU WANT TO QUIT THE PROGRAM?(Y/N)" << endl;
					cout << "=================================================" << endl;
					cin >> confirm;

					if(confirm == 'Y') {
						cout << "BYE!" << endl;
						cout << "=================================================" << endl;
						return 0;
					} else {
						cout << "YOU WILL BE RETURNED TO THE MAIN MENU." << endl;
						continue;
					}
					}
				}

				}
			default: {
				cout << "Confirm Close====================================" << endl;
				cout << "=================================================" << endl;
				cout << "ARE YOU SURE YOU WANT TO QUIT THE PROGRAM?(Y/N)" << endl;
				cout << "=================================================" << endl;
				cin >> confirm;

				if(confirm == 'Y') {
					cout << "BYE!" << endl;
					cout << "=================================================" << endl;
					return 0;
				} else {
					cout << "YOU WILL BE RETURNED TO THE MAIN MENU." << endl;
					continue;
				}
			}
		}
		}

	return 0;
}