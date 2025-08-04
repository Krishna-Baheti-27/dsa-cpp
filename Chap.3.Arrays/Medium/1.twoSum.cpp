#include<bits/stdc++.h>
using namespace std;

vector<int> twoSumBrute(vector<int> &arr, int target) {
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            // we cant start from j = i since the same element will not be considered
            if(arr[i] + arr[j] == target) return {i,j};
        }
    }
    return {-1, -1};
}

vector<int> twoSumOptimal(vector<int> &arr, int target) {
    map<int,int> mp;
    for(int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i];
        if(mp.count(complement)) {
            return {mp[complement], i};
        }
        /// else we store the index of element as value and element itself as key
        mp[arr[i]] = i; // O(1) for unordered_map but O(N) in worst case
        // here we have used ordered map which takes logN time
    }
    return {-1,-1};
}

vector<int> twoSumMostOptimal(vector<int> &arr, int target) {
    // only if arrays is sorted O(N) time and O(1) space
    // very easy and straight forward approach
    int i = 0, j = arr.size() - 1;
    while(i <= j) {
        int sum = arr[i] + arr[j];
        if(sum == target) return {i,j};
        else if(sum < target) i++; // since sum is less than target, we have to increase it and for that increase i
        else j--; // decrease sum
    }
    return {-1,-1};
    // if the array is not sorted then you have to store the indices of original array, then sort the array and finally retrieve the indices
    // so use it if you want to answer is yer or no and dont have to give back indices
}

bool twoSumNotSortedArray(vector<int> &arr, int target) {
    sort(arr.begin(), arr.end()); // first sort the array in NlogN
    int i = 0, j = arr.size() - 1;
    while(i < j) {
        int sum = arr[i] + arr[j];
        if(sum == target) return true;
        else if(sum < target) i++;
        else j--;
    }
    return false;
}

int main() {
    vector<int> arr = {2,5,6,8,11};
    vector<int> solution = twoSumOptimal(arr,14);
    for(int num : solution) cout << num << ' ';
    cout << endl;
    return 0;
}