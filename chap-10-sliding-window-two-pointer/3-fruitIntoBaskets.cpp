#include<bits/stdc++.h>
using namespace std;

// the problem is basically finding the max length subarray or max number of fruits we can pick up having atmost two types of fruits or two types of numbers
// you can also fill one basket completely if every fruit is of same type and leave other empty thats why we use atmost two types of numbers or fruits here
// you only have two baskets
// constraint of picking up fruits from contiguous parts enforces use of subarrays

int maxFruitsBrute(vector<int> &arr) {
    // brute involves generating all subarrays
    int maxFruits = 0;
    for(int i = 0; i < arr.size(); i++) {
        set<int> st;
        for(int j = i; j < arr.size(); j++) {
            // subarray is from i to j
            st.insert(arr[j]);  
            if(st.size() > 2) break;
            maxFruits = max(maxFruits, j - i + 1);
        }
    }
    return maxFruits;
} // O(N^N) time and O(1) space (since set contains only 3 items at max and hence constant time and space)

int maxFruitsBetter(vector<int> &arr) {
    int maxFruits = 0, l = 0, r = 0;
    unordered_map<int,int> mpp; // to store num, freq
    while(r < arr.size()) {
        mpp[arr[r]]++;
        while(mpp.size() > 2) {
            mpp[arr[l]]--;
            if(mpp[arr[l]] == 0) mpp.erase(arr[l]);
            l++;
        }
        maxFruits = max(maxFruits, r - l + 1);
        r++; 
    }
    return maxFruits;
} // O(2N) time and O(1) space

int maxFruitsOptimal(vector<int> &arr) {
    int maxFruits = 0, l = 0, r = 0;
    unordered_map<int,int> mpp;
    while(r < arr.size()) {
        mpp[arr[r]]++;
        if(mpp.size() > 2) {
            mpp[arr[l]]--;
            if(mpp[arr[l]] == 0) mpp.erase(arr[l]);
            l++;
        } else {
            maxFruits = max(maxFruits, r - l + 1);
        }
        r++;
    }   
    return maxFruits;
} // O(N) time and O(1) space

int main() {
    
    return 0;
}