#include<bits/stdc++.h>
using namespace std;

// return the list of all unique combinations of candidates that sum up to given target
// a same number may be chosen unlimited times in an valid combination but two combinations are said to be unique if atleast one of chosen numbers have different frequency

// so we again use the pick and not-pick procedure but here we can pick any element any number of times 

/////////////////////////////////////////////////////////////////////////////////////

void helper(int index, vector<int> &candidates, vector<int> &arr, vector<vector<int>> &ds, int target) {

    if(index >= candidates.size()) {
        if(target == 0) {
            ds.push_back(arr);
        }
        return;
    }

    // picking the index based on this condition (that target does not become negative, we looking to make target == 0 to get a valid combination not < 0)

    if(candidates[index] <= target) {

        arr.push_back(candidates[index]);

        // pick the element but dont move to next index since we can pick something unlimited number of times so we have to explore it

        helper(index, candidates, arr, ds, target - candidates[index]); 

        arr.pop_back(); // remove if you did pick after returning from the function call
    } 

    // not picking the index so we move to next index without changing the target or our array

    helper(index + 1, candidates, arr, ds, target); 
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {

    vector<int> arr; // temporary array to hold subsequence
    vector<vector<int>> ds; // hold our answer

    helper(0, candidates, arr, ds, target);

    return ds;

} // O(2^target * k), because if we have element as 1 we can do pick not pick for atmost target times. and k is the avg length of valid combination and O(target) recursion stack space since atmost target calls will be made for 1 and O(n) temporary array space

// not considering the space to return the anwer which would be O(k * x) when k is avg length of sequence and x is the number of sequences

// for only not pick case we can make atmost n recursive calls before index goes out of bound keading to 2^n time complexity but in pick case we stay at the same index and we can do this for target times and hence 2^target time complexity includes the not pick case as well (target > n)

// since we either pick the element and stay at same index (to generate all combinations) or move ahead to index + 1, we essentially enforcing no duplicate combinations to be picked by either picking and staying or not picking and move ahead

int main() {
    
    return 0;
}