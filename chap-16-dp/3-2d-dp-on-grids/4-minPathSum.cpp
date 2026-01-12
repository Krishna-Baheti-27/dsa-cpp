#include<bits/stdc++.h>
using namespace std;

// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

///////////////////////////////////////////////////////////////////////////////////////////////

// same as our previous problem to move from top left to bottom right but we have to maintain min path sum so again try all possible ways and select the min amongst them

// so our recurrence would be

// f(i,j) = min (f(i + 1, j), f(i, j + 1)) where i and j are valid indices

// so f(i,j) represents the min cost to reach from (0,0) to (i,j) if obey the given constraints

int minPathSumBruteHelper(int i, int j, int m, int n, vector<vector<int>> &grid) {

    // if no path then no cost so we should return a large number so that it has no effect in min(rightCost, bottomCost), but it also shouldnt overflow since grid[i][j] + INT_NAX is overflow hence we choose i billion as we know grid[i][j] <= 200 so no problem

    if(i >= m || j >= n) {
        return 1e9; 
    }

    if(i == m - 1 && j == n - 1) {
        return grid[i][j];
    }

    int rightCost = grid[i][j] + minPathSumBruteHelper(i, j + 1, m, n, grid);
    int bottomCost = grid[i][j] + minPathSumBruteHelper(i + 1, j, m, n, grid);

    return min(rightCost, bottomCost);

} // O(2^(m + n)) time and O(m + n) recursion stack space

int minPathSumBrute(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    return minPathSumBruteHelper(0, 0, m, n, grid);
}

///////////////////////////////////////////////////////////////////////////////////////////

// lets apply memoization to this problem as we have a lot of overlapping subproblems

int memoHelper(int i, int j, int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp) {

    if(i >= m || j >= n) {
        return 1e9; 
    }

    if(i == m - 1 && j == n - 1) {
        return grid[i][j];
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int rightCost = grid[i][j] + memoHelper(i, j + 1, m, n, grid, dp);
    int bottomCost = grid[i][j] + memoHelper(i + 1, j, m, n, grid, dp);

    return dp[i][j] = min(rightCost, bottomCost);

} // O(mn) time and O(mn + m + n) space

int minPathSumMemo(vector<vector<int>> &grid) {

    int m = grid.size(), n = grid[0].size();

    // here we can safely use -1 since array elements are positive and any path sum would not give -1, but if it does it can mess up our code so make sure to check constraints before directly pasting this

    vector<vector<int>> dp(m, vector<int>(n, -1));
    return memoHelper(0, 0, m, n, grid, dp);
}

///////////////////////////////////////////////////////////////////////////////////////////

// in the tabulation we identify the base case and then try to build our solution from there row by row or according to given problem

// so lets find the value of first row and first col of dp array since that would simply be sum of elements of grid's first row and column (since that is the straight line and only possible path so it ought to sorted) and using which we can solve further rows

int minPathSumTab(vector<vector<int>> &grid) {

    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));

    int sum = 0;

    for(int i = 0; i < m; i++) {
        sum += grid[i][0];
        dp[i][0] = sum;
    }

    sum = 0;

    for(int j = 0; j < n; j++) {
        sum += grid[0][j];
        dp[0][j] = sum;
    }

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            dp[i][j] = grid[i][j] + min(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    return dp[m - 1][n - 1];

} // O(mn) time and O(mn) space

////////////////////////////////////////////////////////////////////////////////////////

// now again to space optimise this all we have to do is maintain the previous row

int minPathOptimal(vector<vector<int>> &grid) {

    int m = grid.size(), n = grid[0].size();
    vector<int> dp(n);

    int sum = 0;
    
    for(int j = 0; j < n; j++) {
        sum += grid[0][j];
        dp[j] = sum;
    }

    // we calculate the sum for column on the way while iterating and filling up the table

    sum = grid[0][0];

    for(int i = 1; i < m; i++) {

        sum += grid[i][0];
        dp[0] = sum;

        for(int j = 1; j < n; j++) {
            dp[j] = grid[i][j] + min(dp[j - 1], dp[j]);
        }
    }

    return dp[n - 1];

} // O(mn) time and O(n) space

int main() {
    
    return 0;
}