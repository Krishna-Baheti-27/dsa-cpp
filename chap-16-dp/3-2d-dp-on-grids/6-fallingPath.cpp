#include <bits/stdc++.h>
using namespace std;

// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1)
    
/////////////////////////////////////////////////////////////////////////////////////

// here again it is variable dp since we start from any point out of n in the first row and can reach any point on the bottom row by following the constraint of go directly bottom or diagonally to the left or right

int minFallingPathSumHelper(int i, int j, vector<vector<int>> &matrix, int n) {

    if(j < 0 || j > n - 1) {
        return 1e9;
    }

    if(i == n - 1) {
        return matrix[i][j];
    }

    int down = minFallingPathSumHelper(i + 1, j, matrix, n);
    int leftDown = minFallingPathSumHelper(i + 1, j - 1, matrix, n);
    int rightDown = minFallingPathSumHelper(i + 1, j + 1, matrix, n);

    return matrix[i][j] + min(down, min(leftDown, rightDown));
}

int minFallingPathSum(vector<vector<int>> &matrix) {

    int minSum = INT_MAX;
    int n = matrix.size();

    for(int j = 0; j < n; j++) {
        minSum = min(minSum, minFallingPathSumHelper(0, j, matrix, n));
    }

    return minSum;

} // O(N * 3^N) time and O(n) recursion stack space

// since recursion tree has height of N and at each step we do 3^N work

/////////////////////////////////////////////////////////////////////////////////////

int memoHelper(int i, int j, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp) {

    if(j < 0 || j > n - 1) {
        return 1e9;
    }

    if(i == n - 1) {
        return matrix[i][j];
    }

    if(dp[i][j] != INT_MAX) {
        return dp[i][j];
    }

    int down = memoHelper(i + 1, j, n, matrix, dp);
    int leftDown = memoHelper(i + 1, j - 1, n, matrix, dp);
    int rightDown = memoHelper(i + 1, j + 1, n, matrix, dp);

    return dp[i][j] = matrix[i][j] + min(down, min(leftDown, rightDown));
}

int minFallingPathSumMemo(vector<vector<int>> &matrix) {

    int minSum = INT_MAX;
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX)); // means not evaluated

    for(int j = 0; j < n; j++) {
        minSum = min(minSum, memoHelper(0, j, n, matrix, dp));
    }

    return minSum;

} // O(n^2) time and O(n^2) space

// since there are n x n unique states in dp array and each state is unique so we need n^2 function calls

////////////////////////////////////////////////////////////////////////////////////

// here in optimal and tabulation code we dont have to iterate backwards we can simply start from the 0th row also, no worries and we would have to maintain leftDown and rightDown variables anyway

int minPathSumTab(vector<vector<int>> &matrix) {

    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    // handling the base case

    for(int j = 0; j < n; j++) {
        dp[n - 1][j] = matrix[n - 1][j];
    }

    for(int i = n - 2; i >= 0; i--) {
        for(int j = 0; j < n; j++) {

            int leftDown = 1e9;
            if(j > 0) {
                leftDown = dp[i + 1][j - 1];
            }

            int rightDown = 1e9;
            if(j < n - 1) {
                rightDown = dp[i + 1][j + 1];
            }

            dp[i][j] = matrix[i][j] + min(dp[i + 1][j], min(leftDown, rightDown));
        }
    }

    return *min_element(dp[0].begin(), dp[0].end());
}

///////////////////////////////////////////////////////////////////////////////////

int minPathSumOptimal(vector<vector<int>> &matrix) {
    
    int n = matrix.size();

    vector<int> nextRow = matrix[n - 1];

    for(int i = n - 2; i >= 0; i--) {

        vector<int> currRow(n);

        for(int j = 0; j < n; j++) {

            int leftDown = 1e9;
            if(j > 0) {
                leftDown = nextRow[j - 1];
            }

            int rightDown = 1e9;
            if(j < n - 1) {
                rightDown = nextRow[j + 1];
            }

            currRow[j] = matrix[i][j] + min(nextRow[j], min(leftDown, rightDown));
        }

        nextRow = currRow;
    }

    return *min_element(nextRow.begin(), nextRow.end());
}

// here we have both forward and backward dependency and forced to use two arrays

int main() {
    
    return 0;
}