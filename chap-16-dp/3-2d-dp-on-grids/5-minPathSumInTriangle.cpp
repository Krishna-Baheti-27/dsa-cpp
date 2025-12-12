#include<bits/stdc++.h>
using namespace std;

// here we are given a triangle array which means its size increase by one in each row, and we have to find the min path sum from top to bottom if we are only allowed to move down the row at i or i + 1 where i is the current index we are at in the current row

///////////////////////////////////////////////////////////////////////////////////////

// again we have to find min possible sum so we have to try all possible ways and return the min sum amongst them

// so our recurrence would be

// f(i,j) = min(f(i + 1, j), f(i + 1, j + 1)) where i and j are valid indices
// f(i ,j) represents the min path sum if we were to start from (0,0) and reach to (i,j) obeying the above constraints of traversal

// in the triangle for the ith row we have i + 1 columns

int minPathSumBruteHelper(int i, int j, int n, vector<vector<int>> &triangle) {

    if(i == n - 1) {
        return triangle[i][j];
    }

    int downSum = triangle[i][j] + minPathSumBruteHelper(i + 1, j, n, triangle);
    int downRightSum = triangle[i][j] + minPathSumBruteHelper(i + 1, j + 1, n, triangle);

    return min(downSum, downRightSum);

} // O(2^n) time and O(n) recursion stack space

int minPathSumBrute(vector<vector<int>> &triangle) {
    return minPathSumBruteHelper(0, 0, triangle.size(), triangle);
}

/////////////////////////////////////////////////////////////////////////////////////////

int memoHelper(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp) {
    if(i == n - 1) {
        return triangle[i][j];
    }

    if(dp[i][j] != INT_MIN) {
        return dp[i][j];
    }

    int downSum = triangle[i][j] + memoHelper(i + 1, j, n, triangle, dp);
    int downRightSum = triangle[i][j] + memoHelper(i + 1, j + 1, n, triangle, dp);

    return dp[i][j] = min(downSum, downRightSum);

} // O(n^2) time and O(n^2) space + O(n) recursion stack space 

int minPathSumMemo(vector<vector<int>> &triangle) {
    int n = triangle.size();
    vector<vector<int>> dp;
    for(int i = 0; i < n; i++) {
        vector<int> temp(triangle[i].size(), INT_MIN); // use INT_MIN since triangle[i][j] can be -ve
        dp.push_back(temp);
    }
    return memoHelper(0, 0, n, triangle, dp);
}

////////////////////////////////////////////////////////////////////////////////////////////

int minPathSumTab(vector<vector<int>> &triangle) {

    int n = triangle.size();
    vector<vector<int>> dp;
    for(int i = 0; i < n; i++) {
        vector<int> temp(triangle[i].size());
        dp.push_back(temp);
    }

    // now handle the base cases

    dp[0][0] = triangle[0][0];

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i + 1; j++) {
            
        }
    }
}

int main() {
    
    return 0;
}