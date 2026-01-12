#include<bits/stdc++.h>
using namespace std;

// we have to convert a number to its binary string

/////////////////////////////////////////////////////////////////////////////////

string convertToBinary(int n) {

    string s = "";

    if(n == 0) return "0";

    while(n > 0) {

        if(n % 2 == 0) {
            s.append("0");
        } else {
            s.append("1");
        }

        n /= 2;
    }

    reverse(s.begin(), s.end());

    return s;

} // O(logn + logn / 2) time and O(logn) space

////////////////////////////////////////////////////////////////////////////////////

// assuming it is valid string, we start from right and move to left each time increasing the factor by 2 each time

int convertToDecimal(string s) {

    int n = 0, mul = 1; // here 1 means 2^0

    for(int i = s.length() - 1; i >= 0; i--) {
        n += mul * (s[i] - '0'); // to get the integer value out
        mul *= 2;
    }

    return n;

} // O(n) time and O(1) space

int main() {
    
    return 0;
}