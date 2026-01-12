#include <bits/stdc++.h>
using namespace std;

// this problem is different from leetcode cherry pickup but exactly same as cherry pickup 2

// alice starts at (0,0) and bob at (0, c - 1) and both can move directly down or diagonally and they pick up the chocolates on each cell, return the max both can pick up, if they are at same cell only one can pick it up

///////////////////////////////////////////////////////////////////////////////////

// so we cannot separately do recursion for each as then we would not know the common cells and to keep track of that we would have trace back which is very difficult and complex and hence we start both of them together so we would be able to track them

// and in each move they are moving one row down and both at same row and hence we keep only 1 i and not i1 and i2

// we discard the case where alice or bob goes out of grid since that is not valid configuration and even if we were to consider that we would neet to create a separate logic for handling null values (where either j1 or j2 is out array) and even after that since this is maximisation problem the max path would always be one where both alice and bob pickup sine array elements are positive and hence X + Y > X or Y

int maxChocBruteHelper(int i, int j1, int j2, int r, int c, vector<vector<int>> &arr) {

    if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c) {
        return -1e8; 
    }

    if(i == r - 1) {
        if(j1 != j2) {
            return arr[i][j1] + arr[i][j2];
        } else {
            return arr[i][j1];
        }
    }

    int maxChoc = INT_MIN;

    for(int k = -1; k <= 1; k++) {
        for(int l = -1; l <= 1; l++) {
            if(j1 == j2) {
                maxChoc = max(maxChoc, arr[i][j1] + maxChocBruteHelper(i + 1, j1 + k, j2 + l, r, c, arr));
            } else {
                maxChoc = max(maxChoc, arr[i][j1] + arr[i][j2] + maxChocBruteHelper(i + 1, j1 + k, j2 + l, r, c, arr));
            }
        }
    }

    return maxChoc;

} // O(r * 9^r) time and O(r) space

int maxChocBrute(vector<vector<int>> &arr) {
    int r = arr.size();
    int c = arr[0].size();
    return maxChocBruteHelper(0, 0, c - 1, r, c, arr);
}

////////////////////////////////////////////////////////////////////////////////

// here we apply dp with 3 states that is i, j1, j2

int memoHelper(int i, int j1, int j2, int r, int c, vector<vector<int>> &arr, vector<vector<vector<int>>> &dp) {

    if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c) {
        return -1e8; 
    }

    if(i == r - 1) {
        if(j1 != j2) {
            return arr[i][j1] + arr[i][j2];
        } else {
            return arr[i][j1];
        }
    }

    if(dp[i][j1][j2] != INT_MIN) {
        return dp[i][j1][j2];
    }

    int maxChoc = INT_MIN;

    for(int k = -1; k <= 1; k++) {
        for(int l = -1; l <= 1; l++) {
            if(j1 == j2) {
                maxChoc = max(maxChoc, arr[i][j1] + memoHelper(i + 1, j1 + k, j2 + l, r, c, arr, dp));
            } else {
                maxChoc = max(maxChoc, arr[i][j1] + arr[i][j2] + memoHelper(i + 1, j1 + k, j2 + l, r, c, arr, dp));
            }
        }
    }

    return dp[i][j1][j2] = maxChoc;    
}

int maxChocMemo(vector<vector<int>> &arr) {

    int r = arr.size();
    int c = arr[0].size();

    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, INT_MIN)));

    return memoHelper(0, 0, c - 1, r, c, arr, dp);

} // O(r * c^2) time and space

////////////////////////////////////////////////////////////////////////////////

int maxChocTab(vector<vector<int>> &arr) {

    int r = arr.size();
    int c = arr[0].size();

    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, INT_MIN)));

    // handling the base case for i == r - 1

    for(int j1 = 0; j1 < c; j1++) {
        for(int j2 = 0; j2 < c; j2++) {
            if(j1 == j2) {
                dp[r - 1][j1][j2] = arr[r - 1][j1];
            } else {
                dp[r - 1][j1][j2] = arr[r - 1][j1] + arr[r - 1][j2];
            }
        }
    }

    for(int i = r - 2; i >= 0; i--) {
        for(int j1 = 0; j1 < c; j1++) {
            for(int j2 = 0; j2 < c; j2++) {

                int maxChoc = INT_MIN;

                for(int k = -1; k <= 1; k++) {
                    for(int l = -1; l <= 1; l++) {

                        int value = 0;

                        if(j1 == j2) {
                            value = arr[i][j1];
                        } else {
                            value = arr[i][j1] + arr[i][j2];
                        }

                        if(j1 + k >= 0 && j1 + k < c && j2 + l >= 0 && j2 + l < c) {
                            value += dp[i + 1][j1 + k][j2 + l];
                        } else {
                            value += -1e8;
                        }

                        maxChoc = max(maxChoc, value);
                    }
                }

                dp[i][j1][j2] = maxChoc;
            }
        }
    }

    return dp[0][0][c - 1];
}

////////////////////////////////////////////////////////////////////////////////////

int maxChocOptimal(vector<vector<int>> &arr) {

    int r = arr.size();
    int c = arr[0].size();

    vector<vector<int>> dp(c, vector<int>(c));

    // handling the base case

    for(int j1 = 0; j1 < c; j1++) {
        for(int j2 = 0; j2 < c; j2++) {
            if(j1 == j2) {
                dp[j1][j2] = arr[r - 1][j2];
            } else {
                dp[j1][j2] = arr[r - 1][j1] + arr[r - 1][j2];
            }
        }
    }

    for(int i = r - 2; i >= 0; i--) {

        vector<vector<int>> curr(c, vector<int>(c));

        for(int j1 = 0; j1 < c; j1++) {
            for(int j2 = 0; j2 < c; j2++) {

                int maxChoc = INT_MIN;

                for(int k = -1; k <= 1; k++) {
                    for(int l = -1; l <= 1; l++) {

                        int value = 0;
                        if(j1 == j2) {
                            value = arr[i][j1];
                        } else {
                            value = arr[i][j1] + arr[i][j2];
                        }

                        if(j1 + k >= 0 && j1 + k < c && j2 + l >= 0 && j2 + l < c) {
                            value += dp[j1 + k][j2 + l];
                        } else {
                            value += -1e8;
                        }

                        maxChoc = max(maxChoc, value);
                    }
                }

                curr[j1][j2] = maxChoc;
            }
        }

        dp = curr;
    }

    return dp[0][c - 1];
}

int main() {
    
    return 0;
}