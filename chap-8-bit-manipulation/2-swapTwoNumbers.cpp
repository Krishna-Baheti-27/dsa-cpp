#include<bits/stdc++.h>
using namespace std;

// divide by two => right shift by >> 1
// multiply by two => left shift by << 1

// INT_MAX is 01111111... (total 31 ones)
// INT_MIN is 1000000.... (total 31 zeroes) because 11111... in 2's complement is -1

////////////////////////////////////////////////////////////////////////////////////

// in any operation involving negative numbers always first convert the negative number into 2's complement form and then apply the operation because that is how the compute stores the negative number

/////////////////////////////////////////////////////////////////////////////////////

// this is how we can swap without using third variable with xor operator

void swapNum(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

//////////////////////////////////////////////////////////////////////////////////////

// if bit is 0 then it is not set, if bit is 1 then it is set we have to check whether the ith bit is set or not

// the brute force is convert into binary then traverse from back i times and check if the value of s[i] == 1 or not

bool checkIfIthBitIsSetOrNot(int n, int i) {

    if(n & (1 << i) != 0) {
        return true; // the ith bit is set
    } else {
        return false;
    }
} 

// we can also right shift n and then take & with 1 and check if that is 1 then its set 
// it will take O(1) time since computer performs bitwise operations extremely fast

///////////////////////////////////////////////////////////////////////////////////// 

// we have to make the ith bit == 1 no matter what and hence we use or |

void setIthBit(int &n, int i) {
    n = n | (1 << i); 
}

/////////////////////////////////////////////////////////////////////////////////////

// we have to make the ith bit = 0

// which means take the & operation of n with a number that has only the ith bit as 0 and all other bits are 1, so first we make 1 left shift by i, so only ith bit = 1 and rest all 0 and then we take complement so that only ith bit is 0 rest all 1

void clearIthBit(int &n, int i) {
    n = n & (~(1 << i));
}

//////////////////////////////////////////////////////////////////////////////////////

void toggleIthBit(int &n, int i) {
    n = n ^ (1 << i); // since 1 ^ 1 = 0 (so toggle) and 0 ^ 1 = 1 (so again toggle effect)
}

//////////////////////////////////////////////////////////////////////////////////////

// we have to remove the first set bit, basically make it 0, 

// the observation is if you have n, then to obtain n - 1 just make the rightmost or first set bit 0 and all other bits to the right of it (or before it) to 1 and we have n - 1

// ex => 16 => 10000, change 1 to 0 (rightmost and rest on left as 1) => 15 => 01111

// now to make rightmost bit 0 simply & it with n - 1 since in n - 1 rest all bits on left = 1 (a & 1 = a so no change in and operation) and all bits on right are same (a & a = a)

void removeRightMostSetBit(int &n) {
   n = n & (n - 1);
}

//////////////////////////////////////////////////////////////////////////////////////

// we have to check whether a number is power of 2

// brute force is that number of set bits or bits having value = 1 is only 1 
// in simple words only 1 bit should be set

// so if remove that set bit then number becomes zero like for 1000 that is 8, if we turn off the right most set bit then we get 0000 == 0

bool isPowerOf2(int n) {
    if(n & (n - 1) == 0) {
        return true; 
    } else {
        return false; 
    }
}

////////////////////////////////////////////////////////////////////////////////////////

// we have to count the number of set bits

// no shortcut here we have to use brute force the way in which we find the binary of number we use that and count the times we have remainder == 1

int countSetBitsBrute(int n) {
    
    int count = 0;

    while(n > 0) {
        if(n % 2 != 0) {
            count++;
        }
        n /= 2;
    } 

    return count;

} // O(logn) time

// in more better approach we replace the arithmetic operations with bitwise operations for even faster result

// if number is odd then n & 1 == 1 else if number is even then n & 1 == 0
// and two divide by 2 we right shift by 1

int countSetBitsBetter(int n) {

    int count = 0;

    while(n > 0) {
        if(n & 1) {
            count++;
        }
        n = n >> 1; 
    }

    return count;

} // O(logn) time

// in the most optimal approach we keep turning off the rightmost bit one by one till number becomes 0 hence counting the number of set bits

int countSetBitsOptimal(int n) {

    int count = 0;

    while (n > 0) {
        n = n & (n - 1);  
        count++;
    }

    return count;

} // O(31) time, since it only runs for O(no. of set bits) times unlike above which always run for logn time

int countSetBitsStl(int n) {
    return __builtin_popcount(n); // __popcount(n) also works
}

int main() {
    
    return 0;
}