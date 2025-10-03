#include<bits/stdc++.h>
using namespace std;

// the array contains n distinct numbers from range 0 to n, return the only missing number from range 0 to n which array does not contain, n = size of array

int findMissingBrute(const vector<int> &arr) {
    // initially start to check from 0 and reach till n, since the missing number is from [0,n]
    int n = arr.size();
    for(int numToFind = 0; numToFind <= n; numToFind++) { // trying enitre range of numbers
        bool flag = false;
        for(int j = 0; j < n; j++) { // search in the entire array if numToFind is present
            if(arr[j] == numToFind) flag = true;
        }
        if(flag == false) return numToFind; // our missing number
    }
    return -1; // unreachable
} // O(n^2) time and O(1) space

int findMissingBetter(const vector<int> &arr) {
    unordered_set<int> st(arr.begin(), arr.end()); 
    // can also use array to get O(1) guranteed access unlike set or unordered_set having O(logn) or O(n) access
    for(int numToFind = 0; numToFind <= arr.size(); numToFind++) {
        if(!st.count(numToFind)) return numToFind;
    }
    return -1; // unreachable
} // O(N) runtime and O(N) extra space

int findMissingBetterPreffered(const vector<int> &arr, int n) {
    int hashh[n + 1] = {0}; // to store numbers from 0 to n in our hashh array to store n+1 elements
    // if size of hashh = n only then we would be able to store only n - 1 elements\

    for(int num : arr) hashh[num]++; // missing element would remain to be marked as 0

    for(int i = 0; i <= n; i++) {
        if(!hashh[i]) return i; 
        // i is our missing number since its frequency in the hashh table is zero
    }
    return -1; // unreachable
}

int findMissingOptimal1(const vector<int> &arr) {
    int sum = 0, n = arr.size();
    for(int num : arr) sum += num;
    return n*(n + 1) / 2 - sum; // number = sum of numbers from 0 to n - sum of elements of array
}

int findMissingOptimal2(const vector<int> &arr) {
    int xor1 = 0, xor2 = 0;
    for(int i = 0; i < arr.size(); i++) {
        xor1 = xor1 ^ arr[i];
        // xor of all the array elements
        xor2 = xor2 ^ (i + 1); 
        // xor of complete range from 1 to n (can also be said as 0 to n because x ^ 0 = x)
    }
    return xor1 ^ xor2; // all the common elements would be cancelled as (x ^ x = 0) and onyl the single element would remain
}

// so this xor trick can be used to determine the only single element in array where every other element appears twice

int main() {
    
    return 0;
}