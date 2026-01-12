#include<bits/stdc++.h>
using namespace std;

// we have to count the number of subsets in the array having sum == target

// pretty easy already done in part 1 of subset sum k

int countSubsetsSumKBruteHelper(int index, vector<int> &arr, int target) {

    // we dont check target == 0 and return since we want to check all possible subsets

    if(index == arr.size()) {
        return target == 0 ? 1 : 0;
    }

    // pick case

    int countPick = 0;
    if(target >= arr[index]) {
        countPick = countSubsetsSumKBruteHelper(index + 1, arr, target - arr[index]);
    }

    // not pick case

    int countNotPick = countSubsetsSumKBruteHelper(index + 1, arr, target);

    return countPick + countNotPick;

} // O(2^n) time and O(n) recursion stack space

int countSubsetsSumKBrute(vector<int> &arr, int target) {
    return countSubsetsSumKBruteHelper(0, arr, target);   
}

///////////////////////////////////////////////////////////////////////////////////////////

int memoHelper(int index, int target, vector<int> &arr, vector<vector<int>> &dp) {
    
    if(index == arr.size()) {
        return target == 0 ? 1 : 0;
    }

    if(dp[index][target] != -1) {
        return dp[index][target];
    }

    int countPick = 0;
    if(target >= arr[index]) {
        countPick = memoHelper(index + 1, target - arr[index], arr, dp);
    }

    int notPickCount = memoHelper(index + 1, target, arr, dp);

    return dp[index][target] = countPick + notPickCount;

} // O(n * target) time and O(n * target + n) space

int countSubsetsSumKMemo(vector<int> &arr, int target) {
    vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));
    return memoHelper(0, target, arr, dp);
}

//////////////////////////////////////////////////////////////////////////////////////////

int countSubsetsSumKTab(vector<int> &arr, int target) {

    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    // base case 1 :
    // if target == 0 then true for any index or count = 1 for all i = [0..n - 1] but if we didnt have arr elements as zero themselves, but now if arr[i] == 0 this means there are two subsets that give us target == 0, that is picking it, or not picking it, so we have to keep that in mind

    if(arr[0] == 0) {
        dp[0][0] = 2; // two subsets -> {}, {0}
    } else {
        dp[0][0] = 1; // only empty subset -> {}
    }

    // base case 2 :
    // if i == 0, then if arr[0] <= target then dp[0][arr[0]] count = 1, but what if arr[0] == 0, then we have alreayd dealt with that in earlier case and no need to overwrite it here and hence we check arr[0] != 0 and arr[0] <= target then only dp[0][arr[0]] = 1

    if(arr[0] != 0 && arr[0] <= target) {
        dp[0][arr[0]] = 1;
    }

    // now if you pay close attention we only have computed the first row of dp table that is, only dp[0][j] is computed for all j, but dp[i][0] is still remaining (for i > 0), that is the first column is still remaining so we start from second row (i = 1) and first column that is j = 1 to j = target and compute every entry using our formula and not dp[i][0] = 1 (for all i) like we did when we didnt have zeroes

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < target + 1; j++) {

            int notPick = dp[i - 1][j];
            int pick = 0;
            if(arr[i] <= j) {
                pick = dp[i - 1][j - arr[i]];
            }

            dp[i][j] = pick + notPick;
        }
    }

    return dp[n - 1][target];

} // O(n * target) time and O(n * target) space

//////////////////////////////////////////////////////////////////////////////////////////

// again we can do this using two arrays, where one is the our primary answer and other is the current answer and we build the current answer using primary answer and then after that row is done we change primary answer to current answer and repeat 

// but there is a better way of achieving this only using a single array in which we iterate backwards so we dont overwrite anything important and old to be new updated which causes incorrect calculation of number of ways

int countSubsetsOptimal(vector<int> &arr, int target) {

    int n = arr.size();
    vector<int> dp(target + 1, 0);

    // base case 1 :

    if(arr[0] == 0) {
        dp[0] = 2;
    } else {
        dp[0] = 1;
    }

    // base case 2 : 

    if(arr[0] != 0 && arr[0] <= target) {
        dp[arr[0]] = 1;
    }

    for(int i = 1; i < n; i++) {
        for(int j = target; j >= 0; j--) {

            int notPick = dp[j];

            int pick = 0;
            if(arr[i] <= j) {
                pick = dp[j - arr[i]];
            }

            dp[j] = pick + notPick;
        }
    }

    return dp[target];

} // O(n * target) time and O(target) space

int main() {
    
    return 0;
}