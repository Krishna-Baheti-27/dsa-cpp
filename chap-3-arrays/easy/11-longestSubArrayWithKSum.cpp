#include<bits/stdc++.h>
using namespace std;

// subarray is contiguous part of array
// we have to find the longest subarray having given sum k

int longestSubarrayBrute(const vector<int> &arr, int k) {
    int maxLen = 0;
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i; j < arr.size(); j++) {
            // now we know that subarray is from i to j so lets find the sum of subarray 
            int sum = 0;
            for(int k = i; k <= j; k++) {
                sum += arr[k];
            }
            if(sum == k) maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
} //  approx O(n^3) time

int longestSubarrayBruteBetter(const vector<int> &arr, int k) {
    // optimising the brute force
    int maxLen = 0;
    for(int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for(int j = i; j < arr.size(); j++) {
            // sub array is from i to j, so why do we need a extra loop, we caculate the sum in each iteration and that would be the sum of that subaray
            sum += arr[j];
            if(sum == k) maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
} // O(n^2) time

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
            // if the sum doesnt exist previously then only store the index becuase we do not want to overwrite the index in case of 0's and negatives, we might get the same sum again but now we would loose our original index and hence we would not get the longest or leftmost subarray, instead we would get shortest or rightmost subarray
            mpp[sum] = i; // store the index for a particular sum
        }
    }
    return maxLen;
} // O(N) for unordered_map and O(NlogN) for map and O(N) space 
// this solution is optimal, for array containing positives, negatives or zeroes

// Now understanding above point of why so we not allow to overwrite the sum, we can device a code which gives us the length pf shortest subarray having sum k

int shortestSubarrayBetter(vector<int> &arr, int k) {
    int sum = 0, minlen = 0;
    unordered_map<int,int> mpp;
    mpp[0] = -1; // this is for subarrays starting from 0, for them if sum == k then mpp[sum - k] would return -1 thus giving the length i - (-1) which is i + 1
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if(mpp.find(sum - k) != mpp.end()) minlen = min(minlen, i - mpp[sum - k]); 
        mpp[sum] = i; // let map overwrite always   
    }
    return minlen;
}

// so this mpp[0] = -1 can also be done for longest subarray code so we dont have to perform the explicit check for sum == k, and then the fundamental difference between longest subarray and shortest subarray just boils down to this, in one we dont overwrite in other we do

//////////////////////////////////////////////////////////////

// but for array containing only positives and zeroes, we can derive even more optimal solution using 2 pointer approach

// Writing the code in standard sliding window and two pointer style where our task is to maitain a window always having sum k and finding max possible length from there, this is classic two pointer sliding window problem

int longestSumOptimalReadable(const vector<int> &arr, int k) {
    int sum = 0, l = 0, r = 0, maxlen = 0; // our window is from [l,r]
    while(r < arr.size()) {
        sum += arr[r];
        while(sum > k) { 
            sum -= arr[l];
            l++; // shrink the window when it becomes invalid
        }
        if(sum == k) maxlen = max(maxlen, r - l + 1);
        r++; // expand the window
    }
    return maxlen;
} // O(2n) time

////////////////////////////////////////////////////

// THIS IS PROBABLY INCORRECT

int longestSumOptimalFinal(const vector<int> &arr, int k) {
    int sum = 0, l = 0, r = 0, maxlen = 0; // our window is from [l,r]
    while(r < arr.size()) {
        sum += arr[r];
        if(sum > k) { // invalid sum, no need to check l <= r, that is handled implicitly
            sum -= arr[l];
            l++; // shrink the window when it becomes invalid
        }
        if(sum == k) maxlen = max(maxlen, r - l + 1); 
        r++; // expand the window
    }
    return maxlen;
} // O(N) time

// we only allow to update when window becomes valid and since we are doing r++ always and l++ when window is invalid thus, the size of invalid window remains constant and cant increase and hence impossible to get maxlen unless the window becomes valid by doing r++, which will then increase length of window since no l++ would be happening

//////////////////////////////////////////////////////////

// for using sliding window two pointer for finding shortest subarray having given sum k, once we have the sum >= k, we start shrinking the window from left tillwe can maintain sum == k and compute the length each time does getting the min possible length while still maintaining sum == l

int shortestSubarrayOptimal(vector<int> &arr, int k) {
    int sum = 0, minlen = INT_MAX, l = 0, r = 0;
    while(r < arr.size()) {
        sum += arr[r];
        while(sum >= k) { // try to shrink the window till we can to get min
            if(sum == k) minlen = min(minlen, r - l + 1); // valid window
            sum -= arr[l];
            l++; // shrink from left till we can maintain atmost sum = k
        }
        r++; // move ahead to get valid window
    }
    return minlen == INT_MAX ? 0 : minlen;
} // O(2N) time

int main() {
    
    return 0;
}