#include<bits/stdc++.h>
using namespace std;

// we are given an array and we have to print the sums of all subsets in it in increasing order of sums

//////////////////////////////////////////////////////////////////////////////////////

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

    vector<int> ans; // to store all the subset sums

    subsetSumsHelperBrute(0, nums, ans, 0);

    sort(ans.begin(), ans.end()); // sort it as thats what the question demands

    return ans;

} // O(2^n + n * 2^n) time and O(n) recursion stack space, not considering space to return the answer

/////////////////////////////////////////////////////////////////////////////////////

// this is incorrect as the final output will not be sorted

// void subsetsSumsHelperOptimal(int index, vector<int> &nums, vector<int> &ans) {

//     if(index < 0) {
//         ans.push_back(0);
//         return;
//     }

//     // recursively find all subset sums without current element

//     subsetsSumsHelperOptimal(index - 1, nums, ans);

//     int currSize = ans.size();

//     // to get new subset sums we add current element to all of them

//     for(int i = 0; i < currSize; i++) {
//         ans.push_back(ans[i] + nums[index]);
//     }
// }

// vector<int> subsetsSumsOptimal(vector<int> &nums) {

//     // nlogn time only to sort the initial array and not array consisting of all subsequence sums

//     sort(nums.begin(), nums.end()); 

//     vector<int> ans;

//     subsetsSumsHelperOptimal(nums.size() - 1, nums, ans); // sorting is not required

//     return ans;

// } // O(nlogn + 2^n) time since at each step currSize doubles by 2, so 1, 2,4, .. 2^(n-1) and O(n) recursion stack space, ignoring space to return the answer

///////////////////////////////////////////////////////////////////////////////////

// the most optimal solution doesnt involve recursion since that would make complexity as n * 2^n but this is an iterative way in which each time we create a new list from existing answer for addding the new element and then we merge them (using merge two sorted lists) and then assign the merged list to be our new answer

// We don't need to sort the input `nums` for this approach
// But if we did, it wouldn't change the final complexity
// sort(nums.begin(), nums.end());

vector<int> subsetSumsOptimal(vector<int> &nums) { 

    vector<int> ans;
    ans.push_back(0); // Start with the sum of the empty subset

    for (int num : nums) {

        // 'ans' is already sorted from the previous iteration.
        // Create the new sums by adding 'num' to every element in 'ans'.
        // 'new_sums' will also be sorted since ans is sorted

        vector<int> new_sums;
        for (int sum : ans) {
            new_sums.push_back(sum + num);
        }

        // Now, merge the two sorted lists ('ans' and 'new_sums')
    
        vector<int> merged_ans;
        int i = 0; 
        int j = 0; 

        while(i < ans.size() && j < new_sums.size()) {

            if (ans[i] < new_sums[j]) {
                merged_ans.push_back(ans[i]);
                i++;
            } else {
                merged_ans.push_back(new_sums[j]);
                j++;
            }
        }
        while (i < ans.size()) {
            merged_ans.push_back(ans[i]);
            i++;
        }
        while (j < new_sums.size()) {
            merged_ans.push_back(new_sums[j]);
            j++;
        }

        // The merged list is now the new 'ans' for the next iteration
        ans = merged_ans;
    }

    return ans;

} // O(2^n) time 

// since we have total 2^n new subset sums and we are processing each one of those once
// and total space is also O(2^n) to store the merged list in worst case

int main() {
    vector<int> nums = {4, 1, 2, 3};
    vector<int> ans = subsetSumsOptimal(nums);
    for(int el : ans) cout << el << ' ';
    cout << endl;   
    return 0;
}