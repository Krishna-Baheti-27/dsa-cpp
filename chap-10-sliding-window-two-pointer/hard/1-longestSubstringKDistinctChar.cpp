#include<bits/stdc++.h>
using namespace std;

// we have to find the length of the longest substring having atmost k distinct characters

// the brute force involves generating all substrings and then checking if there are atmost k distinct characters and if yes find the max length amongst all such substrings

int longestSubstringAtmostKDistinctBrute(string s, int k) {
    int maxlen = INT_MIN;
    for(int i = 0; i < s.length(); i++) {
        unordered_set<char> st; // new set for start of all substrings from char s[i]
        for(int j = i; j < s.length(); j++) {
            // substring is from i to j and hence start counting distinct char
            st.insert(s[j]);
            if(st.size() > k) break; // after this we wont get any valid one
            maxlen = max(maxlen, j - i + 1); // else valid so count its length
        }
    }
    return maxlen;
} // O(N^2) time is worst case since the set will store atmax 256 characters not more than that
// O(256) space

// since questions involves substring and min/max we will use two pointer and sliding window
int longestSubstringAtmostKDistinctBetter(string s, int k) {
    int l = 0, r = 0, maxLen = 0;
    unordered_map<char, int> mpp;
    while(r < s.length()) {
        mpp[s[r]]++;
        while(mpp.size() > k) {
            mpp[s[l]]--;
            if(mpp[s[l]] == 0) mpp.erase(s[l]);
            l++;
        }
        // now the window is valid
        maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
} // O(2N) time and O(256) space

int longestSubstringAtmostKDistinctOptimal(string s, int k) {
    int l = 0, r = 0, maxLen = 0;
    unordered_map<char, int> mpp;
    while(r < s.length()) {
        mpp[s[r]]++;
        if(mpp.size() > k) {
            mpp[s[l]]--;
            if(mpp[s[l]] == 0) mpp.erase(s[l]);
            l++;
        }
        if(mpp.size() <= k) {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }
    return maxLen;
} // O(N) time

int main() {
    
    return 0;
}