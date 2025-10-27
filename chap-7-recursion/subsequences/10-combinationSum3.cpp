#include<bits/stdc++.h>
using namespace std;

// the brute force i can think of is generate all possible combinations of k legnth of numbers from [1,9] and then consider all those which have sum == n, but we cannot use any number twice, so we can pick and not pick but move ahead always and since numbers from 1 to 9 are unique we are guranteed we wont form any duplicate combination

// we dont have to generate all subsequences, but only of length k but lets start with generating all

void helperBrute(int index, vector<int> &nums, vector<int> &arr, vector<vector<int>> &ds, int sum, int k, int n) {
    if(index >= nums.size()) {
        if(arr.size() == k && sum == n) {
            // valid permutation
            ds.push_back(arr);
        }
        return;
    }
    sum += nums[index];
    arr.push_back(nums[index]); 
    helperBrute(index + 1, nums, arr, ds, sum, k, n); // pick
    sum -= nums[index];
    arr.pop_back();
    helperBrute(index + 1, nums, arr, ds, sum, k, n); // not pick
}

vector<vector<int>> combinationSumBrute(int k, int n) {
    vector<int> arr;
    vector<vector<int>> ds;
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    helperBrute(0, nums, arr, ds, 0, k, n);
    return ds;
}

////////////////////////////////////////////////////////////////////////////////////////

// so the above code does work, but we are doing a lot of unnecessar work, once we have the combination length == k, we should check if sum == n and return and we dont need to check for every index till index >= 9

void helperOptimal(int index, vector<int> &nums, vector<int> &arr, vector<vector<int>> &ds, int sum, int k, int n) {
    if(sum > n) return;
    if(arr.size() == k) {
        if(sum == n) ds.push_back(arr);
        return;
    }
    if(index >= nums.size()) return;
    sum += nums[index];
    arr.push_back(nums[index]); 
    helperBrute(index + 1, nums, arr, ds, sum, k, n); // pick
    sum -= nums[index];
    arr.pop_back();
    helperBrute(index + 1, nums, arr, ds, sum, k, n); // not pick
} // this is very cluttered way to write

// more better way to write

void helperOptimalReadable(int index, vector<int> &nums, vector<int> &arr, vector<vector<int>> &ds, int sum, int k, int n) {
    if(arr.size() == k && sum == n) { // found the answer
        ds.push_back(arr);
        return; 
    }
    if(sum > n || arr.size() >= k || index >= nums.size()) return; // no answer
    sum += nums[index];
    arr.push_back(nums[index]); 
    helperBrute(index + 1, nums, arr, ds, sum, k, n); // pick
    sum -= nums[index];
    arr.pop_back();
    helperBrute(index + 1, nums, arr, ds, sum, k, n); // not pick
}

vector<vector<int>> combinationSumOptimal(int k, int n) {
    vector<int> arr;
    vector<vector<int>> ds;
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    helperOptimal(0, nums, arr, ds, 0, k, n);
    return ds;
} // O(2^9 * k) time and O(k) space, in reality k <= 9 so our time is O(2^k * k) as we only generate combinations till k length

// we can also this using the second for loop pattern rather than pick and not pick, but here duplicates were being handles imlicitly so we didnt need that but if array contained duplicates we would need to use for loop to pick only first element and skip duplicates

int main() {
    
    return 0;
}