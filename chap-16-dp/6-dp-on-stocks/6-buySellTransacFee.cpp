#include <bits/stdc++.h>
using namespace std;

// You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

// Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

// You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
// The transaction fee is only charged once for each stock purchase and sale.

/////////////////////////////////////////////////////////////////////////////////////

// here clearly greedy solution would work because we being charged a constant fee for each transaction no matter how much profit we make and hence we would greedily try to do min transactions possible which generate max profit (instead of doing a lot of them) and in this way we would require less fee and hence more profit

int maxProfitGreedy(vector<int>& prices, int fee) {
    
    int n = prices.size();


}

////////////////////////////////////////////////////////////////////////////////////

// now dp

int maxProfitBrute(vector<int> &prices, int fee) {

}

int main() {
    
    return 0;
}