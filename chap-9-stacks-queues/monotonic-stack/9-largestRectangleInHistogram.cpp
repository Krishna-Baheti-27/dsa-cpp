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
        int bars = 1;
        for(int left = i - 1; left >= 0; left--) {
            if(heights[left] >= currHeight) bars++; // this are the number of contiguous bars on left
            else break;
        }
        for(int right = i + 1; right < heights.size(); right++) {
            if(heights[right] >= currHeight) bars++; // this are the number of contiguous bars on right
            else break;
        }
        maxArea = max(maxArea, bars * currHeight);
        // Now max area = bars * currHeight since width = 1 for each
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

// what if you are not allowed to precompute and you have to do it in a single pass, like find maxArea in while traversing
int largestRectangleAreaOptimal(vector<int> &heights) {
    // Most optimal is remaining
}

int main() {
    
    return 0;
}