#include<bits/stdc++.h>
using namespace std;

// it is also not a subsequecne since in subsequence we follow order
// all subsequenes set == power set if there are no duplicates
// set by definition do not include duplicates and also follow no specific order but subsequecnes can contain duplicates and also follow a order

// power set (need not be contiguous but have to be a subset of string)
// s = "abc", => '', a ,b, c, ab ,bc, ac, abc, at max 8 subsets 

// Here we will learn it using recursion, although the most optimal solution is using bit manipulation which can be found on bit manipulation playlist

// So how to find the power set using recursion

void helper(int index, vector<int> &arr, vector<int> &nums, set<vector<int>> &ds) {
    if(index >= nums.size()) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        ds.insert(temp);
        return;
    }
    arr.push_back(nums[index]);
    helper(index + 1, arr, nums, ds); // take 
    arr.pop_back();
    helper(index + 1, arr, nums, ds); // dont take
}

vector<vector<int>> generateAllSubsequencesBrute(vector<int> &nums) {
    vector<int> arr; // temporary list to store a single subsequences
    set<vector<int>> ds; // to store the answer
    helper(0, arr, nums, ds);
    vector<vector<int>> ans(ds.begin(), ds.end());
    return ans;
}

/////////////////////////////////////////////////////////////

void findSubsets(int index, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans) {
    // Add the current subset to the answer
    ans.push_back(ds);

    for (int i = index; i < nums.size(); ++i) {
        // *** Key Optimization Step ***
        // If the current element is the same as the previous one, skip it
        // to avoid duplicate subsets.
        if (i > index && nums[i] == nums[i-1]) {
            continue;
        }

        ds.push_back(nums[i]); // take
        findSubsets(i + 1, nums, ds, ans); // Recurse for the next elements
        ds.pop_back(); // Backtrack, not take
    }
}

// this is similar to what we will use in the combination sum 2 to avoid duplicate combinations without using the set data structure

vector<vector<int>> generatePowerSetOptimal(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ds;
    
    // 1. Sort the input array first
    sort(nums.begin(), nums.end());
    
    findSubsets(0, nums, ds, ans);
    return ans;
}

int main() {
    
    return 0;
}