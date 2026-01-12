#include <bits/stdc++.h>
using namespace std;

// this is beginning of partition dp where we can have multiple partitions and we have to solve for each partition

/////////////////////////////////////////////////////////////////////////////////////

// Given an array arr[] which represents the dimensions of a sequence of matrices where the ith matrix has the dimensions (arr[i-1] x arr[i]) for i>=1, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

///////////////////////////////////////////////////////////////////////////////////////

// we have to reduce the number of multiplication operations to minimum to find the most efficient way to multiply matrices

// we are given the arr having n length of dimensions of n - 1 matrices

// partition dp rules =>
// 1) start with entire array or block (i -> start or 0 and j -> end or n - 1)
// 2) try all partititions (run a loop to try all)
// 3) return the best possible partition of 2

// f(i,j) returns the min operations for range i to j
// here our i starts from 1 and j starts from n - 1 so our block is f(1, n - 1)
// the base case is if i == j return 0
// now we run loop from i to j - 1 to create all partitions

int mcmBruteHelper(int i, int j, vector<int> &arr) {

    if(i >= j) {
        return 0;
    }

    int minOps = INT_MAX;

    for(int k = i; k < j; k++) {
        minOps = min(minOps, (arr[i - 1] * arr[k] * arr[j]) + mcmBruteHelper(i, k, arr) + mcmBruteHelper(k + 1, j, arr));
    }

    return minOps;
}

int mcmBrute(vector<int> &arr) {

    int n = arr.size();
    return mcmBruteHelper(1, n - 1, arr);

} // time complexity will be exponential (tough to compute no need to do)

//////////////////////////////////////////////////////////////////////////////////////

int memoHelper(int i, int j, int n, vector<int> &arr, vector<vector<int>> &dp) {

    if(i >= j) {
        return 0;
    }
    
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int minOps = INT_MAX;

    for(int k = i; k < j; k++) {
        minOps = min(minOps, (arr[i - 1] * arr[k] * arr[j]) + memoHelper(i, k, n, arr, dp) + memoHelper(k + 1, j, n, arr, dp));
    }

    return dp[i][j] = minOps;
}

int mcmMemo(vector<int> &arr) {

    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return memoHelper(1, n - 1, n, arr, dp);

} // O(n^3) time since for n^2 states the inner loop runs n times in worst case and O(n^2) space and O(n) recursion stack space

/////////////////////////////////////////////////////////////////////////////////////

// the base case is i == j then return 0

int mcmTab(vector<int> &arr) {

    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // base case initialised by default

    // now just vary all the paramters and copy the recurrence

    // in the top to bottom solution we varied i from 1 to n - 1 and hence here i goes from n - 1 to 1 and since j is always on the right of i hence start j from i + 1 to n - 1

    for(int i = n - 1; i >= 1; i--) {

        for(int j = i + 1; j < n; j++) {

            int minOps = INT_MAX;

            for(int k = i; k < j; k++) {
                minOps = min(minOps, (arr[i - 1] * arr[k] * arr[j]) + dp[i][k] + dp[k + 1][j]);
            }

            dp[i][j] = minOps;
        }
    }

    return dp[1][n - 1];

} // O(n^3) time and O(n^2) space

//////////////////////////////////////////////////////////////////////////////////

// this pattern of dp called as interval dp cannot be space optimised to dependency preservation issue as each time we are accessing elements from all previous rows and hence there is no space optimisation

int main() {
    
    return 0;
}