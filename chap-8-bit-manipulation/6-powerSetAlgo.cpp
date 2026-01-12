#include <bits/stdc++.h>
using namespace std;

// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

//////////////////////////////////////////////////////////////////////////////////////

// this can also be done using backtracking which we have done in recursion but here we will study the power set algo to print all the subsets

vector<vector<int>> subsets(vector<int>& nums) {
    
    int n = nums.size();
    vector<vector<int>> ans;

    int numSubsets = 1 << n;

    for(int i = 0; i < numSubsets; i++) {

        vector<int> temp;

        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                temp.push_back(nums[j]);
            }
        }
        
        ans.push_back(temp);
    }

    return ans;

} // O(n * 2^n) time and space (considering space to return answer)

int main() {
    
    return 0;
}