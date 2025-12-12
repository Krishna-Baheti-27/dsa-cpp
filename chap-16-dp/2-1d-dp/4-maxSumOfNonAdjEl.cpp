#include<bits/stdc++.h>
using namespace std;

// we have to return the max possible sum subsequence keeping in mind that we cant pick adjacent array elements

////////////////////////////////////////////////////////////////////////////////////////

// so the first solution that comes is to try all possible subsequences obeying this constraint of non adjacency and then return the max amongst them

// so the recurrence would be
// f(index) = if pick then go to index + 2 since we dont want adjacent
// if not pick then go to index + 1 and out of all possible subsequences thus formed return one having maxSumm when index goes out of bounds

// this solution is backtracking style and not standard dp style 

int maxSumHelperBack(int index, vector<int> &arr, int sum) {

    if(index >= arr.size()) {
        return sum;
    }

    // pick case
    sum += arr[index];
    int pickSum = maxSumHelperBack(index + 2, arr, sum);
    sum -= arr[index]; // backtrack and decrease the sum to account for not pick case

    // not pick case
    int notPickSum = maxSumHelperBack(index + 1, arr, sum);
    
    return max(pickSum, notPickSum);
} 

int maxSumBruteBack(vector<int> &arr) {
    return maxSumHelperBack(0, arr, 0);
}

//////////////////////////////////////////////////////////////////////////////////////

// so lets a write it in standard dp style without using the sum as a parameter and now lets (write from last to first instead of instead of index == 0 to n - 1)

// the backtracking solution cannot be optimised to dp later as it has two different states of function (due to two paramters) and hence we dont have overlapping subproblems because the second state of sum is accumulator and always increases and cannot be bounded, but if it were to be bounded in a target (using either target - arr[index] which is pick case or simply target not pick case) then it can be optimised using dp

int maxSumHelperDp(int index, vector<int> &arr) {

    if(index == 0) {
        return arr[0];
    }
    if(index < 0) {
        return 0;
    }

    int pickSum = arr[index] + maxSumHelperDp(index - 2, arr);
    int notPickSum = 0 + maxSumHelperDp(index - 1, arr);

    return max(pickSum, notPickSum);
}

int maxSumBruteDp(vector<int> &arr) {
    return maxSumHelperDp(arr.size() - 1, arr);
}

/////////////////////////////////////////////////////////////////////////////////////

// now lets apply memoization to this top-bottom problem as we have a lot of overlapping subproblems which can be memoised so that we can avoid repeated function calls

// so here f(i) signifies the max sum subsequence of non adjacnet elements in the range [0..i]

int memoHelper(int index, vector<int> &arr, vector<int> &dp) {

    if(index == 0) {
        return arr[0];
    }
    if(index < 0) {
        return 0;
    }

    if(dp[index] != -1) {
        return dp[index];
    }

    int pickSum = arr[index] + memoHelper(index - 2, arr, dp);
    int notPickSum = 0 + memoHelper(index - 1, arr, dp);

    return dp[index] = max(pickSum, notPickSum);

} // O(N) time and O(2N) space

int maxSumMemo(vector<int> &arr) {
    vector<int> dp(arr.size(), -1);
    return memoHelper(arr.size() - 1, arr, dp);
}

//////////////////////////////////////////////////////////////////////////////////////

// so here dp[i] signifies the max sum subsequence of non adjacnet elements in the range [0..i]

int maxSumTab(vector<int> &arr) {

    int n = arr.size();

    if(n == 1) {
        return arr[0];
    }

    vector<int> dp(arr.size());
    dp[0] = arr[0], dp[1] = max(arr[0], arr[1]); // necessary to use max

    for(int i = 2; i < n; i++) {
        int pickSum = arr[i] + dp[i - 2];
        int notPickSum = 0 + dp[i - 1];
        dp[i] = max(pickSum, notPickSum);
    }
    
    return dp[n - 1];

} // O(N) time and O(N) space

/////////////////////////////////////////////////////////////////////////////////////

// so here prev signifies the max sum we can get for any non adjacent subsequence in the range [0..i]

int maxSumOptimal(vector<int> &arr) {

    int n = arr.size();

    if(n == 1) {
        return arr[0];
    }

    int pickSum = arr[0], notPickSum = max(arr[0], arr[1]);

    // the max is necessary because dp[i] (or prev) must store the best possible result for the range 0 to i, whether that involves picking the element at i or skipping it, hence we use max.

    // pickSum is prev2 or secondPrev and notPickSum is prev 

    for(int i = 2; i < n; i++) {
        int curr = max(arr[i] + pickSum, 0 + notPickSum);

        // we do this to mov the timeline forward that is initiallt curr at i and notPickSum at i - 1 and pickSum at i - 2, so when we change i that is i + 1 then i - 2 becomes i - 1 and hence its value must be equal to current i - 1 and similarly i - 1 becomes i and hecne it current value must be equal to i

        pickSum = notPickSum;
        notPickSum = curr;
    }

    return notPickSum;

}  // O(N) time and O(N) space

int main() {
    
    return 0;
}