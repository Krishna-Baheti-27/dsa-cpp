#include <bits/stdc++.h>
using namespace std;

// we have to find the length of longest subsequence which is palindrome

///////////////////////////////////////////////////////////////////////////////////

// brute force is to generate all subsequences and find the one which is palindromic and store max one, but we can do it by just finding the lcs of string and its reverse

int longestCommonSubsequence(string &text1, string &text2) {
    
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

int longestPalindromicSubseq(string s) {
    string reversed = s;
    reverse(reversed.begin(), reversed.end());
    return longestCommonSubsequence(s, reversed);
}

int main() {
    
    return 0;
}