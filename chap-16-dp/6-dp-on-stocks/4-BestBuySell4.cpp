#include <bits/stdc++.h>
using namespace std;

// You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

// Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

//////////////////////////////////////////////////////////////////////////////////

// same as part three but here we are allowed atmost k transaction so just change accordingly


int maxProfitOptimalCorrect(int k, vector<int> &prices) {

    int n = prices.size();
    
    vector<vector<int>> after(2, vector<int>(k + 1, 0));

    for(int i = n - 1; i >= 0; i--) {

        vector<vector<int>> curr(2, vector<int>(k + 1, 0));

        for(int buy = 0; buy <= 1; buy++) {

            for(int transac = 0; transac < k; transac++) {

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

} // O(N * 2 * k) time and O(2 * k) space

///////////////////////////////////////////////////////////////////////////////////////

// this incorrect code also works because

// Mathematically, the "Clean" logic says:"If I buy on Day i, the next thing I can do is sell on Day i+1."Your "Buggy" logic says:"If I buy on Day i, the next thing I can do is sell on Day i (immediately)."

// Let's check the math of that extra choice: Profit} = ({Sell Price at } i) - ({Buy Price at } i) = 0. However, this action consumes 1 transaction count (k).So, the algorithm compares two options:The Real Path: Buy now, wait for a higher price later. (Positive profit, costs 1 k)The Bug Path: Buy now, sell immediately. (0 profit, costs 1 k)The max() function will always look at Option 2, realize it is a waste of a transaction for zero gain, and ignore it (unless doing nothing is also 0, in which case it doesn't matter).

int maxProfit(int k, vector<int>& prices) {
         int n = prices.size();
    vector<int> dpBuy(k + 1, 0), dpSell(k + 1, 0);

    for(int i = n - 1; i >= 0; i--) { 

        for(int buy = 0; buy <= 1; buy++) {

            for(int transac = 0; transac < k; transac++) {

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
    }



int main() {
    
    return 0;
}