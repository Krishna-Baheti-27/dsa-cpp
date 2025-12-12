#include<bits/stdc++.h>
using namespace std;

// subset or subsequence is a contiguous or non contiguous portion of the array which follows the order

// we are given an array and we have to return true if there exists a subset or subsequence whose elements add up to given target

//////////////////////////////////////////////////////////////////////////////////////////

// this can also be done using power set algo (bit manipulation) but we dont need to generate all subsets hence go with recursion

// so first idea that comes to mind is to generate all the subsequences, but here we have to just tell whether there is atleast one valid subsequence or not so as soon as we get our answer we just return true early and hence we dont need to generate all the subsequences, neverthless we will have to apply recursion

// so what is the recurrence

// f(index, target) => return true if there is a subsequence from [0..index] that adds up to target or false otherwise

// so for a particular element we always the choice whether to take it or not (pick / not pick)

bool subsetSumKBruteHelper(int index, int target, vector<int> &arr) {

    // check this first very important for arr = [5] and target = 5, but this works because we only have to tell whether there is a subset of sum k or not, but it does not explore all the subsets and fails especially when we have arr[i] == 0 (not only positives but 0 also)
    // a more standard base case would be

    // if(index == arr.size()) {
    //     return target == 0 ? 1 : 0;
    // }

    if(target == 0) {
        return true;
    }

    if(index >= arr.size()) {
        return false;
    }

    // pick case

    if(target >= arr[index]) {
        int ifPick = subsetSumKBruteHelper(index + 1, target - arr[index], arr);
        if(ifPick == true) {
            return true;
        }
    }

    // not pick case

    int ifNotPick = subsetSumKBruteHelper(index + 1, target, arr);
    if(ifNotPick == true) {
        return true;
    }

    return false;

} // O(2^n) time and O(n) recursin stack space

bool subsetSumKBrute(vector<int> &arr, int target) {
    return subsetSumKBruteHelper(0, target, arr);
}

///////////////////////////////////////////////////////////////////////////////////////////

// now lets memoize this solution as we have a lot of overlapping subproblems since we always shrink or keep the target same which keeps it bounded in the range and hence we can apply memoization

// bool memoHelper(int index, vector<int> &arr, int target, vector<vector<bool>> &dp) {

//     if(target == 0) {
//         return true;
//     }

//     if(index >= arr.size()) {
//         return false;
//     }

//     if(dp[index][target] == true) {
//         return true;
//     }

//     if(target >= arr[index]) {
//         int ifPick = memoHelper(index + 1, arr, target - arr[index], dp);
//         if(ifPick == true) {
//             return dp[index][target] = true;
//         }
//     }

//     int ifNotPick = memoHelper(index + 1, arr, target, dp);
//     if(ifNotPick == true) {
//         return dp[index][target] = true;
//     }

//     return dp[index][target] = false;

// } // O(n * target) time and O(n * target + n) space

// bool subsetSumKMemo(vector<int> &arr, int target) {
//     vector<vector<bool>> dp(arr.size(), vector<bool>(target + 1, false));
//     return memoHelper(0, arr, target, dp);
// }

// but there is a bug in this code
// Unvisited: We haven't checked this yet.
// Visited (True): We checked this, and yes, it leads to a solution.
// Visited (False): We checked this, and no, it leads to a dead end.

// so to handle this we have to create three states
// -1: Unvisited
// 0: False
// 1: True

bool memoHelper(int index, vector<int> &arr, int target, vector<vector<int>> &dp) {

    if(target == 0) {
        return true;
    }

    if(index >= arr.size()) {
        return false;
    }

    if(dp[index][target] == 1) {
        return true;
    } 

    if(dp[index][target] == 0) {
        return false;
    }

    if(target >= arr[index]) {
        int ifPick = memoHelper(index + 1, arr, target - arr[index], dp);
        if(ifPick == true) {
            return dp[index][target] = 1;
        }
    }

    int ifNotPick = memoHelper(index + 1, arr, target, dp);
    if(ifNotPick == true) {
        return dp[index][target] = 1;
    }

    return dp[index][target] = 0;

} // O(n * target) time and O(n * target + n) space

bool subsetSumKMemo(vector<int> &arr, int target) {
    vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));
    return memoHelper(0, arr, target, dp);
}

/////////////////////////////////////////////////////////////////////////////////////////

// now we write the tabulation solution

// The State: dp[i][j]
// Meaning: Is it possible to form a sum of exactly j (target) using a subset of elements from index 0 to i (which means elements must be from 0 to i but again in contiguous or non contiguous manner but follow the order
// Final Answer: Located at dp[n-1][target]

bool subsetSumKTab(vector<int> &arr, int target) {
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    // for the base case, which is if target == 0 then return true for all indices

    for(int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    // for the base case it we are at i == 0, we can only form sum for that value of target which is equal to arr[0] or in simple words dp[0][arr[0]] should be true if arr[0] does not exceed the column size of target + 1 (< target + 1 or <= target), rest all should be 0 by default since they cannot make that sum

    if(arr[0] <= target) {
        dp[0][arr[0]] = true;
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < target + 1; j++) {

            bool notPick = dp[i - 1][j];

            bool pick = false;
            if(arr[i] <= j) {
                pick = dp[i - 1][j - arr[i]];
            }

            dp[i][j] = pick || notPick;
        }
    }

    return dp[n - 1][target];

} // O(n * target) time and O(n * target) space

/////////////////////////////////////////////////////////////////////////////////////////

// now we optimise the space using two arrays which is pretty easy and then move to the most optimal solution in which we use single array

////////////////////////////////////////////////////////////////////////////////////////

// if we have to use single array then we cannot do dp[j] = dp[j] || dp[j - arr[i]] since if we update the value of dp[j] so in future if we calculate dp[j + something] and we might need the value of dp[j] and in that case it would return us the newly updated value for this row and not our value from i - 1th row and hence to prevent that dependency we iterate from the back, rest everything same

bool subsetSumKOptimal(vector<int> &arr, int target) {
    int n = arr.size();
    vector<bool> dp(target + 1, false);

    // base case 1 is if target == 0 then for all i we have dp[i][0] = true

    dp[0] = true;

    // base case 2 : if arr[0] <= target then we have true only for arr[0] rest false

    if(arr[0] <= target) {
        dp[arr[0]] = true;
    }

    // now lets form the answer by iterating from the back and always checking value of pick and not pick from i - 1th row or dp[j] array

    for(int i = 1; i < n; i++) {
        for(int j = target; j >= 1; j--) {

            bool notPick = dp[j];

            bool pick = false;
            if(arr[i] <= j) {
                pick = dp[j - arr[i]];
            }

            dp[j] = pick || notPick;
        }
    }

    return dp[target]; 

} // O(n * target) time and O(target) space most optimal solution

int main() {
    
    return 0;
}