#include<bits/stdc++.h>
using namespace std;

// The Next Smaller Element for an element x is defined as the first element to the right of x that is smaller than x.

vector<int> nextSmallerBrute(vector<int> &arr) {
    vector<int> ans;
    for(int i = 0; i < arr.size(); i++) {
        int j;
        for(j = i + 1; j < arr.size(); j++) {
            if(arr[j] < arr[i]) break;
        }
        if(j < arr.size()) ans.push_back(arr[j]);
        else ans.push_back(-1);
    }
    return ans;
} // O(N^2) time and O(1) space

vector<int> nextSmallerOptimal(vector<int> &arr) {
    stack<int> st;
    vector<int> ans(arr.size());
    for(int i = arr.size() - 1; i >= 0; i--) {
        while(!st.empty() && st.top() >= arr[i]) { // only this condition changes 
            st.pop();
        }
        if(st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }
        st.push(arr[i]); // push the element regardless
    }
    return ans;
} // O(2N) time and O(N) space

int main() {
    
    return 0;
}