#include<bits/stdc++.h>
using namespace std;

// single array
vector<int> nextGreaterElBrute(const vector<int> &arr) {
    vector<int> ans;
    for(int i = 0; i < arr.size(); i++) {
        int j;
        for(j = i + 1; j < arr.size(); j++) {
            if(arr[j] > arr[i]) {
                break;
            }
        }
        if(j < arr.size()) ans.push_back(arr[j]);
        else ans.push_back(-1);
    }
    return ans;
} // O(N^N) time and O(N) space

vector<int> nextGreaterElOptimal(const vector<int> &arr) {
    // using a monotonic stack
    // a monotonic stack is something which stores the elements in a specific order according to the question and also obeys our LIFO Principle
    vector<int> ans(arr.size(), 0);
    stack<int> st;
    for(int i = arr.size() - 1; i >= 0; i--) {
        while(!st.empty() && st.top() <= arr[i]) {
            st.pop(); // pop while stack is not empty or the top of stack is greater
        } 
        if(st.empty()) {
            ans[i] = -1; // entire stack became empty but we didnt find anything greater
            // no next greater element and hence -1
        } else {
            ans[i] = st.top(); // always handle the answer case at last
        }
        st.push(arr[i]); // always push into the stack regardless since  we have to keep track of next element
    }
    return ans;
    // O(2N) time is worst case since the outer loop runs for N times and the inner loop can run atmax total of N times in the whole iteration of outer loop, because from stack we are removing elements of array which cannot exceed N

    // here we are using a monotonic stack because the elements are always stored in decreasing order and if the order is distorted we pop from stack
}

/////////////////////   NOW NEXT GREATER LEETCODE STYLE FOR TWO ARRAYS

vector<int> nextGreaterEl2Brute(const vector<int> &arr1, const vector<int> &arr2) {
    // for each query in arr1, you have to find the nextgreater element of that query from arr2
    vector<int> ans;
    for(int i = 0; i < arr1.size(); i++) {
        int j;
        for(j = 0; j < arr2.size(); j++) {
            if(arr2[j] == arr1[i]) break;
        } // because it is guaranteed that each query in arr1 will be present in arr2
        // now we start looking from j + 1 th index for nextGreaterElement, and if not then -1
        while(j < arr2.size() - 1) {
            if(arr2[j + 1] > arr1[i]) {
                break;
            }
            j++;
        }
        if(j < arr2.size() - 1) ans.push_back(arr2[j + 1]);
        else ans.push_back(-1);
    }
    return ans;
}

vector<int> nextGreaterEl2Optimal(const vector<int> &arr1, const vector<int> &arr2) {
    stack<int> st;
    unordered_map<int,int> mpp;
    for(int i = arr2.size() - 1; i >= 0; i--) {
        while(!st.empty() && st.top() <= arr2[i]) {
            st.pop();
        }
        if(st.empty()) mpp[arr2[i]] = -1; // instead of storing in ans array we store it in map and later only those keys of map which are present in arr1, for them we return the answer array
        else mpp[arr2[i]] = st.top();
        st.push(arr2[i]);
    }
    // now build ans array for only elements in arr1
    vector<int> ans;
    for(int i = 0; i < arr1.size(); i++) {
        ans.push_back(mpp[arr1[i]]);
    }
    return ans;
}

int main() {
    
    return 0;
}