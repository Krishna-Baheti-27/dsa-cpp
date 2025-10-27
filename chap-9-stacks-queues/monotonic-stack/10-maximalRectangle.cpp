#include<bits/stdc++.h>
using namespace std;

// we are given matrix and we have to find the max possible area of rectangle of all 1's

// this is simple extension the largest reactangle area in hisogram problem, but we only have to make sure that we are considering 1's only and hence use prefixSum for that

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

int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> prefixMat(n ,vector<int>(m));
    for(int j = 0; j < m; j++) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            if(matrix[i][j] == '0') {
                sum = 0;
            } else {
                sum += matrix[i][j] - '0';
            }
            prefixMat[i][j] = sum;
        }
    }
    // now we can send each row of prefixMat to get our max area
    int maxArea = 0;
    for(int i = 0; i < n; i++) {
        maxArea = max(maxArea, largestRectangleAreaOptimal(prefixMat[i]));
    }
    return maxArea;
}

int main() {
    
    return 0;
}