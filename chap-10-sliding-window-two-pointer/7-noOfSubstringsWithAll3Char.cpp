#include<bits/stdc++.h>
using namespace std;

// Given a string s consisting only of characters a, b and c.
// Return the number of substrings containing at least one occurrence of all these characters a, b and c

// each of abc should occur atleast once in the substring and the entire string consists only of a,b,c

int noOfSubstringsWithAll3CharBrute(string s) {
    // generate all substrings and for each check if a,b,c is present
    int count = 0;
    for(int i = 0; i < s.length(); i++) {
        bool isA = false, isB = false, isC = false;
        for(int j = i; j < s.length(); j++) {
            if(s[j] == 'a') isA = true;
            else if(s[j] == 'b') isB = true;
            else isC = true;

            if(isA && isB && isC) {
                count += s.length() - j;
                break;
            }
        } 
    }
    return count;
} // O(N^2) time and O(1) space 

// the above intuition of finding all substrings directly once we know that we have gotten atleast one occurence of each is exactly what we will use in our optimal solution but here instead we will foucs on the last character of the substring

int noOfSubstringsWithAll3CharOptimal(string s) {
    int count = 0, a = -1, b = -1, c = -1;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'a') a = i;
        else if(s[i] == 'b') b = i;
        else c = i;

    // now we find the minimal occurence, once we have gotten atleast one occurence of all of a,b,c
        if(a != -1 && b != -1 && c != -1) {
            int minlen = min(a, min(b,c)) ;
            // this basically tells the number of valid substrings that end on the character which is max(a,b,c)
            count += minlen + 1;
        }
    }
    return count;
} // O(N) time and O(1) space

int noOfSubstringsWithAll3CharOptimalReadable(string s) {
    int count = 0, lastSeen[] = {-1, -1, -1};
    for(int i = 0; i < s.length(); i++) {
        lastSeen[s[i] - 'a'] = i;
        if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
            count += min(lastSeen[0] , min(lastSeen[1],lastSeen[2])) + 1;
        }
    }
    return count;
}

int main() {
    
    return 0;
}