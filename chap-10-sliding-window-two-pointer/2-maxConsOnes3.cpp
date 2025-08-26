#include<bits/stdc++.h>
using namespace std;

// you can flip at most k o's to be ones and then return the max streak of cons ones that can be possible
// this is same as saying find the lonest subarray with atmost k zeros and return its length, becasue we can flip exactly k times

int maxConsOnesBrute(vector<int> &arr, int k) {
    // so brute force would be generate all subarrays, and then find maxlen of subarray having atmost k zeros
    int maxlen = 0;
    for(int i = 0; i < arr.size(); i++) {
        int numOfZeroes = 0;
        for(int j = i; j < arr.size(); j++) {
            if(arr[j] == 0) numOfZeroes++;
            if(numOfZeroes <= k) {
                maxlen = max(maxlen, j - i + 1);
            } else break;
        }
    }
    return maxlen;
} // O(N^N) would be TLE

int maxConsOnesOptimalIncorrect(vector<int> &arr, int k) {
    // sliding window and two pointer
    int l = 0, r = 0, maxlen = 0, numOfZeroes = 0;
    while(r < arr.size()) {
        if(arr[r] == 0) {
            numOfZeroes++;
        }   
        if(numOfZeroes <= k) {
            maxlen = max(maxlen, r - l + 1);
            r++;
        } else {
            // then move l and change the window so that only k zeroes are present
            if(arr[l] == 0) {
                numOfZeroes--; // since we skipped that zero to hence make numOfZeroes in that window to be one less
            }
            // if we skip 1, it is not to our advantage
            l++; // in either case we move till we make numOfZeroes in our control
        } // this doesnt work becuase if you delegate the task of moving l to outerloop then arr[r] == 0 will hit everytime increasing the numOfZeroes++, essentially an infinite loop
    }
    return maxlen;
}

int maxConsOnesBetter(vector<int> &arr, int k) {
    int l = 0, r = 0, maxlen = 0, numOfZeroes = 0;
    while(r < arr.size()) {
        if(arr[r] == 0) numOfZeroes++;
        while(numOfZeroes > k) {
            // will run total of N time
            if(arr[l] == 0) numOfZeroes--; // because that many zeroes we skipped
            l++;
        }
        // the above while loop guarantees that the window [l,r] is now valid hence directly update maxlen and r
        maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
} // O(2N) time

int maxConsOnesOptimal(vector<int> &arr, int k) {
    // without using the internal while loop
    int l = 0, r = 0, maxlen = 0, numOfZeroes = 0;
    while(r < arr.size()) {
        if(arr[r] == 0) numOfZeroes++;
        if(numOfZeroes > k) {
            if(arr[l] == 0) numOfZeroes--; // similar to what i tried to do in incorrect solution
            l++;
        } 
        // check our main updation condition always in the last ones everything is figured out
        // i have seen this in a lot of questions now
        if(numOfZeroes <= k) {
            maxlen = max(maxlen, r - l + 1);
        }
        r++; // always move ahead is what i missed earlier
    }
    return maxlen;
    // this works because the size of window stays the same as maximum enocutered so far since always either r moves or l moves by 1
}

int main() {
    
    return 0;
}