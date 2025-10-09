#include<bits/stdc++.h>
using namespace std;

// Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

// The following rules define a valid string:

// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

// so we basically have to check for valid parenthesis for ( and ) but we also have * which can be replaced by ( or ) or "" string to make it a valid string

//// WITHOUT ASTERISK ///////
// using stack, checking for valid without parenthesis
bool checkValidStringBrute1(string s) {
    stack<char> st;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') { // if its a opening we push into the stack
            st.push(s[i]);
        } else if(s[i] == ')') {
            if(st.top() != '(') return false;
            st.pop();
        }
    }
    return st.empty(); // if stack is empty it is valid else not
} // we realised that we were using stack as a simple counter thats why we replaced it with count 

// without using stack
bool checkValidStringBrute2(string s) {
    int count = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') count++;
        else count--;
        if(count < 0) return false;
    }
    return count == 0;
}

////////    WITH ASTERISK     ///////////

// now for the string involving asterisks, what we can do is try all possible combinations and if any one of them returns a valid paren string then that string is valid, for that we would use recursion since we want to try out all combinations

bool checkValidStringBrute(string s, int index = 0, int count = 0) {
    if(count < 0) return false;
    if(index == s.length()) {
        return count == 0;
    }
    if(s[index] == '(') {
        return checkValidStringBrute(s, index + 1, count + 1);
    } else if(s[index] == ')') {
        return checkValidStringBrute(s, index + 1, count - 1);
    } else {
        // we have asterisk
        // assume it to be open
        if(checkValidStringBrute(s, index + 1, count + 1)) return true;
        // assume it to be closed
        else if(checkValidStringBrute(s, index + 1, count - 1)) return true;
        // assume it to be empty
        else return checkValidStringBrute(s, index + 1, count);
    }
} // O(3^N) time for checking 3 different cases,  and O(N) space

// more better way to write the same is here
bool checkValidStringBrute(string s, int index = 0, int count = 0) {
    if(count < 0) return false;
    else if(index == s.length()) {
        return count == 0;
    } else if(s[index] == '(') {
        return checkValidStringBrute(s, index + 1, count + 1);
    } else if(s[index] == ')') {
        return checkValidStringBrute(s, index + 1, count - 1);
    }
    return checkValidStringBrute(s, index + 1, count + 1) || checkValidStringBrute(s, index + 1, count - 1) || checkValidStringBrute(s, index + 1, count);
}

// if you do dynamic programming you can optimise this to O(N^2) time and O(N^2) space, which will be a better solution

// but here we are looking for a more optimal O(N) solution
// here we are still trying out all possible combinations, but here instead of actually generating all combinations and checking for them one by one, we instead maintain the range of count using min and max, for opening or closing we increment and decrement both min and max, but for asterisk we store in such a way that min value of range is in min (not less than -1, in that case 0) and max value in max, and in the end we check if there is 0 in our range from min to max

bool checkValidStringOptimal(string s) {
    int minCount = 0, maxCount = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') {
            minCount++;
            maxCount++;
        } else if(s[i] == ')') {
            minCount--;
            maxCount--;
        } else { // asterisk
            minCount--; // since we have to take minimum
            maxCount++; // since we have to take maximum
        }
        if(maxCount < 0) return false;
        if(minCount < 0) minCount = 0;
    } 
    return minCount == 0;
} // O(N) time


int main() {
    
    return 0;
}