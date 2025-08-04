#include<bits/stdc++.h>
using namespace std;

// bool isMatched(char ch1, char ch2) {
//     if(ch1 == '(' && ch2 == ')') return true;
//     if(ch1 == '{' && ch2 == '}') return true;
//     if(ch1 == '[' && ch2 == ']') return true;
//     return false;
// }

// bool isBalanced(string str) {
//     stack<char> st;
//     for(int i = 0; i < str.length(); i++) {
//         if(str[i] == '(' || str[i] == '[' || str[i] == '{') st.push(str[i]);
//         else if(str[i] == ')' || str[i] == ']' || str[i] == '}') {
//             if(st.empty()) return false;
//             char toMatch = st.top();
//             st.pop();
//             if(!isMatched(toMatch, str[i])) return false;
//         }
//     } 
//     if(st.empty()) return true;
//     return false;  
//     // O(N) time and space
// }

// More readable
bool isMatched(char ch1, char ch2) {
    return (ch1 == '(' && ch2 == ')') ||
           (ch1 == '{' && ch2 == '}') ||
           (ch1 == '[' && ch2 == ']');
}

bool isBalanced(const string& str) {
    stack<char> st;
    for(char ch : str) {
        if(ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        } else if(ch == ')' || ch == ']' || ch == '}') {
            if(st.empty() || !isMatched(st.top(), ch))
                return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string s = ")";
    cout << isBalanced(s) << endl;
    return 0;
}