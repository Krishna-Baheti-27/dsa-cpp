#include<bits/stdc++.h>
using namespace std;

// maximum subarray sum, and the array contains negatives also so it need not be the sum of enitre array

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
}

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
}

// kadane algo cleverly covers all the subarrays by making sure to store the maxSum and reset sum to 0 once its not helpful
int maxSubarraySumOptimal(const vector<int> &arr) {
    int sum = 0, maxSum = INT_MIN;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        maxSum = max(sum ,maxSum); // store the maximum sum
        if(sum < 0) {
            sum = 0; // no need to carry it forward, since negative sum would do us more harm
            // and we do maintain maxSum so even if we set sum = 0, we still know maxSum encountered so far
            // this also marks the start of new subarray 
        }
    }
    return maxSum;
}

vector<int> printMaxSumSubarray(const vector<int> &arr) {
    int sum = 0, maxSum = INT_MIN, start = 0, arrStart, arrEnd;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if(sum > maxSum) {
            // here if we use sum >= maxSum, it would be the max-length sub array having maxSum 
            // currently it gives us the min-length sub array having maxSum
            maxSum = sum;
            arrStart = start; // this is where we started this subarray, when we reset the sum to 0
            arrEnd = i; // this is the end becuase it is where we have found the maxSum, nd it will be updated accordingly if we find an even beeter subarray
        } 
        if(sum < 0) {
            sum = 0;
            start = i + 1; // ditch this subarray, its of no use, i + 1 marks the start of new subarray
        }
    }
    return {arrStart, arrEnd};
} // if the array contains all negative numbers then return the max element as subarray {maxIdx,maxIdx}

// IF YOU WANT TO PRINT ALL THE SUBARRAYS HAVING sum = maxSum then apply brute force method to find all the subarrays having sum == maxSum

int main() {
    
    return 0;
}