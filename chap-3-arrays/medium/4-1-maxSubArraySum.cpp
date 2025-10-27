#include<bits/stdc++.h>
using namespace std;

// return the maximum possible subarray sum for given array, and the array contains negatives also so it need not be the sum of enitre array

int maxSubarraySumBrute(const vector<int> &arr) {
    // generating all subarrays, finding sum in each case and returning the maxSum
    int maxSum = INT_MIN;
    for(int i = 0; i < arr.size(); i++) {
        
        for(int j = i; j < arr.size(); j++) {
            // each subarray would from j to i as we are already aware
            int sum = 0;
            for(int k = i; k <= j; k++) {
                sum += arr[k];   
            }
            maxSum = max(sum, maxSum);
        }
    }
    return maxSum;
} // O(n^3)

int maxSubarraySumBetter(const vector<int> &arr) {
    int maxSum = INT_MIN;
    for(int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for(int j = i; j < arr.size(); j++) {
            sum += arr[j];
            maxSum = max(sum, maxSum);
        }
    }
    return maxSum;
} // O(n^2)

// kadane algo cleverly covers all the subarrays by making sure to store the maxSum and reset sum to 0 once its not helpful, the main magic is we immediately store the maxSum once its obtained

int maxSubarraySumOptimal(const vector<int> &arr) {
    int sum = 0, maxSum = INT_MIN;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        maxSum = max(sum, maxSum); // store the maximum sum
        if(sum < 0) sum = 0;
        // no need to carry it forward, since negative sum would do us more harm
        // this also marks the start of new subarray starting from next iteration
    }
    return maxSum;
} // O(n) time

int minSubarraySumOptimal(vector<int> &arr) {
    int sum = 0, minSum = INT_MAX;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        minSum = min(minSum, sum);
        if(sum > 0) sum = 0;
    }
    return minSum;
}

vector<int> printMaxSumSubarray(const vector<int> &arr) {
    int sum = 0, maxSum = INT_MIN, start = 0, arrStart, arrEnd;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if(sum > maxSum) {
            // here if we use sum >= maxSum, it would be the max-length sub array having maxSum 
            // currently it gives us the min-length sub array having maxSum 

            maxSum = sum; // update the maxSum

            arrStart = start; // this is where we started this subarray, when we reset the sum to 0

            arrEnd = i; // this is the end becuase it is where we have found the maxSum, and it will be updated accordingly if we find an even beeter subarray
        } 
        if(sum < 0) {
            sum = 0;
            start = i + 1; 
            // ditch this subarray, its of no use, i + 1 marks the start of new subarray
            // but we dont know if that new subarray would be maxSubArray or not and hence we wait to verify if that is max and then only set arrStart = start
        }
    }

    return {arrStart, arrEnd};

} // if the array contains all negative numbers then return the max element as subarray {maxIdx,maxIdx}

// Ok when we use sum > maxSum, this condition is hit only once and we get the min-legnth max subarray, if there is a segment ahead which sums up to zero so we again have sum = maxSum
// ex => {5,-2,2}
// so when we have the condition as sum >= maxSum the if block woudl be executed and arrStart would remain same but arrEnd to be updated to current i, and hence we have the max-length max subarray

// Ok, if you want to print all the subarrays having max sum and not only min-legnth subarray having max sum and max-length subarray having max sum then first find the maxSum of the max sum subarray and THEN
// WE HAVE QUESTION 4-2 (part 2) WHICH EXPLAINS how to print all the subarrays having given sum k

int main() {
    
    return 0;
}