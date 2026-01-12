#include <bits/stdc++.h>
using namespace std;

// A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.

// For example, for x = 7, the binary representation is 111 and we may choose any bit (including any leading zeros not shown) and flip it. We can flip the first bit from the right to get 110, flip the second bit from the right to get 101, flip the fifth bit from the right (a leading zero) to get 10111, etc.
// Given two integers start and goal, return the minimum number of bit flips to convert start to goal.

////////////////////////////////////////////////////////////////////////////////////////

// the brute force is to change both to binary strings and check different bits at corresponding indices count them and return the answer but it takes O(2 * logn) time to convert + O(logn) to check and also extra space

////////////////////////////////////////////////////////////////////////////////////////

// the optimal solution is have to count the number of bits which are different in both numbers so we use the xor operator since for different bits 0, 1 or 1, 0 it yields 1 else 0

// once we find the xor we just have to count the number of set bits in the xor 

// both start and goal are non negative

int minBitFlips(int start, int goal) {

    // because in the worst case start has all 31 bits as 1 and goal has all 31 bits as 0 then only the xor is start and cant exceed range of int
    // even int gets accepted no overflow
    
    long long xor1 = start ^ goal; 

    int count = 0;

    while(xor1 != 0) {
        xor1 = xor1 & (xor1 - 1);
        count++;
    }

    return count;

} // O(no. of set bits in xor) time in worst case O(31) time and O(1) space

int main() {
    
    return 0;
}