#include<bits/stdc++.h>
using namespace std;

// brute can be probably be using three loops which we have already done before

int subarraysWithSumKBetter(vector<int> &arr, int k) {
    // generate all the subarrays and then count how many are giving you sum = k
    int count = 0;
    for(int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for(int j = i; j < arr.size(); j++) {
            sum += arr[j];
            if(sum == k) count++;
        }
    }
    return count;
} // O(n^2) time

int subArraysWithSumKOptimal(vector<int> &arr, int k) {
    // the most optimal solution will be using prefix sum, same as in logest subarray having given sum
    // simple logic is prefixSum at point is s (cumulative sum) and we are looking for prefixSum = k, then in the map we find any x - k then it essentially gurantees that there will be a prefixSum = k

    unordered_map<int,int> mpp; // our map store prefix sums
    mpp[0] = 1; 
    // This is a crucial initialization. It handles cases where a subarray that sums to k starts from index 0.
    // For example, in [3, 2, 1] with k=5, when i=1, the sum is 5. The code will look for mpp[sum - k], which is mpp[5 - 5] = mpp[0]. By initializing mpp[0] to 1, we correctly count this subarray [3, 2]

    int sum = 0, count = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        // if at a point we find the prefixSum = sum - k or k, then we know we have subarray
        count += mpp[sum - k];
        mpp[sum]++; // its very important to store all occurences of a prefix sum as we want to count total number of subarrays
    }
    return count;
} // O(N) but worst case O(N^2) time, O(N) space

int main() {
    
    return 0;
}