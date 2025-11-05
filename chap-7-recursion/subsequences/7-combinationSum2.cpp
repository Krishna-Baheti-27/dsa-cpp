#include<bits/stdc++.h>
using namespace std;

// same as combination sum - 1, but each element must be used only once unlike unlimited number of times and we dont want any duplicate combinations , so to prevent the duplicate combinations we must fill them in lexicographically sorted order

// here all the array elements are positive thats why the code works becuase we have assumptions in which we return after target == 0 and insert only if target is not negative

//////////////////////////////////////////////////////////////////////////////////////

// so in burte force we generate all, sort them and store them in a set thus not allowing any duplicate insertion and we are guranteed that we wont use any element twice in the same combination since we either pick or not pick and then move to the next index (always) thus no same element would be considered twice

void helperBrute(int index, vector<int> &candidates, vector<int> &arr, set<vector<int>> &ds, int target) {

    if(index >= candidates.size()) {
        if(target == 0) {
            vector<int> temp = arr;
            sort(temp.begin(), temp.end()); // sort to avoid duplicates being inserted
            ds.insert(temp);
        }
        return;
    }

    // we pick the only element only if target does not become negative, since we want to make target 0 and not negative

    if(candidates[index] <= target) {

        arr.push_back(candidates[index]);
        helperBrute(index + 1, candidates, arr, ds, target - candidates[index]); // take 
        arr.pop_back(); // remove if inserted
    } 

    helperBrute(index + 1, candidates, arr, ds, target); // not take
}

vector<vector<int>> combinationSumBrute(vector<int> &candidates, int target) {

    vector<int> arr;
    set<vector<int>> ds;

    helperBrute(0, candidates, arr, ds, target);

    vector<vector<int>> ans(ds.begin(), ds.end()); // storing ans into 2-d array from set

    return ans;

} // O(2^n * klogk) time

// since we are generating all subsequences so 2^n time for that and for all valid subsequences of k avg length we sort them and store them in set O(klogk) time for that
// O(n) recursion stack space + O(n) temporary array space + O(k * x) space where k is avg length of sequence and total x seq

//////////////////////////////////////////////////////////////////////////////

// this is new pattern of recursion on array other than pick and not pick and used to handle duplicates, very very important
// in this we sort the array so that we can skip the duplicates when iterating from current index to array.size() - 1 using arr[i] == arr[i - 1] then continue and once we know its not duplicate then we pick that element if possible and move to the next index and when returning we pop_back()

void helperOptimal(int index, vector<int> &candidates, vector<int> &arr, vector<vector<int>> &ds, int target) {

    if(target == 0) {
        ds.push_back(arr); // add it to the answer as soon as we get valid and return
        return; 
    }

    // in each level we are making recursive calls from index to n - 1

    for(int i = index; i < candidates.size(); i++) {

        // avoid picking duplicates using this logic

        if(i > index && candidates[i] == candidates[i - 1]) continue;
        
        if(candidates[i] > target) {
            break; // since target would become negative
        } 

        arr.push_back(candidates[i]); // pick candidates[i]

        // now we have to maintain the sorted order hence we pick only the next guy which is index + 1 and not previous

        helperOptimal(i + 1, candidates, arr, ds, target - candidates[i]); 

        arr.pop_back(); // remove when returning

    }
}

vector<vector<int>> combinationSumOptimal(vector<int> &candidates, int target) {

    sort(candidates.begin(), candidates.end());

    vector<int> arr;
    vector<vector<int>> ds;

    helperOptimal(0, candidates, arr, ds, target);

    return ds;

} // O(2^n * k + nlogn) time where k is avg length of combination, O(n) recursion stack space
// O(n) temporary array space

int main() {
    
    return 0;
}