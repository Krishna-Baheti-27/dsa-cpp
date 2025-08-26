#include<bits/stdc++.h>
using namespace std;

// subarray is contiguous part of array

int longestSubarrayBrute(const vector<int> &arr, int k) {
    int maxLen = 0;
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i; j < arr.size(); j++) {
            // now we know that subarray is from i to j so lets find the sum of subarray anc check if k
            int sum = 0;
            for(int k = i; k <= j; k++) {
                sum += arr[k];
            }
            if(sum == k) maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
} //  approx O(n^n^n)

int longestSubarrayBruteBetter(const vector<int> &arr, int k) {
    // optimising the brute force
    int maxLen = 0;
    for(int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for(int j = i; j < arr.size(); j++) {
            // sub array is from i to j, so wh ydo we need a extra loop, we caculate the sum in each iteration and that would be the sum of that subaray
            sum += arr[j];
            if(sum == k) maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
} // O(n^n)

int longestSubarrayBetter(const vector<int> &arr, int k) {
    unordered_map<int,int> mpp;
    int sum = 0, maxLen = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if(sum == k) {
            maxLen = i + 1;
        } else if(mpp.find(sum - k) != mpp.end()) {
            maxLen = max(maxLen, i - mpp[sum - k]);
        }
        if(mpp.find(sum) == mpp.end()) {
            // if the sum doesnt exist previously then only store the index becuase we do not want to overwrite the index in case of 0's and negatives, we might get the same sum again but now we would loose our original index and hence we would not get the longest or leftmost subarray
            mpp[sum] = i; // store the index for a particular sum
        }
    }
    return maxLen;
} // O(N) for unordered_map and O(NlogN) for map and O(N) space 
// this solution is optimal, for array containing positives, negatives or zeroes

// but for array containing only positives and zeroes, we can derive even more optimal solution using 2 pointer approach
int longestSumOptimal(const vector<int> &arr, int k) {
    int left = 0, right = 0, sum = arr[0], maxLen = 0;
    while(right < arr.size()) {
        // shrink sum
        while(left <= right && sum > k) {
            sum -= arr[left];
            left++;
        } // while sum is greater than k , we shrink from the left to make sum equivalent to k
        // equate sum
        if(sum == k) {
            // now sum will be either equal to k or less than, if equal we have a subarray
            maxLen = max(maxLen, right - left + 1);
        }
        // now sum is lesser than k, so we have increase the sum by increasing right
        // increase sum
        right++;
        if(right < arr.size()) sum += arr[right];
    }
    return maxLen;
} // O(2n) in worst case, since the inner loop will run total of N times in the whole N iterations of outer loop

int main() {
    
    return 0;
}