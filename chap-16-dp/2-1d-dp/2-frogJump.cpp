#include<bits/stdc++.h>
using namespace std;

// the given array height represents the heights of n stairs, where frog starts from 0th stair (or first stair) to (n - 1)th stair (or last stair) and the cost to jump from stairs is the absolute difference in the height of stairs where height[i] represents the height of ith stair

// we have to minimise the total cost to reach from first to last stair keeping in mind the from ith stair, from can only jump to (i + 1)th or (i + 2)th stair

///////////////////////////////////////////////////////////////////////////////////////

// now here it is a dp problem since we have to find min among all possible ways so write recurrence relation and convert it to dp solution

// why does greedy solution does not work, there are multiple test cases to check why taking the currently best available option isnt the optimal solution instead we have to try all possible ways and return the most efficient amongst them

// given 
// 1 ≤ height.size() ≤ 10^5
// 0 ≤ height[i] ≤ 104

// the 2 ways to reach to i is from i - 1 and i - 2, then simply we have to choose the min amongst them and add that to our cost

// so to write any recurrence use this technique
// 1) Try to represent the problem in terms of index
// 2) Do all possible stuffs on that index according to problem statement
// 3) Sum of all stuffs => count all ways which are possible 
//  Min or max of all stuffs => find min or max


int minCostBruteHelper(int index, vector<int> &height) {

    if(index == 0) {
        return 0;
    }

    int leftCost = minCostBruteHelper(index - 1, height) + abs(height[index] - height[index - 1]);
    int rightCost = INT_MAX;
    if(index > 1) {
        rightCost = minCostBruteHelper(index - 2, height) + abs(height[index] - height[index - 2]);
    }

    return min(leftCost, rightCost);   
}

int minCostBrute(vector<int> &height) {
    return minCostBruteHelper(height.size() - 1, height);
}

////////////////////////////////////////////////////////////////////////////////////////

// when we draw the recursion tree of above problem we see overlapping subproblems and hence we can apply memoization, which is top-bottom or we start from the back

int memoHelper(int index, vector<int> &height, vector<int> &dp) {

    if(index == 0) {
        return 0;
    }

    if(dp[index] != -1) {
        return dp[index];
    }

    int leftCost = memoHelper(index - 1, height, dp) + abs(height[index] - height[index - 1]);
    int rightCost = INT_MAX;

    if(index > 1) {
        rightCost = memoHelper(index - 2, height, dp) + abs(height[index] - height[index - 2]);
    }

    return dp[index] = min(leftCost, rightCost); 

} // O(N) time and O(2N) space

int minCostMemo(vector<int> &height) {
    vector<int> dp(height.size(), -1);
    return memoHelper(height.size() - 1, height, dp);
}

////////////////////////////////////////////////////////////////////////////////////////

// this is bottom up or we start from the very bottom and work our way towards the answer

int minCostTab(vector<int> &height) {

    int n = height.size();

    if(n == 1) {
        return 0;
    }
    
    vector<int> dp(height.size());
    dp[0] = 0, dp[1] = abs(height[1] - height[0]);

    for(int i = 2; i < n; i++) {

        int leftCost = dp[i - 1] + abs(height[i] - height[i - 1]);
        int rightCost = dp[i - 2] + abs(height[i] - height[i - 2]);

        dp[i] = min(leftCost, rightCost);
    }

    return dp[n - 1];

} // O(N) time and O(N) space

//////////////////////////////////////////////////////////////////////////////////////

// we remove the extra space from our solution by checking whats redunant in tabulation

int minCostOptimal(vector<int> &height) {

    int n = height.size();

    if(n == 1) {
        return 0;
    }

    int prev = abs(height[1] - height[0]), secondPrev = 0;

    for(int i = 2; i < n; i++) {

        int leftCost = prev + abs(height[i] - height[i - 1]);
        int rightCost = secondPrev + abs(height[i] - height[i - 2]);

        int curr = min(leftCost, rightCost);
        secondPrev = prev;
        prev = curr;

    }

    return prev; // since current would be out of bounds but prev would be holding true value of curr

} // O(N) time and O(1) space, truly optimal solution

int main() {
    
    return 0;
}