#include<bits/stdc++.h>
using namespace std;

// we have to print all the subsequences that sum up to k

void helper(int index, vector<int> &nums, vector<int> &arr, vector<vector<int>> &ds, int k) {

    if(index >= nums.size()) {
        int sum = 0;
        for(int el : arr) sum += el;
        if(sum == k) ds.push_back(arr);
        return;
    }

    arr.push_back(nums[index]);
    helper(index + 1, nums, arr, ds, k); // take

    arr.pop_back();
    helper(index + 1, nums, arr, ds, k); // not-take
} 

vector<vector<int>> subsequencesWithSumKBrute(vector<int> &nums, int k) {

    vector<int> arr;
    vector<vector<int>> ds;

    helper(0, nums, arr, ds, k);

    return ds;

} // generating all subsequences and then finding sum of each and then adding those which have sum k to answer, O(2^n * 2n) time and O(n) space for temporary array and O(n) recursion space

///////////////////////////////////////////////////////////////////////

// but we dont need to compute sum for each subsequence at the end, we can calculate it on the fly

void helperOptimal(int index, vector<int> &nums, vector<int> &arr, vector<vector<int>> &ds, int k, int sum) {

     // if(sum > k) return;  for array containing positives only

    if(index >= nums.size()) {
        if(sum == k) {
            ds.push_back(arr);
        }
        return; // return irrespective of whether you add it to the answr or not
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

} // O(2^n * l), l is avg length of subsequence having sum K, O(n) recursion space + O(n)space for temporrary array

///////////////////////////////////////////////////////////////////////////////////

// we can also pass sum variable as a reference to maintain it between function calls like our temporary array which is better practice then using global variables but still its much more preferred to write purely functional recursions

//////////////////////////////////////////////////////////////////////////////////

// now how to print any one subsequence with sum k, so if the first call tells us that it found a sbusequence with sum k, there is no need for second call right? Exactly that we will achieve by making the void function boolean so that it signals us with true or false which helps us avoid unnecessary funtion calls

bool helperAnyoneWithSumK(int index, vector<int> &nums, vector<int> &arr, int k, int sum) {

    // if(sum > k) return false;  for array containing positives only

    if(index >= nums.size()) {
        if(sum == k) {
            return true; // subsequence found
        }
        return false; // subsequence not found
    }

    arr.push_back(nums[index]);
    sum += nums[index];
    if(helperAnyoneWithSumK(index + 1, nums, arr, k , sum) == true) {
        return true; // subsequence found, so stop searching and return true
    }

    arr.pop_back();
    sum -= nums[index];
    if(helperAnyoneWithSumK(index + 1, nums, arr, k , sum) == true) {
        return true; // subsequence found, so stop searching and return true
    }

    return false; // if none of the calls give true, then subsequence not found and keep searching
}

vector<int> anyoneSubsequenceWithSumK(vector<int> &nums, int k) {

    vector<int> arr;

    if(helperAnyoneWithSumK(0, nums, arr, k , 0) == true) return arr;

    return {};

} // O(2^n) time and O(n) recursion space + O(n) space for temporary array

////////////////////////////////////////////////////////////////////////////

// we have to count all the subsequences with sum k

//////////////////////////////////////////////////////////////////////////

// method 1 is passing count by reference so it is maintained across function calls

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

} // O(2^n) time and O(n) space for recursion + O(n) space for temporary array

////////////////////////////////////////////////////////////////////////////

// a more better way to write this functionally using recursion is, if we found the subsequence having sum == k, we return 1 (since we have to count it as 1 valid subsequence) and if not then we return 0 stating we didnt find any, if we do this for all take / not take cases then sum of them would be total subsequences having sum == k

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

} // O(2^n) time and O(n) space for recursion + O(n) space for temporary array

// here we only had two recursion calls, for n calls you can run a for loop and achieve same

int countSubsequencesWithSumKOptimal(vector<int> &nums, int k) {
    return countSubsequencesOptimalHelper(0, nums, k, 0);
}

int main() {
    
    return 0;
}