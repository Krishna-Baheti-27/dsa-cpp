#include<bits/stdc++.h>
using namespace std;

// solution using memoization, which is top-bottom approach
// first initialise dp with size n + 1 and all -1 for this to work
int fiboMemo(int n, vector<int> &dp) {
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n]; // answer stored
    return dp[n] = fiboMemo(n - 1, dp) + fiboMemo(n - 2, dp);
} // O(N) time as its not exponential anymore and base case calls take O(1) time
// O(N) recursion space + O(N) array space

// solution using tabulation, which is bottom-top approach

// we know the base case is for n <= 1 => dp[0] = 0, and dp[1] = 1
// so we initialise our dp array with this and we know that recursion will be called from n = 2 and thatd why we start our loop from i = 2 to n
int fiboTab(int n, vector<int> &dp) {
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
} // O(N) time and just O(N) space

int fiboSpaceOptimisation(int n, vector<int> &dp) {
    if(n == 0) return 0; 
    int prev2 = 0, prev = 1; // and our current element is after prev
    for(int i = 1; i <= n - 2; i++) {
        int current = prev2 + prev;
        prev2 = prev;
        prev = current;
    }
    return prev;
}

int main() {
    
    return 0;
}