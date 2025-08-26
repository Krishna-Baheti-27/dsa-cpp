#include<bits/stdc++.h>
using namespace std;

// What is an inversion of an array? Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].
// in simple words, the left element should be greater than the right element

int countInversionsBrute(vector<int> &arr) {
    int count = 0;
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[j] > arr[i]) {
                // if left element is greater than the right element
                count++;
            }
        }
    }
    return count;
} // O(N^N) time and O(1) space

int countInversionsOptimal(vector<int> &arr) {
    
}

int main() {
    
    return 0;
}