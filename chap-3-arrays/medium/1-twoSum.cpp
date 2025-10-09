#include<bits/stdc++.h>
using namespace std;

vector<int> twoSumBrute(const vector<int> &arr, int target) {
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[i] + arr[j] == target) return {i,j};
        }
    }
    return {-1,-1}; 
}

vector<int> twoSumBetter(const vector<int> &arr, int target) {
    // using hashing
    unordered_map<int,int> mpp;
    for(int i = 0; i < arr.size(); i++) {
        // checking if the complement exists
        if(mpp.count(target - arr[i])) return {i,mpp[target - arr[i]]};
        mpp[arr[i]] = i; // storing the number as key and its index as value
    }
    return {-1,-1};
} // O(n) time and O(n) space, better in time

bool twoSumOptimal(vector<int> &arr, int target) {
    // two pointer approach, cant even be considered optimal
    sort(arr.begin(), arr.end());
    int left = 0, right = arr.size() - 1;
    while(left < right) {
        if(arr[left] + arr[right] == target) return true;
        else if(arr[left] + arr[right] < target) {
            // so we have to increase the value and since array is sorted
            left++;
        } else {
            right--; // decrease the value
        }
    }
    return false;
} // O(nlogn + n) time but cant be used to return the indices adding up to the target


int main() {
    
    return 0;
}