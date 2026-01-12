#include<bits/stdc++.h>
using namespace std;

// the problem is starting from the 0th stair we have to reach the Nth stair each time taking only one or two steps so we have to return the number of distinct ways to do so

// this is similar to our problem where we have to make a particular sum using given set of elements so here we have to make sum of N using 1 and 2 and we have to return how many such configurations are possible

//////////////////////////////////////////////////////////////////////////////////////////

// how to understand whether its a dp problem
// whenever the question is like count number of ways or there are multiple ways to do something and find min or max output

// so the above thing gives us idea about recursion and once we write recurrence relation then we can apply dp on it

// Shortcut to write recurrence relation
// 1) Try to represent the problem in terms of index
// 2) Do all possible stuffs on that index according to problem statement (like count total possible ways or find min max)
// 3) Sum of all stuffs => count all ways which are possible 
//  Min or max of all stuffs => find min or max

/////////////////////////////////////////////////////////////////////////////////////////

// now here is the approach for this problem
// here we at each time we can either take 1 or 2 steps, so if we are standing at nth step and f(n) represents the number of ways we can reach the nth step then we came there either from n - 1 or n - 2 since thats what allowed as a jump (1 or 2), so number of ways of reaching n is f(n) which is number of ways of reaching n - 1th step + number of ways of reaching n - 2th step = f(n - 1) + f(n - 2)

// now for the base cases (given 1 <= n <= 45)
// f(1) = 1, only one way that is take one step from n = 0
// f(2) = 2, two ways that is 1 1 and 2

// and now f(3) = f(1) + f(2), so now everything from n >= 3 can be computed from the base cases n = 1 and n = 2

int climbStairsBrute(int n) {

    if(n <= 2) {
        return n;
    }

    return climbStairsBrute(n - 1) + climbStairsBrute(n - 2);

} // O(2^n) time and O(n) space

///////////////////////////////////////////////////////////////////////////////////////////

int memHelper(int n, vector<int> &dp) {

    if(n <= 2) {
        return n;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    return dp[n] = memHelper(n - 1, dp) + memHelper(n - 2, dp);
}

int climbStairsMemo(int n) {

    vector<int> dp(n + 1, -1);
    return memHelper(n, dp);
    
} // O(n) time and O(2n) space similar to fibonacci

//////////////////////////////////////////////////////////////////////////////////////////

int climbStairsTab(int n) {

    if(n <= 2) {
        return n;
    }

    vector<int> dp(n + 1);
    dp[1] = 1, dp[2] = 2; // no error here since n >= 3 so no problem in accessing dp[2]

    // also we dont use the value of dp[0] but its just for good measure so we are actually storing the number of ways in each corresponding entry of dp array

    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];

} // O(n) time ans O(n) space

//////////////////////////////////////////////////////////////////////////////////////////

// now here in the optimal solution similar to fibonacci we maintain the last two entries that are prev and secondPrev since only they are important in determining the next output

int climbStairsOptimal(int n) {

    if(n <= 2) {
        return n;
    }

    int prev = 2, secondPrev = 1;

    for(int i = 3; i <= n; i++) {
        int curr = prev + secondPrev;
        secondPrev = prev;
        prev = curr;
    }

    return prev;

} // O(n) time and O(1) space most optimal solution

int main() {
    
    return 0;
}