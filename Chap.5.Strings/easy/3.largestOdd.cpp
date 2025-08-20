#include<bits/stdc++.h>
using namespace std;

string largestOddBrute(const string &s) {
    string ans = "";
    for(int i = 0; i < s.length(); i++) {
        for(int j = i; j < s.length(); j++) {
            // for each substring from j to i we compute its value if its odd and store in max

        }
    }
}

string largestOddOptimal(const string &s) {
    for(int i = s.length() - 1; i >= 0; i--) {
        if((s[i] - '0') % 2 != 0) return s.substr(0, i + 1);
    }
    return "";
}

int main() {
    
    return 0;
}