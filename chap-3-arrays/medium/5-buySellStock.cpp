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
    // we try to find minPrice so far and try to sell at each day with profit of arr[i] - minPrice becuase we bought at minPrice and once thats done we compare it with maxProfit
    for(int i = 1; i < arr.size(); i++) {
        minPrice = min(arr[i], minPrice); 
        profit = arr[i] - minPrice;
        maxProfit = max(profit, maxProfit);
    }
    return maxProfit;
}

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    cout << maxProfitBrute(arr) << endl;
    cout << maxProfitOptimal(arr) << endl;
    return 0;
}