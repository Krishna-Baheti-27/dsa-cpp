#include<bits/stdc++.h>
using namespace std;

// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
// Return the length of the longest substring containing the same letter you can get after performing the above operations.

// here we have to minimise the number of conversions, basically we can perform atmost k operation and in those we can change any character in the string to any capital enlgish letter so we have to change them in such a way that we get longest repeating substring

// so we would not try to change the max occurence element instead all other ones, so how to find the number of changes for all other ones => it is simply length of substring - maxfreq

int lengthOfLongestRepeatingSubstringBrute(string s, int k) {
    // generate all the substrings and go from there
    int maxlen = 0, maxfreq = 0;
    for(int i = 0; i < s.length(); i++) {
        int hashh[26] = {0}; // since only uppercase english letters
        for(int j = i; j < s.length(); j++) {
            hashh[s[j] - 'A']++;
            maxfreq = max(maxfreq, hashh[s[j] - 'A']); // we keep track of maxfreq encountered yet
            int noOfChanges = (j - i + 1) - maxfreq;
            if(noOfChanges <= k) maxlen = max(maxlen, j - i + 1); // this subtring is eligible
            else break;
        }
    }
    return maxlen;
} // O(N^N) time and O(26) space

// very important to understand here is the thing that number of chages in a substring is essentially length of substring - maxfreq because if we can achieve that then this means all the characters can be turned into a single character which was intially having maxfreq and thus it is eligible to a repeating substring and we only have to find the longest repeating substring

int lengthOfLongestRepeatingSubstringBetter(string s, int k) {
    int maxlen = 0, maxfreq = 0, l = 0, r = 0, hashh[26] = {0};
    // what we want is all the characters in the window l to r can be converted into a single character and for that we required length - maxfreq changes
    while(r < s.length()) {
        hashh[s[r] - 'A']++;
        maxfreq = max(maxfreq, hashh[s[r] - 'A']);
        while((r - l + 1) - maxfreq > k) {
            hashh[s[l] - 'A']--;
            maxfreq = 0; // again find the new maxfreq
            for(int i = 0; i < 26; i++) {
                maxfreq = max(maxfreq, hashh[i]);
            }
            l++;
        }
        maxlen = max(maxlen, r - l + 1); // already valid no need to check
        r++;
    }
    return maxlen;
} // O(N + N) * 26 time and O(26) space

int lengthOfLongestRepeatingSubstringOptimal(string s, int k) {
    int maxlen = 0, maxfreq = 0, l = 0, r = 0, hashh[26] = {0};
    while(r < s.length()) {
        hashh[s[r] - 'A']++;
        maxfreq = max(maxfreq, hashh[s[r] - 'A']);
        if((r - l + 1) - maxfreq > k) {
            hashh[s[l] - 'A']--;
            maxfreq = 0;
            for(int i = 0; i < 26; i++) {
                maxfreq = max(maxfreq, hashh[i]);
            }
            l++;
        } else {
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }
    return maxlen;
}

int lengthOfLongestRepeatingSubstringMostOptimal(string s, int k) {
    int maxlen = 0, maxfreq = 0, l = 0, r = 0, hashh[26] = {0};
    while(r < s.length()) {
        hashh[s[r] - 'A']++;
        maxfreq = max(maxfreq, hashh[s[r] - 'A']);
        if((r - l + 1) - maxfreq > k) { // we dont need this while loop we have already done this optimisation
            hashh[s[l] - 'A']--;
            l++;
            // we dont have to update the maxfreq since it will only go down and that doesnt help us, we want to increase the value of maxfreq so that length - maxfreq decreases and gets <= k and thus a valid window
        } else {
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }
    return maxlen;
} // O(N) time and O(26) space

int main() {
    
    return 0;
}