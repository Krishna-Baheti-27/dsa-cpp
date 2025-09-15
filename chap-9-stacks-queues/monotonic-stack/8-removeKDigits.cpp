#include<bits/stdc++.h>
using namespace std;

// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

// the intuition is to keep the smaller digits at start and then remove bigger digits from end so that the string which we get is smallest numerically

string removeKDigitsUsingStack(string num, int k) {
    if(k == num.length()) return "0";
    stack<char> st;
    st.push(num[0]);
    for(int i = 1; i < num.length(); i++) {
        while(!st.empty() && num[i] < st.top() && k > 0) {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    while(k > 0) {
        st.pop();
        k--;
    }
    string result = "";
    // the string num is constant so we cant really modify it and thus we have to make a new string
    while(!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    reverse(result.begin(), result.end());
    int i = 0;
    while(result[i] == '0' && i < result.length()) {
        i++;   
    }
    result = result.substr(i); // it might happen that our answer was "0" but we trimmed that because of leading zeroes
    return result.length() == 0 ? "0" : result;
}

// thats why solving this using stack is lot more tougher and unecessary work and hence use a vector or string
string removeKDigitsOptimal(string num, int k) {
    if(k == num.length()) return "0";
    string result = "";
    for(int i = 0; i < num.length(); i++) {
        while(result.length() > 0 && result.back() > num[i] && k > 0) {
            result.pop_back();
            k--;
        }
        result.push_back(num[i]);
    }
    while(k > 0) {
        result.pop_back();
        k--;
    }
    // now just trim the leading zeroes
    int i = 0;
    while(result[i] == '0' && i < result.length()) {
        i++;   
    }
    result = result.substr(i); // it might happen that our answer was "0" but we trimmed that because of leading zeroes
    return result.length() == 0 ? "0" : result;
} 

// remove k digits smart 

string removeKDigitsOptimal(string num, int k) {
    if(k == num.length()) return "0";
    string result = "";
    for(int i = 0; i < num.length(); i++) {
        while(result.length() > 0 && result.back() > num[i] && k > 0) {
            result.pop_back();
            k--;
        }
        if(result.length() > 0 || num[i] != '0') result.push_back(num[i]);
        // to avoid insertion of leading zeroes
    }
    while(k > 0 && result.length() > 0) {
        result.pop_back();
        k--;
    }
    if(result == "") return "0"; // if result became empty then return "0"
    return result;
} // O(2N) time and O(N) space

int main() {
    
    return 0;
}