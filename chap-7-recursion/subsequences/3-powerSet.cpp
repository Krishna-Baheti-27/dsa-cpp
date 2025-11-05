#include<bits/stdc++.h>
using namespace std;

// it is also not a subsequecne since in subsequence we follow order
// all subsequenes set == power set if there are no duplicates
// set by definition do not include duplicates and also follow no specific order but subsequecnes can contain duplicates and also follow a order

// power set (need not be contiguous but have to be a subset of string)
// s = "abc", => '', a ,b, c, ab ,bc, ac, abc, at max 8 subsets 
// here we wrote ac so it became a subsequence but ca would not be subsequence

// For the scope of this question, all subsequences and power set are essentially same

// Here we will learn it using recursion, although the most optimal solution is using bit manipulation which can be found on bit manipulation playlist

// So how to find the power set using recursion (when no duplicates then power set is same as generating all subsequences)

// and when the duplicates are present we use two methods to remove them either a set or sort and skip the duplicates

// this is method 1, where we sort the subsequence and store in set so that we dont have repeated terms which would violate our power set

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

    vector<vector<int>> ans(ds.begin(), ds.end()); // copying answer back from set to 2-d array

    return ans;

} // O(2^n * klogk), considering k as the avg length of subsequence

// O(n) recursion stack space + O(n) temporary array space + O(k * x) space where k is avg length of sequence and total x seq

///////////////////////////////////////////////////////////////////////////

// now when we have duplicates then power set is not same as generating all subseqeunces since in thw subsequences we can have redundant terms but the power set must have unique and non repeating sequences 

// hence we skip duplicates here to generate the power set in case of duplicates else without duplicates it is same as generating all subsequences

void findSubsets(int index, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans) {

    // Add the current subset to the answer

    ans.push_back(ds); // O(k) time for this

    for (int i = index; i < nums.size(); ++i) {
        
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

// this is similar to what we will use in the combination sum 2 to avoid duplicate combinations without using the set data structure,and power set essentially means all combinations or subsequecnes without duplicates

vector<vector<int>> generatePowerSetOptimal(vector<int>& nums) {

    vector<vector<int>> ans;
    vector<int> ds;
    
    // sort the array only then our duplicate skipping logic wil work

    sort(nums.begin(), nums.end());
    
    findSubsets(0, nums, ds, ans);

    return ans;

} // O(2^n * k + nlogn) time considering k to be avg length of subsequence
// O(n) recursion stack space + O(n) space for temporary array

int main() {
    
    return 0;
}