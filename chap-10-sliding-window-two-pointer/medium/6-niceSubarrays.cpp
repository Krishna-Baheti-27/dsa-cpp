#include<bits/stdc++.h>
using namespace std;

// we have count the number of nice subarrays
// A continuous subarray is called nice if there are k odd numbers on it.

// brute is generating all subarrays
// better uses hashing
// the most optimal solution uses sliding window and two pointer

// the above problem can be broken into the previous problem involving number of binary subarrays having sum = k, 
// here we want exactly k odd numbers, if we consider all the odd number as 1 and even numbers as zero then what we essentially want is the subarray having sum == k, (in which odd = 1 and even = 0)

int numOfSubarraysWithMaxSumK(vector<int> &arr, int k) {
    if(k < 0) return 0;
    int sum = 0, count = 0, l = 0, r = 0;
    while(r < arr.size()) {
        // instead of if-else you can also use modulo like sum += arr[r] % 2 would give you the answer
        if(arr[r] % 2 != 0) sum += 1; // odd as 1 and even as 0
        while(sum > k) {
            if(arr[l] % 2 != 0) sum -= 1; // odd to be considered as 1
            l++;
        }
        count += (r - l + 1);
        r++;
    }
    return count;
}

int numOfNiceSubArraysOptimal(vector<int> &arr, int k) {
    return numOfSubarraysWithMaxSumK(arr, k) - numOfSubarraysWithMaxSumK(arr, k - 1);
}

int main() {
    
    return 0;
}