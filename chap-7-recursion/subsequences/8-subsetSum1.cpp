#include<bits/stdc++.h>
using namespace std;

// we are given an array and we have to print the sums of all subsets in it in increasing order of sums

// the brute would probably be finding all subset sums and storing in array and then sorting it
// in total we have 2^n subsets or subsequences so total we have to return 2^n sums

void subsetSumsHelperBrute(int index, vector<int> &nums, vector<int> &ans, int sum) {
    if(index >= nums.size()) {
        ans.push_back(sum);
        return;
    }
    sum += nums[index];
    subsetSumsHelperBrute(index + 1, nums, ans, sum); // pick
    sum -= nums[index];
    subsetSumsHelperBrute(index + 1, nums, ans, sum); // not pick
}

vector<int> subsetSumBrute(vector<int> &nums) {
    vector<int> ans;
    subsetSumsHelperBrute(0, nums, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
} // O(2^n + n * 2^n) time and O(n) recursion stack space, not considering space to return the answer

///////////////////////////////////////////////////////////////////////////////////

// now we can eliminate the sorting step at the end which consumes max time, by instead creating sums in increasing order so they can be directly inserted into answer without need of sorting

void subsetsSumsHelperOptimal(int index, vector<int> &nums, vector<int> &ans) {
    if(index < 0) {
        ans.push_back(0);
        return;
    }
    // recursively find all subset sums without current element
    subsetsSumsHelperOptimal(index - 1, nums, ans);
    int currSize = ans.size();
    // to get new subset sums we add current element to all of them
    for(int i = 0; i < currSize; i++) {
        ans.push_back(ans[i] + nums[index]);
    }
}

vector<int> subsetsSumsOptimal(vector<int> &nums) {
    sort(nums.begin(), nums.end()); // nlogn time only
    vector<int> ans;
    subsetsSumsHelperOptimal(nums.size() - 1, nums, ans); // sorting is not required
    return ans;
} // O(nlogn + 2^n) time since at each step currSize doubles by 2, so 1, 2,4, .. 2^(n-1) and O(n) recursion stack space

int main() {
    
    return 0;
}