#include<bits/stdc++.h>
using namespace std;

// memoization -> top bottom dp (find the solutions to bigger subproblems first always recursive since recursion always goes from top to bottom that is from answer to base case)
// tabulation -> bottom up dp (aggregate the solution of smaller subproblems using iterations of loops so we go from base case to answer )
// space optimisation -> final solution (just remove redundant  space from tabulation)

// fibonacci series -> 0 1 1 2 3 5 8 ....
// the recurrence realtion is f(n) = f(n - 1) + f(n - 2)

int fibRecur(int n) {
    if(n <= 1) {
        return n;
    }
    return fibRecur(n - 1) + fibRecur(n - 2);
}

/////////////////////////////////////////////////////////////////////////////////////////

// overlapping subproblems -> whenever we end up solving a subproblem again in a problem then that problem in said to contain overlapping subproblems and we can avoid recomputing the already solved subproblem by remembering it using memoization

// in memoization we tend to store the value of subproblems in map/table to avoid recomputing it

int fibMemo(int n, vector<int> &dp) {

    if(n <= 1) {
        return n;
    }
    
    if(dp[n] != -1) {
        return dp[n]; // step 2, dont compute if value available
    }

    return dp[n] = fibMemo(n - 1, dp) + fibMemo(n - 2, dp); // if not then find value and store

}  // O(N) time and O(N) space for array and O(N) recursion stack space

//////////////////////////////////////////////////////////////////////////////////////////

int fibTab(int n) {

    vector<int> dp(n + 1);
    dp[0] = 0, dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];   
    }

    return dp[n];  

} // O(N) time and O(N) array space, no recursion stack space

/////////////////////////////////////////////////////////////////////////////////////////

int fibSpaceOptimal(int n) {

    if(n == 0) {
        return 0;
    }

    int prev = 1, secondPrev = 0;

    for(int i = 2; i <= n; i++) {
        int curr = prev + secondPrev;
        secondPrev = prev;
        prev = curr;
    }

    return prev; // since when loop breaks i would be n + 1 and prev would point to our desired value

} // O(N) time and O(1) space, so the most optimal solution having space optimisation

int main() {
    int n = 5;
    vector<int> dp(n + 1, -1); // step 1, dp array initialisation
    cout << fibMemo(n, dp) << endl;
    cout << fibTab(n) << endl;
    cout << fibSpaceOptimal(n) << endl;
    return 0;
}