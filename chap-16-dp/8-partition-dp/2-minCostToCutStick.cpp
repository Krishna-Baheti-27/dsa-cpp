#include <bits/stdc++.h>
using namespace std;

// Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

// You should perform the cuts in order, you can change the order of the cuts as you wish.

// The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

// Return the minimum total cost of the cuts.

////////////////////////////////////////////////////////////////////////////////////////

// in partition dp use this trick where do i put my final cut to solve the problem, that is k and we vary it from i to j

int minCostBruteHelper(int i, int j, vector<int> &cuts) {

    if(i >= j) {
        return 0;
    }

    int minCost = INT_MAX;

    for(int k = i; k < j; k++) {
        minCost = min(minCost, cuts[j] - cuts[i] + minCostBruteHelper(i, k, cuts) + minCostBruteHelper(k + 1, j, cuts));
    }

    return minCost;
}

int minCost(int n, vector<int> &cuts) {

    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);

    sort(cuts.begin(), cuts.end());

    return minCostBruteHelper(1, cuts.size() - 1, cuts);
}

////////////////////////////////////////////////////////////////////////////////////

int memoHelper(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {

    if(i >= j) {
        return 0;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int minCost = INT_MAX;

    for(int k = i; k < j; k++) {
        minCost = min(minCost, cuts[j] - cuts[i - 1] + memoHelper(i, k, cuts, dp) + memoHelper(k + 1, j, cuts, dp));
    }

    return minCost;
}

int minCostMemo(int n, vector<int> &cuts) {

    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);

    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(n, vector<int>(n, -1));

    return memoHelper(1, cuts.size() - 1, cuts, dp);
}

int main() {
    
    return 0;
}