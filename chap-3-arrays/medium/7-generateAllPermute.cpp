#include<bits/stdc++.h>
using namespace std;

// arr is of distinct integers

void recurPermute(vector<int> &ds, vector<int> &arr, vector<vector<int>> &ans, int freq[]) {
    if(ds.size() == arr.size()) {
        ans.push_back(ds);
        return; // this is our base case once, the size of ds is full or we have calculated all permutations for a give starting element we store that in the ans, (which is container of our permutations)
    }
    for(int i = 0; i < arr.size(); i++) {
        if(!freq[i]) {
            // if the permutations starting from this element have not been found then
            ds.push_back(arr[i]); // add it to the list
            freq[i] = 1; // mark it
            recurPermute(ds, arr, ans, freq); // call to get and mark next elements
            freq[i] = 0; // unmark it
            ds.pop_back();
        }
    }
}

vector<vector<int>> permutationsBrute(vector<int> &arr) {
    vector<vector<int>> ans; // we will return this
    vector<int> ds; // so we pick the elements from this arr one by one
    int freq[arr.size()] = {0};
    recurPermute(ds, arr, ans, freq);
    return ans;
} 

// here we use swapping to generate all permutations and hence O(1) space excluding recursion stack space
void recurPermuteOptimal(vector<vector<int>> &ans, vector<int> &arr, int index) {
    if(index >= arr.size()) {
        ans.push_back(arr);
        return; 
    }
    for(int j = index; j < arr.size(); j++) {
        swap(arr[index], arr[j]);
        recurPermuteOptimal(ans, arr, index + 1);
        // backtrack , when we do return we want the original array for next calls hence
        swap(arr[index], arr[j]);
    }
}

vector<vector<int>> permutationsOptimal(vector<int> &arr) {
    vector<vector<int>> ans;
    int index = 0;
    recurPermuteOptimal(ans, arr,index);
    return ans;
}

int main() {
    
    return 0;
}