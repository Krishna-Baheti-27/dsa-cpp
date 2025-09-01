#include<bits/stdc++.h>
using namespace std;

// swap O(N) and 

string reverseWordsBrute(const string &s) {
    string ans = "";
    int start = 0, end = s.size() - 1;
    while(end >= 0) {
        if(s[end] == ' ') end--;
        else break;
    } // found the actual end
    while(start <= end) {
        if(s[start] == ' ') start++;
        else break;
    } // found the actual start
    int newStart = end, newEnd = end;
    for(int i = end; i >= start; i--) {
        // we iterate only after trimming initial spaces
        if(s[i] != ' ') {
            newStart--; // to get the actual start of the word
        } else {
            // end the word by copying it to ans
            if(s[newStart] == ' ' && s[newEnd] == ' ') {
                newStart--;
                newEnd--;
                continue;
            }
            for(int j = newStart; j <= newEnd; j++) ans += s[j];
            ans += ' ';
            newStart = i, newEnd = i;
        }
    }
    return ans;
}

string reverseWordsOptimal(string &s) {
    int i1 = 0, j1 = s.size() - 1;
    while(s[i1] == ' ') i1++;
    while(s[j1] == ' ') j1--;
    int i2 = i1, j2 = j1;
    // found the first and last actual pointers
    while(i2 <= j1) {
        while(s[i2] != ' ') i2++;
        while(s[j1] != ' ') j1--;
        // we swap the strings from i1 to i2 with j1 to j2
        int k1 = i1, k2 = j1;
        while(k1 <= i2 && k2 <= j2) {
            char temp = s[k1];
            s[k1] = s[k2];
            s[k2] = temp;
            k1++;
            k2++;
        }
        while(k1 <= i2) {
            s[k2] = s[k1++];
        }
        while(k2 <= j2) {
            s[k1] = s[k2++];
        }
        i1 = i2;
        j2 = j1;
    }
    return s;
}

void reverseStr(string &s, int low, int high) {
    for(int i = low, j = high; i < j; i++, j--) {
        swap(s[i], s[j]);
    }
} 

string reverseWords(string &s) {
    int start = 0, end = s.size() - 1;
    while(s[start] == ' ') start++;
    while(s[end] == ' ') end--;
    reverseStr(s, start, end);
    int newStart = start, newEnd = end;
    for(int i = start; i <= end; i++) {
        if(s[i] != ' ') newEnd++;
        else {
            // reverse the word and move ahead
            reverseStr(s, newStart, newEnd - 1);
        }
    }
}

string reverseCorrect1(string &s) {
    reverse(s.begin(), s.end());
    string ans = "";
    for(int i = 0; i < s.size(); i++) {
        string word = "";
        while(i < s.size() && s[i] != ' ') {
            word += s[i];
            i++;
        }
        reverse(word.begin(), word.end());
        if(word.size() > 0) {
            ans += ' '; // becuase of this first index would be a space
            ans += word;
        }
    }
    return ans.substr(1); // dont include first index since its a space 
}

#include <string>
#include <algorithm>

std::string reverseWordsAndTrim(std::string s) {
    // 1. Reverse the whole string
    std::reverse(s.begin(), s.end());

    int n = s.length();
    int read_ptr = 0;  // Pointer to scan the original (now reversed) string
    int write_ptr = 0; // Pointer to place the next character of the final string

    while (read_ptr < n) {
        // Skip leading spaces for the current word
        while (read_ptr < n && s[read_ptr] == ' ') {
            read_ptr++;
        }
        if (read_ptr == n) break; // End of string

        // If this isn't the first word, add a single space before it
        if (write_ptr != 0) {
            s[write_ptr] = ' ';
            write_ptr++;
        }

        // Find the start and end of the word
        int word_start = write_ptr;
        while (read_ptr < n && s[read_ptr] != ' ') {
            s[write_ptr] = s[read_ptr];
            write_ptr++;
            read_ptr++;
        }

        // 2. Reverse the individual word that we just copied
        std::reverse(s.begin() + word_start, s.begin() + write_ptr);
    }

    // 3. Resize the string to remove the garbage characters at the end
    s.resize(write_ptr);

    return s;
}

int main() {
    
    return 0;
}