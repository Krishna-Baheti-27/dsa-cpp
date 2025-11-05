#include<bits/stdc++.h>
using namespace std;

// given the array we have to generate all the subsequences
// a subsequence is a contiguous / non-contiguous portion of array that follows the order
// there are total 2^n subsequences for n length array including empty one

/////////////////////////////////////////////////////////////////////////////

// the strategy we apply here is we go index by index and decide whether to take or not take and on basis of that we add or remove from the temporary array and once we exceed last index then whatever we have in our temporary arr we push that into the our main array storing all subsequences

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

    vector<int> arr; // temporary list to store the subsequence we are trying to form
    vector<vector<int>> ds; // data structure to store the answer

    helper(0, arr, nums, ds);

    return ds;

} // O(2^n * n) time and O(n) space for recursion + O(n) space for temporary array 

// for every index we have two options take, not take so 2 * 2 * 2 .. n times = O(2^n) * O(n) to store the subsequence in ds

// this code will always generate 2^n subsequences
// this code also works for power set if we have no duplicates and if we have duplicates then we have to make sure we not inserting duplicates by either using a set or simply sorting the nums and skipping suplicates

int main() {
    
    return 0;
}