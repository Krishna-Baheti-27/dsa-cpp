#include <bits/stdc++.h>
using namespace std;

// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete at most two transactions.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

/////////////////////////////////////////////////////////////////////////////////////

// by transactions here they mean that you if you buy and sell it counts as one transaction buy you cannot buy and buy you must sell before buying

// greedy cannot work here as we explore all possible transactions and select the best 2 and one transaction affects other and hence no greedy here

// the recurrence would be starting from index = 0 with buy = 1 we explore all possible combinations and not profit till only two transactions, each time we sell the stock it marks the end of a transaction

int maxProfitBruteHelper(int index, int n, int canBuy, int transac, vector<int> &prices) {

    if(transac >= 2) {
        return 0;
    }

    if(index == n) {
        return 0;
    }

    int profit = 0;

    if(canBuy == 1) {
        profit = max(-prices[index] + maxProfitBruteHelper(index + 1, n, 0, transac, prices), 0 + maxProfitBruteHelper(index + 1, n, 1, transac, prices));
    } else {
        profit = max(prices[index] + maxProfitBruteHelper(index + 1, n, 1, transac + 1, prices), 0 + maxProfitBruteHelper(index + 1, n, 0, transac, prices));
    }

    return profit;

} // O(2^n) time and O(n) recursion stack space

int maxProfitBrute(vector<int>& prices) {

    int n = prices.size();
    return maxProfitBruteHelper(0, n, 1, 0, prices);
}

/////////////////////////////////////////////////////////////////////////////////////////

int memoHelper(int index, int n, int canBuy, int transac, vector<int> &prices, vector<vector<vector<int>>> &dp) {

    if(transac == 2) {
        return 0;
    }

    if(index == n) {
        return 0;
    }

    if(dp[index][canBuy][transac] != -1) {
        return dp[index][canBuy][transac];
    }

    int profit = 0;

    if(canBuy == 1) {
        profit = max(-prices[index] + memoHelper(index + 1, n, 0, transac, prices, dp), 0 + memoHelper(index + 1, n, 1, transac, prices, dp));
    } else {
        profit = max(prices[index] + memoHelper(index + 1, n, 1, transac + 1, prices, dp), 0 + memoHelper(index + 1, n, 0, transac, prices, dp));
    }

    return dp[index][canBuy][transac] = profit;

}

int maxProfitMemo(vector<int> &prices) {

    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int>(2, -1)));

    return memoHelper(0, n, 1, 0, prices, dp);

} // O(N * 2 * 2) time and O(4N) + O(N) recursion stack space 

////////////////////////////////////////////////////////////////////////////////////

// we declare the dp of size n + 1 and for base case of index == n and transac can have 3 values 0, 1, 2 for base case of transac == 2

int maxProfitTab(vector<int> &prices) {

    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int>(3, 0)));

    // base cases written by default

    // now we just vary all parameters that is index, buy and transac and copy the recurrence

    for(int i = n - 1; i >= 0; i--) {
        for(int buy = 0; buy <= 1; buy++) {
            for(int transac = 0; transac < 2; transac++) {

                int profit = 0;

                if(buy == 1) {
                    profit = max(-prices[i] + dp[i + 1][0][transac], 0 + dp[i + 1][1][transac]);
                } else {
                    profit = max(prices[i] + dp[i + 1][1][transac + 1], 0 + dp[i + 1][0][transac]);
                }    

                dp[i][buy][transac] = profit;
            }
        }
    }

    return dp[0][1][0];

} // O(N * 2 * 2) time and O(N * 2 * 3) space

///////////////////////////////////////////////////////////////////////////////////

// we are only using 2 array those are for buy = 0, we trans = 0, 1, 2 and for buy = 1 we have transac = 0, 1 , 2 so we only need to arrays for size 3

// this can be simplified to only two variable which refer to transaction count in buy and not buy cases

int maxProfitOptimalIncorrect(vector<int> &prices) {

    int n = prices.size();
    vector<int> dpBuy(3, 0), dpSell(3, 0);

    for(int i = n - 1; i >= 0; i--) {

        for(int buy = 0; buy <= 1; buy++) {

            for(int transac = 0; transac < 2; transac++) {

                int profit = 0;

                if(buy == 1) {
                    profit = max(-prices[i] + dpSell[transac], 0 + dpBuy[transac]);
                    dpBuy[transac] = profit;
                } else {
                    profit = max(prices[i] + dpBuy[transac + 1], 0 + dpSell[transac]);
                    dpSell[transac] = profit;
                }
            }
        }
    }

    return dpBuy[0];

} // O(N * 2 * 2) time and O(1) space

// even though this code passed but there is a dependency error since we are overwriting dpSell when buy == 0 but when later buy == 1 we would need dpSell but we would have original value not updated value and hence you two sets or arrays that main dp and curr

// but if you go deep inside the math of it you would realise you are overwriting those cases which wont get give optimal answer instead profit = 0 and hence still works

//////////////////////////////////////////////////////////////////////////////////////

int maxProfitOptimalCorrect(vector<int> &prices) {

    int n = prices.size();
    
    vector<vector<int>> after(2, vector<int>(3, 0));

    for(int i = n - 1; i >= 0; i--) {

        vector<vector<int>> curr(2, vector<int>(3, 0));

        for(int buy = 0; buy <= 1; buy++) {

            for(int transac = 0; transac < 2; transac++) {

                int profit = 0;

                if(buy == 1) {
                    profit = max(-prices[i] + after[0][transac], 0 + after[1][transac]);
                    curr[buy][transac] = profit;
                } else {
                    profit = max(prices[i] + after[1][transac + 1], 0 + after[0][transac]);
                    curr[buy][transac] = profit;
                }
            }
        }

        after = curr;
    }

    return after[1][0];

} // O(N * 2 * 2) time and O(1) space

///////////////////////////////////////////////////////////////////////////////////

// another solution which works is write the transaction as B S B S and they have indices 0, 1, 2, 3, so if trans % 2 == 0 it is buy else sell and if trans == 4 return 0

// now using this approach write the recurrence, memo, tab and space optimised version



int main() {
    
    return 0;
}