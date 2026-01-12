#include <bits/stdc++.h>
using namespace std;

// You are given two integers L and R, your task is to find the XOR of elements of the range [L, R].

////////////////////////////////////////////////////////////////////////////////////////

// the brute force is simply to go and compute the xor in linear time from l to r

// but there is way to do it in constant time and space

// you just have to discover the patter starting from n = 1 in the blocks of 4

int findXor1ToN(int n) {

    if(n % 4 == 0) {
        return n;
    } else if(n % 4 == 1) {
        return 1;
    } else if(n % 4 == 2) {
        return n + 1;
    } 

    return 0;
}

int findXor(int l, int r) {
    return findXor1ToN(l - 1) ^ findXor1ToN(r);
}

int main() {
    
    return 0;
}