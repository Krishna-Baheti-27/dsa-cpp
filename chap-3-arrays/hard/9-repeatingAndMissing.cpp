#include<bits/stdc++.h>
using namespace std;

// Problem Statement: You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

//////////////////////////////////////////////////////////////////////////////////////

// now we check each array element with integers from 1 to N, if we didnt match any that is the missing number, if we found that twice then that is the repeating number

vector<int> repeatingAndMissingBrute(vector<int> &arr) {

    int repeating = -1, missing = -1;
    
    for(int i = 0; i < arr.size(); i++) {
        
        if(missing != -1 && repeating != -1) break;

        int count = 0;

        for(int j = 1; j <= arr.size(); j++) {
            if(arr[i] == j) count++; // checking for current element arr[i]
        } 

        if(count == 2) repeating = arr[i];
        else if(count == 0) missing = arr[i];
    }

    return {repeating, missing};
} // O(N^2) time and O(1) space

/////////////////////////////////////////////////////////////////////////////////////////

// here in the better approach we use hashing so arr element having frequency = 2 is repeating and element having frequency = 0 is missing

vector<int> repeatingAndMissingBetter(vector<int> &arr) {

    int missing = -1, repeating = -1;

    // since we have N array elements we require a size of N + 1 to store them since vectors are also 0 based indexed

    vector<int> hashh(arr.size() + 1, 0); 

    for(int el : arr) hashh[el]++;

    for(int el : arr) {

        if(missing != -1 && repeating != -1) break;

        if(hashh[el] == 2) repeating = el; 
        else if(hashh[el] == 0) missing = el;
    }

    return {repeating, missing};
    
} // O(2N) time and O(N) space

////////////////////////////////////////////////////////////////////////////////////////////

// using simple logic and maths we will solve this problem by sum of first N natural number and we also require a second equation since we have 2 unknowns and thus sum of squreas of first N natural numbers also

// let A and B be repeating and missing number then we know using math
// A + B = sum of arr - sum of first N natural no.
// A - B = sum of squres of arr - sum of sqaures of first N natural no. 

vector<int> repeatingAndMissingOptimal1(vector<int> &arr) {

    // use long long to avoid integer overflows
    
    long long n = arr.size();
    long long sum1 = 0, sum2 = 0;

    for(int i = 0; i < arr.size(); i++) {
        sum1 += arr[i]; // sum of first N natural numbers
        sum2 += (long long)arr[i] * (long long)arr[i]; // sum of squares of first N natural numbers
    }

    int repMinusMissing = sum1 - (n*(n + 1)) / 2;
    int repPlusMissing = (sum2 - ((n*(n+1)*(2*n + 1)) / 6)) / repMinusMissing;

    int repeating = (repMinusMissing + repPlusMissing) / 2;
    int missing = repPlusMissing - repeating;

    return {repeating, missing};

} // O(N) time and O(1) space

//////////////////////////////////////////////////////////////////////////////////////////

// Revise this xor approach

// first xor all the numbers with numbers from 1 to N, and finally we would be left with 
// num = x ^ y where x is the repeating element and y is misssing , and the right most bit of num is our differentiating bit, (it would help us divide the array and numbers in two part, those having differentiating bit == 0 and those having differentaiting bit == 1, when we xor the both part the only two numbers left from both the parts would be our repeating and missing (since in xor all even occurences get cancelled and odd ones are left), but we dont know which number is which and therefore we again traverse the array one time to check for repeating number

vector<int> repeatingAndMissingOptimal2(vector<int> &arr) {

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