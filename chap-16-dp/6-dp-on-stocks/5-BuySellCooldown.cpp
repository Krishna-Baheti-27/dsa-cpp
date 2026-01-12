#include <bits/stdc++.h>
using namespace std;

// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

// After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

////////////////////////////////////////////////////////////////////////////////////

// here we can have any number of transactions but we have to maitain a cooldown once we sell a stock we cannot buy the next day (skip it)

// again greedy wont work here because locally making the optimal choice doesnt consider about future outcomes

// instead we explore all possible ways, for each stock we can sell or skip (if previously buyied) or we can buy if no cooldown or skip, so we maintain a cooldown variable with us for this, so 3-d dp again with index, canBuy and cooldown

int maxProfitBruteHelper(int index, int n, int canBuy, vector<int> &prices) {
    
    if(index == n) {
        return 0;
    }

    int profit = 0;

    if(canBuy == 1) {
       profit = max(-prices[index] + maxProfitBruteHelper(index + 1, n, 0, prices), 0 + maxProfitBruteHelper(index + 1, n, 1, prices));
    } else if(canBuy == 2) {
        profit = maxProfitBruteHelper(index + 1, n, 1, prices);
    } else {
        profit = max(prices[index] + maxProfitBruteHelper(index + 1, n, 2, prices), 0 + maxProfitBruteHelper(index + 1, n, 0, prices));
    }

    return profit;

} // O(2^n) time in worst case and O(n) recursion stack space

int maxProfitBrute(vector<int>& prices) {
    
    int n = prices.size();
    return maxProfitBruteHelper(0, n, 1, prices);
}

/////////////////////////////////////////////////////////////////////////////////////

int memoHelper(int index, int n, int canBuy, vector<int> &prices, vector<vector<int>> &dp) {

    if(index == n) {
        return 0;
    }

    if(dp[index][canBuy] != -1) {
        return dp[index][canBuy];
    }

    int profit = 0;

    if(canBuy == 1) {
       profit = max(-prices[index] + memoHelper(index + 1, n, 0, prices, dp), 0 + memoHelper(index + 1, n, 1, prices, dp));
    } else if(canBuy == 2) {
        profit = memoHelper(index + 1, n, 1, prices, dp);
    } else {
        profit = max(prices[index] + memoHelper(index + 1, n, 2, prices, dp), 0 + memoHelper(index + 1, n, 0, prices, dp));
    }

    return dp[index][canBuy] = profit;
}

int maxProfitMemo(vector<int> &prices) {

    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(3, -1));

    return memoHelper(0, n, 1, prices, dp);

} // O(n * 3) time and space and O(n) recursion stack space

////////////////////////////////////////////////////////////////////////////////////////

// again single base case of index == n so declare dp array of n + 1

int maxProfitTab(vector<int> &prices) {
    
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(3));

    // base case by default initialised to 0

    // now vary all parameters and copy the recurrence

    for(int i = n - 1; i >= 0; i--) {

        for(int buy = 0; buy <= 2; buy++) {

            int profit = 0;

            if(buy == 0) {
                profit = max(prices[i] + dp[i + 1][2], 0 + dp[i + 1][0]);
            } else if(buy == 1) {
                profit = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
            } else {
                profit = 0 + dp[i + 1][1];
            }

            dp[i][buy] = profit;
        }
    }

    return dp[0][1];

} // O(n * 3) time and space

/////////////////////////////////////////////////////////////////////////////////////

int maxProfitOptimal(vector<int> &prices) {

    int n = prices.size();
    int prevBuy = 0, prevSell = 0, prevCool = 0;

    // base case by default initialised to 0

    // now vary all parameters and copy the recurrence

    for(int i = n - 1; i >= 0; i--) {

        int currBuy = 0, currSell = 0, currCool = 0;

        for(int buy = 0; buy <= 2; buy++) {

            if(buy == 0) {
                currSell = max(prices[i] + prevCool, 0 + prevSell);
            } else if(buy == 1) {
                currBuy= max(-prices[i] + prevSell, 0 + prevBuy);
            } else {
                currCool = 0 + prevBuy;
            }
        }

        prevBuy = currBuy;
        prevSell = currSell;
        prevCool = currCool;
    }

    return prevBuy;

} // O(n * 3) time and O(1) space

int main() {
    
    return 0;
}