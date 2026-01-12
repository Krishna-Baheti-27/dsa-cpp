#include <bits/stdc++.h>
using namespace std;

// Given an integer array nums, return the length of the longest strictly increasing subsequence.

////////////////////////////////////////////////////////////////////////////////////

// here by strictly increasing it means we cant have equal elements

// the brute force would be printing all subsequences and then checking for increase and then finding the max len using power set or recursion

// but this takes O(2^n * n) time in worst case and hence we apply a efficient method in which we check along the way

/////////////////////////////////////////////////////////////////////////////////////

// the recurrence would be f(index, prev_index) where prev_index would help us in identifying what was the prev element using which we can determine whether to take the current element or not (to maintaing increasing order)

int lisBruteHelper(int index, int n, int prevIdx, vector<int> &arr) {

    if(index == n) {
        return 0;
    }

    if(prevIdx == -1) {
        return 1 + lisBruteHelper(index + 1, n, index, arr);
    }

    if(arr[prevIdx] > arr[index]) {
        return 1 + lisBruteHelper(index + 1, n, index, arr);
    }

    return 0 + lisBruteHelper(index + 1, n, prevIdx, arr);
}

int lisBrute(vector<int> &arr) {

    int n = arr.size();
    return lisBruteHelper(0, n, -1, arr);

} // O(2^n) time since take and not take for each and O(n) recursion stack space

//////////////////////////////////////////////////////////////////////////////////

int memoHelper(int index, int n, int prevIdx, vector<int> &arr, vector<vector<int>> &dp) {

    if(index == n) {
        return 0;
    }

    if(dp[index][prevIdx + 1] != -1) {
        return dp[index][prevIdx + 1];
    }

    int lenSkip = 0 + memoHelper(index + 1, n, prevIdx, arr, dp);

    int lenTake = 0;

    if(prevIdx == -1 || arr[index] > arr[prevIdx]) {
        lenTake = 1 + memoHelper(index + 1, n, index, arr, dp);
    }

    return dp[index][prevIdx + 1] = max(lenSkip, lenTake);
}

int lisMemo(vector<int> &arr) {

    // dp size of n + 1 to afford the coordinate shift so that we check for dp[index][prev + 1] so that prev = -1 is now handled

    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    return memoHelper(0, n, -1, arr, dp);

} // O(n^2) time and space and O(n) recursion stack space

/////////////////////////////////////////////////////////////////////////////////////

// here the base case would be index == n then return 0 and hence we declare dp array of n + 1 size

int lisTab(vector<int> &arr) {

    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // base case done now vary all paramters and copy the recurrence

    for(int i = n - 1; i >= 0; i--) {

        for(int prev = i - 1; prev >= -1; prev--) {

            int lenSkip = 0 + dp[i + 1][prev + 1];

            int lenTake = 0;

            if(prev == -1 || arr[prev] < arr[i]) {
                lenTake = 1 + dp[i + 1][i + 1];
            }

            dp[i][prev + 1] = max(lenTake, lenSkip);
        }
    }

    return dp[0][0];

} // O(n^2) time and space no recursion stack space

/////////////////////////////////////////////////////////////////////////////////////

int lisSpaceOptimised(vector<int> &arr) {

    int n = arr.size();
    vector<int> after(n + 1, 0), curr(n + 1, 0);

    for(int i = n - 1; i >= 0; i--) {

        for(int prev = i - 1; prev >= -1; prev--) {

            int lenSkip = 0 + after[prev + 1];

            int lenTake = 0;

            if(prev == -1 || arr[prev] < arr[i]) {
                lenTake = 1 + after[i + 1];
            }

            curr[prev + 1] = max(lenTake, lenSkip);
        }

        after = curr;
    }

    return after[0];

} // O(n^2) time and O(2n) space

///////////////////////////////////////////////////////////////////////////////////////

// there is another approach to solve this problem where we have a dp array in which for
// dp[i] we store the lis obtained till index i from 0 to that i

// we start with 1 for all dp[i] and then for each corresponding index if arr[index] > arr[prev] then set dp[i] to be max(dp[i], 1 + dp[prev])

int lisOptimal(vector<int> &arr) {

    int n = arr.size();
    vector<int> dp(n, 1);

    int lis = 1;

    for(int i = 0; i < n; i++) {
        for(int prev = 0; prev <= i - 1; prev++) {
            if(arr[i] > arr[prev]) {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        lis = max(lis, dp[i]);
    }

    return lis;

} // O(n^2) time and O(n) space

////////////////////////////////////////////////////////////////////////////////////

// this solution can be used to trace and print the lis in which we also use a hashh array to maintain what element preceeds what and is critical to find the lis

// here we are only updating for the first occurence and hence we get a lis which is formed from elements whose index is smallest lexicographically 

vector<int> printLis(vector<int> &arr) {

    int n = arr.size();

    vector<int> dp(n, 1);
    vector<int> hashh(n);

    int lis = 1, maxIdx = 0;

    for(int i = 0; i < n; i++) {

        hashh[i] = i;

        for(int prev = 0; prev <= i - 1; prev++) {
            if(arr[i] > arr[prev] && 1 + dp[prev] > dp[i]) {
                dp[i] = max(dp[i], 1 + dp[prev]);
                hashh[i] = prev;
            }
        }

        if(dp[i] > lis) {
            lis = dp[i];
            maxIdx = i;
        }
    }

    vector<int> ans(lis);

    for(int i = lis - 1; i >= 0; i--) {
        ans[i] = arr[maxIdx];
        maxIdx = hashh[maxIdx];
    }

    return ans;

} // O(n^2) time and O(2n) space (ignoring space to return answer)

int main() {
    
    return 0;
}