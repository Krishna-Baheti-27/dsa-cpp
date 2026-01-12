#include <bits/stdc++.h>
using namespace std;

// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

////////////////////////////////////////////////////////////////////////////////////

// you cannot sell before buying the stock

// you are allowed to buy and sell only once

// if you are going to sell the stock on the ith day then you are going to buy it on the min price from 1st to (i - 1)th day 

// and this way we will try and check for every day (buy for every day) and thus return the max difference obtained (profit)

int maxProfit(vector<int> &arr) {

    int maxProfit = INT_MIN;
    int minPrice = INT_MAX;

    for(int i = 0; i < arr.size(); i++) {
        minPrice = min(minPrice, arr[i]);
        maxProfit = max(maxProfit, arr[i] - minPrice);
    }

    return maxProfit;

} // O(n) time and O(1) space

// now why is this dp, it is dp because dp is associated with remembering the past and here we are essentially remembering the min price obtained thus far to maximise our profit

int main() {
    
    return 0;
}