#include <bits/stdc++.h>
using namespace std;

// we have to find the length of longest common substring, same as subsequence but it must be contiguous

// so the only difference is that if we have a much we do 1 + f(i - 1, j - 1) but if no match then straight up 0, we start from scratch since we are no longer contiguous 

// so here is the tabulation since for recursion and memo we would have 3 states and we would not want to go into that complication

int lcSubstr(string &s1, string &s2) {

    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int maxlen = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                maxlen = max(maxlen, dp[i][j]);
            } 
        }
    }

    return maxlen;

} // O(n * m) time and space

int main() {
    
    return 0;
}