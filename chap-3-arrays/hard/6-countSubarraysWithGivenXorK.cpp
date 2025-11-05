#include<bits/stdc++.h>
using namespace std;

// find the number of subarrays with given xor of all elements = k

/////////////////////////////////////////////////////////////////////////////////////

// brute force involves generating all subarray, find thier xor and count how many have xor = k

int countSubarraysWithXorKBrute1(vector<int> &arr, int k) {
    
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
} // O(n^3) three loops time

// try to do it in two loops

int countSubarraysWithXorKBrute2(vector<int> &arr, int k) {
    int count = 0;
    for(int i = 0; i < arr.size(); i++) {
        int xor1 = 0;
        for(int j = i; j < arr.size(); j++) {
            xor1 ^= arr[j];
            // now each value of xor1 in this iteration represents the xor of a particular subarray
            if(xor1 == k) count++;
        }
    }
} // O(n^2) time

/////////////////////////////////////////////////////////////////////////////////

// we try to do a preXor here similar to prefixSum
// in prefix sum we had maintained sum = x and if we found someone before has sum = x - k, then we would know there is a subarray having sum k
// similarly here we maintain a preXor = XR and if we found someone before having xor = XR ^ k then we surely have a subarray in between having xor = k (using XR ^ k ^ what = XR, we get what = k)

int countSubarraysWithXorKOptimal(vector<int> &arr, int k) {
    
    unordered_map<int,int> mpp;
    mpp[0] = 1; // to count with subarray starting from 0 having xor = k

    //  here we have to find the number of subarrays similar to count subarray having sum = k in array medium and hence we maintain the frequency of each occurence

    int xor1 = 0, count = 0;

    for(int i = 0; i < arr.size(); i++) {
        xor1 ^= arr[i];
        count += mpp[xor1 ^ k];
        mpp[xor1]++; // store all occurences of xor so we dont miss any subarray
    }

    return count;
    
} // O(N) time and O(N) space

int main() {
    
    return 0;
}