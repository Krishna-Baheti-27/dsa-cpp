#include<bits/stdc++.h>
using namespace std;

void swapNum(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

// if bit is 0 then it is not set, if bit is 1 then it is set
// the brute force is convert into binary then traverse from back i times and check if the value of s[i] == 1 or not
bool checkIfIthBitIsSetOrNot(int n, int i) {
    if(n & (1 << i) != 0) return true; // the ith bit is set
    return false;
} // we can also right shift n and then take & with 1 and check if that is 1 then its set 
// it will take O(1) time since computer performs bitwise operations extremely fast

void setIthBit(int &n, int i) {
    n = n | (1 << i); // we have to make the ith bit == 1 no matter what and hence we use or |
}

void clearIthBit(int &n, int i) {
    // make the ith bit = 0, which means take the & operation of n with a number that has only the ith bit as 0 and all other bits are 1, so first we make 1 left shift by i, so only ith bit = 1 and rest all 0 and then we take complement to simulate what we exactly need
    n = n & (~(1 << i));
}

void toggleIthBit(int &n, int i) {
    n = n ^ (1 << i); // since 1 ^ 1 = 0 (so toggle) and 0 ^ 1 = 1 (so again toggle effect)
}

void removeRightMostSetBit(int &n) {
    // we have to remove the first set bit, basically make it 0, 
    // so for that we have to & it with 0, and all the other things should remain same, so to achieve that we do n & (n - 1)
    n = n & (n - 1);
    // why becuase n - 1, is the number where the first set bit = 0 and all the bits before that will be 1 and all the bits after it remain unchanged   
}

bool isPowerOf2(int n) {
    // brute force is that number of sets bits = 1 (only since we want it to be power of 2 so only 1 bit should be set)
    // so if remove that set bit then number becomes zero like for 1000 that is 8, if we turn off the right most set bit then we get 0000 == 0
    if(n & (n - 1) == 0) return true; 
    return false; 
}

int countSetBitsBrute(int n) {
    // no shortcut here we have to use brute force
    int count = 0;
    while(n > 0) {
        if(n % 2 != 0) count++;
        n /= 2;
    } 
    return count;
} // O(logn) time

int countSetBitsBetter(int n) {
    int count = 0;
    while(n > 0) {
        if(n & 1) count++; // if odd then increase count
        n = n >> 1; // same as n = n / 2
    }
    return count;
} // O(logn) time

int countSetBitsOptimal(int n) {
    int count = 0;
    while (n > 0) {
        // This line unsets the rightmost '1' bit
        n = n & (n - 1);  // so how many times we turn off the rightmost set bit helps us determine the number of set bits
        count++;
    }
    return count;
} // O(31) time, since it only runs for O(no. of set bits) times

int main() {
    
    return 0;
}