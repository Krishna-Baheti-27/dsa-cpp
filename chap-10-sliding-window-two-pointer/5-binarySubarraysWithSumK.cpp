#include<bits/stdc++.h>
using namespace std;

// we are given a binary array having 0 and 1 and we have to compute total number of subarray having sum = k, so same as count subarray having given sum = k

// brute is generating all subarrays and better is using hashing and prefix sum
// so we have already done brute, better and optimal there for array containing negatives also the most optimal solution takes O(N) time and O(N) space, 
// but here we are given a binary array so we take advantage of that and use sliding window and 2 pointer to solve in constant space

// int countSubarraysWithSumK(vector<int> &arr, int k) {
//     int count = 0, l = 0, r = 0, sum = 0;
//     while(r < arr.size()) {
//         while(sum > k) {
//             sum -= arr[l];
//             l++;
//         }
//         if(sum == k) count++;
//         sum += arr[r];
//         r++;
//     }
//     return count;
// }  this doesnt work because we would be leaving some of the subarrays in between

// instead what we do is find the number of subarrays having sum <= k and then we try to go from there to tweak it so that we have number of subarrays having sum == k

int countSubarraysWithMaxSumK(vector<int> &arr, int k) {
    if(k < 0) return 0; // important if k = 0, then k - 1 would be -1
    int count = 0, l = 0, r = 0, sum = 0;
    while(r < arr.size()) {
        sum += arr[r];
        while(sum > k) {
            sum -= arr[l];
            l++;
        }
        // now we have sum <= k for the window [l,r], so how many subarrays are present in the window [l,r] the answer is exactly r - l + 1, so we add those
        // basically we are counting number of subarrays ending at index r, and in the window [l,r]
        // this because we added the new element arr[r], so doing this we ensure that we are not counting any subarray more than once
        count += (r - l + 1); 
        r++;
    }
    return count;
} // O(2N) time and O(1) space

// the above function gives us all the subarrays having sum <= k,
// if we subtract the all the subarrays having sum <= k - 1 from subarrays having sum <= k we will have all the subarrays having sum == k

int countSubarraysWithSumK(vector<int> &arr, int k) {
    return countSubarraysWithMaxSumK(arr, k) - countSubarraysWithMaxSumK(arr, k - 1);
} // O(2 * 2N) and O(1) space

int main() {
    
    return 0;
}