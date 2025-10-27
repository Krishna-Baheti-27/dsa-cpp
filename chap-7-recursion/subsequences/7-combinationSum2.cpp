#include<bits/stdc++.h>
using namespace std;

// same as combination sum - 1, but each element must be used only once unlike unlimited number of times and we dont want any duplicate combinations , so to prevent the duplicate combinations we must fill them in sorted order

// so in burte we generate all, sort them and store them in a set thus not allowing any duplicate insertion

void helperBrute(int index, vector<int> &candidates, vector<int> &arr, set<vector<int>> &ds, int target) {
    if(index >= candidates.size()) {
        if(target == 0) {
            vector<int> temp = arr;
            sort(temp.begin(), temp.end());
            ds.insert(temp);
        }
        return;
    }
    if(candidates[index] <= target) {
        arr.push_back(candidates[index]);
        helperBrute(index + 1, candidates, arr, ds, target - candidates[index]); // take
        // but we are forced to move ahead
        arr.pop_back();
    } 
    helperBrute(index + 1, candidates, arr, ds, target); // not pick
}

vector<vector<int>> combinationSumBrute(vector<int> &candidates, int target) {
    vector<int> arr;
    set<vector<int>> ds;
    helperBrute(0, candidates, arr, ds, target);
    vector<vector<int>> ans(ds.begin(), ds.end());
    return ans;
} // O(2^n * 2klogk), since we are generating all subsequences so 2^n time for that for all valid subsequences of k avg length we sort them and store them in set O(klogk) time for that
// O(n) recursion stack space + O(k * x) space where k is avg length of sequence and total x seq


////////////////////////////////////////////////////////////////////////////

// this is new pattern of recursion on array other than pick and not pick and used to handle suplicates, ver very important

void helperOptimal(int index, vector<int> &candidates, vector<int> &arr, vector<vector<int>> &ds, int target) {
    if(target == 0) {
        ds.push_back(arr); // add it to the answer as soon as we get valid and return
        return; 
    }
    for(int i = index; i < candidates.size(); i++) {
        // in each level we are making recursive calls from index to n - 1
        if(i > index && candidates[i] == candidates[i - 1]) continue;
        // we pick the first number but avoid picking any further duplicates
        if(candidates[i] > target) break; // since candidates[i] was big then anything after that would also be more than target
        arr.push_back(candidates[i]);
        helperOptimal(index + 1, candidates, arr, ds, target - candidates[i]); 
        arr.pop_back();
    }
}

vector<vector<int>> combinationSumOptimal(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> arr;
    vector<vector<int>> ds;
    helperOptimal(0, candidates, arr, ds, target);
    return ds;
} // O(2^n * k) time where k is avg length of combination, O(n) recursion stack space

int main() {
    
    return 0;
}