#include<bits/stdc++.h>
using namespace std;

// we have to count all the subarrays having sum == k

////////////////////////////////////////////////////////////////////////

int subarraysWithSumKBrute(vector<int> &arr, int k) {
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

///////////////////////////////////////////////////////////////////////

// the most optimal solution will be using prefix sum, same as in logest subarray having given sum
// simple logic is prefixSum at point is s (cumulative sum) and we are looking for prefixSum = k, then in the map we find any x - k then it essentially gurantees that there will be a prefixSum = k

// and we have to count all the subarrays and hence store all values of sum encountered

// we already used the similar logic in 4-2 for printing all the subarrays having sum k and here we just how to count the number of subarrays having sum k, so just a subset of that

int subArraysWithSumKOptimal(vector<int> &arr, int k) {

    unordered_map<int,int> mpp; // our map store prefix sums

    // This is a crucial initialization. It handles cases where a subarray that sums to k starts from index 0.
    mpp[0] = 1; 

    int sum = 0, count = 0;

    for(int i = 0; i < arr.size(); i++) {

        sum += arr[i];

        // if at a point we find the prefixSum = sum - k or k, then we know we have subarray
        count += mpp[sum - k];

        // its very important to store all occurences of a prefix sum as we want to count total number of subarrays, we dont have to store index at which sum occured since we only want the count and not actual subarrays

        mpp[sum]++; 

    }

    return count;
    
} // O(N) but worst case O(N^2) time, O(N) space

int main() {
    
    return 0;
}