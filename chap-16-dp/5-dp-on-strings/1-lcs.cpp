#include <bits/stdc++.h>
using namespace std;

// we already know the subsequence (contiguous or non-contiguous but follows the order)
// the longest common subsequence is the length of longest subsequence which is common to both string 1 and string 2

/////////////////////////////////////////////////////////////////////////////////////

// so we can generate all subsequences but that would be 2^n * 2^m and hence we do generate subsequences and compare on the way hence write the recurrence following this rule that is

// the recurrence would be for f(i,j) tell us the lcs for string 1 for index [0..i] and for string 2 for index [0..j]

// f(i,j) = 1 + f(i - 1, j - 1) if(s1[i] == s2[j])
        //  else max(f(i, j - 1), f(i - 1,j))

// till i and j >= 0

int lcsBruteHelper(int i, int j, string &text1, string &text2) {

    if(i < 0 || j < 0) {
        return 0;
    }

    if(text1[i] == text2[j]) {
        return 1 + lcsBruteHelper(i - 1, j - 1, text1, text2);
    } else {
        return max(lcsBruteHelper(i, j - 1, text1, text2), lcsBruteHelper(i - 1, j, text1, text2));
    }

} // O(2^(m + n)) time since if there are all mismatches then in the worst cse we have a tree of height m + n and also O(m + n) space

int lcsBrute(string text1, string text2) {
    return lcsBruteHelper(text1.length() - 1, text2.length() - 1, text1, text2);
}

/////////////////////////////////////////////////////////////////////////////////////

int memoHelper(int i, int j, string &text1, string &text2, vector<vector<int>> &dp) {

    if(i < 0 || j < 0) {
        return 0;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    if(text1[i] == text2[j]) {
        return dp[i][j] = 1 + memoHelper(i - 1, j - 1, text1, text2, dp);
    } else {
        return dp[i][j] = max(memoHelper(i, j - 1, text1, text2, dp), memoHelper(i - 1, j, text1, text2, dp));
    }
}

int lcsBrute(string text1, string text2) {

    int n = text1.length();
    int m = text2.length();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return memoHelper(n - 1, m - 1, text1, text2, dp);

} // O(n * m) time and space

//////////////////////////////////////////////////////////////////////////////////////

int lcsTab(string text1, string text2) {

    int n = text1.length();
    int m = text2.length();

    vector<vector<int>> dp(n, vector<int>(m));

    // base case

    bool isPoss = false;

    for(int j = 0; j < m; j++) {

        if(text1[0] == text2[j]) {
            isPoss = true;
        }

        if(isPoss) {
            dp[0][j] = 1;
        } else {
            dp[0][j] = 0;
        }
    }
    
    // now fill up rest of the table

    for(int i = 1; i < n; i++) {

        if(text1[i] == text2[0]) {
            dp[i][0] = 1;
        } else {
            dp[i][0] = dp[i - 1][0];
        }

        for(int j = 1; j < m; j++) {
            if(text1[i] == text2[j]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    return dp[n - 1][m - 1];

} // O(n * m) time and space but no recursion stack space

///////////////////////////////////////////////////////////////////////////////

// but here as we can see we had to write a lot of checks for 0th row and 0th column and to avoid that and write clean code we initialise dp with n + 1, m + 1 and then simply write our recurrence

// this is because in our base case we have i < 0 || j < 0 then return 0 which means we return for f(-1) but we cant have dp[-1] and hence we shift everything to right by 1 that is treat f(n,m) instead of f(n - 1. m - 1) but still use n - 1 and m - 1 for f(n,m), this ways -1 maps to dp[0]

int lcsTabBetter(string text1, string text2) {
    
    int n = text1.length();
    int m = text2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // here we already have our base cases initilised to 0 and hence dont have to write it separately just write the recurrence and fill our required table from 1 to n and m, because our base case was dp[i][0] = 0 and dp[0][j] = 0 (done by default during the initialisation)

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(text1[i - 1] == text2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    return dp[n][m];

} // O(n * m) time and space

/////////////////////////////////////////////////////////////////////////////////////

// now we write space optimised version wrt this

// so write dp always wrt to the inner loop and hence declare it of size same as inner variables string and to be efficient always iterate on the smaller length string for less memory usage

int lcsOptimal(string text1, string text2) {

    int n = text1.length();
    int m = text2.length();

    vector<int> dp(m + 1, 0);

    for(int i = 1; i <= n; i++) {

        vector<int> curr(m + 1, 0);

        for(int j = 1; j <= m; j++) {
            if(text1[i - 1] == text2[j - 1]) {
                curr[j] = 1 + dp[j - 1];
            } else {
                curr[j] = max(curr[j - 1], dp[j]);
            }
        }

        dp = curr;
    }

    return dp[m];
     
} // O(n * m) time and O(2 * min(n,m)) space

////////////////////////////////////////////////////////////////////////////////////

// reason we were not able to do it using single array was we also needed to maitain the diagonally above element but here is an even more optimised code using only single array and in which we store diagonal value in a variable

// val = max(up, left) so we have to overwrite dp[j] going from 1 to m but store the diagonal since that might be needed and hence prev = dp[j]

int longestCommonSubsequence(string text1, string text2) {
    
    int n = text1.length();
    int m = text2.length();

    // OPTIMIZATION: Always make the inner loop iterate over the SHORTER string 
    // to minimize memory usage.

    if (n < m) {
        return longestCommonSubsequence(text2, text1); 
    }

    vector<int> dp(m + 1, 0);

    for (int i = 1; i <= n; i++) {

        int prev = 0; // Represents dp[i-1][j-1] (the diagonal)
        
        for (int j = 1; j <= m; j++) {

            // Store current value before overwriting (becomes prev for next j)

            int temp = dp[j]; 

            if (text1[i - 1] == text2[j - 1]) {
                dp[j] = 1 + prev;
            } else {
                dp[j] = max(dp[j], dp[j - 1]);
            }

            prev = temp; // Update prev for the next column iteration
        }
    }

    return dp[m];

} // O(n * m) time and O(min(n,m)) space

int main() {
    
    return 0;
}