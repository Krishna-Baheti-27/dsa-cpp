#include<bits/stdc++.h>
using namespace std;

// You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

// Return the sum of all subarray ranges of nums.

// We already know how to find the subarray minimums, extending that we can also find subaray maximums for each subarray

// the summation of max - min for all subarrays is what we require
// that is same as sum of subarrays maximum - sum of subarrays minimum

long long sumSubarrayRangesBrute(vector<int> &arr) {
    // brute force is generate all subarrays and go from there
    long long sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        int minel = arr[i], maxel = arr[i];
        for(int j = i; j < arr.size(); j++) {
            minel = min(minel, arr[j]);
            maxel = max(maxel, arr[j]);
            sum += (maxel - minel);
        }
    }
    return sum;
} // O(N^2) time and O(1) space

/////////////////////////////////////////////////////////////////////

vector<int> nextSmallerIdx(vector<int> &arr) {
    vector<int> ans(arr.size());
    stack<int> st;
    for(int i = arr.size() - 1; i >= 0; i--) {
        while(!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop(); // we want a smaller index so remove it till we have bigger or equal 
        }
        if(st.empty()) {
            ans[i] = arr.size();
        } else {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

vector<int> prevSmallerOrEqualIdx(vector<int> &arr) {
    vector<int> ans(arr.size());
    stack<int> st;
    for(int i = 0; i < arr.size(); i++) {
        while(!st.empty() && arr[st.top()] > arr[i]) {
            st.pop(); // since we want smaller or equal pop only until we have greater
        }
        if(st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

vector<int> nextGreaterIdx(vector<int> &arr) {
    vector<int> ans(arr.size());
    stack<int> st;
    for(int i = arr.size() - 1; i >= 0; i--) {
        while(!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop(); // we want greater so lesser than or equal not allowed so pop
        }
        if(st.empty()) {
            ans[i] = arr.size();
        } else {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

vector<int> prevGreaterOrEqualIdx(vector<int> &arr) {
    vector<int> ans(arr.size());
    stack<int> st;
    for(int i = 0; i < arr.size(); i++) {
        while(!st.empty() && arr[st.top()] < arr[i]) {
            st.pop(); // we want greater or equal so pop all lesser ones
        }
        if(st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

long long sumSubarrayMax(vector<int> &arr) {
    vector<int> nextGreater = nextGreaterIdx(arr);
    vector<int> prevGreater = prevGreaterOrEqualIdx(arr);
    long long sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        int left = i - prevGreater[i];
        int right = nextGreater[i] - i;
        long long prod = right;
        prod *= left;
        prod *= arr[i];
        sum += prod;
    }
    return sum;
}

long long sumSubarrayMin(vector<int> &arr) {
    vector<int> nextSmaller = nextSmallerIdx(arr);
    vector<int> prevSmaller = prevSmallerOrEqualIdx(arr);
    long long sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        int left = i - prevSmaller[i];
        int right = nextSmaller[i] - i;
        long long prod = right;
        prod *= left;
        prod *= arr[i];
        sum += prod;
    }
    return sum;
}

long long sumSubarrayRangesOptimal(vector<int> &arr) {
    // right that will be the range of each subarray added together
    return sumSubarrayMax(arr) - sumSubarrayMin(arr);
} // O(10N) time and O(12N) space 

int main() {
    
    return 0;
}