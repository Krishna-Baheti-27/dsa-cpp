#include<bits/stdc++.h>
using namespace std;

// Problem Statement: You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

vector<int> repeatingAndMissingBrute(vector<int> &arr) {
    int repeating = -1, missing = -1;
    for(int i = 0; i < arr.size(); i++) {
        // now we check each array element with integers from 1 to N, if we didnt match any that is the missing number, if we found that twice then that is the repeating number
        if(missing != -1 && repeating != -1) break;
        int count = 0;
        for(int i = 1; i <= arr.size(); i++) {
            if(arr[i] == i) count++;
        } 
        if(count == 2) repeating = arr[i];
        else if(count == 0) missing = arr[i];
    } 
    return {repeating, missing};
} // O(N^N) time and O(1) space

vector<int> repeatingAndMissingBetter(vector<int> &arr) {
    int missing = -1, repeating = -1;
    vector<int> hashh(arr.size() + 1, 0);
    for(int el : arr) hashh[el]++;
    for(int el : arr) {
        if(missing != -1 && repeating != -1) break;
        if(hashh[el] == 2) repeating = el; 
        else if(hashh[el] == 0) missing = el;
    }
    return {repeating, missing};
} // O(2N) time and O(N) space

vector<int> repeatingAndMissingOptimal1(vector<int> &arr) {
    // using maths
    long long n = arr.size();
    long long sum1 = 0, sum2 = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum1 += arr[i];
        sum2 += (long long)arr[i] * (long long)arr[i];
    }
    int repMinusMissing = sum1 - (n*(n + 1)) / 2;
    int repPlusMissing = (sum2 - ((n*(n+1)*(2*n + 1)) / 6)) / repMinusMissing;
    int repeating = (repMinusMissing + repPlusMissing) / 2;
    int missing = repPlusMissing - repeating;
    return {repeating, missing};
} // O(N) time and O(1) space
// use long long to avoid integer overflows

vector<int> repeatingAndMissingOptimal2(vector<int> &arr) {
    // first xor all the numbers with numbers from 1 to N, and finally we would be left with 
    // num = x ^ y where x is the repeating element and y is misssing , and the right most bit of num is our differentiating bit, (it would help us divide the array and numbers in two part, those having differentiating bit == 0 and those having differentaiting bit == 1, when we xor the both part the only two numbers left from both the parts would be our repeating and missing (since in xor all even occurences get cancelled and odd ones are left), but we dont know which number is which and therefore we again traverse the array one time to check for repeating number

    int xr = 0;
    int repeating, missing;
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        xr ^= arr[i];
        xr ^= (i + 1);
    }
    // to find the diffrentiating bit number we use the & with 1, so only 1 & 1 will give us = 1, and the differentiating bit will give us 1, so we start checking from right and each time we left shift
    int bitno = 0;
    while(1) {
        if((xr & (1 << bitno)) != 0) break; // found 1, so break
        bitno++; // else move ahead
    }
    // now segregate into two parts and take xor of all, so we dont need to do that later we do that at every step
    int zero = 0;
    int one = 0;
    for(int i = 0; i < n; i++) {
        // part of 1 club
        if((arr[i] & (1 << bitno)) != 0) one ^= arr[i];
        else zero ^= arr[i]; // zero club
    }
    // now zero and one would automatically contain our values since only the odd values would not get cancelled and would be stored in them
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(zero == arr[i]) count++;
    }
    if(count == 2) {
        repeating = zero;
        missing = one;
    } else {
        repeating = one;
        missing = zero;
    }
    return {repeating, missing};
} // O(4N) time and O(1) space

int main() {
    
    return 0;
} 