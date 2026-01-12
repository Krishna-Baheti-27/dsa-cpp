#include<bits/stdc++.h>
using namespace std;

// Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

// The following rules define a valid string:

// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

////////////////////////////////////////////////////////////////////////////////////

// so we basically have to check for valid parenthesis for ( and ) but we also have * which can be replaced by ( or ) or "" string to make it a valid string

//////////////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////////////////////////

// without using stack

bool checkValidStringBrute2(string s) {

    int count = 0;

    for(int i = 0; i < s.length(); i++) {

        if(s[i] == '(') {
            count++;
        } else {
            count--;
        } 

        if(count < 0) return false;

    }

    return count == 0;
}

////////    WITH ASTERISK     ///////////

// now for the string involving asterisks, what we can do is try all possible combinations and if any one of them returns a valid paren string then that string is valid, for that we would use recursion since we want to try out all combinations

bool checkValidStringBrute(string s, int index = 0, int count = 0) {

    if(count < 0) return false; // if at any point count < 0, return false as invalid

    if(index == s.length()) {
        return count == 0; // reached the end, check if its valid or not if it is then return true
    }

    if(s[index] == '(') {
        return checkValidStringBrute(s, index + 1, count + 1); // do count + 1 for opening
    } else if(s[index] == ')') {
        return checkValidStringBrute(s, index + 1, count - 1); // do count - 1 for closing
    } else {

        // we have asterisk

        if(checkValidStringBrute(s, index + 1, count + 1)) {
            return true; // assume it to be open and return true if possible
        } else if(checkValidStringBrute(s, index + 1, count - 1)) {
            return true; // assume it to be closed and return true if possible
        } else {
            return checkValidStringBrute(s, index + 1, count); // assume it to be empty
            // return whatever the answer is whether true or false
        }
    }

} // O(3^N) time for checking 3 different cases in worst case if every element is a asterisk,
// and O(N) recursion stack space

///////////////////////////////////////////////////////////////////////////////////////////

// more better way to write the same is here

bool checkValidStringBrute(string s, int index = 0, int count = 0) {

    if(count < 0) {
        return false;
    } else if(index == s.length()) {
        return count == 0;
    } else if(s[index] == '(') {
        return checkValidStringBrute(s, index + 1, count + 1);
    } else if(s[index] == ')') {
        return checkValidStringBrute(s, index + 1, count - 1);
    } else {
        return checkValidStringBrute(s, index + 1, count + 1) || checkValidStringBrute(s, index + 1, count - 1) || checkValidStringBrute(s, index + 1, count);
    }
}

////////////////////////////////////////////////////////////////////////////////////////

// if you apply dynamic programming you can optimise this to O(N^2) time and O(N^2) space, which will be a better solution

// so lets apply memoization

int memoHelper(int index, int count, int n, string &s, vector<vector<int>> &dp) {

    if(count < 0) {
        return 0;
    }

    if(index == n) {
        if(count == 0) {
            return 1;
        }
        return 0;
    }

    if(dp[index][count] != -1) {
        return dp[index][count];
    }

    if(s[index] == '(') {
        return dp[index][count] = memoHelper(index + 1, count + 1, n, s, dp);
    } else if(s[index] == ')') {
        return dp[index][count] = memoHelper(index + 1, count - 1, n, s, dp);
    } 

    return dp[index][count] = memoHelper(index + 1, count + 1, n, s, dp) || memoHelper(index+ 1, count, n, s, dp) || memoHelper(index + 1, count - 1, n, s, dp);
}

bool checkValidMemo(string s) {

    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return memoHelper(0, 0, n, s, dp);

} // O(n^2) time and space + O(n) recursion stack space

////////////////////////////////////////////////////////////////////////////////////

// now lets write the tabulation



////////////////////////////////////////////////////////////////////////////////////////

// but here we are looking for a more optimal O(N) solution

// here we are still trying out all possible combinations, but here instead of actually generating all combinations and checking for them one by one, we instead maintain the range of count using min and max variables and if at the end of iteration we have min == 0 then it is possible

// if any time min becomes -1 then we discard it and restore to 0

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
        
        // even after taking or considering only maximum cases still we are having max < 0 then this is identical to count < 0 and hence we immediately return false

        if(maxCount < 0) {
            return false; // which means we had an edge case like this ()) or ) which means false
        }

        if(minCount < 0) {
            minCount = 0; // if min becomes lesser than 1 then restore it
        }
    } 

    return minCount == 0; // if 0 is possible in the range then valid

} // O(N) time

int main() {
    
    return 0;
}