#include<bits/stdc++.h>
using namespace std;

// print all the subarrays having sum = k, basically return the indices of start and end of subarray in any possible order

// brute involves generating all possible subarrays
vector<vector<int>> subarraysHavingSumKBrute(vector<int> &arr, int k) {
    vector<vector<int>> ans;
    for(int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for(int j = i; j < arr.size(); j++) {
            sum += arr[j];
            if(sum == k) {
                ans.push_back({i ,j});
            }
        }
    }
    return ans;
} // O(n^2) time

// the better solution uses hashing, and its also optimal for array containing negatives
vector<vector<int>> subarraysHavingSumKBetter(vector<int> &arr, int k) {
    int sum = 0;
    vector<vector<int>> ans;
    // Map stores: {prefix_sum -> list_of_indices_where_it_occurred}
    unordered_map<int,vector<int>> mpp; // for each sum we are storing all the indices at which it occured
    mpp[0].push_back(-1); // {-1} for handling subarrays starting from index 0
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if(mpp.find(sum - k) != mpp.end()) {
            for(int startIdx : mpp[sum - k]) {
                ans.push_back({startIdx + 1, i});
                // storing all possible subarrays or indices having sum as k, and its important that the subarray having sum k actually starts from startIdx + 1 to i
            }
        }
        mpp[sum].push_back(i); // push in the vector all the indices i having sum as sum
    }
    return ans;
} // O(N^2) time in worst case when all subarrays have sum k, else O(2N) time and O(N) space

// the most optimal solution using sliding window and two pointer but only for array containing positives and zero but that is very complex and hardly improves time and hence this hashing solution is used and widely preferred


int main() {
    
    return 0;
}