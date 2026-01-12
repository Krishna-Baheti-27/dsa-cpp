#include<bits/stdc++.h>
using namespace std;

// A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the height of the ith step, and an integer k.

// To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference. The frog can jump from the ith step to any step in the range [i + 1, i + k], provided it exists.

// Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.

///////////////////////////////////////////////////////////////////////////////////

// so this question is exactly similar to last question except for the fact that instead of only two choices to jump that is i + 1 and i + 2 from i, here we have k possibilities starting from i + 1 to i + k and both inclusive

// so here also we try the same recursion solution of trying out all possible ways but using a for loop to check from i + 1 to i + k and taking the min as our answer and returning it

// here is the recurrence
// f(i) = for(int j = 1; j <= k; j++) {
    // min(f(i + j) + cost)
// }

int minCostHelper(int index, vector<int> &height, int k) {

    if(index == 0) {
        return 0;
    }

    int minCost = INT_MAX;

    for(int i = 1; i <= k; i++) {
        if(index - i >= 0) {
            minCost = min(minCost, minCostHelper(index - i, height, k) + abs(height[index] - height[index - i]));
        } else {
            break;
        }
    }

    return minCost;
}

int minCostBrute(vector<int> &height, int k) {

    return minCostHelper(height.size() - 1, height, k);

} // O(k^n) time but if k >= n then O(2^n) time and O(n) recursion stack space in the worst case since we will call the function atleast n times

///////////////////////////////////////////////////////////////////////////////////

int memoHelper(int index, vector<int> &height, vector<int> &dp, int k) {

    if(index == 0) {
        return 0;
    }

    if(dp[index] != -1) {
        return dp[index];
    }

    int minCost = INT_MAX;

    for(int i = 1; i <= k; i++) {
        if(index - i >= 0) {
            minCost = min(minCost, memoHelper(index - i, height, dp, k) + abs(height[index] - height[index - i]));
        } else {
            break;
        }
    }

    return dp[index] = minCost;

} // O(N * k) time and O(2N) space

int minCostMemo(vector<int> &height, int k) {

    vector<int> dp(height.size(), -1);
    return memoHelper(height.size() - 1, height, dp, k);
}


////////////////////////////////////////////////////////////////////////////////////

int minCostTab(vector<int> &height, int k) {

    int n = height.size();

    if(n == 1) { // no energy to jump from first stair to first stair
        return 0;
    }

    vector<int> dp(n);
    dp[0] = 0, dp[1] = abs(height[1] - height[0]);

    for(int i = 2; i < n; i++) {
       
        int minCost = INT_MAX;

        for(int j = 1; j <= k; j++) {
            if(i - j >= 0) {
                minCost = min(minCost, dp[i - j] + abs(height[i] - height[i - j]));
            } else {
                break;
            }
        }

        dp[i] = minCost;
    }

    return dp[n - 1];

} // O(N * K) time and O(N) space 

///////////////////////////////////////////////////////////////////////////////////////

// so here we can space optimise this but not like from O(N) to O(1) but from O(N) to O(k) since we need to remember previous k jumps at any point of time and hence we use dp array of size of k instead of n

// int minCostOptimal(vector<int> &height, int k) {

//     int n = height.size();

//     if(n == 1) {
//         return 0;
//     }

//     vector<int> dp(k, -1);
//     dp[0] = 0, dp[1] = abs(height[1] - height[0]);

//     for(int i = 2; i < n; i++) {

//         int minCost = INT_MAX;

//         for(int j = 1; j <= k; j++) {
//             if(i - j >= 0) {
//                 minCost = min(minCost, dp[i - j] + abs(height[i] - height[i - j]));
//             } else {
//                 break;
//             }
//         }

//         // change the state of the array so that we always remembee the last k values

//         dp.erase(dp.begin());
//         dp[i] = minCost;
//     }

//     return dp[n - 1];

// } // O(N * k) time and O(k) space (not really optimal if k == N)

/////////////////////////////////////////////////////////////////////////////////

// the most optimal solution does not work due to index out of bounds errors as when we have our current value and need to shift the values in dp to always have last k values then dp[i - j] will have index out of bounds error so instead use deque to allow insertion from both front and rear and similarly for deletion or each time time shift which will take O(k) time

int minCostOptimal(vector<int> &height, int k) {

    int n = height.size();

    if(n == 1) {
        return 0;
    }

    deque<int> dp;
    dp.push_back(0); // dp[0] = 0
    dp.push_back(abs(height[1] - height[0])); // dp[1] = abs(height[1] - height[0])

    for(int i = 2; i < n; i++) {

        int minCost = INT_MAX;

        for(int j = 1; j <= k; j++) {
            if(i - j >= 0) {
                minCost = min(minCost, dp[dp.size() - j] + abs(height[i] - height[i - j]));
            } else {
                break;
            }
        }

        // change the state of the array so that we always remembee the last k values

        dp.push_back(minCost); // same as dp[i] = minCost

        // if the window is full then remove the first element since we always have to maintain last k values

        if(dp.size() > k) {
            dp.pop_front(); 
        }
    }

    return dp.back(); // return the last value, same as dp[n - 1]

} // O(N * k) time and O(k) space (not really optimal if k == N)

// and hence the most optimal solution isnt really optimal since we just fall back to O(N) (if k == N) in worst case and hence not optimal

int main() {
    
    return 0;
}