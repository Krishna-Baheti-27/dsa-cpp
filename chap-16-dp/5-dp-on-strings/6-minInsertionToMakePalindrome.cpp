#include <bits/stdc++.h>
using namespace std;

// Given a string s. In one step you can insert any character at any index of the string.
// Return the minimum number of steps to make s palindrome.

//////////////////////////////////////////////////////////////////////////////////////

// here we want to minimise the number of operations so what we will do is to keep the longest palidromic part (or longest palidromic subsequence) intact and rest of the letters left would be just reversed and put in appropriate places so that we have the palindrome

// so our answer is length of string - length of longest palindromic subseqeunce

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

int minOpToMakePalindrome(string &s) {
    string reversed = s;
    reverse(reversed.begin(), reversed.end());
    return s.length() - longestCommonSubsequence(s, reversed);
}


int main() {
    
    return 0;
}