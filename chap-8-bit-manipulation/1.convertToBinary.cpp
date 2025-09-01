#include<bits/stdc++.h>
using namespace std;

string convertToBinary(int n) {
    string res = "";
    while(n != 0) {
        if(n % 2 == 1) res += "1";
        else res += "0";
        n = n / 2;
    }
    reverse(res.begin(), res.end());
    return res;
    // O(logN) since we divide by two each time and space O(logN) since number of characters used by the string is same as how many times we divide 
}

int convertToDecimal(string s) {
    int ans = 0, powerOfTwo = 1;
    for(int i = s.size() - 1; i >= 0; i--) {
        if(s[i] == '1') {
            ans += powerOfTwo;
        }
        powerOfTwo *= 2;
    }
    return ans;
} // O(N) time and O(1) space

int main() {
    cout << convertToBinary(12) << endl;
    cout << convertToDecimal("100") << endl;
    return 0;
}