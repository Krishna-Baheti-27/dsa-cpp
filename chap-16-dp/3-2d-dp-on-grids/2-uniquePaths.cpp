#include<bits/stdc++.h>
using namespace std;

// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner

////////////////////////////////////////////////////////////////////////////////////////

// so we start from mat[0][0] and either we can move right or down that is from mat[i][j] we can move mat[i + 1][j] or mat[i][j + 1], and we have to return all possible ways so we solve it by summing all ways by first taking right with summing all ways by first taking left and then add the value returned by both left and right function calls

// here left and right are basically implying down and right

// since we have to return the total possible ways which means we have to apply recursion so how to write the recurrence for this

// f(i,j) = f(i + 1, j) + f(i, j + 1) provided the indices are valid
// so f(i,j) means the number of unique ways to reach from (0,0) to (i,j)

int uniquePathsHelper(int i, int j, int m, int n) {

    // out of grid and no path exists

    if(i >= m || j >= n) {
        return 0;
    }

    // got to our destination and hence count it as 1 path

    if(i == m - 1 && j == n - 1) {
        return 1;
    }

    int rightPaths = uniquePathsHelper(i, j + 1, m, n);
    int downPaths = uniquePathsHelper(i + 1, j, m, n);

    return rightPaths + downPaths;

} 

int uniquePathsBrute(int m, int n) {

    return uniquePathsHelper(0, 0, m, n);

} // O(2^(m + n)) time since total we have m - 1 + n - 1 function calls in worst case and for each we have two options and O(m + n) recursion stack space in worst case

// Why: In the worst case (brute force), you are building a recursion tree.Tree Depth: To go from (0,0) to (m,n), every single path requires exactly m-1 Down moves and n-1 Right moves.Total depth of recursion = (m-1) + (n-1) approx m + n.Branching: At every step, you make 2 calls (rightPaths and downPaths).Calculation: A tree with depth d and branching factor 2 has roughly 2^d nodes

///////////////////////////////////////////////////////////////////////////////////////////

// now lets apply memoization on this as we have lot of overlapping subproblems

int memoHelper(int i, int j, int m, int n, vector<vector<int>> &dp) {

    if(i >= m && j >= n) {
        return 0;
    }

    if(i == m - 1 && j == n - 1) {
        return 1;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int rightPaths = memoHelper(i, j + 1, m, n, dp);
    int downPaths = memoHelper(i + 1, j, m, n, dp);

    return dp[i][j] = rightPaths + downPaths;

} // O(mn) time and O(mn) space + O(m + n) recursion stack space

int uniquePathsMemo(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return memoHelper(0, 0, m, n, dp);
}

/////////////////////////////////////////////////////////////////////////////////////////

// in the tabulation approach we simply use the dp array of same dimension as in memoization and they try to build up the solution row by row or according to question from bottom to up

int uniquePathsTab(int m, int n) {

    vector<vector<int>> dp(m, vector<int>(n));

    // dp[i][j] represents the number of ways to reach from (0,0) to (i,j)

    // dp[0][0] is not equal to 0 since there is one path from (0,0) to (0,0) which is sort of self loop but still counts as a path as src == dest

    // initialising the first row and first col with 1 (our base case)

    for(int j = 0; j < n; j++) {
        dp[0][j] = 1;
    }

    for(int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }

    // now build later solution row by row

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; // from above or left
        }
    }

    return dp[m - 1][n - 1];

} // O(mn) time and O(mn) space, no recursion stack space

/////////////////////////////////////////////////////////////////////////////////////////

// to convert the tabulation into space optimised solution we check where are using redundant space and what exactly is needed so

// here we find that we only need the above row to build the new solution row and not all the rows and columns (also the first element of new columns is 1 in all cases and hence not needed to be derived from the previous row)

int uniquePathsOptimal(int m, int n) {

    vector<int> ansRow(n, 1);

    for(int i = 1; i < m; i++) {

        vector<int> currRow(n);
        currRow[0] = 1;

        for(int j = 1; j < n; j++) {
            currRow[j] = ansRow[j] + currRow[j - 1]; // above + left
        }

        ansRow = currRow; // make the currRow as new answer row for finding future rows
    }

    return ansRow[n - 1];

} // O(mn) time and O(2n) space

///////////////////////////////////////////////////////////////////////////////////////////

// but we can optimise this even further that is using a single array since overwriting here doesnt harm us since we are overwriting the values of dp[j] but they we wont need it anyway for computation of new element we will need value of dp[j + 1] when do come to j + 1

int uniquePathsMostOptimal(int m, int n) {

    vector<int> dp(n, 1);

    for(int i = 1; i < m; i++) {
        
        for(int j = 1; j < n; j++) {

            // so simply overwrite dp[j] since that value would only be needed for the next iteration and not current one

            dp[j] = dp[j - 1] + dp[j]; // left + above
        }
    }

    return dp[n - 1];

} // O(mn) time and O(n) space (the only space required is to remember the space for above row)

int main() {
    
    return 0;
}