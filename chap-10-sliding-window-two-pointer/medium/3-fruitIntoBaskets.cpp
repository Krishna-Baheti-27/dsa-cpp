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
            // if size > 2 then we wont let it update the maxFruits since its invalid
            maxFruits = max(maxFruits, j - i + 1);
        }
    }
    return maxFruits;
} // O(N^2) time and O(3) space (since set contains only 3 items at max and hence constant time and space)

int maxFruitsBetter(vector<int> &arr) {
    int maxFruits = 0, l = 0, r = 0;
    unordered_map<int,int> mpp; // to store num, freq
    while(r < arr.size()) {
        mpp[arr[r]]++; // insert in the map according to element and its freuquency
        while(mpp.size() > 2) {
            mpp[arr[l]]--; 
            if(mpp[arr[l]] == 0) mpp.erase(arr[l]); // if frequency becomes 0, remove from map
            l++; // we always trim the window from the left
        }
        // now we are guaranteed that window is valid
        maxFruits = max(maxFruits, r - l + 1);
        r++; 
    }
    return maxFruits;
} // O(2N) time and O(1) space

// this isnt really optimal
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
            // only update the maxFruits when the window is valid else dont allow
        }
        r++;
    }   
    return maxFruits;
} // O(N) time , O(N/2) space
// O(N/2) space, so here apprantely it feels that the space would be constant and wont exceed O(3) but since l is not inside a while loop it does not gurantee us that size of map will always be <= 3
// try for this test case: [1, 2, 1, 2, 1, 2, 3, 4, 5, 6, 7, 8] and in the worst case map can store n/2 elements

int main() {
    
    return 0;
}