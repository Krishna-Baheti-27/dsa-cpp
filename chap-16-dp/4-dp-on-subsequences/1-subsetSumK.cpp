#include<bits/stdc++.h>
using namespace std;

// subset or subsequence is a contiguous or non contiguous portion of the array which follows the order

// we are given an array and we have to return true if there exists a subset or subsequence whose elements add up to given target

// this code does not work for negative numbers

//////////////////////////////////////////////////////////////////////////////////////////

// this can also be done using power set algo (bit manipulation) but we dont need to generate all subsets (we only want to check whether any subset does the job) hence go with recursion

// so first idea that comes to mind is to generate all the subsequences, but here we have to just tell whether there is atleast one valid subsequence or not so as soon as we get our answer we just return true early and hence we dont need to generate all the subsequences, neverthless we will have to apply recursion

// so what is the recurrence

// f(index, target) => return true if there is a subsequence from [0..index] that adds up to target or false otherwise

// so for a particular element we always the choice whether to take it or not (pick / not pick)

// we dont really maitain a sum variable as we wont have overlapping subproblems and state would only increase and also it would be backtracking style which we wont be able to optimise

bool subsetSumKBruteHelper(int index, int target, vector<int> &arr) {

    // check this first very important for arr = [5] and target = 5, but this works because we only have to tell whether there is a subset of sum k or not, but it does not explore all the subsets and fails especially when we have arr[i] == 0 (not only positives but 0 also)
    // a more standard base case would be this where we explore all the paths

    // so if you want to count the subsets then use index == n or else return early

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

    bool pick = false;

    if(target >= arr[index]) {
        pick = subsetSumKBruteHelper(index + 1, target - arr[index], arr);
    }

    // not pick case

    bool notPick = subsetSumKBruteHelper(index + 1, target, arr);
   
    return pick || notPick;

} // O(2^n) time and O(n) recursion stack space

bool subsetSumKBrute(vector<int> &arr, int target) {
    return subsetSumKBruteHelper(0, target, arr);
}

// apply the formula of no. of levels * work done at each level for T.C if work done at each level is same

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

    // for the base case, which is if target == 0 then return true for all indices since we can always form sum of 0 by not picking any element (empty subset)

    for(int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    // for i == 0 what sums can we make, either 0 (by not picking alreayd marked true) or arr[0] but we cant straight up set dp[0][arr[0]] = true as what if it goes out of bounds and hence we check first

    if(arr[0] <= target) {
        dp[0][arr[0]] = true;
    }

    // fill the rest of the table

    for(int i = 1; i < n; i++) {

        for(int j = 1; j < target + 1; j++) {

            // what if i dont pick any new element can i still make the sum == target, that we can check by looking at the last index where it was possible before or not

            bool notPick = dp[i - 1][j]; 

            // now what sum can we make standing at i, it is arr[i] but again we have to check since we cannot pick an element that is larger than the target sum you want to make (doesnt make sense) (in other words j - arr[i] >= 0 since array indices)

            // so if we can pick the current element then we check if target - current element was possible before because if it was then we have true

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

// if we have to use single array then we cannot do dp[j] = dp[j] || dp[j - arr[i]] since if we update the value of dp[j] so in future if we calculate dp[j + something] and we might need the value of dp[j] and in that case it would return us the newly updated value for this row and not our value from i - 1th row and hence to prevent that dependency we iterate from the back since we have a backward dependency

bool subsetSumKOptimal(vector<int> &arr, int target) {
    
    int n = arr.size();
    vector<bool> dp(target + 1, false);

    // base case 1 is if target == 0 then for all i we have dp[i][0] = true

    dp[0] = true;

    // base case 2 : if arr[0] <= target then we have true only for arr[0] rest false

    if(arr[0] <= target) {
        dp[arr[0]] = true;
    }

    // now lets form the answer by iterating from the back and always checking value of pick and not pick from i - 1th row which is maintained in dp array

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

////////////////////////////////////////////////////////////////////////////////////

// code for array containing negative elements also

bool subsetSumWithNegatives(vector<int> &arr, int target) {
    int n = arr.size();
    
    // 1. Calculate the Range of Possible Sums
    int minSum = 0;
    int maxSum = 0;
    for(int val : arr) {
        if(val < 0) minSum += val;
        else maxSum += val;
    }

    // 2. Check if target is impossible (outside the theoretical bounds)
    if(target < minSum || target > maxSum) return false;

    // 3. Define Offset and DP Size
    // Offset is usually abs(minSum) so that minSum maps to index 0
    int offset = abs(minSum);
    int rangeSize = maxSum - minSum + 1;

    vector<bool> dp(rangeSize, false);

    // 4. Base Case: Sum 0 is always possible (empty subset)
    dp[0 + offset] = true; 

    // 5. Iterate
    for(int num : arr) {
        if(num >= 0) {
            // Positive Number: Iterate Right -> Left
            // We stop at 'num' because below that, index - num would be invalid logic for this loop
            // But realistically we just check bounds inside.
            for(int j = maxSum; j >= minSum; j--) {
                // To form sum 'j', we look at 'j - num'
                // Map logical sum to array index: (j - num) + offset
                int prevIndex = (j - num) + offset;
                int currIndex = j + offset;
                
                if(prevIndex >= 0 && prevIndex < rangeSize) {
                   if(dp[prevIndex]) dp[currIndex] = true;
                }
            }
        } else {
            // Negative Number: Iterate Left -> Right
            // We iterate UP because we need the value from the RIGHT (larger sum)
            for(int j = minSum; j <= maxSum; j++) {
                // To form sum 'j' using a negative number, we needed 'j - num' (which is larger)
                // Example: to form -5 using -3, we needed -2 previously.
                int prevIndex = (j - num) + offset;
                int currIndex = j + offset;

                if(prevIndex >= 0 && prevIndex < rangeSize) {
                    if(dp[prevIndex]) dp[currIndex] = true;
                }
            }
        }
    }

    return dp[target + offset];
}

int main() {
    
    return 0;
}