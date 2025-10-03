#include<bits/stdc++.h>
using namespace std;

int maxFreqBrute(vector<int> &arr, int k) {
    int maxFreq = 1;
    sort(arr.begin(), arr.end());
    // we can only make smaller elements equal to some larger oe since we can only increment, so first element really cant be the max freq element so we start from second element and try make first element as second element, remember we cant make third element as second element since we cant decrement
    for(int i = 1; i < arr.size(); i++) {
        int tempK = k;
        int freq = 1;
        for(int j = i - 1; j >= 0; j--) {
            if(arr[i] - arr[j] <= tempK) {
                tempK -= (arr[i] - arr[j]);   
                freq++;
                maxFreq = max(maxFreq, freq);
            }
            if(tempK == 0) break;
        }
    }
    return maxFreq;
} // O(N^2) solution would give TLE


// here what they basically want is, you can perform k opertions at max, what you should do is, identify the maxfreq element, and try to make all other elements lesser than that element == to that element, so number of operations required per element = maxfreq - elvalue, so we count the number of operations per element for each subarray, and if sum of all operations is lesser than or equal to k, then that is a valid subarray and the max freq element is the only repeating element in that subarray

int maxFreqBruteUsingOp(vector<int> &arr, int k) {
    // generate all subarrays, and try to find the maxlength one obeying the property and the repeating element in that subarray is our answer
    int maxlen = INT_MIN, maxfreqEl = arr[0];
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i; j < arr.size(); j++) {
            // for the subarray [i,j] we check if number of operations <= k, if yes then this is valid subarray and we try to find max length subarray
            int noOfOperations = 0;
            for(int k = i; k <= j; k++) {
                maxfreqEl = max(maxfreqEl, arr[k]);
                noOfOperations += maxfreqEl - arr[k];
            }
        }
    }
}


int maxFreqOptimal(vector<int> &arr, int k) {
    sort(arr.begin(), arr.end());
    int maxFreq = 1, freq = 1;
    int tempK = k;
    for(int i = arr.size() - 1; i >= 1; i--) {
        int toBecome = arr[i];
        if(toBecome - arr[i - 1] <= tempK) {
            tempK -= (toBecome - arr[i - 1]);
            freq++;
            maxFreq = max(maxFreq, freq);
        } else {
            toBecome = arr[i - 1];
            tempK = k;
            freq = 1;
        }
    }
    return maxFreq;
    // Uses sliding window 
}



int main() {
    
    return 0;
}