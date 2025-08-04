#include<bits/stdc++.h>
using namespace std;

int maxProfitBrute(vector<int> &arr) { // O(N^2) brute force solution
    int maxProfit = 0;
    for(int i = 0; i < arr.size() - 1; i++) {
       int buyingAt = arr[i];
       int sellingAt = arr[i + 1]; // we will try to buy from next level till we get best price
       for(int j = i + 2; j < arr.size(); j++) {
            sellingAt = max(sellingAt, arr[j]);
       }
       int profit = sellingAt - buyingAt;
       maxProfit = max(profit, maxProfit);
    }
    return maxProfit;
}

int maxProfitBrute2(const vector<int> &arr) {
    int maxProfit = 0;
    for(int i = 0; i < arr.size() - 1; i++) {
        // we calculate profit if we were to buy at ith day, and sell for each j = i + 1 to arr.size() and compute max
        for(int j = i + 1; j < arr.size(); j++) {
            int profit = arr[j] - arr[i];
            maxProfit = max(profit, maxProfit);
        }
    }
    return maxProfit;
}

int maxProfitOptimal(vector<int> &arr) {
    int maxProfit = 0, profit = 0, minPrice = arr[0];
    // we assume first day has minPrice and start looking from second day (i = 1 till last day)
    for(int i = 1; i < arr.size(); i++) {
         minPrice = min(arr[i], minPrice); // it can also be the last statement after computing maxProfit, order doesnt really matter
         // its more intuitive to calculate minPrice first
        //  I update the minimum price so far before calculating profit, because I want to know what’s the best price I could have bought at before selling today. This makes it intuitive: I’m always comparing today’s price to the lowest price so far, and updating my maximum profit accordingly. The order doesn’t affect correctness, but this way matches how you’d actually make the decision in real life
        profit = arr[i] - minPrice;
        maxProfit = max(profit, maxProfit);
    }
    return maxProfit;
}

// Using Kadane algo
int maxProfit(vector<int>& prices) {
    if (prices.size() < 2) return 0;
    int maxCurrent = 0, maxSoFar = 0;
    for (int i = 1; i < prices.size(); i++) {
        int diff = prices[i] - prices[i-1]; // this is our subarray
        maxCurrent = max(diff, maxCurrent + diff); // we deicde whether to extend subarray or start new one, current subArray
        maxSoFar = max(maxSoFar, maxCurrent); // max sum sub arrays obtained so far
    }
    return maxSoFar;
}
//     Are all subarrays single elements?
// No. Kadane’s Algorithm considers all possible contiguous subarrays, not just single elements.

// For example, if diff = [2, -1, 3], the subarray [2, -1, 3] sums to 4, which is the profit from buying at the start and selling at the end of that period. (3-(-1)) = 4

// The maximum sum subarray may span multiple days, not just one.

// I treat each day’s profit as the difference between today’s and yesterday’s price, then use Kadane’s Algorithm to find the maximum sum subarray of these differences. This gives the maximum possible profit from a single buy-sell transaction in O(n) time and O(1) space.


// best solution
int maxProfitOptimal2(const vector<int> &arr) {
    int maxProfit = 0, minPrice = arr[0];
    // we will consider each day as a buying day and try to calculate profit by selling at best possible day encountered yet, and buying at least possible
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] < minPrice) minPrice = arr[i];
        maxProfit = max(maxProfit, arr[i] - minPrice);
    }
    return maxProfit;
}

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    cout << maxProfitBrute(arr) << endl;
    cout << maxProfitOptimal(arr) << endl;
    return 0;
}