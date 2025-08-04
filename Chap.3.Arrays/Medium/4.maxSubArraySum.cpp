#include<bits/stdc++.h> 
using namespace std;

int maxSubArraySumBrute(vector<int> &arr) {
    // same as what we used in longest subarray with given sum
    int maxSum = arr[0];
    for(int i = 0; i < arr.size(); i++) {
        // the subarray is from i to j
        int sum = 0;
        for(int j = i; j < arr.size(); j++) {
            // find sum in each step and compare with maxSum
            sum += arr[j]; // because sum at each step represents the sum of a subarray
            if(sum > maxSum) maxSum = sum;
        }
    }
    return maxSum;
}

int maxSubArraySumOptimal(vector<int> &arr) {
    int maxSum = arr[0], sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if(sum > maxSum) maxSum = sum;
        if(sum < 0) sum = 0;
    }
    return maxSum;
}

// Deep Explanation of Kadane’s Algorithm Logic
// At each index in the array, I have two choices:

// Option 1: Extend the previous subarray by adding the current element (sum + arr[i]).

// Option 2: Start a new subarray at the current element (arr[i]).

// I choose the option that gives me the higher sum:

int maxSubArrayOptimalBetter(vector<int> &arr) {
    int maxSum = arr[0], sum = arr[0]; // ny initial sum
    for(int i = 1; i < arr.size(); i++) {
        sum = max(arr[i], sum + arr[i]); // decide what to do, take initial sum or also add arr[i]
        maxSum = max(sum,maxSum); // storing the max sum
    }
    return maxSum;
}

void printMaxSubarrayLast(vector<int> &arr) {
    int maxSum = arr[0], sum = arr[0], startIdx = 0, endIdx = 0, tempStart = 0;
    for(int i = 1; i < arr.size(); i++) {
        sum = max(arr[i], sum + arr[i]);
        if(sum == arr[i]) {
            tempStart = i; // potentially can be the start of maxsubarray but not sure
        }
        maxSum = max(sum,maxSum);
        if(sum == maxSum) {
            startIdx = tempStart;
            endIdx = i; // the end would be according to if sum == maxSum then this is our subarray end
        }
        // You are correct that after maxSum = max(sum, maxSum), sum == maxSum is true when a new maximum is found, but it’s also true for repeats. That’s why the robust approach checks only for sum > maxSum.
    }
    // the max subarray will be from startIdx to endIdx
    for(int i = startIdx; i <= endIdx; i++) cout << arr[i] << ' ';
    cout << endl;
} // THIS CODE WILL PRINT THE LAST OCCURENCE IF MULTIPLE SUBARRAYS WITH MAX SUM EXIST

// to print the first subarray with max sum use this:

void printMaxSubArrayFirst(vector<int> &arr) {
    int maxSum = arr[0], sum = arr[0], startIdx = 0, tempStart = 0, endIdx = 0;
    for(int i = 1; i < arr.size(); i++) {
        if(sum + arr[i] < arr[i]) { 
            sum = arr[i]; // new subarray
            tempStart = i; // potential startIdx
        } else {
            sum += arr[i]; // continue the subarray
        }
        if(sum > maxSum) {
            startIdx = tempStart; // guranteed that tempStart is start of the subarray
            endIdx = i; // where the subarray is ending
            maxSum = sum;
        }
    }
    for(int i = startIdx; i <= endIdx; i++) {
        cout << arr[i] << ' '; 
    }
    cout << endl;
}

void printMaxSubArrayFirstMoreReadable(vector<int>&arr) {
    // following strivers stlye
    int maxSum = arr[0], sum = 0, tempStart = 0, startIdx = 0, endIdx = 0; // we start with -1 because they may not exist
    for(int i = 0; i < arr.size(); i++) {
        if(sum == 0) tempStart = i; // startIdx for a potentially new max subarray
        sum += arr[i];
        if(sum > maxSum) {  // If another subarray later has the same sum as maxSum, the indices do not update.
            // Modifying for Last Occurrence
// To capture the last occurrence of the maximum subarray, change the condition to sum >= maxSum:
            // subarray found
            startIdx = tempStart;
            endIdx = i;
            maxSum = sum;
        }
        if(sum < 0) sum = 0;
    }
    for(int i = startIdx; i <= endIdx; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main() {
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArraySumBrute(arr) << endl;
    cout << maxSubArrayOptimalBetter(arr) << endl;
    return 0;
}