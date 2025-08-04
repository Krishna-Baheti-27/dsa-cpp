#include<bits/stdc++.h>
using namespace std;

// Brute O(N^2) solution

int lengthofLongestSubarrayActualBrute(const vector<int> &arr, int k) {
    int lengthLongest = 0;
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i; j < arr.size(); j++) {
            int sum = 0;
            // subarray is from i to j, hence to find the sum of subarray from i to j we use a third loop 
            for(int k = i; k <= j; k++) {
                // both index i and j are inclusive
                sum += arr[k];
            }
            if(sum == k) lengthLongest = max(lengthLongest, j - i + 1); // check whether its max or not
        }
    }
    return lengthLongest;
}

int lengthOfLongestSubarrayBrute(vector<int> &arr, int k) {
    int lengthLongest = 0;
    for(int i = 0; i < arr.size(); i++) {
        int sum = 0; // subarray is from i to j and j starts from i and moves till arr.size()
        for(int j = i; j < arr.size(); j++) {
            sum += arr[j]; // we are already playing it smart by optimising so that sum is calculated as soon as subarray is known, so it is O(N^2) but some people may use extra loop which takes it to O(N^3)
            if(sum == k) {
                lengthLongest = max(lengthLongest, j - i + 1);
            } // similarly use min for finding minimum length subarray
        }
    }
    return lengthLongest;
}

int lengthOfLongestSubarrayOptimal(vector<int> &arr, int k) {
    map<int,int> mp; // we can use unordered_map but that can have O(N) in worst case for insertion and finding
    int sum = 0, maxLen = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if(sum == k) maxLen = i + 1; // zero based indexing (longest subarray if exists)
        if (mp.find(sum - k) != mp.end()) { // we have to check if sum - k exists as a key in a map, because if it does then we are guaranteed to have a subarray having sum = k, since (k + sum - k = sum)
            // the length of that subarray will be i - mp[sum-k] (current index - index where sum - k was found)
            maxLen = max(maxLen, i - mp[sum - k]); // we store the length of max subarray not any arbitrary subarray having sum = k
        }
        if (mp.find(sum) == mp.end()) { // simply means sum does not exist in map and hence store it
            // we store only the first occurrence of k because we want the longest subarray (left most)
            mp[sum] = i;  // only store if it's the first time we're seeing this sum, because it may be possible that we have zeroes or negative numbers due to which we get same value of sum again and that may overwrite and we will get a shorter length of subarray not max
        }
    }
    return maxLen;
} // O(NlogN) time for ordered map, O(N) for unordered_map but in worst case O(N^2) for unordered_map
// O(N) extra space


int lengthOfSmallestSubarrayOptimal(vector<int> &arr, int k) {
    // when we are finding for smallest length sub array we have to use min function instead of max and also allow overwriting of sum key in map so that we get the most recent or rightmost index thus giving us smallest subarray
    int sum = 0, minLen = INT_MAX;
// Why initializing with 0 is incorrect
// 0 means "no length": If you start with minLen = 0, then min(minLen, candidateLength) will always be 0 (since any valid subarray length is at least 1), unless you find a subarray of length 0, which is impossible.
// You never update minLen: Since 0 is always less than or equal to any positive integer, minLen will remain 0 throughout the loop, even if you find valid subarrays.
// You can't distinguish "no subarray found": If no subarray with sum k exists, minLen should indicate this. With minLen = 0, you can't tell if you found a valid subarray or not.


    map<int,int> mp;
    mp[0] = -1; // very important if a subarray is starting at index = 0
    // example = {1,2,3,4} and k = 3, so for i = 2, sum-k == 0, but mp.find(0) does not exist, hence initialsie it with -1 to get proper length which is 2 - (-1) = 3
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if(mp.find(sum - k) != mp.end()) {
            minLen = min(minLen, i - mp[sum - k]);
        }
        mp[sum] = i;
    }
    return minLen == INT_MAX ? 0 : minLen;
}

int lengthOfLongestSubarrayMostOptimal(vector<int> &arr, int k) {
    int i = 0, j = 0, sum = arr[0], maxLen = 0; // since initially subarray is single element hence sum = arr[0]
    while(i < arr.size()) {
        while(j <= i && sum > k) {
            sum -= arr[j];
            j++; // decreasing our window to check for subarray sum, as we know that we cant have sum of subarray = k for that range
        }
        if(sum == k) {
            maxLen = max(maxLen, i - j + 1);
        }
        i++; // increment i if niether sum is > or equal
        if(i < arr.size()) sum += arr[i]; // find the sum
    }
    return maxLen;
} // O(2N) time in worst case since inner while loop is not running always, but will run for exactly N times in total in the whole N iterations of outer loop 
// since in the worst case even j reaches till last 


int main() {
    vector<int> arr = {3,2,2,1,1,1,1,4,2,2};
    cout << lengthofLongestSubarrayActualBrute(arr,3) << endl;
    cout << lengthOfLongestSubarrayBrute(arr,3) << endl;
    cout << lengthOfLongestSubarrayOptimal(arr,3) << endl;
    cout << lengthOfLongestSubarrayMostOptimal(arr,3) << endl;
    cout << lengthOfSmallestSubarrayOptimal(arr,3) << endl;
    return 0;
}