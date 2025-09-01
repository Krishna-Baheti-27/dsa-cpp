#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string s) {
    // for every opening there should be a closing parenthesis of the same type and vice versa, so on each iteration if it is a opening we push to the stack and if its a closing then we pop and check if its of the same type
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        } 
        else if (s[i] == ')') {
            if (st.empty() || st.top() != '(') return false;
            st.pop();
        } 
        else if (s[i] == '}') {
            if (st.empty() || st.top() != '{') return false;
            st.pop();
        } 
        else if (s[i] == ']') {
            if (st.empty() || st.top() != '[') return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    
    return 0;
}