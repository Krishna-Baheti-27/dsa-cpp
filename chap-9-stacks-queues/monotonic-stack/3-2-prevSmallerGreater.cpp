#include<bits/stdc++.h>
using namespace std;

// for the given array find the previous smaller element and previous greater element

// writing optimal solutions directly

// for previous we have to iterate from the front only and maintain the monotonic stack order

vector<int> prevSmaller(vector<int> &arr) {
    stack<int> st;
    vector<int> ans;
    for(int i = 0; i < arr.size(); i++) {
        while(!st.empty() && arr[i] <= st.top()) {
            st.pop();
        }
        if(st.empty()) {
            ans.push_back(-1);
        } else {
            ans.push_back(st.top());
        }
        st.push(arr[i]);
    }
    return ans;
} // O(2N) time and O(N) space

// prevGreater just opp of prevSmaller

vector<int> prevGreater(vector<int> &arr) {
    stack<int> st;
    vector<int> ans;
    for(int i = 0; i < arr.size(); i++) {
        while(!st.empty() && arr[i] >= st.top()) {
            st.pop();
        }
        if(st.empty()) {
            ans.push_back(-1);
        } else {
            ans.push_back(st.top());
        }
        st.push(arr[i]);
    }
    return ans;
} // O(2N) time and O(N) space

int main() {
    
    return 0;
}