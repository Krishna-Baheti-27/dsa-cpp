#include<bits/stdc++.h>
using namespace std;

string largestOddBrute(const string &num) {
    int maxVal = INT_MIN;
    for(int i = 0; i < num.length(); i++) {
        for(int j = i; j < num.length(); j++) {
            // for each substring from j to i we compute its value if its odd and store in max
            int val = stoi(num.substr(i , j - i + 1));
            // the problem is integer overflow and even long long is not enough
            if(val % 2 != 0) maxVal = max(val, maxVal);
        }
    }
    return maxVal != INT_MIN ? to_string(maxVal) : "";
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