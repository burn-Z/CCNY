// need decimal to hexadecimal
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string sourceNum, targetNum;
    cin >> sourceNum;

    int target = 16;

    long int sN = 0;
    //sourceNum to int
    for(int i=0;i<sourceNum.length();i++)
        sN += (sourceNum.at(i)-'0')*pow(10,sourceNum.length()-i-1);

    while(sN>0) {
        int mod = sN%target;
        char m = '0' + mod;  // mod integer to char
        switch(mod) {
            case 10: targetNum.insert(0,1,'a'); break;
            case 11: targetNum.insert(0,1,'b'); break;
            case 12: targetNum.insert(0,1,'c'); break;
            case 13: targetNum.insert(0,1,'d'); break;
            case 14: targetNum.insert(0,1,'e'); break;
            case 15: targetNum.insert(0,1,'f'); break;
            default: targetNum.insert(0,1,m);
        }
        sN /= target;
    }

    cout << "hexadecimal: " << targetNum << endl;
}

// int main()
// {
//     string sourceNum;
//     long targetNum = 0;

//     int target = 8; //added
//     cin >> sourceNum;

//     //sourceNum to int////////////////////////////
//     int sN=0;
//     for(int i=0;i<sourceNum.length();i++)
//         sN += (sourceNum.at(i)-'0')*pow(10,sourceNum.length()-i-1);
//     ////////////////////////////////////////////
//     int t=1;
//     while(sN>0) {
//         targetNum += (sN%target) * t;
//         t*=10;
//         sN /= target;
//     }


//     /*//////////////////////////////////////////////////////
//     for(int i=0;i<8;i++) {
//         targetNum+=(sN%target)*pow(10,i);
//         sN /= target;
//     }
//     *///////////////////////////////////////////////////////
//     cout << targetNum << endl;

//     return 0;
// }