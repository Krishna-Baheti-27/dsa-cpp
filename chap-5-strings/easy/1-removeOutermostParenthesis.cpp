#include<bits/stdc++.h>
using namespace std;

// of so waht do we want exactly, if the stack is empty we dont push or pop from stack, because for valid paren each opening must have a closing and when the stack is empty we discard the opening and closing means we are indeed taking elementary decomposition of valid paren string which cant be broken again, when stack is not empty we push into the stack every opening bracket and add it to the answer and when the stack is not empty and its a closing bracket then we pop from the stack and verify if opening is available (which will always be since every string is valid paren here), we pop and add the closing bracket to answer

string removeParenBrute(const string &s) {
    stack<char> st;
    string ans = ""; 
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            if(!st.empty()) ans += s[i];
            st.push(s[i]); // do always for opening brack
        } else {
            // if s[i] == ')'
            st.pop(); // do always for closing brack
            if(!st.empty()) ans += s[i];
        }
    }
    return ans;
} // O(N) time and O(N) space

string removeParenBetter(const string &s) {
    int counter = 0; // to determine whether stack is empty or not, counter = 0 means stack is empty
    string ans = "";
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            if(counter != 0) ans += s[i];
            // if counter == 0 then stack is empty and since we want to remove outer parenthesis from primitive decomposition hence we dont add it to answer
            counter++;
        } else {
            counter--;
            if(counter != 0) ans += s[i]; // same logic here we dont add to answer if that is the last outer paren since we want to discard it
        }
    }
    return ans;
} // O(N) time and O(1) space (bot considering space to return the answer)

void removeParenOptimal(string &s) {
    // using two pointers technique
    // whenever stack is non empty or counter is non zero then only we write in the string using write_ptr counter which points to the next location on which we want to write
    int write_ptr = 0, counter = 0; // still use a counter to act like a stack
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            if(counter != 0) s[write_ptr++] = s[i];
            counter++;
        } else {
            counter--;
            if(counter != 0) s[write_ptr++] = s[i];
        }
    }
    s.resize(write_ptr); // only take the string from 0 to writer_ptr - 1 index hence we truncate it
} // here we taking O(N) time and no extra space to return the answer
// but here we are actually modifying the actual data so maybe that is not encouraged

int main() {
    
    return 0;
}