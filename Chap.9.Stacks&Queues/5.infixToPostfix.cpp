#include<bits/stdc++.h>
using namespace std;

bool isOperand(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') return false;
    return true;
}

int priority(char ch) {
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '^') return 3;
    return -1;
}

string infixToPostfix(string s) {
    int i = 0;
    string ans = "";
    stack<char> st;
    while(i < s.length()) {
        if(s[i] == '(') st.push(s[i]);   
        else if(s[i] == ')') {
            while(!st.empty() && st.top() != '(') {
                ans.push_back(st.top());
                st.pop();
            }
            if(!st.empty()) st.pop(); // discard opening parentheses from stack and dont do anything for closing one
        }
        else if(isOperand(s[i])) ans.push_back(s[i]);
        else { 
            // Handle operators
            while (!st.empty() && 
                ( (s[i] != '^' && priority(s[i]) <= priority(st.top())) ||
                (s[i] == '^' && priority(s[i]) < priority(st.top())) )) {
                ans.push_back(st.top());
                st.pop();
            }
            // in case of right associative operators like ^ use < , basically you can insert even if the stack priority is equal to operator priority 
            st.push(s[i]);
        }

        i++;
    }
    while(!st.empty()) { // at max O(N)
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
    // O(N) for outer loop + O(N) (at max) for inner loop and O(N) at max for outer => O(2N) time
    // O(N) space for stack and O(N) space for ans 
}

string infixToPrefix(string s) {
    // reverse the s, change ( to ) and ( to ), convert it to postfix, reverse the answer again
    reverse(s.begin(), s.end());
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') s[i] = ')';
        else if(s[i] == ')') s[i] = '(';
    }
    string ans = infixToPostfix(s);
    reverse(ans.begin(), ans.end());
    return ans;
}

string postfixToInfix(string s) {
    stack<string> st;
    int i = 0;
    while(i < s.length()) {
        if(isOperand(s[i])) st.push(string(1,s[i])); // convert character to string
        else {
            string s2 = st.top();
            st.pop();
            string  s1 = st.top();
            st.pop();
            st.push("(" + s1  + s[i] + s2 + ")"); // string concatenation
        } 
        i++;
    }
    return st.top();
} // O(N) time for outer loop and for string concatenation, some languages take time O(N) in worst case when all characters are combined to a string => O(2N)
// O(N) sapce in stack

string prefixToInfix(string s) {
    stack<string> st;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (isOperand(s[i])) {
            st.push(string(1, s[i]));
        } else {
            string s1 = st.top(); st.pop();
            string s2 = st.top(); st.pop();
            st.push("(" + s1 + s[i] + s2 + ")");
//             // works because
//             std::string + char is valid and returns a new string.
//             char + std::string is not valid (unless you explicitly convert the char to a std::string first).
        }
    }
    return st.top();
}

string postfixToPrefix(string s) {
    stack<string> st;
    for(char ch : s) {
        if(isOperand(ch)) st.push(string(1,ch));
        else {
            string s2 = st.top(); st.pop();
            string s1 = st.top(); st.pop();
            st.push(string(1,ch) + s1 + s2);
//             std::string + char is valid and returns a new string.
//             char + std::string is not valid (unless you explicitly convert the char to a std::string first).
        }
    }
    return st.top();
}

string prefixToPostfix(string s) {
    stack<string> st;
    int i = s.length() - 1;
    while(i >= 0) {
        if(isOperand(s[i])) st.push(string(1,s[i]));
        else {
            string s1 = st.top(); st.pop();
            string s2 = st.top(); st.pop();
            st.push(s1 + s2 + string(1,s[i]));
        }
        i--;
    }
    return st.top();
}

int main() {
    string infix = "a+b*(c^d-e)";
    string postfix = infixToPostfix(infix);
    string prefix = infixToPrefix(infix);
    cout << postfix << endl;
    cout << prefix << endl;
    cout << postfixToInfix(postfix) << endl;
    cout << prefixToInfix(prefix) << endl;
    cout << postfixToPrefix(postfix) << endl;
    cout << prefixToPostfix(prefix) << endl;
    return 0;
}