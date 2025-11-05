#include<bits/stdc++.h>
using namespace std;

// we can only make smaller elements equal to some larger oe since we can only increment, so first element really cant be the max freq element so we start from second element and try make first element as second element, remember we cant make third element as second element since we cant decrement, and this valid only if array is sorted and hence we sort it

// this is sort of a greedy approach

//////////////////////////////////////////////////////////////////////////////////

int maxFreqBrute(vector<int> &arr, int k) {
    int maxFreq = 1;
    sort(arr.begin(), arr.end());
    
    for(int i = 1; i < arr.size(); i++) {
        int tempK = k;
        int freq = 1;
        for(int j = i - 1; j >= 0; j--) {
            if(arr[i] - arr[j] <= tempK) {
                tempK -= (arr[i] - arr[j]);   
                freq++;
                maxFreq = max(maxFreq, freq);
            }
            if(tempK <= 0) break;
        }
    }
    return maxFreq;
} // O(N^2) solution would give TLE

/////////////////////////////////////////////////////////////////////////////////////

// int maxFreqOptimalIncorrect(vector<int> &arr, int k) {
//     sort(arr.begin(), arr.end());
//     int maxFreqEl = arr[arr.size() - 1], maxFreq = 1, freq = 1, operations = k;
//     for(int i = arr.size() - 2; i >= 0; i--) {
//         if(arr[i] == maxFreqEl) {
//             freq++;
//             maxFreq = max(maxFreq, freq);
//         } else {
//             // since array is sorted and element is not eqal which means it ought to be lesser
//             operations -= maxFreqEl - arr[i];
//             if(operations >= 0) {
//                 freq++;
//                 maxFreq = max(maxFreq, freq);
//             } else {
//                 maxFreqEl = arr[i]; // new element
//                 freq = 1;
//                 operations = k;
//             }
//         }
//     }
//     return maxFreq;
// }

// This fails for arr = [1, 5, 5, 5, 10], k = 6

///////////////////////////////////////////////////////////////////////////////////////////

// The correct approach is using classing sliding window and two pointer

// we sort the array and use two pointers left and right, where our window is arr[left..right] and we try to make every element in window to equal to largest element arr[right] and we must do this within k operations and if fail we shrink window by left++ and we expand by right++ and maxfreq is the max length window can have at any time where length of window is given by right - left + 1

// the main logic is check if window is valid (that is operations <= k) and if yes then the freq is given by length of window that is r - l + 1 and if invalid then we make window valid by decreasing operations and l++ so main logic lies in how we calculate operations and it can be proved mathematically that
// operations += (arr[r] - arr[r - 1]) * (r - l)

// now when we shrink a window by l++, we are removing the element arr[l] from our window so the cost to convert arr[l] to arr[r] which we added in our operations must be removed and hence
// operations -= arr[r] - arr[l]

int maxFreqBetter(vector<int> &arr, int k) {
    sort(arr.begin(), arr.end());
    int l = 0, r = 0, maxFreq = 0;
    long long operations = 0;
    while(r < arr.size()) {
        if(r > 0) {
            operations += (long long)(arr[r] - arr[r - 1]) * (long long)(r - l);
        }
        while(operations > k) { // make the subarray valid
            operations -= arr[r] - arr[l];
            l++;
        }
        maxFreq = max(maxFreq, r - l + 1); // window is valid
        r++;
    }
    return maxFreq;
} // O(2N + NlogN) time

int maxFreqOptimal(vector<int> &arr, int k) {
    sort(arr.begin(), arr.end());
    int l = 0, r = 0, maxFreq = 0;
    long long operations = 0;
    while(r < arr.size()) {
        if(r > 0) {
            operations += (long long)(arr[r] - arr[r - 1]) * (long long)(r - l);
        }
        if(operations > k) { // make the subarray valid
            operations -= arr[r] - arr[l];
            l++;
        }
        if(operations <= k) {
            maxFreq = max(maxFreq, r - l + 1); // window is valid
        }
        r++;
    }
    return maxFreq;
} // O(N + NlogN) time

int main() {
    
    return 0;
}