#include<bits/stdc++.h>
using namespace std;

// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

// we get this intuition from how we would create a min number if asked from a give set of numbers say 4 3 1 2, we would simply arrange them in sorted order 1 2 3 4, thus maintaining greater or equal tendency (which is what we will use through monotonic stack)

// the intuition is to keep the smaller digits at start and then remove bigger digits from end so that the string which we get is smallest numerically

string removeKDigitsUsingStack(string num, int k) {
    if(k == num.length()) return "0"; // we would pop all and return "0"
    stack<char> st;
    st.push(num[0]); 
    // we inserted the first element, now we have to maintain the increasing or equal order in monotonic stack, which will help us place smaller elements on left and bigger on right
    for(int i = 1; i < num.length(); i++) {
        while(!st.empty() && num[i] < st.top() && k > 0) { 
            // if num[i] < st.top() we would break increasing or equal order and hence we pop from stack till we have that order but remember we can only pop k times
            st.pop();
            k--;
        }
        st.push(num[i]); // now push since the order is maintained
    }
    // if we are exhausted with the string but still elements left which we can pop then pop them, since k can have value up to n 
    while(k > 0) {
        st.pop();
        k--;
    }
    // now whatever is in the stack is ready to be put in our result string, but not in LIFO order
    string result = "";
    // the string num is constant so we cant really modify it and thus we have to make a new string
    while(!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    reverse(result.begin(), result.end()); // reverse to get the true order
    int i = 0;
    while(result[i] == '0' && i < result.length()) {
        i++;  // to trim leading zeroes
    }
    result = result.substr(i); 
    
    // it might happen that our answer was "0" but we trimmed that because of leading zeroes, so in that case we would return empty string which is wrong, hence this check before returning
    return result.length() == 0 ? "0" : result;
}

// thats why solving this using stack is lot more tougher and unecessary work and hence use a vector or string which can be used as a stack

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
    // we dont even have to reverse as elements are already in proper order
    // now just trim the leading zeroes
    int i = 0;
    while(result[i] == '0' && i < result.length()) {
        i++;   
    }
    result = result.substr(i); 
    return result.length() == 0 ? "0" : result;
} // O(2N + x) x is number of leading zeroes time and O(N) space

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
        // to avoid insertion of leading zeroes (we do that by checking if string is empty or not, if it is then inserting a 0 doesnt make sense)
    }
    while(k > 0 && result.length() > 0) {
        result.pop_back();
        k--;
    }
    // no need to trim leading zeroes since we didnt insert them in the first place
    return result.length() == 0 ? "0" : result; 

} // O(2N) time and O(N) space

// if you think about it this way we are not using any space since the space required is to return the answer

int main() {
    
    return 0;
}