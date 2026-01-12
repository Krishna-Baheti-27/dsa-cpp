#include<bits/stdc++.h>
using namespace std;

// same as previous question but here we also have an obstacle which would be marked by 1 on grid and space would be marked as 0, so we have to return the number of total paths to reach from top left to bottom right corner with no obstacle in between

////////////////////////////////////////////////////////////////////////////////////////

// the recurrence would be
// f(i,j) = f(i + 1, j) + f(i, j + 1) provided indices are valid and if any path contains an obstacle then we return 0 since that path cannot be taken

int uniquePaths2BruteHelper(int i, int j, int m, int n, vector<vector<int>> &arr) {

    if(i >= m || j >= n) {
        return 0;
    }

    // check if arr[i][j] == 1 then on that path there is obstacle and no need to check anything there we simply return 0 as no path possible even if we did already our answer of i == m - 1 and j == n - 1

    if(arr[i][j] == 1) {
        return 0;
    }

    // if indices valid and no obstacle and we reach our destination then return 1

    if(i == m - 1 && j == n - 1) {
        return 1;
    }

    int rightPaths = uniquePaths2BruteHelper(i, j + 1, m, n, arr);
    int bottomPaths = uniquePaths2BruteHelper(i + 1, j, m, n, arr);

    return rightPaths + bottomPaths;

} // O(2^(m + n)) time and O(m + n) recursion stack space

int uniquePaths2Brute(vector<vector<int>> &arr) {
    int m = arr.size(), n = arr[0].size();
    return uniquePaths2BruteHelper(0, 0, m, n, arr);
}

////////////////////////////////////////////////////////////////////////////////////////////

// we have a lot of overlapping subproblems so lets convert this into a dp solution using memoization which involves declaring the dp array of same dimension as given array 

int memoHelper(int i, int j, int m, int n, vector<vector<int>> &arr, vector<vector<int>> &dp) {

    if(i >= m || j >= n) {
        return 0;
    }

    if(arr[i][j] == 1) {
        return 0;
    }

    if(i == m - 1 && j == n - 1) {
        return 1;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int rightPaths = memoHelper(i, j + 1, m, n, arr, dp);
    int bottomPaths = memoHelper(i + 1, j, m, n, arr, dp);

    return dp[i][j] = rightPaths + bottomPaths;

} // O(mn) time and O(mn + m + n) space 

int uniquePaths2Memo(vector<vector<int>> &arr) {

    int m = arr.size(), n = arr[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return memoHelper(0, 0, m, n, arr, dp);
}

//////////////////////////////////////////////////////////////////////////////////////////

// to convert this into tabulation we again solve the base case first and then just build up our solution

int uniquePaths2Tab(vector<vector<int>> &arr) {

    int m = arr.size(), n = arr[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0)); // we already initialise everyone to 0 by default

    
    for(int i = 0; i < m; i++) {

        if(arr[i][0] == 1) { // no more path possible beyond obstacle hence break out
            break;
        } else {
            dp[i][0] = 1; // initialise to 1 since only one path possible if no obstacle
        }
    }

    for(int j = 0; j < n; j++) {
        if(arr[0][j] == 1) {
            break;
        } else {
            dp[0][j] = 1;
        }
    }

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {

            // if the current element is 1 then there is not safe path to reahc there and hence without any computation we set dp[i][j] = 0 else wecompute from top and left

            if(arr[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
    }

    return dp[m - 1][n - 1];

} // O(mn) time and O(mn) space (no recursion stack space of O(m + n))

////////////////////////////////////////////////////////////////////////////////////////////

// now again here do the same trick of maintain ansRow and currRow to evalute our final answer

int uniquePaths2Optimal(vector<vector<int>> &arr) {

    int m = arr.size(), n = arr[0].size();
    vector<int> ansRow(n, 0);
    vector<int> ansCol(m, 0);

    // initialise our base case row which will be used to calculate further rows down the line

    for(int j = 0; j < n; j++) {
        if(arr[0][j] == 1) {
            break; 
        } else {
            ansRow[j] = 1;
        }
    } 

    // initialise our first column as we need its value to find the first element (left + above) and subsequent elements are found from using the newly computed element from left + above using ansRow

    for(int i = 0; i < m; i++) { 
        if(arr[i][0] == 1) {
            break;
        } else {
            ansCol[i] = 1;
        }
    }

    for(int i = 1; i < m; i++) {

        vector<int> currRow(n);
        currRow[0] = ansCol[i]; // to get the value of currRow[0] for each row

        for(int j = 1; j < n; j++) {
            if(arr[i][j] == 1) {
                currRow[j] = 0;
            } else {
                currRow[j] = currRow[j - 1] + ansRow[j];
            }
        }

        ansRow = currRow; // make this currRow as our ansRow for finding future rows
    }

    return ansRow[n - 1];

} // O(mn) time and O(2n + m) space

////////////////////////////////////////////////////////////////////////////////////////

// but we can do this in a similar way in which we did the last problem that is using the original ansRow again (overwriting data) and to know whether currRow[0] will be 0 or 1 wwhich will tell if obstacle encountered or not, if obstacle did get encountered then for all subsequent rows the first element would always be 0, before that 1 

int uniquePaths2MostOptimal(vector<vector<int>> &arr) {

    int m = arr.size(), n = arr[0].size();
    vector<int> dp(n, 0);

    for(int j = 0; j < n; j++) {
        if(arr[0][j] == 1) {
            break;
        } else {
            dp[j] = 1;
        }
    }

    for(int i = 1; i < m; i++) {

        // if anyone encountered then we make dp[0] or the paths to first element of the given row = 0 and for all subsequent rows it remains 0
        
        if(arr[i][0] == 1) {
            dp[0] = 0;
        }

        for(int j = 1; j < n; j++) {
            if(arr[i][j] == 1) {
                dp[j] = 0;
            } else {
                dp[j] = dp[j - 1] + dp[j];
            }
        }
    }

    return dp[n - 1];

} // O(mn) time and O(n) space most optimal solution

int main() {
    
    return 0;
}