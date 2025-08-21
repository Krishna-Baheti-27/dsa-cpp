#include<bits/stdc++.h>
using namespace std;

int findMissingBrute(const vector<int> &arr) {
    // the array contains n distinct numbers from range 0 to n, return the only missing number from range 0 to n which array does not contain, n = size of array
    // Brute using O(N^2)
    // initially start to check from 0 and reach till n
    for(int numToFind = 0; numToFind <= arr.size(); numToFind++) { 
        bool flag = false;
        for(int j = 0; j < arr.size(); j++) {
            // search in the entire array if number is present
            if(arr[j] == numToFind) flag = true;
        }
        if(flag == false) return numToFind; // our missing number
    }
    return -1; // unreachable
}

int findMissingBetter(const vector<int> &arr) {
    // O(N) runtime and O(N) extra space
    unordered_set<int> st(arr.begin(), arr.end());
    for(int numToFind = 0; numToFind <= arr.size(); numToFind++) {
        if(!st.count(numToFind)) return numToFind;
    }
    return -1; // unreachable
} // not recommended, this code isnt exactly a better solution and no guaranteed runtime of O(N)

int findMissingBetterPreffered(const vector<int> &arr, int n) {
    int hashh[n + 1] = {0}; // to store numbers from 1 to n in indexes ranging from 1 to n
    for(int num : arr) hashh[num]++;
    for(int i = 1; i <= n; i++) {
        if(!hashh[i]) return i; // i is our missing number since its frequency in the hashh table is zero
    }
    return -1; // unreachable
}

int findMissingOptimal(const vector<int> &arr) {
    int sum = 0, n = arr.size();
    for(int num : arr) sum += num;
    return n*(n + 1) / 2 - sum; // number = sum of natural numbers from 1 to n - sum of elements of array
}

int findMissingOptimal2(const vector<int> &arr) {
    int xor1 = 0, xor2 = 0;
    for(int i = 0; i < arr.size(); i++) {
        xor1 = xor1 ^ arr[i];
        xor2 = xor2 ^ (i + 1);
    }
    return xor1 ^ xor2;
}
// Why Does This Work?
// XORing all numbers from 1 to n (xor2) gives you the XOR of the complete range except 0.

// XORing all elements in the array (xor1) gives you the XOR of all present numbers.

// When you XOR xor1 and xor2, all numbers that appear in both cancel out (since x ^ x = 0), and you’re left with the missing number.

int main() {
    
    return 0;
}