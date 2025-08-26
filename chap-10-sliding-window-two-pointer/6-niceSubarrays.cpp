#include<bits/stdc++.h>
using namespace std;

// a subarray is nice if there are k odd numbers in them

int countNiceSubarraysBrute(vector<int> &arr, int k) {
    // generate all subarrays and count the number of subarrays having k odd numbers
    int count = 0;
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i; j < arr.size(); j++) {
            int countOdd = 0;
            // we know subarray is from i to j
            for(int k = i; k <= j; k++) {
                if(arr[k] % 2 != 0) countOdd++;
            }
            if(countOdd == k) count++;
        }
    }
    return count;
} // O(n^n^n) ,lets try and optimise it

int countNiceSubarraysBruteBetter(vector<int> &arr, int k) {
    int count = 0;
    for(int i = 0; i < arr.size(); i++) {
        int countOdd = 0;
        // we know subarray is from i to j
        for(int j = i; j < arr.size(); j++) {
            if(arr[j] % 2 != 0) countOdd++;
            if(countOdd == k) {
                // the subarray from i to j is our nice subarray
                count++;
            } else if(countOdd > k) {
                // when countOdd exceeds k, we know we wont have any new subarray starting with i so we break out of the loop
                break;
            }
        }
    }
    return count;
} // O(N^N) slightly better solution but still TLE

int countNiceSubarraysBetter(vector<int> &arr, int k) {
    int l = 0, r = 0, count = 0, countOdd = 0;
    while(r < arr.size()) {
        if(arr[r] % 2 != 0) countOdd++;
        while(countOdd > k) {
            // here we move the l to decrease the window
            if(arr[l] % 2 != 0) countOdd--; // since we skipped the odd
            l++; // regardless of whether we skip the odd number or not
        }
        // now finally countOdd == k and we can count it as a nice subarray
        if(countOdd == k) count++;
        r++; // move ahead
    }
    return countOdd;
}

int main() {
    
    return 0;
}