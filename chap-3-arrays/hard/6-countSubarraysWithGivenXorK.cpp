#include<bits/stdc++.h>
using namespace std;

// find the number of subarrays with given xor = k

int countSubarraysWithXorKBrute(vector<int> &arr, int k) {
    // generate all subarray, find thier xor and count how many have xor = k
    int count = 0;
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i; j < arr.size(); i++) {
            // the subarray is from i to j
            int xor1 = 0;
            for(int k = i; k <= j; k++) {
                xor1 ^= arr[k];
            }
            if(xor1 == k) count++;
        }
    }
    return k;
} // O(n^n^n) three loops time

// try to do it in two loops
int countSubarraysWithXorKBetter(vector<int> &arr, int k) {
    int count = 0;
    for(int i = 0; i < arr.size(); i++) {
        int xor1 = 0;
        for(int j = i; j < arr.size(); j++) {
            xor1 ^= arr[j];
            // now each value of xor1 in this iteration represents the xor of a particular subarray
            if(xor1 == k) count++;
        }
    }
}

int countSubarraysWithXorKOptimal(vector<int> &arr, int k) {
    // we try to do a preXor here similar to prefixSum
    // in prefix sum we had maintained sum = x and if we found someone before has sum = x - k, then we would know there is a subarray having sum k
    // similarly here we maintain a preXor = XR and if we found someone before having xor = XR ^ k then we surely have a subarray in between having xor = k (using XR ^ k ^ what = XR, we get what = k)
    unordered_map<int,int> mpp;
    mpp[0] = 1; // intially 0 is in the map with occurence = 1
    // because if we have a same element or subarray having length one then its xor with itself = 0 and therefore we must have that

    //  here we have to find the number of subarrays similar to count subarray having sum = k in array medium and hence we maintain the frequency of each occurence
    int xor1 = 0, count = 0;
    for(int i = 0; i < arr.size(); i++) {
        xor1 ^= arr[i];
        count += mpp[xor1 ^ k];
        mpp[xor1]++;
    }
    return count;
} // O(N) time and O(N) space

int main() {
    
    return 0;
}