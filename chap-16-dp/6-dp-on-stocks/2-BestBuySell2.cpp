#include <bits/stdc++.h>
using namespace std;

// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.

// Find and return the maximum profit you can achieve.

////////////////////////////////////////////////////////////////////////////////////

// the major difference is that we can buy and sell multiple times but only hold atmost one stock at a time (not more than one) and now we have to maximise the profit and we can also buy and sell multiple times on the same day that is i sell today my holded share and then buy today only

// check this example to get clear view

// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Total profit is 4 + 3 = 7.

/////////////////////////////////////////////////////////////////////////////////////

// lets see why greedy solution works here, we want to maximise the profit and only real way to increase is to buy on less price and sell for greater, but here we are allowed to do it multiple times and so the maximum way to do this (amongst a lot of ways when use recursion) is to buy if for the next day we have higher price and add that to profit and again do this same thing so buy and sell and then repeat across all adjacent array pairs

int maxProfitGreedy(vector<int>& prices) {

    int maxProfit = 0;

    for(int i = 0; i < prices.size() - 1; i++) {
        if(prices[i + 1] > prices[i]) {
            maxProfit += prices[i + 1] - prices[i];
        }
    }

    return maxProfit;

} // O(N) time and O(1) space

// the above greedy works because
// Take ex :- [1,4,7,8,6,4]
// if you take (1, 8) , diff = 7
// or if you take (1, 4), (4, 7), (7, 8), diff = 3 + 3 + 1 = 7

// Going directly to 8, or going to 8 by adding all differences in between is same in result, so rather than thinking to jump, think it in this way.

// hence both dp and greedy produce optimal result here

///////////////////////////////////////////////////////////////////////////////////

// as we can see we have a lot of ways or a lot of buy sell patterns so we try all possible ways and then choose the most optimal way

// so the recurrence would be for each stock we have two options that are buy or sell but you must buy before we sell

// so for each stock from 0 to n - 1 we go f(i, buy) so buy signal means we have bought this and for the next index we have option to sell it or simply move to next index without selling and if you havent sold you cant buy new stock

// sp we have canBuy flag with us, canBuy = true means buy or skip
// canBuy = false means sell or skip

int maxProfitBruteHelper(int index, bool canBuy, int n, vector<int> &prices) {

    // when we are exhausted with days which means no more buying or selling and hence return 0

    if(index == n) {
        return 0;
    }

    int profit = 0;

    if(canBuy) {
        profit = max(-prices[index] + maxProfitBruteHelper(index + 1, !canBuy, n, prices), 0 + maxProfitBruteHelper(index + 1, canBuy, n, prices));
    } else {
        profit = max(prices[index] + maxProfitBruteHelper(index + 1, !canBuy, n, prices), 0 + maxProfitBruteHelper(index + 1, canBuy, n, prices));
    }

    return profit;
}

int maxProfitBrute(vector<int> &prices) {
    
    int n = prices.size();
    return maxProfitBruteHelper(0, true, n, prices);

} // O(2^n) time since for each stock we have two options (buy/skip or sell/skip) and O(n) recursion stack space

///////////////////////////////////////////////////////////////////////////////////

int memoHelper(int index, int canBuy, int n, vector<int> &prices, vector<vector<int>> &dp) {

    if(index == n) {
        return 0;
    }

    if(dp[index][canBuy] != -1) {
        return dp[index][canBuy];
    }

    int profit = 0;

    if(canBuy == 1) {
        profit = max(-prices[index] + memoHelper(index + 1, 0, n, prices, dp), 0 + memoHelper(index + 1, 1, n, prices, dp));
    } else {
        profit = max(prices[index] + memoHelper(index + 1, 1, n, prices, dp), 0 + memoHelper(index + 1, 0, n, prices, dp));
    }

    return dp[index][canBuy] = profit;
}

int maxProfitMemo(vector<int> &prices) {
    
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));

    return memoHelper(0, 1, n, prices, dp);

} // O(2 * N) time and O(2N) + O(N) recursion stack space 

/////////////////////////////////////////////////////////////////////////////////////

int maxProfitTab(vector<int> &prices) {

    // here again when writing base case our base case is index == n and hence we declare the dp of size of n + 1

    // here dp[i][buy] represents the max profit i can make starting from i with the state of buy = buy to the end

    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    // base case by default initialised to 0 which is dp[n][0] = dp[n][1] = 0;
    // since for index == n whatever be the buy it will be 0

    // dp[n][0] = dp[n][1] = 0; 

    // now write changing parameters (index and buy and then copy the recurrence)

    for(int i = n - 1; i >= 0; i--) {

        for(int buy = 0; buy <= 1; buy++) {
            
            int profit = 0;

            if(buy == 1) {
                profit = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
            } else {
                profit = max(prices[i] + dp[i + 1][1], 0 + dp[i + 1][0]);
            }

            dp[i][buy] = profit;
        }
    }

    return dp[0][1]; // since on day 0 we can buy hence buy == 1 and not 0

} // O(2N) time and space

//////////////////////////////////////////////////////////////////////////////////////

// here we are only using dp[i + 1][0] and dp[i + 1][1] what it means is we are only dependent on the previous day and hence can use two varibles in place of an entire array

int maxProfitOptimal(vector<int> &prices) {

    int n = prices.size();
    int prevBuy = 0, prevSell = 0;

    for(int i = n - 1; i >= 0; i--) {
        for(int buy = 0; buy <= 1; buy++) {

            int profit = 0;

            if(buy == 1) {
                profit = max(-prices[i] + prevSell, 0 + prevBuy);
                prevBuy = profit;
            } else {
                profit = max(prices[i] + prevBuy, 0 + prevSell);
                prevSell = profit;
            }
        }
    }

    return prevBuy;

} // O(2 * N) time and O(1) space 

int main() {
    
    return 0;
}