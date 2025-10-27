#include<bits/stdc++.h>
using namespace std;

void helper(int index, vector<int> &nums, vector<int> &arr, vector<vector<int>> &ds, int k) {
    if(index >= nums.size()) {
        int sum = 0;
        for(int el : arr) sum += el;
        if(sum == k) ds.push_back(arr);
        return;
    }
    arr.push_back(nums[index]);
    helper(index + 1, nums, arr, ds, k);
    arr.pop_back();
    helper(index + 1, nums, arr, ds, k);
} 

vector<vector<int>> subsequencesWithSumKBrute(vector<int> &nums, int k) {
    vector<int> arr;
    vector<vector<int>> ds;
    helper(0, nums, arr, ds, k);
    return ds;
} // generating all subsequences and then finding sum of each and then adding those which have sum k to answer, O(2^n * 2n) time and O(n) space

///////////////////////////////////////////////////////////////////////

// but we dont need to compute sum for each subsequence at the end, we can calculate it on the fly

void helperOptimal(int index, vector<int> &nums, vector<int> &arr, vector<vector<int>> &ds, int k, int sum) {
     // if(sum > k) return;  for array containing positives only
    if(index >= nums.size()) {
        if(sum == k) ds.push_back(arr);
        return;
    }
    arr.push_back(nums[index]); 
    sum += nums[index]; 
    helperOptimal(index + 1, nums, arr, ds, k, sum); // take
    arr.pop_back();
    sum -= nums[index];
    helperOptimal(index + 1, nums, arr, ds, k, sum); // dont take
}

vector<vector<int>> subsequencesWithSumKOptimal(vector<int> &nums, int k) {
    vector<int> arr;
    vector<vector<int>> ds;
    helperOptimal(0, nums, arr, ds, k, 0);
    return ds;
} // O(2^n * l), l is avg length of subsequence having sum K, O(n) recursion space

//////////////////////////////////////////////////////////////////////////

// now how to print any one subsequence with sum k, so if the first call tells us that it found a sbusequence with sum k, there is no need for second call right ?

bool helperAnyoneWithSumK(int index, vector<int> &nums, vector<int> &arr, int k, int sum) {
    // if(sum > k) return false;  for array containing positives only
    if(index >= nums.size()) {
        if(sum == k) return true;
        return false;
        // so we would return with arr having our answer
    }
    sum += nums[index];
    arr.push_back(nums[index]);
    if(helperAnyoneWithSumK(index + 1, nums, arr, k , sum) == true) return true;
    arr.pop_back();
    sum -= nums[index];
    if(helperAnyoneWithSumK(index + 1, nums, arr, k , sum) == true) return true;
    return false; // if none of the calls give true
}

vector<int> anyoneSubsequenceWithSumK(vector<int> &nums, int k) {
    vector<int> arr;
    if(helperAnyoneWithSumK(0, nums, arr, k , 0) == true) return arr;
    return {};
}

////////////////////////////////////////////////////////////////////////

// we have count all the subsequences with sum k

void countSubsequencesHelper(int index, vector<int> &nums, int k, int sum, int &count) {
    // if(sum > k) return;  for array containing positives only
    if(index >= nums.size()) {
        if(sum == k) count++;
        return;
    }
    sum += nums[index]; 
    countSubsequencesHelper(index + 1, nums, k, sum, count); // take case
    sum -= nums[index];
    countSubsequencesHelper(index + 1, nums, k, sum, count); // not take case
}

int countSubsequencesWithSumK(vector<int> &nums, int k) {
    int count = 0;
    countSubsequencesHelper(0, nums, k, 0, count);
    return count;
}

////////////////////////////////////////////////////////////////////////

// a more better way to write this functionally using recursion is, if we found the subsequence hacvinh sum == k, we return 1 (since we have to count it as 1 valid subsequence) and if not then we return 0 stating we didnt find any, if we do this for all take / not take cases then sum of them would be total subsequences having sum == k

// we can also use default parameters if we dont want to use helpers

int countSubsequencesOptimalHelper(int index, vector<int> &nums, int k, int sum) {
    // if(sum > k) return 0;  for array containing positives only
    if(index >= nums.size()) {
        if(sum == k) return 1;
        return 0;
    }
    sum += nums[index];
    int lcount = countSubsequencesOptimalHelper(index + 1, nums, k , sum);
    sum -= nums[index];
    int rcount = countSubsequencesOptimalHelper(index + 1, nums, k ,sum);

    return lcount + rcount;
    // here we only had two recursion calls, for n calls you can run a for loop and achieve same
}

int countSubsequencesWithSumKOptimal(vector<int> &nums, int k) {
    return countSubsequencesOptimalHelper(0, nums, k, 0);
}

int main() {
    
    return 0;
}