#include<bits/stdc++.h>
using namespace std;

// here we have to check all the way considering the array is circular

// the most naive solution would be using a outer loop from 0 to n - 1 and then for each element, run loop from i + 1 to n - 1 and if not found then from 0 to i - 1

vector<int> nextGreater2Brute(const vector<int> &arr) {
    vector<int> ans;
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        // for each element, look for the whole array in circular fashion and if you still dont find it then -1
        int index;
        int j;
        for(j = i + 1; j < i + n; j++) {
            index = j % n; // index = j till j < n, then it will wrap to 0 
            if(arr[index] > arr[i]) break; // arr[i] is the element for which we have to find nge
        }
        if(j < i + n - 1) ans.push_back(arr[index]);
        else ans.push_back(-1);
    }
    return ans;
}

vector<int> nextGreater2Optimal(const vector<int> &arr) {
    // here again we assume the hypothetical array so now total array is from index 0 to 2*n - 1
    stack<int> st;
    vector<int> ans(arr.size());
    for(int i = 2*arr.size() - 1; i >= 0; i--) {
        while(!st.empty() && st.top() <= arr[i % arr.size()]) {
            st.pop(); // here we maintain the monotonic order of stack
        }
        if(i < arr.size()) {
            // this are the elements for which we have to find next greater element or our answer
            // not for elements for which i >= arr.size() (they are hypothetical, but we still have to maintain monotonic stack order for them)
            // same as in monotonic stack
            if(st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }
        } 
        st.push(arr[i % arr.size()]); // at we end up pushing 2N elements hence we also pop 2N elements
    } 
    return ans;
} // O(2N + 2N) = O(4N) time and O(2N) space 

int main() {
    
    return 0;
}