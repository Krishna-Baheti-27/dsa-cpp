#include<bits/stdc++.h>
using namespace std;

// we have to return the max possible sum subsequence keeping in mind that we cant pick adjacent array elements

// like if we decided we will pick the ith index then we cant pick i + 1 and will have to pick from i + 2 to n and hence greedy doesnt work here as we will have to try all possible combinations

////////////////////////////////////////////////////////////////////////////////////////

// so the first solution that comes is to try all possible subsequences obeying this constraint of non adjacency and then return the max amongst them

// so the recurrence would be
// f(index) = if pick then go to index + 2 since we dont want adjacent
// if not pick then go to index + 1 and out of all possible subsequences thus formed return one having maxSumm when index goes out of bounds

// this solution is backtracking style and not standard dp style and is how we solved combination sum problem to obtain max possible sum subsequence or combination from array

int maxSumHelperBack(int index, vector<int> &arr, int sum) {

    if(index >= arr.size()) {
        return sum;
    }

    // pick case
    sum += arr[index];
    int prev2 = maxSumHelperBack(index + 2, arr, sum);
    sum -= arr[index]; // backtrack and decrease the sum to account for not pick case

    // not pick case
    int prev = maxSumHelperBack(index + 1, arr, sum);
    
    return max(prev2, prev);
} 

int maxSumBruteBack(vector<int> &arr) {
    return maxSumHelperBack(0, arr, 0);
}

//////////////////////////////////////////////////////////////////////////////////////

// so lets a write it in standard dp style without using the sum as a parameter and now lets (write from last to first instead of instead of index == 0 to n - 1)

// the backtracking solution cannot be optimised to dp later as it has two different states of function (due to two paramters) and hence we dont have overlapping subproblems because the second state of sum is accumulator and always increases (since all array elements are positive) and cannot be bounded, but if it were to be bounded in a target (using either target - arr[index] which is pick case or simply target not pick case) then it can be optimised using dp

int maxSumHelperDp(int index, vector<int> &arr) {

    // we reached index 0, so pick it

    if(index == 0) {
        return arr[0];
    }

    // we reached a negative index which means we physically cant pick anything and hence return 0

    if(index < 0) {
        return 0; 
    }

    // if we pick index, then we cant pick index - 1 and hence go for index - 2

    int prev2 = arr[index] + maxSumHelperDp(index - 2, arr);

    // if we dont pick index, then we can surely pick index - 1

    int prev = 0 + maxSumHelperDp(index - 1, arr);

    // and finally we now consider max of these two cases

    return max(prev2, prev);

} // O(2^n) time and O(N) recursion stack space

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

    int prev2 = arr[index] + memoHelper(index - 2, arr, dp);
    int prev = 0 + memoHelper(index - 1, arr, dp);

    return dp[index] = max(prev2, prev);

} // O(N) time and O(2N) space

int maxSumMemo(vector<int> &arr) {
    vector<int> dp(arr.size(), -1);
    return memoHelper(arr.size() - 1, arr, dp);
}

//////////////////////////////////////////////////////////////////////////////////////

// so here dp[i] signifies the max sum subsequence of non adjacent elements in the range [0..i]

int maxSumTab(vector<int> &arr) {

    int n = arr.size();

    // the only subsequences are {} and {arr[0]} and hence return the max

    if(n == 1) {
        return arr[0]; 
    }

    vector<int> dp(arr.size());

    dp[0] = arr[0], dp[1] = max(arr[0], arr[1]); // necessary to use max

    for(int i = 2; i < n; i++) {
        int prev2 = arr[i] + dp[i - 2];
        int prev = 0 + dp[i - 1];
        dp[i] = max(prev2, prev);
    }
    
    return dp[n - 1]; // the max subsequence accross entire array or all the houses

} // O(N) time and O(N) space

/////////////////////////////////////////////////////////////////////////////////////

// so here prev signifies the max sum we can get for any non adjacent subsequence in the range [0..i]

int maxSumOptimal(vector<int> &arr) {

    int n = arr.size();

    if(n == 1) {
        return arr[0];
    }

    int prev2 = arr[0], prev = max(arr[0], arr[1]);

    // the max is necessary because dp[i] (or prev) must store the best possible result for the range 0 to i, whether that involves picking the element at i or skipping it, hence we use max.

    for(int i = 2; i < n; i++) {
        
        int curr = max(arr[i] + prev2, 0 + prev);
        prev2 = prev;
        prev = curr;
        
        // we do this to mov the timeline forward that is initiallt curr at i and prev at i - 1 and prev2 at i - 2, so when we change i that is i + 1 then i - 2 becomes i - 1 and hence its value must be equal to current i - 1 and similarly i - 1 becomes i and hecne it current value must be equal to i
    }

    return prev;

}  // O(N) time and O(N) space

int main() {
    
    return 0;
}