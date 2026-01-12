#include<bits/stdc++.h>
using namespace std;

// solve leetcode 1755 before 

// You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.

// Return the minimum possible absolute difference

////////////////////////////////////////////////////////////////////////////////////////////

// before solving this exact problem lets solve this problem where we have to divide the array into two partitions such that abs diff of there sum is min, then we will try to solve for case of equal length partition

// considering positive numbers

// we know that least value of subset sum is 0 and the max value can be sum of entire array
// so we have range of s1 from 0 to sum of array and then automatically we have s2 = sum - s1
// and then we simply find the abs diff of each pair of s1 and s2 and return min

// now how to find what are the valid values of s1 in the array, that is for target = 0 to sum of array, for which values of target are possible that is dp[target] = true for what values from [0,target] for only those values of target we have our s1 and then we find s2 and absolute diff

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

} // O(n + (n * sum) + sum / 2) time and O(sum) space

// but this does not work for -ve numbers as
// we are using the current sum as an array index (dp[j]). Array indices cannot be negative. If arr[i] is -5, j - arr[i] becomes j + 5. While the math is fine, you cannot represent sum of-5 as dp[-5]

// to fix this we can add a offset dp[0] becomes dp[0 + offset], to eliminate negative indices but large value of sum requires large offset so not possible to declare vector of size 600 million

// and we dont count how many elements are in each subset so we cant have equal length partitions and even if we do by adding another state of count_num then also the large value of sum (negative indices) and large offsets make it impossible

// hence the solution is meet in the middle, when N is small and sum is large
// we use dp when sum is small and N is large

// here we go

// so first we learn the meet in the middle algo
// we divide the array into two equal halves
// find all possible sums for both halves
// take k items from first half and N - K from second half so that we have a partition of N items total

// Helper function to generate all subset sums grouped by "count" of elements

void getSubsetSums(vector<int>& arr, vector<vector<int>>& sums) {
    int n = arr.size();
    // There are 2^n subsets
    for (int i = 0; i < (1 << n); i++) {
        int currentSum = 0;
        int count = 0;
        
        // Iterate through bits to see which elements are included
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) { // If j-th bit is set
                currentSum += arr[j];
                count++;
            }
        }
        sums[count].push_back(currentSum);
    }
}

int minimumDifference(vector<int>& nums) {
    int n = nums.size() / 2; // The size of one partition
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    int halfSum = totalSum / 2; // This is our ideal target
    
    // 1. Split the array
    vector<int> leftPart(nums.begin(), nums.begin() + n);
    vector<int> rightPart(nums.begin() + n, nums.end());
    
    // 2. Generate sums: sums[k] = list of sums using exactly k elements
    vector<vector<int>> leftSums(n + 1), rightSums(n + 1);
    getSubsetSums(leftPart, leftSums);
    getSubsetSums(rightPart, rightSums);
    
    // 3. Sort right part for Binary Search
    for(int i = 0; i <= n; i++) {
        sort(rightSums[i].begin(), rightSums[i].end());
    }
    
    int minDiff = INT_MAX;
    
    // 4. Iterate over count 'k' for left side
    // If we pick k elements from left, we MUST pick n-k from right
    for(int k = 0; k <= n; k++) {
        
        // For every sum 'a' we found using k elements on the left...
        for(int a : leftSums[k]) {
            
            // We need a sum 'b' from rightSums[n-k] such that a + b is close to halfSum
            int targetB = halfSum - a;
            
            // Binary Search in rightSums[n-k]
            auto& rightVec = rightSums[n - k];
            auto it = lower_bound(rightVec.begin(), rightVec.end(), targetB);
            
            // Check the value found (it >= targetB)
            if(it != rightVec.end()) {
                int combinedSum = a + *it;
                int diff = abs(combinedSum - (totalSum - combinedSum));
                minDiff = min(minDiff, diff);
            }
            
            // Check the value before (it < targetB), to be safe
            if(it != rightVec.begin()) {
                int combinedSum = a + *prev(it);
                int diff = abs(combinedSum - (totalSum - combinedSum));
                minDiff = min(minDiff, diff);
            }
        }
    }
    
    return minDiff;
}

int main() {
    
    return 0;
}