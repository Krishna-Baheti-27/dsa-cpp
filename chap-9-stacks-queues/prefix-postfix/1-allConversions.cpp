#include<bits/stdc++.h>
using namespace std;

// HELPER FUNCTIONS FOR ALL 

bool isOperand(char ch) {
    if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
        return true;
    }
    return false;
}

int priority(char ch) {
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    return -1; // '(' || ')' has priority of -1
}

///////////////////////////////////////////////////////////////////////////////////

// code is self explanatory of what we are doing

string infixToPostfix(string infix) {
    string ans = "";
    stack<char> st;
    int i = 0;
    while(i < infix.length()) {
        if(isOperand(infix[i])) ans += infix[i];
        else if(infix[i] == '(') st.push(infix[i]);
        else if(infix[i] == ')') {
            while(!st.empty() && st.top() != '(') { // cannot pop more than N elements in total
                ans += st.top();
                st.pop();
            }
            st.pop(); // discard opening parenthesis
        } else {
            if(infix[i] == '^') { // special handling for right associative operators
                while(!st.empty() && priority(st.top()) > priority(infix[i])) { // same as above
                    ans += st.top();
                    st.pop();
                }
            } else { // for left associative
                while(!st.empty() && priority(st.top()) >= priority(infix[i])) { // same as above
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(infix[i]); // now push the operator
        }
        i++;
    }
    while(!st.empty()) { // if traversed the entire string and still there are elements in stack
        ans += st.top();
        st.pop();
    }
    return ans;
} // O(N + N) time and O(N) space, not considering space to return the answer

/////////////////////////////////////////////////////////////////////////

// follow simple steps, first reverse the infix string, then convert the reversed infix to postfix and then again reverse to get infix to prefix

string infixToPrefix(string infix) {

    reverse(infix.begin(), infix.end()); // O(N / 2)
    // once we reverse we scan through it to make a opening bracket to closing and closing to opening bracket
    for(int i = 0; i < infix.length(); i++) { // O(N)
        if(infix[i] == '(') infix[i] = ')';
        else if(infix[i] == ')') infix[i] = '(';
    }

    int i = 0;
    string ans = "";
    stack<char> st;
    while(i < infix.length()) {
        if(isOperand(infix[i])) ans += infix[i];
        else if(infix[i] == '(') st.push(infix[i]);
        else if(infix[i] == ')') {
            while(!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        } else {
            if(infix[i] == '^') { // special handling for right associative
                while(!st.empty() && priority(infix[i]) <= priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
            } else { // for other operators we have < and not <=, which we means we dont pop for equal precendence and simply push into the stack
                while(!st.empty() && priority(infix[i]) < priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(infix[i]);
        }
        i++;
    }
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    } 
    // O(2N) in total
 
    reverse(ans.begin(), ans.end()); // O(N / 2), reverse the obtained ans not original infix
    return ans;  
} // O(4N) time and O(N) space

////////////////////////////////////////////////////////////////////////////////////////

// whenever we have an operand we push into the stack, whenever we have an operator we pop last two values from stack and do (poppedSecond operator poppedFirst) wrapped in parentheses and push back into the stack

string postfixToInfix(string postfix) {
    stack<string> st;
    int i = 0;
    while(i < postfix.length()) {
        if(isOperand(postfix[i])) st.push(postfix[i] + "");
        else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            st.push('(' + op2 + postfix[i] + op1 + ')');
        }
        i++;
    }
    return st.top(); // this would be wrong only if the given postfix expression is wrong
} // O(N + N) time, because we are doing string concatenation and in worst case we will add to strings to length of N so O(2N) time and O(N) space

////////////////////////////////////////////////////////////////////////

// same as above but here iterate from the back and instead of op2 operator op1 we do op1 operator op2

string prefixToInfix(string prefix) {
    stack<string> st;
    int i = prefix.length() - 1;
    while(i >= 0) {
        if(isOperand(prefix[i])) st.push(prefix[i] + "");
        else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            st.push('(' + op1 + prefix[i] + op2 + ')');
        }
        i--;
    }
    return st.top(); // single element remaining for valid prefix
} // O(2N) time and O(N) space

///////////////////////////////////////////////////////////////////////

// same as above, whenver we see a operand put it into the stack, whenever we see a operator we pop two operands from stack and push operator op2 op1 in stack without parentheses

string postfixToPrefix(string postfix) {
    stack<string> st;
    int i = 0;
    while(i < postfix.length()) {
        if(isOperand(postfix[i])) st.push(postfix[i] + "");
        else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            st.push(postfix[i] + op2 + op1);
        }
        i++;
    }
    return st.top();
} // O(2N) time and O(N) space

/////////////////////////////////////////////////////////////////////////

// same as above, whenver we see a operand we put it into the stack, whenever we see an operator we pop last 2 and push op1 op2 operator into the stack without parentheses, we start from back

string prefixToPostfix(string prefix) {
    stack<string> st;
    int i = prefix.length() - 1;
    while(i >= 0) {
        if(isOperand(prefix[i])) st.push(prefix[i] + "");
        else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            st.push(op1 + op2 + prefix[i]);
        }
        i--;
    }
    return st.top();
} // O(2N) time and O(N) space

// some compilers take up to O(N) for concatenating new strings and thus for total of N each tierations first it would be concatenaing 1 length string then 2 then 3 then so on N
// so 1 + 2 + 3 + 4 + 5 ... N = O(N^2) time

int main() {
    
    return 0;
}