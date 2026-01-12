#include<bits/stdc++.h>
using namespace std;

// here we are given a triangle array which means its size increase by one in each row, and we have to find the min path sum from top to bottom if we are only allowed to move down the row at i or i + 1 where i is the current index we are at in the current row

///////////////////////////////////////////////////////////////////////////////////////

// again we have to find min possible sum so we have to try all possible ways and return the min sum amongst them

// so our recurrence would be

// f(i,j) = min(f(i + 1, j), f(i + 1, j + 1)) where i and j are valid indices
// f(i ,j) represents the min path sum if we were to start from (0,0) and reach to (i,j) obeying the above constraints of traversal

// in the given triangle for the ith row we have i + 1 columns

// we start from the first since there is only one entry point and but multiple end points and hence preferable to start from a single point

int minPathSumBruteHelper(int i, int j, int n, vector<vector<int>> &triangle) {

    // we reached our destination and hence return the sum there

    if(i == n - 1) {
        return triangle[i][j];
    }

    int downSum = triangle[i][j] + minPathSumBruteHelper(i + 1, j, n, triangle);
    int downRightSum = triangle[i][j] + minPathSumBruteHelper(i + 1, j + 1, n, triangle);

    return min(downSum, downRightSum);

} // O(N * 2^N) time and O(N) recursion stack space

// since we have total columns as 1 + 2 + 3 + 4 ... + n and for each column we have 2 options and hence go below or diagonally below

int minPathSumBrute(vector<vector<int>> &triangle) {
    return minPathSumBruteHelper(0, 0, triangle.size(), triangle);
}

/////////////////////////////////////////////////////////////////////////////////////////

// here in the memo solution we have only maintained only that much state which is reuqired like here we dont have to maintain n x n grid instead size of column depends on row number

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

    // here the size of our dp[i] changes at each level and hence we keep that in account

    for(int i = 0; i < n; i++) {

        // use INT_MIN since triangle[i][j] can be -ve and its only to denote that it has not been visited yet

        vector<int> temp(triangle[i].size(), INT_MIN); 
        dp.push_back(temp);
    }

    return memoHelper(0, 0, n, triangle, dp);
}

////////////////////////////////////////////////////////////////////////////////////////////

int minPathSumTab(vector<vector<int>> &triangle) {

    int n = triangle.size();
    vector<vector<int>> dp;

    for(int i = 0; i < n; i++) {
        vector<int> temp(triangle[i].size(), INT_MAX);
        dp.push_back(temp);
    }

    // now handle the base cases

    dp[0][0] = triangle[0][0];

    for(int i = 1; i < n; i++) {

        // handling the edge case of first and last element

        dp[i][0] = triangle[i][0] + dp[i - 1][0]; 
        dp[i][i] = triangle[i][i] + dp[i - 1][i - 1];

        for(int j = 1; j < i; j++) {
            dp[i][j] = triangle[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]);   
        }
    }

    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
}

/////////////////////////////////////////////////////////////////////////////////////

// now we write the optimal wrt to this

int minPathSumOptimal(vector<vector<int>> &triangle) {

    int n = triangle.size();
    vector<int> dp(n, INT_MAX);

    // base case 

    dp[0] = triangle[0][0];

    for(int i = 1; i < n; i++) {

        // here again we have fear of overwriting and hence we have to iterate backwards since if the value of dp[j] is overwritten like we update dp[j] and in future we might want to use dp[j - 1] and the value we would get would be incorrect and hence we iterate backwards so that we dont have this backward dependency

        dp[i] = triangle[i][i] + dp[i - 1]; // came from i - 1 only

        for(int j = i - 1; j > 0; j--) {
            dp[j] = triangle[i][j] + min(dp[j], dp[j - 1]);
        }

        dp[0] = triangle[i][0] + dp[0]; // came from 0 only
    }

    return *min_element(dp.begin(), dp.end());
}

//////////////////////////////////////////////////////////////////////////////////

// now cleaner code for above

int minPathSumOptimal(vector<vector<int>> &triangle) {

    int n = triangle.size();
    vector<int> dp(n, 1e9); // Initialize with a large value to act as infinity

    // Base case

    dp[0] = triangle[0][0];

    for(int i = 1; i < n; i++) {
       
        for(int j = i; j >= 0; j--) {
            
            // If j == 0, we only have 'up' (dp[j]). 
            // If j == i, we only have 'diagUp' (dp[j-1]).
            // Otherwise, we take the min of both.
            
            int prev_diag = (j > 0) ? dp[j - 1] : 1e9;
            int prev_up   = (j < i) ? dp[j] : 1e9;
            
            dp[j] = triangle[i][j] + min(prev_up, prev_diag);
        }
    }

    return *min_element(dp.begin(), dp.end());
}

///////////////////////////////////////////////////////////////////////////////////////

// now the pro approach is instead do the top - bottom approach to avoid this INT_MAX which prevents us from writing clean code, since intially we were using separate checks for corner elements like first and last for a row 

int minPathSumTabBetter(vector<vector<int>> &triangle) {

    int n = triangle.size();
    vector<vector<int>> dp;

    // initialising the dp array

    for(int i = 0; i < n; i++) {
        vector<int> temp(triangle[i].size(), INT_MAX);
        dp.push_back(temp);
    }

    // handling the base case (here we do it from n - 1 to 0) and hence doing it for the last row first

    for(int j = 0; j < n; j++) {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    // then fill rest n - 1 rows

    for(int i = n - 2; i >= 0; i--) {

        for(int j = 0; j < i + 1; j++) {

            // do the same as in recurrence, for the dp[i][j] we take the min from the above possible options (directly above and diagonall above)

            dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    return dp[0][0];

} // O(n^2) time and O(n^2) space

///////////////////////////////////////////////////////////////////////////////////

// now space optimised version of pro approach

int minPathSumOptimalBetter(vector<vector<int>> &triangle) {

    int n = triangle.size();

    // initialse the base case which is just the last row and then just update each element since we wont need it after

    vector<int> dp = triangle[n - 1];

    for(int i = n - 2; i >= 0; i--) {
        for(int j = 0; j < i + 1; j++) {
            dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
        }
    }

    return dp[0];
}

int main() {
    
    return 0;
}