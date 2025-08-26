#include<bits/stdc++.h>
using namespace std;

// sustring is same as subarray, basically contiguous part of a string

int longestSubstringBrute(string s) {
    // generate all substrings and then find the longest one having unique characters
    int maxlen = 0;
     for(int i = 0; i < s.length(); i++) {
        for(int j = i; j < s.length(); j++) {
            // from i to j is a substring
            unordered_map<char,int> mpp;
            int length = 0;
            for(int k = i; k <= j; k++) {
                if(mpp.count(s[k])) {
                    length = 0;
                    break;
                } 
                mpp[s[k]]++;
                length++;
            }
            maxlen = max(length, maxlen);
        }
    }
    return maxlen;
} // O(n^n^n) TLE

int longestSubstringBruteUsingHashing(string s) {
    int maxlen = 0;
    for(int i = 0; i < s.length(); i++) {
        int hashh[256] = {0};
        for(int j = i; j < s.length(); j++) {
            if(!hashh[s[j]]) {
                int length = j - i + 1; // since substring is from indices i to j
                maxlen = max(length, maxlen);
                hashh[s[j]]++;
            } else {
                break; // already present or repeating character
            }
        }
    }   
    return maxlen;
} // O(n^n) time and O(256) space

// for any problem involving max/min substring or any sub thingy we should start thinking of two pointer and sliding window, it is not a generic or specific algorithm but changes according to problem, but does gives us O(N) solution which is what we want by changing the window

int longestSubstringOptimal(string s) {
    int l = 0, r = 0, maxlen = 0;
    vector<int> hashh(256, -1);
    while(r < s.length()) {
        // our window or answer is from l to r
        if(hashh[s[r]] != -1) {
            // in the map
            if(hashh[s[r]] >= l) {
                // within our window, so we have tu update l here
                l = hashh[s[r]] + 1;
            } // else there is a char in map but not in our window and hence no need to consider
        }
        // now if we had a repeating character in our window, we have already dealt with it, now just simply update maxlen
        maxlen = max(maxlen, r - l + 1);
        hashh[s[r]] = r; // always store the latest index of occurence
        r++;
    }
    return maxlen;
} // O(N), O(256)

int main() {
    
    return 0;
}