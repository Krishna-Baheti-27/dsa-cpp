#include <bits/stdc++.h>
using namespace std;

// we have to print the LCS and not only its length and it can be easily done using the dp table so here is the way to print all the LCS (there maybe multiple)

///////////////////////////////////////////////////////////////////////////////////

// to create the dp table

vector<vector<int>> lcsTabBetter(string &text1, string &text2) {
    
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

    return dp;

} // O(n * m) time and space

////////////////////////////////////////////////////////////////////////////////////

// so this is the code to find any given lcs

string printLcs(string &s1, string &s2) {
    
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp = lcsTabBetter(s1,s2);

    int i = n, j = m;
    int index = dp[n][m] - 1;
    string s(index + 1, '$');

    while(i != 0 && j != 0) {

        if(s1[i - 1] == s2[j - 1]) {
            s[index] = s1[i - 1];
            index--;
            i--;
            j--;
        } else if(dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return s;

} // O(n * m) time and space

////////////////////////////////////////////////////////////////////////////////////

// to find all the lcs sorted in lexicographical order we probably have to use recursion since we have to explore all paths

void lcsHelper(int i, int j, string &s1, string &s2, vector<string> &ans, string &s, int index, vector<vector<int>> &dp) {

    if(i == 0 || j == 0) {
        return;
    }

    if(s1[i - 1] == s2[j - 1]) {

        s[index] = s1[i - 1];

        if(index == 0) {
            ans.push_back(s);
            return;
        } else {
            lcsHelper(i - 1, j - 1, s1, s2, ans, s, index - 1, dp);
        }
    } else if(dp[i - 1][j] > dp[i][j - 1]) {
        lcsHelper(i - 1, j, s1, s2, ans, s, index, dp);
    } else if(dp[i - 1][j] < dp[i][j - 1]) {
        lcsHelper(i, j - 1, s1, s2, ans, s, index, dp);
    } else {
        lcsHelper(i - 1, j, s1, s2, ans, s, index, dp);
        lcsHelper(i, j - 1, s1, s2, ans, s, index, dp);
    }
}

vector<string> allLcs(string &s1, string &s2) {

    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp = lcsTabBetter(s1,s2);

    vector<string> ans;

    int index = dp[n][m] - 1;
    string s(index + 1, '$');
    
    lcsHelper(n, m, s1, s2, ans, s, index, dp);

    return ans;
}

// but there is the problem in this code that even with two different paths we may end up forming the same lcs and we also dont maintain the lexicographical or alphabetical order and hence we use the set to serve both purposes and also we are using index variable and not physically appending or popping to string like a vector and hence when backtracking we dont do anything special, next time the index automatically overwrites according to our need

////////////////////////////////////////////////////////////////////////////////////

void lcsHelperBetter(int i, int j, string &s1, string &s2, set<string> &ansSet, string &s, int index, vector<vector<int>> &dp) {

    // Base Case: If we have filled the string (index < 0), we are done.
    // Note: Checking index < 0 is safer than index == 0 inside the loop

    if(index < 0) {
        ansSet.insert(s);
        return;
    }
    
    // Boundary check (though index < 0 usually catches it, this saves cycles)

    if(i == 0 || j == 0) {
        return;
    }

    
    if(s1[i - 1] == s2[j - 1]) {

        s[index] = s1[i - 1]; 
        lcsHelperBetter(i - 1, j - 1, s1, s2, ansSet, s, index - 1, dp);

    } else {

        if(dp[i - 1][j] > dp[i][j - 1]) {
            lcsHelperBetter(i - 1, j, s1, s2, ansSet, s, index, dp);
        } else if (dp[i][j - 1] > dp[i - 1][j]) {
            lcsHelperBetter(i, j - 1, s1, s2, ansSet, s, index, dp);
        } else {
            lcsHelperBetter(i - 1, j, s1, s2, ansSet, s, index, dp);
            lcsHelperBetter(i, j - 1, s1, s2, ansSet, s, index, dp);
        }
    }
}

vector<string> allLcs(string &s1, string &s2) {
   
    vector<vector<int>> dp = lcsTabBetter(s1, s2);
    
    int n = s1.length();
    int m = s2.length();
    
    if (dp[n][m] == 0) {
        return {};
    }

    set<string> ansSet; 
    int lcsLen = dp[n][m];
    string s(lcsLen, '$'); 

    lcsHelperBetter(n, m, s1, s2, ansSet, s, lcsLen - 1, dp);

    vector<string> ans(ansSet.begin(), ansSet.end());

    return ans;

} // O(2^k * set insertion time) where k is the number of times we branch and O(n + m) recursion stack space

/////////////////////////////////////////////////////////////////////////////////////

// but even this solution gets TLE on GFG since we are repeatedly calculating the same state multiple times like f(2,2) many times through different paths and hence we must optimise this

vector<string> memo[101][101]; 
bool visited[101][101];

// Recursive function with Memoization
vector<string> solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
    // 1. Base Case: End of string
    if (i == 0 || j == 0) {
        return {""}; // Return a list containing one empty string
    }

    // 2. Check Memoization
    if (visited[i][j]) {
        return memo[i][j];
    }

    set<string> currentSet; // Use Set to avoid duplicates automatically

    // 3. Logic
    if (s1[i - 1] == s2[j - 1]) {
        // MATCH: Get all results from diagonal
        vector<string> temp = solve(i - 1, j - 1, s1, s2, dp);
        
        // Append current char to all returned strings
        for (string &str : temp) {
            currentSet.insert(str + s1[i - 1]);
        }
    } else {
        // MISMATCH
        if (dp[i - 1][j] >= dp[i][j - 1]) {
            // Pick from UP
            vector<string> temp = solve(i - 1, j, s1, s2, dp);
            currentSet.insert(temp.begin(), temp.end());
        }
        
        if (dp[i][j - 1] >= dp[i - 1][j]) {
            // Pick from LEFT
            // Note: We use distinct IFs (not else if) to handle the EQUAL case 
            // where we must explore BOTH directions.
            vector<string> temp = solve(i, j - 1, s1, s2, dp);
            currentSet.insert(temp.begin(), temp.end());
        }
    }

    // 4. Store and Return
    visited[i][j] = true;
    
    // Convert set back to vector for storage
    vector<string> result(currentSet.begin(), currentSet.end());
    return memo[i][j] = result;
}

vector<string> all_longest_common_subsequences(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    
    // Reset globals
    for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++)
            visited[i][j] = false;

    // Step 1: Build Length DP Table
    vector<vector<int>> dp = lcsTabBetter(s1, s2);
    
    // Step 2: Get results via Memoized Recursion
    vector<string> ans = solve(n, m, s1, s2, dp);
    
    // Step 3: Sort required by GFG
    sort(ans.begin(), ans.end());
    
    return ans;
}

int main() {
    
    return 0;
}