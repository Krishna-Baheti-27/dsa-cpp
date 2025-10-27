#include<bits/stdc++.h>
using namespace std;

// we have to reverse the order of words in a given string and also remove leading or trailing or more than one spaces between any two words

// the brute force i can think of is, encounter a word from beginning and from end and then swap them, for this first do cleaning of initial spaces

string reverseWordsBruteIncorrect(string s) {
    string ans = "";
    int l = 0, r = s.length() - 1;
    while(s[l] == ' ') l++;
    while(s[r] == ' ') r--;
    // now l and r point to first and last word
    int lstart = l;
    int rend = r;
    for(int i = l; i <= r; i++) {
        while(s[l] != ' ') l++;
        while(s[r] != ' ') r--;
        // now we have to swap the string from lstart to l and r to rend, basically swapping them would mean placing the word from r to rend placing first and then after one space place lstart to l
        ans += s.substr(r , rend - r + 1);
        ans += " ";
        ans += s.substr(lstart, l - lstart + 1);
        // now make lstart to l and r to rend point to new set of words

    }
    return ans;
}

// A more straightforward "brute-force" approach is to iterate through the string from right to left, find each word, and append it to your result string.

string reverseWordsBrute(string s) {
    string ans = "";
    int i = s.length() - 1; // Start from the very end

    while (i >= 0) {
        // 1. Skip any trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        if (i < 0) break; // Break if we've passed all characters

        // 2. Mark the end of a word
        int word_end = i;

        // 3. Find the start of the word (the loop condition is i >= 0)
        while (i >= 0 && s[i] != ' ') {
            i--;
        }

        // 4. Extract the word and append it to the result
        string word = s.substr(i + 1, word_end - i);
        
        // Add a space BEFORE the next word, but not for the very first word
        if (!ans.empty()) {
            ans += " ";
        }
        ans += word;
    }
    return ans;
} // O(N) time and O(N) space to return the answer

// The most optimal solution involves reversing the entire string and then reversing each word separately to get the desired output in place by mutating original string

string reverseWordsOptimal(string s) {
    int start = 0, end = s.length() - 1;
    while(s[start] == ' ') start++;
    while(s[end] == ' ') end--;
    reverse(s.begin() + start - 1, s.begin() + end);
    while(start <= end) {
        int wordStart = start;
        while(s[start] != ' ' && start <= end) start++;
        reverse(s.begin() + wordStart - 1, s.begin() + start);
        while(s[start] == ' ' && start <= end) start++;
    }
    return s;
}


int main() {
    
    return 0;
}