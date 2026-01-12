#include <bits/stdc++.h>
using namespace std;

// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
// In one step, you can delete exactly one character in either string

//////////////////////////////////////////////////////////////////////////////////

// since here we are only allowed to delete, so we will try to conserve as much part as we can from both the strings and rest we are forced to delete so that we have min operations and hence remove all elements from both strings apart from elements in lcs

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

int minDeletions(string word1, string word2) {
    int lenLCSubstr = longestCommonSubsequence(word1, word2);
    int ans = 0;
    if(word1.length() > lenLCSubstr) {
        ans += word1.length() - lenLCSubstr;
    } 
    if(word2.length() > lenLCSubstr) {
        ans += word2.length() - lenLCSubstr;
    }

    return ans;
}

int main() {
    
    return 0;
}