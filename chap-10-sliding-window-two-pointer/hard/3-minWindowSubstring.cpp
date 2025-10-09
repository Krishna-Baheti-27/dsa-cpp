#include<bits/stdc++.h>
using namespace std;

// we want to find and return the minimum length substring from s which contains atleast one occurence of every character from string t
// basically if t = "abc", then return the min substring such that there is atleast one occurence of a, b and c
// if t = "aabccc", then return the min substring such that there are atleast 2 occurences of a, 1 occurence of b and 3 occurences of c

// brute force involves generating all substrings and satisfying the constraints in string t, and finding min of all such valid strings and we store min in a variable and return it

string minWindowBrute(string s, string t) {
    string ans = "";
    int minlen = INT_MAX;
    for(int i = 0; i < s.length(); i++) {
        unordered_map<char, int> mpp;
        for(int k = 0; k < t.length(); k++) {
            mpp[t[k]]++;
            // the map now stores our constraints
        }
        for(int j = i; j < s.length(); j++) {
            if(mpp.find(s[j]) != mpp.end()) {
                mpp[s[j]]--;
                if(mpp[s[j]] == 0) mpp.erase(s[j]);
            }
            if(mpp.size() == 0) {
                if(j - i + 1 < minlen) {
                    minlen = j - i + 1;
                    ans = s.substr(i , j - i + 1);
                    break;
                }
            }
        }
    }
    return ans;
}

string minWindowBruteBetter(string s, string t) {
    int minlen = INT_MAX, ansStart = -1;
    for(int i = 0; i < s.length(); i++) {
        int count = 0;
        unordered_map<char, int> mpp;
        for(int k = 0; k < t.length(); k++) {
            mpp[t[k]]++;
        }
        // now start checking substrings
        for(int j = i; j < s.length(); j++) {
            if(mpp[s[j]] > 0) count++;
            mpp[s[j]]--;
            if(count == t.length()) {
                // got the substring, now store if its min
                if(j - i + 1 < minlen) {
                    minlen = j - i + 1;
                    ansStart = i;
                }
                break; // since going ahead wont give us min but will only increase
            }
        }
    }
    return ansStart != -1 ? s.substr(ansStart, minlen) : "";
} // actually here its better to use hashh array instead of a map since we only have to store lowercase and uppercase english letters so do that to get O(N^2) time and O(256) time to store

string minWindowOptimal(string s, string t) {
    int l = 0, r = 0, minlen = INT_MAX, ansStart = -1, count = 0;
    vector<int> hashh(256, 0);
    for(int i = 0; i < t.length(); i++) {
        hashh[t[i]]++;
    }
    while(r < s.length()) {
        if(hashh[s[r]] > 0) count++;
        hashh[s[r]]--;
        while(count == t.length()) { // if we have got the window we try to shrink it as much as possible to get the minlength window
            if(r - l + 1 < minlen) {
                minlen = r - l + 1; 
                ansStart = l;
            }
            hashh[s[l]]++; // add back to the map since we are now not considering that character
            if(hashh[s[l]] > 0) count--;
            l++;
        }
        r++;
    }
    return ansStart != -1 ? s.substr(ansStart, minlen) : "";
} // O(m + 2n) time and O(256) space

int main() {
    
    return 0;
}