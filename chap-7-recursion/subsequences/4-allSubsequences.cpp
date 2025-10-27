#include<bits/stdc++.h>
using namespace std;

void helper(int index, vector<int> &arr, vector<int> &nums, vector<vector<int>> &ds) {
    if(index >= nums.size()) {
        ds.push_back(arr);
        return;
    }
    arr.push_back(nums[index]);
    helper(index + 1, arr, nums, ds); // take 
    arr.pop_back();
    helper(index + 1, arr, nums, ds); // dont take
}

vector<vector<int>> generateAllSubsequences(vector<int> &nums) {
    vector<int> arr; // temporary list to store a single subsequences
    vector<vector<int>> ds; // to store the answer
    helper(0, arr, nums, ds);
    return ds;
} // for every index we have two options take, not take so 2 * 2 * 2 .. n times = O(2^n) * O(n) sot store the subsequence in ds and O(n) space for recursion

// this code will always generate 2^n subsequences
// this code also works for power set but there we have to make sure we not inserting duplicates by either using a set or simply sorting the nums and skipping suplicates

int main() {
    
    return 0;
}