#include<bits/stdc++.h>
using namespace std;

int myAtoiIterative(string s) {
    if(s.length() == 0) return 0;
    // ignore all the leading white spaces
    int i = 0;
    while(i < s.length()) {
        if(s[i] == ' ') i++;
        else break;
    }
    // now i points to the sign index, either = '+', '-', or a digit or alphabet
    int sign = 1;
    if(s[i] == '-') {
        sign = -1;
        i++;
    } else if(s[i] == '+') {
        i++;
    }
    while(i < s.length()) {
        if(s[i] != '0') break;
        i++;
    }
    // either a alphabet or non zero digit
    long ans = 0; // so we can calculate the value of ans and check whether its < INT_MIN || > INT_MAX
    while(i < s.length()) {
        if(s[i] >= 48 && s[i] <= 57) {
            ans = ans*10 + (s[i] - '0');
            if(sign == -1 && -1*ans < INT_MIN) return INT_MIN;
            if(sign == 1 && ans > INT_MAX) return INT_MAX;
            i++;
        } else {
            break;
        }
    }
    return (int)(ans * sign);
} // O(N) time and O(1) space

int myAtoiRecursive(string s) {
    
}

int main() {
    int num = myAtoiIterative("1234");
    cout << "num : " << num << endl;
    return 0;
}