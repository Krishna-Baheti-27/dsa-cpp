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
}

int subArraysWithSumKOptimal(vector<int> &arr, int k) {
    // the most optimal solution will be using prefix sum, same as in logest subarray having given sum
    // simple logic is prefixSum at point is s (cumulative sum) and we are looking for prefixSum = k, then in the map we find any x - k then it essentially gurantees that there will be a prefixSum = k

    unordered_map<int,int> mpp; // our map store prefix sums
    mpp[0] = 1; // storing zero is very imp for algo to work, as it will also help us count single elements as subarray

    int sum = 0, count = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        // if at a point we find the prefixSum = sum - k or k, then we know we have subarray
        count += mpp[sum - k];
        mpp[sum]++;
    }
    return count;
} // O(N) but worst case O(N^N), O(N) space

int main() {
    
    return 0;
}