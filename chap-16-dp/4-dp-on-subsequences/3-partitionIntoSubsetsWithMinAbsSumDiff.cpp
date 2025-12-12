#include<bits/stdc++.h>
using namespace std;

// You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.

// Return the minimum possible absolute difference

/////////////////////////////////////////////////////////////////////////////////////////////

// before solving this exact problem lets solve this problem where we have to divide the array into two partitions such that abs diff of there sum is min, then we will try to solve for case of equal length partition

// we know that least value of subset sum  is 0 and the max value can be sum of entire array
// so we have range of s1 from 0 to sum of array and then automatically we have s2 = sum - s1
// and then we simply find the abs diff of each pair of s1 and s2 and return min

// now how to find what are the valid values of s1 in the array, that is for target = 0 to sum of array, for which values of target is target sum == true, for those values only its possible and then we find s2 and absolute diff

// for finding that we compute the dp table for subset sum equal to target for target = sum of array

vector<bool> subsetSumKOptimal(vector<int> &arr, int target) {
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

    return dp; 

} // O(n * target) time and O(target) space most optimal solution

int minAbsSumDiff(vector<int> &arr) {

    int sum = accumulate(arr.begin(), arr.end(), 0);
    vector<bool> dp = subsetSumKOptimal(arr, sum);

    int minDiff = INT_MAX;

    for(int i = 0; i <= sum / 2; i++) {
        if(dp[i] == true) {
            minDiff = min(minDiff, abs((sum - i) - i));
        }
    } 

    return minDiff;

} // O(n + n * sum + sum / 2) time and O(sum) space

// but this does not work for -ve numbers as
// we are using the current sum as an array index (dp[j]). Array indices cannot be negative. If arr[i] is -5, j - arr[i] becomes j + 5. While the math is fine, you cannot represent sum of-5 as dp[-5]

// to fix this we can add a offset dp[0] becomes dp[0 + offset], to eliminate negative indices but large value of sum requires large offset so not possible to declare vector of size 600 million

// and we dont count how many elements are in each subset so we cant have equal length partitions and even if we do then also the large value of sum (negative indices) and large offsets make it impossible

// hence the solution is meet in the middle

// here we go



int main() {
    
    return 0;
}