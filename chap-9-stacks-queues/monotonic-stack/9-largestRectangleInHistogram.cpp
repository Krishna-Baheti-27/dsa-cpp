#include<bits/stdc++.h>
using namespace std;

// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

// the brute force involves goinf through each bar and finding the max area rectangle it can form and thus do it for all to get the largest rectangle
// but how to find the max area rectangle that a bar can form ?
// we want the negihbouring bars to have a height >= current bar height, so the (number of contiguous bars + 1) * hegiht of current bar gives the max area for that rectangle, and even if one bar in between fails this condition we stop then and there

int largestRectangleAreaBrute(vector<int> &heights) {
    int maxArea = INT_MIN;
    for(int i = 0; i < heights.size(); i++) {
        int currHeight = heights[i];
        int bars = 1; // counting the current bar
        for(int left = i - 1; left >= 0; left--) {
            if(heights[left] >= currHeight) bars++; 
            else break;
            // this are the number of contiguous bars on left
        } 
        for(int right = i + 1; right < heights.size(); right++) {
            if(heights[right] >= currHeight) bars++; 
            else break;
            // this are the number of contiguous bars on right
        }
        maxArea = max(maxArea, bars * currHeight);
        // Now max area = bars * currHeight since width = 1 for each rectangle
    }
    return maxArea;
} // O(n^2) time and O(1) space

vector<int> nextSmallerIdx(vector<int> &arr) {
    vector<int> ans(arr.size());
    stack<int> st;
    for(int i = arr.size() - 1; i >= 0; i--) {
        while(!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop(); // since we want next smaller index we would pop for greater or equal
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

vector<int> prevSmallerIdx(vector<int> &arr) {
    vector<int> ans(arr.size());
    stack<int> st;
    for(int i = 0; i < arr.size(); i++) {
        while(!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop(); // since we want prev smaller index we would pop for greater or equal
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

int largestRectangleAreaBetter(vector<int> &heights) {
    vector<int> nextSmaller = nextSmallerIdx(heights);
    vector<int> prevSmaller = prevSmallerIdx(heights);
    int maxArea = INT_MIN;
    for(int i = 0; i < heights.size(); i++) {
        maxArea = max(maxArea, heights[i] * (nextSmaller[i] - prevSmaller[i] - 1)); // since width = 1
    }
    return maxArea;
} // O(2N + 2N + N) time O(2N + 2N) space

// what if you are not allowed to precompute and you have to do it in a single pass, like find maxArea in while traversing, when we are traversing from left to right we have the context of prevSmaller but how to know about nextSmaller, we do that in future when we are popping

int largestRectangleAreaOptimal(vector<int> &heights) {
    stack<int> st;
    int maxArea = 0;
    for(int i = 0; i < heights.size(); i++) {
        while(!st.empty() && heights[st.top()] > heights[i]) {
            // here the order is breaking and hence we pop and compute maxArea for that element
            int element = st.top(); st.pop();
            int nextSmaller = i; // the current element is nse
            int prevSmaller = st.empty() ? -1 : st.top(); // st.top() is pse
            maxArea = max(maxArea, heights[element] * (nextSmaller - prevSmaller - 1));
        }
        st.push(i);
    }
    while(!st.empty()) {
        int element = st.top(); st.pop();
        int nextSmaller = heights.size();
        int prevSmaller = st.empty() ? -1 : st.top();
        maxArea = max(maxArea, heights[element] * (nextSmaller - prevSmaller - 1));
    }
    return maxArea;
} // O(2N) time and O(N) space

int main() {
    
    return 0;
}